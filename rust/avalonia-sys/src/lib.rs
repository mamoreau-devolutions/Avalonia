//! Raw nano-COM bindings for the Avalonia NativeAOT host.
//!
//! Handwritten for the phase-0 fixture. Later phases replace interface
//! vtables with IR-generated code; `ComPtr` / `Host` stay.

mod application;
mod app_handler;
mod com;
mod echo;
mod factory;
mod generated;
mod guid;
mod hresult;

pub use com::{ComInterface, ComPtr, IUnknown};
pub use application::IAvnApplication;
pub use app_handler::{app_handler, IAvnAppHandler};
pub use echo::IAvnEcho;
pub use factory::IAvnActivationFactory;
pub use generated::*;
pub use guid::Guid;
pub use hresult::{Error, Result, AVN_E_FIXTURE, E_FAIL, E_INVALIDARG, E_NOINTERFACE, E_POINTER, S_OK};

use libloading::Library;
use std::ffi::c_void;
use std::mem::ManuallyDrop;
use std::path::Path;

type GetActivationFactoryFn = unsafe extern "C" fn(*mut *mut c_void) -> i32;
type FreeFn = unsafe extern "C" fn(*mut c_void);
type GetLastErrorFn = unsafe extern "C" fn(*mut *mut u16) -> i32;

pub struct Host {
    _lib: ManuallyDrop<Library>,
    _dependencies: ManuallyDrop<Vec<Library>>,
    get_activation_factory: GetActivationFactoryFn,
    free: FreeFn,
    get_last_error: GetLastErrorFn,
}

impl Host {
    pub fn load(path: impl AsRef<Path>) -> std::result::Result<Self, libloading::Error> {
        unsafe {
            let path = path.as_ref();
            let directory = path.parent().unwrap_or_else(|| Path::new("."));
            let mut dependencies = Vec::new();
            #[cfg(target_os = "windows")]
            for name in ["libSkiaSharp.dll", "libHarfBuzzSharp.dll"] {
                let dependency = directory.join(name);
                if dependency.exists() {
                    dependencies.push(Library::new(dependency)?);
                }
            }
            #[cfg(target_os = "linux")]
            for name in ["libSkiaSharp.so", "libHarfBuzzSharp.so"] {
                let dependency = directory.join(name);
                if dependency.exists() {
                    dependencies.push(Library::new(dependency)?);
                }
            }
            #[cfg(target_os = "macos")]
            for name in ["libSkiaSharp.dylib", "libHarfBuzzSharp.dylib"] {
                let dependency = directory.join(name);
                if dependency.exists() {
                    dependencies.push(Library::new(dependency)?);
                }
            }
            let lib = Library::new(path)?;
            let get_activation_factory = *lib.get::<GetActivationFactoryFn>(b"avn_get_activation_factory\0")?;
            let free = *lib.get::<FreeFn>(b"avn_free\0")?;
            let get_last_error = *lib.get::<GetLastErrorFn>(b"avn_get_last_error\0")?;
            Ok(Self {
                _lib: ManuallyDrop::new(lib),
                _dependencies: ManuallyDrop::new(dependencies),
                get_activation_factory,
                free,
                get_last_error,
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

    pub fn last_error(&self) -> Option<String> {
        unsafe {
            let mut value = std::ptr::null_mut();
            if (self.get_last_error)(&mut value) < 0 || value.is_null() {
                return None;
            }
            let mut len = 0;
            while *value.add(len) != 0 {
                len += 1;
            }
            let result = String::from_utf16_lossy(std::slice::from_raw_parts(value, len));
            (self.free)(value.cast());
            Some(result)
        }
    }
}
