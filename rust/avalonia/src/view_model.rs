use crate::{AppScope, Error, Result, Window};
use avalonia_sys as sys;
use std::any::Any;
use std::collections::HashMap;
use std::fmt;
use std::sync::{Arc, Mutex};

/// Rust-side bookkeeping for nested view-model handles a sink has published:
/// one slot per nested-model property (replacing drops the previous handle)
/// and one ordered list per nested-model collection (mirroring the managed
/// `ObservableCollection<T>` so insert/remove/move/replace/clear stay in
/// sync). This is what keeps repeated attach/replace/detach cycles from
/// accumulating live COM references: dropping a slot's `Box` releases Rust's
/// contribution to that nested object's reference count immediately, and
/// dropping the whole `NestedSlots` (when the last `ViewModelSink` clone for
/// a mount is dropped) releases everything still tracked.
#[derive(Default)]
struct NestedSlots {
    properties: Mutex<HashMap<i32, Box<dyn Any + Send>>>,
    collections: Mutex<HashMap<i32, Vec<Box<dyn Any + Send>>>>,
}

impl NestedSlots {
    fn set_property(&self, property_id: i32, handle: Option<ViewModelHandle>) {
        let mut properties = self.properties.lock_slots();
        match handle {
            Some(handle) => {
                properties.insert(property_id, Box::new(handle));
            }
            None => {
                properties.remove(&property_id);
            }
        }
    }

    fn push_collection_item(&self, collection_id: i32, handle: ViewModelHandle) {
        self.collections
            .lock_slots()
            .entry(collection_id)
            .or_default()
            .push(Box::new(handle));
    }

    fn insert_collection_item(&self, collection_id: i32, index: usize, handle: ViewModelHandle) {
        let mut collections = self.collections.lock_slots();
        let items = collections.entry(collection_id).or_default();
        items.insert(index, Box::new(handle));
    }

    fn replace_collection_item(&self, collection_id: i32, index: usize, handle: ViewModelHandle) {
        let mut collections = self.collections.lock_slots();
        let items = collections
            .get_mut(&collection_id)
            .expect("managed collection update succeeded without a Rust slot");
        items[index] = Box::new(handle);
    }

    fn remove_collection_item(&self, collection_id: i32, index: usize) {
        let mut collections = self.collections.lock_slots();
        let items = collections
            .get_mut(&collection_id)
            .expect("managed collection update succeeded without a Rust slot");
        items.remove(index);
    }

    fn move_collection_item(&self, collection_id: i32, from_index: usize, to_index: usize) {
        let mut collections = self.collections.lock_slots();
        let items = collections
            .get_mut(&collection_id)
            .expect("managed collection update succeeded without a Rust slot");
        let item = items.remove(from_index);
        items.insert(to_index, item);
    }

    fn clear_collection(&self, collection_id: i32) {
        let mut collections = self.collections.lock_slots();
        if let Some(items) = collections.get_mut(&collection_id) {
            items.clear();
        }
    }
}

/// Small helper so lock-poisoning has one documented, consistent message
/// across every `NestedSlots` accessor (a poisoned lock here means an
/// earlier panic happened while a nested handle was being installed or
/// removed; we still want a clear panic message rather than a generic
/// `unwrap` one).
trait LockSlots<T> {
    fn lock_slots(&self) -> std::sync::MutexGuard<'_, T>;
}

impl<T> LockSlots<T> for Mutex<T> {
    fn lock_slots(&self) -> std::sync::MutexGuard<'_, T> {
        self.lock().expect("nested view-model slot lock poisoned")
    }
}

impl fmt::Debug for NestedSlots {
    fn fmt(&self, formatter: &mut fmt::Formatter<'_>) -> fmt::Result {
        formatter
            .debug_struct("NestedSlots")
            .finish_non_exhaustive()
    }
}

