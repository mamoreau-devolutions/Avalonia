//! This crate owns Rust state; `generated/generated_view_models.rs` is emitted
//! from `view-model.ir.json` by the repository-owned consumer build tool.

pub use avalonia::{AppScope, ConversionDirection, Error, Result, ScalarKind, ScalarValue};
pub mod view_model {
    pub use avalonia::view_model::{DynamicViewModel, ViewModelSink};
}
pub mod value_converter {
    pub use avalonia::value_converter::ValueConverterDispatch;
}

#[path = "../generated/generated_view_models.rs"]
mod generated_view_models;

use avalonia::App;
use generated_view_models::{mount_main_window, MainViewModel, MainViewModelSink};

struct Model;

impl MainViewModel for Model {
    fn attach(&mut self, sink: MainViewModelSink) -> Result<()> {
        sink.set_title("Hello from an external Rust consumer")
    }

    fn detach(&mut self) -> Result<()> {
        Ok(())
    }
}

fn main() -> avalonia::Result<()> {
    App::load_from_env()?.run(|scope| mount_main_window(scope, Model))
}
