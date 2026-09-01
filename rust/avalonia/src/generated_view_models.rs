//! Generated from view-model.ir.json. Do not edit.

#[derive(Clone, Debug)]
pub struct SampleViewModelSink(crate::view_model::ViewModelSink);

impl SampleViewModelSink {
    pub fn set_name(&self, value: impl AsRef<str>) -> crate::Result<()> { self.0.set_string(1, value) }
    pub fn set_count(&self, value: i64) -> crate::Result<()> { self.0.set_integer(2, value) }
    pub fn set_new_item(&self, value: impl AsRef<str>) -> crate::Result<()> { self.0.set_string(3, value) }
    pub fn set_status(&self, value: impl AsRef<str>) -> crate::Result<()> { self.0.set_string(4, value) }
    pub fn add_items(&self, value: impl AsRef<str>) -> crate::Result<()> { self.0.add_string(1, value) }
}

pub trait SampleViewModel: Send + 'static {
    fn attach(&mut self, sink: SampleViewModelSink) -> crate::Result<()>;
    fn detach(&mut self) -> crate::Result<()>;
    fn set_name(&mut self, value: String) -> crate::Result<()>;
    fn set_new_item(&mut self, value: String) -> crate::Result<()>;
    fn increment(&mut self) -> crate::Result<()>;
    fn add(&mut self, value: String) -> crate::Result<()>;
    fn save(&mut self) -> crate::Result<()>;
}

struct SampleViewModelDispatch<T: SampleViewModel> { model: T }

impl<T: SampleViewModel> crate::view_model::DynamicViewModel for SampleViewModelDispatch<T> {
    fn attach(&mut self, sink: crate::view_model::ViewModelSink) -> crate::Result<()> { self.model.attach(SampleViewModelSink(sink)) }
    fn detach(&mut self) -> crate::Result<()> { self.model.detach() }
    fn set_string(&mut self, property_id: i32, value: String) -> crate::Result<()> {
        match property_id {
            1 => self.model.set_name(value),
            3 => self.model.set_new_item(value),
            _ => Err(crate::Error::InvalidViewModelMember { kind: "property", id: property_id }),
        }
    }
    fn set_integer(&mut self, property_id: i32, _value: i64) -> crate::Result<()> {
        Err(crate::Error::InvalidViewModelMember { kind: "property", id: property_id })
    }
    fn set_boolean(&mut self, property_id: i32, _value: bool) -> crate::Result<()> {
        Err(crate::Error::InvalidViewModelMember { kind: "property", id: property_id })
    }
    fn set_double(&mut self, property_id: i32, _value: f64) -> crate::Result<()> {
        Err(crate::Error::InvalidViewModelMember { kind: "property", id: property_id })
    }
    fn execute(&mut self, command_id: i32, parameter: Option<String>) -> crate::Result<()> {
        match command_id {
            1 => self.model.increment(),
            2 => self.model.add(parameter.unwrap_or_default()),
            _ => Err(crate::Error::InvalidViewModelMember { kind: "command", id: command_id }),
        }
    }
    fn begin_async(&mut self, command_id: i32, _parameter: Option<String>) -> crate::Result<()> {
        match command_id {
            3 => self.model.save(),
            _ => Err(crate::Error::InvalidViewModelMember { kind: "command", id: command_id }),
        }
    }
}

impl crate::AppScope { pub fn mount_rust_vm_window(&self, model: impl SampleViewModel) -> crate::Result<()> { self.mount_dynamic_view_model(1, SampleViewModelDispatch { model }) } }
