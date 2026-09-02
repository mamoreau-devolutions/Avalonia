use crate::com::{ComInterface, ComPtr, IUnknown};
use crate::guid::Guid;
use crate::hresult::{self, Result};
use std::ffi::c_void;
use std::panic::{catch_unwind, AssertUnwindSafe};
use std::ptr;
use std::sync::atomic::{fence, AtomicU32, Ordering};
use std::sync::Arc;
use std::sync::Mutex;

const IAVN_RUST_VIEW_MODEL_IID: Guid = Guid {
    data1: 0x6B2E8F10,
    data2: 0x4C91,
    data3: 0x4E3A,
    data4: [0x9A, 0x77, 0x1F, 0x0C, 0x2B, 0x3A, 0x4D, 0x24],
};

const IAVN_RUST_VM_SINK_IID: Guid = Guid {
    data1: 0x6B2E8F10,
    data2: 0x4C91,
    data3: 0x4E3A,
    data4: [0x9A, 0x77, 0x1F, 0x0C, 0x2B, 0x3A, 0x4D, 0x25],
};

/// A second, independently versioned sink interface carrying the transport
/// added for nested view models, nullable values, collection insert/remove/
/// replace/move/clear, command `CanExecute` state, and validation-error
/// projection. Kept separate from `IAvnRustVmSink` (rather than extending its
/// vtable) so an older generated adapter that only implements v1 fails a
/// `QueryInterface` for this IID with a normal, explicit ABI error instead of
/// corrupting an existing call site.
const IAVN_RUST_VM_SINK2_IID: Guid = Guid {
    data1: 0x6B2E8F10,
    data2: 0x4C91,
    data3: 0x4E3A,
    data4: [0x9A, 0x77, 0x1F, 0x0C, 0x2B, 0x3A, 0x4D, 0x26],
};

const IAVN_RUST_VM_SINK3_IID: Guid = Guid {
    data1: 0x6B2E8F10,
    data2: 0x4C91,
    data3: 0x4E3A,
    data4: [0x9A, 0x77, 0x1F, 0x0C, 0x2B, 0x3A, 0x4D, 0x27],
};

const IAVN_RUST_VM_UPDATE_BATCH_IID: Guid = Guid {
    data1: 0x6B2E8F10,
    data2: 0x4C91,
    data3: 0x4E3A,
    data4: [0x9A, 0x77, 0x1F, 0x0C, 0x2B, 0x3A, 0x4D, 0x28],
};

const IAVN_RUST_VM_UPDATE_OPERATION_IID: Guid = Guid {
    data1: 0x6B2E8F10,
    data2: 0x4C91,
    data3: 0x4E3A,
    data4: [0x9A, 0x77, 0x1F, 0x0C, 0x2B, 0x3A, 0x4D, 0x29],
};

/// The batch's separately versioned ownership-commit capability. It is a
/// distinct IID and vtable rather than an extension of
/// `IAvnRustVmUpdateBatch`, so the immutable batch contract that already
/// shipped is untouched. Managed code calls it exactly once, after every
/// notification-free state store and before any notification is published.
const IAVN_RUST_VM_UPDATE_BATCH2_IID: Guid = Guid {
    data1: 0x6B2E8F10,
    data2: 0x4C91,
    data3: 0x4E3A,
    data4: [0x9A, 0x77, 0x1F, 0x0C, 0x2B, 0x3A, 0x4D, 0x2A],
};

#[repr(C)]
struct IAvnRustVmSinkVtbl {
    query_interface: unsafe extern "system" fn(*mut IUnknown, *const Guid, *mut *mut c_void) -> i32,
    add_ref: unsafe extern "system" fn(*mut IUnknown) -> u32,
    release: unsafe extern "system" fn(*mut IUnknown) -> u32,
    set_string: unsafe extern "system" fn(*mut IAvnRustVmSink, i32, *const u16) -> i32,
    set_integer: unsafe extern "system" fn(*mut IAvnRustVmSink, i32, i64) -> i32,
    set_boolean: unsafe extern "system" fn(*mut IAvnRustVmSink, i32, i32) -> i32,
    set_double: unsafe extern "system" fn(*mut IAvnRustVmSink, i32, f64) -> i32,
    add_string: unsafe extern "system" fn(*mut IAvnRustVmSink, i32, *const u16) -> i32,
}

#[repr(C)]
pub struct IAvnRustVmSink {
    vtbl: *const IAvnRustVmSinkVtbl,
}

unsafe impl ComInterface for IAvnRustVmSink {
    const IID: Guid = IAVN_RUST_VM_SINK_IID;
}

impl ComPtr<IAvnRustVmSink> {
    pub fn set_string(&self, property_id: i32, value: &[u16]) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().set_string)(
                self.as_raw(),
                property_id,
                value.as_ptr(),
            ))
        }
    }

    pub fn set_integer(&self, property_id: i32, value: i64) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().set_integer)(
                self.as_raw(),
                property_id,
                value,
            ))
        }
    }

    pub fn set_boolean(&self, property_id: i32, value: bool) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().set_boolean)(
                self.as_raw(),
                property_id,
                i32::from(value),
            ))
        }
    }

    pub fn set_double(&self, property_id: i32, value: f64) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().set_double)(
                self.as_raw(),
                property_id,
                value,
            ))
        }
    }

    pub fn add_string(&self, collection_id: i32, value: &[u16]) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().add_string)(
                self.as_raw(),
                collection_id,
                value.as_ptr(),
            ))
        }
    }
}

