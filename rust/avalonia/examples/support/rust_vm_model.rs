use avalonia::{
    AddressViewModel, AddressViewModelSink, Priority, SampleViewModel, SampleViewModelSink,
    TaskItemViewModel, TaskItemViewModelSink, ValueConverters,
};
use std::time::Duration;

pub struct Model {
    sink: Option<SampleViewModelSink>,
    name: String,
    count: i64,
    new_item: String,
    items: Vec<String>,
    nickname: Option<String>,
    priority: Priority,
    address_set: bool,
    new_task_title: String,
    task_count: usize,
}

/// Formats `Count` the way a real Rust application would: purely, with no
/// access to `Model` state. `AppScope::register_value_converters` enforces
/// this by taking the implementation by value/`Arc`, never a reference into
/// the mounted view model.
pub struct Converters;

impl ValueConverters for Converters {
    fn count_to_label(&self, value: i64) -> String {
        format!("Rust count: {value}")
    }
}

/// A standalone nested view model (see `SampleViewModel::Address`). Rust owns
/// its state and republishes it through its own `AddressViewModelSink`,
/// exactly like a top-level model, but it is never mounted as a window: it
/// is attached under a parent property slot (`SampleViewModelSink::set_address`).
struct AddressModel {
    street: String,
    city: String,
    sink: Option<AddressViewModelSink>,
}

impl AddressModel {
    fn new() -> Self {
        Self {
            street: "1 Rust Way".to_string(),
            city: "Rustville".to_string(),
            sink: None,
        }
    }
}

impl AddressViewModel for AddressModel {
    fn attach(&mut self, sink: AddressViewModelSink) -> avalonia::Result<()> {
        sink.set_street(&self.street)?;
        sink.set_city(&self.city)?;
        self.sink = Some(sink);
        Ok(())
    }

    fn detach(&mut self) -> avalonia::Result<()> {
        self.sink = None;
        Ok(())
    }

    fn set_street(&mut self, value: String) -> avalonia::Result<()> {
        self.street = value;
        if let Some(sink) = &self.sink {
            sink.set_street(&self.street)?;
        }
        Ok(())
    }

    fn set_city(&mut self, value: String) -> avalonia::Result<()> {
        self.city = value;
        if let Some(sink) = &self.sink {
            sink.set_city(&self.city)?;
        }
        Ok(())
    }
}

/// A nested view model appearing as an element of `SampleViewModel::Tasks`.
/// Its own `Done` checkbox is two-way: toggling it in the managed `ListBox`
/// item template calls straight into this instance's own sink, without
/// going through the parent model at all — proving nested item
/// notifications flow both ways.
struct TaskModel {
    title: String,
    done: bool,
    sink: Option<TaskItemViewModelSink>,
}

impl TaskItemViewModel for TaskModel {
    fn attach(&mut self, sink: TaskItemViewModelSink) -> avalonia::Result<()> {
        sink.set_title(&self.title)?;
        sink.set_done(self.done)?;
        self.sink = Some(sink);
        Ok(())
    }

    fn detach(&mut self) -> avalonia::Result<()> {
        self.sink = None;
        Ok(())
    }

    fn set_done(&mut self, value: bool) -> avalonia::Result<()> {
        self.done = value;
        if let Some(sink) = &self.sink {
            sink.set_done(self.done)?;
        }
        Ok(())
    }
}

impl Model {
    pub fn new() -> Self {
        Self {
            sink: None,
            name: "Avalonia from Rust".to_string(),
            count: 0,
            new_item: String::new(),
            items: vec!["First Rust item".to_string()],
            nickname: None,
            priority: Priority::Normal,
            address_set: false,
            new_task_title: String::new(),
            task_count: 0,
        }
    }

    fn publish_initial_state(&self, sink: &SampleViewModelSink) -> avalonia::Result<()> {
        sink.set_name(&self.name)?;
        sink.set_count(self.count)?;
        sink.set_new_item(&self.new_item)?;
        for item in &self.items {
            sink.add_items(item)?;
        }
        sink.set_status("Ready")?;
        sink.set_nickname(self.nickname.as_deref())?;
        sink.set_priority(self.priority)?;
        sink.set_new_task_title(&self.new_task_title)
    }
}

impl SampleViewModel for Model {
    fn attach(&mut self, sink: SampleViewModelSink) -> avalonia::Result<()> {
        self.publish_initial_state(&sink)?;
        self.sink = Some(sink);
        Ok(())
    }

