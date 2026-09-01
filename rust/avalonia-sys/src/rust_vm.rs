use crate::com::{ComInterface, ComPtr, IUnknown};
use crate::guid::Guid;
use crate::hresult::{self, Result};
use std::ffi::c_void;
use std::panic::{catch_unwind, AssertUnwindSafe};
use std::ptr;
use std::sync::atomic::{fence, AtomicU32, Ordering};
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
