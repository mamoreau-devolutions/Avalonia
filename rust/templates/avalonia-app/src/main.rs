//! Starting point for a new Avalonia Rust application.
//!
//! `avalonia::App::load_from_env()` locates the native `Avalonia.Host`
//! library the same way every sample in this repository does:
//! `AVN_HOST_NATIVE_LIB` is an explicit override, and otherwise it looks for
//! the platform host library next to this executable (see
//! `../../PRODUCTIZATION.md#host-discovery`). Copying the published host
//! beside your built binary -- which `rust/package.ps1` / `rust/package.sh`
//! do for you -- means no environment variable is required at run time.

use avalonia::{App, Button, Orientation, StackPanel, TextBlock, Window};

fn main() -> avalonia::Result<()> {
    App::load_from_env()?.run(|scope| {
        scope.mount(
            Window::new()?.title("My Avalonia Rust App")?.content(
                StackPanel::new()?
                    .orientation(Orientation::Vertical)?
                    .child(TextBlock::new()?.text("Replace this with your UI.")?)?
                    .child(Button::new()?.content(TextBlock::new()?.text("Click me")?)?)?,
            )?,
        )
    })
}
