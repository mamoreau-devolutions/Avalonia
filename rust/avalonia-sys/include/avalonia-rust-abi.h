/* Generated from projection.ir.json. Do not edit. */
#ifndef AVALONIA_RUST_ABI_H
#define AVALONIA_RUST_ABI_H

#include <stdint.h>

#if defined(_WIN32)
#define AVN_CALL __stdcall
#else
#define AVN_CALL
#endif

typedef int32_t AvnHResult;
typedef struct AvnGuid {
    uint32_t data1;
    uint16_t data2;
    uint16_t data3;
    uint8_t data4[8];
} AvnGuid;

/* Blittable ABI mirror of Avalonia.Thickness. */
typedef struct AvnThickness {
    double left;
    double top;
    double right;
    double bottom;
} AvnThickness;

/* Blittable ABI mirror of Avalonia.CornerRadius. */
typedef struct AvnCornerRadius {
    double top_left;
    double top_right;
    double bottom_right;
    double bottom_left;
} AvnCornerRadius;

/* Blittable ABI mirror of Avalonia.Size. */
typedef struct AvnSize {
    double width;
    double height;
} AvnSize;

/* Blittable ABI mirror of Avalonia.Point. */
typedef struct AvnPoint {
    double x;
    double y;
} AvnPoint;

/* Blittable ABI mirror of Avalonia.Rect. */
typedef struct AvnRect {
    double x;
    double y;
    double width;
    double height;
} AvnRect;

/* Blittable ABI mirror of Avalonia.Media.Color. */
typedef struct AvnColor {
    uint32_t argb;
} AvnColor;

typedef struct IAvnAvaloniaObject IAvnAvaloniaObject;
typedef struct IAvnAvaloniaObjectVtbl IAvnAvaloniaObjectVtbl;
typedef struct IAvnBorder IAvnBorder;
typedef struct IAvnBorderVtbl IAvnBorderVtbl;
typedef struct IAvnBrush IAvnBrush;
typedef struct IAvnBrushVtbl IAvnBrushVtbl;
typedef struct IAvnButton IAvnButton;
typedef struct IAvnButtonVtbl IAvnButtonVtbl;
typedef struct IAvnButtonClickHandler IAvnButtonClickHandler;
typedef struct IAvnButtonClickHandlerVtbl IAvnButtonClickHandlerVtbl;
typedef struct IAvnCanvas IAvnCanvas;
typedef struct IAvnCanvasVtbl IAvnCanvasVtbl;
typedef struct IAvnCanvasStatics IAvnCanvasStatics;
typedef struct IAvnCanvasStaticsVtbl IAvnCanvasStaticsVtbl;
typedef struct IAvnCheckBox IAvnCheckBox;
typedef struct IAvnCheckBoxVtbl IAvnCheckBoxVtbl;
typedef struct IAvnComboBox IAvnComboBox;
typedef struct IAvnComboBoxVtbl IAvnComboBoxVtbl;
typedef struct IAvnComboBoxItem IAvnComboBoxItem;
typedef struct IAvnComboBoxItemVtbl IAvnComboBoxItemVtbl;
typedef struct IAvnContentControl IAvnContentControl;
typedef struct IAvnContentControlVtbl IAvnContentControlVtbl;
typedef struct IAvnControl IAvnControl;
typedef struct IAvnControlVtbl IAvnControlVtbl;
typedef struct IAvnControlFactory IAvnControlFactory;
typedef struct IAvnControlFactoryVtbl IAvnControlFactoryVtbl;
typedef struct IAvnControlKeyDownHandler IAvnControlKeyDownHandler;
typedef struct IAvnControlKeyDownHandlerVtbl IAvnControlKeyDownHandlerVtbl;
typedef struct IAvnControlList IAvnControlList;
typedef struct IAvnControlListVtbl IAvnControlListVtbl;
typedef struct IAvnControlPointerEnteredHandler IAvnControlPointerEnteredHandler;
typedef struct IAvnControlPointerEnteredHandlerVtbl IAvnControlPointerEnteredHandlerVtbl;
typedef struct IAvnControlPointerExitedHandler IAvnControlPointerExitedHandler;
typedef struct IAvnControlPointerExitedHandlerVtbl IAvnControlPointerExitedHandlerVtbl;
typedef struct IAvnDecorator IAvnDecorator;
typedef struct IAvnDecoratorVtbl IAvnDecoratorVtbl;
typedef struct IAvnDockPanel IAvnDockPanel;
typedef struct IAvnDockPanelVtbl IAvnDockPanelVtbl;
typedef struct IAvnDockPanelStatics IAvnDockPanelStatics;
typedef struct IAvnDockPanelStaticsVtbl IAvnDockPanelStaticsVtbl;
typedef struct IAvnExpander IAvnExpander;
typedef struct IAvnExpanderVtbl IAvnExpanderVtbl;
typedef struct IAvnExpanderCollapsedHandler IAvnExpanderCollapsedHandler;
typedef struct IAvnExpanderCollapsedHandlerVtbl IAvnExpanderCollapsedHandlerVtbl;
typedef struct IAvnExpanderExpandedHandler IAvnExpanderExpandedHandler;
typedef struct IAvnExpanderExpandedHandlerVtbl IAvnExpanderExpandedHandlerVtbl;
typedef struct IAvnGrid IAvnGrid;
typedef struct IAvnGridVtbl IAvnGridVtbl;
typedef struct IAvnGridStatics IAvnGridStatics;
typedef struct IAvnGridStaticsVtbl IAvnGridStaticsVtbl;
typedef struct IAvnHeaderedContentControl IAvnHeaderedContentControl;
typedef struct IAvnHeaderedContentControlVtbl IAvnHeaderedContentControlVtbl;
typedef struct IAvnItemList IAvnItemList;
typedef struct IAvnItemListVtbl IAvnItemListVtbl;
typedef struct IAvnItemsControl IAvnItemsControl;
typedef struct IAvnItemsControlVtbl IAvnItemsControlVtbl;
typedef struct IAvnListBox IAvnListBox;
typedef struct IAvnListBoxVtbl IAvnListBoxVtbl;
typedef struct IAvnListBoxItem IAvnListBoxItem;
typedef struct IAvnListBoxItemVtbl IAvnListBoxItemVtbl;
typedef struct IAvnPanel IAvnPanel;
typedef struct IAvnPanelVtbl IAvnPanelVtbl;
typedef struct IAvnProgressBar IAvnProgressBar;
typedef struct IAvnProgressBarVtbl IAvnProgressBarVtbl;
typedef struct IAvnRadioButton IAvnRadioButton;
typedef struct IAvnRadioButtonVtbl IAvnRadioButtonVtbl;
typedef struct IAvnRangeBase IAvnRangeBase;
typedef struct IAvnRangeBaseVtbl IAvnRangeBaseVtbl;
typedef struct IAvnRangeBaseValueChangedHandler IAvnRangeBaseValueChangedHandler;
typedef struct IAvnRangeBaseValueChangedHandlerVtbl IAvnRangeBaseValueChangedHandlerVtbl;
typedef struct IAvnScrollViewer IAvnScrollViewer;
typedef struct IAvnScrollViewerVtbl IAvnScrollViewerVtbl;
typedef struct IAvnScrollViewerScrollChangedHandler IAvnScrollViewerScrollChangedHandler;
typedef struct IAvnScrollViewerScrollChangedHandlerVtbl IAvnScrollViewerScrollChangedHandlerVtbl;
typedef struct IAvnSelectingItemsControl IAvnSelectingItemsControl;
typedef struct IAvnSelectingItemsControlVtbl IAvnSelectingItemsControlVtbl;
typedef struct IAvnSelectingItemsControlSelectionChangedHandler IAvnSelectingItemsControlSelectionChangedHandler;
typedef struct IAvnSelectingItemsControlSelectionChangedHandlerVtbl IAvnSelectingItemsControlSelectionChangedHandlerVtbl;
typedef struct IAvnSlider IAvnSlider;
typedef struct IAvnSliderVtbl IAvnSliderVtbl;
typedef struct IAvnStackPanel IAvnStackPanel;
typedef struct IAvnStackPanelVtbl IAvnStackPanelVtbl;
typedef struct IAvnStringList IAvnStringList;
typedef struct IAvnStringListVtbl IAvnStringListVtbl;
typedef struct IAvnStyledElement IAvnStyledElement;
typedef struct IAvnStyledElementVtbl IAvnStyledElementVtbl;
typedef struct IAvnTemplatedControl IAvnTemplatedControl;
typedef struct IAvnTemplatedControlVtbl IAvnTemplatedControlVtbl;
typedef struct IAvnTextBlock IAvnTextBlock;
typedef struct IAvnTextBlockVtbl IAvnTextBlockVtbl;
typedef struct IAvnTextBox IAvnTextBox;
typedef struct IAvnTextBoxVtbl IAvnTextBoxVtbl;
typedef struct IAvnTextBoxTextChangedHandler IAvnTextBoxTextChangedHandler;
typedef struct IAvnTextBoxTextChangedHandlerVtbl IAvnTextBoxTextChangedHandlerVtbl;
typedef struct IAvnToggleButton IAvnToggleButton;
typedef struct IAvnToggleButtonVtbl IAvnToggleButtonVtbl;
typedef struct IAvnToggleButtonIsCheckedChangedHandler IAvnToggleButtonIsCheckedChangedHandler;
typedef struct IAvnToggleButtonIsCheckedChangedHandlerVtbl IAvnToggleButtonIsCheckedChangedHandlerVtbl;
typedef struct IAvnToggleSwitch IAvnToggleSwitch;
typedef struct IAvnToggleSwitchVtbl IAvnToggleSwitchVtbl;
typedef struct IAvnWindow IAvnWindow;
typedef struct IAvnWindowVtbl IAvnWindowVtbl;

static const AvnGuid I_AVN_BUTTON_CLICK_HANDLER_IID = {
    0x4D76B167,
    0xC926,
    0x5DBD,
    { 0x86, 0xF0, 0xEF, 0x35, 0x2D, 0x9C, 0xBF, 0x9B }
};
#define I_AVN_BUTTON_CLICK_HANDLER_ABI_VERSION 1
struct IAvnButtonClickHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnButtonClickHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnButtonClickHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnButtonClickHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnButtonClickHandler* self); /* slot 3 */
};
struct IAvnButtonClickHandler { const IAvnButtonClickHandlerVtbl* vtbl; };
#define I_AVN_BUTTON_CLICK_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_CONTROL_KEY_DOWN_HANDLER_IID = {
    0x9232F26F,
    0x2F3B,
    0x5BA2,
    { 0xB0, 0x98, 0xE4, 0xCB, 0x6B, 0x26, 0xBD, 0xA3 }
};
#define I_AVN_CONTROL_KEY_DOWN_HANDLER_ABI_VERSION 1
struct IAvnControlKeyDownHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnControlKeyDownHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnControlKeyDownHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnControlKeyDownHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnControlKeyDownHandler* self, int32_t key, int32_t physical_key, int32_t key_modifiers, const uint16_t* key_symbol, int32_t* handled); /* slot 3 */
};
struct IAvnControlKeyDownHandler { const IAvnControlKeyDownHandlerVtbl* vtbl; };
#define I_AVN_CONTROL_KEY_DOWN_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_CONTROL_POINTER_ENTERED_HANDLER_IID = {
    0xCC8694AC,
    0xC51C,
    0x5791,
    { 0xA8, 0x98, 0x1B, 0x0D, 0xE4, 0xD8, 0x4D, 0xC8 }
};
#define I_AVN_CONTROL_POINTER_ENTERED_HANDLER_ABI_VERSION 1
struct IAvnControlPointerEnteredHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnControlPointerEnteredHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnControlPointerEnteredHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnControlPointerEnteredHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnControlPointerEnteredHandler* self); /* slot 3 */
};
struct IAvnControlPointerEnteredHandler { const IAvnControlPointerEnteredHandlerVtbl* vtbl; };
#define I_AVN_CONTROL_POINTER_ENTERED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_CONTROL_POINTER_EXITED_HANDLER_IID = {
    0x218295EF,
    0xA88D,
    0x5B93,
    { 0x8A, 0x33, 0x97, 0xAB, 0xD4, 0x1E, 0x66, 0x45 }
};
#define I_AVN_CONTROL_POINTER_EXITED_HANDLER_ABI_VERSION 1
struct IAvnControlPointerExitedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnControlPointerExitedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnControlPointerExitedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnControlPointerExitedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnControlPointerExitedHandler* self); /* slot 3 */
};
struct IAvnControlPointerExitedHandler { const IAvnControlPointerExitedHandlerVtbl* vtbl; };
#define I_AVN_CONTROL_POINTER_EXITED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_EXPANDER_COLLAPSED_HANDLER_IID = {
    0x09BF1232,
    0x4B8A,
    0x5657,
    { 0xA7, 0x74, 0xA2, 0x79, 0x95, 0x50, 0x1A, 0x13 }
};
#define I_AVN_EXPANDER_COLLAPSED_HANDLER_ABI_VERSION 1
struct IAvnExpanderCollapsedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnExpanderCollapsedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnExpanderCollapsedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnExpanderCollapsedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnExpanderCollapsedHandler* self); /* slot 3 */
};
struct IAvnExpanderCollapsedHandler { const IAvnExpanderCollapsedHandlerVtbl* vtbl; };
#define I_AVN_EXPANDER_COLLAPSED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_EXPANDER_EXPANDED_HANDLER_IID = {
    0x9CB04F88,
    0x445A,
    0x51C5,
    { 0x81, 0xEC, 0x9E, 0x5C, 0xFE, 0x52, 0xCE, 0xD4 }
};
#define I_AVN_EXPANDER_EXPANDED_HANDLER_ABI_VERSION 1
struct IAvnExpanderExpandedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnExpanderExpandedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnExpanderExpandedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnExpanderExpandedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnExpanderExpandedHandler* self); /* slot 3 */
};
struct IAvnExpanderExpandedHandler { const IAvnExpanderExpandedHandlerVtbl* vtbl; };
#define I_AVN_EXPANDER_EXPANDED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_RANGE_BASE_VALUE_CHANGED_HANDLER_IID = {
    0xDAEDA8F7,
    0xD1F6,
    0x54B6,
    { 0x90, 0x0D, 0x4A, 0xAB, 0x0B, 0x0C, 0x72, 0xBA }
};
#define I_AVN_RANGE_BASE_VALUE_CHANGED_HANDLER_ABI_VERSION 1
struct IAvnRangeBaseValueChangedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnRangeBaseValueChangedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnRangeBaseValueChangedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnRangeBaseValueChangedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnRangeBaseValueChangedHandler* self); /* slot 3 */
};
struct IAvnRangeBaseValueChangedHandler { const IAvnRangeBaseValueChangedHandlerVtbl* vtbl; };
#define I_AVN_RANGE_BASE_VALUE_CHANGED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_SCROLL_VIEWER_SCROLL_CHANGED_HANDLER_IID = {
    0x66A75556,
    0x3AA6,
    0x5EC7,
    { 0xB4, 0xA4, 0x02, 0x65, 0xCF, 0xD7, 0x81, 0x39 }
};
#define I_AVN_SCROLL_VIEWER_SCROLL_CHANGED_HANDLER_ABI_VERSION 1
struct IAvnScrollViewerScrollChangedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnScrollViewerScrollChangedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnScrollViewerScrollChangedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnScrollViewerScrollChangedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnScrollViewerScrollChangedHandler* self); /* slot 3 */
};
struct IAvnScrollViewerScrollChangedHandler { const IAvnScrollViewerScrollChangedHandlerVtbl* vtbl; };
#define I_AVN_SCROLL_VIEWER_SCROLL_CHANGED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_SELECTING_ITEMS_CONTROL_SELECTION_CHANGED_HANDLER_IID = {
    0x80E817ED,
    0x8F0E,
    0x5208,
    { 0x9E, 0xFD, 0xEC, 0xBD, 0xEB, 0xC5, 0x6A, 0x46 }
};
#define I_AVN_SELECTING_ITEMS_CONTROL_SELECTION_CHANGED_HANDLER_ABI_VERSION 1
struct IAvnSelectingItemsControlSelectionChangedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnSelectingItemsControlSelectionChangedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnSelectingItemsControlSelectionChangedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnSelectingItemsControlSelectionChangedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnSelectingItemsControlSelectionChangedHandler* self); /* slot 3 */
};
struct IAvnSelectingItemsControlSelectionChangedHandler { const IAvnSelectingItemsControlSelectionChangedHandlerVtbl* vtbl; };
#define I_AVN_SELECTING_ITEMS_CONTROL_SELECTION_CHANGED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_TEXT_BOX_TEXT_CHANGED_HANDLER_IID = {
    0x599D5C79,
    0xE8CB,
    0x52F0,
    { 0xBD, 0x79, 0xCE, 0xFE, 0x66, 0xD9, 0x9C, 0x0C }
};
#define I_AVN_TEXT_BOX_TEXT_CHANGED_HANDLER_ABI_VERSION 1
struct IAvnTextBoxTextChangedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTextBoxTextChangedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTextBoxTextChangedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTextBoxTextChangedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnTextBoxTextChangedHandler* self); /* slot 3 */
};
struct IAvnTextBoxTextChangedHandler { const IAvnTextBoxTextChangedHandlerVtbl* vtbl; };
#define I_AVN_TEXT_BOX_TEXT_CHANGED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_TOGGLE_BUTTON_IS_CHECKED_CHANGED_HANDLER_IID = {
    0xFF444C66,
    0x8E6C,
    0x5B93,
    { 0x9D, 0xB3, 0xA7, 0xD9, 0x43, 0x49, 0x10, 0x3C }
};
#define I_AVN_TOGGLE_BUTTON_IS_CHECKED_CHANGED_HANDLER_ABI_VERSION 1
struct IAvnToggleButtonIsCheckedChangedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnToggleButtonIsCheckedChangedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnToggleButtonIsCheckedChangedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnToggleButtonIsCheckedChangedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnToggleButtonIsCheckedChangedHandler* self); /* slot 3 */
};
struct IAvnToggleButtonIsCheckedChangedHandler { const IAvnToggleButtonIsCheckedChangedHandlerVtbl* vtbl; };
#define I_AVN_TOGGLE_BUTTON_IS_CHECKED_CHANGED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_BRUSH_IID = {
    0xFC7CCBAE,
    0xED75,
    0x5C6D,
    { 0x85, 0x16, 0xDF, 0x70, 0x6E, 0x13, 0x7E, 0xD3 }
};
#define I_AVN_BRUSH_ABI_VERSION 1
struct IAvnBrushVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnBrush* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnBrush* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnBrush* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_color)(IAvnBrush* self, AvnColor* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnBrush* self, double* value); /* slot 4 */
};
struct IAvnBrush { const IAvnBrushVtbl* vtbl; };
#define I_AVN_BRUSH_VTABLE_SLOTS 5

