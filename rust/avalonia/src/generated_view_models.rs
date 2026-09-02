//! Generated from view-model.ir.json. Do not edit.

#[repr(i64)]
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Priority {
    Low = 0,
    Normal = 1,
    High = 2,
}

impl std::convert::TryFrom<i64> for Priority {
    type Error = ();
    fn try_from(value: i64) -> std::result::Result<Self, ()> {
        match value {
            0 => Ok(Self::Low),
            1 => Ok(Self::Normal),
            2 => Ok(Self::High),
            _ => Err(()),
        }
    }
}

#[derive(Clone, Debug)]
pub struct SampleViewModelSink(crate::view_model::ViewModelSink);

impl SampleViewModelSink {
    pub fn set_name(&self, value: impl AsRef<str>) -> crate::Result<()> { self.0.set_string(1, value) }
    pub fn set_count(&self, value: i64) -> crate::Result<()> { self.0.set_integer(2, value) }
    pub fn set_new_item(&self, value: impl AsRef<str>) -> crate::Result<()> { self.0.set_string(3, value) }
    pub fn set_status(&self, value: impl AsRef<str>) -> crate::Result<()> { self.0.set_string(4, value) }
    pub fn set_nickname(&self, value: Option<impl AsRef<str>>) -> crate::Result<()> { match value { Some(value) => self.0.set_string(5, value), None => self.0.set_null(5) } }
    pub fn set_priority(&self, value: Priority) -> crate::Result<()> { self.0.set_integer(6, value as i64) }
    pub fn set_address<M: AddressViewModel>(&self, value: Option<M>) -> crate::Result<()> { self.0.set_model(7, value.map(|model| AddressViewModelDispatch { model })) }
    pub fn set_new_task_title(&self, value: impl AsRef<str>) -> crate::Result<()> { self.0.set_string(8, value) }
    pub fn add_items(&self, value: impl AsRef<str>) -> crate::Result<()> { self.0.add_string(1, value) }
    pub fn insert_items(&self, index: i32, value: impl AsRef<str>) -> crate::Result<()> { self.0.insert_string(1, index, value) }
    pub fn replace_items(&self, index: i32, value: impl AsRef<str>) -> crate::Result<()> { self.0.replace_string(1, index, value) }
    pub fn add_tasks(&self, value: impl TaskItemViewModel) -> crate::Result<()> { self.0.add_model(2, TaskItemViewModelDispatch { model: value }) }
    pub fn insert_tasks(&self, index: i32, value: impl TaskItemViewModel) -> crate::Result<()> { self.0.insert_model(2, index, TaskItemViewModelDispatch { model: value }) }
    pub fn replace_tasks(&self, index: i32, value: impl TaskItemViewModel) -> crate::Result<()> { self.0.replace_model(2, index, TaskItemViewModelDispatch { model: value }) }
    pub fn remove_items(&self, index: i32) -> crate::Result<()> { self.0.remove_string_at(1, index) }
    pub fn move_items(&self, from_index: i32, to_index: i32) -> crate::Result<()> { self.0.move_string_item(1, from_index, to_index) }
    pub fn clear_items(&self) -> crate::Result<()> { self.0.clear_string_collection(1) }
    pub fn remove_tasks(&self, index: i32) -> crate::Result<()> { self.0.remove_model_at(2, index) }
    pub fn move_tasks(&self, from_index: i32, to_index: i32) -> crate::Result<()> { self.0.move_model_item(2, from_index, to_index) }
    pub fn clear_tasks(&self) -> crate::Result<()> { self.0.clear_model_collection(2) }
    pub fn set_increment_enabled(&self, enabled: bool) -> crate::Result<()> { self.0.set_command_enabled(1, enabled) }
    pub fn set_add_enabled(&self, enabled: bool) -> crate::Result<()> { self.0.set_command_enabled(2, enabled) }
    pub fn set_save_enabled(&self, enabled: bool) -> crate::Result<()> { self.0.set_command_enabled(3, enabled) }
    pub fn set_clear_nickname_enabled(&self, enabled: bool) -> crate::Result<()> { self.0.set_command_enabled(4, enabled) }
    pub fn set_toggle_address_enabled(&self, enabled: bool) -> crate::Result<()> { self.0.set_command_enabled(5, enabled) }
    pub fn set_add_task_enabled(&self, enabled: bool) -> crate::Result<()> { self.0.set_command_enabled(6, enabled) }
    pub fn set_remove_first_task_enabled(&self, enabled: bool) -> crate::Result<()> { self.0.set_command_enabled(7, enabled) }
    pub fn set_shuffle_tasks_enabled(&self, enabled: bool) -> crate::Result<()> { self.0.set_command_enabled(8, enabled) }
    pub fn set_clear_tasks_enabled(&self, enabled: bool) -> crate::Result<()> { self.0.set_command_enabled(9, enabled) }
    pub fn set_name_error(&self, message: Option<&str>) -> crate::Result<()> { self.0.set_property_error(1, message) }
    pub fn set_count_error(&self, message: Option<&str>) -> crate::Result<()> { self.0.set_property_error(2, message) }
    pub fn set_new_item_error(&self, message: Option<&str>) -> crate::Result<()> { self.0.set_property_error(3, message) }
    pub fn set_status_error(&self, message: Option<&str>) -> crate::Result<()> { self.0.set_property_error(4, message) }
    pub fn set_nickname_error(&self, message: Option<&str>) -> crate::Result<()> { self.0.set_property_error(5, message) }
    pub fn set_priority_error(&self, message: Option<&str>) -> crate::Result<()> { self.0.set_property_error(6, message) }
    pub fn set_new_task_title_error(&self, message: Option<&str>) -> crate::Result<()> { self.0.set_property_error(8, message) }
    /// Creates a worker-safe immutable update batch with a monotonic generation.
    pub fn batch(&self, generation: i64) -> SampleViewModelSinkBatch { SampleViewModelSinkBatch(crate::view_model::ViewModelBatch::new(generation)) }
    pub fn submit_batch(&self, batch: SampleViewModelSinkBatch) -> crate::Result<crate::view_model::BatchCompletion> { self.0.submit_batch(batch.0) }
}

