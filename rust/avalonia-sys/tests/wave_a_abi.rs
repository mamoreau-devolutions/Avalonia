//! ABI guarantees for the wave A controls: `Image`, the tab pair, the tree pair,
//! `HeaderedItemsControl` and the `ToolTip` attached properties.
//!
//! Wave A adds new interfaces, but the item-control subtree widened when the allowlist exposed
//! `ItemCount`/`ScrollIntoView(Int32)` and the selecting-item toggles, so the interfaces under
//! that flattened vtable republish under fresh IIDs. The new interfaces that remain outside that
//! subtree keep their version-1 contract, and the factory still gains the new creators.

use avalonia_sys::{
    I_AVN_AVALONIA_OBJECT_IID, I_AVN_CONTENT_CONTROL_IID, I_AVN_CONTROL_IID,
    I_AVN_HEADERED_CONTENT_CONTROL_IID, I_AVN_HEADERED_ITEMS_CONTROL_IID, I_AVN_IMAGE_IID,
    I_AVN_ITEMS_CONTROL_IID, I_AVN_SELECTING_ITEMS_CONTROL_IID, I_AVN_TAB_CONTROL_IID,
    I_AVN_TAB_ITEM_IID, I_AVN_TOOL_TIP_IID, I_AVN_TOOL_TIP_STATICS_IID, I_AVN_TREE_VIEW_IID,
    I_AVN_TREE_VIEW_ITEM_IID,
};

const HEADER: &str = include_str!("../include/avalonia-rust-abi.h");

#[test]
fn image_source_is_published_as_a_utf16_string_slot() {
    // Source crosses as the source string the host resolves into a bitmap, so it occupies an
    // ordinary string pair rather than a projected image interface.
    for expected in [
        "*get_source)(IAvnImage* self, uint16_t** value)",
        "*set_source)(IAvnImage* self, const uint16_t* value)",
        "*set_stretch)(IAvnImage* self, int32_t value)",
        "*set_stretch_direction)(IAvnImage* self, int32_t value)",
        "*set_blend_mode)(IAvnImage* self, int32_t value)",
        "#define I_AVN_IMAGE_ABI_VERSION 1",
    ] {
        assert!(HEADER.contains(expected), "header is missing `{expected}`");
    }

    // No image object is minted, so nothing here carries IBrush-level reference-graph
    // complexity.
    for forbidden in ["IAvnImageSource", "IAvnBitmap", "IAvnImageList"] {
        assert!(
            !HEADER.contains(forbidden),
            "header must not declare `{forbidden}`"
        );
    }
}

#[test]
fn tool_tip_tip_is_a_string_attached_property_beside_the_scalar_ones() {
    for expected in [
        "*get_tip)(IAvnToolTipStatics* self, IAvnControl* target, uint16_t** value)",
        "*set_tip)(IAvnToolTipStatics* self, IAvnControl* target, const uint16_t* value)",
        "*set_show_delay)(IAvnToolTipStatics* self, IAvnControl* target, int32_t value)",
        "*set_placement)(IAvnToolTipStatics* self, IAvnControl* target, int32_t value)",
        "*set_horizontal_offset)(IAvnToolTipStatics* self, IAvnControl* target, double value)",
        "#define I_AVN_TOOL_TIP_STATICS_ABI_VERSION 1",
        // The factory hands the statics object out beside the ones it already published.
        "*get_tool_tip_statics)(IAvnControlFactory* self, IAvnToolTipStatics** value)",
        "*create_image)(IAvnControlFactory* self, IAvnImage** value)",
        "*create_tab_control)(IAvnControlFactory* self, IAvnTabControl** value)",
        "*create_tree_view_item)(IAvnControlFactory* self, IAvnTreeViewItem** value)",
    ] {
        assert!(HEADER.contains(expected), "header is missing `{expected}`");
    }
}

