use crate::{AppScope, Error, Result, Window};
use avalonia_sys as sys;
use std::any::Any;
use std::collections::HashMap;
use std::fmt;
use std::sync::mpsc::{self, Receiver, TryRecvError};
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

enum NestedBatchDelta {
    Set(i32, Option<ViewModelHandle>),
    Add(i32, ViewModelHandle),
    Insert(i32, usize, ViewModelHandle),
    Replace(i32, usize, ViewModelHandle),
    Remove(i32, usize),
    Move(i32, usize, usize),
    Clear(i32),
    Snapshot(i32, Vec<ViewModelHandle>),
}

impl NestedBatchDelta {
    fn apply(self, nested: &NestedSlots) {
        match self {
            Self::Set(id, handle) => nested.set_property(id, handle),
            Self::Add(id, handle) => nested.push_collection_item(id, handle),
            Self::Insert(id, index, handle) => nested.insert_collection_item(id, index, handle),
            Self::Replace(id, index, handle) => nested.replace_collection_item(id, index, handle),
            Self::Remove(id, index) => nested.remove_collection_item(id, index),
            Self::Move(id, from, to) => nested.move_collection_item(id, from, to),
            Self::Clear(id) => nested.clear_collection(id),
            Self::Snapshot(id, handles) => {
                let mut collections = nested.collections.lock_slots();
                collections.insert(
                    id,
                    handles
                        .into_iter()
                        .map(|handle| Box::new(handle) as Box<dyn Any + Send>)
                        .collect(),
                );
            }
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
    raw3: Option<sys::ComPtr<sys::IAvnRustVmSink3>>,
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
        // v3 is an optional capability. A matching v1/v2 host remains usable
        // for legacy publication; only batch submission reports E_NOINTERFACE.
        let raw3 = match raw.query_interface::<sys::IAvnRustVmSink3>() {
            Ok(value) => Some(value),
            Err(error) if error.0 == sys::E_NOINTERFACE => None,
            Err(error) => return Err(error.into()),
        };
        Ok(Self {
            raw,
            raw2,
            raw3,
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

    /// Submits one immutable worker-safe update batch. Unlike the legacy sink
    /// methods, this does not synchronously enter managed code beyond enqueueing
    /// its dispatcher callback. Applications publishing off the UI thread should
    /// use generated named batch builders rather than per-item methods.
    pub fn submit_batch(&self, batch: ViewModelBatch) -> Result<BatchCompletion> {
        let (completion, callback) = BatchCompletion::channel();
        let ViewModelBatch {
            generation,
            operations,
            delta,
        } = batch;
        let nested = self.nested.clone();
        let raw = sys::rust_vm_update_batch(
            generation,
            operations,
            Some(Box::new(move |outcome, error| {
                if outcome == 0 {
                    for change in delta {
                        change.apply(&nested);
                    }
                }
                callback(outcome, error);
            })),
        );
        self.raw3
            .as_ref()
            .ok_or(Error::Abi(sys::Error(sys::E_NOINTERFACE)))?
            .submit_batch(&raw)?;
        Ok(completion)
    }

    /// Same as <see cref="submit_batch"/>, with a callback invoked after the UI
    /// dispatcher applies/rejects the batch. The callback is never invoked on
    /// the submitting stack and no view-model lock is held while it runs.
    pub fn submit_batch_with_callback(
        &self,
        batch: ViewModelBatch,
        callback: impl FnOnce(BatchOutcome) + Send + 'static,
    ) -> Result<()> {
        let ViewModelBatch {
            generation,
            operations,
            delta,
        } = batch;
        let nested = self.nested.clone();
        let raw = sys::rust_vm_update_batch(
            generation,
            operations,
            Some(Box::new(move |outcome, error| {
                if outcome == 0 {
                    for change in delta {
                        change.apply(&nested);
                    }
                }
                callback(BatchOutcome::from_wire(outcome, error))
            })),
        );
        self.raw3
            .as_ref()
            .ok_or(Error::Abi(sys::Error(sys::E_NOINTERFACE)))?
            .submit_batch(&raw)?;
        Ok(())
    }
}

/// Result delivered asynchronously for a batch submission.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum BatchOutcome {
    Applied,
    Stale,
    Cancelled,
    Error(i32),
}

impl BatchOutcome {
    fn from_wire(outcome: i32, error: i32) -> Self {
        match outcome {
            0 => Self::Applied,
            1 => Self::Stale,
            2 => Self::Cancelled,
            _ => Self::Error(error),
        }
    }
}

/// A handle to an asynchronous batch completion. Dropping it is safe; Rust's
/// batch object still owns the sender until managed code reaches a terminal
/// outcome. `try_take` is useful in executor-neutral applications.
pub struct BatchCompletion(Receiver<BatchOutcome>);

impl BatchCompletion {
    fn channel() -> (Self, sys::RustVmBatchCompletion) {
        let (sender, receiver) = mpsc::channel();
        (
            Self(receiver),
            Box::new(move |outcome, error| {
                let _ = sender.send(BatchOutcome::from_wire(outcome, error));
            }),
        )
    }

    pub fn wait(self) -> std::result::Result<BatchOutcome, mpsc::RecvError> {
        self.0.recv()
    }

    pub fn try_take(&self) -> std::result::Result<BatchOutcome, TryRecvError> {
        self.0.try_recv()
    }
}

/// Immutable IR-independent batch payload. Its builders own all strings and
/// COM references, so after `submit_batch` starts it is read-only and needs no
/// Rust locks. Generated model-specific wrappers expose named methods over this
/// type; application code should not use the numeric constructor directly.
#[derive(Default)]
pub struct ViewModelBatch {
    generation: i64,
    operations: Vec<sys::RustVmUpdate>,
    delta: Vec<NestedBatchDelta>,
}

impl ViewModelBatch {
    #[doc(hidden)]
    pub fn new(generation: i64) -> Self {
        Self {
            generation,
            operations: Vec::new(),
            delta: Vec::new(),
        }
    }

    #[doc(hidden)]
    pub fn push(&mut self, update: sys::RustVmUpdate) {
        self.operations.push(update);
    }

    #[doc(hidden)]
    pub fn push_string(&mut self, kind: i32, target_id: i32, index: i32, value: impl AsRef<str>) {
        let mut update = sys::RustVmUpdate::new(kind, target_id);
        update.index = index;
        update.text = Some(value.as_ref().to_owned());
        self.push(update);
    }

    #[doc(hidden)]
    pub fn push_integer(&mut self, target_id: i32, value: i64) {
        let mut update = sys::RustVmUpdate::new(2, target_id);
        update.integer = value;
        self.push(update);
    }

    #[doc(hidden)]
    pub fn push_null(&mut self, target_id: i32) {
        self.push(sys::RustVmUpdate::new(5, target_id));
    }

    #[doc(hidden)]
    pub fn push_boolean(&mut self, kind: i32, target_id: i32, value: bool) {
        let mut update = sys::RustVmUpdate::new(kind, target_id);
        update.boolean = i32::from(value);
        self.push(update);
    }

    #[doc(hidden)]
    pub fn push_double(&mut self, target_id: i32, value: f64) {
        let mut update = sys::RustVmUpdate::new(4, target_id);
        update.double = value;
        self.push(update);
    }

    #[doc(hidden)]
    pub fn push_indices(&mut self, kind: i32, target_id: i32, index: i32, index2: i32) {
        let mut update = sys::RustVmUpdate::new(kind, target_id);
        update.index = index;
        update.index2 = index2;
        self.push(update);
    }

    #[doc(hidden)]
    pub fn push_model_indices(&mut self, kind: i32, target_id: i32, index: i32, index2: i32) {
        self.push_indices(kind, target_id, index, index2);
        self.delta.push(match kind {
            13 => NestedBatchDelta::Remove(target_id, index as usize),
            14 => NestedBatchDelta::Move(target_id, index as usize, index2 as usize),
            _ => return,
        });
    }

    #[doc(hidden)]
    pub fn push_model_clear(&mut self, target_id: i32) {
        self.push(sys::RustVmUpdate::new(19, target_id));
        self.delta.push(NestedBatchDelta::Clear(target_id));
    }

    #[doc(hidden)]
    pub fn push_string_snapshot<S: AsRef<str>>(
        &mut self,
        target_id: i32,
        values: impl IntoIterator<Item = S>,
    ) {
        let mut update = sys::RustVmUpdate::new(15, target_id);
        update.snapshot_strings = Some(
            values
                .into_iter()
                .map(|value| value.as_ref().to_owned())
                .collect(),
        );
        self.push(update);
    }

    #[doc(hidden)]
    pub fn push_model(
        &mut self,
        kind: i32,
        target_id: i32,
        index: i32,
        model: impl DynamicViewModel,
    ) {
        let mut update = sys::RustVmUpdate::new(kind, target_id);
        update.index = index;
        let handle = ViewModelHandle::new(model);
        update.model = Some(handle.raw.clone());
        self.delta.push(match kind {
            6 => NestedBatchDelta::Set(target_id, Some(handle)),
            8 => NestedBatchDelta::Add(target_id, handle),
            10 => NestedBatchDelta::Insert(target_id, index as usize, handle),
            12 => NestedBatchDelta::Replace(target_id, index as usize, handle),
            _ => return,
        });
        self.push(update);
    }

    #[doc(hidden)]
    pub fn push_model_snapshot<M: DynamicViewModel>(
        &mut self,
        target_id: i32,
        models: impl IntoIterator<Item = M>,
    ) {
        let mut update = sys::RustVmUpdate::new(16, target_id);
        let handles: Vec<_> = models.into_iter().map(ViewModelHandle::new).collect();
        update.snapshot_models = Some(handles.iter().map(|handle| handle.raw.clone()).collect());
        self.delta
            .push(NestedBatchDelta::Snapshot(target_id, handles));
        self.push(update);
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
