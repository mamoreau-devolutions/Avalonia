use avalonia::{
    App, Border, Button, ComboBox, ComboBoxItem, ExpandDirection, Expander, HorizontalAlignment,
    ListBox, ListBoxItem, Orientation, RadioButton, Slider, StackPanel, TextBlock, TextBox,
    Thickness, ToggleSwitch, VerticalAlignment, Window,
};

fn main() -> avalonia::Result<()> {
    App::load_from_env()?.run(|scope| {
        let window = Window::new()?.title("Control basics")?.can_resize(true)?;
        let click_count = TextBlock::new()?.text("Clicked 0 times")?;
        let click_count_for_handler = click_count.clone();
        let mut clicks = 0;
        let button = Button::new()?
            .content(TextBlock::new()?.text("Click me")?)?
            .on_click(scope, move |_| {
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
        let slider = slider.on_value_changed(scope, move |_| {
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
        let text_box = text_box.on_text_changed(scope, move |_| {
            let value = text_box_for_handler
                .get_text()
                .expect("failed to read text")
                .unwrap_or_default();
            typed_text_for_handler
                .set_text(format!("Text: {value}"))
                .expect("failed to update text readout");
        })?;
        let key_readout = TextBlock::new()?.text("Key: focus the text box and press a key")?;
        let key_readout_for_handler = key_readout.clone();
        let text_box = text_box.on_key_down(scope, move |event| {
            let symbol = event.key_symbol.as_deref().unwrap_or("");
            key_readout_for_handler
                .set_text(format!(
                    "Key={} Physical={} Modifiers={} Symbol={symbol}",
                    event.key, event.physical_key, event.key_modifiers
                ))
                .expect("failed to update key readout");
        })?;

        let toggle_value = TextBlock::new()?.text("Toggle: on")?;
        let toggle_value_for_handler = toggle_value.clone();
        let toggle = ToggleSwitch::new()?
            .content(TextBlock::new()?.text("ToggleSwitch")?)?
            .on_content(TextBlock::new()?.text("On")?)?
            .off_content(TextBlock::new()?.text("Off")?)?
            .checked(Some(true))?;
        let toggle_for_handler = toggle.clone();
        let toggle = toggle.on_is_checked_changed(scope, move |_| {
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

        let radio_buttons = StackPanel::new()?
            .orientation(Orientation::Horizontal)?
            .spacing(8.0)?
            .child(
                RadioButton::new()?
                    .group_name("DemoGroup")?
                    .content(TextBlock::new()?.text("Option A")?)?
                    .checked(Some(true))?,
            )?
            .child(
                RadioButton::new()?
                    .group_name("DemoGroup")?
                    .content(TextBlock::new()?.text("Option B")?)?,
            )?
            .child(
                RadioButton::new()?
                    .group_name("DemoGroup")?
                    .content(TextBlock::new()?.text("Option C")?)?,
            )?;

        let expander = Expander::new()?
            .header(TextBlock::new()?.text("Expandable section")?)?
            .content(
                StackPanel::new()?
                    .spacing(4.0)?
                    .child(TextBlock::new()?.text("Content inside the expander.")?)?
                    .child(TextBlock::new()?.text("Generated from the shared projection IR.")?)?,
            )?
            .expand_direction(ExpandDirection::Down)?
            .expanded(true)?;

        let combo_status = TextBlock::new()?.text("ComboBox: Blue")?;
        let combo_status_for_handler = combo_status.clone();
        let combo_box = ComboBox::new()?
            .placeholder_text("Pick a color")?
            .item(ComboBoxItem::new()?.content(TextBlock::new()?.text("Red")?)?)?
            .item(ComboBoxItem::new()?.content(TextBlock::new()?.text("Green")?)?)?
            .item(ComboBoxItem::new()?.content(TextBlock::new()?.text("Blue")?)?)?
            .selected_index(2)?;
        let combo_box_for_handler = combo_box.clone();
        let combo_box = combo_box.on_selection_changed(scope, move |_| {
            let index = combo_box_for_handler
                .get_selected_index()
                .expect("failed to read ComboBox selection");
            combo_status_for_handler
                .set_text(format!("ComboBox index: {index}"))
                .expect("failed to update ComboBox readout");
        })?;

        let list_status = TextBlock::new()?.text("ListBox: Item 2")?;
        let list_status_for_handler = list_status.clone();
        let list_box = ListBox::new()?
            .item(ListBoxItem::new()?.content(TextBlock::new()?.text("Item 1")?)?)?
            .item(ListBoxItem::new()?.content(TextBlock::new()?.text("Item 2")?)?)?
            .item(ListBoxItem::new()?.content(TextBlock::new()?.text("Item 3")?)?)?
            .item(ListBoxItem::new()?.content(TextBlock::new()?.text("Item 4")?)?)?
            .selected_index(1)?;
        let list_box_for_handler = list_box.clone();
        let list_box = list_box.on_selection_changed(scope, move |_| {
            let index = list_box_for_handler
                .get_selected_index()
                .expect("failed to read ListBox selection");
            list_status_for_handler
                .set_text(format!("ListBox index: {index}"))
                .expect("failed to update ListBox readout");
        })?;

        let hover_state = TextBlock::new()?.text("out")?;
        let entered_state = hover_state.clone();
        let exited_state = hover_state.clone();
        let hover_panel = Border::new()?
            .child(hover_state)?
            .on_pointer_entered(scope, move |_| {
                entered_state
                    .set_text("over")
                    .expect("failed to update hover state");
            })?
            .on_pointer_exited(scope, move |_| {
                exited_state
                    .set_text("out")
                    .expect("failed to update hover state");
            })?;

        let clipboard_text = TextBox::new()?.text("Hello clipboard")?;
        let clipboard_status = TextBlock::new()?.text("")?;

        let copy_scope = scope.clone();
        let copy_window = window.clone();
        let copy_text = clipboard_text.clone();
        let copy_status = clipboard_status.clone();
        let copy = Button::new()?
            .content(TextBlock::new()?.text("Copy")?)?
            .on_click(scope, move |_| {
                let text = copy_text
                    .get_text()
                    .expect("failed to read clipboard text")
                    .unwrap_or_default();
                match copy_scope.clipboard_set_text(&copy_window, &text) {
                    Ok(operation) => {
                        let status = copy_status.clone();
                        copy_scope
                            .spawn(async move {
                                match operation.await {
                                    Ok(()) => status
                                        .set_text(format!("copied {} chars", text.len()))
                                        .expect("failed to update clipboard status"),
                                    Err(error) => status
                                        .set_text(error.to_string())
                                        .expect("failed to update clipboard status"),
                                }
                            })
                            .expect("failed to spawn clipboard copy");
                    }
                    Err(error) => copy_status
                        .set_text(error.to_string())
                        .expect("failed to update clipboard status"),
                }
            })?;

        let paste_scope = scope.clone();
        let paste_window = window.clone();
        let paste_text = clipboard_text.clone();
        let paste_status = clipboard_status.clone();
        let paste = Button::new()?
            .content(TextBlock::new()?.text("Paste")?)?
            .on_click(scope, move |_| {
                match paste_scope.clipboard_get_text(&paste_window) {
                    Ok(operation) => {
                        let text_box = paste_text.clone();
                        let status = paste_status.clone();
                        paste_scope
                            .spawn(async move {
                                match operation.await {
                                    Ok(Some(text)) => {
                                        text_box
                                            .set_text(&text)
                                            .expect("failed to update clipboard text");
                                        status
                                            .set_text(format!("pasted {} chars", text.len()))
                                            .expect("failed to update clipboard status");
                                    }
                                    Ok(None) => status
                                        .set_text("no text on clipboard")
                                        .expect("failed to update clipboard status"),
                                    Err(error) => status
                                        .set_text(error.to_string())
                                        .expect("failed to update clipboard status"),
                                }
                            })
                            .expect("failed to spawn clipboard paste");
                    }
                    Err(error) => paste_status
                        .set_text(error.to_string())
                        .expect("failed to update clipboard status"),
                }
            })?;

        let layout_demo = Border::new()?.padding(Thickness::uniform(8.0))?.child(
            StackPanel::new()?
                .orientation(Orientation::Horizontal)?
                .spacing(8.0)?
                .child(
                    TextBlock::new()?
                        .text("Right aligned, inset")?
                        .name("layout_readout")?
                        .margin(Thickness::symmetric(16.0, 4.0))?
                        .horizontal_alignment(HorizontalAlignment::Right)?
                        .vertical_alignment(VerticalAlignment::Center)?
                        .min_width(160.0)?
                        .opacity(0.7)?,
                )?,
        )?;

        window.set_content(
            StackPanel::new()?
                .orientation(Orientation::Vertical)?
                .spacing(8.0)?
                .margin(Thickness::uniform(12.0))?
                .child(button)?
                .child(click_count)?
                .child(slider)?
                .child(slider_value)?
                .child(text_box)?
                .child(typed_text)?
                .child(key_readout)?
                .child(toggle)?
                .child(toggle_value)?
                .child(TextBlock::new()?.text("Layout")?)?
                .child(layout_demo)?
                .child(TextBlock::new()?.text("Selection & expand patterns")?)?
                .child(combo_box)?
                .child(combo_status)?
                .child(list_box)?
                .child(list_status)?
                .child(radio_buttons)?
                .child(expander)?
                .child(TextBlock::new()?.text("Hover")?)?
                .child(hover_panel)?
                .child(TextBlock::new()?.text("Clipboard")?)?
                .child(clipboard_text)?
                .child(
                    StackPanel::new()?
                        .orientation(Orientation::Horizontal)?
                        .spacing(8.0)?
                        .child(copy)?
                        .child(paste)?,
                )?
                .child(clipboard_status)?,
        )?;
        scope.mount(window)
    })
}