#[repr(C)]
struct IAvnRustVmSink2Vtbl {
    query_interface: unsafe extern "system" fn(*mut IUnknown, *const Guid, *mut *mut c_void) -> i32,
    add_ref: unsafe extern "system" fn(*mut IUnknown) -> u32,
    release: unsafe extern "system" fn(*mut IUnknown) -> u32,
    set_null: unsafe extern "system" fn(*mut IAvnRustVmSink2, i32) -> i32,
    set_model: unsafe extern "system" fn(*mut IAvnRustVmSink2, i32, *mut IAvnRustViewModel) -> i32,
    add_model: unsafe extern "system" fn(*mut IAvnRustVmSink2, i32, *mut IAvnRustViewModel) -> i32,
    insert_string: unsafe extern "system" fn(*mut IAvnRustVmSink2, i32, i32, *const u16) -> i32,
    insert_model:
        unsafe extern "system" fn(*mut IAvnRustVmSink2, i32, i32, *mut IAvnRustViewModel) -> i32,
    replace_string: unsafe extern "system" fn(*mut IAvnRustVmSink2, i32, i32, *const u16) -> i32,
    replace_model:
        unsafe extern "system" fn(*mut IAvnRustVmSink2, i32, i32, *mut IAvnRustViewModel) -> i32,
    remove_at: unsafe extern "system" fn(*mut IAvnRustVmSink2, i32, i32) -> i32,
    move_item: unsafe extern "system" fn(*mut IAvnRustVmSink2, i32, i32, i32) -> i32,
    clear_collection: unsafe extern "system" fn(*mut IAvnRustVmSink2, i32) -> i32,
    set_command_enabled: unsafe extern "system" fn(*mut IAvnRustVmSink2, i32, i32) -> i32,
    set_property_error: unsafe extern "system" fn(*mut IAvnRustVmSink2, i32, *const u16) -> i32,
}

#[repr(C)]
pub struct IAvnRustVmSink2 {
    vtbl: *const IAvnRustVmSink2Vtbl,
}

unsafe impl ComInterface for IAvnRustVmSink2 {
    const IID: Guid = IAVN_RUST_VM_SINK2_IID;
}

impl ComPtr<IAvnRustVmSink2> {
    pub fn set_null(&self, property_id: i32) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().set_null)(
                self.as_raw(),
                property_id,
            ))
        }
    }
}

#[repr(C)]
struct IAvnRustVmSink3Vtbl {
    query_interface: unsafe extern "system" fn(*mut IUnknown, *const Guid, *mut *mut c_void) -> i32,
    add_ref: unsafe extern "system" fn(*mut IUnknown) -> u32,
    release: unsafe extern "system" fn(*mut IUnknown) -> u32,
    submit_batch:
        unsafe extern "system" fn(*mut IAvnRustVmSink3, *mut IAvnRustVmUpdateBatch) -> i32,
}

#[repr(C)]
pub struct IAvnRustVmSink3 {
    vtbl: *const IAvnRustVmSink3Vtbl,
}

unsafe impl ComInterface for IAvnRustVmSink3 {
    const IID: Guid = IAVN_RUST_VM_SINK3_IID;
}

impl ComPtr<IAvnRustVmSink3> {
    pub fn submit_batch(&self, batch: &ComPtr<IAvnRustVmUpdateBatch>) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().submit_batch)(
                self.as_raw(),
                batch.as_raw(),
            ))
        }
    }
}

impl ComPtr<IAvnRustVmUpdateBatch> {
    /// Reports a terminal outcome. Only managed code calls this in production;
    /// it is exposed so the Rust side can be exercised without a managed host.
    pub fn complete(&self, outcome: i32, error: i32) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().complete)(
                self.as_raw(),
                outcome,
                error,
            ))
        }
    }
}

impl ComPtr<IAvnRustVmUpdateBatch2> {
    /// Hands the batch's nested ownership to its producer. Managed code calls
    /// this exactly once, between the state commit and the notifications.
    pub fn commit_ownership(&self) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().commit_ownership)(
                self.as_raw(),
            ))
        }
    }
}

#[repr(C)]
pub struct IAvnRustVmUpdateBatch {
    vtbl: *const IAvnRustVmUpdateBatchVtbl,
}

unsafe impl ComInterface for IAvnRustVmUpdateBatch {
    const IID: Guid = IAVN_RUST_VM_UPDATE_BATCH_IID;
}

#[repr(C)]
pub struct IAvnRustVmUpdateOperation {
    vtbl: *const IAvnRustVmUpdateOperationVtbl,
}

unsafe impl ComInterface for IAvnRustVmUpdateOperation {
    const IID: Guid = IAVN_RUST_VM_UPDATE_OPERATION_IID;
}

/// The batch's ownership-commit interface. Deliberately a separate vtable from
/// [`IAvnRustVmUpdateBatch`]; the two are exposed by the same object.
#[repr(C)]
pub struct IAvnRustVmUpdateBatch2 {
    vtbl: *const IAvnRustVmUpdateBatch2Vtbl,
}

unsafe impl ComInterface for IAvnRustVmUpdateBatch2 {
    const IID: Guid = IAVN_RUST_VM_UPDATE_BATCH2_IID;
}

#[repr(C)]
struct IAvnRustVmUpdateBatch2Vtbl {
    query_interface: unsafe extern "system" fn(*mut IUnknown, *const Guid, *mut *mut c_void) -> i32,
    add_ref: unsafe extern "system" fn(*mut IUnknown) -> u32,
    release: unsafe extern "system" fn(*mut IUnknown) -> u32,
    commit_ownership: unsafe extern "system" fn(*mut IAvnRustVmUpdateBatch2) -> i32,
}

