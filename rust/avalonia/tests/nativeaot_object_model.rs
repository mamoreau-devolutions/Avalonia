use avalonia::{
    App, Border, Button, ComboBox, ComboBoxItem, Dock, DockPanel, ExpandDirection, Expander, Grid,
    ListBox, ListBoxItem, Orientation, ProgressBar, RadioButton, ScrollViewer, StackPanel,
    TextBlock, TextBox, ThemeVariant, ToggleSwitch, Window,
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
    let toggle_changed = Arc::new(AtomicBool::new(false));
    let toggle_changed_from_handler = toggle_changed.clone();
    let combo_changed = Arc::new(AtomicBool::new(false));
    let combo_changed_from_handler = combo_changed.clone();
    let list_changed = Arc::new(AtomicBool::new(false));
    let list_changed_from_handler = list_changed.clone();
    let app = App::load(host_path()).unwrap();

    app.run(move |scope| {
        assert!(scope.check_access()?);
        scope.set_requested_theme_variant(ThemeVariant::Dark)?;
        assert_eq!(scope.requested_theme_variant()?, ThemeVariant::Dark);
        assert_eq!(
            scope.find_resource("__missing_rust_resource__", ThemeVariant::Dark)?,
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
        let button = button.on_click(scope, |_| {})?;

        let text_box = TextBox::new()?
            .text("before")?
            .on_text_changed(scope, move |_| {
                text_changed_from_handler.store(true, Ordering::SeqCst);
            })?;
        DockPanel::set_dock(&text_box, Dock::Top)?;
        assert_eq!(DockPanel::get_dock(&text_box)?, Dock::Top);
        let text_box_for_post = text_box.clone();
        let text_box = ScrollViewer::new()?.content(DockPanel::new()?.child(text_box)?)?;

        let toggle = ToggleSwitch::new()?
            .content(TextBlock::new()?.text("ToggleSwitch")?)?
            .on_content(TextBlock::new()?.text("On")?)?
            .off_content(TextBlock::new()?.text("Off")?)?
            .checked(Some(true))?
            .on_is_checked_changed(scope, move |_| {
                toggle_changed_from_handler.store(true, Ordering::SeqCst);
            })?;
        let toggle_for_post = toggle.clone();

        let radio_one = RadioButton::new()?
            .group_name("TestGroup")?
            .content(TextBlock::new()?.text("One")?)?
            .checked(Some(true))?;
        let radio_two = RadioButton::new()?
            .group_name("TestGroup")?
            .content(TextBlock::new()?.text("Two")?)?;
        let radio_one_for_post = radio_one.clone();
        let radio_two_for_post = radio_two.clone();
        let radio_buttons = StackPanel::new()?.child(radio_one)?.child(radio_two)?;

        let expander = Expander::new()?
            .header(TextBlock::new()?.text("Header")?)?
            .content(TextBlock::new()?.text("Content")?)?
            .expand_direction(ExpandDirection::Down)?
            .expanded(true)?;
        assert_eq!(expander.get_expand_direction()?, ExpandDirection::Down);
        assert!(expander.get_is_expanded()?);
        expander.subscribe_expanded(|_| {})?.unsubscribe()?;

        let combo_box = ComboBox::new()?
            .placeholder_text("Pick")?
            .item(ComboBoxItem::new()?.content(TextBlock::new()?.text("First")?)?)?
            .item(ComboBoxItem::new()?.content(TextBlock::new()?.text("Second")?)?)?
            .on_selection_changed(scope, move |_| {
                combo_changed_from_handler.store(true, Ordering::SeqCst);
            })?;
        assert_eq!(combo_box.items()?.len()?, 2);
        let combo_box_for_post = combo_box.clone();

        let list_box = ListBox::new()?
            .item(ListBoxItem::new()?.content(TextBlock::new()?.text("First")?)?)?
            .item(ListBoxItem::new()?.content(TextBlock::new()?.text("Second")?)?)?
            .on_selection_changed(scope, move |_| {
                list_changed_from_handler.store(true, Ordering::SeqCst);
            })?;
        assert_eq!(list_box.items()?.len()?, 2);
        let list_box_for_post = list_box.clone();

        let hover_panel = Border::new()?.child(TextBlock::new()?.text("Hover")?)?;
        hover_panel
            .subscribe_pointer_entered(|_| {})?
            .unsubscribe()?;
        hover_panel
            .subscribe_pointer_exited(|_| {})?
            .unsubscribe()?;

        let progress = ProgressBar::new()?
            .minimum(0.0)?
            .maximum(100.0)?
            .value(40.0)?
            .show_progress_text(true)?
            .progress_text_format("{0:0}%")?;
        assert_eq!(progress.get_value()?, 40.0);
        assert!(progress.get_show_progress_text()?);

        let panel = StackPanel::new()?
            .orientation(Orientation::Vertical)?
            .spacing(8.0)?
            .child(TextBlock::new()?.text("Hello from Rust")?)?
            .child(text_box)?
            .child(toggle)?
            .child(combo_box)?
            .child(list_box)?
            .child(radio_buttons)?
            .child(expander)?
            .child(hover_panel)?
            .child(progress)?
            .child(button)?;
        assert_eq!(panel.children()?.len()?, 10);
        assert_eq!(panel.get_orientation()?, Orientation::Vertical);
        assert_eq!(panel.get_spacing()?, 8.0);

        let window = Window::new()?.title("Avalonia Rust")?.content(panel)?;
        scope.mount(window.clone())?;
        called_from_handler.store(true, Ordering::SeqCst);

        let context = scope.clone();
        std::thread::spawn(move || {
            assert!(!context.check_access().unwrap());
            context
                .post(move || {
                    text_box_for_post.set_text("after").unwrap();
                    assert_eq!(
                        text_box_for_post.get_text().unwrap().as_deref(),
                        Some("after")
                    );
                    toggle_for_post.set_checked(Some(false)).unwrap();
                    assert_eq!(toggle_for_post.get_is_checked().unwrap(), Some(false));
                    radio_two_for_post.set_checked(Some(true)).unwrap();
                    assert_eq!(radio_one_for_post.get_is_checked().unwrap(), Some(false));
                    assert_eq!(radio_two_for_post.get_is_checked().unwrap(), Some(true));
                    combo_box_for_post.set_selected_index(1).unwrap();
                    assert_eq!(combo_box_for_post.get_selected_index().unwrap(), 1);
                    list_box_for_post.set_selected_index(1).unwrap();
                    assert_eq!(list_box_for_post.get_selected_index().unwrap(), 1);
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
    assert!(toggle_changed.load(Ordering::SeqCst));
    assert!(combo_changed.load(Ordering::SeqCst));
    assert!(list_changed.load(Ordering::SeqCst));
}
