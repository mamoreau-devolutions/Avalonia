//! Raw nano-COM bindings for the Avalonia NativeAOT host.
//!
//! Handwritten for the phase-0 fixture. Later phases replace interface
//! vtables with IR-generated code; `ComPtr` / `Host` stay.

mod application;
mod com;
mod echo;
mod factory;
mod guid;
mod hresult;

pub use com::{ComInterface, ComPtr, IUnknown};
pub use application::IAvnApplication;
pub use echo::IAvnEcho;
pub use factory::IAvnActivationFactory;
pub use guid::Guid;
pub use hresult::{Error, Result, AVN_E_FIXTURE, E_FAIL, E_INVALIDARG, E_NOINTERFACE, E_POINTER, S_OK};

use libloading::Library;
use std::ffi::c_void;
use std::path::Path;

type GetActivationFactoryFn = unsafe extern "C" fn(*mut *mut c_void) -> i32;
type FreeFn = unsafe extern "C" fn(*mut c_void);

pub struct Host {
    _lib: Library,
    get_activation_factory: GetActivationFactoryFn,
    free: FreeFn,
}

impl Host {
    pub fn load(path: impl AsRef<Path>) -> std::result::Result<Self, libloading::Error> {
        unsafe {
            let lib = Library::new(path.as_ref())?;
            let get_activation_factory = *lib.get::<GetActivationFactoryFn>(b"avn_get_activation_factory\0")?;
            let free = *lib.get::<FreeFn>(b"avn_free\0")?;
            Ok(Self {
                _lib: lib,
                get_activation_factory,
                free,
            })
        }
    }

    pub fn activation_factory(&self) -> Result<ComPtr<IAvnActivationFactory>> {
        unsafe {
            let mut unk = std::ptr::null_mut();
            hresult::check((self.get_activation_factory)(&mut unk))?;
            let unk = ComPtr::<IUnknown>::from_raw(unk.cast()).ok_or(Error(hresult::E_POINTER))?;
            unk.query_interface()
        }
    }

    pub unsafe fn free(&self, ptr: *mut c_void) {
        if !ptr.is_null() {
            (self.free)(ptr);
        }
    }
}