    fn detach(&mut self) -> avalonia::Result<()> {
        self.sink = None;
        Ok(())
    }

    fn set_name(&mut self, value: String) -> avalonia::Result<()> {
        self.name = value;
        if let Some(sink) = &self.sink {
            sink.set_name(&self.name)?;
            // A small, real validation-error demonstration: Rust decides
            // when a property is invalid and projects that decision through
            // `INotifyDataErrorInfo` on the managed side; it never runs any
            // validation logic itself.
            if self.name.trim().is_empty() {
                sink.set_name_error(Some("Name cannot be empty."))?;
            } else {
                sink.set_name_error(None)?;
            }
        }
        Ok(())
    }

    fn set_new_item(&mut self, value: String) -> avalonia::Result<()> {
        self.new_item = value;
        if let Some(sink) = &self.sink {
            sink.set_new_item(&self.new_item)?;
        }
        Ok(())
    }

    fn set_nickname(&mut self, value: String) -> avalonia::Result<()> {
        self.nickname = Some(value);
        if let Some(sink) = &self.sink {
            sink.set_nickname(self.nickname.as_deref())?;
        }
        Ok(())
    }

    fn set_priority(&mut self, value: Priority) -> avalonia::Result<()> {
        self.priority = value;
        if let Some(sink) = &self.sink {
            sink.set_priority(self.priority)?;
        }
        Ok(())
    }

    fn set_new_task_title(&mut self, value: String) -> avalonia::Result<()> {
        self.new_task_title = value;
        if let Some(sink) = &self.sink {
            sink.set_new_task_title(&self.new_task_title)?;
        }
        Ok(())
    }

    fn increment(&mut self) -> avalonia::Result<()> {
        self.count += 1;
        if let Some(sink) = &self.sink {
            sink.set_count(self.count)?;
        }
        Ok(())
    }

    fn add(&mut self, value: String) -> avalonia::Result<()> {
        self.items.push(value.clone());
        self.new_item.clear();
        if let Some(sink) = &self.sink {
            sink.add_items(value)?;
            sink.set_new_item("")?;
        }
        Ok(())
    }

    fn save(&mut self) -> avalonia::Result<()> {
        let Some(sink) = self.sink.clone() else {
            return Ok(());
        };
        sink.set_status("Saving in Rust...")?;
        // CanExecute demonstration: disable the Save command itself while
        // the background save is in flight, and re-enable it on completion.
        sink.set_save_enabled(false)?;
        std::thread::spawn(move || {
            std::thread::sleep(Duration::from_millis(250));
            sink.set_status("Saved by Rust async worker")
                .expect("failed to publish Rust save completion");
            sink.set_save_enabled(true)
                .expect("failed to re-enable the Save command");
        });
        Ok(())
    }

    fn clear_nickname(&mut self) -> avalonia::Result<()> {
        self.nickname = None;
        if let Some(sink) = &self.sink {
            sink.set_nickname(self.nickname.as_deref())?;
        }
        Ok(())
    }

    fn toggle_address(&mut self) -> avalonia::Result<()> {
        self.address_set = !self.address_set;
        if let Some(sink) = &self.sink {
            if self.address_set {
                sink.set_address(Some(AddressModel::new()))?;
            } else {
                sink.set_address::<AddressModel>(None)?;
            }
        }
        Ok(())
    }

    fn add_task(&mut self, value: String) -> avalonia::Result<()> {
        self.new_task_title.clear();
        self.task_count += 1;
        if let Some(sink) = &self.sink {
            sink.add_tasks(TaskModel {
                title: value,
                done: false,
                sink: None,
            })?;
            sink.set_new_task_title("")?;
        }
        Ok(())
    }

    fn remove_first_task(&mut self) -> avalonia::Result<()> {
        if self.task_count == 0 {
            return Ok(());
        }
        self.task_count -= 1;
        if let Some(sink) = &self.sink {
            sink.remove_tasks(0)?;
        }
        Ok(())
    }

    fn shuffle_tasks(&mut self) -> avalonia::Result<()> {
        if self.task_count < 2 {
            return Ok(());
        }
        if let Some(sink) = &self.sink {
            sink.move_tasks((self.task_count - 1) as i32, 0)?;
        }
        Ok(())
    }

    fn clear_tasks(&mut self) -> avalonia::Result<()> {
        self.task_count = 0;
        if let Some(sink) = &self.sink {
            sink.clear_tasks()?;
        }
        Ok(())
    }
}
