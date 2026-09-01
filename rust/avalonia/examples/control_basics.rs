use avalonia::{
    App, Button, Orientation, Slider, StackPanel, TextBlock, TextBox, ToggleSwitch, Window,
};

fn main() -> avalonia::Result<()> {
    App::load_from_env()?.run(|_| {
        let click_count = TextBlock::new()?.text("Clicked 0 times")?;
        let click_count_for_handler = click_count.clone();
        let mut clicks = 0;
        let button = Button::new()?
            .content(TextBlock::new()?.text("Click me")?)?
            .on_click(move |_| {
                clicks += 1;
                click_count_for_handler
                    .set_text(format!("Clicked {clicks} times"))
                    .expect("failed to update click count");
            })?;

        let slider_value = TextBlock::new()?.text("Slider: 25")?;
        let slider_value_for_handler = slider_value.clone();
        let slider = Slider::new()?
            .minimum(0.0)?
            .maximum(100.0)?
            .value(25.0)?
            .orientation(Orientation::Horizontal)?;
        let slider_for_handler = slider.clone();
        let slider = slider.on_value_changed(move |_| {
            let value = slider_for_handler
                .get_value()
                .expect("failed to read slider value");
            slider_value_for_handler
                .set_text(format!("Slider: {value:.0}"))
                .expect("failed to update slider readout");
        })?;

        let typed_text = TextBlock::new()?.text("Text: Hello from Avalonia")?;
        let typed_text_for_handler = typed_text.clone();
        let text_box = TextBox::new()?
            .placeholder_text("Type something")?
            .text("Hello from Avalonia")?;
        let text_box_for_handler = text_box.clone();
        let text_box = text_box.on_text_changed(move |_| {
            let value = text_box_for_handler
                .get_text()
                .expect("failed to read text")
                .unwrap_or_default();
            typed_text_for_handler
                .set_text(format!("Text: {value}"))
                .expect("failed to update text readout");
        })?;

        let toggle_value = TextBlock::new()?.text("Toggle: on")?;
        let toggle_value_for_handler = toggle_value.clone();
        let toggle = ToggleSwitch::new()?
            .content(TextBlock::new()?.text("ToggleSwitch")?)?
            .on_content(TextBlock::new()?.text("On")?)?
            .off_content(TextBlock::new()?.text("Off")?)?
            .checked(Some(true))?;
        let toggle_for_handler = toggle.clone();
        let toggle = toggle.on_is_checked_changed(move |_| {
            let state = if toggle_for_handler
                .get_is_checked()
                .expect("failed to read toggle state")
                == Some(true)
            {
                "on"
            } else {
                "off"
            };
            toggle_value_for_handler
                .set_text(format!("Toggle: {state}"))
                .expect("failed to update toggle readout");
        })?;

        Window::new()?
            .title("Control basics")?
            .content(
                StackPanel::new()?
                    .orientation(Orientation::Vertical)?
                    .spacing(8.0)?
                    .child(button)?
                    .child(click_count)?
                    .child(slider)?
                    .child(slider_value)?
                    .child(text_box)?
                    .child(typed_text)?
                    .child(toggle)?
                    .child(toggle_value)?,
            )?
            .show()
    })
}