#[derive(Clone, Debug)]
pub struct ViewModelSink {
    raw: sys::ComPtr<sys::IAvnRustVmSink>,
    raw2: sys::ComPtr<sys::IAvnRustVmSink2>,
    nested: Arc<NestedSlots>,
}

impl ViewModelSink {
    /// Wraps a freshly attached v1 sink and eagerly resolves the v2
    /// capability. Failing fast here (rather than lazily on first v2 use)
    /// keeps the contract explicit: a host whose generated adapter has not
    /// been regenerated to implement `IAvnRustVmSink2` fails attach with a
    /// clear ABI error instead of silently dropping nested/nullable/
    /// collection/`CanExecute`/validation updates later.
    fn new(raw: sys::ComPtr<sys::IAvnRustVmSink>) -> Result<Self> {
        let raw2 = raw.query_interface::<sys::IAvnRustVmSink2>()?;
        Ok(Self {
            raw,
            raw2,
            nested: Arc::new(NestedSlots::default()),
        })
    }

    pub fn set_string(&self, property_id: i32, value: impl AsRef<str>) -> Result<()> {
        self.raw.set_string(property_id, &utf16(value))?;
        Ok(())
    }

    pub fn set_integer(&self, property_id: i32, value: i64) -> Result<()> {
        self.raw.set_integer(property_id, value)?;
        Ok(())
    }

    #[allow(dead_code)]
    pub fn set_boolean(&self, property_id: i32, value: bool) -> Result<()> {
        self.raw.set_boolean(property_id, value)?;
        Ok(())
    }

    #[allow(dead_code)]
    pub fn set_double(&self, property_id: i32, value: f64) -> Result<()> {
        self.raw.set_double(property_id, value)?;
        Ok(())
    }

    pub fn add_string(&self, collection_id: i32, value: impl AsRef<str>) -> Result<()> {
        self.raw.add_string(collection_id, &utf16(value))?;
        Ok(())
    }

    /// Publishes that a nullable scalar property currently has no value.
    pub fn set_null(&self, property_id: i32) -> Result<()> {
        self.raw2.set_null(property_id)?;
        self.nested.set_property(property_id, None);
        Ok(())
    }

    /// Publishes a nested view-model property. `None` clears it (and drops
    /// Rust's own reference to the previously published nested model, if
    /// any); `Some` wraps `model` in a fresh nested COM capability exactly
    /// like a top-level mount, but without making it a window.
    pub fn set_model(&self, property_id: i32, model: Option<impl DynamicViewModel>) -> Result<()> {
        match model {
            Some(model) => {
                let handle = ViewModelHandle::new(model);
                self.raw2.set_model(property_id, Some(&handle.raw))?;
                self.nested.set_property(property_id, Some(handle));
            }
            None => {
                self.raw2.set_model(property_id, None)?;
                self.nested.set_property(property_id, None);
            }
        }
        Ok(())
    }

    /// Appends a nested view-model item to a model-kind collection.
    pub fn add_model(&self, collection_id: i32, model: impl DynamicViewModel) -> Result<()> {
        let handle = ViewModelHandle::new(model);
        self.raw2.add_model(collection_id, &handle.raw)?;
        self.nested.push_collection_item(collection_id, handle);
        Ok(())
    }

    pub fn insert_string(
        &self,
        collection_id: i32,
        index: i32,
        value: impl AsRef<str>,
    ) -> Result<()> {
        self.raw2
            .insert_string(collection_id, index, &utf16(value))?;
        Ok(())
    }

    pub fn insert_model(
        &self,
        collection_id: i32,
        index: i32,
        model: impl DynamicViewModel,
    ) -> Result<()> {
        let handle = ViewModelHandle::new(model);
        self.raw2.insert_model(collection_id, index, &handle.raw)?;
        self.nested
            .insert_collection_item(collection_id, index as usize, handle);
        Ok(())
    }

    pub fn replace_string(
        &self,
        collection_id: i32,
        index: i32,
        value: impl AsRef<str>,
    ) -> Result<()> {
        self.raw2
            .replace_string(collection_id, index, &utf16(value))?;
        Ok(())
    }

