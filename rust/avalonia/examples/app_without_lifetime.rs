use avalonia::{App, Button, CheckBox, Orientation, StackPanel, TextBlock, Window};

fn main() -> avalonia::Result<()> {
    App::load_from_env()?.run(|_| {
        let open = Button::new()?
            .content(TextBlock::new()?.text("Open")?)?
            .on_click(|_| {
                Window::new()
                    .and_then(|window| window.title("Sub"))
                    .and_then(|window| {
                        window.content(TextBlock::new()?.text("Opened from a Rust event handler")?)
                    })
                    .and_then(|window| window.show())
                    .expect("failed to open child window");
            })?;

        Window::new()?
            .title("AppWithoutLifetime")?
            .content(
                StackPanel::new()?
                    .orientation(Orientation::Vertical)?
                    .child(TextBlock::new()?.text("Welcome to Avalonia!")?)?
                    .child(
                        CheckBox::new()?
                            .checked(Some(true))?
                            .content(TextBlock::new()?.text("Welcome to Avalonia!")?)?,
                    )?
                    .child(open)?,
            )?
            .show()
    })
}
