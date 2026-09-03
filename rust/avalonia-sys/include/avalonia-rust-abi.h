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
    0xF739DD7D,
    0x4E30,
    0x54FF,
    { 0xBE, 0x32, 0xDD, 0xC3, 0x91, 0x51, 0x0B, 0x29 }
};
#define I_AVN_BORDER_ABI_VERSION 2
struct IAvnBorderVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnBorder* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnBorder* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnBorder* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnBorder* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnBorder* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnBorder* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnBorder* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnBorder* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnBorder* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnBorder* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnBorder* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnBorder* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnBorder* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnBorder* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnBorder* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnBorder* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnBorder* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnBorder* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_child)(IAvnBorder* self, IAvnControl** value); /* slot 18 */
    AvnHResult (AVN_CALL *set_child)(IAvnBorder* self, IAvnControl* value); /* slot 19 */
    AvnHResult (AVN_CALL *get_background_sizing)(IAvnBorder* self, int32_t* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_background_sizing)(IAvnBorder* self, int32_t value); /* slot 21 */
};
struct IAvnBorder { const IAvnBorderVtbl* vtbl; };
#define I_AVN_BORDER_VTABLE_SLOTS 22

static const AvnGuid I_AVN_BUTTON_IID = {
    0x476007AA,
    0xFC01,
    0x5943,
    { 0xA7, 0x63, 0x41, 0x58, 0x9B, 0x33, 0xB7, 0xA7 }
};
#define I_AVN_BUTTON_ABI_VERSION 2
struct IAvnButtonVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnButton* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnButton* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnButton* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnButton* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnButton* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnButton* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnButton* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnButton* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnButton* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnButton* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnButton* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnButton* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnButton* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnButton* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnButton* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnButton* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnButton* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnButton* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_content)(IAvnButton* self, IAvnControl** value); /* slot 18 */
    AvnHResult (AVN_CALL *set_content)(IAvnButton* self, IAvnControl* value); /* slot 19 */
    AvnHResult (AVN_CALL *advise_click)(IAvnButton* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 20 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnButton* self, int64_t subscription_id); /* slot 21 */
};
struct IAvnButton { const IAvnButtonVtbl* vtbl; };
#define I_AVN_BUTTON_VTABLE_SLOTS 22

static const AvnGuid I_AVN_CANVAS_IID = {
    0x93C6FF9D,
    0x813F,
    0x53A1,
    { 0x8A, 0x4D, 0xC7, 0xC3, 0xCE, 0x48, 0xF6, 0x65 }
};
#define I_AVN_CANVAS_ABI_VERSION 2
struct IAvnCanvasVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCanvas* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCanvas* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCanvas* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnCanvas* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnCanvas* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnCanvas* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnCanvas* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnCanvas* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnCanvas* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnCanvas* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnCanvas* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnCanvas* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnCanvas* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnCanvas* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnCanvas* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnCanvas* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnCanvas* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnCanvas* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_children)(IAvnCanvas* self, IAvnControlList** value); /* slot 18 */
};
struct IAvnCanvas { const IAvnCanvasVtbl* vtbl; };
#define I_AVN_CANVAS_VTABLE_SLOTS 19

static const AvnGuid I_AVN_CHECK_BOX_IID = {
    0xB49EB85F,
    0x9FA3,
    0x5B1F,
    { 0x9A, 0xA7, 0x75, 0x05, 0xFD, 0xF2, 0xD4, 0xCC }
};
#define I_AVN_CHECK_BOX_ABI_VERSION 2
struct IAvnCheckBoxVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCheckBox* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCheckBox* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCheckBox* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnCheckBox* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnCheckBox* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnCheckBox* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnCheckBox* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnCheckBox* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnCheckBox* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnCheckBox* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnCheckBox* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnCheckBox* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnCheckBox* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnCheckBox* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnCheckBox* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnCheckBox* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnCheckBox* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnCheckBox* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_content)(IAvnCheckBox* self, IAvnControl** value); /* slot 18 */
    AvnHResult (AVN_CALL *set_content)(IAvnCheckBox* self, IAvnControl* value); /* slot 19 */
    AvnHResult (AVN_CALL *advise_click)(IAvnCheckBox* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 20 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnCheckBox* self, int64_t subscription_id); /* slot 21 */
    AvnHResult (AVN_CALL *get_is_checked)(IAvnCheckBox* self, int32_t* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_is_checked)(IAvnCheckBox* self, int32_t value); /* slot 23 */
    AvnHResult (AVN_CALL *advise_is_checked_changed)(IAvnCheckBox* self, IAvnToggleButtonIsCheckedChangedHandler* handler, int64_t* subscription_id); /* slot 24 */
    AvnHResult (AVN_CALL *unadvise_is_checked_changed)(IAvnCheckBox* self, int64_t subscription_id); /* slot 25 */
};
struct IAvnCheckBox { const IAvnCheckBoxVtbl* vtbl; };
#define I_AVN_CHECK_BOX_VTABLE_SLOTS 26

static const AvnGuid I_AVN_COMBO_BOX_IID = {
    0x55688009,
    0x14E3,
    0x5334,
    { 0x8E, 0x9B, 0xFE, 0x2A, 0x73, 0x69, 0x17, 0x20 }
};
#define I_AVN_COMBO_BOX_ABI_VERSION 2
struct IAvnComboBoxVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnComboBox* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnComboBox* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnComboBox* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnComboBox* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnComboBox* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnComboBox* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnComboBox* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnComboBox* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnComboBox* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnComboBox* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnComboBox* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnComboBox* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnComboBox* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnComboBox* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnComboBox* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnComboBox* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnComboBox* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnComboBox* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_items)(IAvnComboBox* self, IAvnItemList** value); /* slot 18 */
    AvnHResult (AVN_CALL *get_selected_index)(IAvnComboBox* self, int32_t* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_selected_index)(IAvnComboBox* self, int32_t value); /* slot 20 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnComboBox* self, IAvnSelectingItemsControlSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 21 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnComboBox* self, int64_t subscription_id); /* slot 22 */
    AvnHResult (AVN_CALL *get_placeholder_text)(IAvnComboBox* self, uint16_t** value); /* slot 23 */
    AvnHResult (AVN_CALL *set_placeholder_text)(IAvnComboBox* self, const uint16_t* value); /* slot 24 */
};
struct IAvnComboBox { const IAvnComboBoxVtbl* vtbl; };
#define I_AVN_COMBO_BOX_VTABLE_SLOTS 25

