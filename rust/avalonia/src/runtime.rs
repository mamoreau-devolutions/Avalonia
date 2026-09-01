use crate::{Error, Result};
use avalonia_sys as sys;
use std::cell::RefCell;
use std::path::Path;

thread_local! {
    static FACTORY: RefCell<Option<sys::ComPtr<sys::IAvnControlFactory>>> = const { RefCell::new(None) };
}

pub trait AsControl {
    fn as_control(&self) -> Result<sys::ComPtr<sys::IAvnControl>>;
}

pub struct App {
    application: sys::ComPtr<sys::IAvnApplication>,
    controls: sys::ComPtr<sys::IAvnControlFactory>,
    _host: sys::Host,
}

impl App {
    pub fn load(path: impl AsRef<Path>) -> Result<Self> {
        let host = sys::Host::load(path).map_err(|error| Error::Load(error.to_string()))?;
        let activation = host.activation_factory()?;
        let application = activation.create_application()?;
        let controls = activation.create_control_factory()?;
        Ok(Self {
            application,
            controls,
            _host: host,
        })
    }

    pub fn run(self, callback: impl FnOnce() -> Result<()> + Send + 'static) -> Result<()> {
        let controls = self.controls.clone();
        let handler = sys::app_handler(move || {
            FACTORY.with(|current| {
                let previous = current.replace(Some(controls));
                let result = callback().map_err(to_abi_error);
                current.replace(previous);
                result
            })
        });
        Ok(self.application.run(&handler)?)
    }
}

pub(crate) fn with_factory<T>(
    callback: impl FnOnce(&sys::ComPtr<sys::IAvnControlFactory>) -> sys::Result<T>,
) -> Result<T> {
    FACTORY.with(|factory| {
        let factory = factory.borrow();
        let factory = factory.as_ref().ok_or(Error::NoUiContext)?;
        Ok(callback(factory)?)
    })
}

fn to_abi_error(error: Error) -> sys::Error {
    match error {
        Error::Abi(error) => error,
        Error::Load(_) | Error::NoUiContext | Error::InvalidEnumValue(_) => sys::Error(sys::E_FAIL),
    }
}