static const AvnGuid I_AVN_CONTROL_LIST_IID = {
    0x30347281,
    0x9A69,
    0x5CF9,
    { 0xAE, 0xEF, 0x9F, 0x70, 0x6A, 0x7D, 0xFE, 0x07 }
};
#define I_AVN_CONTROL_LIST_ABI_VERSION 1
struct IAvnControlListVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnControlList* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnControlList* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnControlList* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_count)(IAvnControlList* self, int32_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_at)(IAvnControlList* self, int32_t index, IAvnControl** value); /* slot 4 */
    AvnHResult (AVN_CALL *add)(IAvnControlList* self, IAvnControl* value); /* slot 5 */
    AvnHResult (AVN_CALL *index_of)(IAvnControlList* self, IAvnControl* value, int32_t* index); /* slot 6 */
    AvnHResult (AVN_CALL *remove_at)(IAvnControlList* self, int32_t index); /* slot 7 */
    AvnHResult (AVN_CALL *clear)(IAvnControlList* self); /* slot 8 */
};
struct IAvnControlList { const IAvnControlListVtbl* vtbl; };
#define I_AVN_CONTROL_LIST_VTABLE_SLOTS 9

static const AvnGuid I_AVN_ITEM_LIST_IID = {
    0x59A429A7,
    0xCF8A,
    0x5EB0,
    { 0xB6, 0x15, 0x91, 0x2A, 0x3D, 0xEF, 0x07, 0x04 }
};
#define I_AVN_ITEM_LIST_ABI_VERSION 1
struct IAvnItemListVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnItemList* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnItemList* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnItemList* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_count)(IAvnItemList* self, int32_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_at)(IAvnItemList* self, int32_t index, IAvnControl** value); /* slot 4 */
    AvnHResult (AVN_CALL *add)(IAvnItemList* self, IAvnControl* value); /* slot 5 */
    AvnHResult (AVN_CALL *index_of)(IAvnItemList* self, IAvnControl* value, int32_t* index); /* slot 6 */
    AvnHResult (AVN_CALL *remove_at)(IAvnItemList* self, int32_t index); /* slot 7 */
    AvnHResult (AVN_CALL *clear)(IAvnItemList* self); /* slot 8 */
};
struct IAvnItemList { const IAvnItemListVtbl* vtbl; };
#define I_AVN_ITEM_LIST_VTABLE_SLOTS 9

static const AvnGuid I_AVN_STRING_LIST_IID = {
    0xDD13073B,
    0x22E0,
    0x5372,
    { 0x86, 0xF8, 0x3B, 0x10, 0xD4, 0x8B, 0xC6, 0x01 }
};
#define I_AVN_STRING_LIST_ABI_VERSION 1
struct IAvnStringListVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnStringList* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnStringList* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnStringList* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_count)(IAvnStringList* self, int32_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_at)(IAvnStringList* self, int32_t index, uint16_t** value); /* slot 4 */
    AvnHResult (AVN_CALL *add)(IAvnStringList* self, const uint16_t* value); /* slot 5 */
    AvnHResult (AVN_CALL *index_of)(IAvnStringList* self, const uint16_t* value, int32_t* index); /* slot 6 */
    AvnHResult (AVN_CALL *remove_at)(IAvnStringList* self, int32_t index); /* slot 7 */
    AvnHResult (AVN_CALL *clear)(IAvnStringList* self); /* slot 8 */
};
struct IAvnStringList { const IAvnStringListVtbl* vtbl; };
#define I_AVN_STRING_LIST_VTABLE_SLOTS 9

static const AvnGuid I_AVN_AVALONIA_OBJECT_IID = {
    0xFA7F2E03,
    0x0BFA,
    0x5422,
    { 0x84, 0x0B, 0x18, 0xAE, 0x1D, 0x96, 0x95, 0xC0 }
};
#define I_AVN_AVALONIA_OBJECT_ABI_VERSION 2
struct IAvnAvaloniaObjectVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnAvaloniaObject* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnAvaloniaObject* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnAvaloniaObject* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnAvaloniaObject* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnAvaloniaObject* self, int64_t* value); /* slot 4 */
};
struct IAvnAvaloniaObject { const IAvnAvaloniaObjectVtbl* vtbl; };
#define I_AVN_AVALONIA_OBJECT_VTABLE_SLOTS 5

static const AvnGuid I_AVN_BORDER_IID = {
    0xA8DE13FB,
    0x23AB,
    0x59DD,
    { 0xAB, 0xD1, 0x00, 0x0C, 0x9E, 0xA5, 0x69, 0x3B }
};
#define I_AVN_BORDER_ABI_VERSION 4
struct IAvnBorderVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnBorder* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnBorder* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnBorder* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnBorder* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnBorder* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnBorder* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnBorder* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnBorder* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnBorder* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnBorder* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnBorder* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnBorder* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnBorder* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnBorder* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnBorder* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnBorder* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnBorder* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnBorder* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnBorder* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnBorder* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnBorder* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnBorder* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnBorder* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnBorder* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnBorder* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnBorder* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnBorder* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnBorder* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnBorder* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnBorder* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnBorder* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnBorder* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnBorder* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnBorder* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnBorder* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnBorder* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnBorder* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnBorder* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_child)(IAvnBorder* self, IAvnControl** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_child)(IAvnBorder* self, IAvnControl* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_padding)(IAvnBorder* self, AvnThickness* value); /* slot 40 */
    AvnHResult (AVN_CALL *set_padding)(IAvnBorder* self, AvnThickness value); /* slot 41 */
    AvnHResult (AVN_CALL *get_background)(IAvnBorder* self, IAvnBrush** value); /* slot 42 */
    AvnHResult (AVN_CALL *set_background)(IAvnBorder* self, IAvnBrush* value); /* slot 43 */
    AvnHResult (AVN_CALL *get_background_sizing)(IAvnBorder* self, int32_t* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_background_sizing)(IAvnBorder* self, int32_t value); /* slot 45 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnBorder* self, IAvnBrush** value); /* slot 46 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnBorder* self, IAvnBrush* value); /* slot 47 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnBorder* self, AvnThickness* value); /* slot 48 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnBorder* self, AvnThickness value); /* slot 49 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnBorder* self, AvnCornerRadius* value); /* slot 50 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnBorder* self, AvnCornerRadius value); /* slot 51 */
};
struct IAvnBorder { const IAvnBorderVtbl* vtbl; };
#define I_AVN_BORDER_VTABLE_SLOTS 52

static const AvnGuid I_AVN_BUTTON_IID = {
    0x6D86D2DB,
    0x4473,
    0x576B,
    { 0x87, 0x78, 0x47, 0xC7, 0x4A, 0xAF, 0x18, 0x2D }
};
#define I_AVN_BUTTON_ABI_VERSION 5
struct IAvnButtonVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnButton* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnButton* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnButton* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnButton* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnButton* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnButton* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnButton* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnButton* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnButton* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnButton* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnButton* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnButton* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnButton* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnButton* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnButton* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnButton* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnButton* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnButton* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnButton* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnButton* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnButton* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnButton* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnButton* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnButton* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnButton* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnButton* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnButton* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnButton* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnButton* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnButton* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnButton* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnButton* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnButton* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnButton* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnButton* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnButton* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnButton* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnButton* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnButton* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnButton* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnButton* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnButton* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnButton* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnButton* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnButton* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnButton* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnButton* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnButton* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnButton* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnButton* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_content)(IAvnButton* self, IAvnControl** value); /* slot 50 */
    AvnHResult (AVN_CALL *set_content)(IAvnButton* self, IAvnControl* value); /* slot 51 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnButton* self, int32_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnButton* self, int32_t value); /* slot 53 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnButton* self, int32_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnButton* self, int32_t value); /* slot 55 */
    AvnHResult (AVN_CALL *get_click_mode)(IAvnButton* self, int32_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *set_click_mode)(IAvnButton* self, int32_t value); /* slot 57 */
    AvnHResult (AVN_CALL *get_is_default)(IAvnButton* self, int32_t* value); /* slot 58 */
    AvnHResult (AVN_CALL *set_is_default)(IAvnButton* self, int32_t value); /* slot 59 */
    AvnHResult (AVN_CALL *get_is_cancel)(IAvnButton* self, int32_t* value); /* slot 60 */
    AvnHResult (AVN_CALL *set_is_cancel)(IAvnButton* self, int32_t value); /* slot 61 */
    AvnHResult (AVN_CALL *get_is_pressed)(IAvnButton* self, int32_t* value); /* slot 62 */
    AvnHResult (AVN_CALL *advise_click)(IAvnButton* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 63 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnButton* self, int64_t subscription_id); /* slot 64 */
};
struct IAvnButton { const IAvnButtonVtbl* vtbl; };
#define I_AVN_BUTTON_VTABLE_SLOTS 65

static const AvnGuid I_AVN_CANVAS_IID = {
    0x88515BBD,
    0x2133,
    0x5232,
    { 0xA7, 0x2C, 0x0F, 0x8D, 0x34, 0x8E, 0x58, 0x4E }
};
#define I_AVN_CANVAS_ABI_VERSION 4
struct IAvnCanvasVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCanvas* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCanvas* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCanvas* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnCanvas* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnCanvas* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnCanvas* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnCanvas* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnCanvas* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnCanvas* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnCanvas* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnCanvas* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnCanvas* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnCanvas* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnCanvas* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnCanvas* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnCanvas* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnCanvas* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnCanvas* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnCanvas* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnCanvas* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnCanvas* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnCanvas* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnCanvas* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnCanvas* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnCanvas* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnCanvas* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnCanvas* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnCanvas* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnCanvas* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnCanvas* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnCanvas* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnCanvas* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnCanvas* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnCanvas* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnCanvas* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnCanvas* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnCanvas* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnCanvas* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_children)(IAvnCanvas* self, IAvnControlList** value); /* slot 38 */
    AvnHResult (AVN_CALL *get_background)(IAvnCanvas* self, IAvnBrush** value); /* slot 39 */
    AvnHResult (AVN_CALL *set_background)(IAvnCanvas* self, IAvnBrush* value); /* slot 40 */
};
struct IAvnCanvas { const IAvnCanvasVtbl* vtbl; };
#define I_AVN_CANVAS_VTABLE_SLOTS 41