static const AvnGuid I_AVN_COMBO_BOX_ITEM_IID = {
    0xDF316DBA,
    0xE86C,
    0x56A5,
    { 0xA0, 0xA3, 0x33, 0xDB, 0xFC, 0x4B, 0xE6, 0x54 }
};
#define I_AVN_COMBO_BOX_ITEM_ABI_VERSION 2
struct IAvnComboBoxItemVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnComboBoxItem* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnComboBoxItem* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnComboBoxItem* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnComboBoxItem* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnComboBoxItem* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnComboBoxItem* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnComboBoxItem* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnComboBoxItem* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnComboBoxItem* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnComboBoxItem* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnComboBoxItem* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnComboBoxItem* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnComboBoxItem* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnComboBoxItem* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnComboBoxItem* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnComboBoxItem* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnComboBoxItem* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnComboBoxItem* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_content)(IAvnComboBoxItem* self, IAvnControl** value); /* slot 18 */
    AvnHResult (AVN_CALL *set_content)(IAvnComboBoxItem* self, IAvnControl* value); /* slot 19 */
    AvnHResult (AVN_CALL *get_is_selected)(IAvnComboBoxItem* self, int32_t* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_is_selected)(IAvnComboBoxItem* self, int32_t value); /* slot 21 */
};
struct IAvnComboBoxItem { const IAvnComboBoxItemVtbl* vtbl; };
#define I_AVN_COMBO_BOX_ITEM_VTABLE_SLOTS 22

static const AvnGuid I_AVN_CONTENT_CONTROL_IID = {
    0x44B1FE4E,
    0x5095,
    0x5587,
    { 0xAD, 0x59, 0x57, 0xCB, 0x60, 0xAD, 0xEF, 0xE3 }
};
#define I_AVN_CONTENT_CONTROL_ABI_VERSION 2
struct IAvnContentControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnContentControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnContentControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnContentControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnContentControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnContentControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnContentControl* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnContentControl* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnContentControl* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnContentControl* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnContentControl* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnContentControl* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnContentControl* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnContentControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnContentControl* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnContentControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnContentControl* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnContentControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnContentControl* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_content)(IAvnContentControl* self, IAvnControl** value); /* slot 18 */
    AvnHResult (AVN_CALL *set_content)(IAvnContentControl* self, IAvnControl* value); /* slot 19 */
};
struct IAvnContentControl { const IAvnContentControlVtbl* vtbl; };
#define I_AVN_CONTENT_CONTROL_VTABLE_SLOTS 20

static const AvnGuid I_AVN_CONTROL_IID = {
    0x152B5D1F,
    0x7E08,
    0x56E0,
    { 0xB1, 0x00, 0xF7, 0x79, 0x91, 0x75, 0x10, 0xD3 }
};
#define I_AVN_CONTROL_ABI_VERSION 2
struct IAvnControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnControl* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnControl* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnControl* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnControl* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnControl* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnControl* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnControl* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnControl* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnControl* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnControl* self, int64_t subscription_id); /* slot 17 */
};
struct IAvnControl { const IAvnControlVtbl* vtbl; };
#define I_AVN_CONTROL_VTABLE_SLOTS 18

static const AvnGuid I_AVN_DECORATOR_IID = {
    0xB893E635,
    0x46EE,
    0x58CC,
    { 0xA3, 0xA3, 0x75, 0x22, 0xC6, 0x33, 0x6C, 0x3F }
};
#define I_AVN_DECORATOR_ABI_VERSION 2
struct IAvnDecoratorVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnDecorator* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnDecorator* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnDecorator* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnDecorator* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnDecorator* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnDecorator* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnDecorator* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnDecorator* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnDecorator* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnDecorator* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnDecorator* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnDecorator* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnDecorator* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnDecorator* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnDecorator* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnDecorator* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnDecorator* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnDecorator* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_child)(IAvnDecorator* self, IAvnControl** value); /* slot 18 */
    AvnHResult (AVN_CALL *set_child)(IAvnDecorator* self, IAvnControl* value); /* slot 19 */
};
struct IAvnDecorator { const IAvnDecoratorVtbl* vtbl; };
#define I_AVN_DECORATOR_VTABLE_SLOTS 20

static const AvnGuid I_AVN_DOCK_PANEL_IID = {
    0xD84CC29A,
    0x9E7D,
    0x5A9B,
    { 0xBC, 0x4F, 0x99, 0xE8, 0x54, 0x30, 0xE1, 0x72 }
};
#define I_AVN_DOCK_PANEL_ABI_VERSION 2
struct IAvnDockPanelVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnDockPanel* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnDockPanel* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnDockPanel* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnDockPanel* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnDockPanel* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnDockPanel* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnDockPanel* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnDockPanel* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnDockPanel* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnDockPanel* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnDockPanel* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnDockPanel* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnDockPanel* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnDockPanel* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnDockPanel* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnDockPanel* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnDockPanel* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnDockPanel* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_children)(IAvnDockPanel* self, IAvnControlList** value); /* slot 18 */
    AvnHResult (AVN_CALL *get_last_child_fill)(IAvnDockPanel* self, int32_t* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_last_child_fill)(IAvnDockPanel* self, int32_t value); /* slot 20 */
    AvnHResult (AVN_CALL *get_horizontal_spacing)(IAvnDockPanel* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_horizontal_spacing)(IAvnDockPanel* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_vertical_spacing)(IAvnDockPanel* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_vertical_spacing)(IAvnDockPanel* self, double value); /* slot 24 */
};
struct IAvnDockPanel { const IAvnDockPanelVtbl* vtbl; };
#define I_AVN_DOCK_PANEL_VTABLE_SLOTS 25

static const AvnGuid I_AVN_EXPANDER_IID = {
    0x20EDCA72,
    0x42B6,
    0x57FB,
    { 0x83, 0x8D, 0x50, 0x28, 0x36, 0xEE, 0xD0, 0x3B }
};
#define I_AVN_EXPANDER_ABI_VERSION 2
struct IAvnExpanderVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnExpander* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnExpander* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnExpander* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnExpander* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnExpander* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnExpander* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnExpander* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnExpander* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnExpander* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnExpander* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnExpander* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnExpander* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnExpander* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnExpander* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnExpander* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnExpander* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnExpander* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnExpander* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_content)(IAvnExpander* self, IAvnControl** value); /* slot 18 */
    AvnHResult (AVN_CALL *set_content)(IAvnExpander* self, IAvnControl* value); /* slot 19 */
    AvnHResult (AVN_CALL *get_header)(IAvnExpander* self, IAvnControl** value); /* slot 20 */
    AvnHResult (AVN_CALL *set_header)(IAvnExpander* self, IAvnControl* value); /* slot 21 */
    AvnHResult (AVN_CALL *get_expand_direction)(IAvnExpander* self, int32_t* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_expand_direction)(IAvnExpander* self, int32_t value); /* slot 23 */
    AvnHResult (AVN_CALL *get_is_expanded)(IAvnExpander* self, int32_t* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_is_expanded)(IAvnExpander* self, int32_t value); /* slot 25 */
    AvnHResult (AVN_CALL *advise_collapsed)(IAvnExpander* self, IAvnExpanderCollapsedHandler* handler, int64_t* subscription_id); /* slot 26 */
    AvnHResult (AVN_CALL *unadvise_collapsed)(IAvnExpander* self, int64_t subscription_id); /* slot 27 */
    AvnHResult (AVN_CALL *advise_expanded)(IAvnExpander* self, IAvnExpanderExpandedHandler* handler, int64_t* subscription_id); /* slot 28 */
    AvnHResult (AVN_CALL *unadvise_expanded)(IAvnExpander* self, int64_t subscription_id); /* slot 29 */
};
struct IAvnExpander { const IAvnExpanderVtbl* vtbl; };
#define I_AVN_EXPANDER_VTABLE_SLOTS 30

