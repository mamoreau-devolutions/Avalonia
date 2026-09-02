use crate::support::desktop_files::DesktopFiles;
use avalonia::{
    AddressViewModel, AddressViewModelSink, Priority, SampleViewModel, SampleViewModelSink,
    TaskItemViewModel, TaskItemViewModelSink, TraceEventViewModel, TraceEventViewModelSink,
    TraceRowViewModel, TraceRowViewModelSink, ValueConverters,
};
use std::sync::atomic::{AtomicI64, Ordering};
use std::sync::Arc;
use std::time::Duration;

static NEXT_GENERATION: AtomicI64 = AtomicI64::new(0);

#[derive(Clone)]
struct TraceRecord {
    id: String,
    timestamp: String,
    severity: String,
    source: String,
    message: String,
}

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
    trace_rows: Vec<TraceRecord>,
    selected_trace_index: i64,
    selected_trace_key: String,
    trace_sort_direction: String,
    desktop_files: Arc<DesktopFiles>,
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
    /// Builds the model against a shared desktop file integration handle, so
    /// the example can wire the mounted window and application scope into it
    /// after the host creates them.
    pub fn with_desktop_files(desktop_files: Arc<DesktopFiles>) -> Self {
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
            trace_rows: (0..100_000)
                .map(|index| TraceRecord {
                    id: format!("trace-{index:06}"),
                    timestamp: format!(
                        "2026-09-02T12:{:02}:{:02}.{:03}",
                        (index / 60) % 60,
                        index % 60,
                        index % 1000
                    ),
                    severity: ["Information", "Warning", "Error"][index % 3].to_string(),
                    source: format!("CMTrace.{}", index % 64),
                    message: format!("CMTrace event {index}: Rust-owned virtualized table row"),
                })
                .collect(),
            selected_trace_index: 0,
            selected_trace_key: "trace-000000".to_string(),
            trace_sort_direction: "Ascending".to_string(),
            desktop_files,
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
        sink.set_new_task_title(&self.new_task_title)?;
        sink.set_file_status("No file operation yet")?;
        sink.set_drop_status("Drop files or folders onto the panel below")?;
        sink.set_activation_status("No startup files")?;
        sink.set_selected_trace_index(self.selected_trace_index)?;
        sink.set_selected_trace_key(&self.selected_trace_key)?;
        sink.set_trace_sort_direction(&self.trace_sort_direction)?;
        self.publish_trace_snapshot(sink)
    }

    fn next_generation() -> i64 {
        NEXT_GENERATION.fetch_add(1, Ordering::Relaxed) + 1
    }

    fn publish_trace_snapshot(&self, sink: &SampleViewModelSink) -> avalonia::Result<()> {
        let mut batch = sink.batch(Self::next_generation());
        batch.replace_trace_rows_snapshot(self.trace_rows.iter().cloned().map(TraceRowModel::from));
        batch.set_selected_trace_index(self.selected_trace_index);
        batch.set_selected_trace_key(&self.selected_trace_key);
        batch.set_trace_sort_direction(&self.trace_sort_direction);
        sink.submit_batch(batch).map(|_| ())
    }

    fn update_trace_selection(&mut self, index: i64) {
        let index = index.clamp(0, self.trace_rows.len().saturating_sub(1) as i64);
        self.selected_trace_index = index;
        self.selected_trace_key = self.trace_rows[index as usize].id.clone();
    }
}

struct TraceEventModel {
    id: String,
    source: String,
}

impl TraceEventViewModel for TraceEventModel {
    fn attach(&mut self, sink: TraceEventViewModelSink) -> avalonia::Result<()> {
        sink.set_id(&self.id)?;
        sink.set_source(&self.source)
    }

    fn detach(&mut self) -> avalonia::Result<()> {
        Ok(())
    }
}

struct TraceRowModel {
    record: TraceRecord,
}

impl From<TraceRecord> for TraceRowModel {
    fn from(record: TraceRecord) -> Self {
        Self { record }
    }
}