#[repr(C)]
struct IAvnRustVmUpdateBatchVtbl {
    query_interface: unsafe extern "system" fn(*mut IUnknown, *const Guid, *mut *mut c_void) -> i32,
    add_ref: unsafe extern "system" fn(*mut IUnknown) -> u32,
    release: unsafe extern "system" fn(*mut IUnknown) -> u32,
    get_generation: unsafe extern "system" fn(*mut IAvnRustVmUpdateBatch, *mut i64) -> i32,
    get_operation_count: unsafe extern "system" fn(*mut IAvnRustVmUpdateBatch, *mut i32) -> i32,
    get_operation: unsafe extern "system" fn(
        *mut IAvnRustVmUpdateBatch,
        i32,
        *mut *mut IAvnRustVmUpdateOperation,
    ) -> i32,
    get_snapshot_item_count:
        unsafe extern "system" fn(*mut IAvnRustVmUpdateBatch, i32, *mut i32) -> i32,
    get_snapshot_string_length:
        unsafe extern "system" fn(*mut IAvnRustVmUpdateBatch, i32, i32, *mut i32) -> i32,
    copy_snapshot_string:
        unsafe extern "system" fn(*mut IAvnRustVmUpdateBatch, i32, i32, *mut u16, i32) -> i32,
    get_snapshot_model: unsafe extern "system" fn(
        *mut IAvnRustVmUpdateBatch,
        i32,
        i32,
        *mut *mut IAvnRustViewModel,
    ) -> i32,
    complete: unsafe extern "system" fn(*mut IAvnRustVmUpdateBatch, i32, i32) -> i32,
}

#[repr(C)]
struct IAvnRustVmUpdateOperationVtbl {
    query_interface: unsafe extern "system" fn(*mut IUnknown, *const Guid, *mut *mut c_void) -> i32,
    add_ref: unsafe extern "system" fn(*mut IUnknown) -> u32,
    release: unsafe extern "system" fn(*mut IUnknown) -> u32,
    get_kind: unsafe extern "system" fn(*mut IAvnRustVmUpdateOperation, *mut i32) -> i32,
    get_target_id: unsafe extern "system" fn(*mut IAvnRustVmUpdateOperation, *mut i32) -> i32,
    get_index: unsafe extern "system" fn(*mut IAvnRustVmUpdateOperation, *mut i32) -> i32,
    get_index2: unsafe extern "system" fn(*mut IAvnRustVmUpdateOperation, *mut i32) -> i32,
    get_integer: unsafe extern "system" fn(*mut IAvnRustVmUpdateOperation, *mut i64) -> i32,
    get_double: unsafe extern "system" fn(*mut IAvnRustVmUpdateOperation, *mut f64) -> i32,
    get_boolean: unsafe extern "system" fn(*mut IAvnRustVmUpdateOperation, *mut i32) -> i32,
    get_text_length: unsafe extern "system" fn(*mut IAvnRustVmUpdateOperation, *mut i32) -> i32,
    copy_text: unsafe extern "system" fn(*mut IAvnRustVmUpdateOperation, *mut u16, i32) -> i32,
    get_model: unsafe extern "system" fn(
        *mut IAvnRustVmUpdateOperation,
        *mut *mut IAvnRustViewModel,
    ) -> i32,
}

impl ComPtr<IAvnRustVmSink2> {
    pub fn set_model(
        &self,
        property_id: i32,
        model: Option<&ComPtr<IAvnRustViewModel>>,
    ) -> Result<()> {
        unsafe {
            let raw = model.map_or(ptr::null_mut(), ComPtr::as_raw);
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().set_model)(
                self.as_raw(),
                property_id,
                raw,
            ))
        }
    }

    pub fn add_model(&self, collection_id: i32, model: &ComPtr<IAvnRustViewModel>) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().add_model)(
                self.as_raw(),
                collection_id,
                model.as_raw(),
            ))
        }
    }

    pub fn insert_string(&self, collection_id: i32, index: i32, value: &[u16]) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().insert_string)(
                self.as_raw(),
                collection_id,
                index,
                value.as_ptr(),
            ))
        }
    }

    pub fn insert_model(
        &self,
        collection_id: i32,
        index: i32,
        model: &ComPtr<IAvnRustViewModel>,
    ) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().insert_model)(
                self.as_raw(),
                collection_id,
                index,
                model.as_raw(),
            ))
        }
    }

    pub fn replace_string(&self, collection_id: i32, index: i32, value: &[u16]) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().replace_string)(
                self.as_raw(),
                collection_id,
                index,
                value.as_ptr(),
            ))
        }
    }

    pub fn replace_model(
        &self,
        collection_id: i32,
        index: i32,
        model: &ComPtr<IAvnRustViewModel>,
    ) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().replace_model)(
                self.as_raw(),
                collection_id,
                index,
                model.as_raw(),
            ))
        }
    }

    pub fn remove_at(&self, collection_id: i32, index: i32) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().remove_at)(
                self.as_raw(),
                collection_id,
                index,
            ))
        }
    }

    pub fn move_item(&self, collection_id: i32, from_index: i32, to_index: i32) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().move_item)(
                self.as_raw(),
                collection_id,
                from_index,
                to_index,
            ))
        }
    }

    pub fn clear_collection(&self, collection_id: i32) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().clear_collection)(
                self.as_raw(),
                collection_id,
            ))
        }
    }

    pub fn set_command_enabled(&self, command_id: i32, enabled: bool) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw())
                .vtbl
                .as_ref()
                .unwrap()
                .set_command_enabled)(
                self.as_raw(), command_id, i32::from(enabled)
            ))
        }
    }

    pub fn set_property_error(&self, property_id: i32, message: Option<&[u16]>) -> Result<()> {
        unsafe {
            let raw = message.map_or(ptr::null(), <[u16]>::as_ptr);
            hresult::check(
                ((*self.as_raw()).vtbl.as_ref().unwrap().set_property_error)(
                    self.as_raw(),
                    property_id,
                    raw,
                ),
            )
        }
    }
}

