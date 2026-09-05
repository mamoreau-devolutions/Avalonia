//! ABI guarantees for `Grid`'s column and row definitions.
//!
//! The definitions cross as the comma-separated length list that `ColumnDefinitions` and
//! `RowDefinitions` already parse and print, so they occupy ordinary UTF-16 string slots
//! rather than a projected collection of definition objects. `Grid` is the only interface
//! that grew, and nothing in the object model derives from it, so it is also the only one
//! that republishes.

use avalonia_sys::{
    I_AVN_AVALONIA_OBJECT_IID, I_AVN_CANVAS_IID, I_AVN_CONTROL_IID, I_AVN_DOCK_PANEL_IID,
    I_AVN_GRID_IID, I_AVN_PANEL_IID, I_AVN_STACK_PANEL_IID,
};

const HEADER: &str = include_str!("../include/avalonia-rust-abi.h");

#[test]
fn definitions_are_published_as_utf16_string_slots_on_grid() {
    for expected in [
        "*get_column_definitions)(IAvnGrid* self, uint16_t** value)",
        "*set_column_definitions)(IAvnGrid* self, const uint16_t* value)",
        "*get_row_definitions)(IAvnGrid* self, uint16_t** value)",
        "*set_row_definitions)(IAvnGrid* self, const uint16_t* value)",
        // They are appended after the members Grid already published, so no existing slot moved.
        "*set_column_spacing)(IAvnGrid* self, double value); /* slot 59 */",
        "*get_column_definitions)(IAvnGrid* self, uint16_t** value); /* slot 60 */",
        "#define I_AVN_GRID_VTABLE_SLOTS 64",
    ] {
        assert!(HEADER.contains(expected), "header is missing `{expected}`");
    }

    // A definition list is a string, not a projected collection: no per-definition interface
    // is minted, so there is nothing here with IBrush-level reference-graph complexity.
    for forbidden in [
        "IAvnColumnDefinition",
        "IAvnRowDefinition",
        "IAvnColumnDefinitionList",
        "IAvnRowDefinitionList",
    ] {
        assert!(
            !HEADER.contains(forbidden),
            "header must not declare `{forbidden}`"
        );
    }
}

#[test]
fn only_grid_moved_to_abi_version_five_for_the_definitions() {
    for expected in [
        "#define I_AVN_GRID_ABI_VERSION 8",
        // Grid's base and its sibling panels gained nothing, so their flattened vtables are
        // byte-identical and they keep the version they already published.
        "#define I_AVN_PANEL_ABI_VERSION 7",
        "#define I_AVN_CANVAS_ABI_VERSION 7",
        "#define I_AVN_DOCK_PANEL_ABI_VERSION 7",
        "#define I_AVN_STACK_PANEL_ABI_VERSION 8",
        "#define I_AVN_CONTROL_ABI_VERSION 5",
        "#define I_AVN_AVALONIA_OBJECT_ABI_VERSION 2",
        // The factory mints no definition object, but wave A gave it a creator per new control
        // and get_tool_tip_statics and wave B gave it seven more, so it now publishes at
        // version 4.
        "#define I_AVN_CONTROL_FACTORY_ABI_VERSION 13",
    ] {
        assert!(HEADER.contains(expected), "header is missing `{expected}`");
    }
}

#[test]
fn grid_republishes_under_a_fresh_iid_and_never_reuses_a_retired_one() {
    assert_eq!(
        format_iid(&I_AVN_GRID_IID),
        "B57FF025-1BB8-5CC1-B232-AC3E88445C4B"
    );

    // Every IID Grid has ever published is retired for good: reusing one for a longer vtable
    // would let a stale consumer call through slots its contract never declared.
    for retired in [
        "C6A7C566-BD63-537E-88BD-88A47515F1A7",
        "63B055A6-7C40-5F6D-9A36-4430CB8FED95",
        "B383BDBC-D6E0-500D-AEE5-50363B62912D",
        "240199CD-F2BD-55CD-BE4D-8DA83F228D71",
    ] {
        assert_ne!(
            format_iid(&I_AVN_GRID_IID),
            retired,
            "IAvnGrid reused a retired IID"
        );
        assert!(
            !HEADER.contains(&format!("0x{}", &retired[..8])),
            "header still declares the retired IAvnGrid IID `{retired}`"
        );
    }

    // Nothing else changed identity.
    for (name, expected, current) in [
        (
            "IAvnAvaloniaObject",
            "FA7F2E03-0BFA-5422-840B-18AE1D9695C0",
            I_AVN_AVALONIA_OBJECT_IID,
        ),
        (
            "IAvnControl",
            "C08EBEE5-BDFD-5A33-9024-B64C139D1088",
            I_AVN_CONTROL_IID,
        ),
        (
            "IAvnPanel",
            "712FA85F-0521-517E-BD9B-B655F436360E",
            I_AVN_PANEL_IID,
        ),
    ] {
        assert_eq!(format_iid(&current), expected, "{name} changed its IID");
    }

    // The sibling panels are distinct interfaces that did not move with Grid.
    for sibling in [
        I_AVN_CANVAS_IID,
        I_AVN_DOCK_PANEL_IID,
        I_AVN_STACK_PANEL_IID,
    ] {
        assert_ne!(format_iid(&sibling), format_iid(&I_AVN_GRID_IID));
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