    pub fn replace_model(
        &self,
        collection_id: i32,
        index: i32,
        model: impl DynamicViewModel,
    ) -> Result<()> {
        let handle = ViewModelHandle::new(model);
        self.raw2.replace_model(collection_id, index, &handle.raw)?;
        self.nested
            .replace_collection_item(collection_id, index as usize, handle);
        Ok(())
    }

    pub fn remove_string_at(&self, collection_id: i32, index: i32) -> Result<()> {
        self.raw2.remove_at(collection_id, index)?;
        Ok(())
    }

    pub fn remove_model_at(&self, collection_id: i32, index: i32) -> Result<()> {
        self.raw2.remove_at(collection_id, index)?;
        self.nested
            .remove_collection_item(collection_id, index as usize);
        Ok(())
    }

    pub fn move_string_item(
        &self,
        collection_id: i32,
        from_index: i32,
        to_index: i32,
    ) -> Result<()> {
        self.raw2.move_item(collection_id, from_index, to_index)?;
        Ok(())
    }

    pub fn move_model_item(
        &self,
        collection_id: i32,
        from_index: i32,
        to_index: i32,
    ) -> Result<()> {
        self.raw2.move_item(collection_id, from_index, to_index)?;
        self.nested
            .move_collection_item(collection_id, from_index as usize, to_index as usize);
        Ok(())
    }

    pub fn clear_string_collection(&self, collection_id: i32) -> Result<()> {
        self.raw2.clear_collection(collection_id)?;
        Ok(())
    }

    pub fn clear_model_collection(&self, collection_id: i32) -> Result<()> {
        self.raw2.clear_collection(collection_id)?;
        self.nested.clear_collection(collection_id);
        Ok(())
    }

    /// Publishes a command's current `ICommand.CanExecute` state.
    pub fn set_command_enabled(&self, command_id: i32, enabled: bool) -> Result<()> {
        self.raw2.set_command_enabled(command_id, enabled)?;
        Ok(())
    }

    /// Publishes (or clears, when `message` is `None`) a validation error for
    /// a property, surfaced to managed code through `INotifyDataErrorInfo`.
    pub fn set_property_error(&self, property_id: i32, message: Option<&str>) -> Result<()> {
        match message {
            Some(message) => self
                .raw2
                .set_property_error(property_id, Some(&utf16(message)))?,
            None => self.raw2.set_property_error(property_id, None)?,
        }
        Ok(())
    }
}

pub trait DynamicViewModel: Send + 'static {
    fn attach(&mut self, sink: ViewModelSink) -> Result<()>;
    fn detach(&mut self) -> Result<()>;
    fn set_string(&mut self, property_id: i32, value: String) -> Result<()>;
    fn set_integer(&mut self, property_id: i32, value: i64) -> Result<()>;
    fn set_boolean(&mut self, property_id: i32, value: bool) -> Result<()>;
    fn set_double(&mut self, property_id: i32, value: f64) -> Result<()>;
    fn execute(&mut self, command_id: i32, parameter: Option<String>) -> Result<()>;
    fn begin_async(&mut self, command_id: i32, parameter: Option<String>) -> Result<()>;
}

struct ViewModelHandle {
    raw: sys::ComPtr<sys::IAvnRustViewModel>,
}