static const AvnGuid I_AVN_CHECK_BOX_IID = {
    0x56332928,
    0x3A00,
    0x552F,
    { 0xAC, 0x0F, 0x33, 0xE4, 0xC4, 0x6A, 0x93, 0x3D }
};
#define I_AVN_CHECK_BOX_ABI_VERSION 5
struct IAvnCheckBoxVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCheckBox* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCheckBox* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCheckBox* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnCheckBox* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnCheckBox* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnCheckBox* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnCheckBox* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnCheckBox* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnCheckBox* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnCheckBox* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnCheckBox* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnCheckBox* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnCheckBox* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnCheckBox* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnCheckBox* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnCheckBox* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnCheckBox* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnCheckBox* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnCheckBox* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnCheckBox* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnCheckBox* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnCheckBox* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnCheckBox* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnCheckBox* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnCheckBox* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnCheckBox* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnCheckBox* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnCheckBox* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnCheckBox* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnCheckBox* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnCheckBox* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnCheckBox* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnCheckBox* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnCheckBox* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnCheckBox* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnCheckBox* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnCheckBox* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnCheckBox* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnCheckBox* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnCheckBox* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnCheckBox* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnCheckBox* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnCheckBox* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnCheckBox* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnCheckBox* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnCheckBox* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnCheckBox* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnCheckBox* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnCheckBox* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnCheckBox* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_content)(IAvnCheckBox* self, IAvnControl** value); /* slot 50 */
    AvnHResult (AVN_CALL *set_content)(IAvnCheckBox* self, IAvnControl* value); /* slot 51 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnCheckBox* self, int32_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnCheckBox* self, int32_t value); /* slot 53 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnCheckBox* self, int32_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnCheckBox* self, int32_t value); /* slot 55 */
    AvnHResult (AVN_CALL *get_click_mode)(IAvnCheckBox* self, int32_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *set_click_mode)(IAvnCheckBox* self, int32_t value); /* slot 57 */
    AvnHResult (AVN_CALL *get_is_default)(IAvnCheckBox* self, int32_t* value); /* slot 58 */
    AvnHResult (AVN_CALL *set_is_default)(IAvnCheckBox* self, int32_t value); /* slot 59 */
    AvnHResult (AVN_CALL *get_is_cancel)(IAvnCheckBox* self, int32_t* value); /* slot 60 */
    AvnHResult (AVN_CALL *set_is_cancel)(IAvnCheckBox* self, int32_t value); /* slot 61 */
    AvnHResult (AVN_CALL *get_is_pressed)(IAvnCheckBox* self, int32_t* value); /* slot 62 */
    AvnHResult (AVN_CALL *advise_click)(IAvnCheckBox* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 63 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnCheckBox* self, int64_t subscription_id); /* slot 64 */
    AvnHResult (AVN_CALL *get_is_checked)(IAvnCheckBox* self, int32_t* value); /* slot 65 */
    AvnHResult (AVN_CALL *set_is_checked)(IAvnCheckBox* self, int32_t value); /* slot 66 */
    AvnHResult (AVN_CALL *get_is_three_state)(IAvnCheckBox* self, int32_t* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_is_three_state)(IAvnCheckBox* self, int32_t value); /* slot 68 */
    AvnHResult (AVN_CALL *advise_is_checked_changed)(IAvnCheckBox* self, IAvnToggleButtonIsCheckedChangedHandler* handler, int64_t* subscription_id); /* slot 69 */
    AvnHResult (AVN_CALL *unadvise_is_checked_changed)(IAvnCheckBox* self, int64_t subscription_id); /* slot 70 */
};
struct IAvnCheckBox { const IAvnCheckBoxVtbl* vtbl; };
#define I_AVN_CHECK_BOX_VTABLE_SLOTS 71

static const AvnGuid I_AVN_COMBO_BOX_IID = {
    0x7334041F,
    0xD155,
    0x548C,
    { 0xBF, 0x70, 0x4C, 0xFF, 0xB4, 0xF4, 0x40, 0x21 }
};
#define I_AVN_COMBO_BOX_ABI_VERSION 5
struct IAvnComboBoxVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnComboBox* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnComboBox* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnComboBox* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnComboBox* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnComboBox* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnComboBox* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnComboBox* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnComboBox* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnComboBox* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnComboBox* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnComboBox* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnComboBox* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnComboBox* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnComboBox* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnComboBox* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnComboBox* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnComboBox* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnComboBox* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnComboBox* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnComboBox* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnComboBox* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnComboBox* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnComboBox* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnComboBox* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnComboBox* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnComboBox* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnComboBox* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnComboBox* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnComboBox* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnComboBox* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnComboBox* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnComboBox* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnComboBox* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnComboBox* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnComboBox* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnComboBox* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnComboBox* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnComboBox* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnComboBox* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnComboBox* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnComboBox* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnComboBox* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnComboBox* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnComboBox* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnComboBox* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnComboBox* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnComboBox* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnComboBox* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnComboBox* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnComboBox* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_items)(IAvnComboBox* self, IAvnItemList** value); /* slot 50 */
    AvnHResult (AVN_CALL *get_selected_index)(IAvnComboBox* self, int32_t* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_selected_index)(IAvnComboBox* self, int32_t value); /* slot 52 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnComboBox* self, IAvnSelectingItemsControlSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 53 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnComboBox* self, int64_t subscription_id); /* slot 54 */
    AvnHResult (AVN_CALL *get_is_drop_down_open)(IAvnComboBox* self, int32_t* value); /* slot 55 */
    AvnHResult (AVN_CALL *set_is_drop_down_open)(IAvnComboBox* self, int32_t value); /* slot 56 */
    AvnHResult (AVN_CALL *get_is_editable)(IAvnComboBox* self, int32_t* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_is_editable)(IAvnComboBox* self, int32_t value); /* slot 58 */
    AvnHResult (AVN_CALL *get_max_drop_down_height)(IAvnComboBox* self, double* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_max_drop_down_height)(IAvnComboBox* self, double value); /* slot 60 */
    AvnHResult (AVN_CALL *get_placeholder_text)(IAvnComboBox* self, uint16_t** value); /* slot 61 */
    AvnHResult (AVN_CALL *set_placeholder_text)(IAvnComboBox* self, const uint16_t* value); /* slot 62 */
};
struct IAvnComboBox { const IAvnComboBoxVtbl* vtbl; };
#define I_AVN_COMBO_BOX_VTABLE_SLOTS 63

static const AvnGuid I_AVN_COMBO_BOX_ITEM_IID = {
    0x2502558C,
    0x2FB5,
    0x5DE4,
    { 0x83, 0x84, 0xF4, 0x9D, 0x0D, 0x72, 0x93, 0x2B }
};
#define I_AVN_COMBO_BOX_ITEM_ABI_VERSION 5
struct IAvnComboBoxItemVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnComboBoxItem* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnComboBoxItem* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnComboBoxItem* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnComboBoxItem* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnComboBoxItem* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnComboBoxItem* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnComboBoxItem* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnComboBoxItem* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnComboBoxItem* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnComboBoxItem* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnComboBoxItem* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnComboBoxItem* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnComboBoxItem* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnComboBoxItem* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnComboBoxItem* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnComboBoxItem* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnComboBoxItem* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnComboBoxItem* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnComboBoxItem* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnComboBoxItem* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnComboBoxItem* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnComboBoxItem* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnComboBoxItem* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnComboBoxItem* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnComboBoxItem* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnComboBoxItem* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnComboBoxItem* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnComboBoxItem* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnComboBoxItem* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnComboBoxItem* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnComboBoxItem* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnComboBoxItem* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnComboBoxItem* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnComboBoxItem* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnComboBoxItem* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnComboBoxItem* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnComboBoxItem* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnComboBoxItem* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnComboBoxItem* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnComboBoxItem* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnComboBoxItem* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnComboBoxItem* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnComboBoxItem* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnComboBoxItem* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnComboBoxItem* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnComboBoxItem* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnComboBoxItem* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnComboBoxItem* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnComboBoxItem* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnComboBoxItem* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_content)(IAvnComboBoxItem* self, IAvnControl** value); /* slot 50 */
    AvnHResult (AVN_CALL *set_content)(IAvnComboBoxItem* self, IAvnControl* value); /* slot 51 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnComboBoxItem* self, int32_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnComboBoxItem* self, int32_t value); /* slot 53 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnComboBoxItem* self, int32_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnComboBoxItem* self, int32_t value); /* slot 55 */
    AvnHResult (AVN_CALL *get_is_selected)(IAvnComboBoxItem* self, int32_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *set_is_selected)(IAvnComboBoxItem* self, int32_t value); /* slot 57 */
};
struct IAvnComboBoxItem { const IAvnComboBoxItemVtbl* vtbl; };
#define I_AVN_COMBO_BOX_ITEM_VTABLE_SLOTS 58

static const AvnGuid I_AVN_CONTENT_CONTROL_IID = {
    0x2C4557A2,
    0x537C,
    0x5683,
    { 0x9E, 0x30, 0xC3, 0xAE, 0x87, 0xD7, 0x61, 0x4C }
};
#define I_AVN_CONTENT_CONTROL_ABI_VERSION 5
struct IAvnContentControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnContentControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnContentControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnContentControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnContentControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnContentControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnContentControl* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnContentControl* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnContentControl* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnContentControl* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnContentControl* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnContentControl* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnContentControl* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnContentControl* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnContentControl* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnContentControl* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnContentControl* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnContentControl* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnContentControl* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnContentControl* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnContentControl* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnContentControl* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnContentControl* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnContentControl* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnContentControl* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnContentControl* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnContentControl* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnContentControl* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnContentControl* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnContentControl* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnContentControl* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnContentControl* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnContentControl* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnContentControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnContentControl* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnContentControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnContentControl* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnContentControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnContentControl* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnContentControl* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnContentControl* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnContentControl* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnContentControl* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnContentControl* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnContentControl* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnContentControl* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnContentControl* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnContentControl* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnContentControl* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnContentControl* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnContentControl* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_content)(IAvnContentControl* self, IAvnControl** value); /* slot 50 */
    AvnHResult (AVN_CALL *set_content)(IAvnContentControl* self, IAvnControl* value); /* slot 51 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnContentControl* self, int32_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnContentControl* self, int32_t value); /* slot 53 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnContentControl* self, int32_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnContentControl* self, int32_t value); /* slot 55 */
};
struct IAvnContentControl { const IAvnContentControlVtbl* vtbl; };
#define I_AVN_CONTENT_CONTROL_VTABLE_SLOTS 56

static const AvnGuid I_AVN_CONTROL_IID = {
    0x7CF51B18,
    0xC500,
    0x5D06,
    { 0x8F, 0xFA, 0xD9, 0x7E, 0xF7, 0xBC, 0x64, 0x87 }
};
#define I_AVN_CONTROL_ABI_VERSION 3
struct IAvnControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnControl* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnControl* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnControl* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnControl* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnControl* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnControl* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnControl* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnControl* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnControl* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnControl* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnControl* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnControl* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnControl* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnControl* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnControl* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnControl* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnControl* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnControl* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnControl* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnControl* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnControl* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnControl* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnControl* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnControl* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnControl* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnControl* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnControl* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnControl* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnControl* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnControl* self, int64_t subscription_id); /* slot 37 */
};
struct IAvnControl { const IAvnControlVtbl* vtbl; };
#define I_AVN_CONTROL_VTABLE_SLOTS 38

static const AvnGuid I_AVN_DECORATOR_IID = {
    0x32A420CD,
    0x730F,
    0x5FC4,
    { 0x91, 0x48, 0x18, 0xB4, 0x97, 0xAE, 0x91, 0xA7 }
};
#define I_AVN_DECORATOR_ABI_VERSION 3
struct IAvnDecoratorVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnDecorator* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnDecorator* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnDecorator* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnDecorator* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnDecorator* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnDecorator* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnDecorator* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnDecorator* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnDecorator* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnDecorator* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnDecorator* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnDecorator* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnDecorator* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnDecorator* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnDecorator* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnDecorator* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnDecorator* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnDecorator* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnDecorator* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnDecorator* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnDecorator* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnDecorator* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnDecorator* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnDecorator* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnDecorator* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnDecorator* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnDecorator* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnDecorator* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnDecorator* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnDecorator* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnDecorator* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnDecorator* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnDecorator* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnDecorator* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnDecorator* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnDecorator* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnDecorator* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnDecorator* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_child)(IAvnDecorator* self, IAvnControl** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_child)(IAvnDecorator* self, IAvnControl* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_padding)(IAvnDecorator* self, AvnThickness* value); /* slot 40 */
    AvnHResult (AVN_CALL *set_padding)(IAvnDecorator* self, AvnThickness value); /* slot 41 */
};
struct IAvnDecorator { const IAvnDecoratorVtbl* vtbl; };
#define I_AVN_DECORATOR_VTABLE_SLOTS 42

static const AvnGuid I_AVN_DOCK_PANEL_IID = {
    0xF698353A,
    0x6DB0,
    0x5552,
    { 0x9B, 0x3C, 0xCE, 0x09, 0x00, 0x3E, 0x6F, 0x27 }
};
#define I_AVN_DOCK_PANEL_ABI_VERSION 4
struct IAvnDockPanelVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnDockPanel* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnDockPanel* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnDockPanel* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnDockPanel* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnDockPanel* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnDockPanel* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnDockPanel* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnDockPanel* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnDockPanel* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnDockPanel* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnDockPanel* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnDockPanel* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnDockPanel* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnDockPanel* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnDockPanel* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnDockPanel* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnDockPanel* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnDockPanel* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnDockPanel* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnDockPanel* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnDockPanel* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnDockPanel* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnDockPanel* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnDockPanel* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnDockPanel* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnDockPanel* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnDockPanel* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnDockPanel* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnDockPanel* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnDockPanel* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnDockPanel* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnDockPanel* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnDockPanel* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnDockPanel* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnDockPanel* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnDockPanel* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnDockPanel* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnDockPanel* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_children)(IAvnDockPanel* self, IAvnControlList** value); /* slot 38 */
    AvnHResult (AVN_CALL *get_background)(IAvnDockPanel* self, IAvnBrush** value); /* slot 39 */
    AvnHResult (AVN_CALL *set_background)(IAvnDockPanel* self, IAvnBrush* value); /* slot 40 */
    AvnHResult (AVN_CALL *get_last_child_fill)(IAvnDockPanel* self, int32_t* value); /* slot 41 */
    AvnHResult (AVN_CALL *set_last_child_fill)(IAvnDockPanel* self, int32_t value); /* slot 42 */
    AvnHResult (AVN_CALL *get_horizontal_spacing)(IAvnDockPanel* self, double* value); /* slot 43 */
    AvnHResult (AVN_CALL *set_horizontal_spacing)(IAvnDockPanel* self, double value); /* slot 44 */
    AvnHResult (AVN_CALL *get_vertical_spacing)(IAvnDockPanel* self, double* value); /* slot 45 */
    AvnHResult (AVN_CALL *set_vertical_spacing)(IAvnDockPanel* self, double value); /* slot 46 */
};
struct IAvnDockPanel { const IAvnDockPanelVtbl* vtbl; };
#define I_AVN_DOCK_PANEL_VTABLE_SLOTS 47