pub struct SampleViewModelSinkBatch(crate::view_model::ViewModelBatch);

impl SampleViewModelSinkBatch {
    pub fn set_name(&mut self, value: impl AsRef<str>) { self.0.push_string(1, 1, 0, value); }
    pub fn set_name_error(&mut self, message: impl AsRef<str>) { self.0.push_string(18, 1, 0, message); }
    pub fn set_count(&mut self, value: i64) { self.0.push_integer(2, value as i64); }
    pub fn set_count_error(&mut self, message: impl AsRef<str>) { self.0.push_string(18, 2, 0, message); }
    pub fn set_new_item(&mut self, value: impl AsRef<str>) { self.0.push_string(1, 3, 0, value); }
    pub fn set_new_item_error(&mut self, message: impl AsRef<str>) { self.0.push_string(18, 3, 0, message); }
    pub fn set_status(&mut self, value: impl AsRef<str>) { self.0.push_string(1, 4, 0, value); }
    pub fn set_status_error(&mut self, message: impl AsRef<str>) { self.0.push_string(18, 4, 0, message); }
    pub fn set_nickname(&mut self, value: Option<impl AsRef<str>>) { match value { Some(value) => self.0.push_string(1, 5, 0, value), None => self.0.push_null(5) } }
    pub fn set_nickname_error(&mut self, message: impl AsRef<str>) { self.0.push_string(18, 5, 0, message); }
    pub fn set_priority(&mut self, value: Priority) { self.0.push_integer(6, value as i64); }
    pub fn set_priority_error(&mut self, message: impl AsRef<str>) { self.0.push_string(18, 6, 0, message); }
    pub fn set_address(&mut self, value: impl AddressViewModel) { self.0.push_model(6, 7, 0, AddressViewModelDispatch { model: value }); }
    pub fn set_address_error(&mut self, message: impl AsRef<str>) { self.0.push_string(18, 7, 0, message); }
    pub fn set_new_task_title(&mut self, value: impl AsRef<str>) { self.0.push_string(1, 8, 0, value); }
    pub fn set_new_task_title_error(&mut self, message: impl AsRef<str>) { self.0.push_string(18, 8, 0, message); }
    pub fn add_items(&mut self, value: impl AsRef<str>) { self.0.push_string(7, 1, 0, value); }
    pub fn replace_items_snapshot<S: AsRef<str>>(&mut self, values: impl IntoIterator<Item = S>) { self.0.push_string_snapshot(1, values); }
    pub fn remove_items(&mut self, index: i32) { self.0.push_indices(13, 1, index, 0); }
    pub fn add_tasks(&mut self, value: impl TaskItemViewModel) { self.0.push_model(8, 2, 0, TaskItemViewModelDispatch { model: value }); }
    pub fn replace_tasks_snapshot<M: TaskItemViewModel>(&mut self, values: impl IntoIterator<Item = M>) { self.0.push_model_snapshot(2, values.into_iter().map(|value| TaskItemViewModelDispatch { model: value })); }
    pub fn set_increment_enabled(&mut self, enabled: bool) { self.0.push_boolean(17, 1, enabled); }
    pub fn set_add_enabled(&mut self, enabled: bool) { self.0.push_boolean(17, 2, enabled); }
    pub fn set_save_enabled(&mut self, enabled: bool) { self.0.push_boolean(17, 3, enabled); }
    pub fn set_clear_nickname_enabled(&mut self, enabled: bool) { self.0.push_boolean(17, 4, enabled); }
    pub fn set_toggle_address_enabled(&mut self, enabled: bool) { self.0.push_boolean(17, 5, enabled); }
    pub fn set_add_task_enabled(&mut self, enabled: bool) { self.0.push_boolean(17, 6, enabled); }
    pub fn set_remove_first_task_enabled(&mut self, enabled: bool) { self.0.push_boolean(17, 7, enabled); }
    pub fn set_shuffle_tasks_enabled(&mut self, enabled: bool) { self.0.push_boolean(17, 8, enabled); }
    pub fn set_clear_tasks_enabled(&mut self, enabled: bool) { self.0.push_boolean(17, 9, enabled); }
}