impl ViewModelHandle {
    fn new(model: impl DynamicViewModel) -> Self {
        let model = Arc::new(Mutex::new(model));
        let attach_model = model.clone();
        let detach_model = model.clone();
        let string_model = model.clone();
        let integer_model = model.clone();
        let boolean_model = model.clone();
        let double_model = model.clone();
        let execute_model = model.clone();
        let async_model = model;
        let raw = sys::rust_view_model(sys::RustViewModelCallbacks {
            attach: Box::new(move |sink| {
                map_result((|| {
                    let sink = ViewModelSink::new(sink)?;
                    attach_model
                        .lock()
                        .expect("Rust view-model lock poisoned")
                        .attach(sink)
                })())
            }),
            detach: Box::new(move || {
                map_result(
                    detach_model
                        .lock()
                        .expect("Rust view-model lock poisoned")
                        .detach(),
                )
            }),
            set_string: Box::new(move |id, value| {
                map_result(
                    string_model
                        .lock()
                        .expect("Rust view-model lock poisoned")
                        .set_string(id, value),
                )
            }),
            set_integer: Box::new(move |id, value| {
                map_result(
                    integer_model
                        .lock()
                        .expect("Rust view-model lock poisoned")
                        .set_integer(id, value),
                )
            }),
            set_boolean: Box::new(move |id, value| {
                map_result(
                    boolean_model
                        .lock()
                        .expect("Rust view-model lock poisoned")
                        .set_boolean(id, value),
                )
            }),
            set_double: Box::new(move |id, value| {
                map_result(
                    double_model
                        .lock()
                        .expect("Rust view-model lock poisoned")
                        .set_double(id, value),
                )
            }),
            execute: Box::new(move |id, parameter| {
                map_result(
                    execute_model
                        .lock()
                        .expect("Rust view-model lock poisoned")
                        .execute(id, parameter),
                )
            }),
            begin_async: Box::new(move |id, parameter| {
                map_result(
                    async_model
                        .lock()
                        .expect("Rust view-model lock poisoned")
                        .begin_async(id, parameter),
                )
            }),
        });
        Self { raw }
    }
}

impl AppScope {
    pub fn mount_dynamic_view_model(
        &self,
        view_id: i32,
        model: impl DynamicViewModel,
    ) -> Result<()> {
        let model = ViewModelHandle::new(model);
        let raw = self
            .application()
            .create_rust_vm_window(view_id, &model.raw)?;
        self.retain_object(model);
        self.mount(Window { raw })
    }
}

fn utf16(value: impl AsRef<str>) -> Vec<u16> {
    value.as_ref().encode_utf16().chain(Some(0)).collect()
}

