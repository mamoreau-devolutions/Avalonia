use crate::com::{ComInterface, ComPtr, IUnknown};
use crate::guid::Guid;
use crate::hresult::{self, Result};
use std::ffi::c_void;

#[repr(C)]
struct IAvnApplicationVtbl {
    query_interface: unsafe extern "system" fn(*mut IUnknown, *const Guid, *mut *mut c_void) -> i32,
    add_ref: unsafe extern "system" fn(*mut IUnknown) -> u32,
    release: unsafe extern "system" fn(*mut IUnknown) -> u32,
    run: unsafe extern "system" fn(*mut IAvnApplication, *mut c_void) -> i32,
    shutdown: unsafe extern "system" fn(*mut IAvnApplication) -> i32,
}

#[repr(C)]
pub struct IAvnApplication {
    vtbl: *const IAvnApplicationVtbl,
}

unsafe impl ComInterface for IAvnApplication {
    const IID: Guid = Guid::IAVN_APPLICATION;
}

impl ComPtr<IAvnApplication> {
    pub fn shutdown(&self) -> Result<()> {
        unsafe {
            let hr = ((*self.as_raw()).vtbl.as_ref().unwrap().shutdown)(self.as_raw());
            hresult::check(hr)
        }
    }
}
