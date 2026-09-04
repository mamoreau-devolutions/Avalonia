//! ABI guarantees for the control-completeness members.
//!
//! `ContentControl`, `Button`, `ToggleButton`, `ListBox` and `ComboBox` each grew slots, and
//! nano-COM vtables are flattened, so every interface at or below one of them republishes
//! under a version 5 IID. This pins the generated header, the fresh IIDs, and the retired
//! ones that must never come back.

use avalonia_sys::{
    I_AVN_AVALONIA_OBJECT_IID, I_AVN_BORDER_IID, I_AVN_BUTTON_IID, I_AVN_COMBO_BOX_IID,
    I_AVN_CONTENT_CONTROL_IID, I_AVN_CONTROL_IID, I_AVN_LIST_BOX_IID, I_AVN_PANEL_IID,
    I_AVN_TEMPLATED_CONTROL_IID, I_AVN_TEXT_BLOCK_IID, I_AVN_TOGGLE_BUTTON_IID, I_AVN_WINDOW_IID,
};

const HEADER: &str = include_str!("../include/avalonia-rust-abi.h");

#[test]
fn completeness_members_are_published_on_the_type_that_declares_them() {
    for expected in [
        "*get_horizontal_content_alignment)(IAvnContentControl* self, int32_t* value)",
        "*set_horizontal_content_alignment)(IAvnContentControl* self, int32_t value)",
        "*set_vertical_content_alignment)(IAvnContentControl* self, int32_t value)",
        "*get_click_mode)(IAvnButton* self, int32_t* value)",
        "*set_click_mode)(IAvnButton* self, int32_t value)",
        "*set_is_default)(IAvnButton* self, int32_t value)",
        "*set_is_cancel)(IAvnButton* self, int32_t value)",
        "*get_is_pressed)(IAvnButton* self, int32_t* value)",
        "*set_is_three_state)(IAvnToggleButton* self, int32_t value)",
        "*set_selection_mode)(IAvnListBox* self, int32_t value)",
        "*select_all)(IAvnListBox* self)",
        "*unselect_all)(IAvnListBox* self)",
        "*set_is_drop_down_open)(IAvnComboBox* self, int32_t value)",
        "*set_is_editable)(IAvnComboBox* self, int32_t value)",
        "*set_max_drop_down_height)(IAvnComboBox* self, double value)",
    ] {
        assert!(HEADER.contains(expected), "header is missing `{expected}`");
    }

    // IsPressed is raised by Avalonia's own input handling, so the ABI publishes no setter.
    assert!(
        !HEADER.contains("*set_is_pressed)"),
        "IsPressed is read-only and must not publish a setter"
    );
}

#[test]
fn widened_interfaces_publish_abi_version_five() {
    for expected in [
        "#define I_AVN_CONTENT_CONTROL_ABI_VERSION 5",
        "#define I_AVN_HEADERED_CONTENT_CONTROL_ABI_VERSION 5",
        "#define I_AVN_EXPANDER_ABI_VERSION 5",
        "#define I_AVN_BUTTON_ABI_VERSION 5",
        "#define I_AVN_TOGGLE_BUTTON_ABI_VERSION 5",
        "#define I_AVN_CHECK_BOX_ABI_VERSION 5",
        "#define I_AVN_RADIO_BUTTON_ABI_VERSION 5",
        "#define I_AVN_TOGGLE_SWITCH_ABI_VERSION 5",
        "#define I_AVN_LIST_BOX_ABI_VERSION 5",
        "#define I_AVN_LIST_BOX_ITEM_ABI_VERSION 5",
        "#define I_AVN_COMBO_BOX_ABI_VERSION 5",
        "#define I_AVN_COMBO_BOX_ITEM_ABI_VERSION 5",
        "#define I_AVN_SCROLL_VIEWER_ABI_VERSION 5",
        "#define I_AVN_WINDOW_ABI_VERSION 5",
        // Nothing above or beside the widened types moved, so these keep the version whose
        // flattened vtable they still match.
        "#define I_AVN_BORDER_ABI_VERSION 4",
        "#define I_AVN_PANEL_ABI_VERSION 4",
        "#define I_AVN_TEMPLATED_CONTROL_ABI_VERSION 4",
        "#define I_AVN_TEXT_BLOCK_ABI_VERSION 4",
        "#define I_AVN_TEXT_BOX_ABI_VERSION 4",
        "#define I_AVN_ITEMS_CONTROL_ABI_VERSION 4",
        "#define I_AVN_SELECTING_ITEMS_CONTROL_ABI_VERSION 4",
        "#define I_AVN_CONTROL_ABI_VERSION 3",
        "#define I_AVN_AVALONIA_OBJECT_ABI_VERSION 2",
        // The factory gained a creator per wave A control plus get_tool_tip_statics at version
        // 3, and a creator per constructible wave B type at version 4.
        "#define I_AVN_CONTROL_FACTORY_ABI_VERSION 8",
    ] {
        assert!(HEADER.contains(expected), "header is missing `{expected}`");
    }
}

