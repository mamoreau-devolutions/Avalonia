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

/* Nullable ABI wrapper of AvnThickness. has_value is 0 or 1. */
typedef struct AvnOptionalThickness {
    int32_t has_value;
    AvnThickness value;
} AvnOptionalThickness;

/* Blittable ABI mirror of Avalonia.CornerRadius. */
typedef struct AvnCornerRadius {
    double top_left;
    double top_right;
    double bottom_right;
    double bottom_left;
} AvnCornerRadius;

/* Nullable ABI wrapper of AvnCornerRadius. has_value is 0 or 1. */
typedef struct AvnOptionalCornerRadius {
    int32_t has_value;
    AvnCornerRadius value;
} AvnOptionalCornerRadius;

/* Blittable ABI mirror of Avalonia.Size. */
typedef struct AvnSize {
    double width;
    double height;
} AvnSize;

/* Nullable ABI wrapper of AvnSize. has_value is 0 or 1. */
typedef struct AvnOptionalSize {
    int32_t has_value;
    AvnSize value;
} AvnOptionalSize;

/* Blittable ABI mirror of Avalonia.Point. */
typedef struct AvnPoint {
    double x;
    double y;
} AvnPoint;

/* Nullable ABI wrapper of AvnPoint. has_value is 0 or 1. */
typedef struct AvnOptionalPoint {
    int32_t has_value;
    AvnPoint value;
} AvnOptionalPoint;

/* Blittable ABI mirror of Avalonia.Rect. */
typedef struct AvnRect {
    double x;
    double y;
    double width;
    double height;
} AvnRect;

/* Nullable ABI wrapper of AvnRect. has_value is 0 or 1. */
typedef struct AvnOptionalRect {
    int32_t has_value;
    AvnRect value;
} AvnOptionalRect;

/* Blittable ABI mirror of Avalonia.Media.Color. */
typedef struct AvnColor {
    uint32_t argb;
} AvnColor;

/* Nullable ABI wrapper of AvnColor. has_value is 0 or 1. */
typedef struct AvnOptionalColor {
    int32_t has_value;
    AvnColor value;
} AvnOptionalColor;

/* Blittable ABI mirror of Avalonia.Vector. */
typedef struct AvnVector {
    double x;
    double y;
} AvnVector;

/* Nullable ABI wrapper of AvnVector. has_value is 0 or 1. */
typedef struct AvnOptionalVector {
    int32_t has_value;
    AvnVector value;
} AvnOptionalVector;

/* Tagged scalar carrying object? command parameters. */
/* tag: 0 none, 1 utf16, 2 i32, 3 f64, 4 bool. */
typedef struct AvnVariant {
    int32_t tag;
    const uint16_t* utf16;
    int32_t i32;
    double f64;
} AvnVariant;

typedef struct IAvnArc IAvnArc;
typedef struct IAvnArcVtbl IAvnArcVtbl;
typedef struct IAvnAutoCompleteBox IAvnAutoCompleteBox;
typedef struct IAvnAutoCompleteBoxVtbl IAvnAutoCompleteBoxVtbl;
typedef struct IAvnAutoCompleteBoxDropDownClosedHandler IAvnAutoCompleteBoxDropDownClosedHandler;
typedef struct IAvnAutoCompleteBoxDropDownClosedHandlerVtbl IAvnAutoCompleteBoxDropDownClosedHandlerVtbl;
typedef struct IAvnAutoCompleteBoxDropDownClosingHandler IAvnAutoCompleteBoxDropDownClosingHandler;
typedef struct IAvnAutoCompleteBoxDropDownClosingHandlerVtbl IAvnAutoCompleteBoxDropDownClosingHandlerVtbl;
typedef struct IAvnAutoCompleteBoxDropDownOpenedHandler IAvnAutoCompleteBoxDropDownOpenedHandler;
typedef struct IAvnAutoCompleteBoxDropDownOpenedHandlerVtbl IAvnAutoCompleteBoxDropDownOpenedHandlerVtbl;
typedef struct IAvnAutoCompleteBoxDropDownOpeningHandler IAvnAutoCompleteBoxDropDownOpeningHandler;
typedef struct IAvnAutoCompleteBoxDropDownOpeningHandlerVtbl IAvnAutoCompleteBoxDropDownOpeningHandlerVtbl;
typedef struct IAvnAutoCompleteBoxPopulatingHandler IAvnAutoCompleteBoxPopulatingHandler;
typedef struct IAvnAutoCompleteBoxPopulatingHandlerVtbl IAvnAutoCompleteBoxPopulatingHandlerVtbl;
typedef struct IAvnAutoCompleteBoxTextChangedHandler IAvnAutoCompleteBoxTextChangedHandler;
typedef struct IAvnAutoCompleteBoxTextChangedHandlerVtbl IAvnAutoCompleteBoxTextChangedHandlerVtbl;
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
typedef struct IAvnButtonSpinner IAvnButtonSpinner;
typedef struct IAvnButtonSpinnerVtbl IAvnButtonSpinnerVtbl;
typedef struct IAvnCalendar IAvnCalendar;
typedef struct IAvnCalendarVtbl IAvnCalendarVtbl;
typedef struct IAvnCalendarDatePicker IAvnCalendarDatePicker;
typedef struct IAvnCalendarDatePickerVtbl IAvnCalendarDatePickerVtbl;
typedef struct IAvnCalendarDatePickerCalendarClosedHandler IAvnCalendarDatePickerCalendarClosedHandler;
typedef struct IAvnCalendarDatePickerCalendarClosedHandlerVtbl IAvnCalendarDatePickerCalendarClosedHandlerVtbl;
typedef struct IAvnCalendarDatePickerCalendarOpenedHandler IAvnCalendarDatePickerCalendarOpenedHandler;
typedef struct IAvnCalendarDatePickerCalendarOpenedHandlerVtbl IAvnCalendarDatePickerCalendarOpenedHandlerVtbl;
typedef struct IAvnCanvas IAvnCanvas;
typedef struct IAvnCanvasVtbl IAvnCanvasVtbl;
typedef struct IAvnCanvasStatics IAvnCanvasStatics;
typedef struct IAvnCanvasStaticsVtbl IAvnCanvasStaticsVtbl;
typedef struct IAvnCarousel IAvnCarousel;
typedef struct IAvnCarouselVtbl IAvnCarouselVtbl;
typedef struct IAvnCheckBox IAvnCheckBox;
typedef struct IAvnCheckBoxVtbl IAvnCheckBoxVtbl;
typedef struct IAvnComboBox IAvnComboBox;
typedef struct IAvnComboBoxVtbl IAvnComboBoxVtbl;
typedef struct IAvnComboBoxDropDownClosedHandler IAvnComboBoxDropDownClosedHandler;
typedef struct IAvnComboBoxDropDownClosedHandlerVtbl IAvnComboBoxDropDownClosedHandlerVtbl;
typedef struct IAvnComboBoxDropDownOpenedHandler IAvnComboBoxDropDownOpenedHandler;
typedef struct IAvnComboBoxDropDownOpenedHandlerVtbl IAvnComboBoxDropDownOpenedHandlerVtbl;
typedef struct IAvnComboBoxItem IAvnComboBoxItem;
typedef struct IAvnComboBoxItemVtbl IAvnComboBoxItemVtbl;
typedef struct IAvnCommand IAvnCommand;
typedef struct IAvnCommandVtbl IAvnCommandVtbl;
typedef struct IAvnCommandBar IAvnCommandBar;
typedef struct IAvnCommandBarVtbl IAvnCommandBarVtbl;
typedef struct IAvnCommandBarButton IAvnCommandBarButton;
typedef struct IAvnCommandBarButtonVtbl IAvnCommandBarButtonVtbl;
typedef struct IAvnCommandBarClosedHandler IAvnCommandBarClosedHandler;
typedef struct IAvnCommandBarClosedHandlerVtbl IAvnCommandBarClosedHandlerVtbl;
typedef struct IAvnCommandBarClosingHandler IAvnCommandBarClosingHandler;
typedef struct IAvnCommandBarClosingHandlerVtbl IAvnCommandBarClosingHandlerVtbl;
typedef struct IAvnCommandBarOpenedHandler IAvnCommandBarOpenedHandler;
typedef struct IAvnCommandBarOpenedHandlerVtbl IAvnCommandBarOpenedHandlerVtbl;
typedef struct IAvnCommandBarOpeningHandler IAvnCommandBarOpeningHandler;
typedef struct IAvnCommandBarOpeningHandlerVtbl IAvnCommandBarOpeningHandlerVtbl;
typedef struct IAvnCommandBarSeparator IAvnCommandBarSeparator;
typedef struct IAvnCommandBarSeparatorVtbl IAvnCommandBarSeparatorVtbl;
typedef struct IAvnCommandBarToggleButton IAvnCommandBarToggleButton;
typedef struct IAvnCommandBarToggleButtonVtbl IAvnCommandBarToggleButtonVtbl;
typedef struct IAvnCommandCanExecuteChangedHandler IAvnCommandCanExecuteChangedHandler;
typedef struct IAvnCommandCanExecuteChangedHandlerVtbl IAvnCommandCanExecuteChangedHandlerVtbl;
typedef struct IAvnContentControl IAvnContentControl;
typedef struct IAvnContentControlVtbl IAvnContentControlVtbl;
typedef struct IAvnContextMenu IAvnContextMenu;
typedef struct IAvnContextMenuVtbl IAvnContextMenuVtbl;
typedef struct IAvnContextMenuClosingHandler IAvnContextMenuClosingHandler;
typedef struct IAvnContextMenuClosingHandlerVtbl IAvnContextMenuClosingHandlerVtbl;
typedef struct IAvnContextMenuOpeningHandler IAvnContextMenuOpeningHandler;
typedef struct IAvnContextMenuOpeningHandlerVtbl IAvnContextMenuOpeningHandlerVtbl;
typedef struct IAvnControl IAvnControl;
typedef struct IAvnControlVtbl IAvnControlVtbl;
typedef struct IAvnControlFactory IAvnControlFactory;
typedef struct IAvnControlFactoryVtbl IAvnControlFactoryVtbl;
typedef struct IAvnControlKeyDownHandler IAvnControlKeyDownHandler;
typedef struct IAvnControlKeyDownHandlerVtbl IAvnControlKeyDownHandlerVtbl;
typedef struct IAvnControlList IAvnControlList;
typedef struct IAvnControlListVtbl IAvnControlListVtbl;
typedef struct IAvnControlLoadedHandler IAvnControlLoadedHandler;
typedef struct IAvnControlLoadedHandlerVtbl IAvnControlLoadedHandlerVtbl;
typedef struct IAvnControlPointerEnteredHandler IAvnControlPointerEnteredHandler;
typedef struct IAvnControlPointerEnteredHandlerVtbl IAvnControlPointerEnteredHandlerVtbl;
typedef struct IAvnControlPointerExitedHandler IAvnControlPointerExitedHandler;
typedef struct IAvnControlPointerExitedHandlerVtbl IAvnControlPointerExitedHandlerVtbl;
typedef struct IAvnControlUnloadedHandler IAvnControlUnloadedHandler;
typedef struct IAvnControlUnloadedHandlerVtbl IAvnControlUnloadedHandlerVtbl;
typedef struct IAvnDatePicker IAvnDatePicker;
typedef struct IAvnDatePickerVtbl IAvnDatePickerVtbl;
typedef struct IAvnDecorator IAvnDecorator;
typedef struct IAvnDecoratorVtbl IAvnDecoratorVtbl;
typedef struct IAvnDockPanel IAvnDockPanel;
typedef struct IAvnDockPanelVtbl IAvnDockPanelVtbl;
typedef struct IAvnDockPanelStatics IAvnDockPanelStatics;
typedef struct IAvnDockPanelStaticsVtbl IAvnDockPanelStaticsVtbl;
typedef struct IAvnDropDownButton IAvnDropDownButton;
typedef struct IAvnDropDownButtonVtbl IAvnDropDownButtonVtbl;
typedef struct IAvnEllipse IAvnEllipse;
typedef struct IAvnEllipseVtbl IAvnEllipseVtbl;
typedef struct IAvnExpander IAvnExpander;
typedef struct IAvnExpanderVtbl IAvnExpanderVtbl;
typedef struct IAvnExpanderCollapsedHandler IAvnExpanderCollapsedHandler;
typedef struct IAvnExpanderCollapsedHandlerVtbl IAvnExpanderCollapsedHandlerVtbl;
typedef struct IAvnExpanderExpandedHandler IAvnExpanderExpandedHandler;
typedef struct IAvnExpanderExpandedHandlerVtbl IAvnExpanderExpandedHandlerVtbl;
typedef struct IAvnFlexPanel IAvnFlexPanel;
typedef struct IAvnFlexPanelVtbl IAvnFlexPanelVtbl;
typedef struct IAvnFlyout IAvnFlyout;
typedef struct IAvnFlyoutVtbl IAvnFlyoutVtbl;
typedef struct IAvnFlyoutBase IAvnFlyoutBase;
typedef struct IAvnFlyoutBaseVtbl IAvnFlyoutBaseVtbl;
typedef struct IAvnFlyoutBaseClosedHandler IAvnFlyoutBaseClosedHandler;
typedef struct IAvnFlyoutBaseClosedHandlerVtbl IAvnFlyoutBaseClosedHandlerVtbl;
typedef struct IAvnFlyoutBaseOpenedHandler IAvnFlyoutBaseOpenedHandler;
typedef struct IAvnFlyoutBaseOpenedHandlerVtbl IAvnFlyoutBaseOpenedHandlerVtbl;
typedef struct IAvnGrid IAvnGrid;
typedef struct IAvnGridVtbl IAvnGridVtbl;
typedef struct IAvnGridSplitter IAvnGridSplitter;
typedef struct IAvnGridSplitterVtbl IAvnGridSplitterVtbl;
typedef struct IAvnGridStatics IAvnGridStatics;
typedef struct IAvnGridStaticsVtbl IAvnGridStaticsVtbl;
typedef struct IAvnGroupBox IAvnGroupBox;
typedef struct IAvnGroupBoxVtbl IAvnGroupBoxVtbl;
typedef struct IAvnHeaderedContentControl IAvnHeaderedContentControl;
typedef struct IAvnHeaderedContentControlVtbl IAvnHeaderedContentControlVtbl;
typedef struct IAvnHeaderedItemsControl IAvnHeaderedItemsControl;
typedef struct IAvnHeaderedItemsControlVtbl IAvnHeaderedItemsControlVtbl;
typedef struct IAvnHeaderedSelectingItemsControl IAvnHeaderedSelectingItemsControl;
typedef struct IAvnHeaderedSelectingItemsControlVtbl IAvnHeaderedSelectingItemsControlVtbl;
typedef struct IAvnHyperlinkButton IAvnHyperlinkButton;
typedef struct IAvnHyperlinkButtonVtbl IAvnHyperlinkButtonVtbl;
typedef struct IAvnIconElement IAvnIconElement;
typedef struct IAvnIconElementVtbl IAvnIconElementVtbl;
typedef struct IAvnImage IAvnImage;
typedef struct IAvnImageVtbl IAvnImageVtbl;
typedef struct IAvnItemList IAvnItemList;
typedef struct IAvnItemListVtbl IAvnItemListVtbl;
typedef struct IAvnItemsControl IAvnItemsControl;
typedef struct IAvnItemsControlVtbl IAvnItemsControlVtbl;
typedef struct IAvnLabel IAvnLabel;
typedef struct IAvnLabelVtbl IAvnLabelVtbl;
typedef struct IAvnLayoutTransformControl IAvnLayoutTransformControl;
typedef struct IAvnLayoutTransformControlVtbl IAvnLayoutTransformControlVtbl;
typedef struct IAvnLine IAvnLine;
typedef struct IAvnLineVtbl IAvnLineVtbl;
typedef struct IAvnListBox IAvnListBox;
typedef struct IAvnListBoxVtbl IAvnListBoxVtbl;
typedef struct IAvnListBoxItem IAvnListBoxItem;
typedef struct IAvnListBoxItemVtbl IAvnListBoxItemVtbl;
typedef struct IAvnMaskedTextBox IAvnMaskedTextBox;
typedef struct IAvnMaskedTextBoxVtbl IAvnMaskedTextBoxVtbl;
typedef struct IAvnMenu IAvnMenu;
typedef struct IAvnMenuVtbl IAvnMenuVtbl;
typedef struct IAvnMenuBase IAvnMenuBase;
typedef struct IAvnMenuBaseVtbl IAvnMenuBaseVtbl;
typedef struct IAvnMenuBaseClosedHandler IAvnMenuBaseClosedHandler;
typedef struct IAvnMenuBaseClosedHandlerVtbl IAvnMenuBaseClosedHandlerVtbl;
typedef struct IAvnMenuBaseOpenedHandler IAvnMenuBaseOpenedHandler;
typedef struct IAvnMenuBaseOpenedHandlerVtbl IAvnMenuBaseOpenedHandlerVtbl;
typedef struct IAvnMenuFlyout IAvnMenuFlyout;
typedef struct IAvnMenuFlyoutVtbl IAvnMenuFlyoutVtbl;
typedef struct IAvnMenuItem IAvnMenuItem;
typedef struct IAvnMenuItemVtbl IAvnMenuItemVtbl;
typedef struct IAvnMenuItemClickHandler IAvnMenuItemClickHandler;
typedef struct IAvnMenuItemClickHandlerVtbl IAvnMenuItemClickHandlerVtbl;
typedef struct IAvnMenuItemSubmenuOpenedHandler IAvnMenuItemSubmenuOpenedHandler;
typedef struct IAvnMenuItemSubmenuOpenedHandlerVtbl IAvnMenuItemSubmenuOpenedHandlerVtbl;
typedef struct IAvnNotificationCard IAvnNotificationCard;
typedef struct IAvnNotificationCardVtbl IAvnNotificationCardVtbl;
typedef struct IAvnNumericUpDown IAvnNumericUpDown;
typedef struct IAvnNumericUpDownVtbl IAvnNumericUpDownVtbl;
typedef struct IAvnNumericUpDownValueChangedHandler IAvnNumericUpDownValueChangedHandler;
typedef struct IAvnNumericUpDownValueChangedHandlerVtbl IAvnNumericUpDownValueChangedHandlerVtbl;
typedef struct IAvnPanel IAvnPanel;
typedef struct IAvnPanelVtbl IAvnPanelVtbl;
typedef struct IAvnPath IAvnPath;
typedef struct IAvnPathVtbl IAvnPathVtbl;
typedef struct IAvnPathIcon IAvnPathIcon;
typedef struct IAvnPathIconVtbl IAvnPathIconVtbl;
typedef struct IAvnPipsPager IAvnPipsPager;
typedef struct IAvnPipsPagerVtbl IAvnPipsPagerVtbl;
typedef struct IAvnPipsPagerSelectedIndexChangedHandler IAvnPipsPagerSelectedIndexChangedHandler;
typedef struct IAvnPipsPagerSelectedIndexChangedHandlerVtbl IAvnPipsPagerSelectedIndexChangedHandlerVtbl;
typedef struct IAvnPolygon IAvnPolygon;
typedef struct IAvnPolygonVtbl IAvnPolygonVtbl;
typedef struct IAvnPolyline IAvnPolyline;
typedef struct IAvnPolylineVtbl IAvnPolylineVtbl;
typedef struct IAvnPopup IAvnPopup;
typedef struct IAvnPopupVtbl IAvnPopupVtbl;
typedef struct IAvnPopupClosedHandler IAvnPopupClosedHandler;
typedef struct IAvnPopupClosedHandlerVtbl IAvnPopupClosedHandlerVtbl;
typedef struct IAvnPopupFlyoutBase IAvnPopupFlyoutBase;
typedef struct IAvnPopupFlyoutBaseVtbl IAvnPopupFlyoutBaseVtbl;
typedef struct IAvnPopupFlyoutBaseClosingHandler IAvnPopupFlyoutBaseClosingHandler;
typedef struct IAvnPopupFlyoutBaseClosingHandlerVtbl IAvnPopupFlyoutBaseClosingHandlerVtbl;
typedef struct IAvnPopupFlyoutBaseOpeningHandler IAvnPopupFlyoutBaseOpeningHandler;
typedef struct IAvnPopupFlyoutBaseOpeningHandlerVtbl IAvnPopupFlyoutBaseOpeningHandlerVtbl;
typedef struct IAvnPopupOpenedHandler IAvnPopupOpenedHandler;
typedef struct IAvnPopupOpenedHandlerVtbl IAvnPopupOpenedHandlerVtbl;
typedef struct IAvnProgressBar IAvnProgressBar;
typedef struct IAvnProgressBarVtbl IAvnProgressBarVtbl;
typedef struct IAvnRadioButton IAvnRadioButton;
typedef struct IAvnRadioButtonVtbl IAvnRadioButtonVtbl;
typedef struct IAvnRangeBase IAvnRangeBase;
typedef struct IAvnRangeBaseVtbl IAvnRangeBaseVtbl;
typedef struct IAvnRangeBaseValueChangedHandler IAvnRangeBaseValueChangedHandler;
typedef struct IAvnRangeBaseValueChangedHandlerVtbl IAvnRangeBaseValueChangedHandlerVtbl;
typedef struct IAvnRectangle IAvnRectangle;
typedef struct IAvnRectangleVtbl IAvnRectangleVtbl;
typedef struct IAvnRefreshContainer IAvnRefreshContainer;
typedef struct IAvnRefreshContainerVtbl IAvnRefreshContainerVtbl;
typedef struct IAvnRelativePanel IAvnRelativePanel;
typedef struct IAvnRelativePanelVtbl IAvnRelativePanelVtbl;
typedef struct IAvnRelativePanelStatics IAvnRelativePanelStatics;
typedef struct IAvnRelativePanelStaticsVtbl IAvnRelativePanelStaticsVtbl;
typedef struct IAvnRepeatButton IAvnRepeatButton;
typedef struct IAvnRepeatButtonVtbl IAvnRepeatButtonVtbl;
typedef struct IAvnScrollViewer IAvnScrollViewer;
typedef struct IAvnScrollViewerVtbl IAvnScrollViewerVtbl;
typedef struct IAvnScrollViewerScrollChangedHandler IAvnScrollViewerScrollChangedHandler;
typedef struct IAvnScrollViewerScrollChangedHandlerVtbl IAvnScrollViewerScrollChangedHandlerVtbl;
typedef struct IAvnSector IAvnSector;
typedef struct IAvnSectorVtbl IAvnSectorVtbl;
typedef struct IAvnSelectableTextBlock IAvnSelectableTextBlock;
typedef struct IAvnSelectableTextBlockVtbl IAvnSelectableTextBlockVtbl;
typedef struct IAvnSelectableTextBlockCopyingToClipboardHandler IAvnSelectableTextBlockCopyingToClipboardHandler;
typedef struct IAvnSelectableTextBlockCopyingToClipboardHandlerVtbl IAvnSelectableTextBlockCopyingToClipboardHandlerVtbl;
typedef struct IAvnSelectingItemsControl IAvnSelectingItemsControl;
typedef struct IAvnSelectingItemsControlVtbl IAvnSelectingItemsControlVtbl;
typedef struct IAvnSelectingItemsControlSelectionChangedHandler IAvnSelectingItemsControlSelectionChangedHandler;
typedef struct IAvnSelectingItemsControlSelectionChangedHandlerVtbl IAvnSelectingItemsControlSelectionChangedHandlerVtbl;
typedef struct IAvnSeparator IAvnSeparator;
typedef struct IAvnSeparatorVtbl IAvnSeparatorVtbl;
typedef struct IAvnShape IAvnShape;
typedef struct IAvnShapeVtbl IAvnShapeVtbl;
typedef struct IAvnSlider IAvnSlider;
typedef struct IAvnSliderVtbl IAvnSliderVtbl;
typedef struct IAvnSpinner IAvnSpinner;
typedef struct IAvnSpinnerVtbl IAvnSpinnerVtbl;
typedef struct IAvnSplitButton IAvnSplitButton;
typedef struct IAvnSplitButtonVtbl IAvnSplitButtonVtbl;
typedef struct IAvnSplitButtonClickHandler IAvnSplitButtonClickHandler;
typedef struct IAvnSplitButtonClickHandlerVtbl IAvnSplitButtonClickHandlerVtbl;
typedef struct IAvnSplitView IAvnSplitView;
typedef struct IAvnSplitViewVtbl IAvnSplitViewVtbl;
typedef struct IAvnSplitViewPaneClosedHandler IAvnSplitViewPaneClosedHandler;
typedef struct IAvnSplitViewPaneClosedHandlerVtbl IAvnSplitViewPaneClosedHandlerVtbl;
typedef struct IAvnSplitViewPaneOpenedHandler IAvnSplitViewPaneOpenedHandler;
typedef struct IAvnSplitViewPaneOpenedHandlerVtbl IAvnSplitViewPaneOpenedHandlerVtbl;
typedef struct IAvnStackPanel IAvnStackPanel;
typedef struct IAvnStackPanelVtbl IAvnStackPanelVtbl;
typedef struct IAvnStringList IAvnStringList;
typedef struct IAvnStringListVtbl IAvnStringListVtbl;
typedef struct IAvnStyledElement IAvnStyledElement;
typedef struct IAvnStyledElementVtbl IAvnStyledElementVtbl;
typedef struct IAvnTabControl IAvnTabControl;
typedef struct IAvnTabControlVtbl IAvnTabControlVtbl;
typedef struct IAvnTabItem IAvnTabItem;
typedef struct IAvnTabItemVtbl IAvnTabItemVtbl;
typedef struct IAvnTableView IAvnTableView;
typedef struct IAvnTableViewVtbl IAvnTableViewVtbl;
typedef struct IAvnTableViewCell IAvnTableViewCell;
typedef struct IAvnTableViewCellVtbl IAvnTableViewCellVtbl;
typedef struct IAvnTableViewColumn IAvnTableViewColumn;
typedef struct IAvnTableViewColumnVtbl IAvnTableViewColumnVtbl;
typedef struct IAvnTableViewRow IAvnTableViewRow;
typedef struct IAvnTableViewRowVtbl IAvnTableViewRowVtbl;
typedef struct IAvnTemplatedControl IAvnTemplatedControl;
typedef struct IAvnTemplatedControlVtbl IAvnTemplatedControlVtbl;
typedef struct IAvnTextBlock IAvnTextBlock;
typedef struct IAvnTextBlockVtbl IAvnTextBlockVtbl;
typedef struct IAvnTextBox IAvnTextBox;
typedef struct IAvnTextBoxVtbl IAvnTextBoxVtbl;
typedef struct IAvnTextBoxCopyingToClipboardHandler IAvnTextBoxCopyingToClipboardHandler;
typedef struct IAvnTextBoxCopyingToClipboardHandlerVtbl IAvnTextBoxCopyingToClipboardHandlerVtbl;
typedef struct IAvnTextBoxCuttingToClipboardHandler IAvnTextBoxCuttingToClipboardHandler;
typedef struct IAvnTextBoxCuttingToClipboardHandlerVtbl IAvnTextBoxCuttingToClipboardHandlerVtbl;
typedef struct IAvnTextBoxPastingFromClipboardHandler IAvnTextBoxPastingFromClipboardHandler;
typedef struct IAvnTextBoxPastingFromClipboardHandlerVtbl IAvnTextBoxPastingFromClipboardHandlerVtbl;
typedef struct IAvnTextBoxTextChangedHandler IAvnTextBoxTextChangedHandler;
typedef struct IAvnTextBoxTextChangedHandlerVtbl IAvnTextBoxTextChangedHandlerVtbl;
typedef struct IAvnThemeVariantScope IAvnThemeVariantScope;
typedef struct IAvnThemeVariantScopeVtbl IAvnThemeVariantScopeVtbl;
typedef struct IAvnThumb IAvnThumb;
typedef struct IAvnThumbVtbl IAvnThumbVtbl;
typedef struct IAvnThumbDragCompletedHandler IAvnThumbDragCompletedHandler;
typedef struct IAvnThumbDragCompletedHandlerVtbl IAvnThumbDragCompletedHandlerVtbl;
typedef struct IAvnThumbDragDeltaHandler IAvnThumbDragDeltaHandler;
typedef struct IAvnThumbDragDeltaHandlerVtbl IAvnThumbDragDeltaHandlerVtbl;
typedef struct IAvnThumbDragStartedHandler IAvnThumbDragStartedHandler;
typedef struct IAvnThumbDragStartedHandlerVtbl IAvnThumbDragStartedHandlerVtbl;
typedef struct IAvnTimePicker IAvnTimePicker;
typedef struct IAvnTimePickerVtbl IAvnTimePickerVtbl;
typedef struct IAvnToggleButton IAvnToggleButton;
typedef struct IAvnToggleButtonVtbl IAvnToggleButtonVtbl;
typedef struct IAvnToggleButtonIsCheckedChangedHandler IAvnToggleButtonIsCheckedChangedHandler;
typedef struct IAvnToggleButtonIsCheckedChangedHandlerVtbl IAvnToggleButtonIsCheckedChangedHandlerVtbl;
typedef struct IAvnToggleSplitButton IAvnToggleSplitButton;
typedef struct IAvnToggleSplitButtonVtbl IAvnToggleSplitButtonVtbl;
typedef struct IAvnToggleSplitButtonIsCheckedChangedHandler IAvnToggleSplitButtonIsCheckedChangedHandler;
typedef struct IAvnToggleSplitButtonIsCheckedChangedHandlerVtbl IAvnToggleSplitButtonIsCheckedChangedHandlerVtbl;
typedef struct IAvnToggleSwitch IAvnToggleSwitch;
typedef struct IAvnToggleSwitchVtbl IAvnToggleSwitchVtbl;
typedef struct IAvnToolTip IAvnToolTip;
typedef struct IAvnToolTipVtbl IAvnToolTipVtbl;
typedef struct IAvnToolTipStatics IAvnToolTipStatics;
typedef struct IAvnToolTipStaticsVtbl IAvnToolTipStaticsVtbl;
typedef struct IAvnTransitioningContentControl IAvnTransitioningContentControl;
typedef struct IAvnTransitioningContentControlVtbl IAvnTransitioningContentControlVtbl;
typedef struct IAvnTrayIcon IAvnTrayIcon;
typedef struct IAvnTrayIconVtbl IAvnTrayIconVtbl;
typedef struct IAvnTreeView IAvnTreeView;
typedef struct IAvnTreeViewVtbl IAvnTreeViewVtbl;
typedef struct IAvnTreeViewItem IAvnTreeViewItem;
typedef struct IAvnTreeViewItemVtbl IAvnTreeViewItemVtbl;
typedef struct IAvnTreeViewItemCollapsedHandler IAvnTreeViewItemCollapsedHandler;
typedef struct IAvnTreeViewItemCollapsedHandlerVtbl IAvnTreeViewItemCollapsedHandlerVtbl;
typedef struct IAvnTreeViewItemExpandedHandler IAvnTreeViewItemExpandedHandler;
typedef struct IAvnTreeViewItemExpandedHandlerVtbl IAvnTreeViewItemExpandedHandlerVtbl;
typedef struct IAvnTreeViewSelectionChangedHandler IAvnTreeViewSelectionChangedHandler;
typedef struct IAvnTreeViewSelectionChangedHandlerVtbl IAvnTreeViewSelectionChangedHandlerVtbl;
typedef struct IAvnUniformGrid IAvnUniformGrid;
typedef struct IAvnUniformGridVtbl IAvnUniformGridVtbl;
typedef struct IAvnUserControl IAvnUserControl;
typedef struct IAvnUserControlVtbl IAvnUserControlVtbl;
typedef struct IAvnViewbox IAvnViewbox;
typedef struct IAvnViewboxVtbl IAvnViewboxVtbl;
typedef struct IAvnWindow IAvnWindow;
typedef struct IAvnWindowVtbl IAvnWindowVtbl;
typedef struct IAvnWindowClosingHandler IAvnWindowClosingHandler;
typedef struct IAvnWindowClosingHandlerVtbl IAvnWindowClosingHandlerVtbl;
typedef struct IAvnWindowNotificationManager IAvnWindowNotificationManager;
typedef struct IAvnWindowNotificationManagerVtbl IAvnWindowNotificationManagerVtbl;
typedef struct IAvnWrapPanel IAvnWrapPanel;
typedef struct IAvnWrapPanelVtbl IAvnWrapPanelVtbl;

static const AvnGuid I_AVN_AUTO_COMPLETE_BOX_DROP_DOWN_CLOSED_HANDLER_IID = {
    0x338294B4,
    0x2E9E,
    0x5494,
    { 0xB7, 0x84, 0xA3, 0xE0, 0x1C, 0xA0, 0x73, 0x2D }
};
#define I_AVN_AUTO_COMPLETE_BOX_DROP_DOWN_CLOSED_HANDLER_ABI_VERSION 1
struct IAvnAutoCompleteBoxDropDownClosedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnAutoCompleteBoxDropDownClosedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnAutoCompleteBoxDropDownClosedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnAutoCompleteBoxDropDownClosedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnAutoCompleteBoxDropDownClosedHandler* self); /* slot 3 */
};
struct IAvnAutoCompleteBoxDropDownClosedHandler { const IAvnAutoCompleteBoxDropDownClosedHandlerVtbl* vtbl; };
#define I_AVN_AUTO_COMPLETE_BOX_DROP_DOWN_CLOSED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_AUTO_COMPLETE_BOX_DROP_DOWN_CLOSING_HANDLER_IID = {
    0x22162FC3,
    0xF833,
    0x56BE,
    { 0xBB, 0x5F, 0xFA, 0x47, 0x13, 0x78, 0x62, 0xD0 }
};
#define I_AVN_AUTO_COMPLETE_BOX_DROP_DOWN_CLOSING_HANDLER_ABI_VERSION 1
struct IAvnAutoCompleteBoxDropDownClosingHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnAutoCompleteBoxDropDownClosingHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnAutoCompleteBoxDropDownClosingHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnAutoCompleteBoxDropDownClosingHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnAutoCompleteBoxDropDownClosingHandler* self, int32_t* cancel); /* slot 3 */
};
struct IAvnAutoCompleteBoxDropDownClosingHandler { const IAvnAutoCompleteBoxDropDownClosingHandlerVtbl* vtbl; };
#define I_AVN_AUTO_COMPLETE_BOX_DROP_DOWN_CLOSING_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_AUTO_COMPLETE_BOX_DROP_DOWN_OPENED_HANDLER_IID = {
    0x48E353BF,
    0x246E,
    0x5FC7,
    { 0x9C, 0xF4, 0xDE, 0x08, 0x2C, 0xE3, 0x0E, 0xD8 }
};
#define I_AVN_AUTO_COMPLETE_BOX_DROP_DOWN_OPENED_HANDLER_ABI_VERSION 1
struct IAvnAutoCompleteBoxDropDownOpenedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnAutoCompleteBoxDropDownOpenedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnAutoCompleteBoxDropDownOpenedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnAutoCompleteBoxDropDownOpenedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnAutoCompleteBoxDropDownOpenedHandler* self); /* slot 3 */
};
struct IAvnAutoCompleteBoxDropDownOpenedHandler { const IAvnAutoCompleteBoxDropDownOpenedHandlerVtbl* vtbl; };
#define I_AVN_AUTO_COMPLETE_BOX_DROP_DOWN_OPENED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_AUTO_COMPLETE_BOX_DROP_DOWN_OPENING_HANDLER_IID = {
    0x0A856166,
    0x2348,
    0x5059,
    { 0xA9, 0x95, 0xA3, 0x14, 0x2F, 0x8B, 0x6A, 0x12 }
};
#define I_AVN_AUTO_COMPLETE_BOX_DROP_DOWN_OPENING_HANDLER_ABI_VERSION 1
struct IAvnAutoCompleteBoxDropDownOpeningHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnAutoCompleteBoxDropDownOpeningHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnAutoCompleteBoxDropDownOpeningHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnAutoCompleteBoxDropDownOpeningHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnAutoCompleteBoxDropDownOpeningHandler* self, int32_t* cancel); /* slot 3 */
};
struct IAvnAutoCompleteBoxDropDownOpeningHandler { const IAvnAutoCompleteBoxDropDownOpeningHandlerVtbl* vtbl; };
#define I_AVN_AUTO_COMPLETE_BOX_DROP_DOWN_OPENING_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_AUTO_COMPLETE_BOX_POPULATING_HANDLER_IID = {
    0x53E64265,
    0x6992,
    0x5A51,
    { 0xB5, 0x4C, 0xD9, 0x8D, 0xD6, 0x1F, 0x95, 0xF9 }
};
#define I_AVN_AUTO_COMPLETE_BOX_POPULATING_HANDLER_ABI_VERSION 1
struct IAvnAutoCompleteBoxPopulatingHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnAutoCompleteBoxPopulatingHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnAutoCompleteBoxPopulatingHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnAutoCompleteBoxPopulatingHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnAutoCompleteBoxPopulatingHandler* self, int32_t* cancel, const uint16_t* parameter); /* slot 3 */
};
struct IAvnAutoCompleteBoxPopulatingHandler { const IAvnAutoCompleteBoxPopulatingHandlerVtbl* vtbl; };
#define I_AVN_AUTO_COMPLETE_BOX_POPULATING_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_AUTO_COMPLETE_BOX_TEXT_CHANGED_HANDLER_IID = {
    0x03E79A47,
    0x0885,
    0x5435,
    { 0x88, 0x0A, 0x7A, 0x15, 0x52, 0x93, 0x63, 0x9B }
};
#define I_AVN_AUTO_COMPLETE_BOX_TEXT_CHANGED_HANDLER_ABI_VERSION 1
struct IAvnAutoCompleteBoxTextChangedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnAutoCompleteBoxTextChangedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnAutoCompleteBoxTextChangedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnAutoCompleteBoxTextChangedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnAutoCompleteBoxTextChangedHandler* self); /* slot 3 */
};
struct IAvnAutoCompleteBoxTextChangedHandler { const IAvnAutoCompleteBoxTextChangedHandlerVtbl* vtbl; };
#define I_AVN_AUTO_COMPLETE_BOX_TEXT_CHANGED_HANDLER_VTABLE_SLOTS 4

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

static const AvnGuid I_AVN_CALENDAR_DATE_PICKER_CALENDAR_CLOSED_HANDLER_IID = {
    0xBE1A8386,
    0xE73B,
    0x5FC4,
    { 0x84, 0xAA, 0x92, 0xAD, 0x4F, 0x0D, 0x79, 0xDC }
};
#define I_AVN_CALENDAR_DATE_PICKER_CALENDAR_CLOSED_HANDLER_ABI_VERSION 1
struct IAvnCalendarDatePickerCalendarClosedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCalendarDatePickerCalendarClosedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCalendarDatePickerCalendarClosedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCalendarDatePickerCalendarClosedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnCalendarDatePickerCalendarClosedHandler* self); /* slot 3 */
};
struct IAvnCalendarDatePickerCalendarClosedHandler { const IAvnCalendarDatePickerCalendarClosedHandlerVtbl* vtbl; };
#define I_AVN_CALENDAR_DATE_PICKER_CALENDAR_CLOSED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_CALENDAR_DATE_PICKER_CALENDAR_OPENED_HANDLER_IID = {
    0xBAA74040,
    0xA700,
    0x5736,
    { 0xB4, 0x3B, 0xC3, 0x97, 0x85, 0x98, 0x63, 0xE7 }
};
#define I_AVN_CALENDAR_DATE_PICKER_CALENDAR_OPENED_HANDLER_ABI_VERSION 1
struct IAvnCalendarDatePickerCalendarOpenedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCalendarDatePickerCalendarOpenedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCalendarDatePickerCalendarOpenedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCalendarDatePickerCalendarOpenedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnCalendarDatePickerCalendarOpenedHandler* self); /* slot 3 */
};
struct IAvnCalendarDatePickerCalendarOpenedHandler { const IAvnCalendarDatePickerCalendarOpenedHandlerVtbl* vtbl; };
#define I_AVN_CALENDAR_DATE_PICKER_CALENDAR_OPENED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_COMBO_BOX_DROP_DOWN_CLOSED_HANDLER_IID = {
    0x954838EF,
    0x2A9F,
    0x5383,
    { 0x9E, 0xEF, 0x54, 0x49, 0xFD, 0xE8, 0x98, 0x34 }
};
#define I_AVN_COMBO_BOX_DROP_DOWN_CLOSED_HANDLER_ABI_VERSION 1
struct IAvnComboBoxDropDownClosedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnComboBoxDropDownClosedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnComboBoxDropDownClosedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnComboBoxDropDownClosedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnComboBoxDropDownClosedHandler* self); /* slot 3 */
};
struct IAvnComboBoxDropDownClosedHandler { const IAvnComboBoxDropDownClosedHandlerVtbl* vtbl; };
#define I_AVN_COMBO_BOX_DROP_DOWN_CLOSED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_COMBO_BOX_DROP_DOWN_OPENED_HANDLER_IID = {
    0x4C25AED5,
    0x664F,
    0x5337,
    { 0x84, 0xBB, 0xCE, 0x9B, 0x37, 0x71, 0x18, 0x8D }
};
#define I_AVN_COMBO_BOX_DROP_DOWN_OPENED_HANDLER_ABI_VERSION 1
struct IAvnComboBoxDropDownOpenedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnComboBoxDropDownOpenedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnComboBoxDropDownOpenedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnComboBoxDropDownOpenedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnComboBoxDropDownOpenedHandler* self); /* slot 3 */
};
struct IAvnComboBoxDropDownOpenedHandler { const IAvnComboBoxDropDownOpenedHandlerVtbl* vtbl; };
#define I_AVN_COMBO_BOX_DROP_DOWN_OPENED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_COMMAND_BAR_CLOSED_HANDLER_IID = {
    0x5B61D897,
    0x6279,
    0x57A9,
    { 0x8D, 0x0D, 0x1A, 0x89, 0x52, 0x52, 0xD6, 0xD5 }
};
#define I_AVN_COMMAND_BAR_CLOSED_HANDLER_ABI_VERSION 1
struct IAvnCommandBarClosedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCommandBarClosedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCommandBarClosedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCommandBarClosedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnCommandBarClosedHandler* self); /* slot 3 */
};
struct IAvnCommandBarClosedHandler { const IAvnCommandBarClosedHandlerVtbl* vtbl; };
#define I_AVN_COMMAND_BAR_CLOSED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_COMMAND_BAR_CLOSING_HANDLER_IID = {
    0x5FAD5A98,
    0x49C8,
    0x54B8,
    { 0xA6, 0x48, 0x39, 0xBB, 0xCA, 0x49, 0x78, 0x37 }
};
#define I_AVN_COMMAND_BAR_CLOSING_HANDLER_ABI_VERSION 1
struct IAvnCommandBarClosingHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCommandBarClosingHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCommandBarClosingHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCommandBarClosingHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnCommandBarClosingHandler* self); /* slot 3 */
};
struct IAvnCommandBarClosingHandler { const IAvnCommandBarClosingHandlerVtbl* vtbl; };
#define I_AVN_COMMAND_BAR_CLOSING_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_COMMAND_BAR_OPENED_HANDLER_IID = {
    0xECAA8ED5,
    0xC87D,
    0x51B4,
    { 0x95, 0x8F, 0x01, 0x01, 0xEB, 0xCD, 0x02, 0x63 }
};
#define I_AVN_COMMAND_BAR_OPENED_HANDLER_ABI_VERSION 1
struct IAvnCommandBarOpenedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCommandBarOpenedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCommandBarOpenedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCommandBarOpenedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnCommandBarOpenedHandler* self); /* slot 3 */
};
struct IAvnCommandBarOpenedHandler { const IAvnCommandBarOpenedHandlerVtbl* vtbl; };
#define I_AVN_COMMAND_BAR_OPENED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_COMMAND_BAR_OPENING_HANDLER_IID = {
    0x8116CB28,
    0xBE6F,
    0x5D21,
    { 0x9A, 0xBC, 0x0A, 0xAC, 0xC6, 0xB9, 0xCD, 0x0A }
};
#define I_AVN_COMMAND_BAR_OPENING_HANDLER_ABI_VERSION 1
struct IAvnCommandBarOpeningHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCommandBarOpeningHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCommandBarOpeningHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCommandBarOpeningHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnCommandBarOpeningHandler* self); /* slot 3 */
};
struct IAvnCommandBarOpeningHandler { const IAvnCommandBarOpeningHandlerVtbl* vtbl; };
#define I_AVN_COMMAND_BAR_OPENING_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_CONTEXT_MENU_CLOSING_HANDLER_IID = {
    0xA63F4035,
    0x2362,
    0x546D,
    { 0x82, 0x38, 0xED, 0x91, 0xD4, 0xF8, 0x04, 0xCB }
};
#define I_AVN_CONTEXT_MENU_CLOSING_HANDLER_ABI_VERSION 1
struct IAvnContextMenuClosingHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnContextMenuClosingHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnContextMenuClosingHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnContextMenuClosingHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnContextMenuClosingHandler* self, int32_t* cancel); /* slot 3 */
};
struct IAvnContextMenuClosingHandler { const IAvnContextMenuClosingHandlerVtbl* vtbl; };
#define I_AVN_CONTEXT_MENU_CLOSING_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_CONTEXT_MENU_OPENING_HANDLER_IID = {
    0x25E25F96,
    0x3DD6,
    0x5C15,
    { 0xA1, 0x90, 0x76, 0xE1, 0xE3, 0x2A, 0x4A, 0x5D }
};
#define I_AVN_CONTEXT_MENU_OPENING_HANDLER_ABI_VERSION 1
struct IAvnContextMenuOpeningHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnContextMenuOpeningHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnContextMenuOpeningHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnContextMenuOpeningHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnContextMenuOpeningHandler* self, int32_t* cancel); /* slot 3 */
};
struct IAvnContextMenuOpeningHandler { const IAvnContextMenuOpeningHandlerVtbl* vtbl; };
#define I_AVN_CONTEXT_MENU_OPENING_HANDLER_VTABLE_SLOTS 4

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

static const AvnGuid I_AVN_CONTROL_LOADED_HANDLER_IID = {
    0x02529698,
    0xA53B,
    0x5691,
    { 0x93, 0xB1, 0x92, 0x0B, 0x19, 0x36, 0x4C, 0x5E }
};
#define I_AVN_CONTROL_LOADED_HANDLER_ABI_VERSION 1
struct IAvnControlLoadedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnControlLoadedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnControlLoadedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnControlLoadedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnControlLoadedHandler* self); /* slot 3 */
};
struct IAvnControlLoadedHandler { const IAvnControlLoadedHandlerVtbl* vtbl; };
#define I_AVN_CONTROL_LOADED_HANDLER_VTABLE_SLOTS 4

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

static const AvnGuid I_AVN_CONTROL_UNLOADED_HANDLER_IID = {
    0x1118D172,
    0x21C3,
    0x5D89,
    { 0x8B, 0x7E, 0x3F, 0xFF, 0xF7, 0xB5, 0xE1, 0xAC }
};
#define I_AVN_CONTROL_UNLOADED_HANDLER_ABI_VERSION 1
struct IAvnControlUnloadedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnControlUnloadedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnControlUnloadedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnControlUnloadedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnControlUnloadedHandler* self); /* slot 3 */
};
struct IAvnControlUnloadedHandler { const IAvnControlUnloadedHandlerVtbl* vtbl; };
#define I_AVN_CONTROL_UNLOADED_HANDLER_VTABLE_SLOTS 4

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

static const AvnGuid I_AVN_FLYOUT_BASE_CLOSED_HANDLER_IID = {
    0xFD318133,
    0x16F5,
    0x5136,
    { 0xBA, 0x55, 0xDC, 0x7B, 0x1F, 0xCA, 0x6E, 0x6B }
};
#define I_AVN_FLYOUT_BASE_CLOSED_HANDLER_ABI_VERSION 1
struct IAvnFlyoutBaseClosedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnFlyoutBaseClosedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnFlyoutBaseClosedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnFlyoutBaseClosedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnFlyoutBaseClosedHandler* self); /* slot 3 */
};
struct IAvnFlyoutBaseClosedHandler { const IAvnFlyoutBaseClosedHandlerVtbl* vtbl; };
#define I_AVN_FLYOUT_BASE_CLOSED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_FLYOUT_BASE_OPENED_HANDLER_IID = {
    0x41A6074D,
    0xDE1C,
    0x5B5E,
    { 0x8B, 0xE6, 0x50, 0x32, 0x6C, 0xB7, 0xEA, 0x31 }
};
#define I_AVN_FLYOUT_BASE_OPENED_HANDLER_ABI_VERSION 1
struct IAvnFlyoutBaseOpenedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnFlyoutBaseOpenedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnFlyoutBaseOpenedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnFlyoutBaseOpenedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnFlyoutBaseOpenedHandler* self); /* slot 3 */
};
struct IAvnFlyoutBaseOpenedHandler { const IAvnFlyoutBaseOpenedHandlerVtbl* vtbl; };
#define I_AVN_FLYOUT_BASE_OPENED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_MENU_BASE_CLOSED_HANDLER_IID = {
    0x29D81495,
    0x8F6E,
    0x5F65,
    { 0x8B, 0x74, 0xAB, 0x3E, 0x66, 0x80, 0x77, 0xAF }
};
#define I_AVN_MENU_BASE_CLOSED_HANDLER_ABI_VERSION 1
struct IAvnMenuBaseClosedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnMenuBaseClosedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnMenuBaseClosedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnMenuBaseClosedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnMenuBaseClosedHandler* self); /* slot 3 */
};
struct IAvnMenuBaseClosedHandler { const IAvnMenuBaseClosedHandlerVtbl* vtbl; };
#define I_AVN_MENU_BASE_CLOSED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_MENU_BASE_OPENED_HANDLER_IID = {
    0xEA4E9CCD,
    0xFC83,
    0x5BE9,
    { 0xAD, 0xDF, 0xB2, 0xA4, 0xE4, 0x92, 0xAD, 0x8A }
};
#define I_AVN_MENU_BASE_OPENED_HANDLER_ABI_VERSION 1
struct IAvnMenuBaseOpenedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnMenuBaseOpenedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnMenuBaseOpenedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnMenuBaseOpenedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnMenuBaseOpenedHandler* self); /* slot 3 */
};
struct IAvnMenuBaseOpenedHandler { const IAvnMenuBaseOpenedHandlerVtbl* vtbl; };
#define I_AVN_MENU_BASE_OPENED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_MENU_ITEM_CLICK_HANDLER_IID = {
    0xD5A42FDA,
    0x88B2,
    0x53D0,
    { 0x94, 0x8C, 0xF3, 0xC9, 0x16, 0xCF, 0xF8, 0xAA }
};
#define I_AVN_MENU_ITEM_CLICK_HANDLER_ABI_VERSION 1
struct IAvnMenuItemClickHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnMenuItemClickHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnMenuItemClickHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnMenuItemClickHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnMenuItemClickHandler* self); /* slot 3 */
};
struct IAvnMenuItemClickHandler { const IAvnMenuItemClickHandlerVtbl* vtbl; };
#define I_AVN_MENU_ITEM_CLICK_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_MENU_ITEM_SUBMENU_OPENED_HANDLER_IID = {
    0x2F6D5C20,
    0x67E2,
    0x5411,
    { 0xB0, 0x7C, 0x46, 0xEB, 0xA3, 0xD3, 0xD6, 0x50 }
};
#define I_AVN_MENU_ITEM_SUBMENU_OPENED_HANDLER_ABI_VERSION 1
struct IAvnMenuItemSubmenuOpenedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnMenuItemSubmenuOpenedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnMenuItemSubmenuOpenedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnMenuItemSubmenuOpenedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnMenuItemSubmenuOpenedHandler* self); /* slot 3 */
};
struct IAvnMenuItemSubmenuOpenedHandler { const IAvnMenuItemSubmenuOpenedHandlerVtbl* vtbl; };
#define I_AVN_MENU_ITEM_SUBMENU_OPENED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_NUMERIC_UP_DOWN_VALUE_CHANGED_HANDLER_IID = {
    0x68A72F63,
    0xB469,
    0x5312,
    { 0x92, 0x5F, 0xF7, 0xFC, 0xCF, 0x35, 0xA0, 0xDF }
};
#define I_AVN_NUMERIC_UP_DOWN_VALUE_CHANGED_HANDLER_ABI_VERSION 1
struct IAvnNumericUpDownValueChangedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnNumericUpDownValueChangedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnNumericUpDownValueChangedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnNumericUpDownValueChangedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnNumericUpDownValueChangedHandler* self); /* slot 3 */
};
struct IAvnNumericUpDownValueChangedHandler { const IAvnNumericUpDownValueChangedHandlerVtbl* vtbl; };
#define I_AVN_NUMERIC_UP_DOWN_VALUE_CHANGED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_PIPS_PAGER_SELECTED_INDEX_CHANGED_HANDLER_IID = {
    0xF40B94E7,
    0xCD23,
    0x55D9,
    { 0xA4, 0x62, 0x55, 0x90, 0xA6, 0xFB, 0xB2, 0xB7 }
};
#define I_AVN_PIPS_PAGER_SELECTED_INDEX_CHANGED_HANDLER_ABI_VERSION 1
struct IAvnPipsPagerSelectedIndexChangedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnPipsPagerSelectedIndexChangedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnPipsPagerSelectedIndexChangedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnPipsPagerSelectedIndexChangedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnPipsPagerSelectedIndexChangedHandler* self); /* slot 3 */
};
struct IAvnPipsPagerSelectedIndexChangedHandler { const IAvnPipsPagerSelectedIndexChangedHandlerVtbl* vtbl; };
#define I_AVN_PIPS_PAGER_SELECTED_INDEX_CHANGED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_POPUP_CLOSED_HANDLER_IID = {
    0xBA05BA4E,
    0x4F9F,
    0x527C,
    { 0xA8, 0xD4, 0x35, 0x20, 0x3B, 0x0D, 0x51, 0x01 }
};
#define I_AVN_POPUP_CLOSED_HANDLER_ABI_VERSION 1
struct IAvnPopupClosedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnPopupClosedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnPopupClosedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnPopupClosedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnPopupClosedHandler* self); /* slot 3 */
};
struct IAvnPopupClosedHandler { const IAvnPopupClosedHandlerVtbl* vtbl; };
#define I_AVN_POPUP_CLOSED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_POPUP_FLYOUT_BASE_CLOSING_HANDLER_IID = {
    0xEAE8EE53,
    0x8398,
    0x5DF1,
    { 0xAC, 0x68, 0x38, 0xF3, 0x0C, 0x7F, 0xC8, 0x48 }
};
#define I_AVN_POPUP_FLYOUT_BASE_CLOSING_HANDLER_ABI_VERSION 1
struct IAvnPopupFlyoutBaseClosingHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnPopupFlyoutBaseClosingHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnPopupFlyoutBaseClosingHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnPopupFlyoutBaseClosingHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnPopupFlyoutBaseClosingHandler* self, int32_t* cancel); /* slot 3 */
};
struct IAvnPopupFlyoutBaseClosingHandler { const IAvnPopupFlyoutBaseClosingHandlerVtbl* vtbl; };
#define I_AVN_POPUP_FLYOUT_BASE_CLOSING_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_POPUP_FLYOUT_BASE_OPENING_HANDLER_IID = {
    0x1F90823E,
    0x2D18,
    0x59F2,
    { 0xBD, 0xE7, 0xBD, 0xA5, 0x8E, 0x80, 0xDB, 0xF5 }
};
#define I_AVN_POPUP_FLYOUT_BASE_OPENING_HANDLER_ABI_VERSION 1
struct IAvnPopupFlyoutBaseOpeningHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnPopupFlyoutBaseOpeningHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnPopupFlyoutBaseOpeningHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnPopupFlyoutBaseOpeningHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnPopupFlyoutBaseOpeningHandler* self); /* slot 3 */
};
struct IAvnPopupFlyoutBaseOpeningHandler { const IAvnPopupFlyoutBaseOpeningHandlerVtbl* vtbl; };
#define I_AVN_POPUP_FLYOUT_BASE_OPENING_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_POPUP_OPENED_HANDLER_IID = {
    0xE221E0B8,
    0xBEBA,
    0x5462,
    { 0xAD, 0xE8, 0x9C, 0xD5, 0xCF, 0xAB, 0xA8, 0xB7 }
};
#define I_AVN_POPUP_OPENED_HANDLER_ABI_VERSION 1
struct IAvnPopupOpenedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnPopupOpenedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnPopupOpenedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnPopupOpenedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnPopupOpenedHandler* self); /* slot 3 */
};
struct IAvnPopupOpenedHandler { const IAvnPopupOpenedHandlerVtbl* vtbl; };
#define I_AVN_POPUP_OPENED_HANDLER_VTABLE_SLOTS 4

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

static const AvnGuid I_AVN_SELECTABLE_TEXT_BLOCK_COPYING_TO_CLIPBOARD_HANDLER_IID = {
    0xCB10B16D,
    0xD8FC,
    0x53DE,
    { 0xA8, 0xB0, 0x10, 0x08, 0xB8, 0x21, 0x55, 0x01 }
};
#define I_AVN_SELECTABLE_TEXT_BLOCK_COPYING_TO_CLIPBOARD_HANDLER_ABI_VERSION 1
struct IAvnSelectableTextBlockCopyingToClipboardHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnSelectableTextBlockCopyingToClipboardHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnSelectableTextBlockCopyingToClipboardHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnSelectableTextBlockCopyingToClipboardHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnSelectableTextBlockCopyingToClipboardHandler* self); /* slot 3 */
};
struct IAvnSelectableTextBlockCopyingToClipboardHandler { const IAvnSelectableTextBlockCopyingToClipboardHandlerVtbl* vtbl; };
#define I_AVN_SELECTABLE_TEXT_BLOCK_COPYING_TO_CLIPBOARD_HANDLER_VTABLE_SLOTS 4

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

static const AvnGuid I_AVN_SPLIT_BUTTON_CLICK_HANDLER_IID = {
    0x257AD223,
    0xD656,
    0x551A,
    { 0xAC, 0x83, 0xE4, 0xD4, 0xF3, 0xB5, 0x90, 0xE6 }
};
#define I_AVN_SPLIT_BUTTON_CLICK_HANDLER_ABI_VERSION 1
struct IAvnSplitButtonClickHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnSplitButtonClickHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnSplitButtonClickHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnSplitButtonClickHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnSplitButtonClickHandler* self); /* slot 3 */
};
struct IAvnSplitButtonClickHandler { const IAvnSplitButtonClickHandlerVtbl* vtbl; };
#define I_AVN_SPLIT_BUTTON_CLICK_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_SPLIT_VIEW_PANE_CLOSED_HANDLER_IID = {
    0x82202021,
    0xD4D8,
    0x5789,
    { 0x85, 0x44, 0xE0, 0x04, 0x06, 0x06, 0x6E, 0xC0 }
};
#define I_AVN_SPLIT_VIEW_PANE_CLOSED_HANDLER_ABI_VERSION 1
struct IAvnSplitViewPaneClosedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnSplitViewPaneClosedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnSplitViewPaneClosedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnSplitViewPaneClosedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnSplitViewPaneClosedHandler* self); /* slot 3 */
};
struct IAvnSplitViewPaneClosedHandler { const IAvnSplitViewPaneClosedHandlerVtbl* vtbl; };
#define I_AVN_SPLIT_VIEW_PANE_CLOSED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_SPLIT_VIEW_PANE_OPENED_HANDLER_IID = {
    0x3D24DB63,
    0x45CC,
    0x581B,
    { 0x87, 0x34, 0xEF, 0xEC, 0xDC, 0x25, 0xA6, 0x81 }
};
#define I_AVN_SPLIT_VIEW_PANE_OPENED_HANDLER_ABI_VERSION 1
struct IAvnSplitViewPaneOpenedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnSplitViewPaneOpenedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnSplitViewPaneOpenedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnSplitViewPaneOpenedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnSplitViewPaneOpenedHandler* self); /* slot 3 */
};
struct IAvnSplitViewPaneOpenedHandler { const IAvnSplitViewPaneOpenedHandlerVtbl* vtbl; };
#define I_AVN_SPLIT_VIEW_PANE_OPENED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_TEXT_BOX_COPYING_TO_CLIPBOARD_HANDLER_IID = {
    0xF367E5D4,
    0xB10F,
    0x5BFC,
    { 0x9B, 0x1B, 0x12, 0x1A, 0x76, 0x50, 0xF6, 0xA2 }
};
#define I_AVN_TEXT_BOX_COPYING_TO_CLIPBOARD_HANDLER_ABI_VERSION 1
struct IAvnTextBoxCopyingToClipboardHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTextBoxCopyingToClipboardHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTextBoxCopyingToClipboardHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTextBoxCopyingToClipboardHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnTextBoxCopyingToClipboardHandler* self); /* slot 3 */
};
struct IAvnTextBoxCopyingToClipboardHandler { const IAvnTextBoxCopyingToClipboardHandlerVtbl* vtbl; };
#define I_AVN_TEXT_BOX_COPYING_TO_CLIPBOARD_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_TEXT_BOX_CUTTING_TO_CLIPBOARD_HANDLER_IID = {
    0x20A41A73,
    0x9839,
    0x5C37,
    { 0xA1, 0x49, 0x47, 0xDC, 0xA6, 0x2A, 0x14, 0x99 }
};
#define I_AVN_TEXT_BOX_CUTTING_TO_CLIPBOARD_HANDLER_ABI_VERSION 1
struct IAvnTextBoxCuttingToClipboardHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTextBoxCuttingToClipboardHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTextBoxCuttingToClipboardHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTextBoxCuttingToClipboardHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnTextBoxCuttingToClipboardHandler* self); /* slot 3 */
};
struct IAvnTextBoxCuttingToClipboardHandler { const IAvnTextBoxCuttingToClipboardHandlerVtbl* vtbl; };
#define I_AVN_TEXT_BOX_CUTTING_TO_CLIPBOARD_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_TEXT_BOX_PASTING_FROM_CLIPBOARD_HANDLER_IID = {
    0x9EE4C061,
    0x60F0,
    0x5BA6,
    { 0xB1, 0xAC, 0x5C, 0x65, 0x33, 0xB7, 0x24, 0x8C }
};
#define I_AVN_TEXT_BOX_PASTING_FROM_CLIPBOARD_HANDLER_ABI_VERSION 1
struct IAvnTextBoxPastingFromClipboardHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTextBoxPastingFromClipboardHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTextBoxPastingFromClipboardHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTextBoxPastingFromClipboardHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnTextBoxPastingFromClipboardHandler* self); /* slot 3 */
};
struct IAvnTextBoxPastingFromClipboardHandler { const IAvnTextBoxPastingFromClipboardHandlerVtbl* vtbl; };
#define I_AVN_TEXT_BOX_PASTING_FROM_CLIPBOARD_HANDLER_VTABLE_SLOTS 4

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

static const AvnGuid I_AVN_THUMB_DRAG_COMPLETED_HANDLER_IID = {
    0x913B0E1C,
    0xAF04,
    0x556E,
    { 0xB2, 0xAE, 0x60, 0xD6, 0x19, 0xC9, 0x83, 0x3C }
};
#define I_AVN_THUMB_DRAG_COMPLETED_HANDLER_ABI_VERSION 1
struct IAvnThumbDragCompletedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnThumbDragCompletedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnThumbDragCompletedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnThumbDragCompletedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnThumbDragCompletedHandler* self, AvnVector vector); /* slot 3 */
};
struct IAvnThumbDragCompletedHandler { const IAvnThumbDragCompletedHandlerVtbl* vtbl; };
#define I_AVN_THUMB_DRAG_COMPLETED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_THUMB_DRAG_DELTA_HANDLER_IID = {
    0x213AA2C1,
    0x763B,
    0x5196,
    { 0x99, 0xD1, 0x2F, 0x07, 0x0C, 0x0D, 0xBE, 0xA0 }
};
#define I_AVN_THUMB_DRAG_DELTA_HANDLER_ABI_VERSION 1
struct IAvnThumbDragDeltaHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnThumbDragDeltaHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnThumbDragDeltaHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnThumbDragDeltaHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnThumbDragDeltaHandler* self, AvnVector vector); /* slot 3 */
};
struct IAvnThumbDragDeltaHandler { const IAvnThumbDragDeltaHandlerVtbl* vtbl; };
#define I_AVN_THUMB_DRAG_DELTA_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_THUMB_DRAG_STARTED_HANDLER_IID = {
    0xBCA61CC5,
    0x8334,
    0x5A1E,
    { 0xA6, 0xF1, 0xD9, 0xA3, 0x1D, 0x1E, 0xE5, 0x02 }
};
#define I_AVN_THUMB_DRAG_STARTED_HANDLER_ABI_VERSION 1
struct IAvnThumbDragStartedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnThumbDragStartedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnThumbDragStartedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnThumbDragStartedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnThumbDragStartedHandler* self, AvnVector vector); /* slot 3 */
};
struct IAvnThumbDragStartedHandler { const IAvnThumbDragStartedHandlerVtbl* vtbl; };
#define I_AVN_THUMB_DRAG_STARTED_HANDLER_VTABLE_SLOTS 4

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

static const AvnGuid I_AVN_TOGGLE_SPLIT_BUTTON_IS_CHECKED_CHANGED_HANDLER_IID = {
    0x0034F5FE,
    0xA55D,
    0x5A7E,
    { 0xB5, 0xB0, 0x66, 0x7C, 0x82, 0x85, 0x4A, 0x8A }
};
#define I_AVN_TOGGLE_SPLIT_BUTTON_IS_CHECKED_CHANGED_HANDLER_ABI_VERSION 1
struct IAvnToggleSplitButtonIsCheckedChangedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnToggleSplitButtonIsCheckedChangedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnToggleSplitButtonIsCheckedChangedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnToggleSplitButtonIsCheckedChangedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnToggleSplitButtonIsCheckedChangedHandler* self); /* slot 3 */
};
struct IAvnToggleSplitButtonIsCheckedChangedHandler { const IAvnToggleSplitButtonIsCheckedChangedHandlerVtbl* vtbl; };
#define I_AVN_TOGGLE_SPLIT_BUTTON_IS_CHECKED_CHANGED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_TREE_VIEW_ITEM_COLLAPSED_HANDLER_IID = {
    0xB1B6807B,
    0x83E5,
    0x596B,
    { 0x87, 0x54, 0x4B, 0x49, 0xE2, 0xEB, 0xA9, 0x31 }
};
#define I_AVN_TREE_VIEW_ITEM_COLLAPSED_HANDLER_ABI_VERSION 1
struct IAvnTreeViewItemCollapsedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTreeViewItemCollapsedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTreeViewItemCollapsedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTreeViewItemCollapsedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnTreeViewItemCollapsedHandler* self); /* slot 3 */
};
struct IAvnTreeViewItemCollapsedHandler { const IAvnTreeViewItemCollapsedHandlerVtbl* vtbl; };
#define I_AVN_TREE_VIEW_ITEM_COLLAPSED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_TREE_VIEW_ITEM_EXPANDED_HANDLER_IID = {
    0xDA50A65B,
    0xD90A,
    0x5CA4,
    { 0xBB, 0xC6, 0xE3, 0xAD, 0x26, 0xF4, 0x12, 0x3F }
};
#define I_AVN_TREE_VIEW_ITEM_EXPANDED_HANDLER_ABI_VERSION 1
struct IAvnTreeViewItemExpandedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTreeViewItemExpandedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTreeViewItemExpandedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTreeViewItemExpandedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnTreeViewItemExpandedHandler* self); /* slot 3 */
};
struct IAvnTreeViewItemExpandedHandler { const IAvnTreeViewItemExpandedHandlerVtbl* vtbl; };
#define I_AVN_TREE_VIEW_ITEM_EXPANDED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_TREE_VIEW_SELECTION_CHANGED_HANDLER_IID = {
    0xED72A060,
    0x42CB,
    0x5648,
    { 0x80, 0x4F, 0xC5, 0xDC, 0xAB, 0x3C, 0xD8, 0x7A }
};
#define I_AVN_TREE_VIEW_SELECTION_CHANGED_HANDLER_ABI_VERSION 1
struct IAvnTreeViewSelectionChangedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTreeViewSelectionChangedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTreeViewSelectionChangedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTreeViewSelectionChangedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnTreeViewSelectionChangedHandler* self); /* slot 3 */
};
struct IAvnTreeViewSelectionChangedHandler { const IAvnTreeViewSelectionChangedHandlerVtbl* vtbl; };
#define I_AVN_TREE_VIEW_SELECTION_CHANGED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_WINDOW_CLOSING_HANDLER_IID = {
    0x9E4F5540,
    0x9E58,
    0x52B6,
    { 0x9B, 0xEA, 0xF2, 0x1C, 0xF9, 0xA7, 0xAC, 0x48 }
};
#define I_AVN_WINDOW_CLOSING_HANDLER_ABI_VERSION 1
struct IAvnWindowClosingHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnWindowClosingHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnWindowClosingHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnWindowClosingHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnWindowClosingHandler* self, int32_t* cancel, int32_t close_reason, int32_t is_programmatic); /* slot 3 */
};
struct IAvnWindowClosingHandler { const IAvnWindowClosingHandlerVtbl* vtbl; };
#define I_AVN_WINDOW_CLOSING_HANDLER_VTABLE_SLOTS 4

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

static const AvnGuid I_AVN_COMMAND_CAN_EXECUTE_CHANGED_HANDLER_IID = {
    0x13E58040,
    0xB570,
    0x518F,
    { 0xA5, 0xF2, 0xFE, 0x3E, 0xA8, 0x0B, 0x46, 0x88 }
};
#define I_AVN_COMMAND_CAN_EXECUTE_CHANGED_HANDLER_ABI_VERSION 1
struct IAvnCommandCanExecuteChangedHandlerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCommandCanExecuteChangedHandler* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCommandCanExecuteChangedHandler* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCommandCanExecuteChangedHandler* self); /* slot 2 */
    AvnHResult (AVN_CALL *invoke)(IAvnCommandCanExecuteChangedHandler* self); /* slot 3 */
};
struct IAvnCommandCanExecuteChangedHandler { const IAvnCommandCanExecuteChangedHandlerVtbl* vtbl; };
#define I_AVN_COMMAND_CAN_EXECUTE_CHANGED_HANDLER_VTABLE_SLOTS 4

static const AvnGuid I_AVN_COMMAND_IID = {
    0xE6F7AAF7,
    0xD5E7,
    0x503F,
    { 0x9B, 0xE6, 0x5A, 0xF8, 0xDB, 0x5B, 0x52, 0x73 }
};
#define I_AVN_COMMAND_ABI_VERSION 2
struct IAvnCommandVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCommand* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCommand* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCommand* self); /* slot 2 */
    AvnHResult (AVN_CALL *execute)(IAvnCommand* self, AvnVariant parameter); /* slot 3 */
    AvnHResult (AVN_CALL *can_execute)(IAvnCommand* self, AvnVariant parameter, int32_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *advise_can_execute_changed)(IAvnCommand* self, IAvnCommandCanExecuteChangedHandler* handler, int64_t* subscription_id); /* slot 5 */
    AvnHResult (AVN_CALL *unadvise_can_execute_changed)(IAvnCommand* self, int64_t subscription_id); /* slot 6 */
};
struct IAvnCommand { const IAvnCommandVtbl* vtbl; };
#define I_AVN_COMMAND_VTABLE_SLOTS 7

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

static const AvnGuid I_AVN_ARC_IID = {
    0xA64DB855,
    0xEEBF,
    0x5D4A,
    { 0xB3, 0x5F, 0x69, 0x73, 0x9B, 0x6A, 0xE7, 0xCA }
};
#define I_AVN_ARC_ABI_VERSION 2
struct IAvnArcVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnArc* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnArc* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnArc* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnArc* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnArc* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnArc* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnArc* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnArc* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnArc* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnArc* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnArc* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnArc* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnArc* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnArc* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnArc* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnArc* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnArc* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnArc* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnArc* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnArc* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnArc* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnArc* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnArc* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnArc* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnArc* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnArc* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnArc* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnArc* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnArc* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnArc* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnArc* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnArc* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnArc* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnArc* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnArc* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnArc* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnArc* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnArc* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnArc* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnArc* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnArc* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnArc* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnArc* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnArc* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnArc* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnArc* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnArc* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_fill)(IAvnArc* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_fill)(IAvnArc* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_stretch)(IAvnArc* self, int32_t* value); /* slot 49 */
    AvnHResult (AVN_CALL *set_stretch)(IAvnArc* self, int32_t value); /* slot 50 */
    AvnHResult (AVN_CALL *get_stroke)(IAvnArc* self, IAvnBrush** value); /* slot 51 */
    AvnHResult (AVN_CALL *set_stroke)(IAvnArc* self, IAvnBrush* value); /* slot 52 */
    AvnHResult (AVN_CALL *get_stroke_dash_offset)(IAvnArc* self, double* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_stroke_dash_offset)(IAvnArc* self, double value); /* slot 54 */
    AvnHResult (AVN_CALL *get_stroke_thickness)(IAvnArc* self, double* value); /* slot 55 */
    AvnHResult (AVN_CALL *set_stroke_thickness)(IAvnArc* self, double value); /* slot 56 */
    AvnHResult (AVN_CALL *get_stroke_line_cap)(IAvnArc* self, int32_t* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_stroke_line_cap)(IAvnArc* self, int32_t value); /* slot 58 */
    AvnHResult (AVN_CALL *get_stroke_join)(IAvnArc* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_stroke_join)(IAvnArc* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_stroke_miter_limit)(IAvnArc* self, double* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_stroke_miter_limit)(IAvnArc* self, double value); /* slot 62 */
    AvnHResult (AVN_CALL *get_start_angle)(IAvnArc* self, double* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_start_angle)(IAvnArc* self, double value); /* slot 64 */
    AvnHResult (AVN_CALL *get_sweep_angle)(IAvnArc* self, double* value); /* slot 65 */
    AvnHResult (AVN_CALL *set_sweep_angle)(IAvnArc* self, double value); /* slot 66 */
};
struct IAvnArc { const IAvnArcVtbl* vtbl; };
#define I_AVN_ARC_VTABLE_SLOTS 67

static const AvnGuid I_AVN_AUTO_COMPLETE_BOX_IID = {
    0x7561A64D,
    0x0AFE,
    0x5DA1,
    { 0xA1, 0xD6, 0x6D, 0x06, 0x2E, 0xE4, 0x34, 0x7C }
};
#define I_AVN_AUTO_COMPLETE_BOX_ABI_VERSION 5
struct IAvnAutoCompleteBoxVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnAutoCompleteBox* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnAutoCompleteBox* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnAutoCompleteBox* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnAutoCompleteBox* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnAutoCompleteBox* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnAutoCompleteBox* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnAutoCompleteBox* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnAutoCompleteBox* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnAutoCompleteBox* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnAutoCompleteBox* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnAutoCompleteBox* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnAutoCompleteBox* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnAutoCompleteBox* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnAutoCompleteBox* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnAutoCompleteBox* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnAutoCompleteBox* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnAutoCompleteBox* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnAutoCompleteBox* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnAutoCompleteBox* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnAutoCompleteBox* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnAutoCompleteBox* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnAutoCompleteBox* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnAutoCompleteBox* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnAutoCompleteBox* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnAutoCompleteBox* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnAutoCompleteBox* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnAutoCompleteBox* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnAutoCompleteBox* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnAutoCompleteBox* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnAutoCompleteBox* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnAutoCompleteBox* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnAutoCompleteBox* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnAutoCompleteBox* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnAutoCompleteBox* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnAutoCompleteBox* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnAutoCompleteBox* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnAutoCompleteBox* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnAutoCompleteBox* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnAutoCompleteBox* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnAutoCompleteBox* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnAutoCompleteBox* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnAutoCompleteBox* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnAutoCompleteBox* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnAutoCompleteBox* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnAutoCompleteBox* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnAutoCompleteBox* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnAutoCompleteBox* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnAutoCompleteBox* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnAutoCompleteBox* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnAutoCompleteBox* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnAutoCompleteBox* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnAutoCompleteBox* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnAutoCompleteBox* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnAutoCompleteBox* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnAutoCompleteBox* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnAutoCompleteBox* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnAutoCompleteBox* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnAutoCompleteBox* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnAutoCompleteBox* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnAutoCompleteBox* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnAutoCompleteBox* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnAutoCompleteBox* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnAutoCompleteBox* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnAutoCompleteBox* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnAutoCompleteBox* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnAutoCompleteBox* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnAutoCompleteBox* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnAutoCompleteBox* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnAutoCompleteBox* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnAutoCompleteBox* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnAutoCompleteBox* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_caret_index)(IAvnAutoCompleteBox* self, int32_t* value); /* slot 71 */
    AvnHResult (AVN_CALL *set_caret_index)(IAvnAutoCompleteBox* self, int32_t value); /* slot 72 */
    AvnHResult (AVN_CALL *get_minimum_prefix_length)(IAvnAutoCompleteBox* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_minimum_prefix_length)(IAvnAutoCompleteBox* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_is_text_completion_enabled)(IAvnAutoCompleteBox* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_is_text_completion_enabled)(IAvnAutoCompleteBox* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_minimum_populate_delay)(IAvnAutoCompleteBox* self, int64_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_minimum_populate_delay)(IAvnAutoCompleteBox* self, int64_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_max_drop_down_height)(IAvnAutoCompleteBox* self, double* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_max_drop_down_height)(IAvnAutoCompleteBox* self, double value); /* slot 80 */
    AvnHResult (AVN_CALL *get_is_drop_down_open)(IAvnAutoCompleteBox* self, int32_t* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_is_drop_down_open)(IAvnAutoCompleteBox* self, int32_t value); /* slot 82 */
    AvnHResult (AVN_CALL *get_clear_selection_on_lost_focus)(IAvnAutoCompleteBox* self, int32_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_clear_selection_on_lost_focus)(IAvnAutoCompleteBox* self, int32_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_text)(IAvnAutoCompleteBox* self, uint16_t** value); /* slot 85 */
    AvnHResult (AVN_CALL *set_text)(IAvnAutoCompleteBox* self, const uint16_t* value); /* slot 86 */
    AvnHResult (AVN_CALL *get_search_text)(IAvnAutoCompleteBox* self, uint16_t** value); /* slot 87 */
    AvnHResult (AVN_CALL *get_filter_mode)(IAvnAutoCompleteBox* self, int32_t* value); /* slot 88 */
    AvnHResult (AVN_CALL *set_filter_mode)(IAvnAutoCompleteBox* self, int32_t value); /* slot 89 */
    AvnHResult (AVN_CALL *get_placeholder_text)(IAvnAutoCompleteBox* self, uint16_t** value); /* slot 90 */
    AvnHResult (AVN_CALL *set_placeholder_text)(IAvnAutoCompleteBox* self, const uint16_t* value); /* slot 91 */
    AvnHResult (AVN_CALL *get_placeholder_foreground)(IAvnAutoCompleteBox* self, IAvnBrush** value); /* slot 92 */
    AvnHResult (AVN_CALL *set_placeholder_foreground)(IAvnAutoCompleteBox* self, IAvnBrush* value); /* slot 93 */
    AvnHResult (AVN_CALL *get_max_length)(IAvnAutoCompleteBox* self, int32_t* value); /* slot 94 */
    AvnHResult (AVN_CALL *set_max_length)(IAvnAutoCompleteBox* self, int32_t value); /* slot 95 */
    AvnHResult (AVN_CALL *get_inner_left_content)(IAvnAutoCompleteBox* self, IAvnControl** value); /* slot 96 */
    AvnHResult (AVN_CALL *set_inner_left_content)(IAvnAutoCompleteBox* self, IAvnControl* value); /* slot 97 */
    AvnHResult (AVN_CALL *get_inner_right_content)(IAvnAutoCompleteBox* self, IAvnControl** value); /* slot 98 */
    AvnHResult (AVN_CALL *set_inner_right_content)(IAvnAutoCompleteBox* self, IAvnControl* value); /* slot 99 */
    AvnHResult (AVN_CALL *populate_complete)(IAvnAutoCompleteBox* self); /* slot 100 */
    AvnHResult (AVN_CALL *advise_text_changed)(IAvnAutoCompleteBox* self, IAvnAutoCompleteBoxTextChangedHandler* handler, int64_t* subscription_id); /* slot 101 */
    AvnHResult (AVN_CALL *unadvise_text_changed)(IAvnAutoCompleteBox* self, int64_t subscription_id); /* slot 102 */
    AvnHResult (AVN_CALL *advise_populating)(IAvnAutoCompleteBox* self, IAvnAutoCompleteBoxPopulatingHandler* handler, int64_t* subscription_id); /* slot 103 */
    AvnHResult (AVN_CALL *unadvise_populating)(IAvnAutoCompleteBox* self, int64_t subscription_id); /* slot 104 */
    AvnHResult (AVN_CALL *advise_drop_down_opening)(IAvnAutoCompleteBox* self, IAvnAutoCompleteBoxDropDownOpeningHandler* handler, int64_t* subscription_id); /* slot 105 */
    AvnHResult (AVN_CALL *unadvise_drop_down_opening)(IAvnAutoCompleteBox* self, int64_t subscription_id); /* slot 106 */
    AvnHResult (AVN_CALL *advise_drop_down_opened)(IAvnAutoCompleteBox* self, IAvnAutoCompleteBoxDropDownOpenedHandler* handler, int64_t* subscription_id); /* slot 107 */
    AvnHResult (AVN_CALL *unadvise_drop_down_opened)(IAvnAutoCompleteBox* self, int64_t subscription_id); /* slot 108 */
    AvnHResult (AVN_CALL *advise_drop_down_closing)(IAvnAutoCompleteBox* self, IAvnAutoCompleteBoxDropDownClosingHandler* handler, int64_t* subscription_id); /* slot 109 */
    AvnHResult (AVN_CALL *unadvise_drop_down_closing)(IAvnAutoCompleteBox* self, int64_t subscription_id); /* slot 110 */
    AvnHResult (AVN_CALL *advise_drop_down_closed)(IAvnAutoCompleteBox* self, IAvnAutoCompleteBoxDropDownClosedHandler* handler, int64_t* subscription_id); /* slot 111 */
    AvnHResult (AVN_CALL *unadvise_drop_down_closed)(IAvnAutoCompleteBox* self, int64_t subscription_id); /* slot 112 */
};
struct IAvnAutoCompleteBox { const IAvnAutoCompleteBoxVtbl* vtbl; };
#define I_AVN_AUTO_COMPLETE_BOX_VTABLE_SLOTS 113

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
    0x8CBDF7CD,
    0x7FB0,
    0x5E65,
    { 0x97, 0xA7, 0xCD, 0xA1, 0xA7, 0x91, 0xC1, 0x22 }
};
#define I_AVN_BORDER_ABI_VERSION 6
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnBorder* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnBorder* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnBorder* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnBorder* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnBorder* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnBorder* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnBorder* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnBorder* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnBorder* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnBorder* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnBorder* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnBorder* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnBorder* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnBorder* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnBorder* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnBorder* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnBorder* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnBorder* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnBorder* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnBorder* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnBorder* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnBorder* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnBorder* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnBorder* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnBorder* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnBorder* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnBorder* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnBorder* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnBorder* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnBorder* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnBorder* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnBorder* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnBorder* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnBorder* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnBorder* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_child)(IAvnBorder* self, IAvnControl** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_child)(IAvnBorder* self, IAvnControl* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_padding)(IAvnBorder* self, AvnThickness* value); /* slot 49 */
    AvnHResult (AVN_CALL *set_padding)(IAvnBorder* self, AvnThickness value); /* slot 50 */
    AvnHResult (AVN_CALL *get_background)(IAvnBorder* self, IAvnBrush** value); /* slot 51 */
    AvnHResult (AVN_CALL *set_background)(IAvnBorder* self, IAvnBrush* value); /* slot 52 */
    AvnHResult (AVN_CALL *get_background_sizing)(IAvnBorder* self, int32_t* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_background_sizing)(IAvnBorder* self, int32_t value); /* slot 54 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnBorder* self, IAvnBrush** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnBorder* self, IAvnBrush* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnBorder* self, AvnThickness* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnBorder* self, AvnThickness value); /* slot 58 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnBorder* self, AvnCornerRadius* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnBorder* self, AvnCornerRadius value); /* slot 60 */
    AvnHResult (AVN_CALL *get_clip_to_bounds_radius)(IAvnBorder* self, AvnCornerRadius* value); /* slot 61 */
};
struct IAvnBorder { const IAvnBorderVtbl* vtbl; };
#define I_AVN_BORDER_VTABLE_SLOTS 62

static const AvnGuid I_AVN_BUTTON_IID = {
    0xEE2A808D,
    0x2C6F,
    0x5FF3,
    { 0x9F, 0xFD, 0x6E, 0xFE, 0xF3, 0x21, 0x0E, 0x4E }
};
#define I_AVN_BUTTON_ABI_VERSION 10
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnButton* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnButton* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnButton* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnButton* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnButton* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnButton* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnButton* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnButton* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnButton* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnButton* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnButton* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnButton* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnButton* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnButton* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnButton* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnButton* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnButton* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnButton* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnButton* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnButton* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnButton* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnButton* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnButton* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnButton* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnButton* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnButton* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnButton* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnButton* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnButton* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnButton* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnButton* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnButton* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnButton* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnButton* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnButton* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnButton* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnButton* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnButton* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnButton* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnButton* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnButton* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnButton* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnButton* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnButton* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnButton* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnButton* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnButton* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnButton* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnButton* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnButton* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnButton* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnButton* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnButton* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnButton* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnButton* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnButton* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnButton* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnButton* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnButton* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnButton* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnButton* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnButton* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnButton* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnButton* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnButton* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_click_mode)(IAvnButton* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_click_mode)(IAvnButton* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_command)(IAvnButton* self, IAvnCommand** value); /* slot 79 */
    AvnHResult (AVN_CALL *set_command)(IAvnButton* self, IAvnCommand* value); /* slot 80 */
    AvnHResult (AVN_CALL *get_command_parameter)(IAvnButton* self, AvnVariant* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_command_parameter)(IAvnButton* self, AvnVariant value); /* slot 82 */
    AvnHResult (AVN_CALL *get_is_default)(IAvnButton* self, int32_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_is_default)(IAvnButton* self, int32_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_is_cancel)(IAvnButton* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_is_cancel)(IAvnButton* self, int32_t value); /* slot 86 */
    AvnHResult (AVN_CALL *get_is_pressed)(IAvnButton* self, int32_t* value); /* slot 87 */
    AvnHResult (AVN_CALL *get_flyout)(IAvnButton* self, IAvnFlyoutBase** value); /* slot 88 */
    AvnHResult (AVN_CALL *set_flyout)(IAvnButton* self, IAvnFlyoutBase* value); /* slot 89 */
    AvnHResult (AVN_CALL *advise_click)(IAvnButton* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 90 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnButton* self, int64_t subscription_id); /* slot 91 */
};
struct IAvnButton { const IAvnButtonVtbl* vtbl; };
#define I_AVN_BUTTON_VTABLE_SLOTS 92

static const AvnGuid I_AVN_BUTTON_SPINNER_IID = {
    0x6A6BE978,
    0x6ACE,
    0x539E,
    { 0x84, 0xF2, 0x89, 0x75, 0x7C, 0x0F, 0xCF, 0xEB }
};
#define I_AVN_BUTTON_SPINNER_ABI_VERSION 3
struct IAvnButtonSpinnerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnButtonSpinner* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnButtonSpinner* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnButtonSpinner* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnButtonSpinner* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnButtonSpinner* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnButtonSpinner* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnButtonSpinner* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnButtonSpinner* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnButtonSpinner* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnButtonSpinner* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnButtonSpinner* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnButtonSpinner* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnButtonSpinner* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnButtonSpinner* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnButtonSpinner* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnButtonSpinner* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnButtonSpinner* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnButtonSpinner* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnButtonSpinner* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnButtonSpinner* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnButtonSpinner* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnButtonSpinner* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnButtonSpinner* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnButtonSpinner* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnButtonSpinner* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnButtonSpinner* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnButtonSpinner* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnButtonSpinner* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnButtonSpinner* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnButtonSpinner* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnButtonSpinner* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnButtonSpinner* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnButtonSpinner* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnButtonSpinner* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnButtonSpinner* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnButtonSpinner* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnButtonSpinner* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnButtonSpinner* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnButtonSpinner* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnButtonSpinner* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnButtonSpinner* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnButtonSpinner* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnButtonSpinner* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnButtonSpinner* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnButtonSpinner* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnButtonSpinner* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnButtonSpinner* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnButtonSpinner* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnButtonSpinner* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnButtonSpinner* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnButtonSpinner* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnButtonSpinner* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnButtonSpinner* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnButtonSpinner* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnButtonSpinner* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnButtonSpinner* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnButtonSpinner* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnButtonSpinner* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnButtonSpinner* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnButtonSpinner* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnButtonSpinner* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnButtonSpinner* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnButtonSpinner* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnButtonSpinner* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnButtonSpinner* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnButtonSpinner* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnButtonSpinner* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnButtonSpinner* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnButtonSpinner* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnButtonSpinner* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnButtonSpinner* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnButtonSpinner* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnButtonSpinner* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnButtonSpinner* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnButtonSpinner* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnButtonSpinner* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnButtonSpinner* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_allow_spin)(IAvnButtonSpinner* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_allow_spin)(IAvnButtonSpinner* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_show_button_spinner)(IAvnButtonSpinner* self, int32_t* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_show_button_spinner)(IAvnButtonSpinner* self, int32_t value); /* slot 80 */
    AvnHResult (AVN_CALL *get_button_spinner_location)(IAvnButtonSpinner* self, int32_t* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_button_spinner_location)(IAvnButtonSpinner* self, int32_t value); /* slot 82 */
};
struct IAvnButtonSpinner { const IAvnButtonSpinnerVtbl* vtbl; };
#define I_AVN_BUTTON_SPINNER_VTABLE_SLOTS 83

static const AvnGuid I_AVN_CALENDAR_IID = {
    0x11C507E4,
    0x134D,
    0x5CDD,
    { 0xA6, 0x84, 0x38, 0x66, 0x45, 0xEB, 0x8F, 0x5E }
};
#define I_AVN_CALENDAR_ABI_VERSION 4
struct IAvnCalendarVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCalendar* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCalendar* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCalendar* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnCalendar* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnCalendar* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnCalendar* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnCalendar* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnCalendar* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnCalendar* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnCalendar* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnCalendar* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnCalendar* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnCalendar* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnCalendar* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnCalendar* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnCalendar* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnCalendar* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnCalendar* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnCalendar* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnCalendar* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnCalendar* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnCalendar* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnCalendar* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnCalendar* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnCalendar* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnCalendar* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnCalendar* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnCalendar* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnCalendar* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnCalendar* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnCalendar* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnCalendar* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnCalendar* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnCalendar* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnCalendar* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnCalendar* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnCalendar* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnCalendar* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnCalendar* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnCalendar* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnCalendar* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnCalendar* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnCalendar* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnCalendar* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnCalendar* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnCalendar* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnCalendar* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnCalendar* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnCalendar* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnCalendar* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnCalendar* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnCalendar* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnCalendar* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnCalendar* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnCalendar* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnCalendar* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnCalendar* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnCalendar* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnCalendar* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnCalendar* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnCalendar* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnCalendar* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnCalendar* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnCalendar* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnCalendar* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnCalendar* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnCalendar* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnCalendar* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnCalendar* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnCalendar* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnCalendar* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_first_day_of_week)(IAvnCalendar* self, int32_t* value); /* slot 71 */
    AvnHResult (AVN_CALL *set_first_day_of_week)(IAvnCalendar* self, int32_t value); /* slot 72 */
    AvnHResult (AVN_CALL *get_is_today_highlighted)(IAvnCalendar* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_is_today_highlighted)(IAvnCalendar* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_header_background)(IAvnCalendar* self, IAvnBrush** value); /* slot 75 */
    AvnHResult (AVN_CALL *set_header_background)(IAvnCalendar* self, IAvnBrush* value); /* slot 76 */
    AvnHResult (AVN_CALL *get_is_week_number_visible)(IAvnCalendar* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_is_week_number_visible)(IAvnCalendar* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_week_number_rule)(IAvnCalendar* self, int32_t* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_week_number_rule)(IAvnCalendar* self, int32_t value); /* slot 80 */
    AvnHResult (AVN_CALL *get_display_mode)(IAvnCalendar* self, int32_t* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_display_mode)(IAvnCalendar* self, int32_t value); /* slot 82 */
    AvnHResult (AVN_CALL *get_selection_mode)(IAvnCalendar* self, int32_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_selection_mode)(IAvnCalendar* self, int32_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_allow_tap_range_selection)(IAvnCalendar* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_allow_tap_range_selection)(IAvnCalendar* self, int32_t value); /* slot 86 */
    AvnHResult (AVN_CALL *get_selected_date)(IAvnCalendar* self, uint16_t** value); /* slot 87 */
    AvnHResult (AVN_CALL *set_selected_date)(IAvnCalendar* self, const uint16_t* value); /* slot 88 */
    AvnHResult (AVN_CALL *get_display_date)(IAvnCalendar* self, uint16_t** value); /* slot 89 */
    AvnHResult (AVN_CALL *set_display_date)(IAvnCalendar* self, const uint16_t* value); /* slot 90 */
    AvnHResult (AVN_CALL *get_display_date_start)(IAvnCalendar* self, uint16_t** value); /* slot 91 */
    AvnHResult (AVN_CALL *set_display_date_start)(IAvnCalendar* self, const uint16_t* value); /* slot 92 */
    AvnHResult (AVN_CALL *get_display_date_end)(IAvnCalendar* self, uint16_t** value); /* slot 93 */
    AvnHResult (AVN_CALL *set_display_date_end)(IAvnCalendar* self, const uint16_t* value); /* slot 94 */
};
struct IAvnCalendar { const IAvnCalendarVtbl* vtbl; };
#define I_AVN_CALENDAR_VTABLE_SLOTS 95

static const AvnGuid I_AVN_CALENDAR_DATE_PICKER_IID = {
    0x0C4CEE73,
    0x1939,
    0x512D,
    { 0x8A, 0x6A, 0x56, 0x03, 0x8F, 0x96, 0x9C, 0x80 }
};
#define I_AVN_CALENDAR_DATE_PICKER_ABI_VERSION 4
struct IAvnCalendarDatePickerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCalendarDatePicker* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCalendarDatePicker* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCalendarDatePicker* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnCalendarDatePicker* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnCalendarDatePicker* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnCalendarDatePicker* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnCalendarDatePicker* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnCalendarDatePicker* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnCalendarDatePicker* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnCalendarDatePicker* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnCalendarDatePicker* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnCalendarDatePicker* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnCalendarDatePicker* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnCalendarDatePicker* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnCalendarDatePicker* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnCalendarDatePicker* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnCalendarDatePicker* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnCalendarDatePicker* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnCalendarDatePicker* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnCalendarDatePicker* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnCalendarDatePicker* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnCalendarDatePicker* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnCalendarDatePicker* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnCalendarDatePicker* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnCalendarDatePicker* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnCalendarDatePicker* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnCalendarDatePicker* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnCalendarDatePicker* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnCalendarDatePicker* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnCalendarDatePicker* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnCalendarDatePicker* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnCalendarDatePicker* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnCalendarDatePicker* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnCalendarDatePicker* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnCalendarDatePicker* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnCalendarDatePicker* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnCalendarDatePicker* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnCalendarDatePicker* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnCalendarDatePicker* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnCalendarDatePicker* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnCalendarDatePicker* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnCalendarDatePicker* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnCalendarDatePicker* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnCalendarDatePicker* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnCalendarDatePicker* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnCalendarDatePicker* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnCalendarDatePicker* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnCalendarDatePicker* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnCalendarDatePicker* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnCalendarDatePicker* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnCalendarDatePicker* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnCalendarDatePicker* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnCalendarDatePicker* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnCalendarDatePicker* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnCalendarDatePicker* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnCalendarDatePicker* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnCalendarDatePicker* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnCalendarDatePicker* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnCalendarDatePicker* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnCalendarDatePicker* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnCalendarDatePicker* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnCalendarDatePicker* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnCalendarDatePicker* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnCalendarDatePicker* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnCalendarDatePicker* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnCalendarDatePicker* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnCalendarDatePicker* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnCalendarDatePicker* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnCalendarDatePicker* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnCalendarDatePicker* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnCalendarDatePicker* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_display_date)(IAvnCalendarDatePicker* self, uint16_t** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_display_date)(IAvnCalendarDatePicker* self, const uint16_t* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_display_date_start)(IAvnCalendarDatePicker* self, uint16_t** value); /* slot 73 */
    AvnHResult (AVN_CALL *set_display_date_start)(IAvnCalendarDatePicker* self, const uint16_t* value); /* slot 74 */
    AvnHResult (AVN_CALL *get_display_date_end)(IAvnCalendarDatePicker* self, uint16_t** value); /* slot 75 */
    AvnHResult (AVN_CALL *set_display_date_end)(IAvnCalendarDatePicker* self, const uint16_t* value); /* slot 76 */
    AvnHResult (AVN_CALL *get_first_day_of_week)(IAvnCalendarDatePicker* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_first_day_of_week)(IAvnCalendarDatePicker* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_is_drop_down_open)(IAvnCalendarDatePicker* self, int32_t* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_is_drop_down_open)(IAvnCalendarDatePicker* self, int32_t value); /* slot 80 */
    AvnHResult (AVN_CALL *get_is_today_highlighted)(IAvnCalendarDatePicker* self, int32_t* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_is_today_highlighted)(IAvnCalendarDatePicker* self, int32_t value); /* slot 82 */
    AvnHResult (AVN_CALL *get_selected_date)(IAvnCalendarDatePicker* self, uint16_t** value); /* slot 83 */
    AvnHResult (AVN_CALL *set_selected_date)(IAvnCalendarDatePicker* self, const uint16_t* value); /* slot 84 */
    AvnHResult (AVN_CALL *get_selected_date_format)(IAvnCalendarDatePicker* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_selected_date_format)(IAvnCalendarDatePicker* self, int32_t value); /* slot 86 */
    AvnHResult (AVN_CALL *get_custom_date_format_string)(IAvnCalendarDatePicker* self, uint16_t** value); /* slot 87 */
    AvnHResult (AVN_CALL *set_custom_date_format_string)(IAvnCalendarDatePicker* self, const uint16_t* value); /* slot 88 */
    AvnHResult (AVN_CALL *get_text)(IAvnCalendarDatePicker* self, uint16_t** value); /* slot 89 */
    AvnHResult (AVN_CALL *set_text)(IAvnCalendarDatePicker* self, const uint16_t* value); /* slot 90 */
    AvnHResult (AVN_CALL *get_placeholder_text)(IAvnCalendarDatePicker* self, uint16_t** value); /* slot 91 */
    AvnHResult (AVN_CALL *set_placeholder_text)(IAvnCalendarDatePicker* self, const uint16_t* value); /* slot 92 */
    AvnHResult (AVN_CALL *get_use_floating_placeholder)(IAvnCalendarDatePicker* self, int32_t* value); /* slot 93 */
    AvnHResult (AVN_CALL *set_use_floating_placeholder)(IAvnCalendarDatePicker* self, int32_t value); /* slot 94 */
    AvnHResult (AVN_CALL *get_placeholder_foreground)(IAvnCalendarDatePicker* self, IAvnBrush** value); /* slot 95 */
    AvnHResult (AVN_CALL *set_placeholder_foreground)(IAvnCalendarDatePicker* self, IAvnBrush* value); /* slot 96 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnCalendarDatePicker* self, int32_t* value); /* slot 97 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnCalendarDatePicker* self, int32_t value); /* slot 98 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnCalendarDatePicker* self, int32_t* value); /* slot 99 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnCalendarDatePicker* self, int32_t value); /* slot 100 */
    AvnHResult (AVN_CALL *get_is_week_number_visible)(IAvnCalendarDatePicker* self, int32_t* value); /* slot 101 */
    AvnHResult (AVN_CALL *set_is_week_number_visible)(IAvnCalendarDatePicker* self, int32_t value); /* slot 102 */
    AvnHResult (AVN_CALL *get_week_number_rule)(IAvnCalendarDatePicker* self, int32_t* value); /* slot 103 */
    AvnHResult (AVN_CALL *set_week_number_rule)(IAvnCalendarDatePicker* self, int32_t value); /* slot 104 */
    AvnHResult (AVN_CALL *clear)(IAvnCalendarDatePicker* self); /* slot 105 */
    AvnHResult (AVN_CALL *advise_calendar_closed)(IAvnCalendarDatePicker* self, IAvnCalendarDatePickerCalendarClosedHandler* handler, int64_t* subscription_id); /* slot 106 */
    AvnHResult (AVN_CALL *unadvise_calendar_closed)(IAvnCalendarDatePicker* self, int64_t subscription_id); /* slot 107 */
    AvnHResult (AVN_CALL *advise_calendar_opened)(IAvnCalendarDatePicker* self, IAvnCalendarDatePickerCalendarOpenedHandler* handler, int64_t* subscription_id); /* slot 108 */
    AvnHResult (AVN_CALL *unadvise_calendar_opened)(IAvnCalendarDatePicker* self, int64_t subscription_id); /* slot 109 */
};
struct IAvnCalendarDatePicker { const IAvnCalendarDatePickerVtbl* vtbl; };
#define I_AVN_CALENDAR_DATE_PICKER_VTABLE_SLOTS 110

static const AvnGuid I_AVN_CANVAS_IID = {
    0x3FCDAC92,
    0x9070,
    0x5460,
    { 0x99, 0xF7, 0xBF, 0x91, 0x61, 0x15, 0x50, 0x79 }
};
#define I_AVN_CANVAS_ABI_VERSION 5
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnCanvas* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnCanvas* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnCanvas* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnCanvas* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnCanvas* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnCanvas* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnCanvas* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnCanvas* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnCanvas* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnCanvas* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnCanvas* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnCanvas* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnCanvas* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnCanvas* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnCanvas* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnCanvas* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnCanvas* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnCanvas* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnCanvas* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnCanvas* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnCanvas* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnCanvas* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnCanvas* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnCanvas* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnCanvas* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnCanvas* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnCanvas* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnCanvas* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnCanvas* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnCanvas* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnCanvas* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnCanvas* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnCanvas* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnCanvas* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnCanvas* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_children)(IAvnCanvas* self, IAvnControlList** value); /* slot 47 */
    AvnHResult (AVN_CALL *get_background)(IAvnCanvas* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_background)(IAvnCanvas* self, IAvnBrush* value); /* slot 49 */
};
struct IAvnCanvas { const IAvnCanvasVtbl* vtbl; };
#define I_AVN_CANVAS_VTABLE_SLOTS 50

static const AvnGuid I_AVN_CAROUSEL_IID = {
    0xB3A6F28E,
    0x71B6,
    0x5043,
    { 0xA9, 0x0C, 0xBF, 0x9B, 0x42, 0xCA, 0x23, 0x12 }
};
#define I_AVN_CAROUSEL_ABI_VERSION 5
struct IAvnCarouselVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCarousel* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCarousel* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCarousel* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnCarousel* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnCarousel* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnCarousel* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnCarousel* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnCarousel* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnCarousel* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnCarousel* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnCarousel* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnCarousel* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnCarousel* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnCarousel* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnCarousel* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnCarousel* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnCarousel* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnCarousel* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnCarousel* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnCarousel* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnCarousel* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnCarousel* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnCarousel* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnCarousel* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnCarousel* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnCarousel* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnCarousel* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnCarousel* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnCarousel* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnCarousel* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnCarousel* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnCarousel* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnCarousel* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnCarousel* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnCarousel* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnCarousel* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnCarousel* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnCarousel* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnCarousel* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnCarousel* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnCarousel* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnCarousel* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnCarousel* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnCarousel* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnCarousel* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnCarousel* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnCarousel* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnCarousel* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnCarousel* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnCarousel* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnCarousel* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnCarousel* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnCarousel* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnCarousel* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnCarousel* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnCarousel* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnCarousel* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnCarousel* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnCarousel* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnCarousel* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnCarousel* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnCarousel* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnCarousel* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnCarousel* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnCarousel* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnCarousel* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnCarousel* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnCarousel* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnCarousel* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnCarousel* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnCarousel* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_items)(IAvnCarousel* self, IAvnItemList** value); /* slot 71 */
    AvnHResult (AVN_CALL *get_item_count)(IAvnCarousel* self, int32_t* value); /* slot 72 */
    AvnHResult (AVN_CALL *scroll_into_view_with_int32)(IAvnCarousel* self, int32_t index); /* slot 73 */
    AvnHResult (AVN_CALL *get_auto_scroll_to_selected_item)(IAvnCarousel* self, int32_t* value); /* slot 74 */
    AvnHResult (AVN_CALL *set_auto_scroll_to_selected_item)(IAvnCarousel* self, int32_t value); /* slot 75 */
    AvnHResult (AVN_CALL *get_selected_index)(IAvnCarousel* self, int32_t* value); /* slot 76 */
    AvnHResult (AVN_CALL *set_selected_index)(IAvnCarousel* self, int32_t value); /* slot 77 */
    AvnHResult (AVN_CALL *get_is_text_search_enabled)(IAvnCarousel* self, int32_t* value); /* slot 78 */
    AvnHResult (AVN_CALL *set_is_text_search_enabled)(IAvnCarousel* self, int32_t value); /* slot 79 */
    AvnHResult (AVN_CALL *get_wrap_selection)(IAvnCarousel* self, int32_t* value); /* slot 80 */
    AvnHResult (AVN_CALL *set_wrap_selection)(IAvnCarousel* self, int32_t value); /* slot 81 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnCarousel* self, IAvnSelectingItemsControlSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 82 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnCarousel* self, int64_t subscription_id); /* slot 83 */
    AvnHResult (AVN_CALL *get_is_swipe_enabled)(IAvnCarousel* self, int32_t* value); /* slot 84 */
    AvnHResult (AVN_CALL *set_is_swipe_enabled)(IAvnCarousel* self, int32_t value); /* slot 85 */
    AvnHResult (AVN_CALL *get_viewport_fraction)(IAvnCarousel* self, double* value); /* slot 86 */
    AvnHResult (AVN_CALL *set_viewport_fraction)(IAvnCarousel* self, double value); /* slot 87 */
    AvnHResult (AVN_CALL *get_is_swiping)(IAvnCarousel* self, int32_t* value); /* slot 88 */
    AvnHResult (AVN_CALL *next)(IAvnCarousel* self); /* slot 89 */
    AvnHResult (AVN_CALL *previous)(IAvnCarousel* self); /* slot 90 */
};
struct IAvnCarousel { const IAvnCarouselVtbl* vtbl; };
#define I_AVN_CAROUSEL_VTABLE_SLOTS 91

static const AvnGuid I_AVN_CHECK_BOX_IID = {
    0x87BCFC2E,
    0xFAC2,
    0x531D,
    { 0x88, 0xFA, 0xF0, 0x3C, 0x3E, 0x6D, 0x48, 0xAD }
};
#define I_AVN_CHECK_BOX_ABI_VERSION 10
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnCheckBox* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnCheckBox* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnCheckBox* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnCheckBox* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnCheckBox* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnCheckBox* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnCheckBox* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnCheckBox* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnCheckBox* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnCheckBox* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnCheckBox* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnCheckBox* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnCheckBox* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnCheckBox* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnCheckBox* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnCheckBox* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnCheckBox* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnCheckBox* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnCheckBox* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnCheckBox* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnCheckBox* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnCheckBox* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnCheckBox* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnCheckBox* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnCheckBox* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnCheckBox* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnCheckBox* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnCheckBox* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnCheckBox* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnCheckBox* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnCheckBox* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnCheckBox* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnCheckBox* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnCheckBox* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnCheckBox* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnCheckBox* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnCheckBox* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnCheckBox* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnCheckBox* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnCheckBox* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnCheckBox* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnCheckBox* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnCheckBox* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnCheckBox* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnCheckBox* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnCheckBox* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnCheckBox* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnCheckBox* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnCheckBox* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnCheckBox* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnCheckBox* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnCheckBox* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnCheckBox* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnCheckBox* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnCheckBox* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnCheckBox* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnCheckBox* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnCheckBox* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnCheckBox* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnCheckBox* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnCheckBox* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnCheckBox* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnCheckBox* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnCheckBox* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnCheckBox* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_click_mode)(IAvnCheckBox* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_click_mode)(IAvnCheckBox* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_command)(IAvnCheckBox* self, IAvnCommand** value); /* slot 79 */
    AvnHResult (AVN_CALL *set_command)(IAvnCheckBox* self, IAvnCommand* value); /* slot 80 */
    AvnHResult (AVN_CALL *get_command_parameter)(IAvnCheckBox* self, AvnVariant* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_command_parameter)(IAvnCheckBox* self, AvnVariant value); /* slot 82 */
    AvnHResult (AVN_CALL *get_is_default)(IAvnCheckBox* self, int32_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_is_default)(IAvnCheckBox* self, int32_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_is_cancel)(IAvnCheckBox* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_is_cancel)(IAvnCheckBox* self, int32_t value); /* slot 86 */
    AvnHResult (AVN_CALL *get_is_pressed)(IAvnCheckBox* self, int32_t* value); /* slot 87 */
    AvnHResult (AVN_CALL *get_flyout)(IAvnCheckBox* self, IAvnFlyoutBase** value); /* slot 88 */
    AvnHResult (AVN_CALL *set_flyout)(IAvnCheckBox* self, IAvnFlyoutBase* value); /* slot 89 */
    AvnHResult (AVN_CALL *advise_click)(IAvnCheckBox* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 90 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnCheckBox* self, int64_t subscription_id); /* slot 91 */
    AvnHResult (AVN_CALL *get_is_checked)(IAvnCheckBox* self, int32_t* value); /* slot 92 */
    AvnHResult (AVN_CALL *set_is_checked)(IAvnCheckBox* self, int32_t value); /* slot 93 */
    AvnHResult (AVN_CALL *get_is_three_state)(IAvnCheckBox* self, int32_t* value); /* slot 94 */
    AvnHResult (AVN_CALL *set_is_three_state)(IAvnCheckBox* self, int32_t value); /* slot 95 */
    AvnHResult (AVN_CALL *advise_is_checked_changed)(IAvnCheckBox* self, IAvnToggleButtonIsCheckedChangedHandler* handler, int64_t* subscription_id); /* slot 96 */
    AvnHResult (AVN_CALL *unadvise_is_checked_changed)(IAvnCheckBox* self, int64_t subscription_id); /* slot 97 */
};
struct IAvnCheckBox { const IAvnCheckBoxVtbl* vtbl; };
#define I_AVN_CHECK_BOX_VTABLE_SLOTS 98

static const AvnGuid I_AVN_COMBO_BOX_IID = {
    0x151EDFBA,
    0xD25F,
    0x5E3D,
    { 0x86, 0x4F, 0x57, 0x2B, 0x91, 0xC0, 0x48, 0xF8 }
};
#define I_AVN_COMBO_BOX_ABI_VERSION 9
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnComboBox* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnComboBox* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnComboBox* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnComboBox* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnComboBox* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnComboBox* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnComboBox* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnComboBox* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnComboBox* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnComboBox* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnComboBox* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnComboBox* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnComboBox* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnComboBox* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnComboBox* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnComboBox* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnComboBox* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnComboBox* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnComboBox* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnComboBox* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnComboBox* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnComboBox* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnComboBox* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnComboBox* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnComboBox* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnComboBox* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnComboBox* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnComboBox* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnComboBox* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnComboBox* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnComboBox* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnComboBox* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnComboBox* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnComboBox* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnComboBox* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnComboBox* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnComboBox* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnComboBox* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnComboBox* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnComboBox* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnComboBox* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnComboBox* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnComboBox* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnComboBox* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnComboBox* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnComboBox* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnComboBox* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnComboBox* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnComboBox* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnComboBox* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnComboBox* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnComboBox* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnComboBox* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnComboBox* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnComboBox* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnComboBox* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnComboBox* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnComboBox* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnComboBox* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_items)(IAvnComboBox* self, IAvnItemList** value); /* slot 71 */
    AvnHResult (AVN_CALL *get_item_count)(IAvnComboBox* self, int32_t* value); /* slot 72 */
    AvnHResult (AVN_CALL *scroll_into_view_with_int32)(IAvnComboBox* self, int32_t index); /* slot 73 */
    AvnHResult (AVN_CALL *get_auto_scroll_to_selected_item)(IAvnComboBox* self, int32_t* value); /* slot 74 */
    AvnHResult (AVN_CALL *set_auto_scroll_to_selected_item)(IAvnComboBox* self, int32_t value); /* slot 75 */
    AvnHResult (AVN_CALL *get_selected_index)(IAvnComboBox* self, int32_t* value); /* slot 76 */
    AvnHResult (AVN_CALL *set_selected_index)(IAvnComboBox* self, int32_t value); /* slot 77 */
    AvnHResult (AVN_CALL *get_is_text_search_enabled)(IAvnComboBox* self, int32_t* value); /* slot 78 */
    AvnHResult (AVN_CALL *set_is_text_search_enabled)(IAvnComboBox* self, int32_t value); /* slot 79 */
    AvnHResult (AVN_CALL *get_wrap_selection)(IAvnComboBox* self, int32_t* value); /* slot 80 */
    AvnHResult (AVN_CALL *set_wrap_selection)(IAvnComboBox* self, int32_t value); /* slot 81 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnComboBox* self, IAvnSelectingItemsControlSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 82 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnComboBox* self, int64_t subscription_id); /* slot 83 */
    AvnHResult (AVN_CALL *get_is_drop_down_open)(IAvnComboBox* self, int32_t* value); /* slot 84 */
    AvnHResult (AVN_CALL *set_is_drop_down_open)(IAvnComboBox* self, int32_t value); /* slot 85 */
    AvnHResult (AVN_CALL *get_is_editable)(IAvnComboBox* self, int32_t* value); /* slot 86 */
    AvnHResult (AVN_CALL *set_is_editable)(IAvnComboBox* self, int32_t value); /* slot 87 */
    AvnHResult (AVN_CALL *get_max_drop_down_height)(IAvnComboBox* self, double* value); /* slot 88 */
    AvnHResult (AVN_CALL *set_max_drop_down_height)(IAvnComboBox* self, double value); /* slot 89 */
    AvnHResult (AVN_CALL *get_placeholder_text)(IAvnComboBox* self, uint16_t** value); /* slot 90 */
    AvnHResult (AVN_CALL *set_placeholder_text)(IAvnComboBox* self, const uint16_t* value); /* slot 91 */
    AvnHResult (AVN_CALL *get_placeholder_foreground)(IAvnComboBox* self, IAvnBrush** value); /* slot 92 */
    AvnHResult (AVN_CALL *set_placeholder_foreground)(IAvnComboBox* self, IAvnBrush* value); /* slot 93 */
    AvnHResult (AVN_CALL *get_text)(IAvnComboBox* self, uint16_t** value); /* slot 94 */
    AvnHResult (AVN_CALL *set_text)(IAvnComboBox* self, const uint16_t* value); /* slot 95 */
    AvnHResult (AVN_CALL *clear)(IAvnComboBox* self); /* slot 96 */
    AvnHResult (AVN_CALL *advise_drop_down_closed)(IAvnComboBox* self, IAvnComboBoxDropDownClosedHandler* handler, int64_t* subscription_id); /* slot 97 */
    AvnHResult (AVN_CALL *unadvise_drop_down_closed)(IAvnComboBox* self, int64_t subscription_id); /* slot 98 */
    AvnHResult (AVN_CALL *advise_drop_down_opened)(IAvnComboBox* self, IAvnComboBoxDropDownOpenedHandler* handler, int64_t* subscription_id); /* slot 99 */
    AvnHResult (AVN_CALL *unadvise_drop_down_opened)(IAvnComboBox* self, int64_t subscription_id); /* slot 100 */
};
struct IAvnComboBox { const IAvnComboBoxVtbl* vtbl; };
#define I_AVN_COMBO_BOX_VTABLE_SLOTS 101

static const AvnGuid I_AVN_COMBO_BOX_ITEM_IID = {
    0xBA6A6174,
    0x31FB,
    0x529F,
    { 0xB3, 0xD4, 0xE2, 0xD5, 0xAC, 0x81, 0x90, 0x06 }
};
#define I_AVN_COMBO_BOX_ITEM_ABI_VERSION 7
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnComboBoxItem* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnComboBoxItem* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnComboBoxItem* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnComboBoxItem* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnComboBoxItem* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnComboBoxItem* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnComboBoxItem* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnComboBoxItem* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnComboBoxItem* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnComboBoxItem* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnComboBoxItem* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnComboBoxItem* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnComboBoxItem* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnComboBoxItem* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnComboBoxItem* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnComboBoxItem* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnComboBoxItem* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnComboBoxItem* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnComboBoxItem* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnComboBoxItem* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnComboBoxItem* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnComboBoxItem* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnComboBoxItem* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnComboBoxItem* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnComboBoxItem* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnComboBoxItem* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnComboBoxItem* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnComboBoxItem* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnComboBoxItem* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnComboBoxItem* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnComboBoxItem* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnComboBoxItem* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnComboBoxItem* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnComboBoxItem* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnComboBoxItem* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnComboBoxItem* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnComboBoxItem* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnComboBoxItem* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnComboBoxItem* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnComboBoxItem* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnComboBoxItem* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnComboBoxItem* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnComboBoxItem* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnComboBoxItem* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnComboBoxItem* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnComboBoxItem* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnComboBoxItem* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnComboBoxItem* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnComboBoxItem* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnComboBoxItem* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnComboBoxItem* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnComboBoxItem* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnComboBoxItem* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnComboBoxItem* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnComboBoxItem* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnComboBoxItem* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnComboBoxItem* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnComboBoxItem* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnComboBoxItem* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnComboBoxItem* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnComboBoxItem* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnComboBoxItem* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnComboBoxItem* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnComboBoxItem* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnComboBoxItem* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_is_selected)(IAvnComboBoxItem* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_is_selected)(IAvnComboBoxItem* self, int32_t value); /* slot 78 */
};
struct IAvnComboBoxItem { const IAvnComboBoxItemVtbl* vtbl; };
#define I_AVN_COMBO_BOX_ITEM_VTABLE_SLOTS 79

static const AvnGuid I_AVN_COMMAND_BAR_IID = {
    0x8853C1F6,
    0x3E2B,
    0x5B5C,
    { 0x9C, 0xE5, 0x30, 0x5A, 0x55, 0x80, 0x74, 0x1A }
};
#define I_AVN_COMMAND_BAR_ABI_VERSION 5
struct IAvnCommandBarVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCommandBar* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCommandBar* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCommandBar* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnCommandBar* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnCommandBar* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnCommandBar* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnCommandBar* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnCommandBar* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnCommandBar* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnCommandBar* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnCommandBar* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnCommandBar* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnCommandBar* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnCommandBar* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnCommandBar* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnCommandBar* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnCommandBar* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnCommandBar* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnCommandBar* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnCommandBar* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnCommandBar* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnCommandBar* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnCommandBar* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnCommandBar* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnCommandBar* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnCommandBar* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnCommandBar* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnCommandBar* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnCommandBar* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnCommandBar* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnCommandBar* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnCommandBar* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnCommandBar* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnCommandBar* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnCommandBar* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnCommandBar* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnCommandBar* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnCommandBar* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnCommandBar* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnCommandBar* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnCommandBar* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnCommandBar* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnCommandBar* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnCommandBar* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnCommandBar* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnCommandBar* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnCommandBar* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnCommandBar* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnCommandBar* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnCommandBar* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnCommandBar* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnCommandBar* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnCommandBar* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnCommandBar* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnCommandBar* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnCommandBar* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnCommandBar* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnCommandBar* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnCommandBar* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnCommandBar* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnCommandBar* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnCommandBar* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnCommandBar* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnCommandBar* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnCommandBar* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnCommandBar* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnCommandBar* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnCommandBar* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnCommandBar* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnCommandBar* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnCommandBar* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnCommandBar* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnCommandBar* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_default_label_position)(IAvnCommandBar* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_default_label_position)(IAvnCommandBar* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_is_dynamic_overflow_enabled)(IAvnCommandBar* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_is_dynamic_overflow_enabled)(IAvnCommandBar* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_overflow_button_visibility)(IAvnCommandBar* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_overflow_button_visibility)(IAvnCommandBar* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_is_open)(IAvnCommandBar* self, int32_t* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_is_open)(IAvnCommandBar* self, int32_t value); /* slot 80 */
    AvnHResult (AVN_CALL *get_is_sticky)(IAvnCommandBar* self, int32_t* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_is_sticky)(IAvnCommandBar* self, int32_t value); /* slot 82 */
    AvnHResult (AVN_CALL *get_item_width_bottom)(IAvnCommandBar* self, double* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_item_width_bottom)(IAvnCommandBar* self, double value); /* slot 84 */
    AvnHResult (AVN_CALL *get_item_width_right)(IAvnCommandBar* self, double* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_item_width_right)(IAvnCommandBar* self, double value); /* slot 86 */
    AvnHResult (AVN_CALL *get_item_width_collapsed)(IAvnCommandBar* self, double* value); /* slot 87 */
    AvnHResult (AVN_CALL *set_item_width_collapsed)(IAvnCommandBar* self, double value); /* slot 88 */
    AvnHResult (AVN_CALL *get_has_secondary_commands)(IAvnCommandBar* self, int32_t* value); /* slot 89 */
    AvnHResult (AVN_CALL *get_is_overflow_button_visible)(IAvnCommandBar* self, int32_t* value); /* slot 90 */
    AvnHResult (AVN_CALL *advise_opening)(IAvnCommandBar* self, IAvnCommandBarOpeningHandler* handler, int64_t* subscription_id); /* slot 91 */
    AvnHResult (AVN_CALL *unadvise_opening)(IAvnCommandBar* self, int64_t subscription_id); /* slot 92 */
    AvnHResult (AVN_CALL *advise_opened)(IAvnCommandBar* self, IAvnCommandBarOpenedHandler* handler, int64_t* subscription_id); /* slot 93 */
    AvnHResult (AVN_CALL *unadvise_opened)(IAvnCommandBar* self, int64_t subscription_id); /* slot 94 */
    AvnHResult (AVN_CALL *advise_closing)(IAvnCommandBar* self, IAvnCommandBarClosingHandler* handler, int64_t* subscription_id); /* slot 95 */
    AvnHResult (AVN_CALL *unadvise_closing)(IAvnCommandBar* self, int64_t subscription_id); /* slot 96 */
    AvnHResult (AVN_CALL *advise_closed)(IAvnCommandBar* self, IAvnCommandBarClosedHandler* handler, int64_t* subscription_id); /* slot 97 */
    AvnHResult (AVN_CALL *unadvise_closed)(IAvnCommandBar* self, int64_t subscription_id); /* slot 98 */
};
struct IAvnCommandBar { const IAvnCommandBarVtbl* vtbl; };
#define I_AVN_COMMAND_BAR_VTABLE_SLOTS 99

static const AvnGuid I_AVN_COMMAND_BAR_BUTTON_IID = {
    0x79ECE92B,
    0xB507,
    0x5D64,
    { 0x90, 0xF2, 0x0D, 0xB4, 0x5A, 0x7F, 0xA0, 0x6D }
};
#define I_AVN_COMMAND_BAR_BUTTON_ABI_VERSION 5
struct IAvnCommandBarButtonVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCommandBarButton* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCommandBarButton* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCommandBarButton* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnCommandBarButton* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnCommandBarButton* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnCommandBarButton* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnCommandBarButton* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnCommandBarButton* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnCommandBarButton* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnCommandBarButton* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnCommandBarButton* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnCommandBarButton* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnCommandBarButton* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnCommandBarButton* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnCommandBarButton* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnCommandBarButton* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnCommandBarButton* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnCommandBarButton* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnCommandBarButton* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnCommandBarButton* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnCommandBarButton* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnCommandBarButton* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnCommandBarButton* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnCommandBarButton* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnCommandBarButton* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnCommandBarButton* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnCommandBarButton* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnCommandBarButton* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnCommandBarButton* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnCommandBarButton* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnCommandBarButton* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnCommandBarButton* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnCommandBarButton* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnCommandBarButton* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnCommandBarButton* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnCommandBarButton* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnCommandBarButton* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnCommandBarButton* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnCommandBarButton* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnCommandBarButton* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnCommandBarButton* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnCommandBarButton* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnCommandBarButton* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnCommandBarButton* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnCommandBarButton* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnCommandBarButton* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnCommandBarButton* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnCommandBarButton* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnCommandBarButton* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnCommandBarButton* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnCommandBarButton* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnCommandBarButton* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnCommandBarButton* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnCommandBarButton* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnCommandBarButton* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnCommandBarButton* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnCommandBarButton* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnCommandBarButton* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnCommandBarButton* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnCommandBarButton* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnCommandBarButton* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnCommandBarButton* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnCommandBarButton* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnCommandBarButton* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnCommandBarButton* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnCommandBarButton* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnCommandBarButton* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnCommandBarButton* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnCommandBarButton* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnCommandBarButton* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnCommandBarButton* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnCommandBarButton* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnCommandBarButton* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnCommandBarButton* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnCommandBarButton* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnCommandBarButton* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnCommandBarButton* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_click_mode)(IAvnCommandBarButton* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_click_mode)(IAvnCommandBarButton* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_command)(IAvnCommandBarButton* self, IAvnCommand** value); /* slot 79 */
    AvnHResult (AVN_CALL *set_command)(IAvnCommandBarButton* self, IAvnCommand* value); /* slot 80 */
    AvnHResult (AVN_CALL *get_command_parameter)(IAvnCommandBarButton* self, AvnVariant* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_command_parameter)(IAvnCommandBarButton* self, AvnVariant value); /* slot 82 */
    AvnHResult (AVN_CALL *get_is_default)(IAvnCommandBarButton* self, int32_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_is_default)(IAvnCommandBarButton* self, int32_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_is_cancel)(IAvnCommandBarButton* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_is_cancel)(IAvnCommandBarButton* self, int32_t value); /* slot 86 */
    AvnHResult (AVN_CALL *get_is_pressed)(IAvnCommandBarButton* self, int32_t* value); /* slot 87 */
    AvnHResult (AVN_CALL *get_flyout)(IAvnCommandBarButton* self, IAvnFlyoutBase** value); /* slot 88 */
    AvnHResult (AVN_CALL *set_flyout)(IAvnCommandBarButton* self, IAvnFlyoutBase* value); /* slot 89 */
    AvnHResult (AVN_CALL *advise_click)(IAvnCommandBarButton* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 90 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnCommandBarButton* self, int64_t subscription_id); /* slot 91 */
    AvnHResult (AVN_CALL *get_label)(IAvnCommandBarButton* self, uint16_t** value); /* slot 92 */
    AvnHResult (AVN_CALL *set_label)(IAvnCommandBarButton* self, const uint16_t* value); /* slot 93 */
    AvnHResult (AVN_CALL *get_is_compact)(IAvnCommandBarButton* self, int32_t* value); /* slot 94 */
    AvnHResult (AVN_CALL *set_is_compact)(IAvnCommandBarButton* self, int32_t value); /* slot 95 */
    AvnHResult (AVN_CALL *get_dynamic_overflow_order)(IAvnCommandBarButton* self, int32_t* value); /* slot 96 */
    AvnHResult (AVN_CALL *set_dynamic_overflow_order)(IAvnCommandBarButton* self, int32_t value); /* slot 97 */
    AvnHResult (AVN_CALL *get_label_position)(IAvnCommandBarButton* self, int32_t* value); /* slot 98 */
    AvnHResult (AVN_CALL *set_label_position)(IAvnCommandBarButton* self, int32_t value); /* slot 99 */
    AvnHResult (AVN_CALL *get_is_in_overflow)(IAvnCommandBarButton* self, int32_t* value); /* slot 100 */
    AvnHResult (AVN_CALL *set_is_in_overflow)(IAvnCommandBarButton* self, int32_t value); /* slot 101 */
};
struct IAvnCommandBarButton { const IAvnCommandBarButtonVtbl* vtbl; };
#define I_AVN_COMMAND_BAR_BUTTON_VTABLE_SLOTS 102

static const AvnGuid I_AVN_COMMAND_BAR_SEPARATOR_IID = {
    0x5859273F,
    0x9C0D,
    0x5630,
    { 0xB2, 0xE1, 0x97, 0x0A, 0x3C, 0x5C, 0xC5, 0xC8 }
};
#define I_AVN_COMMAND_BAR_SEPARATOR_ABI_VERSION 3
struct IAvnCommandBarSeparatorVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCommandBarSeparator* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCommandBarSeparator* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCommandBarSeparator* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnCommandBarSeparator* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnCommandBarSeparator* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnCommandBarSeparator* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnCommandBarSeparator* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnCommandBarSeparator* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnCommandBarSeparator* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnCommandBarSeparator* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnCommandBarSeparator* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnCommandBarSeparator* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnCommandBarSeparator* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnCommandBarSeparator* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnCommandBarSeparator* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnCommandBarSeparator* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnCommandBarSeparator* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnCommandBarSeparator* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnCommandBarSeparator* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnCommandBarSeparator* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnCommandBarSeparator* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnCommandBarSeparator* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnCommandBarSeparator* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnCommandBarSeparator* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnCommandBarSeparator* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnCommandBarSeparator* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnCommandBarSeparator* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnCommandBarSeparator* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnCommandBarSeparator* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnCommandBarSeparator* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnCommandBarSeparator* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnCommandBarSeparator* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnCommandBarSeparator* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnCommandBarSeparator* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnCommandBarSeparator* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnCommandBarSeparator* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnCommandBarSeparator* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnCommandBarSeparator* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnCommandBarSeparator* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnCommandBarSeparator* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnCommandBarSeparator* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnCommandBarSeparator* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnCommandBarSeparator* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnCommandBarSeparator* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnCommandBarSeparator* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnCommandBarSeparator* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnCommandBarSeparator* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnCommandBarSeparator* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnCommandBarSeparator* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnCommandBarSeparator* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnCommandBarSeparator* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnCommandBarSeparator* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnCommandBarSeparator* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnCommandBarSeparator* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnCommandBarSeparator* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnCommandBarSeparator* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnCommandBarSeparator* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnCommandBarSeparator* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnCommandBarSeparator* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnCommandBarSeparator* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnCommandBarSeparator* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnCommandBarSeparator* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnCommandBarSeparator* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnCommandBarSeparator* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnCommandBarSeparator* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnCommandBarSeparator* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnCommandBarSeparator* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnCommandBarSeparator* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnCommandBarSeparator* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnCommandBarSeparator* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnCommandBarSeparator* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_is_compact)(IAvnCommandBarSeparator* self, int32_t* value); /* slot 71 */
    AvnHResult (AVN_CALL *set_is_compact)(IAvnCommandBarSeparator* self, int32_t value); /* slot 72 */
    AvnHResult (AVN_CALL *get_is_in_overflow)(IAvnCommandBarSeparator* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_is_in_overflow)(IAvnCommandBarSeparator* self, int32_t value); /* slot 74 */
};
struct IAvnCommandBarSeparator { const IAvnCommandBarSeparatorVtbl* vtbl; };
#define I_AVN_COMMAND_BAR_SEPARATOR_VTABLE_SLOTS 75

static const AvnGuid I_AVN_COMMAND_BAR_TOGGLE_BUTTON_IID = {
    0xD4E7FE62,
    0x9B9A,
    0x56D0,
    { 0xAF, 0x9E, 0x48, 0x67, 0x0B, 0x8F, 0x74, 0xC6 }
};
#define I_AVN_COMMAND_BAR_TOGGLE_BUTTON_ABI_VERSION 5
struct IAvnCommandBarToggleButtonVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnCommandBarToggleButton* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnCommandBarToggleButton* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnCommandBarToggleButton* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnCommandBarToggleButton* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnCommandBarToggleButton* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnCommandBarToggleButton* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnCommandBarToggleButton* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnCommandBarToggleButton* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnCommandBarToggleButton* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnCommandBarToggleButton* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnCommandBarToggleButton* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnCommandBarToggleButton* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnCommandBarToggleButton* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnCommandBarToggleButton* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnCommandBarToggleButton* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnCommandBarToggleButton* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnCommandBarToggleButton* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnCommandBarToggleButton* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnCommandBarToggleButton* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnCommandBarToggleButton* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnCommandBarToggleButton* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnCommandBarToggleButton* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnCommandBarToggleButton* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnCommandBarToggleButton* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnCommandBarToggleButton* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnCommandBarToggleButton* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnCommandBarToggleButton* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnCommandBarToggleButton* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnCommandBarToggleButton* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnCommandBarToggleButton* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnCommandBarToggleButton* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnCommandBarToggleButton* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnCommandBarToggleButton* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnCommandBarToggleButton* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnCommandBarToggleButton* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnCommandBarToggleButton* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnCommandBarToggleButton* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnCommandBarToggleButton* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnCommandBarToggleButton* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnCommandBarToggleButton* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnCommandBarToggleButton* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnCommandBarToggleButton* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnCommandBarToggleButton* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnCommandBarToggleButton* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnCommandBarToggleButton* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnCommandBarToggleButton* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnCommandBarToggleButton* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnCommandBarToggleButton* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnCommandBarToggleButton* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnCommandBarToggleButton* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnCommandBarToggleButton* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnCommandBarToggleButton* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnCommandBarToggleButton* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnCommandBarToggleButton* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnCommandBarToggleButton* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnCommandBarToggleButton* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnCommandBarToggleButton* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnCommandBarToggleButton* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_click_mode)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_click_mode)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_command)(IAvnCommandBarToggleButton* self, IAvnCommand** value); /* slot 79 */
    AvnHResult (AVN_CALL *set_command)(IAvnCommandBarToggleButton* self, IAvnCommand* value); /* slot 80 */
    AvnHResult (AVN_CALL *get_command_parameter)(IAvnCommandBarToggleButton* self, AvnVariant* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_command_parameter)(IAvnCommandBarToggleButton* self, AvnVariant value); /* slot 82 */
    AvnHResult (AVN_CALL *get_is_default)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_is_default)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_is_cancel)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_is_cancel)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 86 */
    AvnHResult (AVN_CALL *get_is_pressed)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 87 */
    AvnHResult (AVN_CALL *get_flyout)(IAvnCommandBarToggleButton* self, IAvnFlyoutBase** value); /* slot 88 */
    AvnHResult (AVN_CALL *set_flyout)(IAvnCommandBarToggleButton* self, IAvnFlyoutBase* value); /* slot 89 */
    AvnHResult (AVN_CALL *advise_click)(IAvnCommandBarToggleButton* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 90 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnCommandBarToggleButton* self, int64_t subscription_id); /* slot 91 */
    AvnHResult (AVN_CALL *get_is_checked)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 92 */
    AvnHResult (AVN_CALL *set_is_checked)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 93 */
    AvnHResult (AVN_CALL *get_is_three_state)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 94 */
    AvnHResult (AVN_CALL *set_is_three_state)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 95 */
    AvnHResult (AVN_CALL *advise_is_checked_changed)(IAvnCommandBarToggleButton* self, IAvnToggleButtonIsCheckedChangedHandler* handler, int64_t* subscription_id); /* slot 96 */
    AvnHResult (AVN_CALL *unadvise_is_checked_changed)(IAvnCommandBarToggleButton* self, int64_t subscription_id); /* slot 97 */
    AvnHResult (AVN_CALL *get_label)(IAvnCommandBarToggleButton* self, uint16_t** value); /* slot 98 */
    AvnHResult (AVN_CALL *set_label)(IAvnCommandBarToggleButton* self, const uint16_t* value); /* slot 99 */
    AvnHResult (AVN_CALL *get_is_compact)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 100 */
    AvnHResult (AVN_CALL *set_is_compact)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 101 */
    AvnHResult (AVN_CALL *get_dynamic_overflow_order)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 102 */
    AvnHResult (AVN_CALL *set_dynamic_overflow_order)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 103 */
    AvnHResult (AVN_CALL *get_label_position)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 104 */
    AvnHResult (AVN_CALL *set_label_position)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 105 */
    AvnHResult (AVN_CALL *get_is_in_overflow)(IAvnCommandBarToggleButton* self, int32_t* value); /* slot 106 */
    AvnHResult (AVN_CALL *set_is_in_overflow)(IAvnCommandBarToggleButton* self, int32_t value); /* slot 107 */
};
struct IAvnCommandBarToggleButton { const IAvnCommandBarToggleButtonVtbl* vtbl; };
#define I_AVN_COMMAND_BAR_TOGGLE_BUTTON_VTABLE_SLOTS 108

static const AvnGuid I_AVN_CONTENT_CONTROL_IID = {
    0x2D229F2A,
    0xB6EE,
    0x5835,
    { 0xA8, 0xEC, 0xBA, 0x98, 0x83, 0x8E, 0x1E, 0xF5 }
};
#define I_AVN_CONTENT_CONTROL_ABI_VERSION 7
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnContentControl* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnContentControl* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnContentControl* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnContentControl* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnContentControl* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnContentControl* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnContentControl* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnContentControl* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnContentControl* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnContentControl* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnContentControl* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnContentControl* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnContentControl* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnContentControl* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnContentControl* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnContentControl* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnContentControl* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnContentControl* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnContentControl* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnContentControl* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnContentControl* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnContentControl* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnContentControl* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnContentControl* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnContentControl* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnContentControl* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnContentControl* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnContentControl* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnContentControl* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnContentControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnContentControl* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnContentControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnContentControl* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnContentControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnContentControl* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnContentControl* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnContentControl* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnContentControl* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnContentControl* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnContentControl* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnContentControl* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnContentControl* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnContentControl* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnContentControl* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnContentControl* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnContentControl* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnContentControl* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnContentControl* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnContentControl* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnContentControl* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnContentControl* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnContentControl* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnContentControl* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnContentControl* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnContentControl* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnContentControl* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnContentControl* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnContentControl* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnContentControl* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnContentControl* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnContentControl* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnContentControl* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnContentControl* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnContentControl* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnContentControl* self, int32_t value); /* slot 76 */
};
struct IAvnContentControl { const IAvnContentControlVtbl* vtbl; };
#define I_AVN_CONTENT_CONTROL_VTABLE_SLOTS 77

static const AvnGuid I_AVN_CONTEXT_MENU_IID = {
    0x13FA26AB,
    0xA74B,
    0x53CF,
    { 0xA4, 0xD0, 0x19, 0x09, 0xD2, 0x62, 0x13, 0x3D }
};
#define I_AVN_CONTEXT_MENU_ABI_VERSION 8
struct IAvnContextMenuVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnContextMenu* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnContextMenu* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnContextMenu* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnContextMenu* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnContextMenu* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnContextMenu* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnContextMenu* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnContextMenu* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnContextMenu* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnContextMenu* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnContextMenu* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnContextMenu* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnContextMenu* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnContextMenu* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnContextMenu* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnContextMenu* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnContextMenu* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnContextMenu* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnContextMenu* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnContextMenu* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnContextMenu* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnContextMenu* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnContextMenu* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnContextMenu* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnContextMenu* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnContextMenu* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnContextMenu* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnContextMenu* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnContextMenu* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnContextMenu* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnContextMenu* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnContextMenu* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnContextMenu* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnContextMenu* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnContextMenu* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnContextMenu* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnContextMenu* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnContextMenu* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnContextMenu* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnContextMenu* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnContextMenu* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnContextMenu* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnContextMenu* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnContextMenu* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnContextMenu* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnContextMenu* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnContextMenu* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnContextMenu* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnContextMenu* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnContextMenu* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnContextMenu* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnContextMenu* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnContextMenu* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnContextMenu* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnContextMenu* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnContextMenu* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnContextMenu* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnContextMenu* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnContextMenu* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnContextMenu* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnContextMenu* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnContextMenu* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnContextMenu* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnContextMenu* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnContextMenu* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnContextMenu* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnContextMenu* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnContextMenu* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnContextMenu* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnContextMenu* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnContextMenu* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_items)(IAvnContextMenu* self, IAvnItemList** value); /* slot 71 */
    AvnHResult (AVN_CALL *get_item_count)(IAvnContextMenu* self, int32_t* value); /* slot 72 */
    AvnHResult (AVN_CALL *scroll_into_view_with_int32)(IAvnContextMenu* self, int32_t index); /* slot 73 */
    AvnHResult (AVN_CALL *get_auto_scroll_to_selected_item)(IAvnContextMenu* self, int32_t* value); /* slot 74 */
    AvnHResult (AVN_CALL *set_auto_scroll_to_selected_item)(IAvnContextMenu* self, int32_t value); /* slot 75 */
    AvnHResult (AVN_CALL *get_selected_index)(IAvnContextMenu* self, int32_t* value); /* slot 76 */
    AvnHResult (AVN_CALL *set_selected_index)(IAvnContextMenu* self, int32_t value); /* slot 77 */
    AvnHResult (AVN_CALL *get_is_text_search_enabled)(IAvnContextMenu* self, int32_t* value); /* slot 78 */
    AvnHResult (AVN_CALL *set_is_text_search_enabled)(IAvnContextMenu* self, int32_t value); /* slot 79 */
    AvnHResult (AVN_CALL *get_wrap_selection)(IAvnContextMenu* self, int32_t* value); /* slot 80 */
    AvnHResult (AVN_CALL *set_wrap_selection)(IAvnContextMenu* self, int32_t value); /* slot 81 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnContextMenu* self, IAvnSelectingItemsControlSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 82 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnContextMenu* self, int64_t subscription_id); /* slot 83 */
    AvnHResult (AVN_CALL *get_is_open)(IAvnContextMenu* self, int32_t* value); /* slot 84 */
    AvnHResult (AVN_CALL *close)(IAvnContextMenu* self); /* slot 85 */
    AvnHResult (AVN_CALL *open)(IAvnContextMenu* self); /* slot 86 */
    AvnHResult (AVN_CALL *advise_opened)(IAvnContextMenu* self, IAvnMenuBaseOpenedHandler* handler, int64_t* subscription_id); /* slot 87 */
    AvnHResult (AVN_CALL *unadvise_opened)(IAvnContextMenu* self, int64_t subscription_id); /* slot 88 */
    AvnHResult (AVN_CALL *advise_closed)(IAvnContextMenu* self, IAvnMenuBaseClosedHandler* handler, int64_t* subscription_id); /* slot 89 */
    AvnHResult (AVN_CALL *unadvise_closed)(IAvnContextMenu* self, int64_t subscription_id); /* slot 90 */
    AvnHResult (AVN_CALL *get_horizontal_offset)(IAvnContextMenu* self, double* value); /* slot 91 */
    AvnHResult (AVN_CALL *set_horizontal_offset)(IAvnContextMenu* self, double value); /* slot 92 */
    AvnHResult (AVN_CALL *get_vertical_offset)(IAvnContextMenu* self, double* value); /* slot 93 */
    AvnHResult (AVN_CALL *set_vertical_offset)(IAvnContextMenu* self, double value); /* slot 94 */
    AvnHResult (AVN_CALL *get_placement_anchor)(IAvnContextMenu* self, int32_t* value); /* slot 95 */
    AvnHResult (AVN_CALL *set_placement_anchor)(IAvnContextMenu* self, int32_t value); /* slot 96 */
    AvnHResult (AVN_CALL *get_placement_constraint_adjustment)(IAvnContextMenu* self, int32_t* value); /* slot 97 */
    AvnHResult (AVN_CALL *set_placement_constraint_adjustment)(IAvnContextMenu* self, int32_t value); /* slot 98 */
    AvnHResult (AVN_CALL *get_placement_gravity)(IAvnContextMenu* self, int32_t* value); /* slot 99 */
    AvnHResult (AVN_CALL *set_placement_gravity)(IAvnContextMenu* self, int32_t value); /* slot 100 */
    AvnHResult (AVN_CALL *get_placement)(IAvnContextMenu* self, int32_t* value); /* slot 101 */
    AvnHResult (AVN_CALL *set_placement)(IAvnContextMenu* self, int32_t value); /* slot 102 */
    AvnHResult (AVN_CALL *get_window_manager_add_shadow_hint)(IAvnContextMenu* self, int32_t* value); /* slot 103 */
    AvnHResult (AVN_CALL *set_window_manager_add_shadow_hint)(IAvnContextMenu* self, int32_t value); /* slot 104 */
    AvnHResult (AVN_CALL *get_placement_rect)(IAvnContextMenu* self, AvnOptionalRect* value); /* slot 105 */
    AvnHResult (AVN_CALL *set_placement_rect)(IAvnContextMenu* self, AvnOptionalRect value); /* slot 106 */
    AvnHResult (AVN_CALL *get_placement_target)(IAvnContextMenu* self, IAvnControl** value); /* slot 107 */
    AvnHResult (AVN_CALL *set_placement_target)(IAvnContextMenu* self, IAvnControl* value); /* slot 108 */
    AvnHResult (AVN_CALL *open_with_control)(IAvnContextMenu* self, IAvnControl* control); /* slot 109 */
    AvnHResult (AVN_CALL *advise_opening)(IAvnContextMenu* self, IAvnContextMenuOpeningHandler* handler, int64_t* subscription_id); /* slot 110 */
    AvnHResult (AVN_CALL *unadvise_opening)(IAvnContextMenu* self, int64_t subscription_id); /* slot 111 */
    AvnHResult (AVN_CALL *advise_closing)(IAvnContextMenu* self, IAvnContextMenuClosingHandler* handler, int64_t* subscription_id); /* slot 112 */
    AvnHResult (AVN_CALL *unadvise_closing)(IAvnContextMenu* self, int64_t subscription_id); /* slot 113 */
};
struct IAvnContextMenu { const IAvnContextMenuVtbl* vtbl; };
#define I_AVN_CONTEXT_MENU_VTABLE_SLOTS 114

static const AvnGuid I_AVN_CONTROL_IID = {
    0x82E7495D,
    0xEC39,
    0x5401,
    { 0x8E, 0xB6, 0x86, 0x2A, 0x4F, 0xD2, 0xC6, 0xB7 }
};
#define I_AVN_CONTROL_ABI_VERSION 4
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnControl* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnControl* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnControl* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnControl* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnControl* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnControl* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnControl* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnControl* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnControl* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnControl* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnControl* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnControl* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnControl* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnControl* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnControl* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnControl* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnControl* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnControl* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnControl* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnControl* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnControl* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnControl* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnControl* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnControl* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnControl* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnControl* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnControl* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnControl* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnControl* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnControl* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnControl* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnControl* self, int64_t subscription_id); /* slot 46 */
};
struct IAvnControl { const IAvnControlVtbl* vtbl; };
#define I_AVN_CONTROL_VTABLE_SLOTS 47

static const AvnGuid I_AVN_DATE_PICKER_IID = {
    0x7F06AD94,
    0x0BD6,
    0x52B0,
    { 0x81, 0x38, 0x16, 0xA7, 0x46, 0xF0, 0xFE, 0xAD }
};
#define I_AVN_DATE_PICKER_ABI_VERSION 4
struct IAvnDatePickerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnDatePicker* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnDatePicker* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnDatePicker* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnDatePicker* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnDatePicker* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnDatePicker* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnDatePicker* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnDatePicker* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnDatePicker* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnDatePicker* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnDatePicker* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnDatePicker* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnDatePicker* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnDatePicker* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnDatePicker* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnDatePicker* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnDatePicker* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnDatePicker* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnDatePicker* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnDatePicker* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnDatePicker* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnDatePicker* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnDatePicker* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnDatePicker* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnDatePicker* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnDatePicker* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnDatePicker* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnDatePicker* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnDatePicker* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnDatePicker* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnDatePicker* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnDatePicker* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnDatePicker* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnDatePicker* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnDatePicker* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnDatePicker* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnDatePicker* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnDatePicker* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnDatePicker* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnDatePicker* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnDatePicker* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnDatePicker* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnDatePicker* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnDatePicker* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnDatePicker* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnDatePicker* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnDatePicker* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnDatePicker* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnDatePicker* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnDatePicker* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnDatePicker* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnDatePicker* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnDatePicker* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnDatePicker* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnDatePicker* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnDatePicker* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnDatePicker* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnDatePicker* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnDatePicker* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnDatePicker* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnDatePicker* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnDatePicker* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnDatePicker* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnDatePicker* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnDatePicker* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnDatePicker* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnDatePicker* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnDatePicker* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnDatePicker* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnDatePicker* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnDatePicker* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnDatePicker* self, int32_t* value); /* slot 71 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnDatePicker* self, int32_t value); /* slot 72 */
    AvnHResult (AVN_CALL *get_day_format)(IAvnDatePicker* self, uint16_t** value); /* slot 73 */
    AvnHResult (AVN_CALL *set_day_format)(IAvnDatePicker* self, const uint16_t* value); /* slot 74 */
    AvnHResult (AVN_CALL *get_day_visible)(IAvnDatePicker* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_day_visible)(IAvnDatePicker* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_max_year)(IAvnDatePicker* self, uint16_t** value); /* slot 77 */
    AvnHResult (AVN_CALL *set_max_year)(IAvnDatePicker* self, const uint16_t* value); /* slot 78 */
    AvnHResult (AVN_CALL *get_min_year)(IAvnDatePicker* self, uint16_t** value); /* slot 79 */
    AvnHResult (AVN_CALL *set_min_year)(IAvnDatePicker* self, const uint16_t* value); /* slot 80 */
    AvnHResult (AVN_CALL *get_month_format)(IAvnDatePicker* self, uint16_t** value); /* slot 81 */
    AvnHResult (AVN_CALL *set_month_format)(IAvnDatePicker* self, const uint16_t* value); /* slot 82 */
    AvnHResult (AVN_CALL *get_month_visible)(IAvnDatePicker* self, int32_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_month_visible)(IAvnDatePicker* self, int32_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_year_format)(IAvnDatePicker* self, uint16_t** value); /* slot 85 */
    AvnHResult (AVN_CALL *set_year_format)(IAvnDatePicker* self, const uint16_t* value); /* slot 86 */
    AvnHResult (AVN_CALL *get_year_visible)(IAvnDatePicker* self, int32_t* value); /* slot 87 */
    AvnHResult (AVN_CALL *set_year_visible)(IAvnDatePicker* self, int32_t value); /* slot 88 */
    AvnHResult (AVN_CALL *get_selected_date)(IAvnDatePicker* self, uint16_t** value); /* slot 89 */
    AvnHResult (AVN_CALL *set_selected_date)(IAvnDatePicker* self, const uint16_t* value); /* slot 90 */
    AvnHResult (AVN_CALL *clear)(IAvnDatePicker* self); /* slot 91 */
};
struct IAvnDatePicker { const IAvnDatePickerVtbl* vtbl; };
#define I_AVN_DATE_PICKER_VTABLE_SLOTS 92

static const AvnGuid I_AVN_DECORATOR_IID = {
    0xE926933F,
    0xDA8E,
    0x51DC,
    { 0xB5, 0x04, 0x9B, 0x17, 0x9F, 0xBC, 0xF1, 0x7F }
};
#define I_AVN_DECORATOR_ABI_VERSION 4
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnDecorator* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnDecorator* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnDecorator* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnDecorator* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnDecorator* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnDecorator* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnDecorator* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnDecorator* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnDecorator* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnDecorator* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnDecorator* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnDecorator* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnDecorator* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnDecorator* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnDecorator* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnDecorator* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnDecorator* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnDecorator* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnDecorator* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnDecorator* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnDecorator* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnDecorator* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnDecorator* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnDecorator* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnDecorator* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnDecorator* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnDecorator* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnDecorator* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnDecorator* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnDecorator* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnDecorator* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnDecorator* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnDecorator* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnDecorator* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnDecorator* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_child)(IAvnDecorator* self, IAvnControl** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_child)(IAvnDecorator* self, IAvnControl* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_padding)(IAvnDecorator* self, AvnThickness* value); /* slot 49 */
    AvnHResult (AVN_CALL *set_padding)(IAvnDecorator* self, AvnThickness value); /* slot 50 */
};
struct IAvnDecorator { const IAvnDecoratorVtbl* vtbl; };
#define I_AVN_DECORATOR_VTABLE_SLOTS 51

static const AvnGuid I_AVN_DOCK_PANEL_IID = {
    0xC91C1A41,
    0x750C,
    0x577F,
    { 0xBB, 0x06, 0x65, 0xBA, 0x41, 0x9C, 0xE1, 0x95 }
};
#define I_AVN_DOCK_PANEL_ABI_VERSION 5
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnDockPanel* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnDockPanel* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnDockPanel* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnDockPanel* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnDockPanel* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnDockPanel* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnDockPanel* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnDockPanel* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnDockPanel* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnDockPanel* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnDockPanel* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnDockPanel* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnDockPanel* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnDockPanel* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnDockPanel* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnDockPanel* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnDockPanel* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnDockPanel* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnDockPanel* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnDockPanel* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnDockPanel* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnDockPanel* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnDockPanel* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnDockPanel* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnDockPanel* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnDockPanel* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnDockPanel* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnDockPanel* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnDockPanel* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnDockPanel* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnDockPanel* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnDockPanel* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnDockPanel* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnDockPanel* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnDockPanel* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_children)(IAvnDockPanel* self, IAvnControlList** value); /* slot 47 */
    AvnHResult (AVN_CALL *get_background)(IAvnDockPanel* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_background)(IAvnDockPanel* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_last_child_fill)(IAvnDockPanel* self, int32_t* value); /* slot 50 */
    AvnHResult (AVN_CALL *set_last_child_fill)(IAvnDockPanel* self, int32_t value); /* slot 51 */
    AvnHResult (AVN_CALL *get_horizontal_spacing)(IAvnDockPanel* self, double* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_horizontal_spacing)(IAvnDockPanel* self, double value); /* slot 53 */
    AvnHResult (AVN_CALL *get_vertical_spacing)(IAvnDockPanel* self, double* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_vertical_spacing)(IAvnDockPanel* self, double value); /* slot 55 */
};
struct IAvnDockPanel { const IAvnDockPanelVtbl* vtbl; };
#define I_AVN_DOCK_PANEL_VTABLE_SLOTS 56

static const AvnGuid I_AVN_DROP_DOWN_BUTTON_IID = {
    0xBFC9AA65,
    0x7E71,
    0x53EB,
    { 0x9C, 0xA5, 0xD6, 0x87, 0x26, 0xDC, 0x6A, 0xC2 }
};
#define I_AVN_DROP_DOWN_BUTTON_ABI_VERSION 5
struct IAvnDropDownButtonVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnDropDownButton* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnDropDownButton* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnDropDownButton* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnDropDownButton* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnDropDownButton* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnDropDownButton* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnDropDownButton* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnDropDownButton* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnDropDownButton* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnDropDownButton* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnDropDownButton* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnDropDownButton* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnDropDownButton* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnDropDownButton* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnDropDownButton* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnDropDownButton* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnDropDownButton* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnDropDownButton* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnDropDownButton* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnDropDownButton* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnDropDownButton* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnDropDownButton* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnDropDownButton* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnDropDownButton* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnDropDownButton* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnDropDownButton* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnDropDownButton* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnDropDownButton* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnDropDownButton* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnDropDownButton* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnDropDownButton* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnDropDownButton* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnDropDownButton* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnDropDownButton* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnDropDownButton* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnDropDownButton* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnDropDownButton* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnDropDownButton* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnDropDownButton* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnDropDownButton* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnDropDownButton* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnDropDownButton* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnDropDownButton* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnDropDownButton* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnDropDownButton* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnDropDownButton* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnDropDownButton* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnDropDownButton* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnDropDownButton* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnDropDownButton* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnDropDownButton* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnDropDownButton* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnDropDownButton* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnDropDownButton* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnDropDownButton* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnDropDownButton* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnDropDownButton* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnDropDownButton* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnDropDownButton* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnDropDownButton* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnDropDownButton* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnDropDownButton* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnDropDownButton* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnDropDownButton* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnDropDownButton* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnDropDownButton* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnDropDownButton* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnDropDownButton* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnDropDownButton* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnDropDownButton* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnDropDownButton* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnDropDownButton* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnDropDownButton* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnDropDownButton* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnDropDownButton* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnDropDownButton* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnDropDownButton* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_click_mode)(IAvnDropDownButton* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_click_mode)(IAvnDropDownButton* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_command)(IAvnDropDownButton* self, IAvnCommand** value); /* slot 79 */
    AvnHResult (AVN_CALL *set_command)(IAvnDropDownButton* self, IAvnCommand* value); /* slot 80 */
    AvnHResult (AVN_CALL *get_command_parameter)(IAvnDropDownButton* self, AvnVariant* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_command_parameter)(IAvnDropDownButton* self, AvnVariant value); /* slot 82 */
    AvnHResult (AVN_CALL *get_is_default)(IAvnDropDownButton* self, int32_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_is_default)(IAvnDropDownButton* self, int32_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_is_cancel)(IAvnDropDownButton* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_is_cancel)(IAvnDropDownButton* self, int32_t value); /* slot 86 */
    AvnHResult (AVN_CALL *get_is_pressed)(IAvnDropDownButton* self, int32_t* value); /* slot 87 */
    AvnHResult (AVN_CALL *get_flyout)(IAvnDropDownButton* self, IAvnFlyoutBase** value); /* slot 88 */
    AvnHResult (AVN_CALL *set_flyout)(IAvnDropDownButton* self, IAvnFlyoutBase* value); /* slot 89 */
    AvnHResult (AVN_CALL *advise_click)(IAvnDropDownButton* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 90 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnDropDownButton* self, int64_t subscription_id); /* slot 91 */
};
struct IAvnDropDownButton { const IAvnDropDownButtonVtbl* vtbl; };
#define I_AVN_DROP_DOWN_BUTTON_VTABLE_SLOTS 92

static const AvnGuid I_AVN_ELLIPSE_IID = {
    0x7067CB2F,
    0x7F47,
    0x5DC5,
    { 0xB1, 0x54, 0x76, 0x8A, 0xA8, 0xBD, 0x05, 0x93 }
};
#define I_AVN_ELLIPSE_ABI_VERSION 2
struct IAvnEllipseVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnEllipse* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnEllipse* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnEllipse* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnEllipse* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnEllipse* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnEllipse* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnEllipse* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnEllipse* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnEllipse* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnEllipse* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnEllipse* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnEllipse* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnEllipse* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnEllipse* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnEllipse* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnEllipse* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnEllipse* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnEllipse* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnEllipse* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnEllipse* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnEllipse* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnEllipse* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnEllipse* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnEllipse* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnEllipse* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnEllipse* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnEllipse* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnEllipse* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnEllipse* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnEllipse* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnEllipse* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnEllipse* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnEllipse* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnEllipse* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnEllipse* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnEllipse* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnEllipse* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnEllipse* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnEllipse* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnEllipse* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnEllipse* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnEllipse* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnEllipse* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnEllipse* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnEllipse* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnEllipse* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnEllipse* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_fill)(IAvnEllipse* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_fill)(IAvnEllipse* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_stretch)(IAvnEllipse* self, int32_t* value); /* slot 49 */
    AvnHResult (AVN_CALL *set_stretch)(IAvnEllipse* self, int32_t value); /* slot 50 */
    AvnHResult (AVN_CALL *get_stroke)(IAvnEllipse* self, IAvnBrush** value); /* slot 51 */
    AvnHResult (AVN_CALL *set_stroke)(IAvnEllipse* self, IAvnBrush* value); /* slot 52 */
    AvnHResult (AVN_CALL *get_stroke_dash_offset)(IAvnEllipse* self, double* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_stroke_dash_offset)(IAvnEllipse* self, double value); /* slot 54 */
    AvnHResult (AVN_CALL *get_stroke_thickness)(IAvnEllipse* self, double* value); /* slot 55 */
    AvnHResult (AVN_CALL *set_stroke_thickness)(IAvnEllipse* self, double value); /* slot 56 */
    AvnHResult (AVN_CALL *get_stroke_line_cap)(IAvnEllipse* self, int32_t* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_stroke_line_cap)(IAvnEllipse* self, int32_t value); /* slot 58 */
    AvnHResult (AVN_CALL *get_stroke_join)(IAvnEllipse* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_stroke_join)(IAvnEllipse* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_stroke_miter_limit)(IAvnEllipse* self, double* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_stroke_miter_limit)(IAvnEllipse* self, double value); /* slot 62 */
};
struct IAvnEllipse { const IAvnEllipseVtbl* vtbl; };
#define I_AVN_ELLIPSE_VTABLE_SLOTS 63

static const AvnGuid I_AVN_EXPANDER_IID = {
    0x9E2809BA,
    0x34CB,
    0x5720,
    { 0xB7, 0x6D, 0x2D, 0xA4, 0x8D, 0x5E, 0xB8, 0xBB }
};
#define I_AVN_EXPANDER_ABI_VERSION 7
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnExpander* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnExpander* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnExpander* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnExpander* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnExpander* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnExpander* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnExpander* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnExpander* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnExpander* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnExpander* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnExpander* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnExpander* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnExpander* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnExpander* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnExpander* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnExpander* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnExpander* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnExpander* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnExpander* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnExpander* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnExpander* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnExpander* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnExpander* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnExpander* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnExpander* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnExpander* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnExpander* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnExpander* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnExpander* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnExpander* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnExpander* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnExpander* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnExpander* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnExpander* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnExpander* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnExpander* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnExpander* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnExpander* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnExpander* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnExpander* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnExpander* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnExpander* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnExpander* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnExpander* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnExpander* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnExpander* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnExpander* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnExpander* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnExpander* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnExpander* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnExpander* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnExpander* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnExpander* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnExpander* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnExpander* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnExpander* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnExpander* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnExpander* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnExpander* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnExpander* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnExpander* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnExpander* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnExpander* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnExpander* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnExpander* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_header)(IAvnExpander* self, IAvnControl** value); /* slot 77 */
    AvnHResult (AVN_CALL *set_header)(IAvnExpander* self, IAvnControl* value); /* slot 78 */
    AvnHResult (AVN_CALL *get_expand_direction)(IAvnExpander* self, int32_t* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_expand_direction)(IAvnExpander* self, int32_t value); /* slot 80 */
    AvnHResult (AVN_CALL *get_is_expanded)(IAvnExpander* self, int32_t* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_is_expanded)(IAvnExpander* self, int32_t value); /* slot 82 */
    AvnHResult (AVN_CALL *advise_collapsed)(IAvnExpander* self, IAvnExpanderCollapsedHandler* handler, int64_t* subscription_id); /* slot 83 */
    AvnHResult (AVN_CALL *unadvise_collapsed)(IAvnExpander* self, int64_t subscription_id); /* slot 84 */
    AvnHResult (AVN_CALL *advise_expanded)(IAvnExpander* self, IAvnExpanderExpandedHandler* handler, int64_t* subscription_id); /* slot 85 */
    AvnHResult (AVN_CALL *unadvise_expanded)(IAvnExpander* self, int64_t subscription_id); /* slot 86 */
};
struct IAvnExpander { const IAvnExpanderVtbl* vtbl; };
#define I_AVN_EXPANDER_VTABLE_SLOTS 87

static const AvnGuid I_AVN_FLEX_PANEL_IID = {
    0xD891A45A,
    0x220E,
    0x508D,
    { 0xB3, 0xE6, 0xE7, 0x7B, 0xEE, 0xC4, 0x84, 0x8E }
};
#define I_AVN_FLEX_PANEL_ABI_VERSION 2
struct IAvnFlexPanelVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnFlexPanel* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnFlexPanel* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnFlexPanel* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnFlexPanel* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnFlexPanel* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnFlexPanel* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnFlexPanel* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnFlexPanel* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnFlexPanel* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnFlexPanel* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnFlexPanel* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnFlexPanel* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnFlexPanel* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnFlexPanel* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnFlexPanel* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnFlexPanel* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnFlexPanel* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnFlexPanel* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnFlexPanel* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnFlexPanel* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnFlexPanel* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnFlexPanel* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnFlexPanel* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnFlexPanel* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnFlexPanel* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnFlexPanel* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnFlexPanel* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnFlexPanel* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnFlexPanel* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnFlexPanel* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnFlexPanel* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnFlexPanel* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnFlexPanel* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnFlexPanel* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnFlexPanel* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnFlexPanel* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnFlexPanel* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnFlexPanel* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnFlexPanel* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnFlexPanel* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnFlexPanel* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnFlexPanel* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnFlexPanel* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnFlexPanel* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnFlexPanel* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnFlexPanel* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnFlexPanel* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_children)(IAvnFlexPanel* self, IAvnControlList** value); /* slot 47 */
    AvnHResult (AVN_CALL *get_background)(IAvnFlexPanel* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_background)(IAvnFlexPanel* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_direction)(IAvnFlexPanel* self, int32_t* value); /* slot 50 */
    AvnHResult (AVN_CALL *set_direction)(IAvnFlexPanel* self, int32_t value); /* slot 51 */
    AvnHResult (AVN_CALL *get_justify_content)(IAvnFlexPanel* self, int32_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_justify_content)(IAvnFlexPanel* self, int32_t value); /* slot 53 */
    AvnHResult (AVN_CALL *get_align_items)(IAvnFlexPanel* self, int32_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_align_items)(IAvnFlexPanel* self, int32_t value); /* slot 55 */
    AvnHResult (AVN_CALL *get_align_content)(IAvnFlexPanel* self, int32_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *set_align_content)(IAvnFlexPanel* self, int32_t value); /* slot 57 */
    AvnHResult (AVN_CALL *get_wrap)(IAvnFlexPanel* self, int32_t* value); /* slot 58 */
    AvnHResult (AVN_CALL *set_wrap)(IAvnFlexPanel* self, int32_t value); /* slot 59 */
    AvnHResult (AVN_CALL *get_column_spacing)(IAvnFlexPanel* self, double* value); /* slot 60 */
    AvnHResult (AVN_CALL *set_column_spacing)(IAvnFlexPanel* self, double value); /* slot 61 */
    AvnHResult (AVN_CALL *get_row_spacing)(IAvnFlexPanel* self, double* value); /* slot 62 */
    AvnHResult (AVN_CALL *set_row_spacing)(IAvnFlexPanel* self, double value); /* slot 63 */
};
struct IAvnFlexPanel { const IAvnFlexPanelVtbl* vtbl; };
#define I_AVN_FLEX_PANEL_VTABLE_SLOTS 64

static const AvnGuid I_AVN_FLYOUT_IID = {
    0x16283CAB,
    0xDD33,
    0x5D3F,
    { 0xB9, 0x80, 0x0E, 0xE0, 0x49, 0x39, 0xCF, 0x2A }
};
#define I_AVN_FLYOUT_ABI_VERSION 3
struct IAvnFlyoutVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnFlyout* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnFlyout* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnFlyout* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnFlyout* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnFlyout* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_is_open)(IAvnFlyout* self, int32_t* value); /* slot 5 */
    AvnHResult (AVN_CALL *set_is_open)(IAvnFlyout* self, int32_t value); /* slot 6 */
    AvnHResult (AVN_CALL *get_target)(IAvnFlyout* self, IAvnControl** value); /* slot 7 */
    AvnHResult (AVN_CALL *show_at_with_control)(IAvnFlyout* self, IAvnControl* placement_target); /* slot 8 */
    AvnHResult (AVN_CALL *hide)(IAvnFlyout* self); /* slot 9 */
    AvnHResult (AVN_CALL *advise_opened)(IAvnFlyout* self, IAvnFlyoutBaseOpenedHandler* handler, int64_t* subscription_id); /* slot 10 */
    AvnHResult (AVN_CALL *unadvise_opened)(IAvnFlyout* self, int64_t subscription_id); /* slot 11 */
    AvnHResult (AVN_CALL *advise_closed)(IAvnFlyout* self, IAvnFlyoutBaseClosedHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_closed)(IAvnFlyout* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *get_popup)(IAvnFlyout* self, IAvnPopup** value); /* slot 14 */
    AvnHResult (AVN_CALL *get_placement)(IAvnFlyout* self, int32_t* value); /* slot 15 */
    AvnHResult (AVN_CALL *set_placement)(IAvnFlyout* self, int32_t value); /* slot 16 */
    AvnHResult (AVN_CALL *get_placement_gravity)(IAvnFlyout* self, int32_t* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_placement_gravity)(IAvnFlyout* self, int32_t value); /* slot 18 */
    AvnHResult (AVN_CALL *get_placement_anchor)(IAvnFlyout* self, int32_t* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_placement_anchor)(IAvnFlyout* self, int32_t value); /* slot 20 */
    AvnHResult (AVN_CALL *get_horizontal_offset)(IAvnFlyout* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_horizontal_offset)(IAvnFlyout* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_vertical_offset)(IAvnFlyout* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_vertical_offset)(IAvnFlyout* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_show_mode)(IAvnFlyout* self, int32_t* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_show_mode)(IAvnFlyout* self, int32_t value); /* slot 26 */
    AvnHResult (AVN_CALL *get_overlay_dismiss_event_pass_through)(IAvnFlyout* self, int32_t* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_overlay_dismiss_event_pass_through)(IAvnFlyout* self, int32_t value); /* slot 28 */
    AvnHResult (AVN_CALL *get_placement_constraint_adjustment)(IAvnFlyout* self, int32_t* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_placement_constraint_adjustment)(IAvnFlyout* self, int32_t value); /* slot 30 */
    AvnHResult (AVN_CALL *advise_closing)(IAvnFlyout* self, IAvnPopupFlyoutBaseClosingHandler* handler, int64_t* subscription_id); /* slot 31 */
    AvnHResult (AVN_CALL *unadvise_closing)(IAvnFlyout* self, int64_t subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *advise_opening)(IAvnFlyout* self, IAvnPopupFlyoutBaseOpeningHandler* handler, int64_t* subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *unadvise_opening)(IAvnFlyout* self, int64_t subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *get_content)(IAvnFlyout* self, IAvnControl** value); /* slot 35 */
    AvnHResult (AVN_CALL *set_content)(IAvnFlyout* self, IAvnControl* value); /* slot 36 */
};
struct IAvnFlyout { const IAvnFlyoutVtbl* vtbl; };
#define I_AVN_FLYOUT_VTABLE_SLOTS 37

static const AvnGuid I_AVN_FLYOUT_BASE_IID = {
    0x101A7B60,
    0xDED9,
    0x560F,
    { 0xAA, 0x4D, 0x8D, 0xBB, 0x5E, 0x12, 0x67, 0x63 }
};
#define I_AVN_FLYOUT_BASE_ABI_VERSION 1
struct IAvnFlyoutBaseVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnFlyoutBase* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnFlyoutBase* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnFlyoutBase* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnFlyoutBase* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnFlyoutBase* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_is_open)(IAvnFlyoutBase* self, int32_t* value); /* slot 5 */
    AvnHResult (AVN_CALL *set_is_open)(IAvnFlyoutBase* self, int32_t value); /* slot 6 */
    AvnHResult (AVN_CALL *get_target)(IAvnFlyoutBase* self, IAvnControl** value); /* slot 7 */
    AvnHResult (AVN_CALL *show_at_with_control)(IAvnFlyoutBase* self, IAvnControl* placement_target); /* slot 8 */
    AvnHResult (AVN_CALL *hide)(IAvnFlyoutBase* self); /* slot 9 */
    AvnHResult (AVN_CALL *advise_opened)(IAvnFlyoutBase* self, IAvnFlyoutBaseOpenedHandler* handler, int64_t* subscription_id); /* slot 10 */
    AvnHResult (AVN_CALL *unadvise_opened)(IAvnFlyoutBase* self, int64_t subscription_id); /* slot 11 */
    AvnHResult (AVN_CALL *advise_closed)(IAvnFlyoutBase* self, IAvnFlyoutBaseClosedHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_closed)(IAvnFlyoutBase* self, int64_t subscription_id); /* slot 13 */
};
struct IAvnFlyoutBase { const IAvnFlyoutBaseVtbl* vtbl; };
#define I_AVN_FLYOUT_BASE_VTABLE_SLOTS 14

static const AvnGuid I_AVN_GRID_IID = {
    0x2A6D0A68,
    0xFF32,
    0x559F,
    { 0xA5, 0xB0, 0x87, 0x1C, 0x53, 0x70, 0x21, 0x80 }
};
#define I_AVN_GRID_ABI_VERSION 6
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnGrid* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnGrid* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnGrid* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnGrid* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnGrid* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnGrid* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnGrid* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnGrid* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnGrid* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnGrid* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnGrid* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnGrid* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnGrid* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnGrid* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnGrid* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnGrid* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnGrid* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnGrid* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnGrid* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnGrid* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnGrid* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnGrid* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnGrid* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnGrid* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnGrid* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnGrid* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnGrid* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnGrid* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnGrid* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnGrid* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnGrid* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnGrid* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnGrid* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnGrid* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnGrid* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_children)(IAvnGrid* self, IAvnControlList** value); /* slot 47 */
    AvnHResult (AVN_CALL *get_background)(IAvnGrid* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_background)(IAvnGrid* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_show_grid_lines)(IAvnGrid* self, int32_t* value); /* slot 50 */
    AvnHResult (AVN_CALL *set_show_grid_lines)(IAvnGrid* self, int32_t value); /* slot 51 */
    AvnHResult (AVN_CALL *get_row_spacing)(IAvnGrid* self, double* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_row_spacing)(IAvnGrid* self, double value); /* slot 53 */
    AvnHResult (AVN_CALL *get_column_spacing)(IAvnGrid* self, double* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_column_spacing)(IAvnGrid* self, double value); /* slot 55 */
    AvnHResult (AVN_CALL *get_column_definitions)(IAvnGrid* self, uint16_t** value); /* slot 56 */
    AvnHResult (AVN_CALL *set_column_definitions)(IAvnGrid* self, const uint16_t* value); /* slot 57 */
    AvnHResult (AVN_CALL *get_row_definitions)(IAvnGrid* self, uint16_t** value); /* slot 58 */
    AvnHResult (AVN_CALL *set_row_definitions)(IAvnGrid* self, const uint16_t* value); /* slot 59 */
};
struct IAvnGrid { const IAvnGridVtbl* vtbl; };
#define I_AVN_GRID_VTABLE_SLOTS 60

static const AvnGuid I_AVN_GRID_SPLITTER_IID = {
    0xFB7311EE,
    0xA6E2,
    0x5F6C,
    { 0xB3, 0x1F, 0x2C, 0x60, 0x6E, 0xF4, 0x18, 0x78 }
};
#define I_AVN_GRID_SPLITTER_ABI_VERSION 4
struct IAvnGridSplitterVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnGridSplitter* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnGridSplitter* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnGridSplitter* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnGridSplitter* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnGridSplitter* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnGridSplitter* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnGridSplitter* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnGridSplitter* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnGridSplitter* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnGridSplitter* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnGridSplitter* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnGridSplitter* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnGridSplitter* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnGridSplitter* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnGridSplitter* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnGridSplitter* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnGridSplitter* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnGridSplitter* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnGridSplitter* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnGridSplitter* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnGridSplitter* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnGridSplitter* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnGridSplitter* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnGridSplitter* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnGridSplitter* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnGridSplitter* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnGridSplitter* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnGridSplitter* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnGridSplitter* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnGridSplitter* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnGridSplitter* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnGridSplitter* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnGridSplitter* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnGridSplitter* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnGridSplitter* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnGridSplitter* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnGridSplitter* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnGridSplitter* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnGridSplitter* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnGridSplitter* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnGridSplitter* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnGridSplitter* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnGridSplitter* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnGridSplitter* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnGridSplitter* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnGridSplitter* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnGridSplitter* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnGridSplitter* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnGridSplitter* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnGridSplitter* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnGridSplitter* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnGridSplitter* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnGridSplitter* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnGridSplitter* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnGridSplitter* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnGridSplitter* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnGridSplitter* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnGridSplitter* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnGridSplitter* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnGridSplitter* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnGridSplitter* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnGridSplitter* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnGridSplitter* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnGridSplitter* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnGridSplitter* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnGridSplitter* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnGridSplitter* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnGridSplitter* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnGridSplitter* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnGridSplitter* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnGridSplitter* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *advise_drag_started)(IAvnGridSplitter* self, IAvnThumbDragStartedHandler* handler, int64_t* subscription_id); /* slot 71 */
    AvnHResult (AVN_CALL *unadvise_drag_started)(IAvnGridSplitter* self, int64_t subscription_id); /* slot 72 */
    AvnHResult (AVN_CALL *advise_drag_delta)(IAvnGridSplitter* self, IAvnThumbDragDeltaHandler* handler, int64_t* subscription_id); /* slot 73 */
    AvnHResult (AVN_CALL *unadvise_drag_delta)(IAvnGridSplitter* self, int64_t subscription_id); /* slot 74 */
    AvnHResult (AVN_CALL *advise_drag_completed)(IAvnGridSplitter* self, IAvnThumbDragCompletedHandler* handler, int64_t* subscription_id); /* slot 75 */
    AvnHResult (AVN_CALL *unadvise_drag_completed)(IAvnGridSplitter* self, int64_t subscription_id); /* slot 76 */
    AvnHResult (AVN_CALL *get_resize_direction)(IAvnGridSplitter* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_resize_direction)(IAvnGridSplitter* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_resize_behavior)(IAvnGridSplitter* self, int32_t* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_resize_behavior)(IAvnGridSplitter* self, int32_t value); /* slot 80 */
    AvnHResult (AVN_CALL *get_shows_preview)(IAvnGridSplitter* self, int32_t* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_shows_preview)(IAvnGridSplitter* self, int32_t value); /* slot 82 */
    AvnHResult (AVN_CALL *get_keyboard_increment)(IAvnGridSplitter* self, double* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_keyboard_increment)(IAvnGridSplitter* self, double value); /* slot 84 */
    AvnHResult (AVN_CALL *get_drag_increment)(IAvnGridSplitter* self, double* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_drag_increment)(IAvnGridSplitter* self, double value); /* slot 86 */
};
struct IAvnGridSplitter { const IAvnGridSplitterVtbl* vtbl; };
#define I_AVN_GRID_SPLITTER_VTABLE_SLOTS 87

static const AvnGuid I_AVN_GROUP_BOX_IID = {
    0x487BC2E6,
    0xEF6F,
    0x5D6F,
    { 0x8B, 0x01, 0xDB, 0x2D, 0x88, 0xD7, 0xC3, 0xC5 }
};
#define I_AVN_GROUP_BOX_ABI_VERSION 3
struct IAvnGroupBoxVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnGroupBox* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnGroupBox* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnGroupBox* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnGroupBox* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnGroupBox* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnGroupBox* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnGroupBox* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnGroupBox* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnGroupBox* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnGroupBox* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnGroupBox* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnGroupBox* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnGroupBox* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnGroupBox* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnGroupBox* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnGroupBox* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnGroupBox* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnGroupBox* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnGroupBox* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnGroupBox* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnGroupBox* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnGroupBox* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnGroupBox* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnGroupBox* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnGroupBox* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnGroupBox* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnGroupBox* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnGroupBox* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnGroupBox* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnGroupBox* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnGroupBox* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnGroupBox* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnGroupBox* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnGroupBox* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnGroupBox* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnGroupBox* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnGroupBox* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnGroupBox* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnGroupBox* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnGroupBox* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnGroupBox* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnGroupBox* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnGroupBox* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnGroupBox* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnGroupBox* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnGroupBox* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnGroupBox* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnGroupBox* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnGroupBox* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnGroupBox* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnGroupBox* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnGroupBox* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnGroupBox* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnGroupBox* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnGroupBox* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnGroupBox* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnGroupBox* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnGroupBox* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnGroupBox* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnGroupBox* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnGroupBox* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnGroupBox* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnGroupBox* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnGroupBox* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnGroupBox* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnGroupBox* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnGroupBox* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnGroupBox* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnGroupBox* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnGroupBox* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnGroupBox* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnGroupBox* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnGroupBox* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnGroupBox* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnGroupBox* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnGroupBox* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnGroupBox* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_header)(IAvnGroupBox* self, IAvnControl** value); /* slot 77 */
    AvnHResult (AVN_CALL *set_header)(IAvnGroupBox* self, IAvnControl* value); /* slot 78 */
};
struct IAvnGroupBox { const IAvnGroupBoxVtbl* vtbl; };
#define I_AVN_GROUP_BOX_VTABLE_SLOTS 79

static const AvnGuid I_AVN_HEADERED_CONTENT_CONTROL_IID = {
    0x070EFA6A,
    0x7C6E,
    0x5A69,
    { 0xB9, 0xED, 0x48, 0x50, 0x1E, 0x7F, 0xAE, 0xF8 }
};
#define I_AVN_HEADERED_CONTENT_CONTROL_ABI_VERSION 7
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnHeaderedContentControl* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnHeaderedContentControl* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnHeaderedContentControl* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnHeaderedContentControl* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnHeaderedContentControl* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnHeaderedContentControl* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnHeaderedContentControl* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnHeaderedContentControl* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnHeaderedContentControl* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnHeaderedContentControl* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnHeaderedContentControl* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnHeaderedContentControl* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnHeaderedContentControl* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnHeaderedContentControl* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnHeaderedContentControl* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnHeaderedContentControl* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnHeaderedContentControl* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnHeaderedContentControl* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnHeaderedContentControl* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnHeaderedContentControl* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnHeaderedContentControl* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnHeaderedContentControl* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnHeaderedContentControl* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnHeaderedContentControl* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnHeaderedContentControl* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnHeaderedContentControl* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnHeaderedContentControl* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnHeaderedContentControl* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnHeaderedContentControl* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnHeaderedContentControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnHeaderedContentControl* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnHeaderedContentControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnHeaderedContentControl* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnHeaderedContentControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnHeaderedContentControl* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnHeaderedContentControl* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnHeaderedContentControl* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnHeaderedContentControl* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnHeaderedContentControl* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnHeaderedContentControl* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnHeaderedContentControl* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnHeaderedContentControl* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnHeaderedContentControl* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnHeaderedContentControl* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnHeaderedContentControl* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnHeaderedContentControl* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnHeaderedContentControl* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnHeaderedContentControl* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnHeaderedContentControl* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnHeaderedContentControl* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnHeaderedContentControl* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnHeaderedContentControl* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnHeaderedContentControl* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnHeaderedContentControl* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnHeaderedContentControl* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnHeaderedContentControl* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnHeaderedContentControl* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnHeaderedContentControl* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnHeaderedContentControl* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnHeaderedContentControl* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnHeaderedContentControl* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnHeaderedContentControl* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnHeaderedContentControl* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnHeaderedContentControl* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnHeaderedContentControl* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_header)(IAvnHeaderedContentControl* self, IAvnControl** value); /* slot 77 */
    AvnHResult (AVN_CALL *set_header)(IAvnHeaderedContentControl* self, IAvnControl* value); /* slot 78 */
};
struct IAvnHeaderedContentControl { const IAvnHeaderedContentControlVtbl* vtbl; };
#define I_AVN_HEADERED_CONTENT_CONTROL_VTABLE_SLOTS 79

static const AvnGuid I_AVN_HEADERED_ITEMS_CONTROL_IID = {
    0x5702F481,
    0x00DC,
    0x5E0F,
    { 0xB4, 0xF2, 0xF3, 0x68, 0x7F, 0xA6, 0xCD, 0xB3 }
};
#define I_AVN_HEADERED_ITEMS_CONTROL_ABI_VERSION 4
struct IAvnHeaderedItemsControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnHeaderedItemsControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnHeaderedItemsControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnHeaderedItemsControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnHeaderedItemsControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnHeaderedItemsControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnHeaderedItemsControl* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnHeaderedItemsControl* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnHeaderedItemsControl* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnHeaderedItemsControl* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnHeaderedItemsControl* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnHeaderedItemsControl* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnHeaderedItemsControl* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnHeaderedItemsControl* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnHeaderedItemsControl* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnHeaderedItemsControl* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnHeaderedItemsControl* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnHeaderedItemsControl* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnHeaderedItemsControl* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnHeaderedItemsControl* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnHeaderedItemsControl* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnHeaderedItemsControl* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnHeaderedItemsControl* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnHeaderedItemsControl* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnHeaderedItemsControl* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnHeaderedItemsControl* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnHeaderedItemsControl* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnHeaderedItemsControl* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnHeaderedItemsControl* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnHeaderedItemsControl* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnHeaderedItemsControl* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnHeaderedItemsControl* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnHeaderedItemsControl* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnHeaderedItemsControl* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnHeaderedItemsControl* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnHeaderedItemsControl* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnHeaderedItemsControl* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnHeaderedItemsControl* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnHeaderedItemsControl* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnHeaderedItemsControl* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnHeaderedItemsControl* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnHeaderedItemsControl* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnHeaderedItemsControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnHeaderedItemsControl* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnHeaderedItemsControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnHeaderedItemsControl* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnHeaderedItemsControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnHeaderedItemsControl* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnHeaderedItemsControl* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnHeaderedItemsControl* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnHeaderedItemsControl* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnHeaderedItemsControl* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnHeaderedItemsControl* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnHeaderedItemsControl* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnHeaderedItemsControl* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnHeaderedItemsControl* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnHeaderedItemsControl* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnHeaderedItemsControl* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnHeaderedItemsControl* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnHeaderedItemsControl* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnHeaderedItemsControl* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnHeaderedItemsControl* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnHeaderedItemsControl* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnHeaderedItemsControl* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnHeaderedItemsControl* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnHeaderedItemsControl* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnHeaderedItemsControl* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnHeaderedItemsControl* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnHeaderedItemsControl* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnHeaderedItemsControl* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnHeaderedItemsControl* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnHeaderedItemsControl* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_items)(IAvnHeaderedItemsControl* self, IAvnItemList** value); /* slot 71 */
    AvnHResult (AVN_CALL *get_item_count)(IAvnHeaderedItemsControl* self, int32_t* value); /* slot 72 */
    AvnHResult (AVN_CALL *scroll_into_view_with_int32)(IAvnHeaderedItemsControl* self, int32_t index); /* slot 73 */
    AvnHResult (AVN_CALL *get_header)(IAvnHeaderedItemsControl* self, IAvnControl** value); /* slot 74 */
    AvnHResult (AVN_CALL *set_header)(IAvnHeaderedItemsControl* self, IAvnControl* value); /* slot 75 */
};
struct IAvnHeaderedItemsControl { const IAvnHeaderedItemsControlVtbl* vtbl; };
#define I_AVN_HEADERED_ITEMS_CONTROL_VTABLE_SLOTS 76

static const AvnGuid I_AVN_HEADERED_SELECTING_ITEMS_CONTROL_IID = {
    0x00E6E8A1,
    0xBF08,
    0x5CA9,
    { 0x9C, 0x29, 0xCC, 0x62, 0x5E, 0x3D, 0x25, 0x6C }
};
#define I_AVN_HEADERED_SELECTING_ITEMS_CONTROL_ABI_VERSION 4
struct IAvnHeaderedSelectingItemsControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnHeaderedSelectingItemsControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnHeaderedSelectingItemsControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnHeaderedSelectingItemsControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnHeaderedSelectingItemsControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnHeaderedSelectingItemsControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnHeaderedSelectingItemsControl* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnHeaderedSelectingItemsControl* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnHeaderedSelectingItemsControl* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnHeaderedSelectingItemsControl* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnHeaderedSelectingItemsControl* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnHeaderedSelectingItemsControl* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnHeaderedSelectingItemsControl* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnHeaderedSelectingItemsControl* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnHeaderedSelectingItemsControl* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnHeaderedSelectingItemsControl* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnHeaderedSelectingItemsControl* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnHeaderedSelectingItemsControl* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnHeaderedSelectingItemsControl* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnHeaderedSelectingItemsControl* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnHeaderedSelectingItemsControl* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnHeaderedSelectingItemsControl* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnHeaderedSelectingItemsControl* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnHeaderedSelectingItemsControl* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnHeaderedSelectingItemsControl* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnHeaderedSelectingItemsControl* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnHeaderedSelectingItemsControl* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnHeaderedSelectingItemsControl* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnHeaderedSelectingItemsControl* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnHeaderedSelectingItemsControl* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnHeaderedSelectingItemsControl* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnHeaderedSelectingItemsControl* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnHeaderedSelectingItemsControl* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnHeaderedSelectingItemsControl* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnHeaderedSelectingItemsControl* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnHeaderedSelectingItemsControl* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnHeaderedSelectingItemsControl* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnHeaderedSelectingItemsControl* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnHeaderedSelectingItemsControl* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnHeaderedSelectingItemsControl* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnHeaderedSelectingItemsControl* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnHeaderedSelectingItemsControl* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnHeaderedSelectingItemsControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnHeaderedSelectingItemsControl* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnHeaderedSelectingItemsControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnHeaderedSelectingItemsControl* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnHeaderedSelectingItemsControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnHeaderedSelectingItemsControl* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnHeaderedSelectingItemsControl* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnHeaderedSelectingItemsControl* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnHeaderedSelectingItemsControl* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnHeaderedSelectingItemsControl* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnHeaderedSelectingItemsControl* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnHeaderedSelectingItemsControl* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnHeaderedSelectingItemsControl* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnHeaderedSelectingItemsControl* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnHeaderedSelectingItemsControl* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnHeaderedSelectingItemsControl* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnHeaderedSelectingItemsControl* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnHeaderedSelectingItemsControl* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnHeaderedSelectingItemsControl* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnHeaderedSelectingItemsControl* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnHeaderedSelectingItemsControl* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnHeaderedSelectingItemsControl* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnHeaderedSelectingItemsControl* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnHeaderedSelectingItemsControl* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnHeaderedSelectingItemsControl* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnHeaderedSelectingItemsControl* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnHeaderedSelectingItemsControl* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnHeaderedSelectingItemsControl* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnHeaderedSelectingItemsControl* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnHeaderedSelectingItemsControl* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_items)(IAvnHeaderedSelectingItemsControl* self, IAvnItemList** value); /* slot 71 */
    AvnHResult (AVN_CALL *get_item_count)(IAvnHeaderedSelectingItemsControl* self, int32_t* value); /* slot 72 */
    AvnHResult (AVN_CALL *scroll_into_view_with_int32)(IAvnHeaderedSelectingItemsControl* self, int32_t index); /* slot 73 */
    AvnHResult (AVN_CALL *get_auto_scroll_to_selected_item)(IAvnHeaderedSelectingItemsControl* self, int32_t* value); /* slot 74 */
    AvnHResult (AVN_CALL *set_auto_scroll_to_selected_item)(IAvnHeaderedSelectingItemsControl* self, int32_t value); /* slot 75 */
    AvnHResult (AVN_CALL *get_selected_index)(IAvnHeaderedSelectingItemsControl* self, int32_t* value); /* slot 76 */
    AvnHResult (AVN_CALL *set_selected_index)(IAvnHeaderedSelectingItemsControl* self, int32_t value); /* slot 77 */
    AvnHResult (AVN_CALL *get_is_text_search_enabled)(IAvnHeaderedSelectingItemsControl* self, int32_t* value); /* slot 78 */
    AvnHResult (AVN_CALL *set_is_text_search_enabled)(IAvnHeaderedSelectingItemsControl* self, int32_t value); /* slot 79 */
    AvnHResult (AVN_CALL *get_wrap_selection)(IAvnHeaderedSelectingItemsControl* self, int32_t* value); /* slot 80 */
    AvnHResult (AVN_CALL *set_wrap_selection)(IAvnHeaderedSelectingItemsControl* self, int32_t value); /* slot 81 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnHeaderedSelectingItemsControl* self, IAvnSelectingItemsControlSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 82 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnHeaderedSelectingItemsControl* self, int64_t subscription_id); /* slot 83 */
    AvnHResult (AVN_CALL *get_header)(IAvnHeaderedSelectingItemsControl* self, IAvnControl** value); /* slot 84 */
    AvnHResult (AVN_CALL *set_header)(IAvnHeaderedSelectingItemsControl* self, IAvnControl* value); /* slot 85 */
};
struct IAvnHeaderedSelectingItemsControl { const IAvnHeaderedSelectingItemsControlVtbl* vtbl; };
#define I_AVN_HEADERED_SELECTING_ITEMS_CONTROL_VTABLE_SLOTS 86

static const AvnGuid I_AVN_HYPERLINK_BUTTON_IID = {
    0x471B3BAE,
    0x2E59,
    0x5955,
    { 0x97, 0x38, 0xF8, 0x54, 0xF5, 0xEB, 0xA8, 0x27 }
};
#define I_AVN_HYPERLINK_BUTTON_ABI_VERSION 5
struct IAvnHyperlinkButtonVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnHyperlinkButton* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnHyperlinkButton* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnHyperlinkButton* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnHyperlinkButton* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnHyperlinkButton* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnHyperlinkButton* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnHyperlinkButton* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnHyperlinkButton* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnHyperlinkButton* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnHyperlinkButton* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnHyperlinkButton* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnHyperlinkButton* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnHyperlinkButton* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnHyperlinkButton* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnHyperlinkButton* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnHyperlinkButton* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnHyperlinkButton* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnHyperlinkButton* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnHyperlinkButton* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnHyperlinkButton* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnHyperlinkButton* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnHyperlinkButton* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnHyperlinkButton* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnHyperlinkButton* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnHyperlinkButton* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnHyperlinkButton* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnHyperlinkButton* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnHyperlinkButton* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnHyperlinkButton* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnHyperlinkButton* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnHyperlinkButton* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnHyperlinkButton* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnHyperlinkButton* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnHyperlinkButton* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnHyperlinkButton* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnHyperlinkButton* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnHyperlinkButton* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnHyperlinkButton* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnHyperlinkButton* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnHyperlinkButton* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnHyperlinkButton* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnHyperlinkButton* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnHyperlinkButton* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnHyperlinkButton* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnHyperlinkButton* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnHyperlinkButton* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnHyperlinkButton* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnHyperlinkButton* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnHyperlinkButton* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnHyperlinkButton* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnHyperlinkButton* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnHyperlinkButton* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnHyperlinkButton* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnHyperlinkButton* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnHyperlinkButton* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnHyperlinkButton* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnHyperlinkButton* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnHyperlinkButton* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnHyperlinkButton* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnHyperlinkButton* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnHyperlinkButton* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnHyperlinkButton* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnHyperlinkButton* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnHyperlinkButton* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnHyperlinkButton* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnHyperlinkButton* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnHyperlinkButton* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnHyperlinkButton* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnHyperlinkButton* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnHyperlinkButton* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnHyperlinkButton* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnHyperlinkButton* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnHyperlinkButton* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnHyperlinkButton* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnHyperlinkButton* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnHyperlinkButton* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnHyperlinkButton* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_click_mode)(IAvnHyperlinkButton* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_click_mode)(IAvnHyperlinkButton* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_command)(IAvnHyperlinkButton* self, IAvnCommand** value); /* slot 79 */
    AvnHResult (AVN_CALL *set_command)(IAvnHyperlinkButton* self, IAvnCommand* value); /* slot 80 */
    AvnHResult (AVN_CALL *get_command_parameter)(IAvnHyperlinkButton* self, AvnVariant* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_command_parameter)(IAvnHyperlinkButton* self, AvnVariant value); /* slot 82 */
    AvnHResult (AVN_CALL *get_is_default)(IAvnHyperlinkButton* self, int32_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_is_default)(IAvnHyperlinkButton* self, int32_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_is_cancel)(IAvnHyperlinkButton* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_is_cancel)(IAvnHyperlinkButton* self, int32_t value); /* slot 86 */
    AvnHResult (AVN_CALL *get_is_pressed)(IAvnHyperlinkButton* self, int32_t* value); /* slot 87 */
    AvnHResult (AVN_CALL *get_flyout)(IAvnHyperlinkButton* self, IAvnFlyoutBase** value); /* slot 88 */
    AvnHResult (AVN_CALL *set_flyout)(IAvnHyperlinkButton* self, IAvnFlyoutBase* value); /* slot 89 */
    AvnHResult (AVN_CALL *advise_click)(IAvnHyperlinkButton* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 90 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnHyperlinkButton* self, int64_t subscription_id); /* slot 91 */
    AvnHResult (AVN_CALL *get_is_visited)(IAvnHyperlinkButton* self, int32_t* value); /* slot 92 */
    AvnHResult (AVN_CALL *set_is_visited)(IAvnHyperlinkButton* self, int32_t value); /* slot 93 */
    AvnHResult (AVN_CALL *get_navigate_uri)(IAvnHyperlinkButton* self, uint16_t** value); /* slot 94 */
    AvnHResult (AVN_CALL *set_navigate_uri)(IAvnHyperlinkButton* self, const uint16_t* value); /* slot 95 */
};
struct IAvnHyperlinkButton { const IAvnHyperlinkButtonVtbl* vtbl; };
#define I_AVN_HYPERLINK_BUTTON_VTABLE_SLOTS 96

static const AvnGuid I_AVN_ICON_ELEMENT_IID = {
    0x685141CE,
    0xD115,
    0x53BB,
    { 0x8C, 0xBA, 0x0E, 0xFC, 0xF8, 0x9D, 0xE8, 0x71 }
};
#define I_AVN_ICON_ELEMENT_ABI_VERSION 3
struct IAvnIconElementVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnIconElement* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnIconElement* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnIconElement* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnIconElement* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnIconElement* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnIconElement* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnIconElement* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnIconElement* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnIconElement* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnIconElement* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnIconElement* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnIconElement* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnIconElement* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnIconElement* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnIconElement* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnIconElement* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnIconElement* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnIconElement* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnIconElement* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnIconElement* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnIconElement* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnIconElement* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnIconElement* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnIconElement* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnIconElement* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnIconElement* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnIconElement* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnIconElement* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnIconElement* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnIconElement* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnIconElement* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnIconElement* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnIconElement* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnIconElement* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnIconElement* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnIconElement* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnIconElement* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnIconElement* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnIconElement* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnIconElement* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnIconElement* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnIconElement* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnIconElement* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnIconElement* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnIconElement* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnIconElement* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnIconElement* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnIconElement* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnIconElement* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnIconElement* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnIconElement* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnIconElement* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnIconElement* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnIconElement* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnIconElement* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnIconElement* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnIconElement* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnIconElement* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnIconElement* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnIconElement* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnIconElement* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnIconElement* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnIconElement* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnIconElement* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnIconElement* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnIconElement* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnIconElement* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnIconElement* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnIconElement* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnIconElement* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnIconElement* self, AvnThickness value); /* slot 70 */
};
struct IAvnIconElement { const IAvnIconElementVtbl* vtbl; };
#define I_AVN_ICON_ELEMENT_VTABLE_SLOTS 71

static const AvnGuid I_AVN_IMAGE_IID = {
    0x471FA068,
    0x6C69,
    0x5AAB,
    { 0x96, 0xC0, 0x29, 0x07, 0x3F, 0xFB, 0x3C, 0x89 }
};
#define I_AVN_IMAGE_ABI_VERSION 2
struct IAvnImageVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnImage* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnImage* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnImage* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnImage* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnImage* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnImage* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnImage* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnImage* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnImage* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnImage* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnImage* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnImage* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnImage* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnImage* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnImage* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnImage* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnImage* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnImage* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnImage* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnImage* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnImage* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnImage* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnImage* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnImage* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnImage* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnImage* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnImage* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnImage* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnImage* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnImage* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnImage* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnImage* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnImage* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnImage* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnImage* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnImage* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnImage* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnImage* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnImage* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnImage* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnImage* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnImage* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnImage* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnImage* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnImage* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnImage* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnImage* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_source)(IAvnImage* self, uint16_t** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_source)(IAvnImage* self, const uint16_t* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_blend_mode)(IAvnImage* self, int32_t* value); /* slot 49 */
    AvnHResult (AVN_CALL *set_blend_mode)(IAvnImage* self, int32_t value); /* slot 50 */
    AvnHResult (AVN_CALL *get_stretch)(IAvnImage* self, int32_t* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_stretch)(IAvnImage* self, int32_t value); /* slot 52 */
    AvnHResult (AVN_CALL *get_stretch_direction)(IAvnImage* self, int32_t* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_stretch_direction)(IAvnImage* self, int32_t value); /* slot 54 */
};
struct IAvnImage { const IAvnImageVtbl* vtbl; };
#define I_AVN_IMAGE_VTABLE_SLOTS 55

static const AvnGuid I_AVN_ITEMS_CONTROL_IID = {
    0x266FAE15,
    0xE701,
    0x5220,
    { 0xAA, 0x28, 0xFF, 0xEA, 0xB6, 0x1E, 0xD3, 0xF7 }
};
#define I_AVN_ITEMS_CONTROL_ABI_VERSION 7
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnItemsControl* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnItemsControl* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnItemsControl* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnItemsControl* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnItemsControl* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnItemsControl* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnItemsControl* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnItemsControl* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnItemsControl* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnItemsControl* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnItemsControl* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnItemsControl* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnItemsControl* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnItemsControl* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnItemsControl* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnItemsControl* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnItemsControl* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnItemsControl* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnItemsControl* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnItemsControl* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnItemsControl* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnItemsControl* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnItemsControl* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnItemsControl* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnItemsControl* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnItemsControl* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnItemsControl* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnItemsControl* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnItemsControl* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnItemsControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnItemsControl* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnItemsControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnItemsControl* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnItemsControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnItemsControl* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnItemsControl* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnItemsControl* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnItemsControl* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnItemsControl* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnItemsControl* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnItemsControl* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnItemsControl* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnItemsControl* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnItemsControl* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnItemsControl* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnItemsControl* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnItemsControl* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnItemsControl* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnItemsControl* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnItemsControl* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnItemsControl* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnItemsControl* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnItemsControl* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnItemsControl* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnItemsControl* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnItemsControl* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnItemsControl* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnItemsControl* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnItemsControl* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_items)(IAvnItemsControl* self, IAvnItemList** value); /* slot 71 */
    AvnHResult (AVN_CALL *get_item_count)(IAvnItemsControl* self, int32_t* value); /* slot 72 */
    AvnHResult (AVN_CALL *scroll_into_view_with_int32)(IAvnItemsControl* self, int32_t index); /* slot 73 */
};
struct IAvnItemsControl { const IAvnItemsControlVtbl* vtbl; };
#define I_AVN_ITEMS_CONTROL_VTABLE_SLOTS 74

static const AvnGuid I_AVN_LABEL_IID = {
    0x03D8AC49,
    0x5620,
    0x5547,
    { 0x8B, 0x33, 0x91, 0xCB, 0xFC, 0x4A, 0x13, 0x4D }
};
#define I_AVN_LABEL_ABI_VERSION 4
struct IAvnLabelVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnLabel* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnLabel* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnLabel* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnLabel* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnLabel* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnLabel* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnLabel* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnLabel* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnLabel* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnLabel* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnLabel* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnLabel* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnLabel* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnLabel* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnLabel* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnLabel* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnLabel* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnLabel* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnLabel* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnLabel* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnLabel* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnLabel* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnLabel* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnLabel* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnLabel* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnLabel* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnLabel* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnLabel* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnLabel* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnLabel* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnLabel* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnLabel* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnLabel* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnLabel* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnLabel* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnLabel* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnLabel* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnLabel* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnLabel* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnLabel* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnLabel* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnLabel* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnLabel* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnLabel* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnLabel* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnLabel* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnLabel* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnLabel* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnLabel* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnLabel* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnLabel* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnLabel* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnLabel* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnLabel* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnLabel* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnLabel* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnLabel* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnLabel* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnLabel* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnLabel* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnLabel* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnLabel* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnLabel* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnLabel* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnLabel* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnLabel* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnLabel* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnLabel* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnLabel* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnLabel* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnLabel* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnLabel* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnLabel* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnLabel* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnLabel* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnLabel* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnLabel* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_target)(IAvnLabel* self, IAvnControl** value); /* slot 77 */
    AvnHResult (AVN_CALL *set_target)(IAvnLabel* self, IAvnControl* value); /* slot 78 */
};
struct IAvnLabel { const IAvnLabelVtbl* vtbl; };
#define I_AVN_LABEL_VTABLE_SLOTS 79

static const AvnGuid I_AVN_LAYOUT_TRANSFORM_CONTROL_IID = {
    0xFCA3934D,
    0x99C5,
    0x5CDC,
    { 0xAC, 0x44, 0xF2, 0x25, 0xE4, 0xE2, 0xEF, 0x3D }
};
#define I_AVN_LAYOUT_TRANSFORM_CONTROL_ABI_VERSION 2
struct IAvnLayoutTransformControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnLayoutTransformControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnLayoutTransformControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnLayoutTransformControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnLayoutTransformControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnLayoutTransformControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnLayoutTransformControl* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnLayoutTransformControl* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnLayoutTransformControl* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnLayoutTransformControl* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnLayoutTransformControl* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnLayoutTransformControl* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnLayoutTransformControl* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnLayoutTransformControl* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnLayoutTransformControl* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnLayoutTransformControl* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnLayoutTransformControl* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnLayoutTransformControl* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnLayoutTransformControl* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnLayoutTransformControl* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnLayoutTransformControl* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnLayoutTransformControl* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnLayoutTransformControl* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnLayoutTransformControl* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnLayoutTransformControl* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnLayoutTransformControl* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnLayoutTransformControl* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnLayoutTransformControl* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnLayoutTransformControl* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnLayoutTransformControl* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnLayoutTransformControl* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnLayoutTransformControl* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnLayoutTransformControl* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnLayoutTransformControl* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnLayoutTransformControl* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnLayoutTransformControl* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnLayoutTransformControl* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnLayoutTransformControl* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnLayoutTransformControl* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnLayoutTransformControl* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnLayoutTransformControl* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnLayoutTransformControl* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnLayoutTransformControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnLayoutTransformControl* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnLayoutTransformControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnLayoutTransformControl* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnLayoutTransformControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnLayoutTransformControl* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_child)(IAvnLayoutTransformControl* self, IAvnControl** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_child)(IAvnLayoutTransformControl* self, IAvnControl* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_padding)(IAvnLayoutTransformControl* self, AvnThickness* value); /* slot 49 */
    AvnHResult (AVN_CALL *set_padding)(IAvnLayoutTransformControl* self, AvnThickness value); /* slot 50 */
    AvnHResult (AVN_CALL *get_use_render_transform)(IAvnLayoutTransformControl* self, int32_t* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_use_render_transform)(IAvnLayoutTransformControl* self, int32_t value); /* slot 52 */
};
struct IAvnLayoutTransformControl { const IAvnLayoutTransformControlVtbl* vtbl; };
#define I_AVN_LAYOUT_TRANSFORM_CONTROL_VTABLE_SLOTS 53

static const AvnGuid I_AVN_LINE_IID = {
    0xAF0B0109,
    0x4E30,
    0x5F61,
    { 0xBA, 0x0A, 0xE8, 0xC5, 0xCB, 0xAC, 0x8B, 0x54 }
};
#define I_AVN_LINE_ABI_VERSION 2
struct IAvnLineVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnLine* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnLine* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnLine* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnLine* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnLine* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnLine* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnLine* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnLine* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnLine* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnLine* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnLine* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnLine* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnLine* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnLine* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnLine* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnLine* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnLine* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnLine* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnLine* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnLine* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnLine* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnLine* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnLine* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnLine* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnLine* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnLine* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnLine* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnLine* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnLine* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnLine* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnLine* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnLine* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnLine* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnLine* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnLine* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnLine* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnLine* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnLine* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnLine* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnLine* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnLine* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnLine* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnLine* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnLine* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnLine* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnLine* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnLine* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_fill)(IAvnLine* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_fill)(IAvnLine* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_stretch)(IAvnLine* self, int32_t* value); /* slot 49 */
    AvnHResult (AVN_CALL *set_stretch)(IAvnLine* self, int32_t value); /* slot 50 */
    AvnHResult (AVN_CALL *get_stroke)(IAvnLine* self, IAvnBrush** value); /* slot 51 */
    AvnHResult (AVN_CALL *set_stroke)(IAvnLine* self, IAvnBrush* value); /* slot 52 */
    AvnHResult (AVN_CALL *get_stroke_dash_offset)(IAvnLine* self, double* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_stroke_dash_offset)(IAvnLine* self, double value); /* slot 54 */
    AvnHResult (AVN_CALL *get_stroke_thickness)(IAvnLine* self, double* value); /* slot 55 */
    AvnHResult (AVN_CALL *set_stroke_thickness)(IAvnLine* self, double value); /* slot 56 */
    AvnHResult (AVN_CALL *get_stroke_line_cap)(IAvnLine* self, int32_t* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_stroke_line_cap)(IAvnLine* self, int32_t value); /* slot 58 */
    AvnHResult (AVN_CALL *get_stroke_join)(IAvnLine* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_stroke_join)(IAvnLine* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_stroke_miter_limit)(IAvnLine* self, double* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_stroke_miter_limit)(IAvnLine* self, double value); /* slot 62 */
    AvnHResult (AVN_CALL *get_start_point)(IAvnLine* self, AvnPoint* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_start_point)(IAvnLine* self, AvnPoint value); /* slot 64 */
    AvnHResult (AVN_CALL *get_end_point)(IAvnLine* self, AvnPoint* value); /* slot 65 */
    AvnHResult (AVN_CALL *set_end_point)(IAvnLine* self, AvnPoint value); /* slot 66 */
};
struct IAvnLine { const IAvnLineVtbl* vtbl; };
#define I_AVN_LINE_VTABLE_SLOTS 67

static const AvnGuid I_AVN_LIST_BOX_IID = {
    0x6355CFDF,
    0x4550,
    0x570A,
    { 0xAD, 0xDD, 0xA5, 0xD5, 0xAA, 0x0B, 0x2D, 0x2E }
};
#define I_AVN_LIST_BOX_ABI_VERSION 8
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnListBox* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnListBox* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnListBox* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnListBox* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnListBox* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnListBox* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnListBox* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnListBox* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnListBox* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnListBox* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnListBox* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnListBox* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnListBox* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnListBox* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnListBox* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnListBox* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnListBox* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnListBox* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnListBox* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnListBox* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnListBox* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnListBox* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnListBox* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnListBox* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnListBox* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnListBox* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnListBox* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnListBox* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnListBox* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnListBox* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnListBox* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnListBox* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnListBox* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnListBox* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnListBox* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnListBox* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnListBox* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnListBox* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnListBox* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnListBox* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnListBox* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnListBox* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnListBox* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnListBox* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnListBox* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnListBox* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnListBox* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnListBox* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnListBox* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnListBox* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnListBox* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnListBox* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnListBox* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnListBox* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnListBox* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnListBox* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnListBox* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnListBox* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnListBox* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_items)(IAvnListBox* self, IAvnItemList** value); /* slot 71 */
    AvnHResult (AVN_CALL *get_item_count)(IAvnListBox* self, int32_t* value); /* slot 72 */
    AvnHResult (AVN_CALL *scroll_into_view_with_int32)(IAvnListBox* self, int32_t index); /* slot 73 */
    AvnHResult (AVN_CALL *get_auto_scroll_to_selected_item)(IAvnListBox* self, int32_t* value); /* slot 74 */
    AvnHResult (AVN_CALL *set_auto_scroll_to_selected_item)(IAvnListBox* self, int32_t value); /* slot 75 */
    AvnHResult (AVN_CALL *get_selected_index)(IAvnListBox* self, int32_t* value); /* slot 76 */
    AvnHResult (AVN_CALL *set_selected_index)(IAvnListBox* self, int32_t value); /* slot 77 */
    AvnHResult (AVN_CALL *get_is_text_search_enabled)(IAvnListBox* self, int32_t* value); /* slot 78 */
    AvnHResult (AVN_CALL *set_is_text_search_enabled)(IAvnListBox* self, int32_t value); /* slot 79 */
    AvnHResult (AVN_CALL *get_wrap_selection)(IAvnListBox* self, int32_t* value); /* slot 80 */
    AvnHResult (AVN_CALL *set_wrap_selection)(IAvnListBox* self, int32_t value); /* slot 81 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnListBox* self, IAvnSelectingItemsControlSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 82 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnListBox* self, int64_t subscription_id); /* slot 83 */
    AvnHResult (AVN_CALL *get_selection_mode)(IAvnListBox* self, int32_t* value); /* slot 84 */
    AvnHResult (AVN_CALL *set_selection_mode)(IAvnListBox* self, int32_t value); /* slot 85 */
    AvnHResult (AVN_CALL *select_all)(IAvnListBox* self); /* slot 86 */
    AvnHResult (AVN_CALL *unselect_all)(IAvnListBox* self); /* slot 87 */
};
struct IAvnListBox { const IAvnListBoxVtbl* vtbl; };
#define I_AVN_LIST_BOX_VTABLE_SLOTS 88

static const AvnGuid I_AVN_LIST_BOX_ITEM_IID = {
    0x0A9448A4,
    0xC789,
    0x57E2,
    { 0x95, 0x55, 0x60, 0x6A, 0x08, 0xC0, 0x92, 0xCF }
};
#define I_AVN_LIST_BOX_ITEM_ABI_VERSION 7
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnListBoxItem* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnListBoxItem* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnListBoxItem* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnListBoxItem* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnListBoxItem* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnListBoxItem* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnListBoxItem* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnListBoxItem* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnListBoxItem* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnListBoxItem* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnListBoxItem* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnListBoxItem* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnListBoxItem* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnListBoxItem* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnListBoxItem* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnListBoxItem* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnListBoxItem* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnListBoxItem* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnListBoxItem* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnListBoxItem* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnListBoxItem* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnListBoxItem* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnListBoxItem* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnListBoxItem* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnListBoxItem* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnListBoxItem* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnListBoxItem* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnListBoxItem* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnListBoxItem* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnListBoxItem* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnListBoxItem* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnListBoxItem* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnListBoxItem* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnListBoxItem* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnListBoxItem* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnListBoxItem* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnListBoxItem* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnListBoxItem* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnListBoxItem* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnListBoxItem* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnListBoxItem* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnListBoxItem* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnListBoxItem* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnListBoxItem* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnListBoxItem* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnListBoxItem* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnListBoxItem* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnListBoxItem* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnListBoxItem* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnListBoxItem* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnListBoxItem* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnListBoxItem* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnListBoxItem* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnListBoxItem* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnListBoxItem* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnListBoxItem* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnListBoxItem* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnListBoxItem* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnListBoxItem* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnListBoxItem* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnListBoxItem* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnListBoxItem* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnListBoxItem* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnListBoxItem* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnListBoxItem* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_is_selected)(IAvnListBoxItem* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_is_selected)(IAvnListBoxItem* self, int32_t value); /* slot 78 */
};
struct IAvnListBoxItem { const IAvnListBoxItemVtbl* vtbl; };
#define I_AVN_LIST_BOX_ITEM_VTABLE_SLOTS 79

static const AvnGuid I_AVN_MASKED_TEXT_BOX_IID = {
    0x5EC5632E,
    0x068C,
    0x5B66,
    { 0xB1, 0xBD, 0x4F, 0x93, 0xB4, 0x74, 0x1B, 0xB6 }
};
#define I_AVN_MASKED_TEXT_BOX_ABI_VERSION 7
struct IAvnMaskedTextBoxVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnMaskedTextBox* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnMaskedTextBox* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnMaskedTextBox* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnMaskedTextBox* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnMaskedTextBox* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnMaskedTextBox* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnMaskedTextBox* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnMaskedTextBox* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnMaskedTextBox* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnMaskedTextBox* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnMaskedTextBox* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnMaskedTextBox* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnMaskedTextBox* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnMaskedTextBox* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnMaskedTextBox* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnMaskedTextBox* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnMaskedTextBox* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnMaskedTextBox* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnMaskedTextBox* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnMaskedTextBox* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnMaskedTextBox* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnMaskedTextBox* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnMaskedTextBox* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnMaskedTextBox* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnMaskedTextBox* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnMaskedTextBox* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnMaskedTextBox* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnMaskedTextBox* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnMaskedTextBox* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnMaskedTextBox* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnMaskedTextBox* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnMaskedTextBox* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnMaskedTextBox* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnMaskedTextBox* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnMaskedTextBox* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnMaskedTextBox* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnMaskedTextBox* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnMaskedTextBox* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnMaskedTextBox* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnMaskedTextBox* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnMaskedTextBox* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnMaskedTextBox* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnMaskedTextBox* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnMaskedTextBox* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnMaskedTextBox* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnMaskedTextBox* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnMaskedTextBox* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnMaskedTextBox* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnMaskedTextBox* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnMaskedTextBox* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnMaskedTextBox* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnMaskedTextBox* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnMaskedTextBox* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnMaskedTextBox* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnMaskedTextBox* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnMaskedTextBox* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnMaskedTextBox* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnMaskedTextBox* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnMaskedTextBox* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnMaskedTextBox* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnMaskedTextBox* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnMaskedTextBox* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnMaskedTextBox* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnMaskedTextBox* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnMaskedTextBox* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnMaskedTextBox* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnMaskedTextBox* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnMaskedTextBox* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnMaskedTextBox* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnMaskedTextBox* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnMaskedTextBox* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_is_inactive_selection_highlight_enabled)(IAvnMaskedTextBox* self, int32_t* value); /* slot 71 */
    AvnHResult (AVN_CALL *set_is_inactive_selection_highlight_enabled)(IAvnMaskedTextBox* self, int32_t value); /* slot 72 */
    AvnHResult (AVN_CALL *get_clear_selection_on_lost_focus)(IAvnMaskedTextBox* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_clear_selection_on_lost_focus)(IAvnMaskedTextBox* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_accepts_return)(IAvnMaskedTextBox* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_accepts_return)(IAvnMaskedTextBox* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_accepts_tab)(IAvnMaskedTextBox* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_accepts_tab)(IAvnMaskedTextBox* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_caret_index)(IAvnMaskedTextBox* self, int32_t* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_caret_index)(IAvnMaskedTextBox* self, int32_t value); /* slot 80 */
    AvnHResult (AVN_CALL *get_is_read_only)(IAvnMaskedTextBox* self, int32_t* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_is_read_only)(IAvnMaskedTextBox* self, int32_t value); /* slot 82 */
    AvnHResult (AVN_CALL *get_password_char)(IAvnMaskedTextBox* self, uint16_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_password_char)(IAvnMaskedTextBox* self, uint16_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_selection_brush)(IAvnMaskedTextBox* self, IAvnBrush** value); /* slot 85 */
    AvnHResult (AVN_CALL *set_selection_brush)(IAvnMaskedTextBox* self, IAvnBrush* value); /* slot 86 */
    AvnHResult (AVN_CALL *get_selection_foreground_brush)(IAvnMaskedTextBox* self, IAvnBrush** value); /* slot 87 */
    AvnHResult (AVN_CALL *set_selection_foreground_brush)(IAvnMaskedTextBox* self, IAvnBrush* value); /* slot 88 */
    AvnHResult (AVN_CALL *get_caret_brush)(IAvnMaskedTextBox* self, IAvnBrush** value); /* slot 89 */
    AvnHResult (AVN_CALL *set_caret_brush)(IAvnMaskedTextBox* self, IAvnBrush* value); /* slot 90 */
    AvnHResult (AVN_CALL *get_selection_start)(IAvnMaskedTextBox* self, int32_t* value); /* slot 91 */
    AvnHResult (AVN_CALL *set_selection_start)(IAvnMaskedTextBox* self, int32_t value); /* slot 92 */
    AvnHResult (AVN_CALL *get_selection_end)(IAvnMaskedTextBox* self, int32_t* value); /* slot 93 */
    AvnHResult (AVN_CALL *set_selection_end)(IAvnMaskedTextBox* self, int32_t value); /* slot 94 */
    AvnHResult (AVN_CALL *get_max_length)(IAvnMaskedTextBox* self, int32_t* value); /* slot 95 */
    AvnHResult (AVN_CALL *set_max_length)(IAvnMaskedTextBox* self, int32_t value); /* slot 96 */
    AvnHResult (AVN_CALL *get_max_lines)(IAvnMaskedTextBox* self, int32_t* value); /* slot 97 */
    AvnHResult (AVN_CALL *set_max_lines)(IAvnMaskedTextBox* self, int32_t value); /* slot 98 */
    AvnHResult (AVN_CALL *get_min_lines)(IAvnMaskedTextBox* self, int32_t* value); /* slot 99 */
    AvnHResult (AVN_CALL *set_min_lines)(IAvnMaskedTextBox* self, int32_t value); /* slot 100 */
    AvnHResult (AVN_CALL *get_line_height)(IAvnMaskedTextBox* self, double* value); /* slot 101 */
    AvnHResult (AVN_CALL *set_line_height)(IAvnMaskedTextBox* self, double value); /* slot 102 */
    AvnHResult (AVN_CALL *get_text)(IAvnMaskedTextBox* self, uint16_t** value); /* slot 103 */
    AvnHResult (AVN_CALL *set_text)(IAvnMaskedTextBox* self, const uint16_t* value); /* slot 104 */
    AvnHResult (AVN_CALL *get_selected_text)(IAvnMaskedTextBox* self, uint16_t** value); /* slot 105 */
    AvnHResult (AVN_CALL *set_selected_text)(IAvnMaskedTextBox* self, const uint16_t* value); /* slot 106 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnMaskedTextBox* self, int32_t* value); /* slot 107 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnMaskedTextBox* self, int32_t value); /* slot 108 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnMaskedTextBox* self, int32_t* value); /* slot 109 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnMaskedTextBox* self, int32_t value); /* slot 110 */
    AvnHResult (AVN_CALL *get_text_alignment)(IAvnMaskedTextBox* self, int32_t* value); /* slot 111 */
    AvnHResult (AVN_CALL *set_text_alignment)(IAvnMaskedTextBox* self, int32_t value); /* slot 112 */
    AvnHResult (AVN_CALL *get_placeholder_text)(IAvnMaskedTextBox* self, uint16_t** value); /* slot 113 */
    AvnHResult (AVN_CALL *set_placeholder_text)(IAvnMaskedTextBox* self, const uint16_t* value); /* slot 114 */
    AvnHResult (AVN_CALL *get_use_floating_placeholder)(IAvnMaskedTextBox* self, int32_t* value); /* slot 115 */
    AvnHResult (AVN_CALL *set_use_floating_placeholder)(IAvnMaskedTextBox* self, int32_t value); /* slot 116 */
    AvnHResult (AVN_CALL *get_placeholder_foreground)(IAvnMaskedTextBox* self, IAvnBrush** value); /* slot 117 */
    AvnHResult (AVN_CALL *set_placeholder_foreground)(IAvnMaskedTextBox* self, IAvnBrush* value); /* slot 118 */
    AvnHResult (AVN_CALL *get_inner_left_content)(IAvnMaskedTextBox* self, IAvnControl** value); /* slot 119 */
    AvnHResult (AVN_CALL *set_inner_left_content)(IAvnMaskedTextBox* self, IAvnControl* value); /* slot 120 */
    AvnHResult (AVN_CALL *get_inner_right_content)(IAvnMaskedTextBox* self, IAvnControl** value); /* slot 121 */
    AvnHResult (AVN_CALL *set_inner_right_content)(IAvnMaskedTextBox* self, IAvnControl* value); /* slot 122 */
    AvnHResult (AVN_CALL *get_reveal_password)(IAvnMaskedTextBox* self, int32_t* value); /* slot 123 */
    AvnHResult (AVN_CALL *set_reveal_password)(IAvnMaskedTextBox* self, int32_t value); /* slot 124 */
    AvnHResult (AVN_CALL *get_text_wrapping)(IAvnMaskedTextBox* self, int32_t* value); /* slot 125 */
    AvnHResult (AVN_CALL *set_text_wrapping)(IAvnMaskedTextBox* self, int32_t value); /* slot 126 */
    AvnHResult (AVN_CALL *get_new_line)(IAvnMaskedTextBox* self, uint16_t** value); /* slot 127 */
    AvnHResult (AVN_CALL *set_new_line)(IAvnMaskedTextBox* self, const uint16_t* value); /* slot 128 */
    AvnHResult (AVN_CALL *get_can_cut)(IAvnMaskedTextBox* self, int32_t* value); /* slot 129 */
    AvnHResult (AVN_CALL *get_can_copy)(IAvnMaskedTextBox* self, int32_t* value); /* slot 130 */
    AvnHResult (AVN_CALL *get_can_paste)(IAvnMaskedTextBox* self, int32_t* value); /* slot 131 */
    AvnHResult (AVN_CALL *get_is_undo_enabled)(IAvnMaskedTextBox* self, int32_t* value); /* slot 132 */
    AvnHResult (AVN_CALL *set_is_undo_enabled)(IAvnMaskedTextBox* self, int32_t value); /* slot 133 */
    AvnHResult (AVN_CALL *get_undo_limit)(IAvnMaskedTextBox* self, int32_t* value); /* slot 134 */
    AvnHResult (AVN_CALL *set_undo_limit)(IAvnMaskedTextBox* self, int32_t value); /* slot 135 */
    AvnHResult (AVN_CALL *get_can_undo)(IAvnMaskedTextBox* self, int32_t* value); /* slot 136 */
    AvnHResult (AVN_CALL *get_can_redo)(IAvnMaskedTextBox* self, int32_t* value); /* slot 137 */
    AvnHResult (AVN_CALL *clear_selection)(IAvnMaskedTextBox* self); /* slot 138 */
    AvnHResult (AVN_CALL *get_line_count)(IAvnMaskedTextBox* self, int32_t* value); /* slot 139 */
    AvnHResult (AVN_CALL *cut)(IAvnMaskedTextBox* self); /* slot 140 */
    AvnHResult (AVN_CALL *copy)(IAvnMaskedTextBox* self); /* slot 141 */
    AvnHResult (AVN_CALL *paste)(IAvnMaskedTextBox* self); /* slot 142 */
    AvnHResult (AVN_CALL *clear)(IAvnMaskedTextBox* self); /* slot 143 */
    AvnHResult (AVN_CALL *scroll_to_line_with_int32)(IAvnMaskedTextBox* self, int32_t line_index); /* slot 144 */
    AvnHResult (AVN_CALL *select_all)(IAvnMaskedTextBox* self); /* slot 145 */
    AvnHResult (AVN_CALL *undo)(IAvnMaskedTextBox* self); /* slot 146 */
    AvnHResult (AVN_CALL *redo)(IAvnMaskedTextBox* self); /* slot 147 */
    AvnHResult (AVN_CALL *advise_copying_to_clipboard)(IAvnMaskedTextBox* self, IAvnTextBoxCopyingToClipboardHandler* handler, int64_t* subscription_id); /* slot 148 */
    AvnHResult (AVN_CALL *unadvise_copying_to_clipboard)(IAvnMaskedTextBox* self, int64_t subscription_id); /* slot 149 */
    AvnHResult (AVN_CALL *advise_cutting_to_clipboard)(IAvnMaskedTextBox* self, IAvnTextBoxCuttingToClipboardHandler* handler, int64_t* subscription_id); /* slot 150 */
    AvnHResult (AVN_CALL *unadvise_cutting_to_clipboard)(IAvnMaskedTextBox* self, int64_t subscription_id); /* slot 151 */
    AvnHResult (AVN_CALL *advise_pasting_from_clipboard)(IAvnMaskedTextBox* self, IAvnTextBoxPastingFromClipboardHandler* handler, int64_t* subscription_id); /* slot 152 */
    AvnHResult (AVN_CALL *unadvise_pasting_from_clipboard)(IAvnMaskedTextBox* self, int64_t subscription_id); /* slot 153 */
    AvnHResult (AVN_CALL *advise_text_changed)(IAvnMaskedTextBox* self, IAvnTextBoxTextChangedHandler* handler, int64_t* subscription_id); /* slot 154 */
    AvnHResult (AVN_CALL *unadvise_text_changed)(IAvnMaskedTextBox* self, int64_t subscription_id); /* slot 155 */
    AvnHResult (AVN_CALL *get_ascii_only)(IAvnMaskedTextBox* self, int32_t* value); /* slot 156 */
    AvnHResult (AVN_CALL *set_ascii_only)(IAvnMaskedTextBox* self, int32_t value); /* slot 157 */
    AvnHResult (AVN_CALL *get_hide_prompt_on_leave)(IAvnMaskedTextBox* self, int32_t* value); /* slot 158 */
    AvnHResult (AVN_CALL *set_hide_prompt_on_leave)(IAvnMaskedTextBox* self, int32_t value); /* slot 159 */
    AvnHResult (AVN_CALL *get_mask)(IAvnMaskedTextBox* self, uint16_t** value); /* slot 160 */
    AvnHResult (AVN_CALL *set_mask)(IAvnMaskedTextBox* self, const uint16_t* value); /* slot 161 */
    AvnHResult (AVN_CALL *get_mask_completed)(IAvnMaskedTextBox* self, int32_t* value); /* slot 162 */
    AvnHResult (AVN_CALL *get_mask_full)(IAvnMaskedTextBox* self, int32_t* value); /* slot 163 */
    AvnHResult (AVN_CALL *get_prompt_char)(IAvnMaskedTextBox* self, uint16_t* value); /* slot 164 */
    AvnHResult (AVN_CALL *set_prompt_char)(IAvnMaskedTextBox* self, uint16_t value); /* slot 165 */
    AvnHResult (AVN_CALL *get_reset_on_prompt)(IAvnMaskedTextBox* self, int32_t* value); /* slot 166 */
    AvnHResult (AVN_CALL *set_reset_on_prompt)(IAvnMaskedTextBox* self, int32_t value); /* slot 167 */
    AvnHResult (AVN_CALL *get_reset_on_space)(IAvnMaskedTextBox* self, int32_t* value); /* slot 168 */
    AvnHResult (AVN_CALL *set_reset_on_space)(IAvnMaskedTextBox* self, int32_t value); /* slot 169 */
};
struct IAvnMaskedTextBox { const IAvnMaskedTextBoxVtbl* vtbl; };
#define I_AVN_MASKED_TEXT_BOX_VTABLE_SLOTS 170

static const AvnGuid I_AVN_MENU_IID = {
    0x3AE47AF3,
    0xBBC0,
    0x55D9,
    { 0x91, 0x3F, 0x07, 0x6B, 0x7C, 0x9A, 0x56, 0xE8 }
};
#define I_AVN_MENU_ABI_VERSION 4
struct IAvnMenuVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnMenu* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnMenu* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnMenu* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnMenu* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnMenu* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnMenu* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnMenu* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnMenu* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnMenu* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnMenu* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnMenu* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnMenu* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnMenu* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnMenu* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnMenu* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnMenu* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnMenu* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnMenu* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnMenu* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnMenu* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnMenu* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnMenu* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnMenu* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnMenu* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnMenu* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnMenu* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnMenu* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnMenu* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnMenu* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnMenu* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnMenu* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnMenu* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnMenu* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnMenu* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnMenu* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnMenu* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnMenu* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnMenu* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnMenu* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnMenu* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnMenu* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnMenu* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnMenu* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnMenu* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnMenu* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnMenu* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnMenu* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnMenu* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnMenu* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnMenu* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnMenu* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnMenu* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnMenu* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnMenu* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnMenu* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnMenu* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnMenu* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnMenu* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnMenu* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnMenu* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnMenu* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnMenu* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnMenu* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnMenu* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnMenu* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnMenu* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnMenu* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnMenu* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnMenu* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnMenu* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnMenu* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_items)(IAvnMenu* self, IAvnItemList** value); /* slot 71 */
    AvnHResult (AVN_CALL *get_item_count)(IAvnMenu* self, int32_t* value); /* slot 72 */
    AvnHResult (AVN_CALL *scroll_into_view_with_int32)(IAvnMenu* self, int32_t index); /* slot 73 */
    AvnHResult (AVN_CALL *get_auto_scroll_to_selected_item)(IAvnMenu* self, int32_t* value); /* slot 74 */
    AvnHResult (AVN_CALL *set_auto_scroll_to_selected_item)(IAvnMenu* self, int32_t value); /* slot 75 */
    AvnHResult (AVN_CALL *get_selected_index)(IAvnMenu* self, int32_t* value); /* slot 76 */
    AvnHResult (AVN_CALL *set_selected_index)(IAvnMenu* self, int32_t value); /* slot 77 */
    AvnHResult (AVN_CALL *get_is_text_search_enabled)(IAvnMenu* self, int32_t* value); /* slot 78 */
    AvnHResult (AVN_CALL *set_is_text_search_enabled)(IAvnMenu* self, int32_t value); /* slot 79 */
    AvnHResult (AVN_CALL *get_wrap_selection)(IAvnMenu* self, int32_t* value); /* slot 80 */
    AvnHResult (AVN_CALL *set_wrap_selection)(IAvnMenu* self, int32_t value); /* slot 81 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnMenu* self, IAvnSelectingItemsControlSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 82 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnMenu* self, int64_t subscription_id); /* slot 83 */
    AvnHResult (AVN_CALL *get_is_open)(IAvnMenu* self, int32_t* value); /* slot 84 */
    AvnHResult (AVN_CALL *close)(IAvnMenu* self); /* slot 85 */
    AvnHResult (AVN_CALL *open)(IAvnMenu* self); /* slot 86 */
    AvnHResult (AVN_CALL *advise_opened)(IAvnMenu* self, IAvnMenuBaseOpenedHandler* handler, int64_t* subscription_id); /* slot 87 */
    AvnHResult (AVN_CALL *unadvise_opened)(IAvnMenu* self, int64_t subscription_id); /* slot 88 */
    AvnHResult (AVN_CALL *advise_closed)(IAvnMenu* self, IAvnMenuBaseClosedHandler* handler, int64_t* subscription_id); /* slot 89 */
    AvnHResult (AVN_CALL *unadvise_closed)(IAvnMenu* self, int64_t subscription_id); /* slot 90 */
};
struct IAvnMenu { const IAvnMenuVtbl* vtbl; };
#define I_AVN_MENU_VTABLE_SLOTS 91

static const AvnGuid I_AVN_MENU_BASE_IID = {
    0xCEAF4CFD,
    0x0A4C,
    0x5481,
    { 0x86, 0x73, 0x50, 0xF0, 0x78, 0xE7, 0x35, 0x73 }
};
#define I_AVN_MENU_BASE_ABI_VERSION 4
struct IAvnMenuBaseVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnMenuBase* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnMenuBase* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnMenuBase* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnMenuBase* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnMenuBase* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnMenuBase* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnMenuBase* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnMenuBase* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnMenuBase* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnMenuBase* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnMenuBase* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnMenuBase* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnMenuBase* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnMenuBase* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnMenuBase* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnMenuBase* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnMenuBase* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnMenuBase* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnMenuBase* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnMenuBase* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnMenuBase* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnMenuBase* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnMenuBase* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnMenuBase* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnMenuBase* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnMenuBase* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnMenuBase* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnMenuBase* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnMenuBase* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnMenuBase* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnMenuBase* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnMenuBase* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnMenuBase* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnMenuBase* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnMenuBase* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnMenuBase* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnMenuBase* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnMenuBase* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnMenuBase* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnMenuBase* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnMenuBase* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnMenuBase* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnMenuBase* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnMenuBase* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnMenuBase* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnMenuBase* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnMenuBase* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnMenuBase* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnMenuBase* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnMenuBase* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnMenuBase* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnMenuBase* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnMenuBase* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnMenuBase* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnMenuBase* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnMenuBase* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnMenuBase* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnMenuBase* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnMenuBase* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnMenuBase* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnMenuBase* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnMenuBase* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnMenuBase* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnMenuBase* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnMenuBase* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnMenuBase* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnMenuBase* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnMenuBase* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnMenuBase* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnMenuBase* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnMenuBase* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_items)(IAvnMenuBase* self, IAvnItemList** value); /* slot 71 */
    AvnHResult (AVN_CALL *get_item_count)(IAvnMenuBase* self, int32_t* value); /* slot 72 */
    AvnHResult (AVN_CALL *scroll_into_view_with_int32)(IAvnMenuBase* self, int32_t index); /* slot 73 */
    AvnHResult (AVN_CALL *get_auto_scroll_to_selected_item)(IAvnMenuBase* self, int32_t* value); /* slot 74 */
    AvnHResult (AVN_CALL *set_auto_scroll_to_selected_item)(IAvnMenuBase* self, int32_t value); /* slot 75 */
    AvnHResult (AVN_CALL *get_selected_index)(IAvnMenuBase* self, int32_t* value); /* slot 76 */
    AvnHResult (AVN_CALL *set_selected_index)(IAvnMenuBase* self, int32_t value); /* slot 77 */
    AvnHResult (AVN_CALL *get_is_text_search_enabled)(IAvnMenuBase* self, int32_t* value); /* slot 78 */
    AvnHResult (AVN_CALL *set_is_text_search_enabled)(IAvnMenuBase* self, int32_t value); /* slot 79 */
    AvnHResult (AVN_CALL *get_wrap_selection)(IAvnMenuBase* self, int32_t* value); /* slot 80 */
    AvnHResult (AVN_CALL *set_wrap_selection)(IAvnMenuBase* self, int32_t value); /* slot 81 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnMenuBase* self, IAvnSelectingItemsControlSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 82 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnMenuBase* self, int64_t subscription_id); /* slot 83 */
    AvnHResult (AVN_CALL *get_is_open)(IAvnMenuBase* self, int32_t* value); /* slot 84 */
    AvnHResult (AVN_CALL *close)(IAvnMenuBase* self); /* slot 85 */
    AvnHResult (AVN_CALL *open)(IAvnMenuBase* self); /* slot 86 */
    AvnHResult (AVN_CALL *advise_opened)(IAvnMenuBase* self, IAvnMenuBaseOpenedHandler* handler, int64_t* subscription_id); /* slot 87 */
    AvnHResult (AVN_CALL *unadvise_opened)(IAvnMenuBase* self, int64_t subscription_id); /* slot 88 */
    AvnHResult (AVN_CALL *advise_closed)(IAvnMenuBase* self, IAvnMenuBaseClosedHandler* handler, int64_t* subscription_id); /* slot 89 */
    AvnHResult (AVN_CALL *unadvise_closed)(IAvnMenuBase* self, int64_t subscription_id); /* slot 90 */
};
struct IAvnMenuBase { const IAvnMenuBaseVtbl* vtbl; };
#define I_AVN_MENU_BASE_VTABLE_SLOTS 91

static const AvnGuid I_AVN_MENU_FLYOUT_IID = {
    0x56421EC0,
    0x482F,
    0x51EF,
    { 0xB5, 0x02, 0x58, 0xEF, 0x0D, 0xF9, 0x17, 0x26 }
};
#define I_AVN_MENU_FLYOUT_ABI_VERSION 3
struct IAvnMenuFlyoutVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnMenuFlyout* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnMenuFlyout* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnMenuFlyout* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnMenuFlyout* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnMenuFlyout* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_is_open)(IAvnMenuFlyout* self, int32_t* value); /* slot 5 */
    AvnHResult (AVN_CALL *set_is_open)(IAvnMenuFlyout* self, int32_t value); /* slot 6 */
    AvnHResult (AVN_CALL *get_target)(IAvnMenuFlyout* self, IAvnControl** value); /* slot 7 */
    AvnHResult (AVN_CALL *show_at_with_control)(IAvnMenuFlyout* self, IAvnControl* placement_target); /* slot 8 */
    AvnHResult (AVN_CALL *hide)(IAvnMenuFlyout* self); /* slot 9 */
    AvnHResult (AVN_CALL *advise_opened)(IAvnMenuFlyout* self, IAvnFlyoutBaseOpenedHandler* handler, int64_t* subscription_id); /* slot 10 */
    AvnHResult (AVN_CALL *unadvise_opened)(IAvnMenuFlyout* self, int64_t subscription_id); /* slot 11 */
    AvnHResult (AVN_CALL *advise_closed)(IAvnMenuFlyout* self, IAvnFlyoutBaseClosedHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_closed)(IAvnMenuFlyout* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *get_popup)(IAvnMenuFlyout* self, IAvnPopup** value); /* slot 14 */
    AvnHResult (AVN_CALL *get_placement)(IAvnMenuFlyout* self, int32_t* value); /* slot 15 */
    AvnHResult (AVN_CALL *set_placement)(IAvnMenuFlyout* self, int32_t value); /* slot 16 */
    AvnHResult (AVN_CALL *get_placement_gravity)(IAvnMenuFlyout* self, int32_t* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_placement_gravity)(IAvnMenuFlyout* self, int32_t value); /* slot 18 */
    AvnHResult (AVN_CALL *get_placement_anchor)(IAvnMenuFlyout* self, int32_t* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_placement_anchor)(IAvnMenuFlyout* self, int32_t value); /* slot 20 */
    AvnHResult (AVN_CALL *get_horizontal_offset)(IAvnMenuFlyout* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_horizontal_offset)(IAvnMenuFlyout* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_vertical_offset)(IAvnMenuFlyout* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_vertical_offset)(IAvnMenuFlyout* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_show_mode)(IAvnMenuFlyout* self, int32_t* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_show_mode)(IAvnMenuFlyout* self, int32_t value); /* slot 26 */
    AvnHResult (AVN_CALL *get_overlay_dismiss_event_pass_through)(IAvnMenuFlyout* self, int32_t* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_overlay_dismiss_event_pass_through)(IAvnMenuFlyout* self, int32_t value); /* slot 28 */
    AvnHResult (AVN_CALL *get_placement_constraint_adjustment)(IAvnMenuFlyout* self, int32_t* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_placement_constraint_adjustment)(IAvnMenuFlyout* self, int32_t value); /* slot 30 */
    AvnHResult (AVN_CALL *advise_closing)(IAvnMenuFlyout* self, IAvnPopupFlyoutBaseClosingHandler* handler, int64_t* subscription_id); /* slot 31 */
    AvnHResult (AVN_CALL *unadvise_closing)(IAvnMenuFlyout* self, int64_t subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *advise_opening)(IAvnMenuFlyout* self, IAvnPopupFlyoutBaseOpeningHandler* handler, int64_t* subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *unadvise_opening)(IAvnMenuFlyout* self, int64_t subscription_id); /* slot 34 */
    AvnHResult (AVN_CALL *get_items)(IAvnMenuFlyout* self, IAvnItemList** value); /* slot 35 */
};
struct IAvnMenuFlyout { const IAvnMenuFlyoutVtbl* vtbl; };
#define I_AVN_MENU_FLYOUT_VTABLE_SLOTS 36

static const AvnGuid I_AVN_MENU_ITEM_IID = {
    0x62E74992,
    0xC111,
    0x5FDA,
    { 0xB9, 0x98, 0x9F, 0x4A, 0x3B, 0x67, 0x4A, 0x8D }
};
#define I_AVN_MENU_ITEM_ABI_VERSION 7
struct IAvnMenuItemVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnMenuItem* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnMenuItem* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnMenuItem* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnMenuItem* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnMenuItem* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnMenuItem* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnMenuItem* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnMenuItem* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnMenuItem* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnMenuItem* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnMenuItem* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnMenuItem* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnMenuItem* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnMenuItem* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnMenuItem* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnMenuItem* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnMenuItem* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnMenuItem* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnMenuItem* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnMenuItem* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnMenuItem* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnMenuItem* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnMenuItem* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnMenuItem* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnMenuItem* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnMenuItem* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnMenuItem* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnMenuItem* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnMenuItem* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnMenuItem* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnMenuItem* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnMenuItem* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnMenuItem* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnMenuItem* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnMenuItem* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnMenuItem* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnMenuItem* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnMenuItem* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnMenuItem* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnMenuItem* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnMenuItem* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnMenuItem* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnMenuItem* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnMenuItem* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnMenuItem* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnMenuItem* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnMenuItem* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnMenuItem* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnMenuItem* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnMenuItem* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnMenuItem* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnMenuItem* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnMenuItem* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnMenuItem* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnMenuItem* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnMenuItem* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnMenuItem* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnMenuItem* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnMenuItem* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnMenuItem* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnMenuItem* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnMenuItem* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnMenuItem* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnMenuItem* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnMenuItem* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnMenuItem* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnMenuItem* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnMenuItem* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnMenuItem* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnMenuItem* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnMenuItem* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_items)(IAvnMenuItem* self, IAvnItemList** value); /* slot 71 */
    AvnHResult (AVN_CALL *get_item_count)(IAvnMenuItem* self, int32_t* value); /* slot 72 */
    AvnHResult (AVN_CALL *scroll_into_view_with_int32)(IAvnMenuItem* self, int32_t index); /* slot 73 */
    AvnHResult (AVN_CALL *get_auto_scroll_to_selected_item)(IAvnMenuItem* self, int32_t* value); /* slot 74 */
    AvnHResult (AVN_CALL *set_auto_scroll_to_selected_item)(IAvnMenuItem* self, int32_t value); /* slot 75 */
    AvnHResult (AVN_CALL *get_selected_index)(IAvnMenuItem* self, int32_t* value); /* slot 76 */
    AvnHResult (AVN_CALL *set_selected_index)(IAvnMenuItem* self, int32_t value); /* slot 77 */
    AvnHResult (AVN_CALL *get_is_text_search_enabled)(IAvnMenuItem* self, int32_t* value); /* slot 78 */
    AvnHResult (AVN_CALL *set_is_text_search_enabled)(IAvnMenuItem* self, int32_t value); /* slot 79 */
    AvnHResult (AVN_CALL *get_wrap_selection)(IAvnMenuItem* self, int32_t* value); /* slot 80 */
    AvnHResult (AVN_CALL *set_wrap_selection)(IAvnMenuItem* self, int32_t value); /* slot 81 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnMenuItem* self, IAvnSelectingItemsControlSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 82 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnMenuItem* self, int64_t subscription_id); /* slot 83 */
    AvnHResult (AVN_CALL *get_header)(IAvnMenuItem* self, IAvnControl** value); /* slot 84 */
    AvnHResult (AVN_CALL *set_header)(IAvnMenuItem* self, IAvnControl* value); /* slot 85 */
    AvnHResult (AVN_CALL *get_command)(IAvnMenuItem* self, IAvnCommand** value); /* slot 86 */
    AvnHResult (AVN_CALL *set_command)(IAvnMenuItem* self, IAvnCommand* value); /* slot 87 */
    AvnHResult (AVN_CALL *get_command_parameter)(IAvnMenuItem* self, AvnVariant* value); /* slot 88 */
    AvnHResult (AVN_CALL *set_command_parameter)(IAvnMenuItem* self, AvnVariant value); /* slot 89 */
    AvnHResult (AVN_CALL *get_icon)(IAvnMenuItem* self, IAvnControl** value); /* slot 90 */
    AvnHResult (AVN_CALL *set_icon)(IAvnMenuItem* self, IAvnControl* value); /* slot 91 */
    AvnHResult (AVN_CALL *get_is_selected)(IAvnMenuItem* self, int32_t* value); /* slot 92 */
    AvnHResult (AVN_CALL *set_is_selected)(IAvnMenuItem* self, int32_t value); /* slot 93 */
    AvnHResult (AVN_CALL *get_is_sub_menu_open)(IAvnMenuItem* self, int32_t* value); /* slot 94 */
    AvnHResult (AVN_CALL *set_is_sub_menu_open)(IAvnMenuItem* self, int32_t value); /* slot 95 */
    AvnHResult (AVN_CALL *get_stays_open_on_click)(IAvnMenuItem* self, int32_t* value); /* slot 96 */
    AvnHResult (AVN_CALL *set_stays_open_on_click)(IAvnMenuItem* self, int32_t value); /* slot 97 */
    AvnHResult (AVN_CALL *get_toggle_type)(IAvnMenuItem* self, int32_t* value); /* slot 98 */
    AvnHResult (AVN_CALL *set_toggle_type)(IAvnMenuItem* self, int32_t value); /* slot 99 */
    AvnHResult (AVN_CALL *get_is_checked)(IAvnMenuItem* self, int32_t* value); /* slot 100 */
    AvnHResult (AVN_CALL *set_is_checked)(IAvnMenuItem* self, int32_t value); /* slot 101 */
    AvnHResult (AVN_CALL *get_group_name)(IAvnMenuItem* self, uint16_t** value); /* slot 102 */
    AvnHResult (AVN_CALL *set_group_name)(IAvnMenuItem* self, const uint16_t* value); /* slot 103 */
    AvnHResult (AVN_CALL *get_has_sub_menu)(IAvnMenuItem* self, int32_t* value); /* slot 104 */
    AvnHResult (AVN_CALL *get_is_top_level)(IAvnMenuItem* self, int32_t* value); /* slot 105 */
    AvnHResult (AVN_CALL *open)(IAvnMenuItem* self); /* slot 106 */
    AvnHResult (AVN_CALL *close)(IAvnMenuItem* self); /* slot 107 */
    AvnHResult (AVN_CALL *advise_click)(IAvnMenuItem* self, IAvnMenuItemClickHandler* handler, int64_t* subscription_id); /* slot 108 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnMenuItem* self, int64_t subscription_id); /* slot 109 */
    AvnHResult (AVN_CALL *advise_submenu_opened)(IAvnMenuItem* self, IAvnMenuItemSubmenuOpenedHandler* handler, int64_t* subscription_id); /* slot 110 */
    AvnHResult (AVN_CALL *unadvise_submenu_opened)(IAvnMenuItem* self, int64_t subscription_id); /* slot 111 */
};
struct IAvnMenuItem { const IAvnMenuItemVtbl* vtbl; };
#define I_AVN_MENU_ITEM_VTABLE_SLOTS 112

static const AvnGuid I_AVN_NOTIFICATION_CARD_IID = {
    0xBEDB9BA8,
    0x3CBC,
    0x5D58,
    { 0x8A, 0xDB, 0x96, 0x55, 0x8A, 0xE3, 0xC9, 0x69 }
};
#define I_AVN_NOTIFICATION_CARD_ABI_VERSION 4
struct IAvnNotificationCardVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnNotificationCard* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnNotificationCard* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnNotificationCard* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnNotificationCard* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnNotificationCard* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnNotificationCard* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnNotificationCard* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnNotificationCard* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnNotificationCard* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnNotificationCard* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnNotificationCard* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnNotificationCard* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnNotificationCard* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnNotificationCard* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnNotificationCard* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnNotificationCard* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnNotificationCard* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnNotificationCard* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnNotificationCard* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnNotificationCard* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnNotificationCard* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnNotificationCard* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnNotificationCard* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnNotificationCard* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnNotificationCard* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnNotificationCard* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnNotificationCard* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnNotificationCard* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnNotificationCard* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnNotificationCard* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnNotificationCard* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnNotificationCard* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnNotificationCard* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnNotificationCard* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnNotificationCard* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnNotificationCard* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnNotificationCard* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnNotificationCard* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnNotificationCard* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnNotificationCard* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnNotificationCard* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnNotificationCard* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnNotificationCard* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnNotificationCard* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnNotificationCard* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnNotificationCard* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnNotificationCard* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnNotificationCard* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnNotificationCard* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnNotificationCard* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnNotificationCard* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnNotificationCard* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnNotificationCard* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnNotificationCard* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnNotificationCard* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnNotificationCard* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnNotificationCard* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnNotificationCard* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnNotificationCard* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnNotificationCard* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnNotificationCard* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnNotificationCard* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnNotificationCard* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnNotificationCard* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnNotificationCard* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnNotificationCard* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnNotificationCard* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnNotificationCard* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnNotificationCard* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnNotificationCard* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnNotificationCard* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnNotificationCard* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnNotificationCard* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnNotificationCard* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnNotificationCard* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnNotificationCard* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnNotificationCard* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_is_closing)(IAvnNotificationCard* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *get_is_closed)(IAvnNotificationCard* self, int32_t* value); /* slot 78 */
    AvnHResult (AVN_CALL *set_is_closed)(IAvnNotificationCard* self, int32_t value); /* slot 79 */
    AvnHResult (AVN_CALL *get_notification_type)(IAvnNotificationCard* self, int32_t* value); /* slot 80 */
    AvnHResult (AVN_CALL *set_notification_type)(IAvnNotificationCard* self, int32_t value); /* slot 81 */
    AvnHResult (AVN_CALL *close)(IAvnNotificationCard* self); /* slot 82 */
};
struct IAvnNotificationCard { const IAvnNotificationCardVtbl* vtbl; };
#define I_AVN_NOTIFICATION_CARD_VTABLE_SLOTS 83

static const AvnGuid I_AVN_NUMERIC_UP_DOWN_IID = {
    0xC486FD9B,
    0x9743,
    0x5403,
    { 0xA4, 0x35, 0x3A, 0xBC, 0x83, 0x32, 0x0F, 0x98 }
};
#define I_AVN_NUMERIC_UP_DOWN_ABI_VERSION 4
struct IAvnNumericUpDownVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnNumericUpDown* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnNumericUpDown* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnNumericUpDown* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnNumericUpDown* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnNumericUpDown* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnNumericUpDown* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnNumericUpDown* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnNumericUpDown* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnNumericUpDown* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnNumericUpDown* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnNumericUpDown* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnNumericUpDown* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnNumericUpDown* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnNumericUpDown* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnNumericUpDown* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnNumericUpDown* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnNumericUpDown* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnNumericUpDown* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnNumericUpDown* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnNumericUpDown* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnNumericUpDown* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnNumericUpDown* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnNumericUpDown* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnNumericUpDown* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnNumericUpDown* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnNumericUpDown* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnNumericUpDown* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnNumericUpDown* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnNumericUpDown* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnNumericUpDown* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnNumericUpDown* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnNumericUpDown* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnNumericUpDown* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnNumericUpDown* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnNumericUpDown* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnNumericUpDown* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnNumericUpDown* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnNumericUpDown* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnNumericUpDown* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnNumericUpDown* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnNumericUpDown* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnNumericUpDown* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnNumericUpDown* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnNumericUpDown* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnNumericUpDown* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnNumericUpDown* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnNumericUpDown* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnNumericUpDown* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnNumericUpDown* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnNumericUpDown* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnNumericUpDown* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnNumericUpDown* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnNumericUpDown* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnNumericUpDown* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnNumericUpDown* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnNumericUpDown* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnNumericUpDown* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnNumericUpDown* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnNumericUpDown* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnNumericUpDown* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnNumericUpDown* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnNumericUpDown* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnNumericUpDown* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnNumericUpDown* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnNumericUpDown* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnNumericUpDown* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnNumericUpDown* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnNumericUpDown* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnNumericUpDown* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnNumericUpDown* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnNumericUpDown* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_allow_spin)(IAvnNumericUpDown* self, int32_t* value); /* slot 71 */
    AvnHResult (AVN_CALL *set_allow_spin)(IAvnNumericUpDown* self, int32_t value); /* slot 72 */
    AvnHResult (AVN_CALL *get_button_spinner_location)(IAvnNumericUpDown* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_button_spinner_location)(IAvnNumericUpDown* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_show_button_spinner)(IAvnNumericUpDown* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_show_button_spinner)(IAvnNumericUpDown* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_clip_value_to_min_max)(IAvnNumericUpDown* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_clip_value_to_min_max)(IAvnNumericUpDown* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_format_string)(IAvnNumericUpDown* self, uint16_t** value); /* slot 79 */
    AvnHResult (AVN_CALL *set_format_string)(IAvnNumericUpDown* self, const uint16_t* value); /* slot 80 */
    AvnHResult (AVN_CALL *get_increment)(IAvnNumericUpDown* self, uint16_t** value); /* slot 81 */
    AvnHResult (AVN_CALL *set_increment)(IAvnNumericUpDown* self, const uint16_t* value); /* slot 82 */
    AvnHResult (AVN_CALL *get_is_read_only)(IAvnNumericUpDown* self, int32_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_is_read_only)(IAvnNumericUpDown* self, int32_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_maximum)(IAvnNumericUpDown* self, uint16_t** value); /* slot 85 */
    AvnHResult (AVN_CALL *set_maximum)(IAvnNumericUpDown* self, const uint16_t* value); /* slot 86 */
    AvnHResult (AVN_CALL *get_minimum)(IAvnNumericUpDown* self, uint16_t** value); /* slot 87 */
    AvnHResult (AVN_CALL *set_minimum)(IAvnNumericUpDown* self, const uint16_t* value); /* slot 88 */
    AvnHResult (AVN_CALL *get_text)(IAvnNumericUpDown* self, uint16_t** value); /* slot 89 */
    AvnHResult (AVN_CALL *set_text)(IAvnNumericUpDown* self, const uint16_t* value); /* slot 90 */
    AvnHResult (AVN_CALL *get_value)(IAvnNumericUpDown* self, uint16_t** value); /* slot 91 */
    AvnHResult (AVN_CALL *set_value)(IAvnNumericUpDown* self, const uint16_t* value); /* slot 92 */
    AvnHResult (AVN_CALL *get_placeholder_text)(IAvnNumericUpDown* self, uint16_t** value); /* slot 93 */
    AvnHResult (AVN_CALL *set_placeholder_text)(IAvnNumericUpDown* self, const uint16_t* value); /* slot 94 */
    AvnHResult (AVN_CALL *get_placeholder_foreground)(IAvnNumericUpDown* self, IAvnBrush** value); /* slot 95 */
    AvnHResult (AVN_CALL *set_placeholder_foreground)(IAvnNumericUpDown* self, IAvnBrush* value); /* slot 96 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnNumericUpDown* self, int32_t* value); /* slot 97 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnNumericUpDown* self, int32_t value); /* slot 98 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnNumericUpDown* self, int32_t* value); /* slot 99 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnNumericUpDown* self, int32_t value); /* slot 100 */
    AvnHResult (AVN_CALL *get_text_alignment)(IAvnNumericUpDown* self, int32_t* value); /* slot 101 */
    AvnHResult (AVN_CALL *set_text_alignment)(IAvnNumericUpDown* self, int32_t value); /* slot 102 */
    AvnHResult (AVN_CALL *get_inner_left_content)(IAvnNumericUpDown* self, IAvnControl** value); /* slot 103 */
    AvnHResult (AVN_CALL *set_inner_left_content)(IAvnNumericUpDown* self, IAvnControl* value); /* slot 104 */
    AvnHResult (AVN_CALL *get_inner_right_content)(IAvnNumericUpDown* self, IAvnControl** value); /* slot 105 */
    AvnHResult (AVN_CALL *set_inner_right_content)(IAvnNumericUpDown* self, IAvnControl* value); /* slot 106 */
    AvnHResult (AVN_CALL *advise_value_changed)(IAvnNumericUpDown* self, IAvnNumericUpDownValueChangedHandler* handler, int64_t* subscription_id); /* slot 107 */
    AvnHResult (AVN_CALL *unadvise_value_changed)(IAvnNumericUpDown* self, int64_t subscription_id); /* slot 108 */
};
struct IAvnNumericUpDown { const IAvnNumericUpDownVtbl* vtbl; };
#define I_AVN_NUMERIC_UP_DOWN_VTABLE_SLOTS 109

static const AvnGuid I_AVN_PANEL_IID = {
    0xA66DB44C,
    0x3C52,
    0x5E8F,
    { 0x8D, 0x94, 0x8C, 0x6C, 0x32, 0x2E, 0x74, 0x4B }
};
#define I_AVN_PANEL_ABI_VERSION 5
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnPanel* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnPanel* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnPanel* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnPanel* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnPanel* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnPanel* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnPanel* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnPanel* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnPanel* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnPanel* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnPanel* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnPanel* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnPanel* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnPanel* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnPanel* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnPanel* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnPanel* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnPanel* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnPanel* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnPanel* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnPanel* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnPanel* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnPanel* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnPanel* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnPanel* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnPanel* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnPanel* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnPanel* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnPanel* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnPanel* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnPanel* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnPanel* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnPanel* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnPanel* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnPanel* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_children)(IAvnPanel* self, IAvnControlList** value); /* slot 47 */
    AvnHResult (AVN_CALL *get_background)(IAvnPanel* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_background)(IAvnPanel* self, IAvnBrush* value); /* slot 49 */
};
struct IAvnPanel { const IAvnPanelVtbl* vtbl; };
#define I_AVN_PANEL_VTABLE_SLOTS 50

static const AvnGuid I_AVN_PATH_IID = {
    0xA5DCC730,
    0x496B,
    0x5891,
    { 0x96, 0xAD, 0x16, 0xD2, 0xA0, 0x9C, 0xD1, 0x55 }
};
#define I_AVN_PATH_ABI_VERSION 2
struct IAvnPathVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnPath* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnPath* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnPath* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnPath* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnPath* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnPath* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnPath* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnPath* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnPath* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnPath* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnPath* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnPath* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnPath* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnPath* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnPath* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnPath* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnPath* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnPath* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnPath* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnPath* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnPath* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnPath* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnPath* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnPath* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnPath* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnPath* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnPath* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnPath* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnPath* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnPath* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnPath* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnPath* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnPath* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnPath* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnPath* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnPath* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnPath* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnPath* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnPath* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnPath* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnPath* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnPath* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnPath* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnPath* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnPath* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnPath* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnPath* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_fill)(IAvnPath* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_fill)(IAvnPath* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_stretch)(IAvnPath* self, int32_t* value); /* slot 49 */
    AvnHResult (AVN_CALL *set_stretch)(IAvnPath* self, int32_t value); /* slot 50 */
    AvnHResult (AVN_CALL *get_stroke)(IAvnPath* self, IAvnBrush** value); /* slot 51 */
    AvnHResult (AVN_CALL *set_stroke)(IAvnPath* self, IAvnBrush* value); /* slot 52 */
    AvnHResult (AVN_CALL *get_stroke_dash_offset)(IAvnPath* self, double* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_stroke_dash_offset)(IAvnPath* self, double value); /* slot 54 */
    AvnHResult (AVN_CALL *get_stroke_thickness)(IAvnPath* self, double* value); /* slot 55 */
    AvnHResult (AVN_CALL *set_stroke_thickness)(IAvnPath* self, double value); /* slot 56 */
    AvnHResult (AVN_CALL *get_stroke_line_cap)(IAvnPath* self, int32_t* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_stroke_line_cap)(IAvnPath* self, int32_t value); /* slot 58 */
    AvnHResult (AVN_CALL *get_stroke_join)(IAvnPath* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_stroke_join)(IAvnPath* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_stroke_miter_limit)(IAvnPath* self, double* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_stroke_miter_limit)(IAvnPath* self, double value); /* slot 62 */
    AvnHResult (AVN_CALL *get_data)(IAvnPath* self, uint16_t** value); /* slot 63 */
    AvnHResult (AVN_CALL *set_data)(IAvnPath* self, const uint16_t* value); /* slot 64 */
};
struct IAvnPath { const IAvnPathVtbl* vtbl; };
#define I_AVN_PATH_VTABLE_SLOTS 65

static const AvnGuid I_AVN_PATH_ICON_IID = {
    0x5969C5F1,
    0xE409,
    0x5B18,
    { 0x9F, 0xE7, 0x9E, 0x71, 0x98, 0x71, 0x8B, 0x7A }
};
#define I_AVN_PATH_ICON_ABI_VERSION 3
struct IAvnPathIconVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnPathIcon* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnPathIcon* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnPathIcon* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnPathIcon* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnPathIcon* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnPathIcon* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnPathIcon* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnPathIcon* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnPathIcon* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnPathIcon* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnPathIcon* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnPathIcon* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnPathIcon* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnPathIcon* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnPathIcon* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnPathIcon* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnPathIcon* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnPathIcon* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnPathIcon* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnPathIcon* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnPathIcon* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnPathIcon* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnPathIcon* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnPathIcon* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnPathIcon* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnPathIcon* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnPathIcon* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnPathIcon* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnPathIcon* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnPathIcon* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnPathIcon* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnPathIcon* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnPathIcon* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnPathIcon* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnPathIcon* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnPathIcon* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnPathIcon* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnPathIcon* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnPathIcon* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnPathIcon* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnPathIcon* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnPathIcon* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnPathIcon* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnPathIcon* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnPathIcon* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnPathIcon* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnPathIcon* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnPathIcon* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnPathIcon* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnPathIcon* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnPathIcon* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnPathIcon* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnPathIcon* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnPathIcon* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnPathIcon* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnPathIcon* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnPathIcon* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnPathIcon* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnPathIcon* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnPathIcon* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnPathIcon* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnPathIcon* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnPathIcon* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnPathIcon* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnPathIcon* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnPathIcon* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnPathIcon* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnPathIcon* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnPathIcon* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnPathIcon* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnPathIcon* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_data)(IAvnPathIcon* self, uint16_t** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_data)(IAvnPathIcon* self, const uint16_t* value); /* slot 72 */
};
struct IAvnPathIcon { const IAvnPathIconVtbl* vtbl; };
#define I_AVN_PATH_ICON_VTABLE_SLOTS 73

static const AvnGuid I_AVN_PIPS_PAGER_IID = {
    0x2D66F914,
    0xFCAA,
    0x5FBD,
    { 0xAD, 0x94, 0xA5, 0x47, 0x17, 0xFF, 0xB3, 0xB8 }
};
#define I_AVN_PIPS_PAGER_ABI_VERSION 4
struct IAvnPipsPagerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnPipsPager* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnPipsPager* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnPipsPager* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnPipsPager* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnPipsPager* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnPipsPager* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnPipsPager* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnPipsPager* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnPipsPager* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnPipsPager* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnPipsPager* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnPipsPager* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnPipsPager* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnPipsPager* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnPipsPager* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnPipsPager* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnPipsPager* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnPipsPager* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnPipsPager* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnPipsPager* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnPipsPager* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnPipsPager* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnPipsPager* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnPipsPager* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnPipsPager* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnPipsPager* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnPipsPager* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnPipsPager* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnPipsPager* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnPipsPager* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnPipsPager* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnPipsPager* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnPipsPager* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnPipsPager* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnPipsPager* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnPipsPager* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnPipsPager* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnPipsPager* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnPipsPager* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnPipsPager* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnPipsPager* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnPipsPager* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnPipsPager* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnPipsPager* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnPipsPager* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnPipsPager* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnPipsPager* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnPipsPager* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnPipsPager* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnPipsPager* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnPipsPager* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnPipsPager* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnPipsPager* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnPipsPager* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnPipsPager* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnPipsPager* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnPipsPager* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnPipsPager* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnPipsPager* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnPipsPager* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnPipsPager* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnPipsPager* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnPipsPager* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnPipsPager* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnPipsPager* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnPipsPager* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnPipsPager* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnPipsPager* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnPipsPager* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnPipsPager* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnPipsPager* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_max_visible_pips)(IAvnPipsPager* self, int32_t* value); /* slot 71 */
    AvnHResult (AVN_CALL *set_max_visible_pips)(IAvnPipsPager* self, int32_t value); /* slot 72 */
    AvnHResult (AVN_CALL *get_is_next_button_visible)(IAvnPipsPager* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_is_next_button_visible)(IAvnPipsPager* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_number_of_pages)(IAvnPipsPager* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_number_of_pages)(IAvnPipsPager* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_orientation)(IAvnPipsPager* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_orientation)(IAvnPipsPager* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_is_previous_button_visible)(IAvnPipsPager* self, int32_t* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_is_previous_button_visible)(IAvnPipsPager* self, int32_t value); /* slot 80 */
    AvnHResult (AVN_CALL *get_selected_page_index)(IAvnPipsPager* self, int32_t* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_selected_page_index)(IAvnPipsPager* self, int32_t value); /* slot 82 */
    AvnHResult (AVN_CALL *advise_selected_index_changed)(IAvnPipsPager* self, IAvnPipsPagerSelectedIndexChangedHandler* handler, int64_t* subscription_id); /* slot 83 */
    AvnHResult (AVN_CALL *unadvise_selected_index_changed)(IAvnPipsPager* self, int64_t subscription_id); /* slot 84 */
};
struct IAvnPipsPager { const IAvnPipsPagerVtbl* vtbl; };
#define I_AVN_PIPS_PAGER_VTABLE_SLOTS 85

static const AvnGuid I_AVN_POLYGON_IID = {
    0xE6DD016D,
    0x26F8,
    0x560B,
    { 0x95, 0xB6, 0x1A, 0x68, 0x23, 0x92, 0xBC, 0x09 }
};
#define I_AVN_POLYGON_ABI_VERSION 2
struct IAvnPolygonVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnPolygon* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnPolygon* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnPolygon* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnPolygon* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnPolygon* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnPolygon* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnPolygon* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnPolygon* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnPolygon* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnPolygon* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnPolygon* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnPolygon* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnPolygon* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnPolygon* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnPolygon* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnPolygon* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnPolygon* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnPolygon* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnPolygon* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnPolygon* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnPolygon* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnPolygon* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnPolygon* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnPolygon* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnPolygon* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnPolygon* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnPolygon* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnPolygon* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnPolygon* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnPolygon* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnPolygon* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnPolygon* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnPolygon* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnPolygon* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnPolygon* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnPolygon* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnPolygon* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnPolygon* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnPolygon* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnPolygon* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnPolygon* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnPolygon* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnPolygon* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnPolygon* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnPolygon* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnPolygon* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnPolygon* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_fill)(IAvnPolygon* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_fill)(IAvnPolygon* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_stretch)(IAvnPolygon* self, int32_t* value); /* slot 49 */
    AvnHResult (AVN_CALL *set_stretch)(IAvnPolygon* self, int32_t value); /* slot 50 */
    AvnHResult (AVN_CALL *get_stroke)(IAvnPolygon* self, IAvnBrush** value); /* slot 51 */
    AvnHResult (AVN_CALL *set_stroke)(IAvnPolygon* self, IAvnBrush* value); /* slot 52 */
    AvnHResult (AVN_CALL *get_stroke_dash_offset)(IAvnPolygon* self, double* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_stroke_dash_offset)(IAvnPolygon* self, double value); /* slot 54 */
    AvnHResult (AVN_CALL *get_stroke_thickness)(IAvnPolygon* self, double* value); /* slot 55 */
    AvnHResult (AVN_CALL *set_stroke_thickness)(IAvnPolygon* self, double value); /* slot 56 */
    AvnHResult (AVN_CALL *get_stroke_line_cap)(IAvnPolygon* self, int32_t* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_stroke_line_cap)(IAvnPolygon* self, int32_t value); /* slot 58 */
    AvnHResult (AVN_CALL *get_stroke_join)(IAvnPolygon* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_stroke_join)(IAvnPolygon* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_stroke_miter_limit)(IAvnPolygon* self, double* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_stroke_miter_limit)(IAvnPolygon* self, double value); /* slot 62 */
    AvnHResult (AVN_CALL *get_fill_rule)(IAvnPolygon* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_fill_rule)(IAvnPolygon* self, int32_t value); /* slot 64 */
};
struct IAvnPolygon { const IAvnPolygonVtbl* vtbl; };
#define I_AVN_POLYGON_VTABLE_SLOTS 65

static const AvnGuid I_AVN_POLYLINE_IID = {
    0x893D539F,
    0x6493,
    0x5532,
    { 0xBD, 0x16, 0x35, 0x74, 0x00, 0xEE, 0xD8, 0x0B }
};
#define I_AVN_POLYLINE_ABI_VERSION 2
struct IAvnPolylineVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnPolyline* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnPolyline* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnPolyline* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnPolyline* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnPolyline* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnPolyline* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnPolyline* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnPolyline* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnPolyline* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnPolyline* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnPolyline* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnPolyline* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnPolyline* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnPolyline* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnPolyline* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnPolyline* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnPolyline* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnPolyline* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnPolyline* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnPolyline* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnPolyline* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnPolyline* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnPolyline* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnPolyline* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnPolyline* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnPolyline* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnPolyline* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnPolyline* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnPolyline* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnPolyline* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnPolyline* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnPolyline* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnPolyline* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnPolyline* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnPolyline* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnPolyline* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnPolyline* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnPolyline* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnPolyline* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnPolyline* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnPolyline* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnPolyline* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnPolyline* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnPolyline* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnPolyline* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnPolyline* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnPolyline* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_fill)(IAvnPolyline* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_fill)(IAvnPolyline* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_stretch)(IAvnPolyline* self, int32_t* value); /* slot 49 */
    AvnHResult (AVN_CALL *set_stretch)(IAvnPolyline* self, int32_t value); /* slot 50 */
    AvnHResult (AVN_CALL *get_stroke)(IAvnPolyline* self, IAvnBrush** value); /* slot 51 */
    AvnHResult (AVN_CALL *set_stroke)(IAvnPolyline* self, IAvnBrush* value); /* slot 52 */
    AvnHResult (AVN_CALL *get_stroke_dash_offset)(IAvnPolyline* self, double* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_stroke_dash_offset)(IAvnPolyline* self, double value); /* slot 54 */
    AvnHResult (AVN_CALL *get_stroke_thickness)(IAvnPolyline* self, double* value); /* slot 55 */
    AvnHResult (AVN_CALL *set_stroke_thickness)(IAvnPolyline* self, double value); /* slot 56 */
    AvnHResult (AVN_CALL *get_stroke_line_cap)(IAvnPolyline* self, int32_t* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_stroke_line_cap)(IAvnPolyline* self, int32_t value); /* slot 58 */
    AvnHResult (AVN_CALL *get_stroke_join)(IAvnPolyline* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_stroke_join)(IAvnPolyline* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_stroke_miter_limit)(IAvnPolyline* self, double* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_stroke_miter_limit)(IAvnPolyline* self, double value); /* slot 62 */
    AvnHResult (AVN_CALL *get_fill_rule)(IAvnPolyline* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_fill_rule)(IAvnPolyline* self, int32_t value); /* slot 64 */
};
struct IAvnPolyline { const IAvnPolylineVtbl* vtbl; };
#define I_AVN_POLYLINE_VTABLE_SLOTS 65

static const AvnGuid I_AVN_POPUP_IID = {
    0x20F9B7E4,
    0x9C5A,
    0x5ABA,
    { 0xAA, 0xD9, 0x40, 0xF2, 0x3A, 0xCE, 0x1D, 0x6E }
};
#define I_AVN_POPUP_ABI_VERSION 5
struct IAvnPopupVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnPopup* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnPopup* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnPopup* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnPopup* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnPopup* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnPopup* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnPopup* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnPopup* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnPopup* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnPopup* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnPopup* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnPopup* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnPopup* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnPopup* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnPopup* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnPopup* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnPopup* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnPopup* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnPopup* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnPopup* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnPopup* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnPopup* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnPopup* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnPopup* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnPopup* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnPopup* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnPopup* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnPopup* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnPopup* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnPopup* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnPopup* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnPopup* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnPopup* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnPopup* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnPopup* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnPopup* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnPopup* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnPopup* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnPopup* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnPopup* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnPopup* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnPopup* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnPopup* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnPopup* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnPopup* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnPopup* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnPopup* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_window_manager_add_shadow_hint)(IAvnPopup* self, int32_t* value); /* slot 47 */
    AvnHResult (AVN_CALL *set_window_manager_add_shadow_hint)(IAvnPopup* self, int32_t value); /* slot 48 */
    AvnHResult (AVN_CALL *get_child)(IAvnPopup* self, IAvnControl** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_child)(IAvnPopup* self, IAvnControl* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_inherits_transform)(IAvnPopup* self, int32_t* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_inherits_transform)(IAvnPopup* self, int32_t value); /* slot 52 */
    AvnHResult (AVN_CALL *get_is_light_dismiss_enabled)(IAvnPopup* self, int32_t* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_is_light_dismiss_enabled)(IAvnPopup* self, int32_t value); /* slot 54 */
    AvnHResult (AVN_CALL *get_is_open)(IAvnPopup* self, int32_t* value); /* slot 55 */
    AvnHResult (AVN_CALL *set_is_open)(IAvnPopup* self, int32_t value); /* slot 56 */
    AvnHResult (AVN_CALL *get_placement_anchor)(IAvnPopup* self, int32_t* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_placement_anchor)(IAvnPopup* self, int32_t value); /* slot 58 */
    AvnHResult (AVN_CALL *get_placement_constraint_adjustment)(IAvnPopup* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_placement_constraint_adjustment)(IAvnPopup* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_placement_gravity)(IAvnPopup* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_placement_gravity)(IAvnPopup* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_placement)(IAvnPopup* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_placement)(IAvnPopup* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_placement_rect)(IAvnPopup* self, AvnOptionalRect* value); /* slot 65 */
    AvnHResult (AVN_CALL *set_placement_rect)(IAvnPopup* self, AvnOptionalRect value); /* slot 66 */
    AvnHResult (AVN_CALL *get_placement_target)(IAvnPopup* self, IAvnControl** value); /* slot 67 */
    AvnHResult (AVN_CALL *set_placement_target)(IAvnPopup* self, IAvnControl* value); /* slot 68 */
    AvnHResult (AVN_CALL *get_overlay_dismiss_event_pass_through)(IAvnPopup* self, int32_t* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_overlay_dismiss_event_pass_through)(IAvnPopup* self, int32_t value); /* slot 70 */
    AvnHResult (AVN_CALL *get_horizontal_offset)(IAvnPopup* self, double* value); /* slot 71 */
    AvnHResult (AVN_CALL *set_horizontal_offset)(IAvnPopup* self, double value); /* slot 72 */
    AvnHResult (AVN_CALL *get_vertical_offset)(IAvnPopup* self, double* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_vertical_offset)(IAvnPopup* self, double value); /* slot 74 */
    AvnHResult (AVN_CALL *get_topmost)(IAvnPopup* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_topmost)(IAvnPopup* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_takes_focus_from_native_control)(IAvnPopup* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_takes_focus_from_native_control)(IAvnPopup* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_should_use_overlay_layer)(IAvnPopup* self, int32_t* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_should_use_overlay_layer)(IAvnPopup* self, int32_t value); /* slot 80 */
    AvnHResult (AVN_CALL *get_is_using_overlay_layer)(IAvnPopup* self, int32_t* value); /* slot 81 */
    AvnHResult (AVN_CALL *get_is_pointer_over_popup)(IAvnPopup* self, int32_t* value); /* slot 82 */
    AvnHResult (AVN_CALL *open)(IAvnPopup* self); /* slot 83 */
    AvnHResult (AVN_CALL *close)(IAvnPopup* self); /* slot 84 */
    AvnHResult (AVN_CALL *advise_closed)(IAvnPopup* self, IAvnPopupClosedHandler* handler, int64_t* subscription_id); /* slot 85 */
    AvnHResult (AVN_CALL *unadvise_closed)(IAvnPopup* self, int64_t subscription_id); /* slot 86 */
    AvnHResult (AVN_CALL *advise_opened)(IAvnPopup* self, IAvnPopupOpenedHandler* handler, int64_t* subscription_id); /* slot 87 */
    AvnHResult (AVN_CALL *unadvise_opened)(IAvnPopup* self, int64_t subscription_id); /* slot 88 */
};
struct IAvnPopup { const IAvnPopupVtbl* vtbl; };
#define I_AVN_POPUP_VTABLE_SLOTS 89

static const AvnGuid I_AVN_POPUP_FLYOUT_BASE_IID = {
    0x8E367D08,
    0x0CD3,
    0x55F1,
    { 0xAF, 0x3E, 0x52, 0x76, 0x4E, 0xE0, 0xFD, 0x1D }
};
#define I_AVN_POPUP_FLYOUT_BASE_ABI_VERSION 3
struct IAvnPopupFlyoutBaseVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnPopupFlyoutBase* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnPopupFlyoutBase* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnPopupFlyoutBase* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnPopupFlyoutBase* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnPopupFlyoutBase* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_is_open)(IAvnPopupFlyoutBase* self, int32_t* value); /* slot 5 */
    AvnHResult (AVN_CALL *set_is_open)(IAvnPopupFlyoutBase* self, int32_t value); /* slot 6 */
    AvnHResult (AVN_CALL *get_target)(IAvnPopupFlyoutBase* self, IAvnControl** value); /* slot 7 */
    AvnHResult (AVN_CALL *show_at_with_control)(IAvnPopupFlyoutBase* self, IAvnControl* placement_target); /* slot 8 */
    AvnHResult (AVN_CALL *hide)(IAvnPopupFlyoutBase* self); /* slot 9 */
    AvnHResult (AVN_CALL *advise_opened)(IAvnPopupFlyoutBase* self, IAvnFlyoutBaseOpenedHandler* handler, int64_t* subscription_id); /* slot 10 */
    AvnHResult (AVN_CALL *unadvise_opened)(IAvnPopupFlyoutBase* self, int64_t subscription_id); /* slot 11 */
    AvnHResult (AVN_CALL *advise_closed)(IAvnPopupFlyoutBase* self, IAvnFlyoutBaseClosedHandler* handler, int64_t* subscription_id); /* slot 12 */
    AvnHResult (AVN_CALL *unadvise_closed)(IAvnPopupFlyoutBase* self, int64_t subscription_id); /* slot 13 */
    AvnHResult (AVN_CALL *get_popup)(IAvnPopupFlyoutBase* self, IAvnPopup** value); /* slot 14 */
    AvnHResult (AVN_CALL *get_placement)(IAvnPopupFlyoutBase* self, int32_t* value); /* slot 15 */
    AvnHResult (AVN_CALL *set_placement)(IAvnPopupFlyoutBase* self, int32_t value); /* slot 16 */
    AvnHResult (AVN_CALL *get_placement_gravity)(IAvnPopupFlyoutBase* self, int32_t* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_placement_gravity)(IAvnPopupFlyoutBase* self, int32_t value); /* slot 18 */
    AvnHResult (AVN_CALL *get_placement_anchor)(IAvnPopupFlyoutBase* self, int32_t* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_placement_anchor)(IAvnPopupFlyoutBase* self, int32_t value); /* slot 20 */
    AvnHResult (AVN_CALL *get_horizontal_offset)(IAvnPopupFlyoutBase* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_horizontal_offset)(IAvnPopupFlyoutBase* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_vertical_offset)(IAvnPopupFlyoutBase* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_vertical_offset)(IAvnPopupFlyoutBase* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_show_mode)(IAvnPopupFlyoutBase* self, int32_t* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_show_mode)(IAvnPopupFlyoutBase* self, int32_t value); /* slot 26 */
    AvnHResult (AVN_CALL *get_overlay_dismiss_event_pass_through)(IAvnPopupFlyoutBase* self, int32_t* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_overlay_dismiss_event_pass_through)(IAvnPopupFlyoutBase* self, int32_t value); /* slot 28 */
    AvnHResult (AVN_CALL *get_placement_constraint_adjustment)(IAvnPopupFlyoutBase* self, int32_t* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_placement_constraint_adjustment)(IAvnPopupFlyoutBase* self, int32_t value); /* slot 30 */
    AvnHResult (AVN_CALL *advise_closing)(IAvnPopupFlyoutBase* self, IAvnPopupFlyoutBaseClosingHandler* handler, int64_t* subscription_id); /* slot 31 */
    AvnHResult (AVN_CALL *unadvise_closing)(IAvnPopupFlyoutBase* self, int64_t subscription_id); /* slot 32 */
    AvnHResult (AVN_CALL *advise_opening)(IAvnPopupFlyoutBase* self, IAvnPopupFlyoutBaseOpeningHandler* handler, int64_t* subscription_id); /* slot 33 */
    AvnHResult (AVN_CALL *unadvise_opening)(IAvnPopupFlyoutBase* self, int64_t subscription_id); /* slot 34 */
};
struct IAvnPopupFlyoutBase { const IAvnPopupFlyoutBaseVtbl* vtbl; };
#define I_AVN_POPUP_FLYOUT_BASE_VTABLE_SLOTS 35

static const AvnGuid I_AVN_PROGRESS_BAR_IID = {
    0x229693D2,
    0x326A,
    0x5415,
    { 0xA8, 0xD5, 0x3E, 0x13, 0x44, 0xF3, 0x31, 0x48 }
};
#define I_AVN_PROGRESS_BAR_ABI_VERSION 7
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnProgressBar* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnProgressBar* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnProgressBar* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnProgressBar* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnProgressBar* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnProgressBar* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnProgressBar* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnProgressBar* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnProgressBar* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnProgressBar* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnProgressBar* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnProgressBar* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnProgressBar* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnProgressBar* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnProgressBar* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnProgressBar* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnProgressBar* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnProgressBar* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnProgressBar* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnProgressBar* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnProgressBar* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnProgressBar* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnProgressBar* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnProgressBar* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnProgressBar* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnProgressBar* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnProgressBar* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnProgressBar* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnProgressBar* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnProgressBar* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnProgressBar* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnProgressBar* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnProgressBar* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnProgressBar* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnProgressBar* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnProgressBar* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnProgressBar* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnProgressBar* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnProgressBar* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnProgressBar* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnProgressBar* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnProgressBar* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnProgressBar* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnProgressBar* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnProgressBar* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnProgressBar* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnProgressBar* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnProgressBar* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnProgressBar* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnProgressBar* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnProgressBar* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnProgressBar* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnProgressBar* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnProgressBar* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnProgressBar* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnProgressBar* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnProgressBar* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnProgressBar* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnProgressBar* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_minimum)(IAvnProgressBar* self, double* value); /* slot 71 */
    AvnHResult (AVN_CALL *set_minimum)(IAvnProgressBar* self, double value); /* slot 72 */
    AvnHResult (AVN_CALL *get_maximum)(IAvnProgressBar* self, double* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_maximum)(IAvnProgressBar* self, double value); /* slot 74 */
    AvnHResult (AVN_CALL *get_value)(IAvnProgressBar* self, double* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_value)(IAvnProgressBar* self, double value); /* slot 76 */
    AvnHResult (AVN_CALL *get_small_change)(IAvnProgressBar* self, double* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_small_change)(IAvnProgressBar* self, double value); /* slot 78 */
    AvnHResult (AVN_CALL *get_large_change)(IAvnProgressBar* self, double* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_large_change)(IAvnProgressBar* self, double value); /* slot 80 */
    AvnHResult (AVN_CALL *advise_value_changed)(IAvnProgressBar* self, IAvnRangeBaseValueChangedHandler* handler, int64_t* subscription_id); /* slot 81 */
    AvnHResult (AVN_CALL *unadvise_value_changed)(IAvnProgressBar* self, int64_t subscription_id); /* slot 82 */
    AvnHResult (AVN_CALL *get_percentage)(IAvnProgressBar* self, double* value); /* slot 83 */
    AvnHResult (AVN_CALL *get_is_indeterminate)(IAvnProgressBar* self, int32_t* value); /* slot 84 */
    AvnHResult (AVN_CALL *set_is_indeterminate)(IAvnProgressBar* self, int32_t value); /* slot 85 */
    AvnHResult (AVN_CALL *get_show_progress_text)(IAvnProgressBar* self, int32_t* value); /* slot 86 */
    AvnHResult (AVN_CALL *set_show_progress_text)(IAvnProgressBar* self, int32_t value); /* slot 87 */
    AvnHResult (AVN_CALL *get_progress_text_format)(IAvnProgressBar* self, uint16_t** value); /* slot 88 */
    AvnHResult (AVN_CALL *set_progress_text_format)(IAvnProgressBar* self, const uint16_t* value); /* slot 89 */
    AvnHResult (AVN_CALL *get_orientation)(IAvnProgressBar* self, int32_t* value); /* slot 90 */
    AvnHResult (AVN_CALL *set_orientation)(IAvnProgressBar* self, int32_t value); /* slot 91 */
};
struct IAvnProgressBar { const IAvnProgressBarVtbl* vtbl; };
#define I_AVN_PROGRESS_BAR_VTABLE_SLOTS 92

static const AvnGuid I_AVN_RADIO_BUTTON_IID = {
    0x19E5AD81,
    0xC085,
    0x5DA3,
    { 0xAD, 0x05, 0xEA, 0x74, 0xBD, 0xA6, 0xB5, 0x60 }
};
#define I_AVN_RADIO_BUTTON_ABI_VERSION 10
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnRadioButton* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnRadioButton* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnRadioButton* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnRadioButton* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnRadioButton* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnRadioButton* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnRadioButton* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnRadioButton* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnRadioButton* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnRadioButton* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnRadioButton* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnRadioButton* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnRadioButton* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnRadioButton* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnRadioButton* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnRadioButton* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnRadioButton* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnRadioButton* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnRadioButton* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnRadioButton* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnRadioButton* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnRadioButton* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnRadioButton* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnRadioButton* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnRadioButton* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnRadioButton* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnRadioButton* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnRadioButton* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnRadioButton* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnRadioButton* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnRadioButton* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnRadioButton* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnRadioButton* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnRadioButton* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnRadioButton* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnRadioButton* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnRadioButton* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnRadioButton* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnRadioButton* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnRadioButton* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnRadioButton* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnRadioButton* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnRadioButton* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnRadioButton* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnRadioButton* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnRadioButton* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnRadioButton* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnRadioButton* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnRadioButton* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnRadioButton* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnRadioButton* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnRadioButton* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnRadioButton* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnRadioButton* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnRadioButton* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnRadioButton* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnRadioButton* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnRadioButton* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnRadioButton* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnRadioButton* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnRadioButton* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnRadioButton* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnRadioButton* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnRadioButton* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnRadioButton* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_click_mode)(IAvnRadioButton* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_click_mode)(IAvnRadioButton* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_command)(IAvnRadioButton* self, IAvnCommand** value); /* slot 79 */
    AvnHResult (AVN_CALL *set_command)(IAvnRadioButton* self, IAvnCommand* value); /* slot 80 */
    AvnHResult (AVN_CALL *get_command_parameter)(IAvnRadioButton* self, AvnVariant* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_command_parameter)(IAvnRadioButton* self, AvnVariant value); /* slot 82 */
    AvnHResult (AVN_CALL *get_is_default)(IAvnRadioButton* self, int32_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_is_default)(IAvnRadioButton* self, int32_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_is_cancel)(IAvnRadioButton* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_is_cancel)(IAvnRadioButton* self, int32_t value); /* slot 86 */
    AvnHResult (AVN_CALL *get_is_pressed)(IAvnRadioButton* self, int32_t* value); /* slot 87 */
    AvnHResult (AVN_CALL *get_flyout)(IAvnRadioButton* self, IAvnFlyoutBase** value); /* slot 88 */
    AvnHResult (AVN_CALL *set_flyout)(IAvnRadioButton* self, IAvnFlyoutBase* value); /* slot 89 */
    AvnHResult (AVN_CALL *advise_click)(IAvnRadioButton* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 90 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnRadioButton* self, int64_t subscription_id); /* slot 91 */
    AvnHResult (AVN_CALL *get_is_checked)(IAvnRadioButton* self, int32_t* value); /* slot 92 */
    AvnHResult (AVN_CALL *set_is_checked)(IAvnRadioButton* self, int32_t value); /* slot 93 */
    AvnHResult (AVN_CALL *get_is_three_state)(IAvnRadioButton* self, int32_t* value); /* slot 94 */
    AvnHResult (AVN_CALL *set_is_three_state)(IAvnRadioButton* self, int32_t value); /* slot 95 */
    AvnHResult (AVN_CALL *advise_is_checked_changed)(IAvnRadioButton* self, IAvnToggleButtonIsCheckedChangedHandler* handler, int64_t* subscription_id); /* slot 96 */
    AvnHResult (AVN_CALL *unadvise_is_checked_changed)(IAvnRadioButton* self, int64_t subscription_id); /* slot 97 */
    AvnHResult (AVN_CALL *get_group_name)(IAvnRadioButton* self, uint16_t** value); /* slot 98 */
    AvnHResult (AVN_CALL *set_group_name)(IAvnRadioButton* self, const uint16_t* value); /* slot 99 */
};
struct IAvnRadioButton { const IAvnRadioButtonVtbl* vtbl; };
#define I_AVN_RADIO_BUTTON_VTABLE_SLOTS 100

static const AvnGuid I_AVN_RANGE_BASE_IID = {
    0x697D205C,
    0xBCD7,
    0x5235,
    { 0xA2, 0xA7, 0x0D, 0x9E, 0xF5, 0xC0, 0xF9, 0xD5 }
};
#define I_AVN_RANGE_BASE_ABI_VERSION 6
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnRangeBase* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnRangeBase* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnRangeBase* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnRangeBase* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnRangeBase* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnRangeBase* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnRangeBase* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnRangeBase* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnRangeBase* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnRangeBase* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnRangeBase* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnRangeBase* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnRangeBase* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnRangeBase* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnRangeBase* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnRangeBase* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnRangeBase* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnRangeBase* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnRangeBase* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnRangeBase* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnRangeBase* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnRangeBase* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnRangeBase* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnRangeBase* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnRangeBase* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnRangeBase* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnRangeBase* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnRangeBase* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnRangeBase* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnRangeBase* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnRangeBase* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnRangeBase* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnRangeBase* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnRangeBase* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnRangeBase* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnRangeBase* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnRangeBase* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnRangeBase* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnRangeBase* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnRangeBase* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnRangeBase* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnRangeBase* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnRangeBase* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnRangeBase* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnRangeBase* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnRangeBase* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnRangeBase* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnRangeBase* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnRangeBase* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnRangeBase* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnRangeBase* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnRangeBase* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnRangeBase* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnRangeBase* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnRangeBase* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnRangeBase* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnRangeBase* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnRangeBase* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnRangeBase* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_minimum)(IAvnRangeBase* self, double* value); /* slot 71 */
    AvnHResult (AVN_CALL *set_minimum)(IAvnRangeBase* self, double value); /* slot 72 */
    AvnHResult (AVN_CALL *get_maximum)(IAvnRangeBase* self, double* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_maximum)(IAvnRangeBase* self, double value); /* slot 74 */
    AvnHResult (AVN_CALL *get_value)(IAvnRangeBase* self, double* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_value)(IAvnRangeBase* self, double value); /* slot 76 */
    AvnHResult (AVN_CALL *get_small_change)(IAvnRangeBase* self, double* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_small_change)(IAvnRangeBase* self, double value); /* slot 78 */
    AvnHResult (AVN_CALL *get_large_change)(IAvnRangeBase* self, double* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_large_change)(IAvnRangeBase* self, double value); /* slot 80 */
    AvnHResult (AVN_CALL *advise_value_changed)(IAvnRangeBase* self, IAvnRangeBaseValueChangedHandler* handler, int64_t* subscription_id); /* slot 81 */
    AvnHResult (AVN_CALL *unadvise_value_changed)(IAvnRangeBase* self, int64_t subscription_id); /* slot 82 */
};
struct IAvnRangeBase { const IAvnRangeBaseVtbl* vtbl; };
#define I_AVN_RANGE_BASE_VTABLE_SLOTS 83

static const AvnGuid I_AVN_RECTANGLE_IID = {
    0x0B13A220,
    0xDEE0,
    0x53FC,
    { 0xA7, 0xB3, 0x2F, 0x6E, 0xD6, 0x3E, 0x10, 0x2F }
};
#define I_AVN_RECTANGLE_ABI_VERSION 2
struct IAvnRectangleVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnRectangle* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnRectangle* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnRectangle* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnRectangle* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnRectangle* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnRectangle* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnRectangle* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnRectangle* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnRectangle* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnRectangle* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnRectangle* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnRectangle* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnRectangle* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnRectangle* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnRectangle* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnRectangle* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnRectangle* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnRectangle* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnRectangle* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnRectangle* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnRectangle* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnRectangle* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnRectangle* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnRectangle* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnRectangle* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnRectangle* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnRectangle* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnRectangle* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnRectangle* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnRectangle* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnRectangle* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnRectangle* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnRectangle* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnRectangle* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnRectangle* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnRectangle* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnRectangle* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnRectangle* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnRectangle* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnRectangle* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnRectangle* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnRectangle* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnRectangle* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnRectangle* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnRectangle* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnRectangle* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnRectangle* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_fill)(IAvnRectangle* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_fill)(IAvnRectangle* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_stretch)(IAvnRectangle* self, int32_t* value); /* slot 49 */
    AvnHResult (AVN_CALL *set_stretch)(IAvnRectangle* self, int32_t value); /* slot 50 */
    AvnHResult (AVN_CALL *get_stroke)(IAvnRectangle* self, IAvnBrush** value); /* slot 51 */
    AvnHResult (AVN_CALL *set_stroke)(IAvnRectangle* self, IAvnBrush* value); /* slot 52 */
    AvnHResult (AVN_CALL *get_stroke_dash_offset)(IAvnRectangle* self, double* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_stroke_dash_offset)(IAvnRectangle* self, double value); /* slot 54 */
    AvnHResult (AVN_CALL *get_stroke_thickness)(IAvnRectangle* self, double* value); /* slot 55 */
    AvnHResult (AVN_CALL *set_stroke_thickness)(IAvnRectangle* self, double value); /* slot 56 */
    AvnHResult (AVN_CALL *get_stroke_line_cap)(IAvnRectangle* self, int32_t* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_stroke_line_cap)(IAvnRectangle* self, int32_t value); /* slot 58 */
    AvnHResult (AVN_CALL *get_stroke_join)(IAvnRectangle* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_stroke_join)(IAvnRectangle* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_stroke_miter_limit)(IAvnRectangle* self, double* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_stroke_miter_limit)(IAvnRectangle* self, double value); /* slot 62 */
    AvnHResult (AVN_CALL *get_radius_x)(IAvnRectangle* self, double* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_radius_x)(IAvnRectangle* self, double value); /* slot 64 */
    AvnHResult (AVN_CALL *get_radius_y)(IAvnRectangle* self, double* value); /* slot 65 */
    AvnHResult (AVN_CALL *set_radius_y)(IAvnRectangle* self, double value); /* slot 66 */
};
struct IAvnRectangle { const IAvnRectangleVtbl* vtbl; };
#define I_AVN_RECTANGLE_VTABLE_SLOTS 67

static const AvnGuid I_AVN_REFRESH_CONTAINER_IID = {
    0xE61AE098,
    0x3BFC,
    0x5128,
    { 0xBD, 0x03, 0xFA, 0xCD, 0x48, 0xA1, 0xB0, 0x85 }
};
#define I_AVN_REFRESH_CONTAINER_ABI_VERSION 4
struct IAvnRefreshContainerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnRefreshContainer* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnRefreshContainer* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnRefreshContainer* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnRefreshContainer* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnRefreshContainer* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnRefreshContainer* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnRefreshContainer* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnRefreshContainer* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnRefreshContainer* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnRefreshContainer* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnRefreshContainer* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnRefreshContainer* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnRefreshContainer* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnRefreshContainer* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnRefreshContainer* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnRefreshContainer* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnRefreshContainer* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnRefreshContainer* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnRefreshContainer* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnRefreshContainer* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnRefreshContainer* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnRefreshContainer* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnRefreshContainer* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnRefreshContainer* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnRefreshContainer* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnRefreshContainer* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnRefreshContainer* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnRefreshContainer* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnRefreshContainer* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnRefreshContainer* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnRefreshContainer* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnRefreshContainer* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnRefreshContainer* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnRefreshContainer* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnRefreshContainer* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnRefreshContainer* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnRefreshContainer* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnRefreshContainer* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnRefreshContainer* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnRefreshContainer* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnRefreshContainer* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnRefreshContainer* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnRefreshContainer* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnRefreshContainer* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnRefreshContainer* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnRefreshContainer* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnRefreshContainer* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnRefreshContainer* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnRefreshContainer* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnRefreshContainer* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnRefreshContainer* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnRefreshContainer* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnRefreshContainer* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnRefreshContainer* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnRefreshContainer* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnRefreshContainer* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnRefreshContainer* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnRefreshContainer* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnRefreshContainer* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnRefreshContainer* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnRefreshContainer* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnRefreshContainer* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnRefreshContainer* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnRefreshContainer* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnRefreshContainer* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnRefreshContainer* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnRefreshContainer* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnRefreshContainer* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnRefreshContainer* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnRefreshContainer* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnRefreshContainer* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnRefreshContainer* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnRefreshContainer* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnRefreshContainer* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnRefreshContainer* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnRefreshContainer* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnRefreshContainer* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_is_mouse_enabled)(IAvnRefreshContainer* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_is_mouse_enabled)(IAvnRefreshContainer* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_pull_direction)(IAvnRefreshContainer* self, int32_t* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_pull_direction)(IAvnRefreshContainer* self, int32_t value); /* slot 80 */
    AvnHResult (AVN_CALL *request_refresh)(IAvnRefreshContainer* self); /* slot 81 */
};
struct IAvnRefreshContainer { const IAvnRefreshContainerVtbl* vtbl; };
#define I_AVN_REFRESH_CONTAINER_VTABLE_SLOTS 82

static const AvnGuid I_AVN_RELATIVE_PANEL_IID = {
    0x49879823,
    0x0BD7,
    0x5F66,
    { 0xA3, 0x83, 0xD9, 0x5A, 0x6D, 0xE5, 0x71, 0xFC }
};
#define I_AVN_RELATIVE_PANEL_ABI_VERSION 2
struct IAvnRelativePanelVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnRelativePanel* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnRelativePanel* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnRelativePanel* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnRelativePanel* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnRelativePanel* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnRelativePanel* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnRelativePanel* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnRelativePanel* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnRelativePanel* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnRelativePanel* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnRelativePanel* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnRelativePanel* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnRelativePanel* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnRelativePanel* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnRelativePanel* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnRelativePanel* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnRelativePanel* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnRelativePanel* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnRelativePanel* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnRelativePanel* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnRelativePanel* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnRelativePanel* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnRelativePanel* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnRelativePanel* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnRelativePanel* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnRelativePanel* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnRelativePanel* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnRelativePanel* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnRelativePanel* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnRelativePanel* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnRelativePanel* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnRelativePanel* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnRelativePanel* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnRelativePanel* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnRelativePanel* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnRelativePanel* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnRelativePanel* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnRelativePanel* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnRelativePanel* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnRelativePanel* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnRelativePanel* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnRelativePanel* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnRelativePanel* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnRelativePanel* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnRelativePanel* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnRelativePanel* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnRelativePanel* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_children)(IAvnRelativePanel* self, IAvnControlList** value); /* slot 47 */
    AvnHResult (AVN_CALL *get_background)(IAvnRelativePanel* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_background)(IAvnRelativePanel* self, IAvnBrush* value); /* slot 49 */
};
struct IAvnRelativePanel { const IAvnRelativePanelVtbl* vtbl; };
#define I_AVN_RELATIVE_PANEL_VTABLE_SLOTS 50

static const AvnGuid I_AVN_REPEAT_BUTTON_IID = {
    0xCCB2A943,
    0x5B7E,
    0x5EF4,
    { 0xA6, 0x8D, 0xC3, 0x87, 0x61, 0x33, 0x75, 0x2A }
};
#define I_AVN_REPEAT_BUTTON_ABI_VERSION 5
struct IAvnRepeatButtonVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnRepeatButton* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnRepeatButton* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnRepeatButton* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnRepeatButton* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnRepeatButton* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnRepeatButton* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnRepeatButton* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnRepeatButton* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnRepeatButton* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnRepeatButton* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnRepeatButton* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnRepeatButton* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnRepeatButton* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnRepeatButton* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnRepeatButton* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnRepeatButton* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnRepeatButton* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnRepeatButton* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnRepeatButton* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnRepeatButton* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnRepeatButton* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnRepeatButton* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnRepeatButton* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnRepeatButton* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnRepeatButton* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnRepeatButton* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnRepeatButton* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnRepeatButton* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnRepeatButton* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnRepeatButton* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnRepeatButton* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnRepeatButton* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnRepeatButton* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnRepeatButton* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnRepeatButton* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnRepeatButton* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnRepeatButton* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnRepeatButton* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnRepeatButton* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnRepeatButton* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnRepeatButton* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnRepeatButton* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnRepeatButton* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnRepeatButton* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnRepeatButton* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnRepeatButton* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnRepeatButton* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnRepeatButton* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnRepeatButton* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnRepeatButton* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnRepeatButton* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnRepeatButton* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnRepeatButton* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnRepeatButton* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnRepeatButton* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnRepeatButton* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnRepeatButton* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnRepeatButton* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnRepeatButton* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnRepeatButton* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnRepeatButton* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnRepeatButton* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnRepeatButton* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnRepeatButton* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnRepeatButton* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnRepeatButton* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnRepeatButton* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnRepeatButton* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnRepeatButton* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnRepeatButton* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnRepeatButton* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnRepeatButton* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnRepeatButton* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnRepeatButton* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnRepeatButton* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnRepeatButton* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnRepeatButton* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_click_mode)(IAvnRepeatButton* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_click_mode)(IAvnRepeatButton* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_command)(IAvnRepeatButton* self, IAvnCommand** value); /* slot 79 */
    AvnHResult (AVN_CALL *set_command)(IAvnRepeatButton* self, IAvnCommand* value); /* slot 80 */
    AvnHResult (AVN_CALL *get_command_parameter)(IAvnRepeatButton* self, AvnVariant* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_command_parameter)(IAvnRepeatButton* self, AvnVariant value); /* slot 82 */
    AvnHResult (AVN_CALL *get_is_default)(IAvnRepeatButton* self, int32_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_is_default)(IAvnRepeatButton* self, int32_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_is_cancel)(IAvnRepeatButton* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_is_cancel)(IAvnRepeatButton* self, int32_t value); /* slot 86 */
    AvnHResult (AVN_CALL *get_is_pressed)(IAvnRepeatButton* self, int32_t* value); /* slot 87 */
    AvnHResult (AVN_CALL *get_flyout)(IAvnRepeatButton* self, IAvnFlyoutBase** value); /* slot 88 */
    AvnHResult (AVN_CALL *set_flyout)(IAvnRepeatButton* self, IAvnFlyoutBase* value); /* slot 89 */
    AvnHResult (AVN_CALL *advise_click)(IAvnRepeatButton* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 90 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnRepeatButton* self, int64_t subscription_id); /* slot 91 */
    AvnHResult (AVN_CALL *get_interval)(IAvnRepeatButton* self, int32_t* value); /* slot 92 */
    AvnHResult (AVN_CALL *set_interval)(IAvnRepeatButton* self, int32_t value); /* slot 93 */
    AvnHResult (AVN_CALL *get_delay)(IAvnRepeatButton* self, int32_t* value); /* slot 94 */
    AvnHResult (AVN_CALL *set_delay)(IAvnRepeatButton* self, int32_t value); /* slot 95 */
};
struct IAvnRepeatButton { const IAvnRepeatButtonVtbl* vtbl; };
#define I_AVN_REPEAT_BUTTON_VTABLE_SLOTS 96

static const AvnGuid I_AVN_SCROLL_VIEWER_IID = {
    0x8CB86977,
    0xE9B3,
    0x519F,
    { 0x91, 0xB7, 0x99, 0x80, 0x42, 0xC9, 0x98, 0x94 }
};
#define I_AVN_SCROLL_VIEWER_ABI_VERSION 9
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnScrollViewer* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnScrollViewer* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnScrollViewer* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnScrollViewer* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnScrollViewer* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnScrollViewer* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnScrollViewer* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnScrollViewer* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnScrollViewer* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnScrollViewer* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnScrollViewer* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnScrollViewer* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnScrollViewer* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnScrollViewer* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnScrollViewer* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnScrollViewer* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnScrollViewer* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnScrollViewer* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnScrollViewer* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnScrollViewer* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnScrollViewer* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnScrollViewer* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnScrollViewer* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnScrollViewer* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnScrollViewer* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnScrollViewer* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnScrollViewer* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnScrollViewer* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnScrollViewer* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnScrollViewer* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnScrollViewer* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnScrollViewer* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnScrollViewer* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnScrollViewer* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnScrollViewer* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnScrollViewer* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnScrollViewer* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnScrollViewer* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnScrollViewer* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnScrollViewer* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnScrollViewer* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnScrollViewer* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnScrollViewer* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnScrollViewer* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnScrollViewer* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnScrollViewer* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnScrollViewer* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnScrollViewer* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnScrollViewer* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnScrollViewer* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnScrollViewer* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnScrollViewer* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnScrollViewer* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnScrollViewer* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnScrollViewer* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnScrollViewer* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnScrollViewer* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnScrollViewer* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnScrollViewer* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnScrollViewer* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnScrollViewer* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnScrollViewer* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnScrollViewer* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnScrollViewer* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnScrollViewer* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_bring_into_view_on_focus_change)(IAvnScrollViewer* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_bring_into_view_on_focus_change)(IAvnScrollViewer* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_extent)(IAvnScrollViewer* self, AvnSize* value); /* slot 79 */
    AvnHResult (AVN_CALL *get_offset)(IAvnScrollViewer* self, AvnVector* value); /* slot 80 */
    AvnHResult (AVN_CALL *set_offset)(IAvnScrollViewer* self, AvnVector value); /* slot 81 */
    AvnHResult (AVN_CALL *get_viewport)(IAvnScrollViewer* self, AvnSize* value); /* slot 82 */
    AvnHResult (AVN_CALL *get_large_change)(IAvnScrollViewer* self, AvnSize* value); /* slot 83 */
    AvnHResult (AVN_CALL *get_small_change)(IAvnScrollViewer* self, AvnSize* value); /* slot 84 */
    AvnHResult (AVN_CALL *get_horizontal_scroll_bar_visibility)(IAvnScrollViewer* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_horizontal_scroll_bar_visibility)(IAvnScrollViewer* self, int32_t value); /* slot 86 */
    AvnHResult (AVN_CALL *get_vertical_scroll_bar_visibility)(IAvnScrollViewer* self, int32_t* value); /* slot 87 */
    AvnHResult (AVN_CALL *set_vertical_scroll_bar_visibility)(IAvnScrollViewer* self, int32_t value); /* slot 88 */
    AvnHResult (AVN_CALL *get_current_anchor)(IAvnScrollViewer* self, IAvnControl** value); /* slot 89 */
    AvnHResult (AVN_CALL *get_scroll_bar_maximum)(IAvnScrollViewer* self, AvnVector* value); /* slot 90 */
    AvnHResult (AVN_CALL *get_is_expanded)(IAvnScrollViewer* self, int32_t* value); /* slot 91 */
    AvnHResult (AVN_CALL *get_horizontal_snap_points_type)(IAvnScrollViewer* self, int32_t* value); /* slot 92 */
    AvnHResult (AVN_CALL *set_horizontal_snap_points_type)(IAvnScrollViewer* self, int32_t value); /* slot 93 */
    AvnHResult (AVN_CALL *get_vertical_snap_points_type)(IAvnScrollViewer* self, int32_t* value); /* slot 94 */
    AvnHResult (AVN_CALL *set_vertical_snap_points_type)(IAvnScrollViewer* self, int32_t value); /* slot 95 */
    AvnHResult (AVN_CALL *get_horizontal_snap_points_alignment)(IAvnScrollViewer* self, int32_t* value); /* slot 96 */
    AvnHResult (AVN_CALL *set_horizontal_snap_points_alignment)(IAvnScrollViewer* self, int32_t value); /* slot 97 */
    AvnHResult (AVN_CALL *get_vertical_snap_points_alignment)(IAvnScrollViewer* self, int32_t* value); /* slot 98 */
    AvnHResult (AVN_CALL *set_vertical_snap_points_alignment)(IAvnScrollViewer* self, int32_t value); /* slot 99 */
    AvnHResult (AVN_CALL *get_allow_auto_hide)(IAvnScrollViewer* self, int32_t* value); /* slot 100 */
    AvnHResult (AVN_CALL *set_allow_auto_hide)(IAvnScrollViewer* self, int32_t value); /* slot 101 */
    AvnHResult (AVN_CALL *get_is_scroll_chaining_enabled)(IAvnScrollViewer* self, int32_t* value); /* slot 102 */
    AvnHResult (AVN_CALL *set_is_scroll_chaining_enabled)(IAvnScrollViewer* self, int32_t value); /* slot 103 */
    AvnHResult (AVN_CALL *get_is_scroll_inertia_enabled)(IAvnScrollViewer* self, int32_t* value); /* slot 104 */
    AvnHResult (AVN_CALL *set_is_scroll_inertia_enabled)(IAvnScrollViewer* self, int32_t value); /* slot 105 */
    AvnHResult (AVN_CALL *get_is_deferred_scrolling_enabled)(IAvnScrollViewer* self, int32_t* value); /* slot 106 */
    AvnHResult (AVN_CALL *set_is_deferred_scrolling_enabled)(IAvnScrollViewer* self, int32_t value); /* slot 107 */
    AvnHResult (AVN_CALL *line_up)(IAvnScrollViewer* self); /* slot 108 */
    AvnHResult (AVN_CALL *line_down)(IAvnScrollViewer* self); /* slot 109 */
    AvnHResult (AVN_CALL *line_left)(IAvnScrollViewer* self); /* slot 110 */
    AvnHResult (AVN_CALL *line_right)(IAvnScrollViewer* self); /* slot 111 */
    AvnHResult (AVN_CALL *page_up)(IAvnScrollViewer* self); /* slot 112 */
    AvnHResult (AVN_CALL *page_down)(IAvnScrollViewer* self); /* slot 113 */
    AvnHResult (AVN_CALL *page_left)(IAvnScrollViewer* self); /* slot 114 */
    AvnHResult (AVN_CALL *page_right)(IAvnScrollViewer* self); /* slot 115 */
    AvnHResult (AVN_CALL *scroll_to_home)(IAvnScrollViewer* self); /* slot 116 */
    AvnHResult (AVN_CALL *scroll_to_end)(IAvnScrollViewer* self); /* slot 117 */
    AvnHResult (AVN_CALL *register_anchor_candidate_with_control)(IAvnScrollViewer* self, IAvnControl* element); /* slot 118 */
    AvnHResult (AVN_CALL *unregister_anchor_candidate_with_control)(IAvnScrollViewer* self, IAvnControl* element); /* slot 119 */
    AvnHResult (AVN_CALL *advise_scroll_changed)(IAvnScrollViewer* self, IAvnScrollViewerScrollChangedHandler* handler, int64_t* subscription_id); /* slot 120 */
    AvnHResult (AVN_CALL *unadvise_scroll_changed)(IAvnScrollViewer* self, int64_t subscription_id); /* slot 121 */
};
struct IAvnScrollViewer { const IAvnScrollViewerVtbl* vtbl; };
#define I_AVN_SCROLL_VIEWER_VTABLE_SLOTS 122

static const AvnGuid I_AVN_SECTOR_IID = {
    0xD0F311C0,
    0xA041,
    0x586B,
    { 0xB0, 0x7D, 0x25, 0x73, 0xD5, 0xEC, 0x93, 0x68 }
};
#define I_AVN_SECTOR_ABI_VERSION 2
struct IAvnSectorVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnSector* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnSector* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnSector* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnSector* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnSector* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnSector* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnSector* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnSector* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnSector* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnSector* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnSector* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnSector* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnSector* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnSector* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnSector* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnSector* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnSector* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnSector* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnSector* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnSector* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnSector* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnSector* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnSector* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnSector* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnSector* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnSector* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnSector* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnSector* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnSector* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnSector* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnSector* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnSector* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnSector* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnSector* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnSector* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnSector* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnSector* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnSector* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnSector* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnSector* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnSector* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnSector* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnSector* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnSector* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnSector* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnSector* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnSector* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_fill)(IAvnSector* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_fill)(IAvnSector* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_stretch)(IAvnSector* self, int32_t* value); /* slot 49 */
    AvnHResult (AVN_CALL *set_stretch)(IAvnSector* self, int32_t value); /* slot 50 */
    AvnHResult (AVN_CALL *get_stroke)(IAvnSector* self, IAvnBrush** value); /* slot 51 */
    AvnHResult (AVN_CALL *set_stroke)(IAvnSector* self, IAvnBrush* value); /* slot 52 */
    AvnHResult (AVN_CALL *get_stroke_dash_offset)(IAvnSector* self, double* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_stroke_dash_offset)(IAvnSector* self, double value); /* slot 54 */
    AvnHResult (AVN_CALL *get_stroke_thickness)(IAvnSector* self, double* value); /* slot 55 */
    AvnHResult (AVN_CALL *set_stroke_thickness)(IAvnSector* self, double value); /* slot 56 */
    AvnHResult (AVN_CALL *get_stroke_line_cap)(IAvnSector* self, int32_t* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_stroke_line_cap)(IAvnSector* self, int32_t value); /* slot 58 */
    AvnHResult (AVN_CALL *get_stroke_join)(IAvnSector* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_stroke_join)(IAvnSector* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_stroke_miter_limit)(IAvnSector* self, double* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_stroke_miter_limit)(IAvnSector* self, double value); /* slot 62 */
    AvnHResult (AVN_CALL *get_start_angle)(IAvnSector* self, double* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_start_angle)(IAvnSector* self, double value); /* slot 64 */
    AvnHResult (AVN_CALL *get_sweep_angle)(IAvnSector* self, double* value); /* slot 65 */
    AvnHResult (AVN_CALL *set_sweep_angle)(IAvnSector* self, double value); /* slot 66 */
};
struct IAvnSector { const IAvnSectorVtbl* vtbl; };
#define I_AVN_SECTOR_VTABLE_SLOTS 67

static const AvnGuid I_AVN_SELECTABLE_TEXT_BLOCK_IID = {
    0x64DADF29,
    0xB8E9,
    0x5B35,
    { 0x87, 0xF2, 0xD4, 0x92, 0x4D, 0xE7, 0xEC, 0x48 }
};
#define I_AVN_SELECTABLE_TEXT_BLOCK_ABI_VERSION 5
struct IAvnSelectableTextBlockVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnSelectableTextBlock* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnSelectableTextBlock* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnSelectableTextBlock* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnSelectableTextBlock* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnSelectableTextBlock* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnSelectableTextBlock* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnSelectableTextBlock* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnSelectableTextBlock* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnSelectableTextBlock* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnSelectableTextBlock* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnSelectableTextBlock* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnSelectableTextBlock* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnSelectableTextBlock* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnSelectableTextBlock* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnSelectableTextBlock* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnSelectableTextBlock* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnSelectableTextBlock* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnSelectableTextBlock* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnSelectableTextBlock* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnSelectableTextBlock* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnSelectableTextBlock* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnSelectableTextBlock* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnSelectableTextBlock* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnSelectableTextBlock* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnSelectableTextBlock* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnSelectableTextBlock* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnSelectableTextBlock* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnSelectableTextBlock* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnSelectableTextBlock* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnSelectableTextBlock* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnSelectableTextBlock* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnSelectableTextBlock* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnSelectableTextBlock* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnSelectableTextBlock* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnSelectableTextBlock* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnSelectableTextBlock* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnSelectableTextBlock* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnSelectableTextBlock* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnSelectableTextBlock* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnSelectableTextBlock* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnSelectableTextBlock* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnSelectableTextBlock* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnSelectableTextBlock* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnSelectableTextBlock* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnSelectableTextBlock* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnSelectableTextBlock* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnSelectableTextBlock* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_padding)(IAvnSelectableTextBlock* self, AvnThickness* value); /* slot 47 */
    AvnHResult (AVN_CALL *set_padding)(IAvnSelectableTextBlock* self, AvnThickness value); /* slot 48 */
    AvnHResult (AVN_CALL *get_background)(IAvnSelectableTextBlock* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_background)(IAvnSelectableTextBlock* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_text)(IAvnSelectableTextBlock* self, uint16_t** value); /* slot 51 */
    AvnHResult (AVN_CALL *set_text)(IAvnSelectableTextBlock* self, const uint16_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnSelectableTextBlock* self, uint16_t** value); /* slot 53 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnSelectableTextBlock* self, const uint16_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnSelectableTextBlock* self, double* value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnSelectableTextBlock* self, double value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnSelectableTextBlock* self, int32_t* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnSelectableTextBlock* self, int32_t value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnSelectableTextBlock* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnSelectableTextBlock* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnSelectableTextBlock* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnSelectableTextBlock* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnSelectableTextBlock* self, IAvnBrush** value); /* slot 63 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnSelectableTextBlock* self, IAvnBrush* value); /* slot 64 */
    AvnHResult (AVN_CALL *get_line_height)(IAvnSelectableTextBlock* self, double* value); /* slot 65 */
    AvnHResult (AVN_CALL *set_line_height)(IAvnSelectableTextBlock* self, double value); /* slot 66 */
    AvnHResult (AVN_CALL *get_line_spacing)(IAvnSelectableTextBlock* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_line_spacing)(IAvnSelectableTextBlock* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnSelectableTextBlock* self, double* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnSelectableTextBlock* self, double value); /* slot 70 */
    AvnHResult (AVN_CALL *get_max_lines)(IAvnSelectableTextBlock* self, int32_t* value); /* slot 71 */
    AvnHResult (AVN_CALL *set_max_lines)(IAvnSelectableTextBlock* self, int32_t value); /* slot 72 */
    AvnHResult (AVN_CALL *get_text_wrapping)(IAvnSelectableTextBlock* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_text_wrapping)(IAvnSelectableTextBlock* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_text_trimming)(IAvnSelectableTextBlock* self, uint16_t** value); /* slot 75 */
    AvnHResult (AVN_CALL *set_text_trimming)(IAvnSelectableTextBlock* self, const uint16_t* value); /* slot 76 */
    AvnHResult (AVN_CALL *get_text_alignment)(IAvnSelectableTextBlock* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_text_alignment)(IAvnSelectableTextBlock* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_baseline_offset)(IAvnSelectableTextBlock* self, double* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_baseline_offset)(IAvnSelectableTextBlock* self, double value); /* slot 80 */
    AvnHResult (AVN_CALL *get_selection_brush)(IAvnSelectableTextBlock* self, IAvnBrush** value); /* slot 81 */
    AvnHResult (AVN_CALL *set_selection_brush)(IAvnSelectableTextBlock* self, IAvnBrush* value); /* slot 82 */
    AvnHResult (AVN_CALL *get_selection_foreground_brush)(IAvnSelectableTextBlock* self, IAvnBrush** value); /* slot 83 */
    AvnHResult (AVN_CALL *set_selection_foreground_brush)(IAvnSelectableTextBlock* self, IAvnBrush* value); /* slot 84 */
    AvnHResult (AVN_CALL *get_selection_start)(IAvnSelectableTextBlock* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_selection_start)(IAvnSelectableTextBlock* self, int32_t value); /* slot 86 */
    AvnHResult (AVN_CALL *get_selection_end)(IAvnSelectableTextBlock* self, int32_t* value); /* slot 87 */
    AvnHResult (AVN_CALL *set_selection_end)(IAvnSelectableTextBlock* self, int32_t value); /* slot 88 */
    AvnHResult (AVN_CALL *get_selected_text)(IAvnSelectableTextBlock* self, uint16_t** value); /* slot 89 */
    AvnHResult (AVN_CALL *get_can_copy)(IAvnSelectableTextBlock* self, int32_t* value); /* slot 90 */
    AvnHResult (AVN_CALL *copy)(IAvnSelectableTextBlock* self); /* slot 91 */
    AvnHResult (AVN_CALL *select_all)(IAvnSelectableTextBlock* self); /* slot 92 */
    AvnHResult (AVN_CALL *clear_selection)(IAvnSelectableTextBlock* self); /* slot 93 */
    AvnHResult (AVN_CALL *advise_copying_to_clipboard)(IAvnSelectableTextBlock* self, IAvnSelectableTextBlockCopyingToClipboardHandler* handler, int64_t* subscription_id); /* slot 94 */
    AvnHResult (AVN_CALL *unadvise_copying_to_clipboard)(IAvnSelectableTextBlock* self, int64_t subscription_id); /* slot 95 */
};
struct IAvnSelectableTextBlock { const IAvnSelectableTextBlockVtbl* vtbl; };
#define I_AVN_SELECTABLE_TEXT_BLOCK_VTABLE_SLOTS 96

static const AvnGuid I_AVN_SELECTING_ITEMS_CONTROL_IID = {
    0x9E0E63B7,
    0x6A89,
    0x5073,
    { 0x8D, 0xC9, 0x1B, 0x5A, 0x43, 0x5E, 0x4F, 0x22 }
};
#define I_AVN_SELECTING_ITEMS_CONTROL_ABI_VERSION 7
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnSelectingItemsControl* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnSelectingItemsControl* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnSelectingItemsControl* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnSelectingItemsControl* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnSelectingItemsControl* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnSelectingItemsControl* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnSelectingItemsControl* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnSelectingItemsControl* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnSelectingItemsControl* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnSelectingItemsControl* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnSelectingItemsControl* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnSelectingItemsControl* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnSelectingItemsControl* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnSelectingItemsControl* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnSelectingItemsControl* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnSelectingItemsControl* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnSelectingItemsControl* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnSelectingItemsControl* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnSelectingItemsControl* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnSelectingItemsControl* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnSelectingItemsControl* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnSelectingItemsControl* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnSelectingItemsControl* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnSelectingItemsControl* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnSelectingItemsControl* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnSelectingItemsControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnSelectingItemsControl* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnSelectingItemsControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnSelectingItemsControl* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnSelectingItemsControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnSelectingItemsControl* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnSelectingItemsControl* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnSelectingItemsControl* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnSelectingItemsControl* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnSelectingItemsControl* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnSelectingItemsControl* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnSelectingItemsControl* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnSelectingItemsControl* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnSelectingItemsControl* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnSelectingItemsControl* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnSelectingItemsControl* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnSelectingItemsControl* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnSelectingItemsControl* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnSelectingItemsControl* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnSelectingItemsControl* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnSelectingItemsControl* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnSelectingItemsControl* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnSelectingItemsControl* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnSelectingItemsControl* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnSelectingItemsControl* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnSelectingItemsControl* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnSelectingItemsControl* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_items)(IAvnSelectingItemsControl* self, IAvnItemList** value); /* slot 71 */
    AvnHResult (AVN_CALL *get_item_count)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 72 */
    AvnHResult (AVN_CALL *scroll_into_view_with_int32)(IAvnSelectingItemsControl* self, int32_t index); /* slot 73 */
    AvnHResult (AVN_CALL *get_auto_scroll_to_selected_item)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 74 */
    AvnHResult (AVN_CALL *set_auto_scroll_to_selected_item)(IAvnSelectingItemsControl* self, int32_t value); /* slot 75 */
    AvnHResult (AVN_CALL *get_selected_index)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 76 */
    AvnHResult (AVN_CALL *set_selected_index)(IAvnSelectingItemsControl* self, int32_t value); /* slot 77 */
    AvnHResult (AVN_CALL *get_is_text_search_enabled)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 78 */
    AvnHResult (AVN_CALL *set_is_text_search_enabled)(IAvnSelectingItemsControl* self, int32_t value); /* slot 79 */
    AvnHResult (AVN_CALL *get_wrap_selection)(IAvnSelectingItemsControl* self, int32_t* value); /* slot 80 */
    AvnHResult (AVN_CALL *set_wrap_selection)(IAvnSelectingItemsControl* self, int32_t value); /* slot 81 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnSelectingItemsControl* self, IAvnSelectingItemsControlSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 82 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnSelectingItemsControl* self, int64_t subscription_id); /* slot 83 */
};
struct IAvnSelectingItemsControl { const IAvnSelectingItemsControlVtbl* vtbl; };
#define I_AVN_SELECTING_ITEMS_CONTROL_VTABLE_SLOTS 84

static const AvnGuid I_AVN_SEPARATOR_IID = {
    0xEA4F057C,
    0xA24E,
    0x5433,
    { 0x81, 0x47, 0x00, 0xC2, 0x5E, 0x65, 0xFB, 0xF1 }
};
#define I_AVN_SEPARATOR_ABI_VERSION 3
struct IAvnSeparatorVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnSeparator* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnSeparator* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnSeparator* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnSeparator* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnSeparator* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnSeparator* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnSeparator* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnSeparator* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnSeparator* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnSeparator* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnSeparator* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnSeparator* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnSeparator* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnSeparator* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnSeparator* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnSeparator* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnSeparator* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnSeparator* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnSeparator* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnSeparator* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnSeparator* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnSeparator* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnSeparator* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnSeparator* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnSeparator* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnSeparator* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnSeparator* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnSeparator* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnSeparator* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnSeparator* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnSeparator* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnSeparator* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnSeparator* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnSeparator* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnSeparator* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnSeparator* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnSeparator* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnSeparator* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnSeparator* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnSeparator* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnSeparator* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnSeparator* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnSeparator* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnSeparator* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnSeparator* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnSeparator* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnSeparator* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnSeparator* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnSeparator* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnSeparator* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnSeparator* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnSeparator* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnSeparator* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnSeparator* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnSeparator* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnSeparator* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnSeparator* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnSeparator* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnSeparator* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnSeparator* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnSeparator* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnSeparator* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnSeparator* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnSeparator* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnSeparator* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnSeparator* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnSeparator* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnSeparator* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnSeparator* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnSeparator* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnSeparator* self, AvnThickness value); /* slot 70 */
};
struct IAvnSeparator { const IAvnSeparatorVtbl* vtbl; };
#define I_AVN_SEPARATOR_VTABLE_SLOTS 71

static const AvnGuid I_AVN_SHAPE_IID = {
    0xD7B89215,
    0xFEEB,
    0x5459,
    { 0x83, 0x95, 0x7C, 0xCB, 0x1B, 0xF4, 0x8A, 0xB7 }
};
#define I_AVN_SHAPE_ABI_VERSION 2
struct IAvnShapeVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnShape* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnShape* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnShape* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnShape* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnShape* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnShape* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnShape* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnShape* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnShape* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnShape* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnShape* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnShape* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnShape* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnShape* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnShape* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnShape* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnShape* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnShape* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnShape* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnShape* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnShape* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnShape* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnShape* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnShape* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnShape* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnShape* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnShape* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnShape* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnShape* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnShape* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnShape* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnShape* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnShape* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnShape* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnShape* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnShape* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnShape* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnShape* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnShape* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnShape* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnShape* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnShape* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnShape* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnShape* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnShape* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnShape* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnShape* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_fill)(IAvnShape* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_fill)(IAvnShape* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_stretch)(IAvnShape* self, int32_t* value); /* slot 49 */
    AvnHResult (AVN_CALL *set_stretch)(IAvnShape* self, int32_t value); /* slot 50 */
    AvnHResult (AVN_CALL *get_stroke)(IAvnShape* self, IAvnBrush** value); /* slot 51 */
    AvnHResult (AVN_CALL *set_stroke)(IAvnShape* self, IAvnBrush* value); /* slot 52 */
    AvnHResult (AVN_CALL *get_stroke_dash_offset)(IAvnShape* self, double* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_stroke_dash_offset)(IAvnShape* self, double value); /* slot 54 */
    AvnHResult (AVN_CALL *get_stroke_thickness)(IAvnShape* self, double* value); /* slot 55 */
    AvnHResult (AVN_CALL *set_stroke_thickness)(IAvnShape* self, double value); /* slot 56 */
    AvnHResult (AVN_CALL *get_stroke_line_cap)(IAvnShape* self, int32_t* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_stroke_line_cap)(IAvnShape* self, int32_t value); /* slot 58 */
    AvnHResult (AVN_CALL *get_stroke_join)(IAvnShape* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_stroke_join)(IAvnShape* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_stroke_miter_limit)(IAvnShape* self, double* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_stroke_miter_limit)(IAvnShape* self, double value); /* slot 62 */
};
struct IAvnShape { const IAvnShapeVtbl* vtbl; };
#define I_AVN_SHAPE_VTABLE_SLOTS 63

static const AvnGuid I_AVN_SLIDER_IID = {
    0x4CF7FCE8,
    0xACE5,
    0x5CAD,
    { 0x94, 0xF6, 0xF4, 0x0F, 0xDA, 0x7A, 0xF1, 0x15 }
};
#define I_AVN_SLIDER_ABI_VERSION 6
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnSlider* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnSlider* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnSlider* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnSlider* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnSlider* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnSlider* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnSlider* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnSlider* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnSlider* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnSlider* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnSlider* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnSlider* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnSlider* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnSlider* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnSlider* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnSlider* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnSlider* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnSlider* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnSlider* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnSlider* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnSlider* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnSlider* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnSlider* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnSlider* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnSlider* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnSlider* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnSlider* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnSlider* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnSlider* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnSlider* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnSlider* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnSlider* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnSlider* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnSlider* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnSlider* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnSlider* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnSlider* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnSlider* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnSlider* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnSlider* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnSlider* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnSlider* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnSlider* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnSlider* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnSlider* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnSlider* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnSlider* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnSlider* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnSlider* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnSlider* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnSlider* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnSlider* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnSlider* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnSlider* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnSlider* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnSlider* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnSlider* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnSlider* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnSlider* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_minimum)(IAvnSlider* self, double* value); /* slot 71 */
    AvnHResult (AVN_CALL *set_minimum)(IAvnSlider* self, double value); /* slot 72 */
    AvnHResult (AVN_CALL *get_maximum)(IAvnSlider* self, double* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_maximum)(IAvnSlider* self, double value); /* slot 74 */
    AvnHResult (AVN_CALL *get_value)(IAvnSlider* self, double* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_value)(IAvnSlider* self, double value); /* slot 76 */
    AvnHResult (AVN_CALL *get_small_change)(IAvnSlider* self, double* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_small_change)(IAvnSlider* self, double value); /* slot 78 */
    AvnHResult (AVN_CALL *get_large_change)(IAvnSlider* self, double* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_large_change)(IAvnSlider* self, double value); /* slot 80 */
    AvnHResult (AVN_CALL *advise_value_changed)(IAvnSlider* self, IAvnRangeBaseValueChangedHandler* handler, int64_t* subscription_id); /* slot 81 */
    AvnHResult (AVN_CALL *unadvise_value_changed)(IAvnSlider* self, int64_t subscription_id); /* slot 82 */
    AvnHResult (AVN_CALL *get_orientation)(IAvnSlider* self, int32_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_orientation)(IAvnSlider* self, int32_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_is_direction_reversed)(IAvnSlider* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_is_direction_reversed)(IAvnSlider* self, int32_t value); /* slot 86 */
    AvnHResult (AVN_CALL *get_is_snap_to_tick_enabled)(IAvnSlider* self, int32_t* value); /* slot 87 */
    AvnHResult (AVN_CALL *set_is_snap_to_tick_enabled)(IAvnSlider* self, int32_t value); /* slot 88 */
    AvnHResult (AVN_CALL *get_tick_frequency)(IAvnSlider* self, double* value); /* slot 89 */
    AvnHResult (AVN_CALL *set_tick_frequency)(IAvnSlider* self, double value); /* slot 90 */
    AvnHResult (AVN_CALL *get_tick_placement)(IAvnSlider* self, int32_t* value); /* slot 91 */
    AvnHResult (AVN_CALL *set_tick_placement)(IAvnSlider* self, int32_t value); /* slot 92 */
};
struct IAvnSlider { const IAvnSliderVtbl* vtbl; };
#define I_AVN_SLIDER_VTABLE_SLOTS 93

static const AvnGuid I_AVN_SPINNER_IID = {
    0xD9C76469,
    0xBDB9,
    0x55DF,
    { 0x9B, 0xC4, 0x6E, 0xAF, 0xFA, 0xDD, 0x84, 0x34 }
};
#define I_AVN_SPINNER_ABI_VERSION 3
struct IAvnSpinnerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnSpinner* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnSpinner* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnSpinner* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnSpinner* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnSpinner* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnSpinner* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnSpinner* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnSpinner* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnSpinner* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnSpinner* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnSpinner* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnSpinner* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnSpinner* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnSpinner* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnSpinner* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnSpinner* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnSpinner* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnSpinner* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnSpinner* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnSpinner* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnSpinner* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnSpinner* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnSpinner* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnSpinner* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnSpinner* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnSpinner* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnSpinner* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnSpinner* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnSpinner* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnSpinner* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnSpinner* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnSpinner* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnSpinner* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnSpinner* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnSpinner* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnSpinner* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnSpinner* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnSpinner* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnSpinner* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnSpinner* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnSpinner* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnSpinner* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnSpinner* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnSpinner* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnSpinner* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnSpinner* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnSpinner* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnSpinner* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnSpinner* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnSpinner* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnSpinner* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnSpinner* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnSpinner* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnSpinner* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnSpinner* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnSpinner* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnSpinner* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnSpinner* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnSpinner* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnSpinner* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnSpinner* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnSpinner* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnSpinner* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnSpinner* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnSpinner* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnSpinner* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnSpinner* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnSpinner* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnSpinner* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnSpinner* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnSpinner* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnSpinner* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnSpinner* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnSpinner* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnSpinner* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnSpinner* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnSpinner* self, int32_t value); /* slot 76 */
};
struct IAvnSpinner { const IAvnSpinnerVtbl* vtbl; };
#define I_AVN_SPINNER_VTABLE_SLOTS 77

static const AvnGuid I_AVN_SPLIT_BUTTON_IID = {
    0xA7305BAD,
    0x060A,
    0x5178,
    { 0xAF, 0x34, 0x86, 0x88, 0xDB, 0x87, 0x5B, 0x31 }
};
#define I_AVN_SPLIT_BUTTON_ABI_VERSION 6
struct IAvnSplitButtonVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnSplitButton* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnSplitButton* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnSplitButton* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnSplitButton* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnSplitButton* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnSplitButton* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnSplitButton* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnSplitButton* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnSplitButton* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnSplitButton* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnSplitButton* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnSplitButton* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnSplitButton* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnSplitButton* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnSplitButton* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnSplitButton* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnSplitButton* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnSplitButton* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnSplitButton* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnSplitButton* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnSplitButton* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnSplitButton* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnSplitButton* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnSplitButton* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnSplitButton* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnSplitButton* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnSplitButton* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnSplitButton* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnSplitButton* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnSplitButton* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnSplitButton* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnSplitButton* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnSplitButton* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnSplitButton* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnSplitButton* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnSplitButton* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnSplitButton* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnSplitButton* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnSplitButton* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnSplitButton* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnSplitButton* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnSplitButton* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnSplitButton* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnSplitButton* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnSplitButton* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnSplitButton* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnSplitButton* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnSplitButton* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnSplitButton* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnSplitButton* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnSplitButton* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnSplitButton* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnSplitButton* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnSplitButton* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnSplitButton* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnSplitButton* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnSplitButton* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnSplitButton* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnSplitButton* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnSplitButton* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnSplitButton* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnSplitButton* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnSplitButton* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnSplitButton* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnSplitButton* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnSplitButton* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnSplitButton* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnSplitButton* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnSplitButton* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnSplitButton* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnSplitButton* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnSplitButton* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnSplitButton* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnSplitButton* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnSplitButton* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnSplitButton* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnSplitButton* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_command)(IAvnSplitButton* self, IAvnCommand** value); /* slot 77 */
    AvnHResult (AVN_CALL *set_command)(IAvnSplitButton* self, IAvnCommand* value); /* slot 78 */
    AvnHResult (AVN_CALL *get_command_parameter)(IAvnSplitButton* self, AvnVariant* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_command_parameter)(IAvnSplitButton* self, AvnVariant value); /* slot 80 */
    AvnHResult (AVN_CALL *get_flyout)(IAvnSplitButton* self, IAvnFlyoutBase** value); /* slot 81 */
    AvnHResult (AVN_CALL *set_flyout)(IAvnSplitButton* self, IAvnFlyoutBase* value); /* slot 82 */
    AvnHResult (AVN_CALL *advise_click)(IAvnSplitButton* self, IAvnSplitButtonClickHandler* handler, int64_t* subscription_id); /* slot 83 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnSplitButton* self, int64_t subscription_id); /* slot 84 */
};
struct IAvnSplitButton { const IAvnSplitButtonVtbl* vtbl; };
#define I_AVN_SPLIT_BUTTON_VTABLE_SLOTS 85

static const AvnGuid I_AVN_SPLIT_VIEW_IID = {
    0x0C9C08BE,
    0x9C25,
    0x5CAC,
    { 0xB3, 0xE8, 0xAA, 0x28, 0x3A, 0x43, 0x19, 0x19 }
};
#define I_AVN_SPLIT_VIEW_ABI_VERSION 3
struct IAvnSplitViewVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnSplitView* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnSplitView* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnSplitView* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnSplitView* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnSplitView* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnSplitView* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnSplitView* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnSplitView* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnSplitView* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnSplitView* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnSplitView* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnSplitView* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnSplitView* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnSplitView* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnSplitView* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnSplitView* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnSplitView* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnSplitView* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnSplitView* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnSplitView* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnSplitView* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnSplitView* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnSplitView* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnSplitView* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnSplitView* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnSplitView* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnSplitView* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnSplitView* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnSplitView* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnSplitView* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnSplitView* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnSplitView* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnSplitView* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnSplitView* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnSplitView* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnSplitView* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnSplitView* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnSplitView* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnSplitView* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnSplitView* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnSplitView* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnSplitView* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnSplitView* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnSplitView* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnSplitView* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnSplitView* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnSplitView* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnSplitView* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnSplitView* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnSplitView* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnSplitView* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnSplitView* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnSplitView* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnSplitView* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnSplitView* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnSplitView* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnSplitView* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnSplitView* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnSplitView* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnSplitView* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnSplitView* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnSplitView* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnSplitView* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnSplitView* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnSplitView* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnSplitView* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnSplitView* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnSplitView* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnSplitView* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnSplitView* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnSplitView* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnSplitView* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnSplitView* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnSplitView* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnSplitView* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnSplitView* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnSplitView* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_compact_pane_length)(IAvnSplitView* self, double* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_compact_pane_length)(IAvnSplitView* self, double value); /* slot 78 */
    AvnHResult (AVN_CALL *get_display_mode)(IAvnSplitView* self, int32_t* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_display_mode)(IAvnSplitView* self, int32_t value); /* slot 80 */
    AvnHResult (AVN_CALL *get_is_pane_open)(IAvnSplitView* self, int32_t* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_is_pane_open)(IAvnSplitView* self, int32_t value); /* slot 82 */
    AvnHResult (AVN_CALL *get_open_pane_length)(IAvnSplitView* self, double* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_open_pane_length)(IAvnSplitView* self, double value); /* slot 84 */
    AvnHResult (AVN_CALL *get_pane_background)(IAvnSplitView* self, IAvnBrush** value); /* slot 85 */
    AvnHResult (AVN_CALL *set_pane_background)(IAvnSplitView* self, IAvnBrush* value); /* slot 86 */
    AvnHResult (AVN_CALL *get_pane_placement)(IAvnSplitView* self, int32_t* value); /* slot 87 */
    AvnHResult (AVN_CALL *set_pane_placement)(IAvnSplitView* self, int32_t value); /* slot 88 */
    AvnHResult (AVN_CALL *get_pane)(IAvnSplitView* self, IAvnControl** value); /* slot 89 */
    AvnHResult (AVN_CALL *set_pane)(IAvnSplitView* self, IAvnControl* value); /* slot 90 */
    AvnHResult (AVN_CALL *get_use_light_dismiss_overlay_mode)(IAvnSplitView* self, int32_t* value); /* slot 91 */
    AvnHResult (AVN_CALL *set_use_light_dismiss_overlay_mode)(IAvnSplitView* self, int32_t value); /* slot 92 */
    AvnHResult (AVN_CALL *advise_pane_closed)(IAvnSplitView* self, IAvnSplitViewPaneClosedHandler* handler, int64_t* subscription_id); /* slot 93 */
    AvnHResult (AVN_CALL *unadvise_pane_closed)(IAvnSplitView* self, int64_t subscription_id); /* slot 94 */
    AvnHResult (AVN_CALL *advise_pane_opened)(IAvnSplitView* self, IAvnSplitViewPaneOpenedHandler* handler, int64_t* subscription_id); /* slot 95 */
    AvnHResult (AVN_CALL *unadvise_pane_opened)(IAvnSplitView* self, int64_t subscription_id); /* slot 96 */
};
struct IAvnSplitView { const IAvnSplitViewVtbl* vtbl; };
#define I_AVN_SPLIT_VIEW_VTABLE_SLOTS 97

static const AvnGuid I_AVN_STACK_PANEL_IID = {
    0xB9102549,
    0xF805,
    0x54B9,
    { 0x8A, 0x4E, 0x65, 0x49, 0x9B, 0xEE, 0x64, 0x37 }
};
#define I_AVN_STACK_PANEL_ABI_VERSION 6
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnStackPanel* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnStackPanel* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnStackPanel* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnStackPanel* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnStackPanel* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnStackPanel* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnStackPanel* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnStackPanel* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnStackPanel* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnStackPanel* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnStackPanel* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnStackPanel* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnStackPanel* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnStackPanel* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnStackPanel* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnStackPanel* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnStackPanel* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnStackPanel* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnStackPanel* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnStackPanel* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnStackPanel* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnStackPanel* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnStackPanel* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnStackPanel* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnStackPanel* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnStackPanel* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnStackPanel* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnStackPanel* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnStackPanel* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnStackPanel* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnStackPanel* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnStackPanel* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnStackPanel* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnStackPanel* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnStackPanel* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_children)(IAvnStackPanel* self, IAvnControlList** value); /* slot 47 */
    AvnHResult (AVN_CALL *get_background)(IAvnStackPanel* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_background)(IAvnStackPanel* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_spacing)(IAvnStackPanel* self, double* value); /* slot 50 */
    AvnHResult (AVN_CALL *set_spacing)(IAvnStackPanel* self, double value); /* slot 51 */
    AvnHResult (AVN_CALL *get_orientation)(IAvnStackPanel* self, int32_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_orientation)(IAvnStackPanel* self, int32_t value); /* slot 53 */
    AvnHResult (AVN_CALL *get_are_horizontal_snap_points_regular)(IAvnStackPanel* self, int32_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_are_horizontal_snap_points_regular)(IAvnStackPanel* self, int32_t value); /* slot 55 */
    AvnHResult (AVN_CALL *get_are_vertical_snap_points_regular)(IAvnStackPanel* self, int32_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *set_are_vertical_snap_points_regular)(IAvnStackPanel* self, int32_t value); /* slot 57 */
};
struct IAvnStackPanel { const IAvnStackPanelVtbl* vtbl; };
#define I_AVN_STACK_PANEL_VTABLE_SLOTS 58

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

static const AvnGuid I_AVN_TAB_CONTROL_IID = {
    0xB0C6EFAF,
    0x8F86,
    0x584A,
    { 0x8A, 0xF0, 0x06, 0x62, 0x97, 0x0B, 0x59, 0x7B }
};
#define I_AVN_TAB_CONTROL_ABI_VERSION 4
struct IAvnTabControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTabControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTabControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTabControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnTabControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnTabControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnTabControl* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnTabControl* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnTabControl* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnTabControl* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnTabControl* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnTabControl* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnTabControl* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnTabControl* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnTabControl* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnTabControl* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnTabControl* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnTabControl* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnTabControl* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnTabControl* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnTabControl* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnTabControl* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnTabControl* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnTabControl* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnTabControl* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnTabControl* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnTabControl* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnTabControl* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnTabControl* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnTabControl* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnTabControl* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnTabControl* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnTabControl* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnTabControl* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnTabControl* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnTabControl* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTabControl* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTabControl* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnTabControl* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnTabControl* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnTabControl* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnTabControl* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTabControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTabControl* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTabControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTabControl* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTabControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTabControl* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnTabControl* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnTabControl* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnTabControl* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnTabControl* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnTabControl* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnTabControl* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnTabControl* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnTabControl* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnTabControl* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnTabControl* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnTabControl* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnTabControl* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnTabControl* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnTabControl* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnTabControl* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnTabControl* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnTabControl* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnTabControl* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnTabControl* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnTabControl* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnTabControl* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnTabControl* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnTabControl* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnTabControl* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_items)(IAvnTabControl* self, IAvnItemList** value); /* slot 71 */
    AvnHResult (AVN_CALL *get_item_count)(IAvnTabControl* self, int32_t* value); /* slot 72 */
    AvnHResult (AVN_CALL *scroll_into_view_with_int32)(IAvnTabControl* self, int32_t index); /* slot 73 */
    AvnHResult (AVN_CALL *get_auto_scroll_to_selected_item)(IAvnTabControl* self, int32_t* value); /* slot 74 */
    AvnHResult (AVN_CALL *set_auto_scroll_to_selected_item)(IAvnTabControl* self, int32_t value); /* slot 75 */
    AvnHResult (AVN_CALL *get_selected_index)(IAvnTabControl* self, int32_t* value); /* slot 76 */
    AvnHResult (AVN_CALL *set_selected_index)(IAvnTabControl* self, int32_t value); /* slot 77 */
    AvnHResult (AVN_CALL *get_is_text_search_enabled)(IAvnTabControl* self, int32_t* value); /* slot 78 */
    AvnHResult (AVN_CALL *set_is_text_search_enabled)(IAvnTabControl* self, int32_t value); /* slot 79 */
    AvnHResult (AVN_CALL *get_wrap_selection)(IAvnTabControl* self, int32_t* value); /* slot 80 */
    AvnHResult (AVN_CALL *set_wrap_selection)(IAvnTabControl* self, int32_t value); /* slot 81 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnTabControl* self, IAvnSelectingItemsControlSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 82 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnTabControl* self, int64_t subscription_id); /* slot 83 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnTabControl* self, int32_t* value); /* slot 84 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnTabControl* self, int32_t value); /* slot 85 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnTabControl* self, int32_t* value); /* slot 86 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnTabControl* self, int32_t value); /* slot 87 */
    AvnHResult (AVN_CALL *get_tab_strip_placement)(IAvnTabControl* self, int32_t* value); /* slot 88 */
    AvnHResult (AVN_CALL *set_tab_strip_placement)(IAvnTabControl* self, int32_t value); /* slot 89 */
};
struct IAvnTabControl { const IAvnTabControlVtbl* vtbl; };
#define I_AVN_TAB_CONTROL_VTABLE_SLOTS 90

static const AvnGuid I_AVN_TAB_ITEM_IID = {
    0x1C7A24F7,
    0x5E14,
    0x5981,
    { 0x8E, 0xFF, 0x60, 0xAA, 0x50, 0xF7, 0xD7, 0xD4 }
};
#define I_AVN_TAB_ITEM_ABI_VERSION 3
struct IAvnTabItemVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTabItem* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTabItem* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTabItem* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnTabItem* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnTabItem* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnTabItem* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnTabItem* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnTabItem* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnTabItem* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnTabItem* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnTabItem* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnTabItem* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnTabItem* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnTabItem* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnTabItem* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnTabItem* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnTabItem* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnTabItem* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnTabItem* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnTabItem* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnTabItem* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnTabItem* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnTabItem* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnTabItem* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnTabItem* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnTabItem* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnTabItem* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnTabItem* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnTabItem* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnTabItem* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnTabItem* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnTabItem* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnTabItem* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnTabItem* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnTabItem* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTabItem* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTabItem* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnTabItem* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnTabItem* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnTabItem* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnTabItem* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTabItem* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTabItem* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTabItem* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTabItem* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTabItem* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTabItem* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnTabItem* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnTabItem* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnTabItem* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnTabItem* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnTabItem* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnTabItem* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnTabItem* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnTabItem* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnTabItem* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnTabItem* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnTabItem* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnTabItem* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnTabItem* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnTabItem* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnTabItem* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnTabItem* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnTabItem* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnTabItem* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnTabItem* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnTabItem* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnTabItem* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnTabItem* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnTabItem* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnTabItem* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnTabItem* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnTabItem* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnTabItem* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnTabItem* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnTabItem* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnTabItem* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_header)(IAvnTabItem* self, IAvnControl** value); /* slot 77 */
    AvnHResult (AVN_CALL *set_header)(IAvnTabItem* self, IAvnControl* value); /* slot 78 */
    AvnHResult (AVN_CALL *get_is_selected)(IAvnTabItem* self, int32_t* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_is_selected)(IAvnTabItem* self, int32_t value); /* slot 80 */
};
struct IAvnTabItem { const IAvnTabItemVtbl* vtbl; };
#define I_AVN_TAB_ITEM_VTABLE_SLOTS 81

static const AvnGuid I_AVN_TABLE_VIEW_IID = {
    0x4D0435C8,
    0xC782,
    0x5FDA,
    { 0x8C, 0xCB, 0x2C, 0xB8, 0x23, 0xA4, 0x3B, 0x7A }
};
#define I_AVN_TABLE_VIEW_ABI_VERSION 4
struct IAvnTableViewVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTableView* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTableView* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTableView* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnTableView* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnTableView* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnTableView* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnTableView* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnTableView* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnTableView* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnTableView* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnTableView* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnTableView* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnTableView* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnTableView* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnTableView* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnTableView* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnTableView* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnTableView* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnTableView* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnTableView* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnTableView* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnTableView* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnTableView* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnTableView* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnTableView* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnTableView* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnTableView* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnTableView* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnTableView* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnTableView* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnTableView* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnTableView* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnTableView* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnTableView* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnTableView* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTableView* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTableView* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnTableView* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnTableView* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnTableView* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnTableView* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTableView* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTableView* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTableView* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTableView* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTableView* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTableView* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnTableView* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnTableView* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnTableView* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnTableView* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnTableView* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnTableView* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnTableView* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnTableView* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnTableView* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnTableView* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnTableView* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnTableView* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnTableView* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnTableView* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnTableView* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnTableView* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnTableView* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnTableView* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnTableView* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnTableView* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnTableView* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnTableView* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnTableView* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnTableView* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_items)(IAvnTableView* self, IAvnItemList** value); /* slot 71 */
    AvnHResult (AVN_CALL *get_item_count)(IAvnTableView* self, int32_t* value); /* slot 72 */
    AvnHResult (AVN_CALL *scroll_into_view_with_int32)(IAvnTableView* self, int32_t index); /* slot 73 */
    AvnHResult (AVN_CALL *get_auto_scroll_to_selected_item)(IAvnTableView* self, int32_t* value); /* slot 74 */
    AvnHResult (AVN_CALL *set_auto_scroll_to_selected_item)(IAvnTableView* self, int32_t value); /* slot 75 */
    AvnHResult (AVN_CALL *get_selected_index)(IAvnTableView* self, int32_t* value); /* slot 76 */
    AvnHResult (AVN_CALL *set_selected_index)(IAvnTableView* self, int32_t value); /* slot 77 */
    AvnHResult (AVN_CALL *get_is_text_search_enabled)(IAvnTableView* self, int32_t* value); /* slot 78 */
    AvnHResult (AVN_CALL *set_is_text_search_enabled)(IAvnTableView* self, int32_t value); /* slot 79 */
    AvnHResult (AVN_CALL *get_wrap_selection)(IAvnTableView* self, int32_t* value); /* slot 80 */
    AvnHResult (AVN_CALL *set_wrap_selection)(IAvnTableView* self, int32_t value); /* slot 81 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnTableView* self, IAvnSelectingItemsControlSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 82 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnTableView* self, int64_t subscription_id); /* slot 83 */
    AvnHResult (AVN_CALL *get_selection_mode)(IAvnTableView* self, int32_t* value); /* slot 84 */
    AvnHResult (AVN_CALL *set_selection_mode)(IAvnTableView* self, int32_t value); /* slot 85 */
    AvnHResult (AVN_CALL *select_all)(IAvnTableView* self); /* slot 86 */
    AvnHResult (AVN_CALL *unselect_all)(IAvnTableView* self); /* slot 87 */
    AvnHResult (AVN_CALL *get_can_user_resize_columns)(IAvnTableView* self, int32_t* value); /* slot 88 */
    AvnHResult (AVN_CALL *set_can_user_resize_columns)(IAvnTableView* self, int32_t value); /* slot 89 */
};
struct IAvnTableView { const IAvnTableViewVtbl* vtbl; };
#define I_AVN_TABLE_VIEW_VTABLE_SLOTS 90

static const AvnGuid I_AVN_TABLE_VIEW_CELL_IID = {
    0xEF4B5794,
    0xDF8D,
    0x5F67,
    { 0x99, 0xF9, 0x2E, 0xDA, 0xBF, 0x1A, 0x32, 0xA7 }
};
#define I_AVN_TABLE_VIEW_CELL_ABI_VERSION 3
struct IAvnTableViewCellVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTableViewCell* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTableViewCell* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTableViewCell* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnTableViewCell* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnTableViewCell* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnTableViewCell* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnTableViewCell* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnTableViewCell* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnTableViewCell* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnTableViewCell* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnTableViewCell* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnTableViewCell* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnTableViewCell* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnTableViewCell* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnTableViewCell* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnTableViewCell* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnTableViewCell* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnTableViewCell* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnTableViewCell* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnTableViewCell* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnTableViewCell* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnTableViewCell* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnTableViewCell* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnTableViewCell* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnTableViewCell* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnTableViewCell* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnTableViewCell* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnTableViewCell* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnTableViewCell* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnTableViewCell* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnTableViewCell* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnTableViewCell* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnTableViewCell* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnTableViewCell* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnTableViewCell* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTableViewCell* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTableViewCell* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnTableViewCell* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnTableViewCell* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnTableViewCell* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnTableViewCell* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTableViewCell* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTableViewCell* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTableViewCell* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTableViewCell* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTableViewCell* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTableViewCell* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnTableViewCell* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnTableViewCell* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnTableViewCell* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnTableViewCell* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnTableViewCell* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnTableViewCell* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnTableViewCell* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnTableViewCell* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnTableViewCell* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnTableViewCell* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnTableViewCell* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnTableViewCell* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnTableViewCell* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnTableViewCell* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnTableViewCell* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnTableViewCell* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnTableViewCell* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnTableViewCell* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnTableViewCell* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnTableViewCell* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnTableViewCell* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnTableViewCell* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnTableViewCell* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnTableViewCell* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnTableViewCell* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnTableViewCell* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnTableViewCell* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnTableViewCell* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnTableViewCell* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnTableViewCell* self, int32_t value); /* slot 76 */
};
struct IAvnTableViewCell { const IAvnTableViewCellVtbl* vtbl; };
#define I_AVN_TABLE_VIEW_CELL_VTABLE_SLOTS 77

static const AvnGuid I_AVN_TABLE_VIEW_COLUMN_IID = {
    0xE17F1C8C,
    0xCEA3,
    0x51A4,
    { 0x8A, 0x06, 0xAD, 0x85, 0x99, 0xCD, 0xDA, 0x0D }
};
#define I_AVN_TABLE_VIEW_COLUMN_ABI_VERSION 2
struct IAvnTableViewColumnVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTableViewColumn* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTableViewColumn* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTableViewColumn* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnTableViewColumn* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnTableViewColumn* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnTableViewColumn* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnTableViewColumn* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnTableViewColumn* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_header)(IAvnTableViewColumn* self, IAvnControl** value); /* slot 8 */
    AvnHResult (AVN_CALL *set_header)(IAvnTableViewColumn* self, IAvnControl* value); /* slot 9 */
    AvnHResult (AVN_CALL *get_width)(IAvnTableViewColumn* self, uint16_t** value); /* slot 10 */
    AvnHResult (AVN_CALL *set_width)(IAvnTableViewColumn* self, const uint16_t* value); /* slot 11 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnTableViewColumn* self, double* value); /* slot 12 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnTableViewColumn* self, double value); /* slot 13 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnTableViewColumn* self, double* value); /* slot 14 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnTableViewColumn* self, double value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnTableViewColumn* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnTableViewColumn* self, int32_t value); /* slot 17 */
    AvnHResult (AVN_CALL *get_can_user_resize)(IAvnTableViewColumn* self, int32_t* value); /* slot 18 */
    AvnHResult (AVN_CALL *set_can_user_resize)(IAvnTableViewColumn* self, int32_t value); /* slot 19 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnTableViewColumn* self, int32_t* value); /* slot 20 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnTableViewColumn* self, int32_t value); /* slot 21 */
    AvnHResult (AVN_CALL *get_actual_width)(IAvnTableViewColumn* self, double* value); /* slot 22 */
    AvnHResult (AVN_CALL *get_can_user_effectively_resize)(IAvnTableViewColumn* self, int32_t* value); /* slot 23 */
};
struct IAvnTableViewColumn { const IAvnTableViewColumnVtbl* vtbl; };
#define I_AVN_TABLE_VIEW_COLUMN_VTABLE_SLOTS 24

static const AvnGuid I_AVN_TABLE_VIEW_ROW_IID = {
    0x77D8135A,
    0x51C5,
    0x5225,
    { 0x94, 0xF3, 0x94, 0x83, 0x9A, 0x67, 0x4B, 0xDE }
};
#define I_AVN_TABLE_VIEW_ROW_ABI_VERSION 3
struct IAvnTableViewRowVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTableViewRow* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTableViewRow* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTableViewRow* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnTableViewRow* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnTableViewRow* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnTableViewRow* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnTableViewRow* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnTableViewRow* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnTableViewRow* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnTableViewRow* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnTableViewRow* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnTableViewRow* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnTableViewRow* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnTableViewRow* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnTableViewRow* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnTableViewRow* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnTableViewRow* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnTableViewRow* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnTableViewRow* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnTableViewRow* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnTableViewRow* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnTableViewRow* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnTableViewRow* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnTableViewRow* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnTableViewRow* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnTableViewRow* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnTableViewRow* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnTableViewRow* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnTableViewRow* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnTableViewRow* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnTableViewRow* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnTableViewRow* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnTableViewRow* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnTableViewRow* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnTableViewRow* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTableViewRow* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTableViewRow* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnTableViewRow* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnTableViewRow* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnTableViewRow* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnTableViewRow* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTableViewRow* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTableViewRow* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTableViewRow* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTableViewRow* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTableViewRow* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTableViewRow* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnTableViewRow* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnTableViewRow* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnTableViewRow* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnTableViewRow* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnTableViewRow* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnTableViewRow* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnTableViewRow* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnTableViewRow* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnTableViewRow* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnTableViewRow* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnTableViewRow* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnTableViewRow* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnTableViewRow* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnTableViewRow* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnTableViewRow* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnTableViewRow* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnTableViewRow* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnTableViewRow* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnTableViewRow* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnTableViewRow* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnTableViewRow* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnTableViewRow* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnTableViewRow* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnTableViewRow* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnTableViewRow* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnTableViewRow* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnTableViewRow* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnTableViewRow* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnTableViewRow* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnTableViewRow* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_is_selected)(IAvnTableViewRow* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_is_selected)(IAvnTableViewRow* self, int32_t value); /* slot 78 */
};
struct IAvnTableViewRow { const IAvnTableViewRowVtbl* vtbl; };
#define I_AVN_TABLE_VIEW_ROW_VTABLE_SLOTS 79

static const AvnGuid I_AVN_TEMPLATED_CONTROL_IID = {
    0x1778CB20,
    0xC613,
    0x5979,
    { 0x86, 0xD6, 0xA2, 0x15, 0xF6, 0xB0, 0x5E, 0x2D }
};
#define I_AVN_TEMPLATED_CONTROL_ABI_VERSION 6
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnTemplatedControl* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnTemplatedControl* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnTemplatedControl* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnTemplatedControl* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnTemplatedControl* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnTemplatedControl* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnTemplatedControl* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnTemplatedControl* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnTemplatedControl* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnTemplatedControl* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnTemplatedControl* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnTemplatedControl* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnTemplatedControl* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnTemplatedControl* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnTemplatedControl* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnTemplatedControl* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnTemplatedControl* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnTemplatedControl* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnTemplatedControl* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnTemplatedControl* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnTemplatedControl* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnTemplatedControl* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnTemplatedControl* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTemplatedControl* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTemplatedControl* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnTemplatedControl* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnTemplatedControl* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnTemplatedControl* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnTemplatedControl* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTemplatedControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTemplatedControl* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTemplatedControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTemplatedControl* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTemplatedControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTemplatedControl* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnTemplatedControl* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnTemplatedControl* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnTemplatedControl* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnTemplatedControl* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnTemplatedControl* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnTemplatedControl* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnTemplatedControl* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnTemplatedControl* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnTemplatedControl* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnTemplatedControl* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnTemplatedControl* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnTemplatedControl* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnTemplatedControl* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnTemplatedControl* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnTemplatedControl* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnTemplatedControl* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnTemplatedControl* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnTemplatedControl* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnTemplatedControl* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnTemplatedControl* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnTemplatedControl* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnTemplatedControl* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnTemplatedControl* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnTemplatedControl* self, AvnThickness value); /* slot 70 */
};
struct IAvnTemplatedControl { const IAvnTemplatedControlVtbl* vtbl; };
#define I_AVN_TEMPLATED_CONTROL_VTABLE_SLOTS 71

static const AvnGuid I_AVN_TEXT_BLOCK_IID = {
    0x89F4FFBF,
    0x8672,
    0x5A0E,
    { 0xB2, 0xE0, 0xDA, 0x4A, 0x3F, 0x2C, 0x12, 0xA2 }
};
#define I_AVN_TEXT_BLOCK_ABI_VERSION 8
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnTextBlock* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnTextBlock* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnTextBlock* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnTextBlock* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnTextBlock* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnTextBlock* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnTextBlock* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnTextBlock* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnTextBlock* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnTextBlock* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnTextBlock* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnTextBlock* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnTextBlock* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnTextBlock* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnTextBlock* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnTextBlock* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnTextBlock* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnTextBlock* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnTextBlock* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnTextBlock* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnTextBlock* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnTextBlock* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnTextBlock* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTextBlock* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTextBlock* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnTextBlock* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnTextBlock* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnTextBlock* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnTextBlock* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTextBlock* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTextBlock* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTextBlock* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTextBlock* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTextBlock* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTextBlock* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_padding)(IAvnTextBlock* self, AvnThickness* value); /* slot 47 */
    AvnHResult (AVN_CALL *set_padding)(IAvnTextBlock* self, AvnThickness value); /* slot 48 */
    AvnHResult (AVN_CALL *get_background)(IAvnTextBlock* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_background)(IAvnTextBlock* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_text)(IAvnTextBlock* self, uint16_t** value); /* slot 51 */
    AvnHResult (AVN_CALL *set_text)(IAvnTextBlock* self, const uint16_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnTextBlock* self, uint16_t** value); /* slot 53 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnTextBlock* self, const uint16_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnTextBlock* self, double* value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnTextBlock* self, double value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnTextBlock* self, int32_t* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnTextBlock* self, int32_t value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnTextBlock* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnTextBlock* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnTextBlock* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnTextBlock* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnTextBlock* self, IAvnBrush** value); /* slot 63 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnTextBlock* self, IAvnBrush* value); /* slot 64 */
    AvnHResult (AVN_CALL *get_line_height)(IAvnTextBlock* self, double* value); /* slot 65 */
    AvnHResult (AVN_CALL *set_line_height)(IAvnTextBlock* self, double value); /* slot 66 */
    AvnHResult (AVN_CALL *get_line_spacing)(IAvnTextBlock* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_line_spacing)(IAvnTextBlock* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnTextBlock* self, double* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnTextBlock* self, double value); /* slot 70 */
    AvnHResult (AVN_CALL *get_max_lines)(IAvnTextBlock* self, int32_t* value); /* slot 71 */
    AvnHResult (AVN_CALL *set_max_lines)(IAvnTextBlock* self, int32_t value); /* slot 72 */
    AvnHResult (AVN_CALL *get_text_wrapping)(IAvnTextBlock* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_text_wrapping)(IAvnTextBlock* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_text_trimming)(IAvnTextBlock* self, uint16_t** value); /* slot 75 */
    AvnHResult (AVN_CALL *set_text_trimming)(IAvnTextBlock* self, const uint16_t* value); /* slot 76 */
    AvnHResult (AVN_CALL *get_text_alignment)(IAvnTextBlock* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_text_alignment)(IAvnTextBlock* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_baseline_offset)(IAvnTextBlock* self, double* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_baseline_offset)(IAvnTextBlock* self, double value); /* slot 80 */
};
struct IAvnTextBlock { const IAvnTextBlockVtbl* vtbl; };
#define I_AVN_TEXT_BLOCK_VTABLE_SLOTS 81

static const AvnGuid I_AVN_TEXT_BOX_IID = {
    0xBED2F9C1,
    0x483B,
    0x5D76,
    { 0x8F, 0x75, 0x5B, 0xF2, 0x30, 0x6C, 0xFB, 0x67 }
};
#define I_AVN_TEXT_BOX_ABI_VERSION 10
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnTextBox* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnTextBox* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnTextBox* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnTextBox* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnTextBox* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnTextBox* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnTextBox* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnTextBox* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnTextBox* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnTextBox* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnTextBox* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnTextBox* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnTextBox* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnTextBox* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnTextBox* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnTextBox* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnTextBox* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnTextBox* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnTextBox* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnTextBox* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnTextBox* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnTextBox* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnTextBox* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTextBox* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTextBox* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnTextBox* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnTextBox* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnTextBox* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnTextBox* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTextBox* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTextBox* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTextBox* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTextBox* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTextBox* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTextBox* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnTextBox* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnTextBox* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnTextBox* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnTextBox* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnTextBox* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnTextBox* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnTextBox* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnTextBox* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnTextBox* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnTextBox* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnTextBox* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnTextBox* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnTextBox* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnTextBox* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnTextBox* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnTextBox* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnTextBox* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnTextBox* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnTextBox* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnTextBox* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnTextBox* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnTextBox* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnTextBox* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnTextBox* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_is_inactive_selection_highlight_enabled)(IAvnTextBox* self, int32_t* value); /* slot 71 */
    AvnHResult (AVN_CALL *set_is_inactive_selection_highlight_enabled)(IAvnTextBox* self, int32_t value); /* slot 72 */
    AvnHResult (AVN_CALL *get_clear_selection_on_lost_focus)(IAvnTextBox* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_clear_selection_on_lost_focus)(IAvnTextBox* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_accepts_return)(IAvnTextBox* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_accepts_return)(IAvnTextBox* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_accepts_tab)(IAvnTextBox* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_accepts_tab)(IAvnTextBox* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_caret_index)(IAvnTextBox* self, int32_t* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_caret_index)(IAvnTextBox* self, int32_t value); /* slot 80 */
    AvnHResult (AVN_CALL *get_is_read_only)(IAvnTextBox* self, int32_t* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_is_read_only)(IAvnTextBox* self, int32_t value); /* slot 82 */
    AvnHResult (AVN_CALL *get_password_char)(IAvnTextBox* self, uint16_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_password_char)(IAvnTextBox* self, uint16_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_selection_brush)(IAvnTextBox* self, IAvnBrush** value); /* slot 85 */
    AvnHResult (AVN_CALL *set_selection_brush)(IAvnTextBox* self, IAvnBrush* value); /* slot 86 */
    AvnHResult (AVN_CALL *get_selection_foreground_brush)(IAvnTextBox* self, IAvnBrush** value); /* slot 87 */
    AvnHResult (AVN_CALL *set_selection_foreground_brush)(IAvnTextBox* self, IAvnBrush* value); /* slot 88 */
    AvnHResult (AVN_CALL *get_caret_brush)(IAvnTextBox* self, IAvnBrush** value); /* slot 89 */
    AvnHResult (AVN_CALL *set_caret_brush)(IAvnTextBox* self, IAvnBrush* value); /* slot 90 */
    AvnHResult (AVN_CALL *get_selection_start)(IAvnTextBox* self, int32_t* value); /* slot 91 */
    AvnHResult (AVN_CALL *set_selection_start)(IAvnTextBox* self, int32_t value); /* slot 92 */
    AvnHResult (AVN_CALL *get_selection_end)(IAvnTextBox* self, int32_t* value); /* slot 93 */
    AvnHResult (AVN_CALL *set_selection_end)(IAvnTextBox* self, int32_t value); /* slot 94 */
    AvnHResult (AVN_CALL *get_max_length)(IAvnTextBox* self, int32_t* value); /* slot 95 */
    AvnHResult (AVN_CALL *set_max_length)(IAvnTextBox* self, int32_t value); /* slot 96 */
    AvnHResult (AVN_CALL *get_max_lines)(IAvnTextBox* self, int32_t* value); /* slot 97 */
    AvnHResult (AVN_CALL *set_max_lines)(IAvnTextBox* self, int32_t value); /* slot 98 */
    AvnHResult (AVN_CALL *get_min_lines)(IAvnTextBox* self, int32_t* value); /* slot 99 */
    AvnHResult (AVN_CALL *set_min_lines)(IAvnTextBox* self, int32_t value); /* slot 100 */
    AvnHResult (AVN_CALL *get_line_height)(IAvnTextBox* self, double* value); /* slot 101 */
    AvnHResult (AVN_CALL *set_line_height)(IAvnTextBox* self, double value); /* slot 102 */
    AvnHResult (AVN_CALL *get_text)(IAvnTextBox* self, uint16_t** value); /* slot 103 */
    AvnHResult (AVN_CALL *set_text)(IAvnTextBox* self, const uint16_t* value); /* slot 104 */
    AvnHResult (AVN_CALL *get_selected_text)(IAvnTextBox* self, uint16_t** value); /* slot 105 */
    AvnHResult (AVN_CALL *set_selected_text)(IAvnTextBox* self, const uint16_t* value); /* slot 106 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnTextBox* self, int32_t* value); /* slot 107 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnTextBox* self, int32_t value); /* slot 108 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnTextBox* self, int32_t* value); /* slot 109 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnTextBox* self, int32_t value); /* slot 110 */
    AvnHResult (AVN_CALL *get_text_alignment)(IAvnTextBox* self, int32_t* value); /* slot 111 */
    AvnHResult (AVN_CALL *set_text_alignment)(IAvnTextBox* self, int32_t value); /* slot 112 */
    AvnHResult (AVN_CALL *get_placeholder_text)(IAvnTextBox* self, uint16_t** value); /* slot 113 */
    AvnHResult (AVN_CALL *set_placeholder_text)(IAvnTextBox* self, const uint16_t* value); /* slot 114 */
    AvnHResult (AVN_CALL *get_use_floating_placeholder)(IAvnTextBox* self, int32_t* value); /* slot 115 */
    AvnHResult (AVN_CALL *set_use_floating_placeholder)(IAvnTextBox* self, int32_t value); /* slot 116 */
    AvnHResult (AVN_CALL *get_placeholder_foreground)(IAvnTextBox* self, IAvnBrush** value); /* slot 117 */
    AvnHResult (AVN_CALL *set_placeholder_foreground)(IAvnTextBox* self, IAvnBrush* value); /* slot 118 */
    AvnHResult (AVN_CALL *get_inner_left_content)(IAvnTextBox* self, IAvnControl** value); /* slot 119 */
    AvnHResult (AVN_CALL *set_inner_left_content)(IAvnTextBox* self, IAvnControl* value); /* slot 120 */
    AvnHResult (AVN_CALL *get_inner_right_content)(IAvnTextBox* self, IAvnControl** value); /* slot 121 */
    AvnHResult (AVN_CALL *set_inner_right_content)(IAvnTextBox* self, IAvnControl* value); /* slot 122 */
    AvnHResult (AVN_CALL *get_reveal_password)(IAvnTextBox* self, int32_t* value); /* slot 123 */
    AvnHResult (AVN_CALL *set_reveal_password)(IAvnTextBox* self, int32_t value); /* slot 124 */
    AvnHResult (AVN_CALL *get_text_wrapping)(IAvnTextBox* self, int32_t* value); /* slot 125 */
    AvnHResult (AVN_CALL *set_text_wrapping)(IAvnTextBox* self, int32_t value); /* slot 126 */
    AvnHResult (AVN_CALL *get_new_line)(IAvnTextBox* self, uint16_t** value); /* slot 127 */
    AvnHResult (AVN_CALL *set_new_line)(IAvnTextBox* self, const uint16_t* value); /* slot 128 */
    AvnHResult (AVN_CALL *get_can_cut)(IAvnTextBox* self, int32_t* value); /* slot 129 */
    AvnHResult (AVN_CALL *get_can_copy)(IAvnTextBox* self, int32_t* value); /* slot 130 */
    AvnHResult (AVN_CALL *get_can_paste)(IAvnTextBox* self, int32_t* value); /* slot 131 */
    AvnHResult (AVN_CALL *get_is_undo_enabled)(IAvnTextBox* self, int32_t* value); /* slot 132 */
    AvnHResult (AVN_CALL *set_is_undo_enabled)(IAvnTextBox* self, int32_t value); /* slot 133 */
    AvnHResult (AVN_CALL *get_undo_limit)(IAvnTextBox* self, int32_t* value); /* slot 134 */
    AvnHResult (AVN_CALL *set_undo_limit)(IAvnTextBox* self, int32_t value); /* slot 135 */
    AvnHResult (AVN_CALL *get_can_undo)(IAvnTextBox* self, int32_t* value); /* slot 136 */
    AvnHResult (AVN_CALL *get_can_redo)(IAvnTextBox* self, int32_t* value); /* slot 137 */
    AvnHResult (AVN_CALL *clear_selection)(IAvnTextBox* self); /* slot 138 */
    AvnHResult (AVN_CALL *get_line_count)(IAvnTextBox* self, int32_t* value); /* slot 139 */
    AvnHResult (AVN_CALL *cut)(IAvnTextBox* self); /* slot 140 */
    AvnHResult (AVN_CALL *copy)(IAvnTextBox* self); /* slot 141 */
    AvnHResult (AVN_CALL *paste)(IAvnTextBox* self); /* slot 142 */
    AvnHResult (AVN_CALL *clear)(IAvnTextBox* self); /* slot 143 */
    AvnHResult (AVN_CALL *scroll_to_line_with_int32)(IAvnTextBox* self, int32_t line_index); /* slot 144 */
    AvnHResult (AVN_CALL *select_all)(IAvnTextBox* self); /* slot 145 */
    AvnHResult (AVN_CALL *undo)(IAvnTextBox* self); /* slot 146 */
    AvnHResult (AVN_CALL *redo)(IAvnTextBox* self); /* slot 147 */
    AvnHResult (AVN_CALL *advise_copying_to_clipboard)(IAvnTextBox* self, IAvnTextBoxCopyingToClipboardHandler* handler, int64_t* subscription_id); /* slot 148 */
    AvnHResult (AVN_CALL *unadvise_copying_to_clipboard)(IAvnTextBox* self, int64_t subscription_id); /* slot 149 */
    AvnHResult (AVN_CALL *advise_cutting_to_clipboard)(IAvnTextBox* self, IAvnTextBoxCuttingToClipboardHandler* handler, int64_t* subscription_id); /* slot 150 */
    AvnHResult (AVN_CALL *unadvise_cutting_to_clipboard)(IAvnTextBox* self, int64_t subscription_id); /* slot 151 */
    AvnHResult (AVN_CALL *advise_pasting_from_clipboard)(IAvnTextBox* self, IAvnTextBoxPastingFromClipboardHandler* handler, int64_t* subscription_id); /* slot 152 */
    AvnHResult (AVN_CALL *unadvise_pasting_from_clipboard)(IAvnTextBox* self, int64_t subscription_id); /* slot 153 */
    AvnHResult (AVN_CALL *advise_text_changed)(IAvnTextBox* self, IAvnTextBoxTextChangedHandler* handler, int64_t* subscription_id); /* slot 154 */
    AvnHResult (AVN_CALL *unadvise_text_changed)(IAvnTextBox* self, int64_t subscription_id); /* slot 155 */
};
struct IAvnTextBox { const IAvnTextBoxVtbl* vtbl; };
#define I_AVN_TEXT_BOX_VTABLE_SLOTS 156

static const AvnGuid I_AVN_THEME_VARIANT_SCOPE_IID = {
    0x6B8223DE,
    0x4F86,
    0x5921,
    { 0xBA, 0xD1, 0x39, 0xD6, 0xD3, 0x3D, 0x0B, 0x10 }
};
#define I_AVN_THEME_VARIANT_SCOPE_ABI_VERSION 2
struct IAvnThemeVariantScopeVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnThemeVariantScope* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnThemeVariantScope* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnThemeVariantScope* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnThemeVariantScope* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnThemeVariantScope* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnThemeVariantScope* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnThemeVariantScope* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnThemeVariantScope* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnThemeVariantScope* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnThemeVariantScope* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnThemeVariantScope* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnThemeVariantScope* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnThemeVariantScope* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnThemeVariantScope* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnThemeVariantScope* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnThemeVariantScope* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnThemeVariantScope* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnThemeVariantScope* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnThemeVariantScope* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnThemeVariantScope* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnThemeVariantScope* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnThemeVariantScope* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnThemeVariantScope* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnThemeVariantScope* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnThemeVariantScope* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnThemeVariantScope* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnThemeVariantScope* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnThemeVariantScope* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnThemeVariantScope* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnThemeVariantScope* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnThemeVariantScope* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnThemeVariantScope* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnThemeVariantScope* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnThemeVariantScope* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnThemeVariantScope* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnThemeVariantScope* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnThemeVariantScope* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnThemeVariantScope* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnThemeVariantScope* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnThemeVariantScope* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnThemeVariantScope* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnThemeVariantScope* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnThemeVariantScope* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnThemeVariantScope* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnThemeVariantScope* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnThemeVariantScope* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnThemeVariantScope* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_child)(IAvnThemeVariantScope* self, IAvnControl** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_child)(IAvnThemeVariantScope* self, IAvnControl* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_padding)(IAvnThemeVariantScope* self, AvnThickness* value); /* slot 49 */
    AvnHResult (AVN_CALL *set_padding)(IAvnThemeVariantScope* self, AvnThickness value); /* slot 50 */
};
struct IAvnThemeVariantScope { const IAvnThemeVariantScopeVtbl* vtbl; };
#define I_AVN_THEME_VARIANT_SCOPE_VTABLE_SLOTS 51

static const AvnGuid I_AVN_THUMB_IID = {
    0x76FE925F,
    0xC530,
    0x5A8D,
    { 0x9A, 0xBC, 0x2C, 0x91, 0x5C, 0x6B, 0xCF, 0x9C }
};
#define I_AVN_THUMB_ABI_VERSION 4
struct IAvnThumbVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnThumb* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnThumb* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnThumb* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnThumb* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnThumb* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnThumb* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnThumb* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnThumb* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnThumb* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnThumb* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnThumb* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnThumb* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnThumb* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnThumb* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnThumb* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnThumb* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnThumb* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnThumb* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnThumb* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnThumb* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnThumb* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnThumb* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnThumb* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnThumb* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnThumb* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnThumb* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnThumb* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnThumb* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnThumb* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnThumb* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnThumb* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnThumb* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnThumb* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnThumb* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnThumb* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnThumb* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnThumb* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnThumb* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnThumb* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnThumb* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnThumb* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnThumb* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnThumb* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnThumb* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnThumb* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnThumb* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnThumb* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnThumb* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnThumb* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnThumb* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnThumb* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnThumb* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnThumb* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnThumb* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnThumb* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnThumb* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnThumb* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnThumb* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnThumb* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnThumb* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnThumb* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnThumb* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnThumb* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnThumb* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnThumb* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnThumb* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnThumb* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnThumb* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnThumb* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnThumb* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnThumb* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *advise_drag_started)(IAvnThumb* self, IAvnThumbDragStartedHandler* handler, int64_t* subscription_id); /* slot 71 */
    AvnHResult (AVN_CALL *unadvise_drag_started)(IAvnThumb* self, int64_t subscription_id); /* slot 72 */
    AvnHResult (AVN_CALL *advise_drag_delta)(IAvnThumb* self, IAvnThumbDragDeltaHandler* handler, int64_t* subscription_id); /* slot 73 */
    AvnHResult (AVN_CALL *unadvise_drag_delta)(IAvnThumb* self, int64_t subscription_id); /* slot 74 */
    AvnHResult (AVN_CALL *advise_drag_completed)(IAvnThumb* self, IAvnThumbDragCompletedHandler* handler, int64_t* subscription_id); /* slot 75 */
    AvnHResult (AVN_CALL *unadvise_drag_completed)(IAvnThumb* self, int64_t subscription_id); /* slot 76 */
};
struct IAvnThumb { const IAvnThumbVtbl* vtbl; };
#define I_AVN_THUMB_VTABLE_SLOTS 77

static const AvnGuid I_AVN_TIME_PICKER_IID = {
    0x60009974,
    0x2307,
    0x5DB3,
    { 0x93, 0x1F, 0x79, 0x65, 0xFD, 0x21, 0x76, 0xB5 }
};
#define I_AVN_TIME_PICKER_ABI_VERSION 4
struct IAvnTimePickerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTimePicker* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTimePicker* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTimePicker* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnTimePicker* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnTimePicker* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnTimePicker* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnTimePicker* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnTimePicker* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnTimePicker* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnTimePicker* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnTimePicker* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnTimePicker* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnTimePicker* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnTimePicker* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnTimePicker* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnTimePicker* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnTimePicker* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnTimePicker* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnTimePicker* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnTimePicker* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnTimePicker* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnTimePicker* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnTimePicker* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnTimePicker* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnTimePicker* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnTimePicker* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnTimePicker* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnTimePicker* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnTimePicker* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnTimePicker* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnTimePicker* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnTimePicker* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnTimePicker* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnTimePicker* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnTimePicker* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTimePicker* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTimePicker* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnTimePicker* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnTimePicker* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnTimePicker* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnTimePicker* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTimePicker* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTimePicker* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTimePicker* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTimePicker* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTimePicker* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTimePicker* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnTimePicker* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnTimePicker* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnTimePicker* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnTimePicker* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnTimePicker* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnTimePicker* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnTimePicker* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnTimePicker* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnTimePicker* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnTimePicker* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnTimePicker* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnTimePicker* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnTimePicker* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnTimePicker* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnTimePicker* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnTimePicker* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnTimePicker* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnTimePicker* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnTimePicker* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnTimePicker* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnTimePicker* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnTimePicker* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnTimePicker* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnTimePicker* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnTimePicker* self, int32_t* value); /* slot 71 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnTimePicker* self, int32_t value); /* slot 72 */
    AvnHResult (AVN_CALL *get_minute_increment)(IAvnTimePicker* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_minute_increment)(IAvnTimePicker* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_second_increment)(IAvnTimePicker* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_second_increment)(IAvnTimePicker* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_clock_identifier)(IAvnTimePicker* self, uint16_t** value); /* slot 77 */
    AvnHResult (AVN_CALL *set_clock_identifier)(IAvnTimePicker* self, const uint16_t* value); /* slot 78 */
    AvnHResult (AVN_CALL *get_use_seconds)(IAvnTimePicker* self, int32_t* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_use_seconds)(IAvnTimePicker* self, int32_t value); /* slot 80 */
    AvnHResult (AVN_CALL *get_selected_time)(IAvnTimePicker* self, uint16_t** value); /* slot 81 */
    AvnHResult (AVN_CALL *set_selected_time)(IAvnTimePicker* self, const uint16_t* value); /* slot 82 */
    AvnHResult (AVN_CALL *clear)(IAvnTimePicker* self); /* slot 83 */
};
struct IAvnTimePicker { const IAvnTimePickerVtbl* vtbl; };
#define I_AVN_TIME_PICKER_VTABLE_SLOTS 84

static const AvnGuid I_AVN_TOGGLE_BUTTON_IID = {
    0x6E46D960,
    0x3762,
    0x595C,
    { 0x99, 0x50, 0xE1, 0x62, 0x04, 0xF4, 0xE4, 0x00 }
};
#define I_AVN_TOGGLE_BUTTON_ABI_VERSION 10
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnToggleButton* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnToggleButton* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnToggleButton* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnToggleButton* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnToggleButton* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnToggleButton* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnToggleButton* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnToggleButton* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnToggleButton* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnToggleButton* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnToggleButton* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnToggleButton* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnToggleButton* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnToggleButton* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnToggleButton* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnToggleButton* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnToggleButton* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnToggleButton* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnToggleButton* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnToggleButton* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnToggleButton* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnToggleButton* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnToggleButton* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnToggleButton* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnToggleButton* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnToggleButton* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnToggleButton* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnToggleButton* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnToggleButton* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnToggleButton* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnToggleButton* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnToggleButton* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnToggleButton* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnToggleButton* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnToggleButton* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnToggleButton* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnToggleButton* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnToggleButton* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnToggleButton* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnToggleButton* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnToggleButton* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnToggleButton* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnToggleButton* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnToggleButton* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnToggleButton* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnToggleButton* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnToggleButton* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnToggleButton* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnToggleButton* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnToggleButton* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnToggleButton* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnToggleButton* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnToggleButton* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnToggleButton* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnToggleButton* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnToggleButton* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnToggleButton* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnToggleButton* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnToggleButton* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnToggleButton* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnToggleButton* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnToggleButton* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnToggleButton* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnToggleButton* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnToggleButton* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_click_mode)(IAvnToggleButton* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_click_mode)(IAvnToggleButton* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_command)(IAvnToggleButton* self, IAvnCommand** value); /* slot 79 */
    AvnHResult (AVN_CALL *set_command)(IAvnToggleButton* self, IAvnCommand* value); /* slot 80 */
    AvnHResult (AVN_CALL *get_command_parameter)(IAvnToggleButton* self, AvnVariant* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_command_parameter)(IAvnToggleButton* self, AvnVariant value); /* slot 82 */
    AvnHResult (AVN_CALL *get_is_default)(IAvnToggleButton* self, int32_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_is_default)(IAvnToggleButton* self, int32_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_is_cancel)(IAvnToggleButton* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_is_cancel)(IAvnToggleButton* self, int32_t value); /* slot 86 */
    AvnHResult (AVN_CALL *get_is_pressed)(IAvnToggleButton* self, int32_t* value); /* slot 87 */
    AvnHResult (AVN_CALL *get_flyout)(IAvnToggleButton* self, IAvnFlyoutBase** value); /* slot 88 */
    AvnHResult (AVN_CALL *set_flyout)(IAvnToggleButton* self, IAvnFlyoutBase* value); /* slot 89 */
    AvnHResult (AVN_CALL *advise_click)(IAvnToggleButton* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 90 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnToggleButton* self, int64_t subscription_id); /* slot 91 */
    AvnHResult (AVN_CALL *get_is_checked)(IAvnToggleButton* self, int32_t* value); /* slot 92 */
    AvnHResult (AVN_CALL *set_is_checked)(IAvnToggleButton* self, int32_t value); /* slot 93 */
    AvnHResult (AVN_CALL *get_is_three_state)(IAvnToggleButton* self, int32_t* value); /* slot 94 */
    AvnHResult (AVN_CALL *set_is_three_state)(IAvnToggleButton* self, int32_t value); /* slot 95 */
    AvnHResult (AVN_CALL *advise_is_checked_changed)(IAvnToggleButton* self, IAvnToggleButtonIsCheckedChangedHandler* handler, int64_t* subscription_id); /* slot 96 */
    AvnHResult (AVN_CALL *unadvise_is_checked_changed)(IAvnToggleButton* self, int64_t subscription_id); /* slot 97 */
};
struct IAvnToggleButton { const IAvnToggleButtonVtbl* vtbl; };
#define I_AVN_TOGGLE_BUTTON_VTABLE_SLOTS 98

static const AvnGuid I_AVN_TOGGLE_SPLIT_BUTTON_IID = {
    0x3F3FC868,
    0xC393,
    0x5834,
    { 0x9B, 0x57, 0x16, 0x13, 0x23, 0x73, 0xDE, 0x1C }
};
#define I_AVN_TOGGLE_SPLIT_BUTTON_ABI_VERSION 6
struct IAvnToggleSplitButtonVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnToggleSplitButton* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnToggleSplitButton* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnToggleSplitButton* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnToggleSplitButton* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnToggleSplitButton* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnToggleSplitButton* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnToggleSplitButton* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnToggleSplitButton* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnToggleSplitButton* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnToggleSplitButton* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnToggleSplitButton* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnToggleSplitButton* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnToggleSplitButton* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnToggleSplitButton* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnToggleSplitButton* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnToggleSplitButton* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnToggleSplitButton* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnToggleSplitButton* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnToggleSplitButton* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnToggleSplitButton* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnToggleSplitButton* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnToggleSplitButton* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnToggleSplitButton* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnToggleSplitButton* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnToggleSplitButton* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnToggleSplitButton* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnToggleSplitButton* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnToggleSplitButton* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnToggleSplitButton* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnToggleSplitButton* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnToggleSplitButton* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnToggleSplitButton* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnToggleSplitButton* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnToggleSplitButton* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnToggleSplitButton* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnToggleSplitButton* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnToggleSplitButton* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnToggleSplitButton* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnToggleSplitButton* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnToggleSplitButton* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnToggleSplitButton* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnToggleSplitButton* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnToggleSplitButton* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnToggleSplitButton* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnToggleSplitButton* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnToggleSplitButton* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnToggleSplitButton* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnToggleSplitButton* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnToggleSplitButton* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnToggleSplitButton* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnToggleSplitButton* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnToggleSplitButton* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnToggleSplitButton* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnToggleSplitButton* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnToggleSplitButton* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnToggleSplitButton* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnToggleSplitButton* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnToggleSplitButton* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnToggleSplitButton* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnToggleSplitButton* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnToggleSplitButton* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnToggleSplitButton* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnToggleSplitButton* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnToggleSplitButton* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnToggleSplitButton* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnToggleSplitButton* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnToggleSplitButton* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnToggleSplitButton* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnToggleSplitButton* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnToggleSplitButton* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnToggleSplitButton* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnToggleSplitButton* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnToggleSplitButton* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnToggleSplitButton* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnToggleSplitButton* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnToggleSplitButton* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnToggleSplitButton* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_command)(IAvnToggleSplitButton* self, IAvnCommand** value); /* slot 77 */
    AvnHResult (AVN_CALL *set_command)(IAvnToggleSplitButton* self, IAvnCommand* value); /* slot 78 */
    AvnHResult (AVN_CALL *get_command_parameter)(IAvnToggleSplitButton* self, AvnVariant* value); /* slot 79 */
    AvnHResult (AVN_CALL *set_command_parameter)(IAvnToggleSplitButton* self, AvnVariant value); /* slot 80 */
    AvnHResult (AVN_CALL *get_flyout)(IAvnToggleSplitButton* self, IAvnFlyoutBase** value); /* slot 81 */
    AvnHResult (AVN_CALL *set_flyout)(IAvnToggleSplitButton* self, IAvnFlyoutBase* value); /* slot 82 */
    AvnHResult (AVN_CALL *advise_click)(IAvnToggleSplitButton* self, IAvnSplitButtonClickHandler* handler, int64_t* subscription_id); /* slot 83 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnToggleSplitButton* self, int64_t subscription_id); /* slot 84 */
    AvnHResult (AVN_CALL *get_is_checked)(IAvnToggleSplitButton* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_is_checked)(IAvnToggleSplitButton* self, int32_t value); /* slot 86 */
    AvnHResult (AVN_CALL *advise_is_checked_changed)(IAvnToggleSplitButton* self, IAvnToggleSplitButtonIsCheckedChangedHandler* handler, int64_t* subscription_id); /* slot 87 */
    AvnHResult (AVN_CALL *unadvise_is_checked_changed)(IAvnToggleSplitButton* self, int64_t subscription_id); /* slot 88 */
};
struct IAvnToggleSplitButton { const IAvnToggleSplitButtonVtbl* vtbl; };
#define I_AVN_TOGGLE_SPLIT_BUTTON_VTABLE_SLOTS 89

static const AvnGuid I_AVN_TOGGLE_SWITCH_IID = {
    0x25A80BAD,
    0xDD11,
    0x579D,
    { 0x87, 0x74, 0x64, 0x70, 0xC2, 0x7A, 0xC8, 0xC6 }
};
#define I_AVN_TOGGLE_SWITCH_ABI_VERSION 10
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnToggleSwitch* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnToggleSwitch* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnToggleSwitch* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnToggleSwitch* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnToggleSwitch* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnToggleSwitch* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnToggleSwitch* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnToggleSwitch* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnToggleSwitch* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnToggleSwitch* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnToggleSwitch* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnToggleSwitch* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnToggleSwitch* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnToggleSwitch* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnToggleSwitch* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnToggleSwitch* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnToggleSwitch* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnToggleSwitch* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnToggleSwitch* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnToggleSwitch* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnToggleSwitch* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnToggleSwitch* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnToggleSwitch* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnToggleSwitch* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnToggleSwitch* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnToggleSwitch* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnToggleSwitch* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnToggleSwitch* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnToggleSwitch* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnToggleSwitch* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnToggleSwitch* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnToggleSwitch* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnToggleSwitch* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnToggleSwitch* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnToggleSwitch* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnToggleSwitch* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnToggleSwitch* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnToggleSwitch* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnToggleSwitch* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnToggleSwitch* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnToggleSwitch* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnToggleSwitch* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnToggleSwitch* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnToggleSwitch* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnToggleSwitch* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnToggleSwitch* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnToggleSwitch* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnToggleSwitch* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnToggleSwitch* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnToggleSwitch* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnToggleSwitch* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnToggleSwitch* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnToggleSwitch* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnToggleSwitch* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnToggleSwitch* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnToggleSwitch* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnToggleSwitch* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnToggleSwitch* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnToggleSwitch* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnToggleSwitch* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnToggleSwitch* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnToggleSwitch* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnToggleSwitch* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnToggleSwitch* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnToggleSwitch* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_click_mode)(IAvnToggleSwitch* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_click_mode)(IAvnToggleSwitch* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_command)(IAvnToggleSwitch* self, IAvnCommand** value); /* slot 79 */
    AvnHResult (AVN_CALL *set_command)(IAvnToggleSwitch* self, IAvnCommand* value); /* slot 80 */
    AvnHResult (AVN_CALL *get_command_parameter)(IAvnToggleSwitch* self, AvnVariant* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_command_parameter)(IAvnToggleSwitch* self, AvnVariant value); /* slot 82 */
    AvnHResult (AVN_CALL *get_is_default)(IAvnToggleSwitch* self, int32_t* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_is_default)(IAvnToggleSwitch* self, int32_t value); /* slot 84 */
    AvnHResult (AVN_CALL *get_is_cancel)(IAvnToggleSwitch* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *set_is_cancel)(IAvnToggleSwitch* self, int32_t value); /* slot 86 */
    AvnHResult (AVN_CALL *get_is_pressed)(IAvnToggleSwitch* self, int32_t* value); /* slot 87 */
    AvnHResult (AVN_CALL *get_flyout)(IAvnToggleSwitch* self, IAvnFlyoutBase** value); /* slot 88 */
    AvnHResult (AVN_CALL *set_flyout)(IAvnToggleSwitch* self, IAvnFlyoutBase* value); /* slot 89 */
    AvnHResult (AVN_CALL *advise_click)(IAvnToggleSwitch* self, IAvnButtonClickHandler* handler, int64_t* subscription_id); /* slot 90 */
    AvnHResult (AVN_CALL *unadvise_click)(IAvnToggleSwitch* self, int64_t subscription_id); /* slot 91 */
    AvnHResult (AVN_CALL *get_is_checked)(IAvnToggleSwitch* self, int32_t* value); /* slot 92 */
    AvnHResult (AVN_CALL *set_is_checked)(IAvnToggleSwitch* self, int32_t value); /* slot 93 */
    AvnHResult (AVN_CALL *get_is_three_state)(IAvnToggleSwitch* self, int32_t* value); /* slot 94 */
    AvnHResult (AVN_CALL *set_is_three_state)(IAvnToggleSwitch* self, int32_t value); /* slot 95 */
    AvnHResult (AVN_CALL *advise_is_checked_changed)(IAvnToggleSwitch* self, IAvnToggleButtonIsCheckedChangedHandler* handler, int64_t* subscription_id); /* slot 96 */
    AvnHResult (AVN_CALL *unadvise_is_checked_changed)(IAvnToggleSwitch* self, int64_t subscription_id); /* slot 97 */
    AvnHResult (AVN_CALL *get_on_content)(IAvnToggleSwitch* self, IAvnControl** value); /* slot 98 */
    AvnHResult (AVN_CALL *set_on_content)(IAvnToggleSwitch* self, IAvnControl* value); /* slot 99 */
    AvnHResult (AVN_CALL *get_off_content)(IAvnToggleSwitch* self, IAvnControl** value); /* slot 100 */
    AvnHResult (AVN_CALL *set_off_content)(IAvnToggleSwitch* self, IAvnControl* value); /* slot 101 */
};
struct IAvnToggleSwitch { const IAvnToggleSwitchVtbl* vtbl; };
#define I_AVN_TOGGLE_SWITCH_VTABLE_SLOTS 102

static const AvnGuid I_AVN_TOOL_TIP_IID = {
    0x1567103D,
    0x03B5,
    0x51A8,
    { 0xA3, 0x8F, 0xAD, 0xEE, 0x27, 0x41, 0xF0, 0xCE }
};
#define I_AVN_TOOL_TIP_ABI_VERSION 3
struct IAvnToolTipVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnToolTip* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnToolTip* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnToolTip* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnToolTip* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnToolTip* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnToolTip* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnToolTip* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnToolTip* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnToolTip* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnToolTip* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnToolTip* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnToolTip* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnToolTip* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnToolTip* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnToolTip* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnToolTip* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnToolTip* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnToolTip* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnToolTip* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnToolTip* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnToolTip* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnToolTip* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnToolTip* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnToolTip* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnToolTip* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnToolTip* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnToolTip* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnToolTip* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnToolTip* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnToolTip* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnToolTip* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnToolTip* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnToolTip* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnToolTip* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnToolTip* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnToolTip* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnToolTip* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnToolTip* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnToolTip* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnToolTip* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnToolTip* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnToolTip* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnToolTip* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnToolTip* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnToolTip* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnToolTip* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnToolTip* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnToolTip* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnToolTip* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnToolTip* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnToolTip* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnToolTip* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnToolTip* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnToolTip* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnToolTip* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnToolTip* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnToolTip* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnToolTip* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnToolTip* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnToolTip* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnToolTip* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnToolTip* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnToolTip* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnToolTip* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnToolTip* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnToolTip* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnToolTip* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnToolTip* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnToolTip* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnToolTip* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnToolTip* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnToolTip* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnToolTip* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnToolTip* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnToolTip* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnToolTip* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnToolTip* self, int32_t value); /* slot 76 */
};
struct IAvnToolTip { const IAvnToolTipVtbl* vtbl; };
#define I_AVN_TOOL_TIP_VTABLE_SLOTS 77

static const AvnGuid I_AVN_TRANSITIONING_CONTENT_CONTROL_IID = {
    0x0B974218,
    0xD860,
    0x5122,
    { 0xBC, 0x61, 0xAE, 0xA6, 0x5B, 0x05, 0xDE, 0x7C }
};
#define I_AVN_TRANSITIONING_CONTENT_CONTROL_ABI_VERSION 3
struct IAvnTransitioningContentControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTransitioningContentControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTransitioningContentControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTransitioningContentControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnTransitioningContentControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnTransitioningContentControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnTransitioningContentControl* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnTransitioningContentControl* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnTransitioningContentControl* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnTransitioningContentControl* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnTransitioningContentControl* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnTransitioningContentControl* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnTransitioningContentControl* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnTransitioningContentControl* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnTransitioningContentControl* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnTransitioningContentControl* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnTransitioningContentControl* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnTransitioningContentControl* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnTransitioningContentControl* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnTransitioningContentControl* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnTransitioningContentControl* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnTransitioningContentControl* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnTransitioningContentControl* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnTransitioningContentControl* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnTransitioningContentControl* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnTransitioningContentControl* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnTransitioningContentControl* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnTransitioningContentControl* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnTransitioningContentControl* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnTransitioningContentControl* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnTransitioningContentControl* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnTransitioningContentControl* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnTransitioningContentControl* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnTransitioningContentControl* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnTransitioningContentControl* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnTransitioningContentControl* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTransitioningContentControl* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTransitioningContentControl* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnTransitioningContentControl* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnTransitioningContentControl* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnTransitioningContentControl* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnTransitioningContentControl* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTransitioningContentControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTransitioningContentControl* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTransitioningContentControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTransitioningContentControl* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTransitioningContentControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTransitioningContentControl* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnTransitioningContentControl* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnTransitioningContentControl* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnTransitioningContentControl* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnTransitioningContentControl* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnTransitioningContentControl* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnTransitioningContentControl* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnTransitioningContentControl* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnTransitioningContentControl* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnTransitioningContentControl* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnTransitioningContentControl* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnTransitioningContentControl* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnTransitioningContentControl* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnTransitioningContentControl* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnTransitioningContentControl* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnTransitioningContentControl* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnTransitioningContentControl* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnTransitioningContentControl* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnTransitioningContentControl* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnTransitioningContentControl* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnTransitioningContentControl* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnTransitioningContentControl* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnTransitioningContentControl* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnTransitioningContentControl* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnTransitioningContentControl* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnTransitioningContentControl* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnTransitioningContentControl* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnTransitioningContentControl* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnTransitioningContentControl* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnTransitioningContentControl* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnTransitioningContentControl* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_is_transition_reversed)(IAvnTransitioningContentControl* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_is_transition_reversed)(IAvnTransitioningContentControl* self, int32_t value); /* slot 78 */
};
struct IAvnTransitioningContentControl { const IAvnTransitioningContentControlVtbl* vtbl; };
#define I_AVN_TRANSITIONING_CONTENT_CONTROL_VTABLE_SLOTS 79

static const AvnGuid I_AVN_TRAY_ICON_IID = {
    0xC05739ED,
    0x7716,
    0x5E87,
    { 0x90, 0xAD, 0x96, 0xCC, 0xBA, 0x60, 0x42, 0x9C }
};
#define I_AVN_TRAY_ICON_ABI_VERSION 3
struct IAvnTrayIconVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTrayIcon* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTrayIcon* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTrayIcon* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnTrayIcon* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnTrayIcon* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_command)(IAvnTrayIcon* self, IAvnCommand** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_command)(IAvnTrayIcon* self, IAvnCommand* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_command_parameter)(IAvnTrayIcon* self, AvnVariant* value); /* slot 7 */
    AvnHResult (AVN_CALL *set_command_parameter)(IAvnTrayIcon* self, AvnVariant value); /* slot 8 */
    AvnHResult (AVN_CALL *get_tool_tip_text)(IAvnTrayIcon* self, uint16_t** value); /* slot 9 */
    AvnHResult (AVN_CALL *set_tool_tip_text)(IAvnTrayIcon* self, const uint16_t* value); /* slot 10 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnTrayIcon* self, int32_t* value); /* slot 11 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnTrayIcon* self, int32_t value); /* slot 12 */
};
struct IAvnTrayIcon { const IAvnTrayIconVtbl* vtbl; };
#define I_AVN_TRAY_ICON_VTABLE_SLOTS 13

static const AvnGuid I_AVN_TREE_VIEW_IID = {
    0x662E54E6,
    0x2CB4,
    0x585C,
    { 0x8C, 0xE7, 0xA3, 0xFE, 0x2D, 0x3F, 0x58, 0x38 }
};
#define I_AVN_TREE_VIEW_ABI_VERSION 4
struct IAvnTreeViewVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTreeView* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTreeView* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTreeView* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnTreeView* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnTreeView* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnTreeView* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnTreeView* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnTreeView* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnTreeView* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnTreeView* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnTreeView* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnTreeView* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnTreeView* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnTreeView* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnTreeView* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnTreeView* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnTreeView* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnTreeView* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnTreeView* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnTreeView* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnTreeView* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnTreeView* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnTreeView* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnTreeView* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnTreeView* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnTreeView* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnTreeView* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnTreeView* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnTreeView* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnTreeView* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnTreeView* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnTreeView* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnTreeView* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnTreeView* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnTreeView* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTreeView* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTreeView* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnTreeView* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnTreeView* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnTreeView* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnTreeView* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTreeView* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTreeView* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTreeView* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTreeView* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTreeView* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTreeView* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnTreeView* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnTreeView* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnTreeView* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnTreeView* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnTreeView* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnTreeView* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnTreeView* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnTreeView* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnTreeView* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnTreeView* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnTreeView* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnTreeView* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnTreeView* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnTreeView* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnTreeView* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnTreeView* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnTreeView* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnTreeView* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnTreeView* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnTreeView* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnTreeView* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnTreeView* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnTreeView* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnTreeView* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_items)(IAvnTreeView* self, IAvnItemList** value); /* slot 71 */
    AvnHResult (AVN_CALL *get_item_count)(IAvnTreeView* self, int32_t* value); /* slot 72 */
    AvnHResult (AVN_CALL *scroll_into_view_with_int32)(IAvnTreeView* self, int32_t index); /* slot 73 */
    AvnHResult (AVN_CALL *get_auto_scroll_to_selected_item)(IAvnTreeView* self, int32_t* value); /* slot 74 */
    AvnHResult (AVN_CALL *set_auto_scroll_to_selected_item)(IAvnTreeView* self, int32_t value); /* slot 75 */
    AvnHResult (AVN_CALL *get_selection_mode)(IAvnTreeView* self, int32_t* value); /* slot 76 */
    AvnHResult (AVN_CALL *set_selection_mode)(IAvnTreeView* self, int32_t value); /* slot 77 */
    AvnHResult (AVN_CALL *expand_sub_tree_with_tree_view_item)(IAvnTreeView* self, IAvnTreeViewItem* item); /* slot 78 */
    AvnHResult (AVN_CALL *collapse_sub_tree_with_tree_view_item)(IAvnTreeView* self, IAvnTreeViewItem* item); /* slot 79 */
    AvnHResult (AVN_CALL *select_all)(IAvnTreeView* self); /* slot 80 */
    AvnHResult (AVN_CALL *unselect_all)(IAvnTreeView* self); /* slot 81 */
    AvnHResult (AVN_CALL *advise_selection_changed)(IAvnTreeView* self, IAvnTreeViewSelectionChangedHandler* handler, int64_t* subscription_id); /* slot 82 */
    AvnHResult (AVN_CALL *unadvise_selection_changed)(IAvnTreeView* self, int64_t subscription_id); /* slot 83 */
};
struct IAvnTreeView { const IAvnTreeViewVtbl* vtbl; };
#define I_AVN_TREE_VIEW_VTABLE_SLOTS 84

static const AvnGuid I_AVN_TREE_VIEW_ITEM_IID = {
    0x33D8152A,
    0x31F9,
    0x5356,
    { 0x89, 0x55, 0xE2, 0x48, 0xFB, 0x07, 0x8D, 0x13 }
};
#define I_AVN_TREE_VIEW_ITEM_ABI_VERSION 4
struct IAvnTreeViewItemVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnTreeViewItem* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnTreeViewItem* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnTreeViewItem* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnTreeViewItem* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnTreeViewItem* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnTreeViewItem* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnTreeViewItem* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnTreeViewItem* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnTreeViewItem* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnTreeViewItem* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnTreeViewItem* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnTreeViewItem* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnTreeViewItem* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnTreeViewItem* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnTreeViewItem* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnTreeViewItem* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnTreeViewItem* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnTreeViewItem* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnTreeViewItem* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnTreeViewItem* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnTreeViewItem* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnTreeViewItem* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnTreeViewItem* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnTreeViewItem* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnTreeViewItem* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnTreeViewItem* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnTreeViewItem* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnTreeViewItem* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnTreeViewItem* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnTreeViewItem* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnTreeViewItem* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnTreeViewItem* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnTreeViewItem* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnTreeViewItem* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnTreeViewItem* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnTreeViewItem* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnTreeViewItem* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnTreeViewItem* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnTreeViewItem* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnTreeViewItem* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnTreeViewItem* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnTreeViewItem* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnTreeViewItem* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnTreeViewItem* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnTreeViewItem* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnTreeViewItem* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnTreeViewItem* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnTreeViewItem* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnTreeViewItem* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnTreeViewItem* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnTreeViewItem* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnTreeViewItem* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnTreeViewItem* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnTreeViewItem* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnTreeViewItem* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnTreeViewItem* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnTreeViewItem* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnTreeViewItem* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnTreeViewItem* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnTreeViewItem* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnTreeViewItem* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnTreeViewItem* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnTreeViewItem* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnTreeViewItem* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnTreeViewItem* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnTreeViewItem* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnTreeViewItem* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnTreeViewItem* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnTreeViewItem* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnTreeViewItem* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnTreeViewItem* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_items)(IAvnTreeViewItem* self, IAvnItemList** value); /* slot 71 */
    AvnHResult (AVN_CALL *get_item_count)(IAvnTreeViewItem* self, int32_t* value); /* slot 72 */
    AvnHResult (AVN_CALL *scroll_into_view_with_int32)(IAvnTreeViewItem* self, int32_t index); /* slot 73 */
    AvnHResult (AVN_CALL *get_header)(IAvnTreeViewItem* self, IAvnControl** value); /* slot 74 */
    AvnHResult (AVN_CALL *set_header)(IAvnTreeViewItem* self, IAvnControl* value); /* slot 75 */
    AvnHResult (AVN_CALL *get_is_expanded)(IAvnTreeViewItem* self, int32_t* value); /* slot 76 */
    AvnHResult (AVN_CALL *set_is_expanded)(IAvnTreeViewItem* self, int32_t value); /* slot 77 */
    AvnHResult (AVN_CALL *get_is_selected)(IAvnTreeViewItem* self, int32_t* value); /* slot 78 */
    AvnHResult (AVN_CALL *set_is_selected)(IAvnTreeViewItem* self, int32_t value); /* slot 79 */
    AvnHResult (AVN_CALL *get_level)(IAvnTreeViewItem* self, int32_t* value); /* slot 80 */
    AvnHResult (AVN_CALL *advise_expanded)(IAvnTreeViewItem* self, IAvnTreeViewItemExpandedHandler* handler, int64_t* subscription_id); /* slot 81 */
    AvnHResult (AVN_CALL *unadvise_expanded)(IAvnTreeViewItem* self, int64_t subscription_id); /* slot 82 */
    AvnHResult (AVN_CALL *advise_collapsed)(IAvnTreeViewItem* self, IAvnTreeViewItemCollapsedHandler* handler, int64_t* subscription_id); /* slot 83 */
    AvnHResult (AVN_CALL *unadvise_collapsed)(IAvnTreeViewItem* self, int64_t subscription_id); /* slot 84 */
};
struct IAvnTreeViewItem { const IAvnTreeViewItemVtbl* vtbl; };
#define I_AVN_TREE_VIEW_ITEM_VTABLE_SLOTS 85

static const AvnGuid I_AVN_UNIFORM_GRID_IID = {
    0x12DD4BFC,
    0x89D8,
    0x571D,
    { 0x95, 0xC1, 0xE9, 0x83, 0xF9, 0xDD, 0xFB, 0x88 }
};
#define I_AVN_UNIFORM_GRID_ABI_VERSION 2
struct IAvnUniformGridVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnUniformGrid* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnUniformGrid* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnUniformGrid* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnUniformGrid* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnUniformGrid* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnUniformGrid* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnUniformGrid* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnUniformGrid* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnUniformGrid* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnUniformGrid* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnUniformGrid* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnUniformGrid* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnUniformGrid* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnUniformGrid* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnUniformGrid* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnUniformGrid* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnUniformGrid* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnUniformGrid* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnUniformGrid* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnUniformGrid* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnUniformGrid* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnUniformGrid* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnUniformGrid* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnUniformGrid* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnUniformGrid* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnUniformGrid* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnUniformGrid* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnUniformGrid* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnUniformGrid* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnUniformGrid* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnUniformGrid* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnUniformGrid* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnUniformGrid* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnUniformGrid* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnUniformGrid* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnUniformGrid* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnUniformGrid* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnUniformGrid* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnUniformGrid* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnUniformGrid* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnUniformGrid* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnUniformGrid* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnUniformGrid* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnUniformGrid* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnUniformGrid* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnUniformGrid* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnUniformGrid* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_children)(IAvnUniformGrid* self, IAvnControlList** value); /* slot 47 */
    AvnHResult (AVN_CALL *get_background)(IAvnUniformGrid* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_background)(IAvnUniformGrid* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_rows)(IAvnUniformGrid* self, int32_t* value); /* slot 50 */
    AvnHResult (AVN_CALL *set_rows)(IAvnUniformGrid* self, int32_t value); /* slot 51 */
    AvnHResult (AVN_CALL *get_columns)(IAvnUniformGrid* self, int32_t* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_columns)(IAvnUniformGrid* self, int32_t value); /* slot 53 */
    AvnHResult (AVN_CALL *get_first_column)(IAvnUniformGrid* self, int32_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_first_column)(IAvnUniformGrid* self, int32_t value); /* slot 55 */
    AvnHResult (AVN_CALL *get_row_spacing)(IAvnUniformGrid* self, double* value); /* slot 56 */
    AvnHResult (AVN_CALL *set_row_spacing)(IAvnUniformGrid* self, double value); /* slot 57 */
    AvnHResult (AVN_CALL *get_column_spacing)(IAvnUniformGrid* self, double* value); /* slot 58 */
    AvnHResult (AVN_CALL *set_column_spacing)(IAvnUniformGrid* self, double value); /* slot 59 */
};
struct IAvnUniformGrid { const IAvnUniformGridVtbl* vtbl; };
#define I_AVN_UNIFORM_GRID_VTABLE_SLOTS 60

static const AvnGuid I_AVN_USER_CONTROL_IID = {
    0xB61B153D,
    0xEC8B,
    0x54C4,
    { 0x87, 0xBA, 0x28, 0x3F, 0xD7, 0xCC, 0xF9, 0xEB }
};
#define I_AVN_USER_CONTROL_ABI_VERSION 3
struct IAvnUserControlVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnUserControl* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnUserControl* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnUserControl* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnUserControl* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnUserControl* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnUserControl* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnUserControl* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnUserControl* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnUserControl* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnUserControl* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnUserControl* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnUserControl* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnUserControl* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnUserControl* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnUserControl* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnUserControl* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnUserControl* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnUserControl* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnUserControl* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnUserControl* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnUserControl* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnUserControl* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnUserControl* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnUserControl* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnUserControl* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnUserControl* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnUserControl* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnUserControl* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnUserControl* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnUserControl* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnUserControl* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnUserControl* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnUserControl* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnUserControl* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnUserControl* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnUserControl* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnUserControl* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnUserControl* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnUserControl* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnUserControl* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnUserControl* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnUserControl* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnUserControl* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnUserControl* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnUserControl* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnUserControl* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnUserControl* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnUserControl* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnUserControl* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnUserControl* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnUserControl* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnUserControl* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnUserControl* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnUserControl* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnUserControl* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnUserControl* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnUserControl* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnUserControl* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnUserControl* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnUserControl* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnUserControl* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnUserControl* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnUserControl* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnUserControl* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnUserControl* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnUserControl* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnUserControl* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnUserControl* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnUserControl* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnUserControl* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnUserControl* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnUserControl* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnUserControl* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnUserControl* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnUserControl* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnUserControl* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnUserControl* self, int32_t value); /* slot 76 */
};
struct IAvnUserControl { const IAvnUserControlVtbl* vtbl; };
#define I_AVN_USER_CONTROL_VTABLE_SLOTS 77

static const AvnGuid I_AVN_VIEWBOX_IID = {
    0xCDC2A914,
    0x1F29,
    0x5A49,
    { 0xB1, 0xDE, 0x16, 0xB3, 0x44, 0x07, 0xE2, 0x70 }
};
#define I_AVN_VIEWBOX_ABI_VERSION 2
struct IAvnViewboxVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnViewbox* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnViewbox* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnViewbox* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnViewbox* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnViewbox* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnViewbox* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnViewbox* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnViewbox* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnViewbox* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnViewbox* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnViewbox* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnViewbox* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnViewbox* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnViewbox* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnViewbox* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnViewbox* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnViewbox* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnViewbox* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnViewbox* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnViewbox* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnViewbox* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnViewbox* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnViewbox* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnViewbox* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnViewbox* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnViewbox* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnViewbox* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnViewbox* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnViewbox* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnViewbox* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnViewbox* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnViewbox* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnViewbox* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnViewbox* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnViewbox* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnViewbox* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnViewbox* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnViewbox* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnViewbox* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnViewbox* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnViewbox* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnViewbox* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnViewbox* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnViewbox* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnViewbox* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnViewbox* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnViewbox* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_stretch)(IAvnViewbox* self, int32_t* value); /* slot 47 */
    AvnHResult (AVN_CALL *set_stretch)(IAvnViewbox* self, int32_t value); /* slot 48 */
    AvnHResult (AVN_CALL *get_stretch_direction)(IAvnViewbox* self, int32_t* value); /* slot 49 */
    AvnHResult (AVN_CALL *set_stretch_direction)(IAvnViewbox* self, int32_t value); /* slot 50 */
    AvnHResult (AVN_CALL *get_child)(IAvnViewbox* self, IAvnControl** value); /* slot 51 */
    AvnHResult (AVN_CALL *set_child)(IAvnViewbox* self, IAvnControl* value); /* slot 52 */
};
struct IAvnViewbox { const IAvnViewboxVtbl* vtbl; };
#define I_AVN_VIEWBOX_VTABLE_SLOTS 53

static const AvnGuid I_AVN_WINDOW_IID = {
    0xF5E5AEB8,
    0xFB6D,
    0x5AF1,
    { 0xAE, 0x35, 0x33, 0xB4, 0x1F, 0xC6, 0xFC, 0xF1 }
};
#define I_AVN_WINDOW_ABI_VERSION 10
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
    AvnHResult (AVN_CALL *get_context_menu)(IAvnWindow* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnWindow* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnWindow* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnWindow* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnWindow* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnWindow* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnWindow* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnWindow* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnWindow* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnWindow* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnWindow* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnWindow* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnWindow* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnWindow* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnWindow* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnWindow* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnWindow* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnWindow* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnWindow* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnWindow* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnWindow* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnWindow* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnWindow* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnWindow* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnWindow* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnWindow* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnWindow* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnWindow* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnWindow* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnWindow* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnWindow* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnWindow* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnWindow* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnWindow* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnWindow* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnWindow* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnWindow* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnWindow* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnWindow* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnWindow* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnWindow* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnWindow* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnWindow* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnWindow* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnWindow* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnWindow* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnWindow* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnWindow* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnWindow* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnWindow* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnWindow* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnWindow* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnWindow* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnWindow* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnWindow* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnWindow* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnWindow* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnWindow* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnWindow* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_content)(IAvnWindow* self, IAvnControl** value); /* slot 71 */
    AvnHResult (AVN_CALL *set_content)(IAvnWindow* self, IAvnControl* value); /* slot 72 */
    AvnHResult (AVN_CALL *get_horizontal_content_alignment)(IAvnWindow* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_horizontal_content_alignment)(IAvnWindow* self, int32_t value); /* slot 74 */
    AvnHResult (AVN_CALL *get_vertical_content_alignment)(IAvnWindow* self, int32_t* value); /* slot 75 */
    AvnHResult (AVN_CALL *set_vertical_content_alignment)(IAvnWindow* self, int32_t value); /* slot 76 */
    AvnHResult (AVN_CALL *get_size_to_content)(IAvnWindow* self, int32_t* value); /* slot 77 */
    AvnHResult (AVN_CALL *set_size_to_content)(IAvnWindow* self, int32_t value); /* slot 78 */
    AvnHResult (AVN_CALL *get_title)(IAvnWindow* self, uint16_t** value); /* slot 79 */
    AvnHResult (AVN_CALL *set_title)(IAvnWindow* self, const uint16_t* value); /* slot 80 */
    AvnHResult (AVN_CALL *get_extend_client_area_to_decorations_hint)(IAvnWindow* self, int32_t* value); /* slot 81 */
    AvnHResult (AVN_CALL *set_extend_client_area_to_decorations_hint)(IAvnWindow* self, int32_t value); /* slot 82 */
    AvnHResult (AVN_CALL *get_extend_client_area_title_bar_height_hint)(IAvnWindow* self, double* value); /* slot 83 */
    AvnHResult (AVN_CALL *set_extend_client_area_title_bar_height_hint)(IAvnWindow* self, double value); /* slot 84 */
    AvnHResult (AVN_CALL *get_is_extended_into_window_decorations)(IAvnWindow* self, int32_t* value); /* slot 85 */
    AvnHResult (AVN_CALL *get_window_decoration_margin)(IAvnWindow* self, AvnThickness* value); /* slot 86 */
    AvnHResult (AVN_CALL *get_off_screen_margin)(IAvnWindow* self, AvnThickness* value); /* slot 87 */
    AvnHResult (AVN_CALL *get_window_decorations)(IAvnWindow* self, int32_t* value); /* slot 88 */
    AvnHResult (AVN_CALL *set_window_decorations)(IAvnWindow* self, int32_t value); /* slot 89 */
    AvnHResult (AVN_CALL *get_show_activated)(IAvnWindow* self, int32_t* value); /* slot 90 */
    AvnHResult (AVN_CALL *set_show_activated)(IAvnWindow* self, int32_t value); /* slot 91 */
    AvnHResult (AVN_CALL *get_show_in_taskbar)(IAvnWindow* self, int32_t* value); /* slot 92 */
    AvnHResult (AVN_CALL *set_show_in_taskbar)(IAvnWindow* self, int32_t value); /* slot 93 */
    AvnHResult (AVN_CALL *get_closing_behavior)(IAvnWindow* self, int32_t* value); /* slot 94 */
    AvnHResult (AVN_CALL *set_closing_behavior)(IAvnWindow* self, int32_t value); /* slot 95 */
    AvnHResult (AVN_CALL *get_window_state)(IAvnWindow* self, int32_t* value); /* slot 96 */
    AvnHResult (AVN_CALL *set_window_state)(IAvnWindow* self, int32_t value); /* slot 97 */
    AvnHResult (AVN_CALL *get_can_resize)(IAvnWindow* self, int32_t* value); /* slot 98 */
    AvnHResult (AVN_CALL *set_can_resize)(IAvnWindow* self, int32_t value); /* slot 99 */
    AvnHResult (AVN_CALL *get_can_minimize)(IAvnWindow* self, int32_t* value); /* slot 100 */
    AvnHResult (AVN_CALL *set_can_minimize)(IAvnWindow* self, int32_t value); /* slot 101 */
    AvnHResult (AVN_CALL *get_can_maximize)(IAvnWindow* self, int32_t* value); /* slot 102 */
    AvnHResult (AVN_CALL *set_can_maximize)(IAvnWindow* self, int32_t value); /* slot 103 */
    AvnHResult (AVN_CALL *get_window_startup_location)(IAvnWindow* self, int32_t* value); /* slot 104 */
    AvnHResult (AVN_CALL *set_window_startup_location)(IAvnWindow* self, int32_t value); /* slot 105 */
    AvnHResult (AVN_CALL *get_is_dialog)(IAvnWindow* self, int32_t* value); /* slot 106 */
    AvnHResult (AVN_CALL *close)(IAvnWindow* self); /* slot 107 */
    AvnHResult (AVN_CALL *hide)(IAvnWindow* self); /* slot 108 */
    AvnHResult (AVN_CALL *show)(IAvnWindow* self); /* slot 109 */
    AvnHResult (AVN_CALL *show_with_window)(IAvnWindow* self, IAvnWindow* owner); /* slot 110 */
    AvnHResult (AVN_CALL *advise_closing)(IAvnWindow* self, IAvnWindowClosingHandler* handler, int64_t* subscription_id); /* slot 111 */
    AvnHResult (AVN_CALL *unadvise_closing)(IAvnWindow* self, int64_t subscription_id); /* slot 112 */
};
struct IAvnWindow { const IAvnWindowVtbl* vtbl; };
#define I_AVN_WINDOW_VTABLE_SLOTS 113

static const AvnGuid I_AVN_WINDOW_NOTIFICATION_MANAGER_IID = {
    0x4F5B9E71,
    0x475C,
    0x5297,
    { 0x89, 0xDE, 0x55, 0xE0, 0x79, 0xBB, 0xF4, 0xD9 }
};
#define I_AVN_WINDOW_NOTIFICATION_MANAGER_ABI_VERSION 3
struct IAvnWindowNotificationManagerVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnWindowNotificationManager* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnWindowNotificationManager* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnWindowNotificationManager* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnWindowNotificationManager* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnWindowNotificationManager* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnWindowNotificationManager* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnWindowNotificationManager* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnWindowNotificationManager* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnWindowNotificationManager* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnWindowNotificationManager* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnWindowNotificationManager* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnWindowNotificationManager* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnWindowNotificationManager* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnWindowNotificationManager* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnWindowNotificationManager* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnWindowNotificationManager* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnWindowNotificationManager* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnWindowNotificationManager* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnWindowNotificationManager* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnWindowNotificationManager* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnWindowNotificationManager* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnWindowNotificationManager* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnWindowNotificationManager* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnWindowNotificationManager* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnWindowNotificationManager* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnWindowNotificationManager* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnWindowNotificationManager* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnWindowNotificationManager* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnWindowNotificationManager* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnWindowNotificationManager* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnWindowNotificationManager* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnWindowNotificationManager* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnWindowNotificationManager* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnWindowNotificationManager* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnWindowNotificationManager* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnWindowNotificationManager* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnWindowNotificationManager* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnWindowNotificationManager* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnWindowNotificationManager* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnWindowNotificationManager* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnWindowNotificationManager* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnWindowNotificationManager* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnWindowNotificationManager* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnWindowNotificationManager* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnWindowNotificationManager* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnWindowNotificationManager* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnWindowNotificationManager* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_background)(IAvnWindowNotificationManager* self, IAvnBrush** value); /* slot 47 */
    AvnHResult (AVN_CALL *set_background)(IAvnWindowNotificationManager* self, IAvnBrush* value); /* slot 48 */
    AvnHResult (AVN_CALL *get_border_brush)(IAvnWindowNotificationManager* self, IAvnBrush** value); /* slot 49 */
    AvnHResult (AVN_CALL *set_border_brush)(IAvnWindowNotificationManager* self, IAvnBrush* value); /* slot 50 */
    AvnHResult (AVN_CALL *get_border_thickness)(IAvnWindowNotificationManager* self, AvnThickness* value); /* slot 51 */
    AvnHResult (AVN_CALL *set_border_thickness)(IAvnWindowNotificationManager* self, AvnThickness value); /* slot 52 */
    AvnHResult (AVN_CALL *get_corner_radius)(IAvnWindowNotificationManager* self, AvnCornerRadius* value); /* slot 53 */
    AvnHResult (AVN_CALL *set_corner_radius)(IAvnWindowNotificationManager* self, AvnCornerRadius value); /* slot 54 */
    AvnHResult (AVN_CALL *get_font_family)(IAvnWindowNotificationManager* self, uint16_t** value); /* slot 55 */
    AvnHResult (AVN_CALL *set_font_family)(IAvnWindowNotificationManager* self, const uint16_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *get_font_size)(IAvnWindowNotificationManager* self, double* value); /* slot 57 */
    AvnHResult (AVN_CALL *set_font_size)(IAvnWindowNotificationManager* self, double value); /* slot 58 */
    AvnHResult (AVN_CALL *get_font_style)(IAvnWindowNotificationManager* self, int32_t* value); /* slot 59 */
    AvnHResult (AVN_CALL *set_font_style)(IAvnWindowNotificationManager* self, int32_t value); /* slot 60 */
    AvnHResult (AVN_CALL *get_font_weight)(IAvnWindowNotificationManager* self, int32_t* value); /* slot 61 */
    AvnHResult (AVN_CALL *set_font_weight)(IAvnWindowNotificationManager* self, int32_t value); /* slot 62 */
    AvnHResult (AVN_CALL *get_font_stretch)(IAvnWindowNotificationManager* self, int32_t* value); /* slot 63 */
    AvnHResult (AVN_CALL *set_font_stretch)(IAvnWindowNotificationManager* self, int32_t value); /* slot 64 */
    AvnHResult (AVN_CALL *get_foreground)(IAvnWindowNotificationManager* self, IAvnBrush** value); /* slot 65 */
    AvnHResult (AVN_CALL *set_foreground)(IAvnWindowNotificationManager* self, IAvnBrush* value); /* slot 66 */
    AvnHResult (AVN_CALL *get_letter_spacing)(IAvnWindowNotificationManager* self, double* value); /* slot 67 */
    AvnHResult (AVN_CALL *set_letter_spacing)(IAvnWindowNotificationManager* self, double value); /* slot 68 */
    AvnHResult (AVN_CALL *get_padding)(IAvnWindowNotificationManager* self, AvnThickness* value); /* slot 69 */
    AvnHResult (AVN_CALL *set_padding)(IAvnWindowNotificationManager* self, AvnThickness value); /* slot 70 */
    AvnHResult (AVN_CALL *get_position)(IAvnWindowNotificationManager* self, int32_t* value); /* slot 71 */
    AvnHResult (AVN_CALL *set_position)(IAvnWindowNotificationManager* self, int32_t value); /* slot 72 */
    AvnHResult (AVN_CALL *get_max_items)(IAvnWindowNotificationManager* self, int32_t* value); /* slot 73 */
    AvnHResult (AVN_CALL *set_max_items)(IAvnWindowNotificationManager* self, int32_t value); /* slot 74 */
};
struct IAvnWindowNotificationManager { const IAvnWindowNotificationManagerVtbl* vtbl; };
#define I_AVN_WINDOW_NOTIFICATION_MANAGER_VTABLE_SLOTS 75

static const AvnGuid I_AVN_WRAP_PANEL_IID = {
    0x62F0588C,
    0x31F3,
    0x59FA,
    { 0xBF, 0xE6, 0x0D, 0x38, 0x09, 0xF8, 0x39, 0x70 }
};
#define I_AVN_WRAP_PANEL_ABI_VERSION 2
struct IAvnWrapPanelVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnWrapPanel* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnWrapPanel* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnWrapPanel* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_object_id)(IAvnWrapPanel* self, int64_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *get_lifetime_token)(IAvnWrapPanel* self, int64_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_name)(IAvnWrapPanel* self, uint16_t** value); /* slot 5 */
    AvnHResult (AVN_CALL *set_name)(IAvnWrapPanel* self, const uint16_t* value); /* slot 6 */
    AvnHResult (AVN_CALL *get_classes)(IAvnWrapPanel* self, IAvnStringList** value); /* slot 7 */
    AvnHResult (AVN_CALL *get_is_visible)(IAvnWrapPanel* self, int32_t* value); /* slot 8 */
    AvnHResult (AVN_CALL *set_is_visible)(IAvnWrapPanel* self, int32_t value); /* slot 9 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnWrapPanel* self, double* value); /* slot 10 */
    AvnHResult (AVN_CALL *set_opacity)(IAvnWrapPanel* self, double value); /* slot 11 */
    AvnHResult (AVN_CALL *get_context_menu)(IAvnWrapPanel* self, IAvnContextMenu** value); /* slot 12 */
    AvnHResult (AVN_CALL *set_context_menu)(IAvnWrapPanel* self, IAvnContextMenu* value); /* slot 13 */
    AvnHResult (AVN_CALL *get_context_flyout)(IAvnWrapPanel* self, IAvnFlyoutBase** value); /* slot 14 */
    AvnHResult (AVN_CALL *set_context_flyout)(IAvnWrapPanel* self, IAvnFlyoutBase* value); /* slot 15 */
    AvnHResult (AVN_CALL *get_is_loaded)(IAvnWrapPanel* self, int32_t* value); /* slot 16 */
    AvnHResult (AVN_CALL *get_width)(IAvnWrapPanel* self, double* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_width)(IAvnWrapPanel* self, double value); /* slot 18 */
    AvnHResult (AVN_CALL *get_height)(IAvnWrapPanel* self, double* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_height)(IAvnWrapPanel* self, double value); /* slot 20 */
    AvnHResult (AVN_CALL *get_min_width)(IAvnWrapPanel* self, double* value); /* slot 21 */
    AvnHResult (AVN_CALL *set_min_width)(IAvnWrapPanel* self, double value); /* slot 22 */
    AvnHResult (AVN_CALL *get_max_width)(IAvnWrapPanel* self, double* value); /* slot 23 */
    AvnHResult (AVN_CALL *set_max_width)(IAvnWrapPanel* self, double value); /* slot 24 */
    AvnHResult (AVN_CALL *get_min_height)(IAvnWrapPanel* self, double* value); /* slot 25 */
    AvnHResult (AVN_CALL *set_min_height)(IAvnWrapPanel* self, double value); /* slot 26 */
    AvnHResult (AVN_CALL *get_max_height)(IAvnWrapPanel* self, double* value); /* slot 27 */
    AvnHResult (AVN_CALL *set_max_height)(IAvnWrapPanel* self, double value); /* slot 28 */
    AvnHResult (AVN_CALL *get_margin)(IAvnWrapPanel* self, AvnThickness* value); /* slot 29 */
    AvnHResult (AVN_CALL *set_margin)(IAvnWrapPanel* self, AvnThickness value); /* slot 30 */
    AvnHResult (AVN_CALL *get_horizontal_alignment)(IAvnWrapPanel* self, int32_t* value); /* slot 31 */
    AvnHResult (AVN_CALL *set_horizontal_alignment)(IAvnWrapPanel* self, int32_t value); /* slot 32 */
    AvnHResult (AVN_CALL *get_vertical_alignment)(IAvnWrapPanel* self, int32_t* value); /* slot 33 */
    AvnHResult (AVN_CALL *set_vertical_alignment)(IAvnWrapPanel* self, int32_t value); /* slot 34 */
    AvnHResult (AVN_CALL *get_is_enabled)(IAvnWrapPanel* self, int32_t* value); /* slot 35 */
    AvnHResult (AVN_CALL *set_is_enabled)(IAvnWrapPanel* self, int32_t value); /* slot 36 */
    AvnHResult (AVN_CALL *advise_loaded)(IAvnWrapPanel* self, IAvnControlLoadedHandler* handler, int64_t* subscription_id); /* slot 37 */
    AvnHResult (AVN_CALL *unadvise_loaded)(IAvnWrapPanel* self, int64_t subscription_id); /* slot 38 */
    AvnHResult (AVN_CALL *advise_unloaded)(IAvnWrapPanel* self, IAvnControlUnloadedHandler* handler, int64_t* subscription_id); /* slot 39 */
    AvnHResult (AVN_CALL *unadvise_unloaded)(IAvnWrapPanel* self, int64_t subscription_id); /* slot 40 */
    AvnHResult (AVN_CALL *advise_key_down)(IAvnWrapPanel* self, IAvnControlKeyDownHandler* handler, int64_t* subscription_id); /* slot 41 */
    AvnHResult (AVN_CALL *unadvise_key_down)(IAvnWrapPanel* self, int64_t subscription_id); /* slot 42 */
    AvnHResult (AVN_CALL *advise_pointer_entered)(IAvnWrapPanel* self, IAvnControlPointerEnteredHandler* handler, int64_t* subscription_id); /* slot 43 */
    AvnHResult (AVN_CALL *unadvise_pointer_entered)(IAvnWrapPanel* self, int64_t subscription_id); /* slot 44 */
    AvnHResult (AVN_CALL *advise_pointer_exited)(IAvnWrapPanel* self, IAvnControlPointerExitedHandler* handler, int64_t* subscription_id); /* slot 45 */
    AvnHResult (AVN_CALL *unadvise_pointer_exited)(IAvnWrapPanel* self, int64_t subscription_id); /* slot 46 */
    AvnHResult (AVN_CALL *get_children)(IAvnWrapPanel* self, IAvnControlList** value); /* slot 47 */
    AvnHResult (AVN_CALL *get_background)(IAvnWrapPanel* self, IAvnBrush** value); /* slot 48 */
    AvnHResult (AVN_CALL *set_background)(IAvnWrapPanel* self, IAvnBrush* value); /* slot 49 */
    AvnHResult (AVN_CALL *get_item_spacing)(IAvnWrapPanel* self, double* value); /* slot 50 */
    AvnHResult (AVN_CALL *set_item_spacing)(IAvnWrapPanel* self, double value); /* slot 51 */
    AvnHResult (AVN_CALL *get_line_spacing)(IAvnWrapPanel* self, double* value); /* slot 52 */
    AvnHResult (AVN_CALL *set_line_spacing)(IAvnWrapPanel* self, double value); /* slot 53 */
    AvnHResult (AVN_CALL *get_orientation)(IAvnWrapPanel* self, int32_t* value); /* slot 54 */
    AvnHResult (AVN_CALL *set_orientation)(IAvnWrapPanel* self, int32_t value); /* slot 55 */
    AvnHResult (AVN_CALL *get_items_alignment)(IAvnWrapPanel* self, int32_t* value); /* slot 56 */
    AvnHResult (AVN_CALL *set_items_alignment)(IAvnWrapPanel* self, int32_t value); /* slot 57 */
    AvnHResult (AVN_CALL *get_item_width)(IAvnWrapPanel* self, double* value); /* slot 58 */
    AvnHResult (AVN_CALL *set_item_width)(IAvnWrapPanel* self, double value); /* slot 59 */
    AvnHResult (AVN_CALL *get_item_height)(IAvnWrapPanel* self, double* value); /* slot 60 */
    AvnHResult (AVN_CALL *set_item_height)(IAvnWrapPanel* self, double value); /* slot 61 */
};
struct IAvnWrapPanel { const IAvnWrapPanelVtbl* vtbl; };
#define I_AVN_WRAP_PANEL_VTABLE_SLOTS 62

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

static const AvnGuid I_AVN_RELATIVE_PANEL_STATICS_IID = {
    0xB4F946D3,
    0xE062,
    0x52AB,
    { 0xA2, 0x80, 0xC2, 0x90, 0x4E, 0xC2, 0x8F, 0xE8 }
};
#define I_AVN_RELATIVE_PANEL_STATICS_ABI_VERSION 1
struct IAvnRelativePanelStaticsVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnRelativePanelStatics* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnRelativePanelStatics* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnRelativePanelStatics* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_align_left_with_panel)(IAvnRelativePanelStatics* self, IAvnControl* target, int32_t* value); /* slot 3 */
    AvnHResult (AVN_CALL *set_align_left_with_panel)(IAvnRelativePanelStatics* self, IAvnControl* target, int32_t value); /* slot 4 */
    AvnHResult (AVN_CALL *get_align_right_with_panel)(IAvnRelativePanelStatics* self, IAvnControl* target, int32_t* value); /* slot 5 */
    AvnHResult (AVN_CALL *set_align_right_with_panel)(IAvnRelativePanelStatics* self, IAvnControl* target, int32_t value); /* slot 6 */
    AvnHResult (AVN_CALL *get_align_top_with_panel)(IAvnRelativePanelStatics* self, IAvnControl* target, int32_t* value); /* slot 7 */
    AvnHResult (AVN_CALL *set_align_top_with_panel)(IAvnRelativePanelStatics* self, IAvnControl* target, int32_t value); /* slot 8 */
    AvnHResult (AVN_CALL *get_align_bottom_with_panel)(IAvnRelativePanelStatics* self, IAvnControl* target, int32_t* value); /* slot 9 */
    AvnHResult (AVN_CALL *set_align_bottom_with_panel)(IAvnRelativePanelStatics* self, IAvnControl* target, int32_t value); /* slot 10 */
    AvnHResult (AVN_CALL *get_align_horizontal_center_with_panel)(IAvnRelativePanelStatics* self, IAvnControl* target, int32_t* value); /* slot 11 */
    AvnHResult (AVN_CALL *set_align_horizontal_center_with_panel)(IAvnRelativePanelStatics* self, IAvnControl* target, int32_t value); /* slot 12 */
    AvnHResult (AVN_CALL *get_align_vertical_center_with_panel)(IAvnRelativePanelStatics* self, IAvnControl* target, int32_t* value); /* slot 13 */
    AvnHResult (AVN_CALL *set_align_vertical_center_with_panel)(IAvnRelativePanelStatics* self, IAvnControl* target, int32_t value); /* slot 14 */
};
struct IAvnRelativePanelStatics { const IAvnRelativePanelStaticsVtbl* vtbl; };
#define I_AVN_RELATIVE_PANEL_STATICS_VTABLE_SLOTS 15

static const AvnGuid I_AVN_TOOL_TIP_STATICS_IID = {
    0x32697945,
    0x82A7,
    0x51F1,
    { 0xAC, 0x6A, 0x67, 0x92, 0x95, 0x8F, 0x17, 0x59 }
};
#define I_AVN_TOOL_TIP_STATICS_ABI_VERSION 1
struct IAvnToolTipStaticsVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnToolTipStatics* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnToolTipStatics* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnToolTipStatics* self); /* slot 2 */
    AvnHResult (AVN_CALL *get_tip)(IAvnToolTipStatics* self, IAvnControl* target, uint16_t** value); /* slot 3 */
    AvnHResult (AVN_CALL *set_tip)(IAvnToolTipStatics* self, IAvnControl* target, const uint16_t* value); /* slot 4 */
    AvnHResult (AVN_CALL *get_is_open)(IAvnToolTipStatics* self, IAvnControl* target, int32_t* value); /* slot 5 */
    AvnHResult (AVN_CALL *set_is_open)(IAvnToolTipStatics* self, IAvnControl* target, int32_t value); /* slot 6 */
    AvnHResult (AVN_CALL *get_placement)(IAvnToolTipStatics* self, IAvnControl* target, int32_t* value); /* slot 7 */
    AvnHResult (AVN_CALL *set_placement)(IAvnToolTipStatics* self, IAvnControl* target, int32_t value); /* slot 8 */
    AvnHResult (AVN_CALL *get_horizontal_offset)(IAvnToolTipStatics* self, IAvnControl* target, double* value); /* slot 9 */
    AvnHResult (AVN_CALL *set_horizontal_offset)(IAvnToolTipStatics* self, IAvnControl* target, double value); /* slot 10 */
    AvnHResult (AVN_CALL *get_vertical_offset)(IAvnToolTipStatics* self, IAvnControl* target, double* value); /* slot 11 */
    AvnHResult (AVN_CALL *set_vertical_offset)(IAvnToolTipStatics* self, IAvnControl* target, double value); /* slot 12 */
    AvnHResult (AVN_CALL *get_show_delay)(IAvnToolTipStatics* self, IAvnControl* target, int32_t* value); /* slot 13 */
    AvnHResult (AVN_CALL *set_show_delay)(IAvnToolTipStatics* self, IAvnControl* target, int32_t value); /* slot 14 */
    AvnHResult (AVN_CALL *get_between_show_delay)(IAvnToolTipStatics* self, IAvnControl* target, int32_t* value); /* slot 15 */
    AvnHResult (AVN_CALL *set_between_show_delay)(IAvnToolTipStatics* self, IAvnControl* target, int32_t value); /* slot 16 */
    AvnHResult (AVN_CALL *get_show_on_disabled)(IAvnToolTipStatics* self, IAvnControl* target, int32_t* value); /* slot 17 */
    AvnHResult (AVN_CALL *set_show_on_disabled)(IAvnToolTipStatics* self, IAvnControl* target, int32_t value); /* slot 18 */
    AvnHResult (AVN_CALL *get_service_enabled)(IAvnToolTipStatics* self, IAvnControl* target, int32_t* value); /* slot 19 */
    AvnHResult (AVN_CALL *set_service_enabled)(IAvnToolTipStatics* self, IAvnControl* target, int32_t value); /* slot 20 */
};
struct IAvnToolTipStatics { const IAvnToolTipStaticsVtbl* vtbl; };
#define I_AVN_TOOL_TIP_STATICS_VTABLE_SLOTS 21

static const AvnGuid I_AVN_CONTROL_FACTORY_IID = {
    0x15778134,
    0x9E9F,
    0x5BAF,
    { 0x98, 0xFF, 0x55, 0x10, 0x77, 0x80, 0x94, 0xBA }
};
#define I_AVN_CONTROL_FACTORY_ABI_VERSION 13
struct IAvnControlFactoryVtbl {
    AvnHResult (AVN_CALL *query_interface)(IAvnControlFactory* self, const AvnGuid* iid, void** result); /* slot 0 */
    uint32_t (AVN_CALL *add_ref)(IAvnControlFactory* self); /* slot 1 */
    uint32_t (AVN_CALL *release)(IAvnControlFactory* self); /* slot 2 */
    AvnHResult (AVN_CALL *create_arc)(IAvnControlFactory* self, IAvnArc** value); /* slot 3 */
    AvnHResult (AVN_CALL *create_auto_complete_box)(IAvnControlFactory* self, IAvnAutoCompleteBox** value); /* slot 4 */
    AvnHResult (AVN_CALL *create_avalonia_object)(IAvnControlFactory* self, IAvnAvaloniaObject** value); /* slot 5 */
    AvnHResult (AVN_CALL *create_border)(IAvnControlFactory* self, IAvnBorder** value); /* slot 6 */
    AvnHResult (AVN_CALL *create_button)(IAvnControlFactory* self, IAvnButton** value); /* slot 7 */
    AvnHResult (AVN_CALL *create_button_spinner)(IAvnControlFactory* self, IAvnButtonSpinner** value); /* slot 8 */
    AvnHResult (AVN_CALL *create_calendar)(IAvnControlFactory* self, IAvnCalendar** value); /* slot 9 */
    AvnHResult (AVN_CALL *create_calendar_date_picker)(IAvnControlFactory* self, IAvnCalendarDatePicker** value); /* slot 10 */
    AvnHResult (AVN_CALL *create_canvas)(IAvnControlFactory* self, IAvnCanvas** value); /* slot 11 */
    AvnHResult (AVN_CALL *create_carousel)(IAvnControlFactory* self, IAvnCarousel** value); /* slot 12 */
    AvnHResult (AVN_CALL *create_check_box)(IAvnControlFactory* self, IAvnCheckBox** value); /* slot 13 */
    AvnHResult (AVN_CALL *create_combo_box)(IAvnControlFactory* self, IAvnComboBox** value); /* slot 14 */
    AvnHResult (AVN_CALL *create_combo_box_item)(IAvnControlFactory* self, IAvnComboBoxItem** value); /* slot 15 */
    AvnHResult (AVN_CALL *create_command_bar)(IAvnControlFactory* self, IAvnCommandBar** value); /* slot 16 */
    AvnHResult (AVN_CALL *create_command_bar_button)(IAvnControlFactory* self, IAvnCommandBarButton** value); /* slot 17 */
    AvnHResult (AVN_CALL *create_command_bar_separator)(IAvnControlFactory* self, IAvnCommandBarSeparator** value); /* slot 18 */
    AvnHResult (AVN_CALL *create_command_bar_toggle_button)(IAvnControlFactory* self, IAvnCommandBarToggleButton** value); /* slot 19 */
    AvnHResult (AVN_CALL *create_content_control)(IAvnControlFactory* self, IAvnContentControl** value); /* slot 20 */
    AvnHResult (AVN_CALL *create_context_menu)(IAvnControlFactory* self, IAvnContextMenu** value); /* slot 21 */
    AvnHResult (AVN_CALL *create_control)(IAvnControlFactory* self, IAvnControl** value); /* slot 22 */
    AvnHResult (AVN_CALL *create_date_picker)(IAvnControlFactory* self, IAvnDatePicker** value); /* slot 23 */
    AvnHResult (AVN_CALL *create_decorator)(IAvnControlFactory* self, IAvnDecorator** value); /* slot 24 */
    AvnHResult (AVN_CALL *create_dock_panel)(IAvnControlFactory* self, IAvnDockPanel** value); /* slot 25 */
    AvnHResult (AVN_CALL *create_drop_down_button)(IAvnControlFactory* self, IAvnDropDownButton** value); /* slot 26 */
    AvnHResult (AVN_CALL *create_ellipse)(IAvnControlFactory* self, IAvnEllipse** value); /* slot 27 */
    AvnHResult (AVN_CALL *create_expander)(IAvnControlFactory* self, IAvnExpander** value); /* slot 28 */
    AvnHResult (AVN_CALL *create_flex_panel)(IAvnControlFactory* self, IAvnFlexPanel** value); /* slot 29 */
    AvnHResult (AVN_CALL *create_flyout)(IAvnControlFactory* self, IAvnFlyout** value); /* slot 30 */
    AvnHResult (AVN_CALL *create_grid)(IAvnControlFactory* self, IAvnGrid** value); /* slot 31 */
    AvnHResult (AVN_CALL *create_grid_splitter)(IAvnControlFactory* self, IAvnGridSplitter** value); /* slot 32 */
    AvnHResult (AVN_CALL *create_group_box)(IAvnControlFactory* self, IAvnGroupBox** value); /* slot 33 */
    AvnHResult (AVN_CALL *create_headered_content_control)(IAvnControlFactory* self, IAvnHeaderedContentControl** value); /* slot 34 */
    AvnHResult (AVN_CALL *create_headered_items_control)(IAvnControlFactory* self, IAvnHeaderedItemsControl** value); /* slot 35 */
    AvnHResult (AVN_CALL *create_headered_selecting_items_control)(IAvnControlFactory* self, IAvnHeaderedSelectingItemsControl** value); /* slot 36 */
    AvnHResult (AVN_CALL *create_hyperlink_button)(IAvnControlFactory* self, IAvnHyperlinkButton** value); /* slot 37 */
    AvnHResult (AVN_CALL *create_image)(IAvnControlFactory* self, IAvnImage** value); /* slot 38 */
    AvnHResult (AVN_CALL *create_items_control)(IAvnControlFactory* self, IAvnItemsControl** value); /* slot 39 */
    AvnHResult (AVN_CALL *create_label)(IAvnControlFactory* self, IAvnLabel** value); /* slot 40 */
    AvnHResult (AVN_CALL *create_layout_transform_control)(IAvnControlFactory* self, IAvnLayoutTransformControl** value); /* slot 41 */
    AvnHResult (AVN_CALL *create_line)(IAvnControlFactory* self, IAvnLine** value); /* slot 42 */
    AvnHResult (AVN_CALL *create_list_box)(IAvnControlFactory* self, IAvnListBox** value); /* slot 43 */
    AvnHResult (AVN_CALL *create_list_box_item)(IAvnControlFactory* self, IAvnListBoxItem** value); /* slot 44 */
    AvnHResult (AVN_CALL *create_masked_text_box)(IAvnControlFactory* self, IAvnMaskedTextBox** value); /* slot 45 */
    AvnHResult (AVN_CALL *create_menu)(IAvnControlFactory* self, IAvnMenu** value); /* slot 46 */
    AvnHResult (AVN_CALL *create_menu_flyout)(IAvnControlFactory* self, IAvnMenuFlyout** value); /* slot 47 */
    AvnHResult (AVN_CALL *create_menu_item)(IAvnControlFactory* self, IAvnMenuItem** value); /* slot 48 */
    AvnHResult (AVN_CALL *create_notification_card)(IAvnControlFactory* self, IAvnNotificationCard** value); /* slot 49 */
    AvnHResult (AVN_CALL *create_numeric_up_down)(IAvnControlFactory* self, IAvnNumericUpDown** value); /* slot 50 */
    AvnHResult (AVN_CALL *create_panel)(IAvnControlFactory* self, IAvnPanel** value); /* slot 51 */
    AvnHResult (AVN_CALL *create_path)(IAvnControlFactory* self, IAvnPath** value); /* slot 52 */
    AvnHResult (AVN_CALL *create_path_icon)(IAvnControlFactory* self, IAvnPathIcon** value); /* slot 53 */
    AvnHResult (AVN_CALL *create_pips_pager)(IAvnControlFactory* self, IAvnPipsPager** value); /* slot 54 */
    AvnHResult (AVN_CALL *create_polygon)(IAvnControlFactory* self, IAvnPolygon** value); /* slot 55 */
    AvnHResult (AVN_CALL *create_polyline)(IAvnControlFactory* self, IAvnPolyline** value); /* slot 56 */
    AvnHResult (AVN_CALL *create_popup)(IAvnControlFactory* self, IAvnPopup** value); /* slot 57 */
    AvnHResult (AVN_CALL *create_progress_bar)(IAvnControlFactory* self, IAvnProgressBar** value); /* slot 58 */
    AvnHResult (AVN_CALL *create_radio_button)(IAvnControlFactory* self, IAvnRadioButton** value); /* slot 59 */
    AvnHResult (AVN_CALL *create_rectangle)(IAvnControlFactory* self, IAvnRectangle** value); /* slot 60 */
    AvnHResult (AVN_CALL *create_refresh_container)(IAvnControlFactory* self, IAvnRefreshContainer** value); /* slot 61 */
    AvnHResult (AVN_CALL *create_relative_panel)(IAvnControlFactory* self, IAvnRelativePanel** value); /* slot 62 */
    AvnHResult (AVN_CALL *create_repeat_button)(IAvnControlFactory* self, IAvnRepeatButton** value); /* slot 63 */
    AvnHResult (AVN_CALL *create_scroll_viewer)(IAvnControlFactory* self, IAvnScrollViewer** value); /* slot 64 */
    AvnHResult (AVN_CALL *create_sector)(IAvnControlFactory* self, IAvnSector** value); /* slot 65 */
    AvnHResult (AVN_CALL *create_selectable_text_block)(IAvnControlFactory* self, IAvnSelectableTextBlock** value); /* slot 66 */
    AvnHResult (AVN_CALL *create_selecting_items_control)(IAvnControlFactory* self, IAvnSelectingItemsControl** value); /* slot 67 */
    AvnHResult (AVN_CALL *create_separator)(IAvnControlFactory* self, IAvnSeparator** value); /* slot 68 */
    AvnHResult (AVN_CALL *create_slider)(IAvnControlFactory* self, IAvnSlider** value); /* slot 69 */
    AvnHResult (AVN_CALL *create_split_button)(IAvnControlFactory* self, IAvnSplitButton** value); /* slot 70 */
    AvnHResult (AVN_CALL *create_split_view)(IAvnControlFactory* self, IAvnSplitView** value); /* slot 71 */
    AvnHResult (AVN_CALL *create_stack_panel)(IAvnControlFactory* self, IAvnStackPanel** value); /* slot 72 */
    AvnHResult (AVN_CALL *create_styled_element)(IAvnControlFactory* self, IAvnStyledElement** value); /* slot 73 */
    AvnHResult (AVN_CALL *create_tab_control)(IAvnControlFactory* self, IAvnTabControl** value); /* slot 74 */
    AvnHResult (AVN_CALL *create_tab_item)(IAvnControlFactory* self, IAvnTabItem** value); /* slot 75 */
    AvnHResult (AVN_CALL *create_table_view)(IAvnControlFactory* self, IAvnTableView** value); /* slot 76 */
    AvnHResult (AVN_CALL *create_table_view_cell)(IAvnControlFactory* self, IAvnTableViewCell** value); /* slot 77 */
    AvnHResult (AVN_CALL *create_table_view_column)(IAvnControlFactory* self, IAvnTableViewColumn** value); /* slot 78 */
    AvnHResult (AVN_CALL *create_table_view_row)(IAvnControlFactory* self, IAvnTableViewRow** value); /* slot 79 */
    AvnHResult (AVN_CALL *create_templated_control)(IAvnControlFactory* self, IAvnTemplatedControl** value); /* slot 80 */
    AvnHResult (AVN_CALL *create_text_block)(IAvnControlFactory* self, IAvnTextBlock** value); /* slot 81 */
    AvnHResult (AVN_CALL *create_text_box)(IAvnControlFactory* self, IAvnTextBox** value); /* slot 82 */
    AvnHResult (AVN_CALL *create_theme_variant_scope)(IAvnControlFactory* self, IAvnThemeVariantScope** value); /* slot 83 */
    AvnHResult (AVN_CALL *create_thumb)(IAvnControlFactory* self, IAvnThumb** value); /* slot 84 */
    AvnHResult (AVN_CALL *create_time_picker)(IAvnControlFactory* self, IAvnTimePicker** value); /* slot 85 */
    AvnHResult (AVN_CALL *create_toggle_button)(IAvnControlFactory* self, IAvnToggleButton** value); /* slot 86 */
    AvnHResult (AVN_CALL *create_toggle_split_button)(IAvnControlFactory* self, IAvnToggleSplitButton** value); /* slot 87 */
    AvnHResult (AVN_CALL *create_toggle_switch)(IAvnControlFactory* self, IAvnToggleSwitch** value); /* slot 88 */
    AvnHResult (AVN_CALL *create_tool_tip)(IAvnControlFactory* self, IAvnToolTip** value); /* slot 89 */
    AvnHResult (AVN_CALL *create_transitioning_content_control)(IAvnControlFactory* self, IAvnTransitioningContentControl** value); /* slot 90 */
    AvnHResult (AVN_CALL *create_tray_icon)(IAvnControlFactory* self, IAvnTrayIcon** value); /* slot 91 */
    AvnHResult (AVN_CALL *create_tree_view)(IAvnControlFactory* self, IAvnTreeView** value); /* slot 92 */
    AvnHResult (AVN_CALL *create_tree_view_item)(IAvnControlFactory* self, IAvnTreeViewItem** value); /* slot 93 */
    AvnHResult (AVN_CALL *create_uniform_grid)(IAvnControlFactory* self, IAvnUniformGrid** value); /* slot 94 */
    AvnHResult (AVN_CALL *create_user_control)(IAvnControlFactory* self, IAvnUserControl** value); /* slot 95 */
    AvnHResult (AVN_CALL *create_viewbox)(IAvnControlFactory* self, IAvnViewbox** value); /* slot 96 */
    AvnHResult (AVN_CALL *create_window)(IAvnControlFactory* self, IAvnWindow** value); /* slot 97 */
    AvnHResult (AVN_CALL *create_window_notification_manager)(IAvnControlFactory* self, IAvnWindowNotificationManager** value); /* slot 98 */
    AvnHResult (AVN_CALL *create_wrap_panel)(IAvnControlFactory* self, IAvnWrapPanel** value); /* slot 99 */
    AvnHResult (AVN_CALL *get_canvas_statics)(IAvnControlFactory* self, IAvnCanvasStatics** value); /* slot 100 */
    AvnHResult (AVN_CALL *get_dock_panel_statics)(IAvnControlFactory* self, IAvnDockPanelStatics** value); /* slot 101 */
    AvnHResult (AVN_CALL *get_grid_statics)(IAvnControlFactory* self, IAvnGridStatics** value); /* slot 102 */
    AvnHResult (AVN_CALL *get_relative_panel_statics)(IAvnControlFactory* self, IAvnRelativePanelStatics** value); /* slot 103 */
    AvnHResult (AVN_CALL *get_tool_tip_statics)(IAvnControlFactory* self, IAvnToolTipStatics** value); /* slot 104 */
    AvnHResult (AVN_CALL *create_solid_color_brush)(IAvnControlFactory* self, AvnColor color, double opacity, IAvnBrush** value); /* slot 105 */
};
struct IAvnControlFactory { const IAvnControlFactoryVtbl* vtbl; };
#define I_AVN_CONTROL_FACTORY_VTABLE_SLOTS 106

#endif /* AVALONIA_RUST_ABI_H */