static const AvnGuid I_AVN_GRID_IID = {
    0x63B055A6,
    0x7C40,
    0x5F6D,
    { 0x9A, 0x36, 0x44, 0x30, 0xCB, 0x8F, 0xED, 0x95 }
};
#define I_AVN_GRID_ABI_VERSION 2
struct IAvnGridVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnGrid* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnGrid* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnGrid* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnGrid* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnGrid* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnGrid* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnGrid* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnGrid* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnGrid* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnGrid* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnGrid* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnGrid* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnGrid* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnGrid* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnGrid* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnGrid* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnGrid* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnGrid* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_children)(IAvnGrid* self, IAvnControlList** value); /* slot 18 */
    AvnHResult (AVN_CALL *get_show_grid_lines)(IAvnGrid* self, int32_t* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_show_grid_lines)(IAvnGrid* self, int32_t value); /* slot 20 */
    AvnHResult (AVN_CALL *get_row_spacing)(IAvnGrid* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_row_spacing)(IAvnGrid* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_column_spacing)(IAvnGrid* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_column_spacing)(IAvnGrid* self, double value); /* slot 24 */
};
struct IAvnGrid { const IAvnGridVtbl* vtbl; };
#define I_AVN_GRID_VTABLE_SLOTS 25

static const AvnGuid I_AVN_HEADERED_CONTENT_CONTROL_IID = {
    0xD754F819,
    0x0B66,
    0x540A,
    { 0xAC, 0x7D, 0xB8, 0x50, 0xEF, 0x28, 0xA6, 0xC9 }
};
#define I_AVN_HEADERED_CONTENT_CONTROL_ABI_VERSION 2
struct IAvnHeaderedContentControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnHeaderedContentControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnHeaderedContentControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnHeaderedContentControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnHeaderedContentControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnHeaderedContentControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnHeaderedContentControl* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnHeaderedContentControl* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnHeaderedContentControl* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnHeaderedContentControl* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnHeaderedContentControl* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnHeaderedContentControl* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnHeaderedContentControl* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnHeaderedContentControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnHeaderedContentControl* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnHeaderedContentControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnHeaderedContentControl* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnHeaderedContentControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnHeaderedContentControl* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_content)(IAvnHeaderedContentControl* self, IAvnControl** value); /* slot 18 */
    AvnHResult (AVN_CALL *set_content)(IAvnHeaderedContentControl* self, IAvnControl* value); /* slot 19 */
    AvnHResult (AVN_CALL *get_header)(IAvnHeaderedContentControl* self, IAvnControl** value); /* slot 20 */
    AvnHResult (AVN_CALL *set_header)(IAvnHeaderedContentControl* self, IAvnControl* value); /* slot 21 */
};
struct IAvnHeaderedContentControl { const IAvnHeaderedContentControlVtbl* vtbl; };
#define I_AVN_HEADERED_CONTENT_CONTROL_VTABLE_SLOTS 22

static const AvnGuid I_AVN_ITEMS_CONTROL_IID = {
    0xE3E795EB,
    0x2BDC,
    0x512A,
    { 0x9A, 0x81, 0x24, 0x60, 0x7C, 0x44, 0xA1, 0x66 }
};
#define I_AVN_ITEMS_CONTROL_ABI_VERSION 2
struct IAvnItemsControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnItemsControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnItemsControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnItemsControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnItemsControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnItemsControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnItemsControl* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnItemsControl* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnItemsControl* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnItemsControl* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnItemsControl* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnItemsControl* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnItemsControl* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnItemsControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnItemsControl* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnItemsControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnItemsControl* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnItemsControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnItemsControl* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_items)(IAvnItemsControl* self, IAvnItemList** value); /* slot 18 */
};
struct IAvnItemsControl { const IAvnItemsControlVtbl* vtbl; };
#define I_AVN_ITEMS_CONTROL_VTABLE_SLOTS 19

static const AvnGuid I_AVN_LIST_BOX_IID = {
    0xC0C05FD7,
    0xA38F,
    0x5310,
    { 0xB8, 0x2F, 0xF4, 0xFC, 0xA3, 0x27, 0xD0, 0x4A }
};
#define I_AVN_LIST_BOX_ABI_VERSION 2
struct IAvnListBoxVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnListBox* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnListBox* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnListBox* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnListBox* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnListBox* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnListBox* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnListBox* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnListBox* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnListBox* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnListBox* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnListBox* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnListBox* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnListBox* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnListBox* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnListBox* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnListBox* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnListBox* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnListBox* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_items)(IAvnListBox* self, IAvnItemList** value); /* slot 18 */
    AvnHResult (AVN_CALL *get_selected_index)(IAvnListBox* self, int32_t* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_selected_index)(IAvnListBox* self, int32_t value); /* slot 20 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnListBox* self, IAvnSelectingItemsControlSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 21 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnListBox* self, int64_t subscription_id); /* slot 22 */
};
struct IAvnListBox { const IAvnListBoxVtbl* vtbl; };
#define I_AVN_LIST_BOX_VTABLE_SLOTS 23

static const AvnGuid I_AVN_LIST_BOX_ITEM_IID = {
    0x309C4165,
    0xA289,
    0x57E3,
    { 0xBD, 0x50, 0x25, 0xB2, 0x72, 0x38, 0x1C, 0xB6 }
};
#define I_AVN_LIST_BOX_ITEM_ABI_VERSION 2
struct IAvnListBoxItemVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnListBoxItem* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnListBoxItem* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnListBoxItem* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnListBoxItem* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnListBoxItem* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnListBoxItem* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnListBoxItem* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnListBoxItem* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnListBoxItem* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnListBoxItem* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnListBoxItem* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnListBoxItem* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnListBoxItem* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnListBoxItem* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnListBoxItem* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnListBoxItem* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnListBoxItem* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnListBoxItem* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_content)(IAvnListBoxItem* self, IAvnControl** value); /* slot 18 */
    AvnHResult (AVN_CALL *set_content)(IAvnListBoxItem* self, IAvnControl* value); /* slot 19 */
    AvnHResult (AVN_CALL *get_is_selected)(IAvnListBoxItem* self, int32_t* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_is_selected)(IAvnListBoxItem* self, int32_t value); /* slot 21 */
};
struct IAvnListBoxItem { const IAvnListBoxItemVtbl* vtbl; };
#define I_AVN_LIST_BOX_ITEM_VTABLE_SLOTS 22