pub struct RustViewModelCallbacks {
    pub attach: Box<dyn FnMut(ComPtr<IAvnRustVmSink>) -> Result<()> + Send>,
    pub detach: Box<dyn FnMut() -> Result<()> + Send>,
    pub set_string: Box<dyn FnMut(i32, String) -> Result<()> + Send>,
    pub set_integer: Box<dyn FnMut(i32, i64) -> Result<()> + Send>,
    pub set_boolean: Box<dyn FnMut(i32, bool) -> Result<()> + Send>,
    pub set_double: Box<dyn FnMut(i32, f64) -> Result<()> + Send>,
    pub execute: Box<dyn FnMut(i32, Option<String>) -> Result<()> + Send>,
    pub begin_async: Box<dyn FnMut(i32, Option<String>) -> Result<()> + Send>,
}

#[repr(C)]
struct IAvnRustViewModelVtbl {
    query_interface: unsafe extern "system" fn(*mut IUnknown, *const Guid, *mut *mut c_void) -> i32,
    add_ref: unsafe extern "system" fn(*mut IUnknown) -> u32,
    release: unsafe extern "system" fn(*mut IUnknown) -> u32,
    attach: unsafe extern "system" fn(*mut IAvnRustViewModel, *mut IAvnRustVmSink) -> i32,
    detach: unsafe extern "system" fn(*mut IAvnRustViewModel) -> i32,
    set_string: unsafe extern "system" fn(*mut IAvnRustViewModel, i32, *const u16) -> i32,
    set_integer: unsafe extern "system" fn(*mut IAvnRustViewModel, i32, i64) -> i32,
    set_boolean: unsafe extern "system" fn(*mut IAvnRustViewModel, i32, i32) -> i32,
    set_double: unsafe extern "system" fn(*mut IAvnRustViewModel, i32, f64) -> i32,
    execute: unsafe extern "system" fn(*mut IAvnRustViewModel, i32, *const u16) -> i32,
    begin_async: unsafe extern "system" fn(*mut IAvnRustViewModel, i32, *const u16) -> i32,
}

#[repr(C)]
pub struct IAvnRustViewModel {
    vtbl: *const IAvnRustViewModelVtbl,
}

unsafe impl ComInterface for IAvnRustViewModel {
    const IID: Guid = IAVN_RUST_VIEW_MODEL_IID;
}

#[repr(C)]
struct RustViewModelObject {
    interface: IAvnRustViewModel,
    references: AtomicU32,
    callbacks: Mutex<RustViewModelCallbacks>,
}

static RUST_VIEW_MODEL_VTBL: IAvnRustViewModelVtbl = IAvnRustViewModelVtbl {
    query_interface,
    add_ref,
    release,
    attach,
    detach,
    set_string,
    set_integer,
    set_boolean,
    set_double,
    execute,
    begin_async,
};

pub fn rust_view_model(callbacks: RustViewModelCallbacks) -> ComPtr<IAvnRustViewModel> {
    let object = Box::new(RustViewModelObject {
        interface: IAvnRustViewModel {
            vtbl: &RUST_VIEW_MODEL_VTBL,
        },
        references: AtomicU32::new(1),
        callbacks: Mutex::new(callbacks),
    });
    unsafe {
        ComPtr::from_raw(Box::into_raw(object).cast())
            .expect("Box allocation cannot produce a null pointer")
    }
}

unsafe extern "system" fn query_interface(
    this: *mut IUnknown,
    iid: *const Guid,
    result: *mut *mut c_void,
) -> i32 {
    if iid.is_null() || result.is_null() {
        return hresult::E_POINTER;
    }
    *result = ptr::null_mut();
    if *iid != Guid::IUNKNOWN && *iid != IAVN_RUST_VIEW_MODEL_IID {
        return hresult::E_NOINTERFACE;
    }
    add_ref(this);
    *result = this.cast();
    hresult::S_OK
}

unsafe extern "system" fn add_ref(this: *mut IUnknown) -> u32 {
    let object = this.cast::<RustViewModelObject>();
    (*object).references.fetch_add(1, Ordering::Relaxed) + 1
}

unsafe extern "system" fn release(this: *mut IUnknown) -> u32 {
    let object = this.cast::<RustViewModelObject>();
    let remaining = (*object).references.fetch_sub(1, Ordering::Release) - 1;
    if remaining == 0 {
        fence(Ordering::Acquire);
        drop(Box::from_raw(object));
    }
    remaining
}

unsafe extern "system" fn attach(this: *mut IAvnRustViewModel, sink: *mut IAvnRustVmSink) -> i32 {
    let Some(sink) = ComPtr::from_borrowed(sink) else {
        return hresult::E_POINTER;
    };
    invoke(this, |callbacks| (callbacks.attach)(sink))
}

unsafe extern "system" fn detach(this: *mut IAvnRustViewModel) -> i32 {
    invoke(this, |callbacks| (callbacks.detach)())
}