static const AvnGuid I_AVN_EXPANDER_IID = {
    0x332ED548,
    0x2796,
    0x596D,
    { 0xA9, 0xD0, 0x47, 0xC9, 0x07, 0x28, 0x36, 0x3B }
};
#define I_AVN_EXPANDER_ABI_VERSION 5
struct IAvnExpanderVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnExpander* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnExpander* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnExpander* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnExpander* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnExpander* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnExpander* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnExpander* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnExpander* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnExpander* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnExpander* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnExpander* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnExpander* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnExpander* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnExpander* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnExpander* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnExpander* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnExpander* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnExpander* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnExpander* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnExpander* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnExpander* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnExpander* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnExpander* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnExpander* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnExpander* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnExpander* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnExpander* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnExpander* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnExpander* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnExpander* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnExpander* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnExpander* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnExpander* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnExpander* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnExpander* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnExpander* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnExpander* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnExpander* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnExpander* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnExpander* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnExpander* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnExpander* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnExpander* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnExpander* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnExpander* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnExpander* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnExpander* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnExpander* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnExpander* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnExpander* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_content)(IAvnExpander* self, IAvnControl** value); /* slot 50 */
    AvnHResult (AVN_CALL *set_content)(IAvnExpander* self, IAvnControl* value); /* slot 51 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnExpander* self, int32_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnExpander* self, int32_t value); /* slot 53 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnExpander* self, int32_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnExpander* self, int32_t value); /* slot 55 */
    AvnHResult (AVN_CALL *get_header)(IAvnExpander* self, IAvnControl** value); /* slot 56 */
    AvnHResult (AVN_CALL *set_header)(IAvnExpander* self, IAvnControl* value); /* slot 57 */
    AvnHResult (AVN_CALL *get_expand_direction)(IAvnExpander* self, int32_t* value); /* slot 58 */
    AvnHResult (AVN_CALL *set_expand_direction)(IAvnExpander* self, int32_t value); /* slot 59 */
    AvnHResult (AVN_CALL *get_is_expanded)(IAvnExpander* self, int32_t* value); /* slot 60 */
    AvnHResult (AVN_CALL *set_is_expanded)(IAvnExpander* self, int32_t value); /* slot 61 */
    AvnHResult (AVN_CALL *advise_collapsed)(IAvnExpander* self, IAvnExpanderCollapsedHandler* handler, int64_t* subscription_id); /* slot 62 */
    AvnHResult (AVN_CALL *unadvise_collapsed)(IAvnExpander* self, int64_t subscription_id); /* slot 63 */
    AvnHResult (AVN_CALL *advise_expanded)(IAvnExpander* self, IAvnExpanderExpandedHandler* handler, int64_t* subscription_id); /* slot 64 */
    AvnHResult (AVN_CALL *unadvise_expanded)(IAvnExpander* self, int64_t subscription_id); /* slot 65 */
};
struct IAvnExpander { const IAvnExpanderVtbl* vtbl; };
#define I_AVN_EXPANDER_VTABLE_SLOTS 66

static const AvnGuid I_AVN_GRID_IID = {
    0x240199CD,
    0xF2BD,
    0x55CD,
    { 0xBE, 0x4D, 0x8D, 0xA8, 0x3F, 0x22, 0x8D, 0x71 }
};
#define I_AVN_GRID_ABI_VERSION 4
struct IAvnGridVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnGrid* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnGrid* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnGrid* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnGrid* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnGrid* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnGrid* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnGrid* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnGrid* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnGrid* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnGrid* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnGrid* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnGrid* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnGrid* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnGrid* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnGrid* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnGrid* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnGrid* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnGrid* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnGrid* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnGrid* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnGrid* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnGrid* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnGrid* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnGrid* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnGrid* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnGrid* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnGrid* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnGrid* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnGrid* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnGrid* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnGrid* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnGrid* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnGrid* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnGrid* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnGrid* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnGrid* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnGrid* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnGrid* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_children)(IAvnGrid* self, IAvnControlList** value); /* slot 38 */
    AvnHResult (AVN_CALL *get_background)(IAvnGrid* self, IAvnBrush** value); /* slot 39 */
    AvnHResult (AVN_CALL *set_background)(IAvnGrid* self, IAvnBrush* value); /* slot 40 */
    AvnHResult (AVN_CALL *get_show_grid_lines)(IAvnGrid* self, int32_t* value); /* slot 41 */
    AvnHResult (AVN_CALL *set_show_grid_lines)(IAvnGrid* self, int32_t value); /* slot 42 */
    AvnHResult (AVN_CALL *get_row_spacing)(IAvnGrid* self, double* value); /* slot 43 */
    AvnHResult (AVN_CALL *set_row_spacing)(IAvnGrid* self, double value); /* slot 44 */
    AvnHResult (AVN_CALL *get_column_spacing)(IAvnGrid* self, double* value); /* slot 45 */
    AvnHResult (AVN_CALL *set_column_spacing)(IAvnGrid* self, double value); /* slot 46 */
};
struct IAvnGrid { const IAvnGridVtbl* vtbl; };
#define I_AVN_GRID_VTABLE_SLOTS 47

static const AvnGuid I_AVN_HEADERED_CONTENT_CONTROL_IID = {
    0xEF77B5CB,
    0xD25B,
    0x5F21,
    { 0x99, 0xAB, 0xC3, 0x45, 0xE7, 0xCE, 0x2C, 0x30 }
};
#define I_AVN_HEADERED_CONTENT_CONTROL_ABI_VERSION 5
struct IAvnHeaderedContentControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnHeaderedContentControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnHeaderedContentControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnHeaderedContentControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnHeaderedContentControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnHeaderedContentControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnHeaderedContentControl* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnHeaderedContentControl* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnHeaderedContentControl* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnHeaderedContentControl* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnHeaderedContentControl* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnHeaderedContentControl* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnHeaderedContentControl* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnHeaderedContentControl* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnHeaderedContentControl* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnHeaderedContentControl* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnHeaderedContentControl* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnHeaderedContentControl* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnHeaderedContentControl* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnHeaderedContentControl* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnHeaderedContentControl* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnHeaderedContentControl* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnHeaderedContentControl* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnHeaderedContentControl* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnHeaderedContentControl* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnHeaderedContentControl* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnHeaderedContentControl* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnHeaderedContentControl* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnHeaderedContentControl* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnHeaderedContentControl* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnHeaderedContentControl* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnHeaderedContentControl* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnHeaderedContentControl* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnHeaderedContentControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnHeaderedContentControl* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnHeaderedContentControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnHeaderedContentControl* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnHeaderedContentControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnHeaderedContentControl* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnHeaderedContentControl* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnHeaderedContentControl* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnHeaderedContentControl* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnHeaderedContentControl* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnHeaderedContentControl* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnHeaderedContentControl* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnHeaderedContentControl* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnHeaderedContentControl* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnHeaderedContentControl* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnHeaderedContentControl* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnHeaderedContentControl* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnHeaderedContentControl* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_content)(IAvnHeaderedContentControl* self, IAvnControl** value); /* slot 50 */
    AvnHResult (AVN_CALL *set_content)(IAvnHeaderedContentControl* self, IAvnControl* value); /* slot 51 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnHeaderedContentControl* self, int32_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnHeaderedContentControl* self, int32_t value); /* slot 53 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnHeaderedContentControl* self, int32_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnHeaderedContentControl* self, int32_t value); /* slot 55 */
    AvnHResult (AVN_CALL *get_header)(IAvnHeaderedContentControl* self, IAvnControl** value); /* slot 56 */
    AvnHResult (AVN_CALL *set_header)(IAvnHeaderedContentControl* self, IAvnControl* value); /* slot 57 */
};
struct IAvnHeaderedContentControl { const IAvnHeaderedContentControlVtbl* vtbl; };
#define I_AVN_HEADERED_CONTENT_CONTROL_VTABLE_SLOTS 58

static const AvnGuid I_AVN_ITEMS_CONTROL_IID = {
    0x95D1FA77,
    0x96F7,
    0x5F24,
    { 0xBE, 0x8A, 0x36, 0x2E, 0x53, 0x0C, 0xCB, 0xD9 }
};
#define I_AVN_ITEMS_CONTROL_ABI_VERSION 4
struct IAvnItemsControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnItemsControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnItemsControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnItemsControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnItemsControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnItemsControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnItemsControl* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnItemsControl* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnItemsControl* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnItemsControl* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnItemsControl* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnItemsControl* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnItemsControl* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnItemsControl* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnItemsControl* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnItemsControl* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnItemsControl* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnItemsControl* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnItemsControl* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnItemsControl* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnItemsControl* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnItemsControl* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnItemsControl* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnItemsControl* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnItemsControl* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnItemsControl* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnItemsControl* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnItemsControl* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnItemsControl* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnItemsControl* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnItemsControl* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnItemsControl* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnItemsControl* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnItemsControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnItemsControl* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnItemsControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnItemsControl* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnItemsControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnItemsControl* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnItemsControl* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnItemsControl* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnItemsControl* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnItemsControl* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnItemsControl* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnItemsControl* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnItemsControl* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnItemsControl* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnItemsControl* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnItemsControl* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnItemsControl* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnItemsControl* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_items)(IAvnItemsControl* self, IAvnItemList** value); /* slot 50 */
};
struct IAvnItemsControl { const IAvnItemsControlVtbl* vtbl; };
#define I_AVN_ITEMS_CONTROL_VTABLE_SLOTS 51

static const AvnGuid I_AVN_LIST_BOX_IID = {
    0xEAD15413,
    0x53EB,
    0x5159,
    { 0xBE, 0x99, 0x7B, 0xED, 0x7B, 0xF2, 0x56, 0x51 }
};
#define I_AVN_LIST_BOX_ABI_VERSION 5
struct IAvnListBoxVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnListBox* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnListBox* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnListBox* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnListBox* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnListBox* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnListBox* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnListBox* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnListBox* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnListBox* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnListBox* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnListBox* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnListBox* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnListBox* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnListBox* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnListBox* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnListBox* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnListBox* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnListBox* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnListBox* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnListBox* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnListBox* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnListBox* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnListBox* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnListBox* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnListBox* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnListBox* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnListBox* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnListBox* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnListBox* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnListBox* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnListBox* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnListBox* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnListBox* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnListBox* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnListBox* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnListBox* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnListBox* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnListBox* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnListBox* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnListBox* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnListBox* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnListBox* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnListBox* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnListBox* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnListBox* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnListBox* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnListBox* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnListBox* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnListBox* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnListBox* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_items)(IAvnListBox* self, IAvnItemList** value); /* slot 50 */
    AvnHResult (AVN_CALL *get_selected_index)(IAvnListBox* self, int32_t* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_selected_index)(IAvnListBox* self, int32_t value); /* slot 52 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnListBox* self, IAvnSelectingItemsControlSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 53 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnListBox* self, int64_t subscription_id); /* slot 54 */
    AvnHResult (AVN_CALL *get_selection_mode)(IAvnListBox* self, int32_t* value); /* slot 55 */
    AvnHResult (AVN_CALL *set_selection_mode)(IAvnListBox* self, int32_t value); /* slot 56 */
    AvnHResult (AVN_CALL *select_all)(IAvnListBox* self); /* slot 57 */
    AvnHResult (AVN_CALL *unselect_all)(IAvnListBox* self); /* slot 58 */
};
struct IAvnListBox { const IAvnListBoxVtbl* vtbl; };
#define I_AVN_LIST_BOX_VTABLE_SLOTS 59

static const AvnGuid I_AVN_LIST_BOX_ITEM_IID = {
    0xF10EB1EB,
    0x9F6C,
    0x580E,
    { 0x92, 0x0B, 0x8E, 0xF9, 0x36, 0x4E, 0x48, 0x7D }
};
#define I_AVN_LIST_BOX_ITEM_ABI_VERSION 5
struct IAvnListBoxItemVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnListBoxItem* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnListBoxItem* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnListBoxItem* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnListBoxItem* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnListBoxItem* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnListBoxItem* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnListBoxItem* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnListBoxItem* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnListBoxItem* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnListBoxItem* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnListBoxItem* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnListBoxItem* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnListBoxItem* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnListBoxItem* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnListBoxItem* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnListBoxItem* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnListBoxItem* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnListBoxItem* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnListBoxItem* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnListBoxItem* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnListBoxItem* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnListBoxItem* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnListBoxItem* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnListBoxItem* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnListBoxItem* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnListBoxItem* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnListBoxItem* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnListBoxItem* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnListBoxItem* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnListBoxItem* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnListBoxItem* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnListBoxItem* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnListBoxItem* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnListBoxItem* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnListBoxItem* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnListBoxItem* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnListBoxItem* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnListBoxItem* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnListBoxItem* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnListBoxItem* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnListBoxItem* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnListBoxItem* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnListBoxItem* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnListBoxItem* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnListBoxItem* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnListBoxItem* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnListBoxItem* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnListBoxItem* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnListBoxItem* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnListBoxItem* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_content)(IAvnListBoxItem* self, IAvnControl** value); /* slot 50 */
    AvnHResult (AVN_CALL *set_content)(IAvnListBoxItem* self, IAvnControl* value); /* slot 51 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnListBoxItem* self, int32_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnListBoxItem* self, int32_t value); /* slot 53 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnListBoxItem* self, int32_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnListBoxItem* self, int32_t value); /* slot 55 */
    AvnHResult (AVN_CALL *get_is_selected)(IAvnListBoxItem* self, int32_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *set_is_selected)(IAvnListBoxItem* self, int32_t value); /* slot 57 */
};
struct IAvnListBoxItem { const IAvnListBoxItemVtbl* vtbl; };
#define I_AVN_LIST_BOX_ITEM_VTABLE_SLOTS 58