static const AvnGuid I_AVN_PANEL_IID = {
    0xF72F3D40,
    0xA1B2,
    0x50F3,
    { 0xA7, 0xF6, 0xE6, 0x3C, 0x8A, 0x19, 0x19, 0x27 }
};
#define I_AVN_PANEL_ABI_VERSION 2
struct IAvnPanelVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnPanel* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnPanel* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnPanel* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnPanel* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnPanel* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnPanel* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnPanel* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnPanel* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnPanel* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnPanel* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnPanel* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnPanel* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnPanel* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnPanel* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnPanel* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnPanel* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnPanel* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnPanel* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_children)(IAvnPanel* self, IAvnControlList** value); /* slot 18 */
};
struct IAvnPanel { const IAvnPanelVtbl* vtbl; };
#define I_AVN_PANEL_VTABLE_SLOTS 19

static const AvnGuid I_AVN_PROGRESS_BAR_IID = {
    0xF35F36F3,
    0x15C0,
    0x5295,
    { 0xA3, 0xDD, 0xE3, 0x12, 0xD8, 0x52, 0x2A, 0x66 }
};
#define I_AVN_PROGRESS_BAR_ABI_VERSION 2
struct IAvnProgressBarVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnProgressBar* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnProgressBar* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnProgressBar* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnProgressBar* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnProgressBar* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnProgressBar* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnProgressBar* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnProgressBar* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnProgressBar* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnProgressBar* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnProgressBar* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnProgressBar* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnProgressBar* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnProgressBar* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnProgressBar* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnProgressBar* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnProgressBar* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnProgressBar* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_minimum)(IAvnProgressBar* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_minimum)(IAvnProgressBar* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_maximum)(IAvnProgressBar* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_maximum)(IAvnProgressBar* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_value)(IAvnProgressBar* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_value)(IAvnProgressBar* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_small_change)(IAvnProgressBar* self, double* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_small_change)(IAvnProgressBar* self, double value); /* slot 25 */
    AvnHResult (AVN_CALL *get_large_change)(IAvnProgressBar* self, double* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_large_change)(IAvnProgressBar* self, double value); /* slot 27 */
    AvnHResult (AVN_CALL *advise_value_changed)(IAvnProgressBar* self, IAvnRangeBaseValueChangedHandler* handler, int64_t* subscription_id); /* slot 28 */
    AvnHResult (AVN_CALL *unadvise_value_changed)(IAvnProgressBar* self, int64_t subscription_id); /* slot 29 */
    AvnHResult (AVN_CALL *get_is_indeterminate)(IAvnProgressBar* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_is_indeterminate)(IAvnProgressBar* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *get_show_progress_text)(IAvnProgressBar* self, int32_t* value); /* slot 32 */
    AvnHResult (AVN_CALL *set_show_progress_text)(IAvnProgressBar* self, int32_t value); /* slot 33 */
    AvnHResult (AVN_CALL *get_progress_text_format)(IAvnProgressBar* self, uint16_t** value); /* slot 34 */
    AvnHResult (AVN_CALL *set_progress_text_format)(IAvnProgressBar* self, const uint16_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *get_orientation)(IAvnProgressBar* self, int32_t* value); /* slot 36 */
    AvnHResult (AVN_CALL *set_orientation)(IAvnProgressBar* self, int32_t value); /* slot 37 */
};
struct IAvnProgressBar { const IAvnProgressBarVtbl* vtbl; };
#define I_AVN_PROGRESS_BAR_VTABLE_SLOTS 38

static const AvnGuid I_AVN_RADIO_BUTTON_IID = {
    0xAF4C6114,
    0x15C4,
    0x5073,
    { 0x80, 0x98, 0xD1, 0x3E, 0x46, 0x67, 0x4D, 0x54 }
};
#define I_AVN_RADIO_BUTTON_ABI_VERSION 2
struct IAvnRadioButtonVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnRadioButton* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnRadioButton* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnRadioButton* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnRadioButton* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnRadioButton* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnRadioButton* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnRadioButton* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnRadioButton* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnRadioButton* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnRadioButton* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnRadioButton* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnRadioButton* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnRadioButton* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnRadioButton* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnRadioButton* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnRadioButton* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnRadioButton* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnRadioButton* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_content)(IAvnRadioButton* self, IAvnControl** value); /* slot 18 */
    AvnHResult (AVN_CALL *set_content)(IAvnRadioButton* self, IAvnControl* value); /* slot 19 */
    AvnHResult (AVN_CALL *advise_click)(IAvnRadioButton* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 20 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnRadioButton* self, int64_t subscription_id); /* slot 21 */
    AvnHResult (AVN_CALL *get_is_checked)(IAvnRadioButton* self, int32_t* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_is_checked)(IAvnRadioButton* self, int32_t value); /* slot 23 */
    AvnHResult (AVN_CALL *advise_is_checked_changed)(IAvnRadioButton* self, IAvnToggleButtonIsCheckedChangedHandler* handler, int64_t* subscription_id); /* slot 24 */
    AvnHResult (AVN_CALL *unadvise_is_checked_changed)(IAvnRadioButton* self, int64_t subscription_id); /* slot 25 */
    AvnHResult (AVN_CALL *get_group_name)(IAvnRadioButton* self, uint16_t** value); /* slot 26 */
    AvnHResult (AVN_CALL *set_group_name)(IAvnRadioButton* self, const uint16_t* value); /* slot 27 */
};
struct IAvnRadioButton { const IAvnRadioButtonVtbl* vtbl; };
#define I_AVN_RADIO_BUTTON_VTABLE_SLOTS 28