impl TraceRowViewModel for TraceRowModel {
    fn attach(&mut self, sink: TraceRowViewModelSink) -> avalonia::Result<()> {
        sink.set_timestamp(&self.record.timestamp)?;
        sink.set_severity(&self.record.severity)?;
        sink.set_message(&self.record.message)?;
        sink.set_event(Some(TraceEventModel {
            id: self.record.id.clone(),
            source: self.record.source.clone(),
        }))
    }

    fn detach(&mut self) -> avalonia::Result<()> {
        Ok(())
    }
}

impl SampleViewModel for Model {
    fn attach(&mut self, sink: SampleViewModelSink) -> avalonia::Result<()> {
        self.publish_initial_state(&sink)?;
        self.desktop_files.set_sink(Some(sink.clone()));
        self.sink = Some(sink);
        Ok(())
    }

    fn detach(&mut self) -> avalonia::Result<()> {
        self.desktop_files.set_sink(None);
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
            // The two UI changes publish together. Repeated clicks/workers can
            // overlap safely: the newest generation wins and completion occurs
            // only after UI application, never on this worker's call stack.
            let mut batch = sink.batch(Self::next_generation());
            batch.set_status("Saved by Rust async worker");
            batch.set_save_enabled(true);
            let _completion = sink
                .submit_batch(batch)
                .expect("failed to submit Rust save batch");
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

    fn set_selected_trace_index(&mut self, value: i64) -> avalonia::Result<()> {
        // TableView clears the selected container during a snapshot Reset. The
        // retained row key remains authoritative, so immediately republish its
        // post-sort index instead of accepting that transient `-1`.
        if value < 0 {
            if let Some(sink) = &self.sink {
                sink.set_selected_trace_index(self.selected_trace_index)?;
            }
            return Ok(());
        }
        self.update_trace_selection(value);
        if let Some(sink) = &self.sink {
            sink.set_selected_trace_key(&self.selected_trace_key)?;
        }
        Ok(())
    }

    fn set_selected_trace_key(&mut self, value: String) -> avalonia::Result<()> {
        if let Some(index) = self.trace_rows.iter().position(|row| row.id == value) {
            self.update_trace_selection(index as i64);
            if let Some(sink) = &self.sink {
                sink.set_selected_trace_index(self.selected_trace_index)?;
            }
        }
        Ok(())
    }

    fn sort_trace_rows(&mut self, value: String) -> avalonia::Result<()> {
        let (column, direction) =
            value
                .split_once(':')
                .ok_or(avalonia::Error::InvalidViewModelMember {
                    kind: "sort",
                    id: 10,
                })?;
        let descending = match direction {
            "Ascending" => false,
            "Descending" => true,
            _ => {
                return Err(avalonia::Error::InvalidViewModelMember {
                    kind: "sort",
                    id: 10,
                })
            }
        };
        let selected = self.selected_trace_key.clone();
        self.trace_rows.sort_by(|left, right| {
            let comparison = match column {
                "Timestamp" => left.timestamp.cmp(&right.timestamp),
                "Severity" => left.severity.cmp(&right.severity),
                "Source" => left.source.cmp(&right.source),
                _ => return left.id.cmp(&right.id),
            };
            if descending {
                comparison.reverse()
            } else {
                comparison
            }
        });
        self.trace_sort_direction = direction.to_string();
        self.selected_trace_index = self
            .trace_rows
            .iter()
            .position(|row| row.id == selected)
            .unwrap_or(0) as i64;
        self.selected_trace_key = self.trace_rows[self.selected_trace_index as usize]
            .id
            .clone();
        if let Some(sink) = &self.sink {
            self.publish_trace_snapshot(sink)?;
        }
        Ok(())
    }

    /// Desktop file integration commands. They only start the platform-neutral
    /// picker; the completion is awaited on the application scope's executor
    /// and published back through the same sink, so the UI thread is never
    /// blocked while a dialog is open.
    fn open_files(&mut self) -> avalonia::Result<()> {
        self.desktop_files.open_files()
    }

    fn open_folder(&mut self) -> avalonia::Result<()> {
        self.desktop_files.open_folder()
    }

    fn save_export(&mut self) -> avalonia::Result<()> {
        self.desktop_files.save_export()
    }
}