static const AvnGuid I_AVN_PANEL_IID = {
    0xBD97617A,
    0xEEDC,
    0x5695,
    { 0x88, 0xC1, 0xE3, 0x0E, 0x66, 0x73, 0xB2, 0x86 }
};
#define I_AVN_PANEL_ABI_VERSION 4
struct IAvnPanelVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnPanel* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnPanel* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnPanel* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnPanel* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnPanel* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnPanel* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnPanel* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnPanel* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnPanel* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnPanel* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnPanel* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnPanel* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnPanel* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnPanel* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnPanel* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnPanel* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnPanel* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnPanel* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnPanel* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnPanel* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnPanel* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnPanel* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnPanel* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnPanel* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnPanel* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnPanel* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnPanel* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnPanel* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnPanel* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnPanel* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnPanel* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnPanel* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnPanel* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnPanel* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnPanel* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnPanel* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnPanel* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnPanel* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_children)(IAvnPanel* self, IAvnControlList** value); /* slot 38 */
    AvnHResult (AVN_CALL *get_background)(IAvnPanel* self, IAvnBrush** value); /* slot 39 */
    AvnHResult (AVN_CALL *set_background)(IAvnPanel* self, IAvnBrush* value); /* slot 40 */
};
struct IAvnPanel { const IAvnPanelVtbl* vtbl; };
#define I_AVN_PANEL_VTABLE_SLOTS 41

static const AvnGuid I_AVN_PROGRESS_BAR_IID = {
    0xAAE19E94,
    0x367F,
    0x5C7C,
    { 0x9C, 0x93, 0x3E, 0xB9, 0xCF, 0x52, 0x91, 0xFA }
};
#define I_AVN_PROGRESS_BAR_ABI_VERSION 4
struct IAvnProgressBarVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnProgressBar* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnProgressBar* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnProgressBar* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnProgressBar* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnProgressBar* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnProgressBar* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnProgressBar* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnProgressBar* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnProgressBar* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnProgressBar* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnProgressBar* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnProgressBar* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnProgressBar* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnProgressBar* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnProgressBar* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnProgressBar* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnProgressBar* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnProgressBar* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnProgressBar* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnProgressBar* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnProgressBar* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnProgressBar* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnProgressBar* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnProgressBar* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnProgressBar* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnProgressBar* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnProgressBar* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnProgressBar* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnProgressBar* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnProgressBar* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnProgressBar* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnProgressBar* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnProgressBar* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnProgressBar* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnProgressBar* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnProgressBar* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnProgressBar* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnProgressBar* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnProgressBar* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnProgressBar* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnProgressBar* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnProgressBar* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnProgressBar* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnProgressBar* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnProgressBar* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnProgressBar* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnProgressBar* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnProgressBar* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnProgressBar* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnProgressBar* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_minimum)(IAvnProgressBar* self, double* value); /* slot 50 */
    AvnHResult (AVN_CALL *set_minimum)(IAvnProgressBar* self, double value); /* slot 51 */
    AvnHResult (AVN_CALL *get_maximum)(IAvnProgressBar* self, double* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_maximum)(IAvnProgressBar* self, double value); /* slot 53 */
    AvnHResult (AVN_CALL *get_value)(IAvnProgressBar* self, double* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_value)(IAvnProgressBar* self, double value); /* slot 55 */
    AvnHResult (AVN_CALL *get_small_change)(IAvnProgressBar* self, double* value); /* slot 56 */
    AvnHResult (AVN_CALL *set_small_change)(IAvnProgressBar* self, double value); /* slot 57 */
    AvnHResult (AVN_CALL *get_large_change)(IAvnProgressBar* self, double* value); /* slot 58 */
    AvnHResult (AVN_CALL *set_large_change)(IAvnProgressBar* self, double value); /* slot 59 */
    AvnHResult (AVN_CALL *advise_value_changed)(IAvnProgressBar* self, IAvnRangeBaseValueChangedHandler* handler, int64_t* subscription_id); /* slot 60 */
    AvnHResult (AVN_CALL *unadvise_value_changed)(IAvnProgressBar* self, int64_t subscription_id); /* slot 61 */
    AvnHResult (AVN_CALL *get_is_indeterminate)(IAvnProgressBar* self, int32_t* value); /* slot 62 */
    AvnHResult (AVN_CALL *set_is_indeterminate)(IAvnProgressBar* self, int32_t value); /* slot 63 */
    AvnHResult (AVN_CALL *get_show_progress_text)(IAvnProgressBar* self, int32_t* value); /* slot 64 */
    AvnHResult (AVN_CALL *set_show_progress_text)(IAvnProgressBar* self, int32_t value); /* slot 65 */
    AvnHResult (AVN_CALL *get_progress_text_format)(IAvnProgressBar* self, uint16_t** value); /* slot 66 */
    AvnHResult (AVN_CALL *set_progress_text_format)(IAvnProgressBar* self, const uint16_t* value); /* slot 67 */
    AvnHResult (AVN_CALL *get_orientation)(IAvnProgressBar* self, int32_t* value); /* slot 68 */
    AvnHResult (AVN_CALL *set_orientation)(IAvnProgressBar* self, int32_t value); /* slot 69 */
};
struct IAvnProgressBar { const IAvnProgressBarVtbl* vtbl; };
#define I_AVN_PROGRESS_BAR_VTABLE_SLOTS 70

static const AvnGuid I_AVN_RADIO_BUTTON_IID = {
    0x05867789,
    0x0F58,
    0x5C1E,
    { 0xA3, 0xE5, 0x54, 0x84, 0x1D, 0x87, 0x24, 0x2E }
};
#define I_AVN_RADIO_BUTTON_ABI_VERSION 5
struct IAvnRadioButtonVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnRadioButton* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnRadioButton* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnRadioButton* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnRadioButton* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnRadioButton* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnRadioButton* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnRadioButton* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnRadioButton* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnRadioButton* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnRadioButton* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnRadioButton* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnRadioButton* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnRadioButton* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnRadioButton* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnRadioButton* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnRadioButton* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnRadioButton* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnRadioButton* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnRadioButton* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnRadioButton* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnRadioButton* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnRadioButton* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnRadioButton* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnRadioButton* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnRadioButton* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnRadioButton* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnRadioButton* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnRadioButton* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnRadioButton* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnRadioButton* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnRadioButton* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnRadioButton* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnRadioButton* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnRadioButton* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnRadioButton* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnRadioButton* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnRadioButton* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnRadioButton* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnRadioButton* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnRadioButton* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnRadioButton* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnRadioButton* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnRadioButton* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnRadioButton* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnRadioButton* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnRadioButton* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnRadioButton* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnRadioButton* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnRadioButton* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnRadioButton* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_content)(IAvnRadioButton* self, IAvnControl** value); /* slot 50 */
    AvnHResult (AVN_CALL *set_content)(IAvnRadioButton* self, IAvnControl* value); /* slot 51 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnRadioButton* self, int32_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnRadioButton* self, int32_t value); /* slot 53 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnRadioButton* self, int32_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnRadioButton* self, int32_t value); /* slot 55 */
    AvnHResult (AVN_CALL *get_click_mode)(IAvnRadioButton* self, int32_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *set_click_mode)(IAvnRadioButton* self, int32_t value); /* slot 57 */
    AvnHResult (AVN_CALL *get_is_default)(IAvnRadioButton* self, int32_t* value); /* slot 58 */
    AvnHResult (AVN_CALL *set_is_default)(IAvnRadioButton* self, int32_t value); /* slot 59 */
    AvnHResult (AVN_CALL *get_is_cancel)(IAvnRadioButton* self, int32_t* value); /* slot 60 */
    AvnHResult (AVN_CALL *set_is_cancel)(IAvnRadioButton* self, int32_t value); /* slot 61 */
    AvnHResult (AVN_CALL *get_is_pressed)(IAvnRadioButton* self, int32_t* value); /* slot 62 */
    AvnHResult (AVN_CALL *advise_click)(IAvnRadioButton* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 63 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnRadioButton* self, int64_t subscription_id); /* slot 64 */
    AvnHResult (AVN_CALL *get_is_checked)(IAvnRadioButton* self, int32_t* value); /* slot 65 */
    AvnHResult (AVN_CALL *set_is_checked)(IAvnRadioButton* self, int32_t value); /* slot 66 */
    AvnHResult (AVN_CALL *get_is_three_state)(IAvnRadioButton* self, int32_t* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_is_three_state)(IAvnRadioButton* self, int32_t value); /* slot 68 */
    AvnHResult (AVN_CALL *advise_is_checked_changed)(IAvnRadioButton* self, IAvnToggleButtonIsCheckedChangedHandler* handler, int64_t* subscription_id); /* slot 69 */
    AvnHResult (AVN_CALL *unadvise_is_checked_changed)(IAvnRadioButton* self, int64_t subscription_id); /* slot 70 */
    AvnHResult (AVN_CALL *get_group_name)(IAvnRadioButton* self, uint16_t** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_group_name)(IAvnRadioButton* self, const uint16_t* value); /* slot 72 */
};
struct IAvnRadioButton { const IAvnRadioButtonVtbl* vtbl; };
#define I_AVN_RADIO_BUTTON_VTABLE_SLOTS 73

static const AvnGuid I_AVN_RANGE_BASE_IID = {
    0x1738721D,
    0x47BE,
    0x52DA,
    { 0x8B, 0x85, 0x6E, 0x50, 0xA5, 0x61, 0x2F, 0xB9 }
};
#define I_AVN_RANGE_BASE_ABI_VERSION 4
struct IAvnRangeBaseVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnRangeBase* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnRangeBase* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnRangeBase* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnRangeBase* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnRangeBase* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnRangeBase* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnRangeBase* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnRangeBase* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnRangeBase* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnRangeBase* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnRangeBase* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnRangeBase* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnRangeBase* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnRangeBase* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnRangeBase* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnRangeBase* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnRangeBase* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnRangeBase* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnRangeBase* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnRangeBase* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnRangeBase* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnRangeBase* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnRangeBase* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnRangeBase* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnRangeBase* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnRangeBase* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnRangeBase* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnRangeBase* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnRangeBase* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnRangeBase* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnRangeBase* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnRangeBase* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnRangeBase* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnRangeBase* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnRangeBase* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnRangeBase* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnRangeBase* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnRangeBase* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnRangeBase* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnRangeBase* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnRangeBase* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnRangeBase* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnRangeBase* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnRangeBase* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnRangeBase* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnRangeBase* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnRangeBase* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnRangeBase* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnRangeBase* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnRangeBase* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_minimum)(IAvnRangeBase* self, double* value); /* slot 50 */
    AvnHResult (AVN_CALL *set_minimum)(IAvnRangeBase* self, double value); /* slot 51 */
    AvnHResult (AVN_CALL *get_maximum)(IAvnRangeBase* self, double* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_maximum)(IAvnRangeBase* self, double value); /* slot 53 */
    AvnHResult (AVN_CALL *get_value)(IAvnRangeBase* self, double* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_value)(IAvnRangeBase* self, double value); /* slot 55 */
    AvnHResult (AVN_CALL *get_small_change)(IAvnRangeBase* self, double* value); /* slot 56 */
    AvnHResult (AVN_CALL *set_small_change)(IAvnRangeBase* self, double value); /* slot 57 */
    AvnHResult (AVN_CALL *get_large_change)(IAvnRangeBase* self, double* value); /* slot 58 */
    AvnHResult (AVN_CALL *set_large_change)(IAvnRangeBase* self, double value); /* slot 59 */
    AvnHResult (AVN_CALL *advise_value_changed)(IAvnRangeBase* self, IAvnRangeBaseValueChangedHandler* handler, int64_t* subscription_id); /* slot 60 */
    AvnHResult (AVN_CALL *unadvise_value_changed)(IAvnRangeBase* self, int64_t subscription_id); /* slot 61 */
};
struct IAvnRangeBase { const IAvnRangeBaseVtbl* vtbl; };
#define I_AVN_RANGE_BASE_VTABLE_SLOTS 62

static const AvnGuid I_AVN_SCROLL_VIEWER_IID = {
    0xAFC6EC9E,
    0xD300,
    0x5DE5,
    { 0xAA, 0x51, 0xFA, 0xCB, 0x2C, 0x8F, 0x29, 0x9C }
};
#define I_AVN_SCROLL_VIEWER_ABI_VERSION 5
struct IAvnScrollViewerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnScrollViewer* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnScrollViewer* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnScrollViewer* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnScrollViewer* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnScrollViewer* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnScrollViewer* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnScrollViewer* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnScrollViewer* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnScrollViewer* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnScrollViewer* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnScrollViewer* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnScrollViewer* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnScrollViewer* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnScrollViewer* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnScrollViewer* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnScrollViewer* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnScrollViewer* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnScrollViewer* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnScrollViewer* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnScrollViewer* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnScrollViewer* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnScrollViewer* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnScrollViewer* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnScrollViewer* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnScrollViewer* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnScrollViewer* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnScrollViewer* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnScrollViewer* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnScrollViewer* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnScrollViewer* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnScrollViewer* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnScrollViewer* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnScrollViewer* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnScrollViewer* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnScrollViewer* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnScrollViewer* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnScrollViewer* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnScrollViewer* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnScrollViewer* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnScrollViewer* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnScrollViewer* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnScrollViewer* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnScrollViewer* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnScrollViewer* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnScrollViewer* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnScrollViewer* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnScrollViewer* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnScrollViewer* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnScrollViewer* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnScrollViewer* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_content)(IAvnScrollViewer* self, IAvnControl** value); /* slot 50 */
    AvnHResult (AVN_CALL *set_content)(IAvnScrollViewer* self, IAvnControl* value); /* slot 51 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnScrollViewer* self, int32_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnScrollViewer* self, int32_t value); /* slot 53 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnScrollViewer* self, int32_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnScrollViewer* self, int32_t value); /* slot 55 */
    AvnHResult (AVN_CALL *get_bring_into_view_on_focus_change)(IAvnScrollViewer* self, int32_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *set_bring_into_view_on_focus_change)(IAvnScrollViewer* self, int32_t value); /* slot 57 */
    AvnHResult (AVN_CALL *get_horizontal_scroll_bar_visibility)(IAvnScrollViewer* self, int32_t* value); /* slot 58 */
    AvnHResult (AVN_CALL *set_horizontal_scroll_bar_visibility)(IAvnScrollViewer* self, int32_t value); /* slot 59 */
    AvnHResult (AVN_CALL *get_vertical_scroll_bar_visibility)(IAvnScrollViewer* self, int32_t* value); /* slot 60 */
    AvnHResult (AVN_CALL *set_vertical_scroll_bar_visibility)(IAvnScrollViewer* self, int32_t value); /* slot 61 */
    AvnHResult (AVN_CALL *get_is_expanded)(IAvnScrollViewer* self, int32_t* value); /* slot 62 */
    AvnHResult (AVN_CALL *get_allow_auto_hide)(IAvnScrollViewer* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_allow_auto_hide)(IAvnScrollViewer* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_is_scroll_chaining_enabled)(IAvnScrollViewer* self, int32_t* value); /* slot 65 */
    AvnHResult (AVN_CALL *set_is_scroll_chaining_enabled)(IAvnScrollViewer* self, int32_t value); /* slot 66 */
    AvnHResult (AVN_CALL *get_is_scroll_inertia_enabled)(IAvnScrollViewer* self, int32_t* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_is_scroll_inertia_enabled)(IAvnScrollViewer* self, int32_t value); /* slot 68 */
    AvnHResult (AVN_CALL *get_is_deferred_scrolling_enabled)(IAvnScrollViewer* self, int32_t* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_is_deferred_scrolling_enabled)(IAvnScrollViewer* self, int32_t value); /* slot 70 */
    AvnHResult (AVN_CALL *line_up)(IAvnScrollViewer* self); /* slot 71 */
    AvnHResult (AVN_CALL *line_down)(IAvnScrollViewer* self); /* slot 72 */
    AvnHResult (AVN_CALL *line_left)(IAvnScrollViewer* self); /* slot 73 */
    AvnHResult (AVN_CALL *line_right)(IAvnScrollViewer* self); /* slot 74 */
    AvnHResult (AVN_CALL *page_up)(IAvnScrollViewer* self); /* slot 75 */
    AvnHResult (AVN_CALL *page_down)(IAvnScrollViewer* self); /* slot 76 */
    AvnHResult (AVN_CALL *page_left)(IAvnScrollViewer* self); /* slot 77 */
    AvnHResult (AVN_CALL *page_right)(IAvnScrollViewer* self); /* slot 78 */
    AvnHResult (AVN_CALL *scroll_to_home)(IAvnScrollViewer* self); /* slot 79 */
    AvnHResult (AVN_CALL *scroll_to_end)(IAvnScrollViewer* self); /* slot 80 */
    AvnHResult (AVN_CALL *advise_scroll_changed)(IAvnScrollViewer* self, IAvnScrollViewerScrollChangedHandler* handler, int64_t* subscription_id); /* slot 81 */
    AvnHResult (AVN_CALL *unadvise_scroll_changed)(IAvnScrollViewer* self, int64_t subscription_id); /* slot 82 */
};
struct IAvnScrollViewer { const IAvnScrollViewerVtbl* vtbl; };
#define I_AVN_SCROLL_VIEWER_VTABLE_SLOTS 83