static const AvnGuid I_AVN_RANGE_BASE_IID = {
    0x19568233,
    0x252A,
    0x5517,
    { 0x87, 0x59, 0x82, 0xA3, 0xC3, 0xA1, 0x56, 0x92 }
};
#define I_AVN_RANGE_BASE_ABI_VERSION 2
struct IAvnRangeBaseVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnRangeBase* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnRangeBase* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnRangeBase* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnRangeBase* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnRangeBase* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnRangeBase* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnRangeBase* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnRangeBase* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnRangeBase* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnRangeBase* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnRangeBase* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnRangeBase* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnRangeBase* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnRangeBase* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnRangeBase* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnRangeBase* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnRangeBase* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnRangeBase* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_minimum)(IAvnRangeBase* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_minimum)(IAvnRangeBase* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_maximum)(IAvnRangeBase* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_maximum)(IAvnRangeBase* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_value)(IAvnRangeBase* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_value)(IAvnRangeBase* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_small_change)(IAvnRangeBase* self, double* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_small_change)(IAvnRangeBase* self, double value); /* slot 25 */
    AvnHResult (AVN_CALL *get_large_change)(IAvnRangeBase* self, double* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_large_change)(IAvnRangeBase* self, double value); /* slot 27 */
    AvnHResult (AVN_CALL *advise_value_changed)(IAvnRangeBase* self, IAvnRangeBaseValueChangedHandler* handler, int64_t* subscription_id); /* slot 28 */
    AvnHResult (AVN_CALL *unadvise_value_changed)(IAvnRangeBase* self, int64_t subscription_id); /* slot 29 */
};
struct IAvnRangeBase { const IAvnRangeBaseVtbl* vtbl; };
#define I_AVN_RANGE_BASE_VTABLE_SLOTS 30

static const AvnGuid I_AVN_SCROLL_VIEWER_IID = {
    0x26F419ED,
    0x02FB,
    0x5AEC,
    { 0x81, 0xDC, 0x7C, 0x15, 0xC5, 0x1D, 0x6A, 0xDB }
};
#define I_AVN_SCROLL_VIEWER_ABI_VERSION 2
struct IAvnScrollViewerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnScrollViewer* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnScrollViewer* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnScrollViewer* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnScrollViewer* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnScrollViewer* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnScrollViewer* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnScrollViewer* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnScrollViewer* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnScrollViewer* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnScrollViewer* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnScrollViewer* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnScrollViewer* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnScrollViewer* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnScrollViewer* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnScrollViewer* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnScrollViewer* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnScrollViewer* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnScrollViewer* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_content)(IAvnScrollViewer* self, IAvnControl** value); /* slot 18 */
    AvnHResult (AVN_CALL *set_content)(IAvnScrollViewer* self, IAvnControl* value); /* slot 19 */
    AvnHResult (AVN_CALL *get_bring_into_view_on_focus_change)(IAvnScrollViewer* self, int32_t* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_bring_into_view_on_focus_change)(IAvnScrollViewer* self, int32_t value); /* slot 21 */
    AvnHResult (AVN_CALL *get_horizontal_scroll_bar_visibility)(IAvnScrollViewer* self, int32_t* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_horizontal_scroll_bar_visibility)(IAvnScrollViewer* self, int32_t value); /* slot 23 */
    AvnHResult (AVN_CALL *get_vertical_scroll_bar_visibility)(IAvnScrollViewer* self, int32_t* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_vertical_scroll_bar_visibility)(IAvnScrollViewer* self, int32_t value); /* slot 25 */
    AvnHResult (AVN_CALL *get_is_expanded)(IAvnScrollViewer* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *get_allow_auto_hide)(IAvnScrollViewer* self, int32_t* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_allow_auto_hide)(IAvnScrollViewer* self, int32_t value); /* slot 28 */
    AvnHResult (AVN_CALL *get_is_scroll_chaining_enabled)(IAvnScrollViewer* self, int32_t* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_is_scroll_chaining_enabled)(IAvnScrollViewer* self, int32_t value); /* slot 30 */
    AvnHResult (AVN_CALL *get_is_scroll_inertia_enabled)(IAvnScrollViewer* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_is_scroll_inertia_enabled)(IAvnScrollViewer* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_is_deferred_scrolling_enabled)(IAvnScrollViewer* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_is_deferred_scrolling_enabled)(IAvnScrollViewer* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *line_up)(IAvnScrollViewer* self); /* slot 35 */
    AvnHResult (AVN_CALL *line_down)(IAvnScrollViewer* self); /* slot 36 */
    AvnHResult (AVN_CALL *line_left)(IAvnScrollViewer* self); /* slot 37 */
    AvnHResult (AVN_CALL *line_right)(IAvnScrollViewer* self); /* slot 38 */
    AvnHResult (AVN_CALL *page_up)(IAvnScrollViewer* self); /* slot 39 */
    AvnHResult (AVN_CALL *page_down)(IAvnScrollViewer* self); /* slot 40 */
    AvnHResult (AVN_CALL *page_left)(IAvnScrollViewer* self); /* slot 41 */
    AvnHResult (AVN_CALL *page_right)(IAvnScrollViewer* self); /* slot 42 */
    AvnHResult (AVN_CALL *scroll_to_home)(IAvnScrollViewer* self); /* slot 43 */
    AvnHResult (AVN_CALL *scroll_to_end)(IAvnScrollViewer* self); /* slot 44 */
    AvnHResult (AVN_CALL *advise_scroll_changed)(IAvnScrollViewer* self, IAvnScrollViewerScrollChangedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_scroll_changed)(IAvnScrollViewer* self, int64_t subscription_id); /* slot 46 */
};
struct IAvnScrollViewer { const IAvnScrollViewerVtbl* vtbl; };
#define I_AVN_SCROLL_VIEWER_VTABLE_SLOTS 47

static const AvnGuid I_AVN_SELECTING_ITEMS_CONTROL_IID = {
    0x248458E4,
    0x051A,
    0x5FAF,
    { 0x8B, 0xC5, 0xD5, 0xDF, 0x74, 0x68, 0xDA, 0xCA }
};
#define I_AVN_SELECTING_ITEMS_CONTROL_ABI_VERSION 2
struct IAvnSelectingItemsControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnSelectingItemsControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnSelectingItemsControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnSelectingItemsControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnSelectingItemsControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnSelectingItemsControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnSelectingItemsControl* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnSelectingItemsControl* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnSelectingItemsControl* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnSelectingItemsControl* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnSelectingItemsControl* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnSelectingItemsControl* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnSelectingItemsControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnSelectingItemsControl* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnSelectingItemsControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnSelectingItemsControl* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnSelectingItemsControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnSelectingItemsControl* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_items)(IAvnSelectingItemsControl* self, IAvnItemList** value); /* slot 18 */
    AvnHResult (AVN_CALL *get_selected_index)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_selected_index)(IAvnSelectingItemsControl* self, int32_t value); /* slot 20 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnSelectingItemsControl* self, IAvnSelectingItemsControlSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 21 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnSelectingItemsControl* self, int64_t subscription_id); /* slot 22 */
};
struct IAvnSelectingItemsControl { const IAvnSelectingItemsControlVtbl* vtbl; };
#define I_AVN_SELECTING_ITEMS_CONTROL_VTABLE_SLOTS 23

