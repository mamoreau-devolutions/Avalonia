use crate::{AppScope, Error, Result, Window};
use avalonia_sys as sys;
use std::sync::{Arc, Mutex};

#[derive(Clone, Debug)]
pub struct RustVmSink {
    raw: sys::ComPtr<sys::IAvnRustVmSink>,
}

impl RustVmSink {
    pub fn set_name(&self, value: impl AsRef<str>) -> Result<()> {
        self.raw.set_name(&utf16(value))?;
        Ok(())
    }

    pub fn set_count(&self, value: i32) -> Result<()> {
        self.raw.set_count(value)?;
        Ok(())
    }

    pub fn add_item(&self, value: impl AsRef<str>) -> Result<()> {
        self.raw.add_item(&utf16(value))?;
        Ok(())
    }

    pub fn set_status(&self, value: impl AsRef<str>) -> Result<()> {
        self.raw.set_status(&utf16(value))?;
        Ok(())
    }
}

pub trait RustViewModel: Send + 'static {
    fn attach(&mut self, sink: RustVmSink) -> Result<()>;
    fn detach(&mut self) -> Result<()>;
    fn set_name(&mut self, value: String) -> Result<()>;
    fn increment(&mut self) -> Result<()>;
    fn add_item(&mut self, value: String) -> Result<()>;
    fn begin_save(&mut self) -> Result<()>;
}

struct RustViewModelHandle {
    raw: sys::ComPtr<sys::IAvnRustViewModel>,
}

impl RustViewModelHandle {
    fn new(model: impl RustViewModel) -> Self {
        let model = Arc::new(Mutex::new(model));
        let attach_model = model.clone();
        let detach_model = model.clone();
        let name_model = model.clone();
        let increment_model = model.clone();
        let item_model = model.clone();
        let save_model = model;
        let raw = sys::rust_view_model(sys::RustViewModelCallbacks {
            attach: Box::new(move |sink| {
                map_result(
                    attach_model
                        .lock()
                        .expect("Rust view-model lock poisoned")
                        .attach(RustVmSink { raw: sink }),
                )
            }),
            detach: Box::new(move || {
                map_result(
                    detach_model
                        .lock()
                        .expect("Rust view-model lock poisoned")
                        .detach(),
                )
            }),
            set_name: Box::new(move |value| {
                map_result(
                    name_model
                        .lock()
                        .expect("Rust view-model lock poisoned")
                        .set_name(value),
                )
            }),
            increment: Box::new(move || {
                map_result(
                    increment_model
                        .lock()
                        .expect("Rust view-model lock poisoned")
                        .increment(),
                )
            }),
            add_item: Box::new(move |value| {
                map_result(
                    item_model
                        .lock()
                        .expect("Rust view-model lock poisoned")
                        .add_item(value),
                )
            }),
            begin_save: Box::new(move || {
                map_result(
                    save_model
                        .lock()
                        .expect("Rust view-model lock poisoned")
                        .begin_save(),
                )
            }),
        });
        Self { raw }
    }
}

impl AppScope {
    pub fn mount_view_model(&self, model: impl RustViewModel) -> Result<()> {
        let model = RustViewModelHandle::new(model);
        let raw = self.application().create_rust_vm_window(&model.raw)?;
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
