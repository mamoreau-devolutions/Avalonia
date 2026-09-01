use avalonia::{App, Button, Error, Orientation, StackPanel, TextBlock, Window};
use std::path::PathBuf;
use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::Arc;

fn host_path() -> PathBuf {
    if let Ok(path) = std::env::var("AVN_HOST_NATIVE_LIB") {
        return PathBuf::from(path);
    }

    let root = PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../..");
    let candidates = [
        "src/Avalonia.Host/bin/Release/net10.0/win-x64/publish/Avalonia.Host.dll",
        "src/Avalonia.Host/bin/Release/net10.0/win-arm64/publish/Avalonia.Host.dll",
        "src/Avalonia.Host/bin/Debug/net10.0/win-x64/publish/Avalonia.Host.dll",
    ];

    candidates
        .into_iter()
        .map(|relative| root.join(relative))
        .find(|path| path.exists())
        .unwrap_or_else(|| {
            panic!(
                "Avalonia.Host native library not found. Publish with \
                 `dotnet publish src/Avalonia.Host/Avalonia.Host.csproj -c Release -r win-x64` \
                 or set AVN_HOST_NATIVE_LIB."
            )
        })
}

#[test]
fn builders_create_a_real_window_through_nativeaot() {
    let called = Arc::new(AtomicBool::new(false));
    let called_from_handler = called.clone();
    let app = App::load(host_path()).unwrap();

    let error = app
        .run(move || {
            let button = Button::new()?.content(TextBlock::new()?.text("Close")?)?;
            button.subscribe_click(|_| {})?.unsubscribe()?;
            let button = button.on_click(|_| {})?;
            let panel = StackPanel::new()?
                .orientation(Orientation::Vertical)?
                .spacing(8.0)?
                .child(TextBlock::new()?.text("Hello from Rust")?)?
                .child(button)?;
            assert_eq!(panel.children()?.len()?, 2);
            assert_eq!(panel.get_orientation()?, Orientation::Vertical);
            assert_eq!(panel.get_spacing()?, 8.0);

            let window = Window::new()?.title("Avalonia Rust")?.content(panel)?;
            window.show()?;
            window.close()?;
            called_from_handler.store(true, Ordering::SeqCst);

            Err(Error::NoUiContext)
        })
        .unwrap_err();

    assert!(matches!(error, Error::Abi(_)));
    assert!(called.load(Ordering::SeqCst));
}