static const AvnGuid I_AVN_SELECTING_ITEMS_CONTROL_IID = {
    0x4D40F605,
    0x0330,
    0x573F,
    { 0x9C, 0x4E, 0x06, 0xB1, 0xCC, 0x3C, 0xF5, 0xA3 }
};
#define I_AVN_SELECTING_ITEMS_CONTROL_ABI_VERSION 4
struct IAvnSelectingItemsControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnSelectingItemsControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnSelectingItemsControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnSelectingItemsControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnSelectingItemsControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnSelectingItemsControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnSelectingItemsControl* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnSelectingItemsControl* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnSelectingItemsControl* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnSelectingItemsControl* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnSelectingItemsControl* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnSelectingItemsControl* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnSelectingItemsControl* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnSelectingItemsControl* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnSelectingItemsControl* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnSelectingItemsControl* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnSelectingItemsControl* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnSelectingItemsControl* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnSelectingItemsControl* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnSelectingItemsControl* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnSelectingItemsControl* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnSelectingItemsControl* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnSelectingItemsControl* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnSelectingItemsControl* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnSelectingItemsControl* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnSelectingItemsControl* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnSelectingItemsControl* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnSelectingItemsControl* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnSelectingItemsControl* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnSelectingItemsControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnSelectingItemsControl* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnSelectingItemsControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnSelectingItemsControl* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnSelectingItemsControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnSelectingItemsControl* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnSelectingItemsControl* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnSelectingItemsControl* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnSelectingItemsControl* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnSelectingItemsControl* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnSelectingItemsControl* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnSelectingItemsControl* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnSelectingItemsControl* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnSelectingItemsControl* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnSelectingItemsControl* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnSelectingItemsControl* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnSelectingItemsControl* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnSelectingItemsControl* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_items)(IAvnSelectingItemsControl* self, IAvnItemList** value); /* slot 50 */
    AvnHResult (AVN_CALL *get_selected_index)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_selected_index)(IAvnSelectingItemsControl* self, int32_t value); /* slot 52 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnSelectingItemsControl* self, IAvnSelectingItemsControlSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 53 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnSelectingItemsControl* self, int64_t subscription_id); /* slot 54 */
};
struct IAvnSelectingItemsControl { const IAvnSelectingItemsControlVtbl* vtbl; };
#define I_AVN_SELECTING_ITEMS_CONTROL_VTABLE_SLOTS 55

static const AvnGuid I_AVN_SLIDER_IID = {
    0xBEB1A630,
    0x805B,
    0x5A11,
    { 0x8F, 0x1C, 0x18, 0x17, 0xBD, 0x9F, 0xE5, 0x15 }
};
#define I_AVN_SLIDER_ABI_VERSION 4
struct IAvnSliderVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnSlider* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnSlider* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnSlider* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnSlider* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnSlider* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnSlider* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnSlider* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnSlider* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnSlider* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnSlider* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnSlider* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnSlider* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnSlider* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnSlider* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnSlider* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnSlider* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnSlider* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnSlider* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnSlider* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnSlider* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnSlider* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnSlider* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnSlider* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnSlider* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnSlider* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnSlider* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnSlider* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnSlider* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnSlider* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnSlider* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnSlider* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnSlider* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnSlider* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnSlider* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnSlider* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnSlider* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnSlider* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnSlider* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnSlider* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnSlider* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnSlider* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnSlider* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnSlider* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnSlider* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnSlider* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnSlider* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnSlider* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnSlider* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnSlider* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnSlider* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_minimum)(IAvnSlider* self, double* value); /* slot 50 */
    AvnHResult (AVN_CALL *set_minimum)(IAvnSlider* self, double value); /* slot 51 */
    AvnHResult (AVN_CALL *get_maximum)(IAvnSlider* self, double* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_maximum)(IAvnSlider* self, double value); /* slot 53 */
    AvnHResult (AVN_CALL *get_value)(IAvnSlider* self, double* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_value)(IAvnSlider* self, double value); /* slot 55 */
    AvnHResult (AVN_CALL *get_small_change)(IAvnSlider* self, double* value); /* slot 56 */
    AvnHResult (AVN_CALL *set_small_change)(IAvnSlider* self, double value); /* slot 57 */
    AvnHResult (AVN_CALL *get_large_change)(IAvnSlider* self, double* value); /* slot 58 */
    AvnHResult (AVN_CALL *set_large_change)(IAvnSlider* self, double value); /* slot 59 */
    AvnHResult (AVN_CALL *advise_value_changed)(IAvnSlider* self, IAvnRangeBaseValueChangedHandler* handler, int64_t* subscription_id); /* slot 60 */
    AvnHResult (AVN_CALL *unadvise_value_changed)(IAvnSlider* self, int64_t subscription_id); /* slot 61 */
    AvnHResult (AVN_CALL *get_orientation)(IAvnSlider* self, int32_t* value); /* slot 62 */
    AvnHResult (AVN_CALL *set_orientation)(IAvnSlider* self, int32_t value); /* slot 63 */
    AvnHResult (AVN_CALL *get_is_direction_reversed)(IAvnSlider* self, int32_t* value); /* slot 64 */
    AvnHResult (AVN_CALL *set_is_direction_reversed)(IAvnSlider* self, int32_t value); /* slot 65 */
    AvnHResult (AVN_CALL *get_is_snap_to_tick_enabled)(IAvnSlider* self, int32_t* value); /* slot 66 */
    AvnHResult (AVN_CALL *set_is_snap_to_tick_enabled)(IAvnSlider* self, int32_t value); /* slot 67 */
    AvnHResult (AVN_CALL *get_tick_frequency)(IAvnSlider* self, double* value); /* slot 68 */
    AvnHResult (AVN_CALL *set_tick_frequency)(IAvnSlider* self, double value); /* slot 69 */
    AvnHResult (AVN_CALL *get_tick_placement)(IAvnSlider* self, int32_t* value); /* slot 70 */
    AvnHResult (AVN_CALL *set_tick_placement)(IAvnSlider* self, int32_t value); /* slot 71 */
};
struct IAvnSlider { const IAvnSliderVtbl* vtbl; };
#define I_AVN_SLIDER_VTABLE_SLOTS 72

static const AvnGuid I_AVN_STACK_PANEL_IID = {
    0x0C9EDC6F,
    0x33B2,
    0x56A8,
    { 0x94, 0x81, 0x85, 0xEC, 0x28, 0xFF, 0x7D, 0x5A }
};
#define I_AVN_STACK_PANEL_ABI_VERSION 4
struct IAvnStackPanelVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnStackPanel* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnStackPanel* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnStackPanel* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnStackPanel* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnStackPanel* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnStackPanel* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnStackPanel* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnStackPanel* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnStackPanel* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnStackPanel* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnStackPanel* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnStackPanel* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnStackPanel* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnStackPanel* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnStackPanel* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnStackPanel* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnStackPanel* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnStackPanel* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnStackPanel* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnStackPanel* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnStackPanel* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnStackPanel* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnStackPanel* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnStackPanel* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnStackPanel* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnStackPanel* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnStackPanel* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnStackPanel* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnStackPanel* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnStackPanel* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnStackPanel* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnStackPanel* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnStackPanel* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnStackPanel* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnStackPanel* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnStackPanel* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnStackPanel* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnStackPanel* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_children)(IAvnStackPanel* self, IAvnControlList** value); /* slot 38 */
    AvnHResult (AVN_CALL *get_background)(IAvnStackPanel* self, IAvnBrush** value); /* slot 39 */
    AvnHResult (AVN_CALL *set_background)(IAvnStackPanel* self, IAvnBrush* value); /* slot 40 */
    AvnHResult (AVN_CALL *get_spacing)(IAvnStackPanel* self, double* value); /* slot 41 */
    AvnHResult (AVN_CALL *set_spacing)(IAvnStackPanel* self, double value); /* slot 42 */
    AvnHResult (AVN_CALL *get_orientation)(IAvnStackPanel* self, int32_t* value); /* slot 43 */
    AvnHResult (AVN_CALL *set_orientation)(IAvnStackPanel* self, int32_t value); /* slot 44 */
};
struct IAvnStackPanel { const IAvnStackPanelVtbl* vtbl; };
#define I_AVN_STACK_PANEL_VTABLE_SLOTS 45

static const AvnGuid I_AVN_STYLED_ELEMENT_IID = {
    0x52B157BF,
    0x839E,
    0x5307,
    { 0x9C, 0xE0, 0x49, 0x1F, 0xD6, 0x1F, 0xF6, 0x03 }
};
#define I_AVN_STYLED_ELEMENT_ABI_VERSION 3
struct IAvnStyledElementVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnStyledElement* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnStyledElement* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnStyledElement* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnStyledElement* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnStyledElement* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnStyledElement* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnStyledElement* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnStyledElement* self, IAvnStringList** value); /* slot 7 */
};
struct IAvnStyledElement { const IAvnStyledElementVtbl* vtbl; };
#define I_AVN_STYLED_ELEMENT_VTABLE_SLOTS 8

static const AvnGuid I_AVN_TEMPLATED_CONTROL_IID = {
    0x002B0BD0,
    0x7F53,
    0x52CD,
    { 0xA7, 0xBC, 0x49, 0x92, 0x24, 0x43, 0x8B, 0x34 }
};
#define I_AVN_TEMPLATED_CONTROL_ABI_VERSION 4
struct IAvnTemplatedControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTemplatedControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTemplatedControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTemplatedControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnTemplatedControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnTemplatedControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnTemplatedControl* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnTemplatedControl* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnTemplatedControl* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnTemplatedControl* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnTemplatedControl* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnTemplatedControl* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnTemplatedControl* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnTemplatedControl* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnTemplatedControl* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnTemplatedControl* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnTemplatedControl* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnTemplatedControl* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnTemplatedControl* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnTemplatedControl* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnTemplatedControl* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnTemplatedControl* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnTemplatedControl* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnTemplatedControl* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnTemplatedControl* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnTemplatedControl* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnTemplatedControl* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnTemplatedControl* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnTemplatedControl* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnTemplatedControl* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnTemplatedControl* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTemplatedControl* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTemplatedControl* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTemplatedControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTemplatedControl* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTemplatedControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTemplatedControl* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTemplatedControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTemplatedControl* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnTemplatedControl* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnTemplatedControl* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnTemplatedControl* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnTemplatedControl* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnTemplatedControl* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnTemplatedControl* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnTemplatedControl* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnTemplatedControl* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnTemplatedControl* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnTemplatedControl* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnTemplatedControl* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnTemplatedControl* self, IAvnBrush* value); /* slot 49 */
};
struct IAvnTemplatedControl { const IAvnTemplatedControlVtbl* vtbl; };
#define I_AVN_TEMPLATED_CONTROL_VTABLE_SLOTS 50

static const AvnGuid I_AVN_TEXT_BLOCK_IID = {
    0x3348758A,
    0x72D6,
    0x5B1F,
    { 0x84, 0xF2, 0x9D, 0x80, 0xA5, 0x1D, 0xC2, 0xFD }
};
#define I_AVN_TEXT_BLOCK_ABI_VERSION 4
struct IAvnTextBlockVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTextBlock* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTextBlock* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTextBlock* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnTextBlock* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnTextBlock* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnTextBlock* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnTextBlock* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnTextBlock* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnTextBlock* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnTextBlock* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnTextBlock* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnTextBlock* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnTextBlock* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnTextBlock* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnTextBlock* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnTextBlock* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnTextBlock* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnTextBlock* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnTextBlock* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnTextBlock* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnTextBlock* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnTextBlock* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnTextBlock* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnTextBlock* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnTextBlock* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnTextBlock* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnTextBlock* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnTextBlock* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnTextBlock* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnTextBlock* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTextBlock* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTextBlock* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTextBlock* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTextBlock* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTextBlock* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTextBlock* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTextBlock* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTextBlock* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_padding)(IAvnTextBlock* self, AvnThickness* value); /* slot 38 */
    AvnHResult (AVN_CALL *set_padding)(IAvnTextBlock* self, AvnThickness value); /* slot 39 */
    AvnHResult (AVN_CALL *get_text)(IAvnTextBlock* self, uint16_t** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_text)(IAvnTextBlock* self, const uint16_t* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnTextBlock* self, double* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnTextBlock* self, double value); /* slot 43 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnTextBlock* self, int32_t* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnTextBlock* self, int32_t value); /* slot 45 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnTextBlock* self, IAvnBrush** value); /* slot 46 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnTextBlock* self, IAvnBrush* value); /* slot 47 */
    AvnHResult (AVN_CALL *get_text_alignment)(IAvnTextBlock* self, int32_t* value); /* slot 48 */
    AvnHResult (AVN_CALL *set_text_alignment)(IAvnTextBlock* self, int32_t value); /* slot 49 */
};
struct IAvnTextBlock { const IAvnTextBlockVtbl* vtbl; };
#define I_AVN_TEXT_BLOCK_VTABLE_SLOTS 50