unsafe extern "system" fn set_string(
    this: *mut IAvnRustViewModel,
    property_id: i32,
    value: *const u16,
) -> i32 {
    let value = crate::clone_utf16(value).unwrap_or_default();
    invoke(this, |callbacks| (callbacks.set_string)(property_id, value))
}

unsafe extern "system" fn set_integer(
    this: *mut IAvnRustViewModel,
    property_id: i32,
    value: i64,
) -> i32 {
    invoke(this, |callbacks| {
        (callbacks.set_integer)(property_id, value)
    })
}

unsafe extern "system" fn set_boolean(
    this: *mut IAvnRustViewModel,
    property_id: i32,
    value: i32,
) -> i32 {
    invoke(this, |callbacks| {
        (callbacks.set_boolean)(property_id, value != 0)
    })
}

unsafe extern "system" fn set_double(
    this: *mut IAvnRustViewModel,
    property_id: i32,
    value: f64,
) -> i32 {
    invoke(this, |callbacks| (callbacks.set_double)(property_id, value))
}

unsafe extern "system" fn execute(
    this: *mut IAvnRustViewModel,
    command_id: i32,
    parameter: *const u16,
) -> i32 {
    let parameter = crate::clone_utf16(parameter);
    invoke(this, |callbacks| (callbacks.execute)(command_id, parameter))
}

unsafe extern "system" fn begin_async(
    this: *mut IAvnRustViewModel,
    command_id: i32,
    parameter: *const u16,
) -> i32 {
    let parameter = crate::clone_utf16(parameter);
    invoke(this, |callbacks| {
        (callbacks.begin_async)(command_id, parameter)
    })
}

unsafe fn invoke(
    this: *mut IAvnRustViewModel,
    callback: impl FnOnce(&mut RustViewModelCallbacks) -> Result<()>,
) -> i32 {
    let object = this.cast::<RustViewModelObject>();
    let result = catch_unwind(AssertUnwindSafe(|| {
        let mut callbacks = (*object)
            .callbacks
            .lock()
            .map_err(|_| hresult::Error(hresult::E_FAIL))?;
        callback(&mut callbacks)
    }));
    match result {
        Ok(Ok(())) => hresult::S_OK,
        Ok(Err(error)) => error.0,
        Err(_) => hresult::E_FAIL,
    }
}

/// Immutable update operation used by the v3 batch transport. The numeric tags
/// intentionally match `Avalonia.Rust.RustVmUpdateKind`; unknown tags are
/// rejected by managed code before it mutates presentation state.
#[derive(Clone)]
pub struct RustVmUpdate {
    pub kind: i32,
    pub target_id: i32,
    pub index: i32,
    pub index2: i32,
    pub integer: i64,
    pub double: f64,
    pub boolean: i32,
    pub text: Option<String>,
    pub model: Option<ComPtr<IAvnRustViewModel>>,
    pub snapshot_strings: Option<Vec<String>>,
    pub snapshot_models: Option<Vec<ComPtr<IAvnRustViewModel>>>,
}

impl RustVmUpdate {
    pub fn new(kind: i32, target_id: i32) -> Self {
        Self {
            kind,
            target_id,
            index: 0,
            index2: 0,
            integer: 0,
            double: 0.0,
            boolean: 0,
            text: None,
            model: None,
            snapshot_strings: None,
            snapshot_models: None,
        }
    }
}

pub type RustVmBatchCompletion = Box<dyn FnOnce(i32, i32) + Send>;

/// Invoked exactly once, by managed code, after every notification-free state
/// store and before any notification is published. This is where the batch's
/// nested ownership is handed to the producer.
pub type RustVmBatchOwnershipCommit = Box<dyn FnOnce() + Send>;

struct RustVmBatchState {
    generation: i64,
    operations: Vec<RustVmUpdate>,
    ownership: Mutex<Option<RustVmBatchOwnershipCommit>>,
    completion: Mutex<Option<RustVmBatchCompletion>>,
}

/// One allocation exposing two interfaces: the immutable batch itself and the
/// separately versioned ownership-commit capability. Both share the object's
/// single reference count.
#[repr(C)]
struct RustVmBatchObject {
    interface: IAvnRustVmUpdateBatch,
    ownership_interface: IAvnRustVmUpdateBatch2,
    references: AtomicU32,
    state: Arc<RustVmBatchState>,
}

#[repr(C)]
struct RustVmBatchOperationObject {
    interface: IAvnRustVmUpdateOperation,
    references: AtomicU32,
    state: Arc<RustVmBatchState>,
    index: usize,
}

static RUST_VM_BATCH_VTBL: IAvnRustVmUpdateBatchVtbl = IAvnRustVmUpdateBatchVtbl {
    query_interface: batch_query_interface,
    add_ref: batch_add_ref,
    release: batch_release,
    get_generation: batch_get_generation,
    get_operation_count: batch_get_operation_count,
    get_operation: batch_get_operation,
    get_snapshot_item_count: batch_get_snapshot_item_count,
    get_snapshot_string_length: batch_get_snapshot_string_length,
    copy_snapshot_string: batch_copy_snapshot_string,
    get_snapshot_model: batch_get_snapshot_model,
    complete: batch_complete,
};

static RUST_VM_BATCH_OWNERSHIP_VTBL: IAvnRustVmUpdateBatch2Vtbl = IAvnRustVmUpdateBatch2Vtbl {
    query_interface: ownership_query_interface,
    add_ref: ownership_add_ref,
    release: ownership_release,
    commit_ownership: batch_commit_ownership,
};

