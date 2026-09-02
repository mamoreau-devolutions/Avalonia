mod support;

use avalonia::App;
use support::rust_vm_model::{Converters, Model};

fn main() -> avalonia::Result<()> {
    App::load_from_env()?
        .run(|scope| scope.mount_rust_dynamic_vm_window_with_converters(Model::new(), Converters))
}