static const AvnGuid I_AVN_TEXT_BOX_IID = {
    0x14FFA332,
    0xBD09,
    0x594F,
    { 0xAE, 0x6F, 0x67, 0x95, 0x9D, 0xEB, 0x40, 0xF9 }
};
#define I_AVN_TEXT_BOX_ABI_VERSION 4
struct IAvnTextBoxVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTextBox* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTextBox* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTextBox* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnTextBox* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnTextBox* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnTextBox* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnTextBox* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnTextBox* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnTextBox* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnTextBox* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnTextBox* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnTextBox* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnTextBox* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnTextBox* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnTextBox* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnTextBox* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnTextBox* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnTextBox* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnTextBox* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnTextBox* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnTextBox* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnTextBox* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnTextBox* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnTextBox* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnTextBox* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnTextBox* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnTextBox* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnTextBox* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnTextBox* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnTextBox* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTextBox* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTextBox* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTextBox* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTextBox* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTextBox* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTextBox* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTextBox* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTextBox* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnTextBox* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnTextBox* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnTextBox* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnTextBox* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnTextBox* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnTextBox* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnTextBox* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnTextBox* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnTextBox* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnTextBox* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnTextBox* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnTextBox* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_accepts_return)(IAvnTextBox* self, int32_t* value); /* slot 50 */
    AvnHResult (AVN_CALL *set_accepts_return)(IAvnTextBox* self, int32_t value); /* slot 51 */
    AvnHResult (AVN_CALL *get_accepts_tab)(IAvnTextBox* self, int32_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_accepts_tab)(IAvnTextBox* self, int32_t value); /* slot 53 */
    AvnHResult (AVN_CALL *get_caret_index)(IAvnTextBox* self, int32_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_caret_index)(IAvnTextBox* self, int32_t value); /* slot 55 */
    AvnHResult (AVN_CALL *get_is_read_only)(IAvnTextBox* self, int32_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *set_is_read_only)(IAvnTextBox* self, int32_t value); /* slot 57 */
    AvnHResult (AVN_CALL *get_selection_start)(IAvnTextBox* self, int32_t* value); /* slot 58 */
    AvnHResult (AVN_CALL *set_selection_start)(IAvnTextBox* self, int32_t value); /* slot 59 */
    AvnHResult (AVN_CALL *get_selection_end)(IAvnTextBox* self, int32_t* value); /* slot 60 */
    AvnHResult (AVN_CALL *set_selection_end)(IAvnTextBox* self, int32_t value); /* slot 61 */
    AvnHResult (AVN_CALL *get_max_length)(IAvnTextBox* self, int32_t* value); /* slot 62 */
    AvnHResult (AVN_CALL *set_max_length)(IAvnTextBox* self, int32_t value); /* slot 63 */
    AvnHResult (AVN_CALL *get_max_lines)(IAvnTextBox* self, int32_t* value); /* slot 64 */
    AvnHResult (AVN_CALL *set_max_lines)(IAvnTextBox* self, int32_t value); /* slot 65 */
    AvnHResult (AVN_CALL *get_min_lines)(IAvnTextBox* self, int32_t* value); /* slot 66 */
    AvnHResult (AVN_CALL *set_min_lines)(IAvnTextBox* self, int32_t value); /* slot 67 */
    AvnHResult (AVN_CALL *get_line_height)(IAvnTextBox* self, double* value); /* slot 68 */
    AvnHResult (AVN_CALL *set_line_height)(IAvnTextBox* self, double value); /* slot 69 */
    AvnHResult (AVN_CALL *get_text)(IAvnTextBox* self, uint16_t** value); /* slot 70 */
    AvnHResult (AVN_CALL *set_text)(IAvnTextBox* self, const uint16_t* value); /* slot 71 */
    AvnHResult (AVN_CALL *get_placeholder_text)(IAvnTextBox* self, uint16_t** value); /* slot 72 */
    AvnHResult (AVN_CALL *set_placeholder_text)(IAvnTextBox* self, const uint16_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *get_reveal_password)(IAvnTextBox* self, int32_t* value); /* slot 74 */
    AvnHResult (AVN_CALL *set_reveal_password)(IAvnTextBox* self, int32_t value); /* slot 75 */
    AvnHResult (AVN_CALL *get_text_wrapping)(IAvnTextBox* self, int32_t* value); /* slot 76 */
    AvnHResult (AVN_CALL *set_text_wrapping)(IAvnTextBox* self, int32_t value); /* slot 77 */
    AvnHResult (AVN_CALL *get_new_line)(IAvnTextBox* self, uint16_t** value); /* slot 78 */
    AvnHResult (AVN_CALL *set_new_line)(IAvnTextBox* self, const uint16_t* value); /* slot 79 */
    AvnHResult (AVN_CALL *get_can_cut)(IAvnTextBox* self, int32_t* value); /* slot 80 */
    AvnHResult (AVN_CALL *get_can_copy)(IAvnTextBox* self, int32_t* value); /* slot 81 */
    AvnHResult (AVN_CALL *get_can_paste)(IAvnTextBox* self, int32_t* value); /* slot 82 */
    AvnHResult (AVN_CALL *get_is_undo_enabled)(IAvnTextBox* self, int32_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_is_undo_enabled)(IAvnTextBox* self, int32_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_undo_limit)(IAvnTextBox* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_undo_limit)(IAvnTextBox* self, int32_t value); /* slot 86 */
    AvnHResult (AVN_CALL *get_can_undo)(IAvnTextBox* self, int32_t* value); /* slot 87 */
    AvnHResult (AVN_CALL *get_can_redo)(IAvnTextBox* self, int32_t* value); /* slot 88 */
    AvnHResult (AVN_CALL *cut)(IAvnTextBox* self); /* slot 89 */
    AvnHResult (AVN_CALL *copy)(IAvnTextBox* self); /* slot 90 */
    AvnHResult (AVN_CALL *paste)(IAvnTextBox* self); /* slot 91 */
    AvnHResult (AVN_CALL *clear)(IAvnTextBox* self); /* slot 92 */
    AvnHResult (AVN_CALL *undo)(IAvnTextBox* self); /* slot 93 */
    AvnHResult (AVN_CALL *redo)(IAvnTextBox* self); /* slot 94 */
    AvnHResult (AVN_CALL *advise_text_changed)(IAvnTextBox* self, IAvnTextBoxTextChangedHandler* handler, int64_t* subscription_id); /* slot 95 */
    AvnHResult (AVN_CALL *unadvise_text_changed)(IAvnTextBox* self, int64_t subscription_id); /* slot 96 */
};
struct IAvnTextBox { const IAvnTextBoxVtbl* vtbl; };
#define I_AVN_TEXT_BOX_VTABLE_SLOTS 97

static const AvnGuid I_AVN_TOGGLE_BUTTON_IID = {
    0x587791B4,
    0x65DA,
    0x5D37,
    { 0x9E, 0x5B, 0xC0, 0x3B, 0x93, 0x11, 0x56, 0x83 }
};
#define I_AVN_TOGGLE_BUTTON_ABI_VERSION 5
struct IAvnToggleButtonVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnToggleButton* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnToggleButton* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnToggleButton* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnToggleButton* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnToggleButton* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnToggleButton* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnToggleButton* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnToggleButton* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnToggleButton* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnToggleButton* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnToggleButton* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnToggleButton* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnToggleButton* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnToggleButton* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnToggleButton* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnToggleButton* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnToggleButton* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnToggleButton* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnToggleButton* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnToggleButton* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnToggleButton* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnToggleButton* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnToggleButton* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnToggleButton* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnToggleButton* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnToggleButton* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnToggleButton* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnToggleButton* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnToggleButton* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnToggleButton* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnToggleButton* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnToggleButton* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnToggleButton* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnToggleButton* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnToggleButton* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnToggleButton* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnToggleButton* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnToggleButton* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnToggleButton* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnToggleButton* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnToggleButton* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnToggleButton* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnToggleButton* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnToggleButton* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnToggleButton* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnToggleButton* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnToggleButton* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnToggleButton* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnToggleButton* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnToggleButton* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_content)(IAvnToggleButton* self, IAvnControl** value); /* slot 50 */
    AvnHResult (AVN_CALL *set_content)(IAvnToggleButton* self, IAvnControl* value); /* slot 51 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnToggleButton* self, int32_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnToggleButton* self, int32_t value); /* slot 53 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnToggleButton* self, int32_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnToggleButton* self, int32_t value); /* slot 55 */
    AvnHResult (AVN_CALL *get_click_mode)(IAvnToggleButton* self, int32_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *set_click_mode)(IAvnToggleButton* self, int32_t value); /* slot 57 */
    AvnHResult (AVN_CALL *get_is_default)(IAvnToggleButton* self, int32_t* value); /* slot 58 */
    AvnHResult (AVN_CALL *set_is_default)(IAvnToggleButton* self, int32_t value); /* slot 59 */
    AvnHResult (AVN_CALL *get_is_cancel)(IAvnToggleButton* self, int32_t* value); /* slot 60 */
    AvnHResult (AVN_CALL *set_is_cancel)(IAvnToggleButton* self, int32_t value); /* slot 61 */
    AvnHResult (AVN_CALL *get_is_pressed)(IAvnToggleButton* self, int32_t* value); /* slot 62 */
    AvnHResult (AVN_CALL *advise_click)(IAvnToggleButton* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 63 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnToggleButton* self, int64_t subscription_id); /* slot 64 */
    AvnHResult (AVN_CALL *get_is_checked)(IAvnToggleButton* self, int32_t* value); /* slot 65 */
    AvnHResult (AVN_CALL *set_is_checked)(IAvnToggleButton* self, int32_t value); /* slot 66 */
    AvnHResult (AVN_CALL *get_is_three_state)(IAvnToggleButton* self, int32_t* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_is_three_state)(IAvnToggleButton* self, int32_t value); /* slot 68 */
    AvnHResult (AVN_CALL *advise_is_checked_changed)(IAvnToggleButton* self, IAvnToggleButtonIsCheckedChangedHandler* handler, int64_t* subscription_id); /* slot 69 */
    AvnHResult (AVN_CALL *unadvise_is_checked_changed)(IAvnToggleButton* self, int64_t subscription_id); /* slot 70 */
};
struct IAvnToggleButton { const IAvnToggleButtonVtbl* vtbl; };
#define I_AVN_TOGGLE_BUTTON_VTABLE_SLOTS 71

static const AvnGuid I_AVN_TOGGLE_SWITCH_IID = {
    0xECCA05F2,
    0x9F5B,
    0x51A9,
    { 0xA2, 0x74, 0x02, 0x70, 0x59, 0x9E, 0x61, 0xC7 }
};
#define I_AVN_TOGGLE_SWITCH_ABI_VERSION 5
struct IAvnToggleSwitchVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnToggleSwitch* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnToggleSwitch* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnToggleSwitch* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnToggleSwitch* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnToggleSwitch* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnToggleSwitch* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnToggleSwitch* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnToggleSwitch* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnToggleSwitch* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnToggleSwitch* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnToggleSwitch* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnToggleSwitch* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnToggleSwitch* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnToggleSwitch* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnToggleSwitch* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnToggleSwitch* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnToggleSwitch* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnToggleSwitch* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnToggleSwitch* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnToggleSwitch* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnToggleSwitch* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnToggleSwitch* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnToggleSwitch* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnToggleSwitch* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnToggleSwitch* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnToggleSwitch* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnToggleSwitch* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnToggleSwitch* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnToggleSwitch* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnToggleSwitch* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnToggleSwitch* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnToggleSwitch* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnToggleSwitch* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnToggleSwitch* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnToggleSwitch* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnToggleSwitch* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnToggleSwitch* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnToggleSwitch* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnToggleSwitch* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnToggleSwitch* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnToggleSwitch* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnToggleSwitch* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnToggleSwitch* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnToggleSwitch* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnToggleSwitch* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnToggleSwitch* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnToggleSwitch* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnToggleSwitch* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnToggleSwitch* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnToggleSwitch* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_content)(IAvnToggleSwitch* self, IAvnControl** value); /* slot 50 */
    AvnHResult (AVN_CALL *set_content)(IAvnToggleSwitch* self, IAvnControl* value); /* slot 51 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnToggleSwitch* self, int32_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnToggleSwitch* self, int32_t value); /* slot 53 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnToggleSwitch* self, int32_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnToggleSwitch* self, int32_t value); /* slot 55 */
    AvnHResult (AVN_CALL *get_click_mode)(IAvnToggleSwitch* self, int32_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *set_click_mode)(IAvnToggleSwitch* self, int32_t value); /* slot 57 */
    AvnHResult (AVN_CALL *get_is_default)(IAvnToggleSwitch* self, int32_t* value); /* slot 58 */
    AvnHResult (AVN_CALL *set_is_default)(IAvnToggleSwitch* self, int32_t value); /* slot 59 */
    AvnHResult (AVN_CALL *get_is_cancel)(IAvnToggleSwitch* self, int32_t* value); /* slot 60 */
    AvnHResult (AVN_CALL *set_is_cancel)(IAvnToggleSwitch* self, int32_t value); /* slot 61 */
    AvnHResult (AVN_CALL *get_is_pressed)(IAvnToggleSwitch* self, int32_t* value); /* slot 62 */
    AvnHResult (AVN_CALL *advise_click)(IAvnToggleSwitch* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 63 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnToggleSwitch* self, int64_t subscription_id); /* slot 64 */
    AvnHResult (AVN_CALL *get_is_checked)(IAvnToggleSwitch* self, int32_t* value); /* slot 65 */
    AvnHResult (AVN_CALL *set_is_checked)(IAvnToggleSwitch* self, int32_t value); /* slot 66 */
    AvnHResult (AVN_CALL *get_is_three_state)(IAvnToggleSwitch* self, int32_t* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_is_three_state)(IAvnToggleSwitch* self, int32_t value); /* slot 68 */
    AvnHResult (AVN_CALL *advise_is_checked_changed)(IAvnToggleSwitch* self, IAvnToggleButtonIsCheckedChangedHandler* handler, int64_t* subscription_id); /* slot 69 */
    AvnHResult (AVN_CALL *unadvise_is_checked_changed)(IAvnToggleSwitch* self, int64_t subscription_id); /* slot 70 */
    AvnHResult (AVN_CALL *get_on_content)(IAvnToggleSwitch* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_on_content)(IAvnToggleSwitch* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_off_content)(IAvnToggleSwitch* self, IAvnControl** value); /* slot 73 */
    AvnHResult (AVN_CALL *set_off_content)(IAvnToggleSwitch* self, IAvnControl* value); /* slot 74 */
};
struct IAvnToggleSwitch { const IAvnToggleSwitchVtbl* vtbl; };
#define I_AVN_TOGGLE_SWITCH_VTABLE_SLOTS 75