#[test]
fn wave_a_interfaces_publish_abi_version_one_and_nothing_else_moved() {
    for expected in [
        "#define I_AVN_IMAGE_ABI_VERSION 1",
        "#define I_AVN_HEADERED_ITEMS_CONTROL_ABI_VERSION 3",
        "#define I_AVN_TAB_CONTROL_ABI_VERSION 3",
        "#define I_AVN_TAB_ITEM_ABI_VERSION 2",
        "#define I_AVN_TREE_VIEW_ABI_VERSION 3",
        "#define I_AVN_TREE_VIEW_ITEM_ABI_VERSION 3",
        "#define I_AVN_TOOL_TIP_ABI_VERSION 2",
        // The item-control allowlist widened the flattened vtable for its descendants, so the
        // bases and the descended controls republish together while unrelated wave-A interfaces
        // keep the version whose flattened vtable they still match.
        "#define I_AVN_AVALONIA_OBJECT_ABI_VERSION 2",
        "#define I_AVN_CONTROL_ABI_VERSION 3",
        "#define I_AVN_ITEMS_CONTROL_ABI_VERSION 6",
        "#define I_AVN_SELECTING_ITEMS_CONTROL_ABI_VERSION 6",
        "#define I_AVN_CONTENT_CONTROL_ABI_VERSION 6",
        "#define I_AVN_HEADERED_CONTENT_CONTROL_ABI_VERSION 6",
        // Only the factory grew slots. Wave B moved it again, from 3 to 4, for its own
        // creators; the item-control subtree instead republished under its new flattened vtable.
        "#define I_AVN_CONTROL_FACTORY_ABI_VERSION 13",
    ] {
        assert!(HEADER.contains(expected), "header is missing `{expected}`");
    }
}

#[test]
fn wave_a_iids_are_fresh_and_distinct_from_every_shipped_one() {
    // The interfaces the new types derive from must be byte-identical to what shipped, or a
    // consumer holding one would be calling through a contract that quietly changed.
    for (name, expected, current) in [
        (
            "IAvnAvaloniaObject",
            "FA7F2E03-0BFA-5422-840B-18AE1D9695C0",
            I_AVN_AVALONIA_OBJECT_IID,
        ),
        (
            "IAvnControl",
            "7CF51B18-C500-5D06-8FFA-D97EF7BC6487",
            I_AVN_CONTROL_IID,
        ),
        (
            "IAvnItemsControl",
            "AD06A856-E8AF-5AC5-9105-A81F3AE12D4D",
            I_AVN_ITEMS_CONTROL_IID,
        ),
        (
            "IAvnSelectingItemsControl",
            "5F901899-E71F-503E-9DF5-95C167014353",
            I_AVN_SELECTING_ITEMS_CONTROL_IID,
        ),
        (
            "IAvnContentControl",
            "35C15BC0-F6CD-51D5-868A-9A391D7EF443",
            I_AVN_CONTENT_CONTROL_IID,
        ),
        (
            "IAvnHeaderedContentControl",
            "FEF87661-E67A-5C14-A8B6-A3BD6D47EACA",
            I_AVN_HEADERED_CONTENT_CONTROL_IID,
        ),
    ] {
        assert_eq!(format_iid(&current), expected, "{name} changed its IID");
    }

    let wave_a = [
        I_AVN_IMAGE_IID,
        I_AVN_HEADERED_ITEMS_CONTROL_IID,
        I_AVN_TAB_CONTROL_IID,
        I_AVN_TAB_ITEM_IID,
        I_AVN_TREE_VIEW_IID,
        I_AVN_TREE_VIEW_ITEM_IID,
        I_AVN_TOOL_TIP_IID,
        I_AVN_TOOL_TIP_STATICS_IID,
    ];
    let shipped = [
        I_AVN_AVALONIA_OBJECT_IID,
        I_AVN_CONTROL_IID,
        I_AVN_ITEMS_CONTROL_IID,
        I_AVN_SELECTING_ITEMS_CONTROL_IID,
        I_AVN_CONTENT_CONTROL_IID,
        I_AVN_HEADERED_CONTENT_CONTROL_IID,
    ];
    for new in wave_a {
        for old in shipped {
            assert_ne!(
                format_iid(&new),
                format_iid(&old),
                "a wave A interface reused a shipped IID"
            );
        }
    }
    for (index, left) in wave_a.iter().enumerate() {
        for right in &wave_a[index + 1..] {
            assert_ne!(
                format_iid(left),
                format_iid(right),
                "two wave A interfaces share an IID"
            );
        }
    }
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