static const AvnGuid I_AVN_SLIDER_IID = {
    0x6D529CA4,
    0xC009,
    0x5EDE,
    { 0xA1, 0x48, 0xDC, 0x1B, 0x87, 0x08, 0x28, 0x7A }
};
#define I_AVN_SLIDER_ABI_VERSION 2
struct IAvnSliderVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnSlider* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnSlider* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnSlider* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnSlider* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnSlider* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnSlider* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnSlider* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnSlider* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnSlider* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnSlider* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnSlider* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnSlider* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnSlider* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnSlider* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnSlider* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnSlider* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnSlider* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnSlider* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_minimum)(IAvnSlider* self, double* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_minimum)(IAvnSlider* self, double value); /* slot 19 */
    AvnHResult (AVN_CALL *get_maximum)(IAvnSlider* self, double* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_maximum)(IAvnSlider* self, double value); /* slot 21 */
    AvnHResult (AVN_CALL *get_value)(IAvnSlider* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_value)(IAvnSlider* self, double value); /* slot 23 */
    AvnHResult (AVN_CALL *get_small_change)(IAvnSlider* self, double* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_small_change)(IAvnSlider* self, double value); /* slot 25 */
    AvnHResult (AVN_CALL *get_large_change)(IAvnSlider* self, double* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_large_change)(IAvnSlider* self, double value); /* slot 27 */
    AvnHResult (AVN_CALL *advise_value_changed)(IAvnSlider* self, IAvnRangeBaseValueChangedHandler* handler, int64_t* subscription_id); /* slot 28 */
    AvnHResult (AVN_CALL *unadvise_value_changed)(IAvnSlider* self, int64_t subscription_id); /* slot 29 */
    AvnHResult (AVN_CALL *get_orientation)(IAvnSlider* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_orientation)(IAvnSlider* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *get_is_direction_reversed)(IAvnSlider* self, int32_t* value); /* slot 32 */
    AvnHResult (AVN_CALL *set_is_direction_reversed)(IAvnSlider* self, int32_t value); /* slot 33 */
    AvnHResult (AVN_CALL *get_is_snap_to_tick_enabled)(IAvnSlider* self, int32_t* value); /* slot 34 */
    AvnHResult (AVN_CALL *set_is_snap_to_tick_enabled)(IAvnSlider* self, int32_t value); /* slot 35 */
    AvnHResult (AVN_CALL *get_tick_frequency)(IAvnSlider* self, double* value); /* slot 36 */
    AvnHResult (AVN_CALL *set_tick_frequency)(IAvnSlider* self, double value); /* slot 37 */
    AvnHResult (AVN_CALL *get_tick_placement)(IAvnSlider* self, int32_t* value); /* slot 38 */
    AvnHResult (AVN_CALL *set_tick_placement)(IAvnSlider* self, int32_t value); /* slot 39 */
};
struct IAvnSlider { const IAvnSliderVtbl* vtbl; };
#define I_AVN_SLIDER_VTABLE_SLOTS 40

static const AvnGuid I_AVN_STACK_PANEL_IID = {
    0xEF25BE3E,
    0x33CD,
    0x5FA1,
    { 0xB1, 0x15, 0x37, 0x5C, 0xC2, 0xFC, 0x01, 0xCB }
};
#define I_AVN_STACK_PANEL_ABI_VERSION 2
struct IAvnStackPanelVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnStackPanel* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnStackPanel* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnStackPanel* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnStackPanel* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnStackPanel* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnStackPanel* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnStackPanel* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnStackPanel* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnStackPanel* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnStackPanel* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnStackPanel* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnStackPanel* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnStackPanel* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnStackPanel* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnStackPanel* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnStackPanel* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnStackPanel* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnStackPanel* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_children)(IAvnStackPanel* self, IAvnControlList** value); /* slot 18 */
    AvnHResult (AVN_CALL *get_spacing)(IAvnStackPanel* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_spacing)(IAvnStackPanel* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_orientation)(IAvnStackPanel* self, int32_t* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_orientation)(IAvnStackPanel* self, int32_t value); /* slot 22 */
};
struct IAvnStackPanel { const IAvnStackPanelVtbl* vtbl; };
#define I_AVN_STACK_PANEL_VTABLE_SLOTS 23

static const AvnGuid I_AVN_STYLED_ELEMENT_IID = {
    0xFFC4634F,
    0xD15C,
    0x5549,
    { 0xB8, 0x1E, 0x4A, 0x63, 0x85, 0xE1, 0x83, 0x83 }
};
#define I_AVN_STYLED_ELEMENT_ABI_VERSION 2
struct IAvnStyledElementVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnStyledElement* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnStyledElement* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnStyledElement* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnStyledElement* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnStyledElement* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnStyledElement* self, IAvnStringList** value); /* slot 5 */
};
struct IAvnStyledElement { const IAvnStyledElementVtbl* vtbl; };
#define I_AVN_STYLED_ELEMENT_VTABLE_SLOTS 6

static const AvnGuid I_AVN_TEMPLATED_CONTROL_IID = {
    0xC2E11540,
    0x6DFA,
    0x5130,
    { 0xB1, 0xF5, 0x47, 0xD9, 0xB2, 0xBF, 0x67, 0xC0 }
};
#define I_AVN_TEMPLATED_CONTROL_ABI_VERSION 2
struct IAvnTemplatedControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTemplatedControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTemplatedControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTemplatedControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnTemplatedControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnTemplatedControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnTemplatedControl* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnTemplatedControl* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnTemplatedControl* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnTemplatedControl* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnTemplatedControl* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTemplatedControl* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTemplatedControl* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTemplatedControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTemplatedControl* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTemplatedControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTemplatedControl* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTemplatedControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTemplatedControl* self, int64_t subscription_id); /* slot 17 */
};
struct IAvnTemplatedControl { const IAvnTemplatedControlVtbl* vtbl; };
#define I_AVN_TEMPLATED_CONTROL_VTABLE_SLOTS 18

static const AvnGuid I_AVN_TEXT_BLOCK_IID = {
    0x491DC967,
    0x7C00,
    0x5692,
    { 0x94, 0x7D, 0xC8, 0x04, 0x61, 0xF4, 0x98, 0x63 }
};
#define I_AVN_TEXT_BLOCK_ABI_VERSION 2
struct IAvnTextBlockVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTextBlock* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTextBlock* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTextBlock* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnTextBlock* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnTextBlock* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnTextBlock* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnTextBlock* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnTextBlock* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnTextBlock* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnTextBlock* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTextBlock* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTextBlock* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTextBlock* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTextBlock* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTextBlock* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTextBlock* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTextBlock* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTextBlock* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_text)(IAvnTextBlock* self, uint16_t** value); /* slot 18 */
    AvnHResult (AVN_CALL *set_text)(IAvnTextBlock* self, const uint16_t* value); /* slot 19 */
};
struct IAvnTextBlock { const IAvnTextBlockVtbl* vtbl; };
#define I_AVN_TEXT_BLOCK_VTABLE_SLOTS 20