static RUST_VM_BATCH_OPERATION_VTBL: IAvnRustVmUpdateOperationVtbl =
    IAvnRustVmUpdateOperationVtbl {
        query_interface: operation_query_interface,
        add_ref: operation_add_ref,
        release: operation_release,
        get_kind: operation_get_kind,
        get_target_id: operation_get_target_id,
        get_index: operation_get_index,
        get_index2: operation_get_index2,
        get_integer: operation_get_integer,
        get_double: operation_get_double,
        get_boolean: operation_get_boolean,
        get_text_length: operation_get_text_length,
        copy_text: operation_copy_text,
        get_model: operation_get_model,
    };

/// Creates an immutable nano-COM batch exposing both the batch interface and
/// its separately versioned ownership-commit capability. `ownership` is taken
/// exactly once, by managed code, between the state commit and the
/// notifications; `completion` is taken exactly once after apply/stale/cancel/
/// error. Neither is ever invoked by SubmitBatch. Dropping the batch without an
/// ownership commit simply drops the callback (and everything it owns).
pub fn rust_vm_update_batch(
    generation: i64,
    operations: Vec<RustVmUpdate>,
    ownership: Option<RustVmBatchOwnershipCommit>,
    completion: Option<RustVmBatchCompletion>,
) -> ComPtr<IAvnRustVmUpdateBatch> {
    let object = Box::new(RustVmBatchObject {
        interface: IAvnRustVmUpdateBatch {
            vtbl: &RUST_VM_BATCH_VTBL,
        },
        ownership_interface: IAvnRustVmUpdateBatch2 {
            vtbl: &RUST_VM_BATCH_OWNERSHIP_VTBL,
        },
        references: AtomicU32::new(1),
        state: Arc::new(RustVmBatchState {
            generation,
            operations,
            ownership: Mutex::new(ownership),
            completion: Mutex::new(completion),
        }),
    });
    unsafe {
        ComPtr::from_raw(Box::into_raw(object).cast())
            .expect("Box allocation cannot produce a null pointer")
    }
}

/// Resolves the owning object from either of the two interface pointers it
/// exposes.
unsafe fn batch_object_from_ownership(this: *mut c_void) -> *mut RustVmBatchObject {
    this.cast::<u8>()
        .sub(std::mem::offset_of!(RustVmBatchObject, ownership_interface))
        .cast::<RustVmBatchObject>()
}

unsafe fn batch_query(
    object: *mut RustVmBatchObject,
    iid: *const Guid,
    result: *mut *mut c_void,
) -> i32 {
    *result = ptr::null_mut();
    if *iid == Guid::IUNKNOWN || *iid == IAVN_RUST_VM_UPDATE_BATCH_IID {
        (*object).references.fetch_add(1, Ordering::Relaxed);
        *result = ptr::addr_of_mut!((*object).interface).cast();
        return hresult::S_OK;
    }
    if *iid == IAVN_RUST_VM_UPDATE_BATCH2_IID {
        (*object).references.fetch_add(1, Ordering::Relaxed);
        *result = ptr::addr_of_mut!((*object).ownership_interface).cast();
        return hresult::S_OK;
    }
    hresult::E_NOINTERFACE
}

unsafe extern "system" fn batch_query_interface(
    this: *mut IUnknown,
    iid: *const Guid,
    result: *mut *mut c_void,
) -> i32 {
    if this.is_null() || iid.is_null() || result.is_null() {
        return hresult::E_POINTER;
    }
    batch_query(this.cast::<RustVmBatchObject>(), iid, result)
}

unsafe extern "system" fn ownership_query_interface(
    this: *mut IUnknown,
    iid: *const Guid,
    result: *mut *mut c_void,
) -> i32 {
    if this.is_null() || iid.is_null() || result.is_null() {
        return hresult::E_POINTER;
    }
    batch_query(batch_object_from_ownership(this.cast()), iid, result)
}

unsafe extern "system" fn batch_add_ref(this: *mut IUnknown) -> u32 {
    (*this.cast::<RustVmBatchObject>())
        .references
        .fetch_add(1, Ordering::Relaxed)
        + 1
}

unsafe extern "system" fn ownership_add_ref(this: *mut IUnknown) -> u32 {
    batch_add_ref(batch_object_from_ownership(this.cast()).cast())
}

unsafe extern "system" fn batch_release(this: *mut IUnknown) -> u32 {
    let object = this.cast::<RustVmBatchObject>();
    let remaining = (*object).references.fetch_sub(1, Ordering::Release) - 1;
    if remaining == 0 {
        fence(Ordering::Acquire);
        drop(Box::from_raw(object));
    }
    remaining
}

unsafe extern "system" fn ownership_release(this: *mut IUnknown) -> u32 {
    batch_release(batch_object_from_ownership(this.cast()).cast())
}

/// Hands the batch's nested ownership to the producer. The callback is taken
/// under the state lock, so it runs at most once no matter how many times
/// managed code calls this.
unsafe extern "system" fn batch_commit_ownership(this: *mut IAvnRustVmUpdateBatch2) -> i32 {
    ffi(|| {
        if this.is_null() {
            return Err(hresult::Error(hresult::E_POINTER));
        }
        let state = (*batch_object_from_ownership(this.cast())).state.clone();
        let ownership = state
            .ownership
            .lock()
            .map_err(|_| hresult::Error(hresult::E_FAIL))?
            .take();
        if let Some(ownership) = ownership {
            ownership();
        }
        Ok(())
    })
}

