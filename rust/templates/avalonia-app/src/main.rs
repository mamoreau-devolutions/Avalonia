//! This crate owns Rust state; `generated/generated_view_models.rs` is emitted
//! from `view-model.ir.json` by the repository-owned consumer build tool.

pub use avalonia::{
    AppScope, CancellationToken, ConversionDirection, Error, MapKey, RangeBatch, RangeRequest,
    Result, ScalarKind, ScalarValue,
};
pub mod view_model {
    pub use avalonia::view_model::{
        BatchCompletion, DynamicViewModel, ViewModelBatch, ViewModelSink,
    };
}
pub mod value_converter {
    pub use avalonia::value_converter::ValueConverterDispatch;
}

#[path = "../generated/generated_view_models.rs"]
mod generated_view_models;

use avalonia::{ActivationEvent, App, StorageItem};
use generated_view_models::{mount_main_window, MainViewModel, MainViewModelSink};
use std::sync::{Arc, Mutex};

#[derive(Default)]
struct Model {
    sink: Arc<Mutex<Option<MainViewModelSink>>>,
}

impl MainViewModel for Model {
    fn attach(&mut self, sink: MainViewModelSink) -> Result<()> {
        sink.set_title("Hello from an external Rust consumer")?;
        *self.sink.lock().expect("sink lock poisoned") = Some(sink);
        Ok(())
    }

    fn detach(&mut self) -> Result<()> {
        *self.sink.lock().expect("sink lock poisoned") = None;
        Ok(())
    }
}

/// Describes the documents the desktop shell launched this application with.
///
/// `App::run` forwards this process's arguments to the managed desktop
/// lifetime, so a registered file association (see `file-associations/`)
/// reaches Rust here with no extra wiring. `uri()` is always available;
/// `local_path()` is `None` for non-local documents.
fn describe(items: &[StorageItem]) -> String {
    if items.is_empty() {
        return "Hello from an external Rust consumer".to_string();
    }
    let names: Vec<&str> = items.iter().map(StorageItem::name).collect();
    format!("Opened {}: {}", items.len(), names.join(", "))
}

fn main() -> avalonia::Result<()> {
    App::load_from_env()?.run(|scope| {
        let model = Model::default();
        let sink = model.sink.clone();
        mount_main_window(scope, model)?;

        if let Some(sink) = sink.lock().expect("sink lock poisoned").as_ref() {
            sink.set_title(describe(&scope.activation_items()?))?;
        }

        // Later "open with" activations, where the desktop lifetime supports
        // them (macOS while the application is already running).
        let activation_sink = sink.clone();
        scope.on_activation(move |event| {
            if let ActivationEvent::Files(items) = &event {
                if let Some(sink) = activation_sink.lock().expect("sink lock poisoned").as_ref() {
                    let _ = sink.set_title(describe(items));
                }
            }
        })
    })
}