static const AvnGuid I_AVN_WINDOW_IID = {
    0x965CC1CE,
    0xDA6F,
    0x5CCB,
    { 0x90, 0x0F, 0x31, 0x50, 0xCA, 0x8D, 0xB6, 0x05 }
};
#define I_AVN_WINDOW_ABI_VERSION 5
struct IAvnWindowVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnWindow* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnWindow* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnWindow* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnWindow* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnWindow* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnWindow* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnWindow* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnWindow* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnWindow* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnWindow* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnWindow* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnWindow* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_width)(IAvnWindow* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_width)(IAvnWindow* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_height)(IAvnWindow* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_height)(IAvnWindow* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnWindow* self, double* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnWindow* self, double value); /* slot 17 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnWindow* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnWindow* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnWindow* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnWindow* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnWindow* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnWindow* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_margin)(IAvnWindow* self, AvnThickness* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_margin)(IAvnWindow* self, AvnThickness value); /* slot 25 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnWindow* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnWindow* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnWindow* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnWindow* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnWindow* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnWindow* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnWindow* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnWindow* self, int64_t subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnWindow* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnWindow* self, int64_t subscription_id); /* slot 35 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnWindow* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 36 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnWindow* self, int64_t subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *get_background)(IAvnWindow* self, IAvnBrush** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_background)(IAvnWindow* self, IAvnBrush* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnWindow* self, IAvnBrush** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnWindow* self, IAvnBrush* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnWindow* self, AvnThickness* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnWindow* self, AvnThickness value); /* slot 43 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnWindow* self, AvnCornerRadius* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnWindow* self, AvnCornerRadius value); /* slot 45 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnWindow* self, double* value); /* slot 46 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnWindow* self, double value); /* slot 47 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnWindow* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnWindow* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_content)(IAvnWindow* self, IAvnControl** value); /* slot 50 */
    AvnHResult (AVN_CALL *set_content)(IAvnWindow* self, IAvnControl* value); /* slot 51 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnWindow* self, int32_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnWindow* self, int32_t value); /* slot 53 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnWindow* self, int32_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnWindow* self, int32_t value); /* slot 55 */
    AvnHResult (AVN_CALL *get_title)(IAvnWindow* self, uint16_t** value); /* slot 56 */
    AvnHResult (AVN_CALL *set_title)(IAvnWindow* self, const uint16_t* value); /* slot 57 */
    AvnHResult (AVN_CALL *get_window_state)(IAvnWindow* self, int32_t* value); /* slot 58 */
    AvnHResult (AVN_CALL *set_window_state)(IAvnWindow* self, int32_t value); /* slot 59 */
    AvnHResult (AVN_CALL *get_can_resize)(IAvnWindow* self, int32_t* value); /* slot 60 */
    AvnHResult (AVN_CALL *set_can_resize)(IAvnWindow* self, int32_t value); /* slot 61 */
    AvnHResult (AVN_CALL *close)(IAvnWindow* self); /* slot 62 */
    AvnHResult (AVN_CALL *show)(IAvnWindow* self); /* slot 63 */
    AvnHResult (AVN_CALL *show_with_window)(IAvnWindow* self, IAvnWindow* owner); /* slot 64 */
};
struct IAvnWindow { const IAvnWindowVtbl* vtbl; };
#define I_AVN_WINDOW_VTABLE_SLOTS 65

static const AvnGuid I_AVN_CANVAS_STATICS_IID = {
    0x5F4ABE7B,
    0xF5E4,
    0x58E1,
    { 0xB3, 0x7B, 0xF2, 0x9F, 0xF6, 0x89, 0xD0, 0xA0 }
};
#define I_AVN_CANVAS_STATICS_ABI_VERSION 1
struct IAvnCanvasStaticsVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCanvasStatics* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCanvasStatics* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCanvasStatics* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_left)(IAvnCanvasStatics* self, IAvnControl* target, double* value); /* slot 3 */
    AvnHResult (AVN_CALL *set_left)(IAvnCanvasStatics* self, IAvnControl* target, double value); /* slot 4 */
    AvnHResult (AVN_CALL *get_top)(IAvnCanvasStatics* self, IAvnControl* target, double* value); /* slot 5 */
    AvnHResult (AVN_CALL *set_top)(IAvnCanvasStatics* self, IAvnControl* target, double value); /* slot 6 */
    AvnHResult (AVN_CALL *get_right)(IAvnCanvasStatics* self, IAvnControl* target, double* value); /* slot 7 */
    AvnHResult (AVN_CALL *set_right)(IAvnCanvasStatics* self, IAvnControl* target, double value); /* slot 8 */
    AvnHResult (AVN_CALL *get_bottom)(IAvnCanvasStatics* self, IAvnControl* target, double* value); /* slot 9 */
    AvnHResult (AVN_CALL *set_bottom)(IAvnCanvasStatics* self, IAvnControl* target, double value); /* slot 10 */
};
struct IAvnCanvasStatics { const IAvnCanvasStaticsVtbl* vtbl; };
#define I_AVN_CANVAS_STATICS_VTABLE_SLOTS 11

static const AvnGuid I_AVN_DOCK_PANEL_STATICS_IID = {
    0xCFAE424D,
    0xA4EB,
    0x5486,
    { 0x90, 0xDB, 0x3B, 0xC2, 0xD5, 0xA2, 0x0A, 0x3E }
};
#define I_AVN_DOCK_PANEL_STATICS_ABI_VERSION 1
struct IAvnDockPanelStaticsVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnDockPanelStatics* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnDockPanelStatics* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnDockPanelStatics* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_dock)(IAvnDockPanelStatics* self, IAvnControl* target, int32_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *set_dock)(IAvnDockPanelStatics* self, IAvnControl* target, int32_t value); /* slot 4 */
};
struct IAvnDockPanelStatics { const IAvnDockPanelStaticsVtbl* vtbl; };
#define I_AVN_DOCK_PANEL_STATICS_VTABLE_SLOTS 5

static const AvnGuid I_AVN_GRID_STATICS_IID = {
    0x37D5F766,
    0xD7F5,
    0x57CD,
    { 0xBE, 0x7F, 0xA0, 0x3A, 0x1A, 0xA9, 0xB6, 0x83 }
};
#define I_AVN_GRID_STATICS_ABI_VERSION 1
struct IAvnGridStaticsVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnGridStatics* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnGridStatics* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnGridStatics* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_column)(IAvnGridStatics* self, IAvnControl* target, int32_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *set_column)(IAvnGridStatics* self, IAvnControl* target, int32_t value); /* slot 4 */
    AvnHResult (AVN_CALL *get_row)(IAvnGridStatics* self, IAvnControl* target, int32_t* value); /* slot 5 */
    AvnHResult (AVN_CALL *set_row)(IAvnGridStatics* self, IAvnControl* target, int32_t value); /* slot 6 */
    AvnHResult (AVN_CALL *get_column_span)(IAvnGridStatics* self, IAvnControl* target, int32_t* value); /* slot 7 */
    AvnHResult (AVN_CALL *set_column_span)(IAvnGridStatics* self, IAvnControl* target, int32_t value); /* slot 8 */
    AvnHResult (AVN_CALL *get_row_span)(IAvnGridStatics* self, IAvnControl* target, int32_t* value); /* slot 9 */
    AvnHResult (AVN_CALL *set_row_span)(IAvnGridStatics* self, IAvnControl* target, int32_t value); /* slot 10 */
    AvnHResult (AVN_CALL *get_is_shared_size_scope)(IAvnGridStatics* self, IAvnControl* target, int32_t* value); /* slot 11 */
    AvnHResult (AVN_CALL *set_is_shared_size_scope)(IAvnGridStatics* self, IAvnControl* target, int32_t value); /* slot 12 */
};
struct IAvnGridStatics { const IAvnGridStaticsVtbl* vtbl; };
#define I_AVN_GRID_STATICS_VTABLE_SLOTS 13

static const AvnGuid I_AVN_CONTROL_FACTORY_IID = {
    0xD4F85479,
    0xDCD6,
    0x5E2E,
    { 0xB8, 0xAB, 0x06, 0x93, 0xA8, 0xC0, 0xD6, 0xD6 }
};
#define I_AVN_CONTROL_FACTORY_ABI_VERSION 2
struct IAvnControlFactoryVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnControlFactory* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnControlFactory* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnControlFactory* self); /* slot 2 */
    AvnHResult (AVN_CALL *create_avalonia_object)(IAvnControlFactory* self, IAvnAvaloniaObject** value); /* slot 3 */
    AvnHResult (AVN_CALL *create_border)(IAvnControlFactory* self, IAvnBorder** value); /* slot 4 */
    AvnHResult (AVN_CALL *create_button)(IAvnControlFactory* self, IAvnButton** value); /* slot 5 */
    AvnHResult (AVN_CALL *create_canvas)(IAvnControlFactory* self, IAvnCanvas** value); /* slot 6 */
    AvnHResult (AVN_CALL *create_check_box)(IAvnControlFactory* self, IAvnCheckBox** value); /* slot 7 */
    AvnHResult (AVN_CALL *create_combo_box)(IAvnControlFactory* self, IAvnComboBox** value); /* slot 8 */
    AvnHResult (AVN_CALL *create_combo_box_item)(IAvnControlFactory* self, IAvnComboBoxItem** value); /* slot 9 */
    AvnHResult (AVN_CALL *create_content_control)(IAvnControlFactory* self, IAvnContentControl** value); /* slot 10 */
    AvnHResult (AVN_CALL *create_control)(IAvnControlFactory* self, IAvnControl** value); /* slot 11 */
    AvnHResult (AVN_CALL *create_decorator)(IAvnControlFactory* self, IAvnDecorator** value); /* slot 12 */
    AvnHResult (AVN_CALL *create_dock_panel)(IAvnControlFactory* self, IAvnDockPanel** value); /* slot 13 */
    AvnHResult (AVN_CALL *create_expander)(IAvnControlFactory* self, IAvnExpander** value); /* slot 14 */
    AvnHResult (AVN_CALL *create_grid)(IAvnControlFactory* self, IAvnGrid** value); /* slot 15 */
    AvnHResult (AVN_CALL *create_headered_content_control)(IAvnControlFactory* self, IAvnHeaderedContentControl** value); /* slot 16 */
    AvnHResult (AVN_CALL *create_items_control)(IAvnControlFactory* self, IAvnItemsControl** value); /* slot 17 */
    AvnHResult (AVN_CALL *create_list_box)(IAvnControlFactory* self, IAvnListBox** value); /* slot 18 */
    AvnHResult (AVN_CALL *create_list_box_item)(IAvnControlFactory* self, IAvnListBoxItem** value); /* slot 19 */
    AvnHResult (AVN_CALL *create_panel)(IAvnControlFactory* self, IAvnPanel** value); /* slot 20 */
    AvnHResult (AVN_CALL *create_progress_bar)(IAvnControlFactory* self, IAvnProgressBar** value); /* slot 21 */
    AvnHResult (AVN_CALL *create_radio_button)(IAvnControlFactory* self, IAvnRadioButton** value); /* slot 22 */
    AvnHResult (AVN_CALL *create_scroll_viewer)(IAvnControlFactory* self, IAvnScrollViewer** value); /* slot 23 */
    AvnHResult (AVN_CALL *create_selecting_items_control)(IAvnControlFactory* self, IAvnSelectingItemsControl** value); /* slot 24 */
    AvnHResult (AVN_CALL *create_slider)(IAvnControlFactory* self, IAvnSlider** value); /* slot 25 */
    AvnHResult (AVN_CALL *create_stack_panel)(IAvnControlFactory* self, IAvnStackPanel** value); /* slot 26 */
    AvnHResult (AVN_CALL *create_styled_element)(IAvnControlFactory* self, IAvnStyledElement** value); /* slot 27 */
    AvnHResult (AVN_CALL *create_templated_control)(IAvnControlFactory* self, IAvnTemplatedControl** value); /* slot 28 */
    AvnHResult (AVN_CALL *create_text_block)(IAvnControlFactory* self, IAvnTextBlock** value); /* slot 29 */
    AvnHResult (AVN_CALL *create_text_box)(IAvnControlFactory* self, IAvnTextBox** value); /* slot 30 */
    AvnHResult (AVN_CALL *create_toggle_button)(IAvnControlFactory* self, IAvnToggleButton** value); /* slot 31 */
    AvnHResult (AVN_CALL *create_toggle_switch)(IAvnControlFactory* self, IAvnToggleSwitch** value); /* slot 32 */
    AvnHResult (AVN_CALL *create_window)(IAvnControlFactory* self, IAvnWindow** value); /* slot 33 */
    AvnHResult (AVN_CALL *get_canvas_statics)(IAvnControlFactory* self, IAvnCanvasStatics** value); /* slot 34 */
    AvnHResult (AVN_CALL *get_dock_panel_statics)(IAvnControlFactory* self, IAvnDockPanelStatics** value); /* slot 35 */
    AvnHResult (AVN_CALL *get_grid_statics)(IAvnControlFactory* self, IAvnGridStatics** value); /* slot 36 */
    AvnHResult (AVN_CALL *create_solid_color_brush)(IAvnControlFactory* self, AvnColor color, double opacity, IAvnBrush** value); /* slot 37 */
};
struct IAvnControlFactory { const IAvnControlFactoryVtbl* vtbl; };
#define I_AVN_CONTROL_FACTORY_VTABLE_SLOTS 38

#endif /* AVALONIA_RUST_ABI_H */
