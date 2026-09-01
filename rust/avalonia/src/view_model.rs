use crate::{AppScope, Error, Result, Window};
use avalonia_sys as sys;
use std::sync::{Arc, Mutex};

#[derive(Clone, Debug)]
pub(crate) struct ViewModelSink {
    raw: sys::ComPtr<sys::IAvnRustVmSink>,
}

impl ViewModelSink {
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
}

pub(crate) trait DynamicViewModel: Send + 'static {
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
                map_result(
                    attach_model
                        .lock()
                        .expect("Rust view-model lock poisoned")
                        .attach(ViewModelSink { raw: sink }),
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
    pub(crate) fn mount_dynamic_view_model(
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
