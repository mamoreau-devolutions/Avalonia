use avalonia::{App, SampleViewModel, SampleViewModelSink};
use std::time::Duration;

struct Model {
    sink: Option<SampleViewModelSink>,
    name: String,
    count: i64,
    new_item: String,
    items: Vec<String>,
}

impl Model {
    fn publish_initial_state(&self, sink: &SampleViewModelSink) -> avalonia::Result<()> {
        sink.set_name(&self.name)?;
        sink.set_count(self.count)?;
        sink.set_new_item(&self.new_item)?;
        for item in &self.items {
            sink.add_items(item)?;
        }
        sink.set_status("Ready")
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
        std::thread::spawn(move || {
            std::thread::sleep(Duration::from_millis(250));
            sink.set_status("Saved by Rust async worker")
                .expect("failed to publish Rust save completion");
        });
        Ok(())
    }
}

fn main() -> avalonia::Result<()> {
    App::load_from_env()?.run(|scope| {
        scope.mount_rust_vm_window(Model {
            sink: None,
            name: "Avalonia from Rust".to_string(),
            count: 0,
            new_item: String::new(),
            items: vec!["First Rust item".to_string()],
        })
    })
}
