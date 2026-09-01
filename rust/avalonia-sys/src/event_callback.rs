use crate::com::{ComInterface, ComPtr, IUnknown};
use crate::guid::Guid;
use crate::hresult::{self, Result};
use std::ffi::c_void;
use std::panic::{catch_unwind, AssertUnwindSafe};
use std::ptr;
use std::sync::atomic::{fence, AtomicU32, Ordering};
use std::sync::Mutex;

type EventCallback = Box<dyn FnMut() -> Result<()> + Send>;

#[repr(C)]
pub(crate) struct EventHandlerObject<I> {
    interface: I,
    ref_count: AtomicU32,
    callback: Mutex<Option<EventCallback>>,
}

pub(crate) fn create<I: ComInterface>(
    interface: I,
    callback: impl FnMut() -> Result<()> + Send + 'static,
) -> ComPtr<I> {
    let object = Box::new(EventHandlerObject {
        interface,
        ref_count: AtomicU32::new(1),
        callback: Mutex::new(Some(Box::new(callback))),
    });
    unsafe {
        ComPtr::from_raw(Box::into_raw(object).cast())
            .expect("Box allocation cannot produce a null pointer")
    }
}

pub(crate) unsafe fn query_interface<I: ComInterface>(
    this: *mut IUnknown,
    iid: *const Guid,
    result: *mut *mut c_void,
) -> i32 {
    if iid.is_null() || result.is_null() {
        return hresult::E_POINTER;
    }
    *result = ptr::null_mut();
    if *iid != Guid::IUNKNOWN && *iid != I::IID {
        return hresult::E_NOINTERFACE;
    }
    add_ref::<I>(this);
    *result = this.cast();
    hresult::S_OK
}

pub(crate) unsafe fn add_ref<I>(this: *mut IUnknown) -> u32 {
    let object = this.cast::<EventHandlerObject<I>>();
    (*object).ref_count.fetch_add(1, Ordering::Relaxed) + 1
}

pub(crate) unsafe fn release<I>(this: *mut IUnknown) -> u32 {
    let object = this.cast::<EventHandlerObject<I>>();
    let remaining = (*object).ref_count.fetch_sub(1, Ordering::Release) - 1;
    if remaining == 0 {
        fence(Ordering::Acquire);
        drop(Box::from_raw(object));
    }
    remaining
}

pub(crate) unsafe fn invoke<I>(this: *mut I) -> i32 {
    let object = this.cast::<EventHandlerObject<I>>();
    let callback = {
        let mut callback = match (*object).callback.lock() {
            Ok(callback) => callback,
            Err(_) => return hresult::E_FAIL,
        };
        match callback.take() {
            Some(callback) => callback,
            None => return hresult::E_FAIL,
        }
    };
    let mut callback = callback;
    let result = catch_unwind(AssertUnwindSafe(&mut callback));
    if let Ok(mut slot) = (*object).callback.lock() {
        *slot = Some(callback);
    } else {
        return hresult::E_FAIL;
    }
    match result {
        Ok(Ok(())) => hresult::S_OK,
        Ok(Err(error)) => error.0,
        Err(_) => hresult::E_FAIL,
    }
}