unsafe fn batch_state(this: *mut IAvnRustVmUpdateBatch) -> Result<Arc<RustVmBatchState>> {
    if this.is_null() {
        return Err(hresult::Error(hresult::E_POINTER));
    }
    Ok((*this.cast::<RustVmBatchObject>()).state.clone())
}

unsafe extern "system" fn batch_get_generation(
    this: *mut IAvnRustVmUpdateBatch,
    result: *mut i64,
) -> i32 {
    ffi(|| {
        if result.is_null() {
            return Err(hresult::Error(hresult::E_POINTER));
        }
        *result = batch_state(this)?.generation;
        Ok(())
    })
}

unsafe extern "system" fn batch_get_operation_count(
    this: *mut IAvnRustVmUpdateBatch,
    result: *mut i32,
) -> i32 {
    ffi(|| {
        if result.is_null() {
            return Err(hresult::Error(hresult::E_POINTER));
        }
        *result = i32::try_from(batch_state(this)?.operations.len())
            .map_err(|_| hresult::Error(hresult::E_INVALIDARG))?;
        Ok(())
    })
}

unsafe extern "system" fn batch_get_operation(
    this: *mut IAvnRustVmUpdateBatch,
    index: i32,
    result: *mut *mut IAvnRustVmUpdateOperation,
) -> i32 {
    ffi(|| {
        if result.is_null() {
            return Err(hresult::Error(hresult::E_POINTER));
        }
        *result = ptr::null_mut();
        let state = batch_state(this)?;
        let index = usize::try_from(index).map_err(|_| hresult::Error(hresult::E_INVALIDARG))?;
        if index >= state.operations.len() {
            return Err(hresult::Error(hresult::E_INVALIDARG));
        }
        let operation = Box::new(RustVmBatchOperationObject {
            interface: IAvnRustVmUpdateOperation {
                vtbl: &RUST_VM_BATCH_OPERATION_VTBL,
            },
            references: AtomicU32::new(1),
            state,
            index,
        });
        *result = Box::into_raw(operation).cast();
        Ok(())
    })
}

unsafe fn snapshot_operation(
    this: *mut IAvnRustVmUpdateBatch,
    operation: i32,
) -> Result<(Arc<RustVmBatchState>, usize)> {
    let state = batch_state(this)?;
    let index = usize::try_from(operation).map_err(|_| hresult::Error(hresult::E_INVALIDARG))?;
    if index >= state.operations.len() {
        return Err(hresult::Error(hresult::E_INVALIDARG));
    }
    Ok((state, index))
}

unsafe extern "system" fn batch_get_snapshot_item_count(
    this: *mut IAvnRustVmUpdateBatch,
    operation: i32,
    result: *mut i32,
) -> i32 {
    ffi(|| {
        if result.is_null() {
            return Err(hresult::Error(hresult::E_POINTER));
        }
        let (state, index) = snapshot_operation(this, operation)?;
        let update = &state.operations[index];
        let length = update
            .snapshot_strings
            .as_ref()
            .map(Vec::len)
            .or_else(|| update.snapshot_models.as_ref().map(Vec::len))
            .ok_or(hresult::Error(hresult::E_INVALIDARG))?;
        *result = i32::try_from(length).map_err(|_| hresult::Error(hresult::E_INVALIDARG))?;
        Ok(())
    })
}

unsafe extern "system" fn batch_get_snapshot_string_length(
    this: *mut IAvnRustVmUpdateBatch,
    operation: i32,
    item: i32,
    result: *mut i32,
) -> i32 {
    ffi(|| {
        if result.is_null() {
            return Err(hresult::Error(hresult::E_POINTER));
        }
        let (state, index) = snapshot_operation(this, operation)?;
        let item = usize::try_from(item).map_err(|_| hresult::Error(hresult::E_INVALIDARG))?;
        let value = state.operations[index]
            .snapshot_strings
            .as_ref()
            .and_then(|items| items.get(item))
            .ok_or(hresult::Error(hresult::E_INVALIDARG))?;
        *result = i32::try_from(value.encode_utf16().count())
            .map_err(|_| hresult::Error(hresult::E_INVALIDARG))?;
        Ok(())
    })
}

unsafe extern "system" fn batch_copy_snapshot_string(
    this: *mut IAvnRustVmUpdateBatch,
    operation: i32,
    item: i32,
    destination: *mut u16,
    capacity: i32,
) -> i32 {
    ffi(|| {
        let (state, index) = snapshot_operation(this, operation)?;
        let item = usize::try_from(item).map_err(|_| hresult::Error(hresult::E_INVALIDARG))?;
        let value = state.operations[index]
            .snapshot_strings
            .as_ref()
            .and_then(|items| items.get(item))
            .ok_or(hresult::Error(hresult::E_INVALIDARG))?;
        copy_utf16(value, destination, capacity)
    })
}

unsafe extern "system" fn batch_get_snapshot_model(
    this: *mut IAvnRustVmUpdateBatch,
    operation: i32,
    item: i32,
    result: *mut *mut IAvnRustViewModel,
) -> i32 {
    ffi(|| {
        if result.is_null() {
            return Err(hresult::Error(hresult::E_POINTER));
        }
        *result = ptr::null_mut();
        let (state, index) = snapshot_operation(this, operation)?;
        let item = usize::try_from(item).map_err(|_| hresult::Error(hresult::E_INVALIDARG))?;
        let model = state.operations[index]
            .snapshot_models
            .as_ref()
            .and_then(|items| items.get(item))
            .ok_or(hresult::Error(hresult::E_INVALIDARG))?;
        add_ref(model.as_raw().cast());
        *result = model.as_raw();
        Ok(())
    })
}

