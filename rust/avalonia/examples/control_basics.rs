use avalonia::{App, Button, Orientation, Slider, StackPanel, TextBlock, Window};

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

        Window::new()?
            .title("Control basics")?
            .content(
                StackPanel::new()?
                    .orientation(Orientation::Vertical)?
                    .spacing(8.0)?
                    .child(button)?
                    .child(click_count)?
                    .child(slider)?
                    .child(slider_value)?,
            )?
            .show()
    })
}
