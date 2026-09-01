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
    data4: [0x9A, 0x77, 0x1F, 0x0C, 0x2B, 0x3A, 0x4D, 0x20],
};

const IAVN_RUST_VM_SINK_IID: Guid = Guid {
    data1: 0x6B2E8F10,
    data2: 0x4C91,
    data3: 0x4E3A,
    data4: [0x9A, 0x77, 0x1F, 0x0C, 0x2B, 0x3A, 0x4D, 0x21],
};

#[repr(C)]
struct IAvnRustVmSinkVtbl {
    query_interface: unsafe extern "system" fn(*mut IUnknown, *const Guid, *mut *mut c_void) -> i32,
    add_ref: unsafe extern "system" fn(*mut IUnknown) -> u32,
    release: unsafe extern "system" fn(*mut IUnknown) -> u32,
    set_name: unsafe extern "system" fn(*mut IAvnRustVmSink, *const u16) -> i32,
    set_count: unsafe extern "system" fn(*mut IAvnRustVmSink, i32) -> i32,
    add_item: unsafe extern "system" fn(*mut IAvnRustVmSink, *const u16) -> i32,
    set_status: unsafe extern "system" fn(*mut IAvnRustVmSink, *const u16) -> i32,
}

#[repr(C)]
pub struct IAvnRustVmSink {
    vtbl: *const IAvnRustVmSinkVtbl,
}

unsafe impl ComInterface for IAvnRustVmSink {
    const IID: Guid = IAVN_RUST_VM_SINK_IID;
}

impl ComPtr<IAvnRustVmSink> {
    pub fn set_name(&self, value: &[u16]) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().set_name)(
                self.as_raw(),
                value.as_ptr(),
            ))
        }
    }

    pub fn set_count(&self, value: i32) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().set_count)(
                self.as_raw(),
                value,
            ))
        }
    }

    pub fn add_item(&self, value: &[u16]) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().add_item)(
                self.as_raw(),
                value.as_ptr(),
            ))
        }
    }

    pub fn set_status(&self, value: &[u16]) -> Result<()> {
        unsafe {
            hresult::check(((*self.as_raw()).vtbl.as_ref().unwrap().set_status)(
                self.as_raw(),
                value.as_ptr(),
            ))
        }
    }
}

pub struct RustViewModelCallbacks {
    pub attach: Box<dyn FnMut(ComPtr<IAvnRustVmSink>) -> Result<()> + Send>,
    pub detach: Box<dyn FnMut() -> Result<()> + Send>,
    pub set_name: Box<dyn FnMut(String) -> Result<()> + Send>,
    pub increment: Box<dyn FnMut() -> Result<()> + Send>,
    pub add_item: Box<dyn FnMut(String) -> Result<()> + Send>,
    pub begin_save: Box<dyn FnMut() -> Result<()> + Send>,
}

#[repr(C)]
struct IAvnRustViewModelVtbl {
    query_interface: unsafe extern "system" fn(*mut IUnknown, *const Guid, *mut *mut c_void) -> i32,
    add_ref: unsafe extern "system" fn(*mut IUnknown) -> u32,
    release: unsafe extern "system" fn(*mut IUnknown) -> u32,
    attach: unsafe extern "system" fn(*mut IAvnRustViewModel, *mut IAvnRustVmSink) -> i32,
    detach: unsafe extern "system" fn(*mut IAvnRustViewModel) -> i32,
    set_name: unsafe extern "system" fn(*mut IAvnRustViewModel, *const u16) -> i32,
    increment: unsafe extern "system" fn(*mut IAvnRustViewModel) -> i32,
    add_item: unsafe extern "system" fn(*mut IAvnRustViewModel, *const u16) -> i32,
    begin_save: unsafe extern "system" fn(*mut IAvnRustViewModel) -> i32,
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
    set_name,
    increment,
    add_item,
    begin_save,
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

unsafe extern "system" fn set_name(this: *mut IAvnRustViewModel, value: *const u16) -> i32 {
    let value = crate::clone_utf16(value).unwrap_or_default();
    invoke(this, |callbacks| (callbacks.set_name)(value))
}

unsafe extern "system" fn increment(this: *mut IAvnRustViewModel) -> i32 {
    invoke(this, |callbacks| (callbacks.increment)())
}

unsafe extern "system" fn add_item(this: *mut IAvnRustViewModel, value: *const u16) -> i32 {
    let value = crate::clone_utf16(value).unwrap_or_default();
    invoke(this, |callbacks| (callbacks.add_item)(value))
}

unsafe extern "system" fn begin_save(this: *mut IAvnRustViewModel) -> i32 {
    invoke(this, |callbacks| (callbacks.begin_save)())
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
