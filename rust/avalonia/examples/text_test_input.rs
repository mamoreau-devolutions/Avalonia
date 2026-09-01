use avalonia::{
    App, Button, Dock, DockPanel, Orientation, ScrollViewer, StackPanel, TextBlock, TextBox, Window,
};

fn main() -> avalonia::Result<()> {
    App::load_from_env()?.run(|_| {
        let preview = TextBlock::new()?.text("Hello!")?;
        let preview_for_handler = preview.clone();

        let editor = TextBox::new()?
            .text("Hello!")?
            .placeholder_text("Text to preview")?;
        let editor_for_handler = editor.clone();
        let editor_for_window = editor.clone();
        let editor = editor.on_text_changed(move |_| {
            let text = editor_for_handler
                .get_text()
                .expect("failed to read edited text")
                .unwrap_or_default();
            preview_for_handler
                .set_text(text)
                .expect("failed to update text preview");
        })?;

        let new_window = Button::new()?
            .content(TextBlock::new()?.text("+")?)?
            .on_click(move |_| {
                let text = editor_for_window
                    .get_text()
                    .expect("failed to read edited text")
                    .unwrap_or_default();
                Window::new()
                    .and_then(|window| window.title("Text Test App"))
                    .and_then(|window| window.content(TextBlock::new()?.text(text)?))
                    .and_then(|window| window.show())
                    .expect("failed to open text preview window");
            })?;

        let toolbar = StackPanel::new()?
            .orientation(Orientation::Horizontal)?
            .spacing(8.0)?
            .child(TextBlock::new()?.text("Text:")?)?
            .child(editor)?
            .child(new_window)?;
        DockPanel::set_dock(&toolbar, Dock::Top)?;

        Window::new()?
            .title("Text Test App")?
            .content(
                DockPanel::new()?
                    .child(toolbar)?
                    .child(ScrollViewer::new()?.content(preview)?)?,
            )?
            .show()
    })
}