pub trait SampleViewModel: Send + 'static {
    fn attach(&mut self, sink: SampleViewModelSink) -> crate::Result<()>;
    fn detach(&mut self) -> crate::Result<()>;
    fn set_name(&mut self, value: String) -> crate::Result<()>;
    fn set_new_item(&mut self, value: String) -> crate::Result<()>;
    fn set_nickname(&mut self, value: String) -> crate::Result<()>;
    fn set_priority(&mut self, value: Priority) -> crate::Result<()>;
    fn set_new_task_title(&mut self, value: String) -> crate::Result<()>;
    fn increment(&mut self) -> crate::Result<()>;
    fn add(&mut self, value: String) -> crate::Result<()>;
    fn save(&mut self) -> crate::Result<()>;
    fn clear_nickname(&mut self) -> crate::Result<()>;
    fn toggle_address(&mut self) -> crate::Result<()>;
    fn add_task(&mut self, value: String) -> crate::Result<()>;
    fn remove_first_task(&mut self) -> crate::Result<()>;
    fn shuffle_tasks(&mut self) -> crate::Result<()>;
    fn clear_tasks(&mut self) -> crate::Result<()>;
}

struct SampleViewModelDispatch<T: SampleViewModel> { model: T }

impl<T: SampleViewModel> crate::view_model::DynamicViewModel for SampleViewModelDispatch<T> {
    fn attach(&mut self, sink: crate::view_model::ViewModelSink) -> crate::Result<()> { self.model.attach(SampleViewModelSink(sink)) }
    fn detach(&mut self) -> crate::Result<()> { self.model.detach() }
    fn set_string(&mut self, property_id: i32, value: String) -> crate::Result<()> {
        match property_id {
            1 => self.model.set_name(value),
            3 => self.model.set_new_item(value),
            5 => self.model.set_nickname(value),
            8 => self.model.set_new_task_title(value),
            _ => Err(crate::Error::InvalidViewModelMember { kind: "property", id: property_id }),
        }
    }
    fn set_integer(&mut self, property_id: i32, value: i64) -> crate::Result<()> {
        match property_id {
            6 => self.model.set_priority(Priority::try_from(value).map_err(|_| crate::Error::InvalidViewModelMember { kind: "property", id: property_id })?),
            _ => Err(crate::Error::InvalidViewModelMember { kind: "property", id: property_id }),
        }
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
            4 => self.model.clear_nickname(),
            5 => self.model.toggle_address(),
            6 => self.model.add_task(parameter.unwrap_or_default()),
            7 => self.model.remove_first_task(),
            8 => self.model.shuffle_tasks(),
            9 => self.model.clear_tasks(),
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
impl crate::AppScope {
    pub fn mount_rust_vm_window_with_converters<C: ValueConverters>(
        &self,
        model: impl SampleViewModel,
        converters: C,
    ) -> crate::Result<()> {
        self.register_value_converters(converters)?;
        self.mount_rust_vm_window(model)
    }
}
impl crate::AppScope { pub fn mount_rust_dynamic_vm_window(&self, model: impl SampleViewModel) -> crate::Result<()> { self.mount_dynamic_view_model(2, SampleViewModelDispatch { model }) } }
impl crate::AppScope {
    pub fn mount_rust_dynamic_vm_window_with_converters<C: ValueConverters>(
        &self,
        model: impl SampleViewModel,
        converters: C,
    ) -> crate::Result<()> {
        self.register_value_converters(converters)?;
        self.mount_rust_dynamic_vm_window(model)
    }
}

#[derive(Clone, Debug)]
pub struct AddressViewModelSink(crate::view_model::ViewModelSink);

impl AddressViewModelSink {
    pub fn set_street(&self, value: impl AsRef<str>) -> crate::Result<()> { self.0.set_string(1, value) }
    pub fn set_city(&self, value: impl AsRef<str>) -> crate::Result<()> { self.0.set_string(2, value) }
    pub fn set_street_error(&self, message: Option<&str>) -> crate::Result<()> { self.0.set_property_error(1, message) }
    pub fn set_city_error(&self, message: Option<&str>) -> crate::Result<()> { self.0.set_property_error(2, message) }
    /// Creates a worker-safe immutable update batch with a monotonic generation.
    pub fn batch(&self, generation: i64) -> AddressViewModelSinkBatch { AddressViewModelSinkBatch(crate::view_model::ViewModelBatch::new(generation)) }
    pub fn submit_batch(&self, batch: AddressViewModelSinkBatch) -> crate::Result<crate::view_model::BatchCompletion> { self.0.submit_batch(batch.0) }
}

pub struct AddressViewModelSinkBatch(crate::view_model::ViewModelBatch);

impl AddressViewModelSinkBatch {
    pub fn set_street(&mut self, value: impl AsRef<str>) { self.0.push_string(1, 1, 0, value); }
    pub fn set_street_error(&mut self, message: impl AsRef<str>) { self.0.push_string(18, 1, 0, message); }
    pub fn set_city(&mut self, value: impl AsRef<str>) { self.0.push_string(1, 2, 0, value); }
    pub fn set_city_error(&mut self, message: impl AsRef<str>) { self.0.push_string(18, 2, 0, message); }
}

pub trait AddressViewModel: Send + 'static {
    fn attach(&mut self, sink: AddressViewModelSink) -> crate::Result<()>;
    fn detach(&mut self) -> crate::Result<()>;
    fn set_street(&mut self, value: String) -> crate::Result<()>;
    fn set_city(&mut self, value: String) -> crate::Result<()>;
}

struct AddressViewModelDispatch<T: AddressViewModel> { model: T }

impl<T: AddressViewModel> crate::view_model::DynamicViewModel for AddressViewModelDispatch<T> {
    fn attach(&mut self, sink: crate::view_model::ViewModelSink) -> crate::Result<()> { self.model.attach(AddressViewModelSink(sink)) }
    fn detach(&mut self) -> crate::Result<()> { self.model.detach() }
    fn set_string(&mut self, property_id: i32, value: String) -> crate::Result<()> {
        match property_id {
            1 => self.model.set_street(value),
            2 => self.model.set_city(value),
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
    fn execute(&mut self, command_id: i32, _parameter: Option<String>) -> crate::Result<()> {
        match command_id {
            _ => Err(crate::Error::InvalidViewModelMember { kind: "command", id: command_id }),
        }
    }
    fn begin_async(&mut self, command_id: i32, _parameter: Option<String>) -> crate::Result<()> {
        match command_id {
            _ => Err(crate::Error::InvalidViewModelMember { kind: "command", id: command_id }),
        }
    }
}


#[derive(Clone, Debug)]
pub struct TaskItemViewModelSink(crate::view_model::ViewModelSink);

impl TaskItemViewModelSink {
    pub fn set_title(&self, value: impl AsRef<str>) -> crate::Result<()> { self.0.set_string(1, value) }
    pub fn set_done(&self, value: bool) -> crate::Result<()> { self.0.set_boolean(2, value) }
    pub fn set_title_error(&self, message: Option<&str>) -> crate::Result<()> { self.0.set_property_error(1, message) }
    pub fn set_done_error(&self, message: Option<&str>) -> crate::Result<()> { self.0.set_property_error(2, message) }
    /// Creates a worker-safe immutable update batch with a monotonic generation.
    pub fn batch(&self, generation: i64) -> TaskItemViewModelSinkBatch { TaskItemViewModelSinkBatch(crate::view_model::ViewModelBatch::new(generation)) }
    pub fn submit_batch(&self, batch: TaskItemViewModelSinkBatch) -> crate::Result<crate::view_model::BatchCompletion> { self.0.submit_batch(batch.0) }
}

pub struct TaskItemViewModelSinkBatch(crate::view_model::ViewModelBatch);

impl TaskItemViewModelSinkBatch {
    pub fn set_title(&mut self, value: impl AsRef<str>) { self.0.push_string(1, 1, 0, value); }
    pub fn set_title_error(&mut self, message: impl AsRef<str>) { self.0.push_string(18, 1, 0, message); }
    pub fn set_done(&mut self, value: bool) { self.0.push_boolean(3, 2, value); }
    pub fn set_done_error(&mut self, message: impl AsRef<str>) { self.0.push_string(18, 2, 0, message); }
}

pub trait TaskItemViewModel: Send + 'static {
    fn attach(&mut self, sink: TaskItemViewModelSink) -> crate::Result<()>;
    fn detach(&mut self) -> crate::Result<()>;
    fn set_done(&mut self, value: bool) -> crate::Result<()>;
}

struct TaskItemViewModelDispatch<T: TaskItemViewModel> { model: T }

impl<T: TaskItemViewModel> crate::view_model::DynamicViewModel for TaskItemViewModelDispatch<T> {
    fn attach(&mut self, sink: crate::view_model::ViewModelSink) -> crate::Result<()> { self.model.attach(TaskItemViewModelSink(sink)) }
    fn detach(&mut self) -> crate::Result<()> { self.model.detach() }
    fn set_string(&mut self, property_id: i32, _value: String) -> crate::Result<()> {
        Err(crate::Error::InvalidViewModelMember { kind: "property", id: property_id })
    }
    fn set_integer(&mut self, property_id: i32, _value: i64) -> crate::Result<()> {
        Err(crate::Error::InvalidViewModelMember { kind: "property", id: property_id })
    }
    fn set_boolean(&mut self, property_id: i32, value: bool) -> crate::Result<()> {
        match property_id {
            2 => self.model.set_done(value),
            _ => Err(crate::Error::InvalidViewModelMember { kind: "property", id: property_id }),
        }
    }
    fn set_double(&mut self, property_id: i32, _value: f64) -> crate::Result<()> {
        Err(crate::Error::InvalidViewModelMember { kind: "property", id: property_id })
    }
    fn execute(&mut self, command_id: i32, _parameter: Option<String>) -> crate::Result<()> {
        match command_id {
            _ => Err(crate::Error::InvalidViewModelMember { kind: "command", id: command_id }),
        }
    }
    fn begin_async(&mut self, command_id: i32, _parameter: Option<String>) -> crate::Result<()> {
        match command_id {
            _ => Err(crate::Error::InvalidViewModelMember { kind: "command", id: command_id }),
        }
    }
}


pub trait ValueConverters: Send + Sync + 'static {
    fn count_to_label(&self, value: i64) -> String;
}

struct ValueConvertersDispatch<T: ValueConverters> { converters: T }

impl<T: ValueConverters> crate::value_converter::ValueConverterDispatch for ValueConvertersDispatch<T> {
    fn convert(
        &self,
        converter_id: i32,
        direction: crate::ConversionDirection,
        value: crate::ScalarValue,
        _parameter: crate::ScalarValue,
        _target_kind: crate::ScalarKind,
        _culture: &str,
    ) -> crate::Result<crate::ScalarValue> {
        use crate::{ConversionDirection, ScalarValue};
        match (converter_id, direction) {
            (1, ConversionDirection::Convert) => {
                let value = match value { ScalarValue::Int64(value) => value, ScalarValue::Unset => return Ok(ScalarValue::Unset), ScalarValue::DoNothing => return Ok(ScalarValue::DoNothing), ScalarValue::Null => return Ok(ScalarValue::Null), _ => return Err(crate::Error::InvalidViewModelMember { kind: "converter-value", id: 1 }) };
                Ok(ScalarValue::String(self.converters.count_to_label(value)))
            }
            _ => Err(crate::Error::InvalidViewModelMember { kind: "converter", id: converter_id }),
        }
    }
}

impl crate::AppScope {
    pub fn register_value_converters(&self, converters: impl ValueConverters) -> crate::Result<()> {
        self.register_value_converter_dispatch(ValueConvertersDispatch { converters })
    }
}
