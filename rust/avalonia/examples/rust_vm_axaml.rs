use avalonia::{App, RustViewModel, RustVmSink};
use std::time::Duration;

struct Model {
    sink: Option<RustVmSink>,
    name: String,
    count: i32,
    items: Vec<String>,
}

impl Model {
    fn publish_initial_state(&self, sink: &RustVmSink) -> avalonia::Result<()> {
        sink.set_name(&self.name)?;
        sink.set_count(self.count)?;
        for item in &self.items {
            sink.add_item(item)?;
        }
        sink.set_status("Ready")
    }
}

impl RustViewModel for Model {
    fn attach(&mut self, sink: RustVmSink) -> avalonia::Result<()> {
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

    fn increment(&mut self) -> avalonia::Result<()> {
        self.count += 1;
        if let Some(sink) = &self.sink {
            sink.set_count(self.count)?;
        }
        Ok(())
    }

    fn add_item(&mut self, value: String) -> avalonia::Result<()> {
        self.items.push(value.clone());
        if let Some(sink) = &self.sink {
            sink.add_item(value)?;
        }
        Ok(())
    }

    fn begin_save(&mut self) -> avalonia::Result<()> {
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
        scope.mount_view_model(Model {
            sink: None,
            name: "Avalonia from Rust".to_string(),
            count: 0,
            items: vec!["First Rust item".to_string()],
        })
    })
}