static const AvnGuid I_AVN_TEXT_BOX_IID = {
    0x6D239DFB,
    0x3EDD,
    0x59D5,
    { 0xB1, 0x80, 0xE7, 0xF2, 0xDA, 0xFE, 0xF1, 0x36 }
};
#define I_AVN_TEXT_BOX_ABI_VERSION 2
struct IAvnTextBoxVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTextBox* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTextBox* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTextBox* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnTextBox* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnTextBox* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnTextBox* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnTextBox* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnTextBox* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnTextBox* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnTextBox* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTextBox* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTextBox* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTextBox* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTextBox* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTextBox* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTextBox* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTextBox* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTextBox* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_accepts_return)(IAvnTextBox* self, int32_t* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_accepts_return)(IAvnTextBox* self, int32_t value); /* slot 19 */
    AvnHResult (AVN_CALL *get_accepts_tab)(IAvnTextBox* self, int32_t* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_accepts_tab)(IAvnTextBox* self, int32_t value); /* slot 21 */
    AvnHResult (AVN_CALL *get_caret_index)(IAvnTextBox* self, int32_t* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_caret_index)(IAvnTextBox* self, int32_t value); /* slot 23 */
    AvnHResult (AVN_CALL *get_is_read_only)(IAvnTextBox* self, int32_t* value); /* slot 24 */
    AvnHResult (AVN_CALL *set_is_read_only)(IAvnTextBox* self, int32_t value); /* slot 25 */
    AvnHResult (AVN_CALL *get_selection_start)(IAvnTextBox* self, int32_t* value); /* slot 26 */
    AvnHResult (AVN_CALL *set_selection_start)(IAvnTextBox* self, int32_t value); /* slot 27 */
    AvnHResult (AVN_CALL *get_selection_end)(IAvnTextBox* self, int32_t* value); /* slot 28 */
    AvnHResult (AVN_CALL *set_selection_end)(IAvnTextBox* self, int32_t value); /* slot 29 */
    AvnHResult (AVN_CALL *get_max_length)(IAvnTextBox* self, int32_t* value); /* slot 30 */
    AvnHResult (AVN_CALL *set_max_length)(IAvnTextBox* self, int32_t value); /* slot 31 */
    AvnHResult (AVN_CALL *get_max_lines)(IAvnTextBox* self, int32_t* value); /* slot 32 */
    AvnHResult (AVN_CALL *set_max_lines)(IAvnTextBox* self, int32_t value); /* slot 33 */
    AvnHResult (AVN_CALL *get_min_lines)(IAvnTextBox* self, int32_t* value); /* slot 34 */
    AvnHResult (AVN_CALL *set_min_lines)(IAvnTextBox* self, int32_t value); /* slot 35 */
    AvnHResult (AVN_CALL *get_line_height)(IAvnTextBox* self, double* value); /* slot 36 */
    AvnHResult (AVN_CALL *set_line_height)(IAvnTextBox* self, double value); /* slot 37 */
    AvnHResult (AVN_CALL *get_text)(IAvnTextBox* self, uint16_t** value); /* slot 38 */
    AvnHResult (AVN_CALL *set_text)(IAvnTextBox* self, const uint16_t* value); /* slot 39 */
    AvnHResult (AVN_CALL *get_placeholder_text)(IAvnTextBox* self, uint16_t** value); /* slot 40 */
    AvnHResult (AVN_CALL *set_placeholder_text)(IAvnTextBox* self, const uint16_t* value); /* slot 41 */
    AvnHResult (AVN_CALL *get_reveal_password)(IAvnTextBox* self, int32_t* value); /* slot 42 */
    AvnHResult (AVN_CALL *set_reveal_password)(IAvnTextBox* self, int32_t value); /* slot 43 */
    AvnHResult (AVN_CALL *get_text_wrapping)(IAvnTextBox* self, int32_t* value); /* slot 44 */
    AvnHResult (AVN_CALL *set_text_wrapping)(IAvnTextBox* self, int32_t value); /* slot 45 */
    AvnHResult (AVN_CALL *get_new_line)(IAvnTextBox* self, uint16_t** value); /* slot 46 */
    AvnHResult (AVN_CALL *set_new_line)(IAvnTextBox* self, const uint16_t* value); /* slot 47 */
    AvnHResult (AVN_CALL *get_can_cut)(IAvnTextBox* self, int32_t* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_can_copy)(IAvnTextBox* self, int32_t* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_can_paste)(IAvnTextBox* self, int32_t* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_is_undo_enabled)(IAvnTextBox* self, int32_t* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_is_undo_enabled)(IAvnTextBox* self, int32_t value); /* slot 52 */
    AvnHResult (AVN_CALL *get_undo_limit)(IAvnTextBox* self, int32_t* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_undo_limit)(IAvnTextBox* self, int32_t value); /* slot 54 */
    AvnHResult (AVN_CALL *get_can_undo)(IAvnTextBox* self, int32_t* value); /* slot 55 */
    AvnHResult (AVN_CALL *get_can_redo)(IAvnTextBox* self, int32_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *cut)(IAvnTextBox* self); /* slot 57 */
    AvnHResult (AVN_CALL *copy)(IAvnTextBox* self); /* slot 58 */
    AvnHResult (AVN_CALL *paste)(IAvnTextBox* self); /* slot 59 */
    AvnHResult (AVN_CALL *clear)(IAvnTextBox* self); /* slot 60 */
    AvnHResult (AVN_CALL *undo)(IAvnTextBox* self); /* slot 61 */
    AvnHResult (AVN_CALL *redo)(IAvnTextBox* self); /* slot 62 */
    AvnHResult (AVN_CALL *advise_text_changed)(IAvnTextBox* self, IAvnTextBoxTextChangedHandler* handler, int64_t* subscription_id); /* slot 63 */
    AvnHResult (AVN_CALL *unadvise_text_changed)(IAvnTextBox* self, int64_t subscription_id); /* slot 64 */
};
struct IAvnTextBox { const IAvnTextBoxVtbl* vtbl; };
#define I_AVN_TEXT_BOX_VTABLE_SLOTS 65