#[test]
fn widened_interfaces_republish_under_fresh_iids() {
    // The version 4 IIDs are retired: reusing one for a longer vtable would let a stale
    // consumer call through slots the old contract never declared.
    for (name, retired, current) in [
        (
            "IAvnContentControl",
            "341FD6C2-31EA-572B-B53F-A8CFB57B3BF0",
            I_AVN_CONTENT_CONTROL_IID,
        ),
        (
            "IAvnButton",
            "9DE6B725-9BF0-5DEE-A947-DD87709DD52E",
            I_AVN_BUTTON_IID,
        ),
        (
            "IAvnToggleButton",
            "A68058CE-1067-5C24-A3C4-470105EBF433",
            I_AVN_TOGGLE_BUTTON_IID,
        ),
        (
            "IAvnListBox",
            "97204BC7-2150-5475-B853-9241B9B03781",
            I_AVN_LIST_BOX_IID,
        ),
        (
            "IAvnComboBox",
            "4EEFC042-03EE-5E79-AF4B-3A53F50C63B4",
            I_AVN_COMBO_BOX_IID,
        ),
        (
            "IAvnWindow",
            "0A480A4D-6DF1-5762-8661-F83519B0CC38",
            I_AVN_WINDOW_IID,
        ),
    ] {
        assert_ne!(format_iid(&current), retired, "{name} reused a retired IID");
    }

    // The freshly published version 5 IIDs.
    for (name, expected, current) in [
        (
            "IAvnContentControl",
            "2C4557A2-537C-5683-9E30-C3AE87D7614C",
            I_AVN_CONTENT_CONTROL_IID,
        ),
        (
            "IAvnButton",
            "6D86D2DB-4473-576B-8778-47C74AAF182D",
            I_AVN_BUTTON_IID,
        ),
        (
            "IAvnToggleButton",
            "587791B4-65DA-5D37-9E5B-C03B93115683",
            I_AVN_TOGGLE_BUTTON_IID,
        ),
        (
            "IAvnListBox",
            "EAD15413-53EB-5159-BE99-7BED7BF25651",
            I_AVN_LIST_BOX_IID,
        ),
        (
            "IAvnComboBox",
            "7334041F-D155-548C-BF70-4CFFB4F44021",
            I_AVN_COMBO_BOX_IID,
        ),
        (
            "IAvnWindow",
            "965CC1CE-DA6F-5CCB-900F-3150CA8DB605",
            I_AVN_WINDOW_IID,
        ),
    ] {
        assert_eq!(format_iid(&current), expected, "{name} changed its IID");
    }

    // Nothing that kept its vtable may change identity.
    assert_eq!(
        format_iid(&I_AVN_AVALONIA_OBJECT_IID),
        "FA7F2E03-0BFA-5422-840B-18AE1D9695C0"
    );
    assert_eq!(
        format_iid(&I_AVN_CONTROL_IID),
        "7CF51B18-C500-5D06-8FFA-D97EF7BC6487"
    );
    assert_eq!(
        format_iid(&I_AVN_BORDER_IID),
        "A8DE13FB-23AB-59DD-ABD1-000C9EA5693B"
    );
    assert_eq!(
        format_iid(&I_AVN_PANEL_IID),
        "BD97617A-EEDC-5695-88C1-E30E6673B286"
    );
    assert_eq!(
        format_iid(&I_AVN_TEMPLATED_CONTROL_IID),
        "002B0BD0-7F53-52CD-A7BC-499224438B34"
    );
    assert_eq!(
        format_iid(&I_AVN_TEXT_BLOCK_IID),
        "3348758A-72D6-5B1F-84F2-9D80A51DC2FD"
    );
}

fn format_iid(iid: &avalonia_sys::Guid) -> String {
    let mut out = format!("{:08X}-{:04X}-{:04X}-", iid.data1, iid.data2, iid.data3);
    for (index, byte) in iid.data4.iter().enumerate() {
        if index == 2 {
            out.push('-');
        }
        out.push_str(&format!("{byte:02X}"));
    }
    out
}