fn map_result(result: Result<()>) -> sys::Result<()> {
    result.map_err(|error| match error {
        Error::Abi(error) => error,
        _ => sys::Error(sys::E_FAIL),
    })
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::sync::atomic::{AtomicUsize, Ordering};

    /// A minimal `DynamicViewModel` whose `Drop` increments a shared counter,
    /// so tests can assert that nested handles are actually released (not
    /// merely unreferenced from the managed side) when they are replaced,
    /// removed, or the owning sink/slots are dropped.
    struct CountedModel {
        alive: Arc<AtomicUsize>,
    }

    impl CountedModel {
        fn new(alive: Arc<AtomicUsize>) -> Self {
            alive.fetch_add(1, Ordering::SeqCst);
            Self { alive }
        }
    }

    impl Drop for CountedModel {
        fn drop(&mut self) {
            self.alive.fetch_sub(1, Ordering::SeqCst);
        }
    }

    impl DynamicViewModel for CountedModel {
        fn attach(&mut self, _sink: ViewModelSink) -> Result<()> {
            Ok(())
        }
        fn detach(&mut self) -> Result<()> {
            Ok(())
        }
        fn set_string(&mut self, _property_id: i32, _value: String) -> Result<()> {
            Ok(())
        }
        fn set_integer(&mut self, _property_id: i32, _value: i64) -> Result<()> {
            Ok(())
        }
        fn set_boolean(&mut self, _property_id: i32, _value: bool) -> Result<()> {
            Ok(())
        }
        fn set_double(&mut self, _property_id: i32, _value: f64) -> Result<()> {
            Ok(())
        }
        fn execute(&mut self, _command_id: i32, _parameter: Option<String>) -> Result<()> {
            Ok(())
        }
        fn begin_async(&mut self, _command_id: i32, _parameter: Option<String>) -> Result<()> {
            Ok(())
        }
    }

    #[test]
    fn nested_property_slot_replaces_and_drops_the_previous_handle() {
        let alive = Arc::new(AtomicUsize::new(0));
        let slots = NestedSlots::default();

        slots.set_property(
            1,
            Some(ViewModelHandle::new(CountedModel::new(alive.clone()))),
        );
        assert_eq!(1, alive.load(Ordering::SeqCst));

        // Replacing must drop the previous handle, not accumulate it.
        slots.set_property(
            1,
            Some(ViewModelHandle::new(CountedModel::new(alive.clone()))),
        );
        assert_eq!(1, alive.load(Ordering::SeqCst));

        slots.set_property(1, None);
        assert_eq!(0, alive.load(Ordering::SeqCst));
    }

    #[test]
    fn nested_collection_slots_track_insert_move_replace_remove_and_clear() {
        let alive = Arc::new(AtomicUsize::new(0));
        let slots = NestedSlots::default();
        let make = || ViewModelHandle::new(CountedModel::new(alive.clone()));

        slots.push_collection_item(1, make());
        slots.push_collection_item(1, make());
        slots.insert_collection_item(1, 0, make());
        assert_eq!(3, alive.load(Ordering::SeqCst));

        slots.replace_collection_item(1, 0, make());
        assert_eq!(
            3,
            alive.load(Ordering::SeqCst),
            "replace must not leak the old handle"
        );

        slots.move_collection_item(1, 0, 2);
        assert_eq!(
            3,
            alive.load(Ordering::SeqCst),
            "move must not drop or duplicate handles"
        );

        slots.remove_collection_item(1, 0);
        assert_eq!(2, alive.load(Ordering::SeqCst));

        slots.clear_collection(1);
        assert_eq!(0, alive.load(Ordering::SeqCst));
    }

    #[test]
    fn scalar_collection_operations_do_not_touch_nested_slots() {
        let alive = Arc::new(AtomicUsize::new(0));
        let slots = NestedSlots::default();
        slots.push_collection_item(2, ViewModelHandle::new(CountedModel::new(alive.clone())));

        // String collection changes deliberately have no nested-slot operation:
        // they must not look up collection 1 in the model-only slot map.
        assert_eq!(1, alive.load(Ordering::SeqCst));
        assert_eq!(1, slots.collections.lock_slots()[&2].len());

        slots.clear_collection(2);
        assert_eq!(0, alive.load(Ordering::SeqCst));
    }

    #[test]
    fn dropping_the_nested_slots_releases_every_tracked_handle() {
        let alive = Arc::new(AtomicUsize::new(0));
        {
            let slots = NestedSlots::default();
            slots.set_property(
                1,
                Some(ViewModelHandle::new(CountedModel::new(alive.clone()))),
            );
            slots.push_collection_item(2, ViewModelHandle::new(CountedModel::new(alive.clone())));
            slots.push_collection_item(2, ViewModelHandle::new(CountedModel::new(alive.clone())));
            assert_eq!(3, alive.load(Ordering::SeqCst));
        }
        assert_eq!(0, alive.load(Ordering::SeqCst));
    }

    #[test]
    fn repeated_mount_style_create_and_drop_cycles_do_not_leak() {
        // Mirrors the "repeatedly attach/detach models" conformance
        // requirement at the `ViewModelHandle` level: creating and dropping
        // many handles (as `AppScope::mount_dynamic_view_model` and
        // `ViewModelSink::set_model`/`add_model` do internally) must not
        // accumulate live models.
        let alive = Arc::new(AtomicUsize::new(0));
        for _ in 0..200 {
            let handle = ViewModelHandle::new(CountedModel::new(alive.clone()));
            assert_eq!(1, alive.load(Ordering::SeqCst));
            drop(handle);
        }
        assert_eq!(0, alive.load(Ordering::SeqCst));
    }
}