static const AvnGuid I_AVN_TOGGLE_BUTTON_IID = {
    0xAB096AE3,
    0xC4DF,
    0x5512,
    { 0xB1, 0xDE, 0x7A, 0x1D, 0x1A, 0x3F, 0x8C, 0xA9 }
};
#define I_AVN_TOGGLE_BUTTON_ABI_VERSION 2
struct IAvnToggleButtonVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnToggleButton* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnToggleButton* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnToggleButton* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnToggleButton* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnToggleButton* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnToggleButton* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnToggleButton* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnToggleButton* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnToggleButton* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnToggleButton* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnToggleButton* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnToggleButton* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnToggleButton* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnToggleButton* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnToggleButton* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnToggleButton* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnToggleButton* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnToggleButton* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_content)(IAvnToggleButton* self, IAvnControl** value); /* slot 18 */
    AvnHResult (AVN_CALL *set_content)(IAvnToggleButton* self, IAvnControl* value); /* slot 19 */
    AvnHResult (AVN_CALL *advise_click)(IAvnToggleButton* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 20 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnToggleButton* self, int64_t subscription_id); /* slot 21 */
    AvnHResult (AVN_CALL *get_is_checked)(IAvnToggleButton* self, int32_t* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_is_checked)(IAvnToggleButton* self, int32_t value); /* slot 23 */
    AvnHResult (AVN_CALL *advise_is_checked_changed)(IAvnToggleButton* self, IAvnToggleButtonIsCheckedChangedHandler* handler, int64_t* subscription_id); /* slot 24 */
    AvnHResult (AVN_CALL *unadvise_is_checked_changed)(IAvnToggleButton* self, int64_t subscription_id); /* slot 25 */
};
struct IAvnToggleButton { const IAvnToggleButtonVtbl* vtbl; };
#define I_AVN_TOGGLE_BUTTON_VTABLE_SLOTS 26

static const AvnGuid I_AVN_TOGGLE_SWITCH_IID = {
    0xF7FEE989,
    0x88FE,
    0x5957,
    { 0x93, 0x41, 0x21, 0xF7, 0x50, 0xE1, 0xA9, 0x40 }
};
#define I_AVN_TOGGLE_SWITCH_ABI_VERSION 2
struct IAvnToggleSwitchVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnToggleSwitch* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnToggleSwitch* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnToggleSwitch* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnToggleSwitch* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnToggleSwitch* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnToggleSwitch* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnToggleSwitch* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnToggleSwitch* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnToggleSwitch* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnToggleSwitch* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnToggleSwitch* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnToggleSwitch* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnToggleSwitch* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnToggleSwitch* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnToggleSwitch* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnToggleSwitch* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnToggleSwitch* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnToggleSwitch* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_content)(IAvnToggleSwitch* self, IAvnControl** value); /* slot 18 */
    AvnHResult (AVN_CALL *set_content)(IAvnToggleSwitch* self, IAvnControl* value); /* slot 19 */
    AvnHResult (AVN_CALL *advise_click)(IAvnToggleSwitch* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 20 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnToggleSwitch* self, int64_t subscription_id); /* slot 21 */
    AvnHResult (AVN_CALL *get_is_checked)(IAvnToggleSwitch* self, int32_t* value); /* slot 22 */
    AvnHResult (AVN_CALL *set_is_checked)(IAvnToggleSwitch* self, int32_t value); /* slot 23 */
    AvnHResult (AVN_CALL *advise_is_checked_changed)(IAvnToggleSwitch* self, IAvnToggleButtonIsCheckedChangedHandler* handler, int64_t* subscription_id); /* slot 24 */
    AvnHResult (AVN_CALL *unadvise_is_checked_changed)(IAvnToggleSwitch* self, int64_t subscription_id); /* slot 25 */
    AvnHResult (AVN_CALL *get_on_content)(IAvnToggleSwitch* self, IAvnControl** value); /* slot 26 */
    AvnHResult (AVN_CALL *set_on_content)(IAvnToggleSwitch* self, IAvnControl* value); /* slot 27 */
    AvnHResult (AVN_CALL *get_off_content)(IAvnToggleSwitch* self, IAvnControl** value); /* slot 28 */
    AvnHResult (AVN_CALL *set_off_content)(IAvnToggleSwitch* self, IAvnControl* value); /* slot 29 */
};
struct IAvnToggleSwitch { const IAvnToggleSwitchVtbl* vtbl; };
#define I_AVN_TOGGLE_SWITCH_VTABLE_SLOTS 30

static const AvnGuid I_AVN_WINDOW_IID = {
    0x0EF99637,
    0x5CA4,
    0x5C5D,
    { 0xAC, 0xB7, 0x54, 0x6C, 0xBA, 0x81, 0x4D, 0xD9 }
};
#define I_AVN_WINDOW_ABI_VERSION 2
struct IAvnWindowVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnWindow* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnWindow* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnWindow* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnWindow* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnWindow* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_classes)(IAvnWindow* self, IAvnStringList** value); /* slot 5 */
    AvnHResult (AVN_CALL *get_width)(IAvnWindow* self, double* value); /* slot 6 */
    AvnHResult (AVN_CALL *set_width)(IAvnWindow* self, double value); /* slot 7 */
    AvnHResult (AVN_CALL *get_height)(IAvnWindow* self, double* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_height)(IAvnWindow* self, double value); /* slot 9 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnWindow* self, int32_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnWindow* self, int32_t value); /* slot 11 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnWindow* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnWindow* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnWindow* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 14 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnWindow* self, int64_t subscription_id); /* slot 15 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnWindow* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 16 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnWindow* self, int64_t subscription_id); /* slot 17 */
    AvnHResult (AVN_CALL *get_content)(IAvnWindow* self, IAvnControl** value); /* slot 18 */
    AvnHResult (AVN_CALL *set_content)(IAvnWindow* self, IAvnControl* value); /* slot 19 */
    AvnHResult (AVN_CALL *get_title)(IAvnWindow* self, uint16_t** value); /* slot 20 */
    AvnHResult (AVN_CALL *set_title)(IAvnWindow* self, const uint16_t* value); /* slot 21 */
    AvnHResult (AVN_CALL *close)(IAvnWindow* self); /* slot 22 */
    AvnHResult (AVN_CALL *show)(IAvnWindow* self); /* slot 23 */
    AvnHResult (AVN_CALL *show_with_window)(IAvnWindow* self, IAvnWindow* owner); /* slot 24 */
};
struct IAvnWindow { const IAvnWindowVtbl* vtbl; };
#define I_AVN_WINDOW_VTABLE_SLOTS 25

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
    0x91404D32,
    0x3815,
    0x5EC7,
    { 0xBA, 0x4B, 0x6C, 0xDC, 0xD2, 0xED, 0x9D, 0xD9 }
};
#define I_AVN_CONTROL_FACTORY_ABI_VERSION 1
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
};
struct IAvnControlFactory { const IAvnControlFactoryVtbl* vtbl; };
#define I_AVN_CONTROL_FACTORY_VTABLE_SLOTS 37

#endif /* AVALONIA_RUST_ABI_H */