unsafe extern "system" fn batch_complete(
    this: *mut IAvnRustVmUpdateBatch,
    outcome: i32,
    error: i32,
) -> i32 {
    ffi(|| {
        let state = batch_state(this)?;
        let completion = state
            .completion
            .lock()
            .map_err(|_| hresult::Error(hresult::E_FAIL))?
            .take();
        if let Some(completion) = completion {
            completion(outcome, error);
        }
        Ok(())
    })
}

unsafe extern "system" fn operation_query_interface(
    this: *mut IUnknown,
    iid: *const Guid,
    result: *mut *mut c_void,
) -> i32 {
    if this.is_null() || iid.is_null() || result.is_null() {
        return hresult::E_POINTER;
    }
    *result = ptr::null_mut();
    if *iid != Guid::IUNKNOWN && *iid != IAVN_RUST_VM_UPDATE_OPERATION_IID {
        return hresult::E_NOINTERFACE;
    }
    operation_add_ref(this);
    *result = this.cast();
    hresult::S_OK
}

unsafe extern "system" fn operation_add_ref(this: *mut IUnknown) -> u32 {
    (*this.cast::<RustVmBatchOperationObject>())
        .references
        .fetch_add(1, Ordering::Relaxed)
        + 1
}

unsafe extern "system" fn operation_release(this: *mut IUnknown) -> u32 {
    let object = this.cast::<RustVmBatchOperationObject>();
    let remaining = (*object).references.fetch_sub(1, Ordering::Release) - 1;
    if remaining == 0 {
        fence(Ordering::Acquire);
        drop(Box::from_raw(object));
    }
    remaining
}

unsafe fn operation(this: *mut IAvnRustVmUpdateOperation) -> Result<Arc<RustVmBatchState>> {
    if this.is_null() {
        return Err(hresult::Error(hresult::E_POINTER));
    }
    Ok((*this.cast::<RustVmBatchOperationObject>()).state.clone())
}
unsafe fn operation_value(
    this: *mut IAvnRustVmUpdateOperation,
) -> Result<(Arc<RustVmBatchState>, usize)> {
    let object = this.cast::<RustVmBatchOperationObject>();
    let state = operation(this)?;
    Ok((state, (*object).index))
}
macro_rules! operation_get {
    ($name:ident, $type:ty, $field:ident) => {
        unsafe extern "system" fn $name(
            this: *mut IAvnRustVmUpdateOperation,
            result: *mut $type,
        ) -> i32 {
            ffi(|| {
                if result.is_null() {
                    return Err(hresult::Error(hresult::E_POINTER));
                }
                let (state, index) = operation_value(this)?;
                *result = state.operations[index].$field;
                Ok(())
            })
        }
    };
}
operation_get!(operation_get_kind, i32, kind);
operation_get!(operation_get_target_id, i32, target_id);
operation_get!(operation_get_index, i32, index);
operation_get!(operation_get_index2, i32, index2);
operation_get!(operation_get_integer, i64, integer);
operation_get!(operation_get_double, f64, double);
operation_get!(operation_get_boolean, i32, boolean);

unsafe extern "system" fn operation_get_text_length(
    this: *mut IAvnRustVmUpdateOperation,
    result: *mut i32,
) -> i32 {
    ffi(|| {
        if result.is_null() {
            return Err(hresult::Error(hresult::E_POINTER));
        }
        let (state, index) = operation_value(this)?;
        *result = match &state.operations[index].text {
            Some(value) => i32::try_from(value.encode_utf16().count())
                .map_err(|_| hresult::Error(hresult::E_INVALIDARG))?,
            None => 0,
        };
        Ok(())
    })
}

unsafe fn copy_utf16(value: &str, destination: *mut u16, capacity: i32) -> Result<()> {
    if destination.is_null() || capacity < 0 {
        return Err(hresult::Error(hresult::E_POINTER));
    }
    let units: Vec<u16> = value.encode_utf16().collect();
    if usize::try_from(capacity).map_err(|_| hresult::Error(hresult::E_INVALIDARG))?
        < units.len() + 1
    {
        return Err(hresult::Error(hresult::E_INVALIDARG));
    }
    ptr::copy_nonoverlapping(units.as_ptr(), destination, units.len());
    *destination.add(units.len()) = 0;
    Ok(())
}

unsafe extern "system" fn operation_copy_text(
    this: *mut IAvnRustVmUpdateOperation,
    destination: *mut u16,
    capacity: i32,
) -> i32 {
    ffi(|| {
        let (state, index) = operation_value(this)?;
        copy_utf16(
            state.operations[index].text.as_deref().unwrap_or(""),
            destination,
            capacity,
        )
    })
}

unsafe extern "system" fn operation_get_model(
    this: *mut IAvnRustVmUpdateOperation,
    result: *mut *mut IAvnRustViewModel,
) -> i32 {
    ffi(|| {
        if result.is_null() {
            return Err(hresult::Error(hresult::E_POINTER));
        }
        *result = ptr::null_mut();
        let (state, index) = operation_value(this)?;
        if let Some(model) = &state.operations[index].model {
            add_ref(model.as_raw().cast());
            *result = model.as_raw();
        }
        Ok(())
    })
}

unsafe fn ffi(action: impl FnOnce() -> Result<()>) -> i32 {
    match catch_unwind(AssertUnwindSafe(action)) {
        Ok(Ok(())) => hresult::S_OK,
        Ok(Err(error)) => error.0,
        Err(_) => hresult::E_FAIL,
    }
}
