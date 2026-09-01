use avalonia::{
    App, Button, Dock, DockPanel, Grid, Orientation, ScrollViewer, StackPanel, TextBlock, TextBox,
    ThemeVariant, Window,
};
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
    let posted = Arc::new(AtomicBool::new(false));
    let posted_from_handler = posted.clone();
    let text_changed = Arc::new(AtomicBool::new(false));
    let text_changed_from_handler = text_changed.clone();
    let app = App::load(host_path()).unwrap();

    app.run(move |context| {
        assert!(context.check_access()?);
        context.set_requested_theme_variant(ThemeVariant::Dark)?;
        assert_eq!(context.requested_theme_variant()?, ThemeVariant::Dark);
        assert_eq!(
            context.find_resource("__missing_rust_resource__", ThemeVariant::Dark)?,
            None
        );
        let button = Button::new()?.content(TextBlock::new()?.text("Close")?)?;
        let classes = button.classes()?;
        classes.add("primary")?;
        assert!(classes.contains("primary")?);
        assert!(classes.remove_value("primary")?);
        Grid::set_row(&button, 1)?;
        assert_eq!(Grid::get_row(&button)?, 1);
        button.subscribe_click(|_| {})?.unsubscribe()?;
        let button = button.on_click(|_| {})?;

        let text_box = TextBox::new()?.text("before")?.on_text_changed(move |_| {
            text_changed_from_handler.store(true, Ordering::SeqCst);
        })?;
        DockPanel::set_dock(&text_box, Dock::Top)?;
        assert_eq!(DockPanel::get_dock(&text_box)?, Dock::Top);
        let text_box_for_post = text_box.clone();
        let text_box = ScrollViewer::new()?.content(DockPanel::new()?.child(text_box)?)?;

        let panel = StackPanel::new()?
            .orientation(Orientation::Vertical)?
            .spacing(8.0)?
            .child(TextBlock::new()?.text("Hello from Rust")?)?
            .child(text_box)?
            .child(button)?;
        assert_eq!(panel.children()?.len()?, 3);
        assert_eq!(panel.get_orientation()?, Orientation::Vertical);
        assert_eq!(panel.get_spacing()?, 8.0);

        let window = Window::new()?.title("Avalonia Rust")?.content(panel)?;
        window.show()?;
        called_from_handler.store(true, Ordering::SeqCst);

        let context = context.clone();
        std::thread::spawn(move || {
            assert!(!context.check_access().unwrap());
            context
                .post(move || {
                    text_box_for_post.set_text("after").unwrap();
                    assert_eq!(
                        text_box_for_post.get_text().unwrap().as_deref(),
                        Some("after")
                    );
                    posted_from_handler.store(true, Ordering::SeqCst);
                    window.close().unwrap();
                })
                .unwrap();
        });

        Ok(())
    })
    .unwrap();

    assert!(called.load(Ordering::SeqCst));
    assert!(posted.load(Ordering::SeqCst));
    assert!(text_changed.load(Ordering::SeqCst));
}
