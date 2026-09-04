namespace Avalonia.Projection.Ir;

public static class AvaloniaProjectionProfiles
{
    public static ProjectionPolicy ObjectModelKernel { get; } = new()
    {
        // Waves A and B both add brand-new interfaces and widen no existing one, so every
        // previously published interface keeps the IID it last shipped and the new ones publish
        // at version 1. The default is therefore 1 and every older interface is pinned to the
        // version whose flattened vtable it still matches.
        DefaultProjectedTypeAbiVersion = 1,
        AbiVersions = new Dictionary<string, int>(StringComparer.Ordinal)
        {
            // AvaloniaObject projects no members, so its vtable is byte-identical to
            // version 2. Republishing it under a new IID would be a gratuitous break.
            ["Avalonia.Host.Com.IAvnAvaloniaObject"] = 2,
            // StyledElement is unchanged. Control grows ContextMenu/ContextFlyout/IsLoaded/
            // Loaded/Unloaded, so Control and every descendant republish.
            ["Avalonia.Host.Com.IAvnStyledElement"] = 3,
            ["Avalonia.Host.Com.IAvnControl"] = 4,
            ["Avalonia.Host.Com.IAvnDecorator"] = 4,
            // Everything the completeness wave left alone. None of these sits below
            // ContentControl, Button, ToggleButton, ListBox, ComboBox or Grid, so their
            // flattened vtables are byte-identical to version 4.
            ["Avalonia.Host.Com.IAvnBorder"] = 6,
            ["Avalonia.Host.Com.IAvnTableViewColumn"] = 2,
            ["Avalonia.Host.Com.IAvnPanel"] = 5,
            ["Avalonia.Host.Com.IAvnCanvas"] = 5,
            ["Avalonia.Host.Com.IAvnDockPanel"] = 5,
            ["Avalonia.Host.Com.IAvnStackPanel"] = 6,
            // Wave M grew TemplatedControl (fonts/padding) and TextBlock (fonts/wrapping).
            // Nano-COM vtables are flattened, so every interface below TemplatedControl
            // republishes. TextBlock is not under TemplatedControl; SelectableTextBlock is.
            ["Avalonia.Host.Com.IAvnTextBlock"] = 7,
            ["Avalonia.Host.Com.IAvnSelectableTextBlock"] = 4,
            ["Avalonia.Host.Com.IAvnTemplatedControl"] = 6,
            ["Avalonia.Host.Com.IAvnItemsControl"] = 7,
            ["Avalonia.Host.Com.IAvnSelectingItemsControl"] = 7,
            ["Avalonia.Host.Com.IAvnTextBox"] = 10,
            ["Avalonia.Host.Com.IAvnRangeBase"] = 6,
            ["Avalonia.Host.Com.IAvnSlider"] = 6,
            ["Avalonia.Host.Com.IAvnProgressBar"] = 7,
            ["Avalonia.Host.Com.IAvnContentControl"] = 7,
            ["Avalonia.Host.Com.IAvnHeaderedContentControl"] = 7,
            ["Avalonia.Host.Com.IAvnExpander"] = 7,
            ["Avalonia.Host.Com.IAvnButton"] = 8,
            ["Avalonia.Host.Com.IAvnToggleButton"] = 8,
            ["Avalonia.Host.Com.IAvnCheckBox"] = 8,
            ["Avalonia.Host.Com.IAvnRadioButton"] = 8,
            ["Avalonia.Host.Com.IAvnToggleSwitch"] = 8,
            ["Avalonia.Host.Com.IAvnListBox"] = 8,
            ["Avalonia.Host.Com.IAvnComboBox"] = 9,
            ["Avalonia.Host.Com.IAvnListBoxItem"] = 7,
            ["Avalonia.Host.Com.IAvnComboBoxItem"] = 7,
            ["Avalonia.Host.Com.IAvnScrollViewer"] = 8,
            ["Avalonia.Host.Com.IAvnWindow"] = 9,
            ["Avalonia.Host.Com.IAvnGrid"] = 6,
            // Previously version-1 templated types inherit the TemplatedControl bump.
            ["Avalonia.Host.Com.IAvnAutoCompleteBox"] = 4,
            ["Avalonia.Host.Com.IAvnButtonSpinner"] = 3,
            ["Avalonia.Host.Com.IAvnCalendar"] = 4,
            ["Avalonia.Host.Com.IAvnCalendarDatePicker"] = 4,
            ["Avalonia.Host.Com.IAvnCarousel"] = 5,
            ["Avalonia.Host.Com.IAvnCommandBar"] = 4,
            ["Avalonia.Host.Com.IAvnCommandBarButton"] = 4,
            ["Avalonia.Host.Com.IAvnCommandBarSeparator"] = 3,
            ["Avalonia.Host.Com.IAvnCommandBarToggleButton"] = 4,
            ["Avalonia.Host.Com.IAvnContextMenu"] = 7,
            ["Avalonia.Host.Com.IAvnPopup"] = 5,
            ["Avalonia.Host.Com.IAvnPopupFlyoutBase"] = 3,
            ["Avalonia.Host.Com.IAvnFlyout"] = 3,
            ["Avalonia.Host.Com.IAvnMenuFlyout"] = 3,
            ["Avalonia.Host.Com.IAvnDatePicker"] = 4,
            ["Avalonia.Host.Com.IAvnDropDownButton"] = 4,
            ["Avalonia.Host.Com.IAvnGridSplitter"] = 3,
            ["Avalonia.Host.Com.IAvnGroupBox"] = 3,
            ["Avalonia.Host.Com.IAvnHeaderedItemsControl"] = 4,
            ["Avalonia.Host.Com.IAvnHeaderedSelectingItemsControl"] = 4,
            ["Avalonia.Host.Com.IAvnHyperlinkButton"] = 4,
            ["Avalonia.Host.Com.IAvnIconElement"] = 3,
            ["Avalonia.Host.Com.IAvnLabel"] = 3,
            ["Avalonia.Host.Com.IAvnMaskedTextBox"] = 7,
            ["Avalonia.Host.Com.IAvnMenu"] = 4,
            ["Avalonia.Host.Com.IAvnMenuBase"] = 4,
            ["Avalonia.Host.Com.IAvnMenuItem"] = 5,
            ["Avalonia.Host.Com.IAvnNotificationCard"] = 4,
            ["Avalonia.Host.Com.IAvnNumericUpDown"] = 4,
            ["Avalonia.Host.Com.IAvnPathIcon"] = 3,
            ["Avalonia.Host.Com.IAvnPipsPager"] = 4,
            ["Avalonia.Host.Com.IAvnRefreshContainer"] = 4,
            ["Avalonia.Host.Com.IAvnRepeatButton"] = 4,
            ["Avalonia.Host.Com.IAvnSeparator"] = 3,
            ["Avalonia.Host.Com.IAvnSpinner"] = 3,
            ["Avalonia.Host.Com.IAvnSplitButton"] = 4,
            ["Avalonia.Host.Com.IAvnSplitView"] = 3,
            ["Avalonia.Host.Com.IAvnTabControl"] = 4,
            ["Avalonia.Host.Com.IAvnTabItem"] = 3,
            ["Avalonia.Host.Com.IAvnTableView"] = 4,
            ["Avalonia.Host.Com.IAvnTableViewCell"] = 3,
            ["Avalonia.Host.Com.IAvnTableViewRow"] = 3,
            ["Avalonia.Host.Com.IAvnThumb"] = 3,
            ["Avalonia.Host.Com.IAvnTimePicker"] = 4,
            ["Avalonia.Host.Com.IAvnToggleSplitButton"] = 4,
            ["Avalonia.Host.Com.IAvnToolTip"] = 3,
            ["Avalonia.Host.Com.IAvnTransitioningContentControl"] = 3,
            ["Avalonia.Host.Com.IAvnTreeView"] = 4,
            ["Avalonia.Host.Com.IAvnTreeViewItem"] = 4,
            ["Avalonia.Host.Com.IAvnUserControl"] = 3,
            ["Avalonia.Host.Com.IAvnWindowNotificationManager"] = 3,
            // Wave A's seven new interfaces publish at the default version 1 and nothing they
            // sit under moved, so they need no entry here. Waves B, C and D do the same.
            // The factory is the only interface these waves move: wave A gave it a creator per
            // new control plus GetToolTipStatics (2 → 3), wave B seven more, wave C seven more,
            // and wave D seven more still (RepeatButton, DropDownButton, SplitButton,
            // ToggleSplitButton, HyperlinkButton, ContextMenu, MenuFlyout), so it republishes
            // at version 6, wave E six more (Spinner is abstract) so 7, and wave F two more
            // (Calendar, CalendarDatePicker) so 8, wave G seven more so 9, and wave H
            // eight constructible shapes (Shape is abstract) so 10, wave I five more so 11,
            // and wave J six more so 12, and wave K five constructible (IconElement abstract) so 13.
            ["Avalonia.Host.Com.IAvnImage"] = 2,
            ["Avalonia.Host.Com.IAvnWrapPanel"] = 2,
            ["Avalonia.Host.Com.IAvnUniformGrid"] = 2,
            ["Avalonia.Host.Com.IAvnRelativePanel"] = 2,
            ["Avalonia.Host.Com.IAvnViewbox"] = 2,
            ["Avalonia.Host.Com.IAvnFlexPanel"] = 2,
            ["Avalonia.Host.Com.IAvnShape"] = 2,
            ["Avalonia.Host.Com.IAvnRectangle"] = 2,
            ["Avalonia.Host.Com.IAvnEllipse"] = 2,
            ["Avalonia.Host.Com.IAvnLine"] = 2,
            ["Avalonia.Host.Com.IAvnPath"] = 2,
            ["Avalonia.Host.Com.IAvnPolygon"] = 2,
            ["Avalonia.Host.Com.IAvnPolyline"] = 2,
            ["Avalonia.Host.Com.IAvnArc"] = 2,
            ["Avalonia.Host.Com.IAvnSector"] = 2,
            ["Avalonia.Host.Com.IAvnLayoutTransformControl"] = 2,
            ["Avalonia.Host.Com.IAvnThemeVariantScope"] = 2,
            ["Avalonia.Host.Com.IAvnControlFactory"] = 13,
        },
        IncludeTypeNames =
        [
            "Avalonia.AvaloniaObject",
            "Avalonia.StyledElement",
            "Avalonia.Controls.Control",
            "Avalonia.Controls.ContentControl",
            "Avalonia.Controls.Primitives.HeaderedContentControl",
            "Avalonia.Controls.ItemsControl",
            "Avalonia.Controls.Primitives.HeaderedItemsControl",
            "Avalonia.Controls.Primitives.SelectingItemsControl",
            "Avalonia.Controls.Primitives.HeaderedSelectingItemsControl",
            "Avalonia.Controls.Decorator",
            "Avalonia.Controls.Border",
            "Avalonia.Controls.Panel",
            "Avalonia.Controls.Grid",
            "Avalonia.Controls.Canvas",
            "Avalonia.Controls.DockPanel",
            "Avalonia.Controls.Window",
            "Avalonia.Controls.StackPanel",
            "Avalonia.Controls.TextBlock",
            "Avalonia.Controls.Image",
            "Avalonia.Controls.Primitives.TemplatedControl",
            "Avalonia.Controls.Button",
            "Avalonia.Controls.Primitives.ToggleButton",
            "Avalonia.Controls.CheckBox",
            "Avalonia.Controls.RadioButton",
            "Avalonia.Controls.ToggleSwitch",
            "Avalonia.Controls.Expander",
            "Avalonia.Controls.ListBox",
            "Avalonia.Controls.ComboBox",
            "Avalonia.Controls.ListBoxItem",
            "Avalonia.Controls.ComboBoxItem",
            "Avalonia.Controls.TabControl",
            "Avalonia.Controls.TabItem",
            "Avalonia.Controls.TreeView",
            "Avalonia.Controls.TreeViewItem",
            "Avalonia.Controls.ToolTip",
            // Wave B. A flyout is an AvaloniaObject rather than a Control, so IAvnFlyoutBase
            // hangs directly off IAvnAvaloniaObject and nothing existing moves.
            "Avalonia.Controls.Primitives.FlyoutBase",
            "Avalonia.Controls.Primitives.PopupFlyoutBase",
            "Avalonia.Controls.Flyout",
            "Avalonia.Controls.MenuBase",
            "Avalonia.Controls.Menu",
            "Avalonia.Controls.MenuItem",
            "Avalonia.Controls.SplitView",
            "Avalonia.Controls.DatePicker",
            "Avalonia.Controls.TimePicker",
            // Wave C. Remaining layout panels plus the Thumb base GridSplitter needs.
            // RelativePanel's object-valued attached properties (Above/LeftOf/…) stay gaps:
            // a COM-valued attached property has no ABI shape. The Align*WithPanel bools do
            // cross. Flex's attached properties live on the static Flex class, which is not
            // an AvaloniaObject, so Order/Grow/Shrink/Basis/AlignSelf stay gaps too.
            "Avalonia.Controls.WrapPanel",
            "Avalonia.Controls.Primitives.UniformGrid",
            "Avalonia.Controls.RelativePanel",
            "Avalonia.Controls.Viewbox",
            "Avalonia.Controls.FlexPanel",
            "Avalonia.Controls.Primitives.Thumb",
            "Avalonia.Controls.GridSplitter",
            // Wave D. Button family plus context menus. Flyout on SplitButton/Button stays a
            // gap (COM-valued). NavigateUri crosses as a URI string through AvnUri.
            "Avalonia.Controls.RepeatButton",
            "Avalonia.Controls.DropDownButton",
            "Avalonia.Controls.SplitButton",
            "Avalonia.Controls.ToggleSplitButton",
            "Avalonia.Controls.HyperlinkButton",
            "Avalonia.Controls.ContextMenu",
            "Avalonia.Controls.MenuFlyout",
            // Wave E. Remaining input. Spinner is abstract; NumericUpDown decimals cross as
            // invariant strings. PromptChar is a char and stays a gap.
            "Avalonia.Controls.Spinner",
            "Avalonia.Controls.ButtonSpinner",
            "Avalonia.Controls.NumericUpDown",
            "Avalonia.Controls.AutoCompleteBox",
            "Avalonia.Controls.MaskedTextBox",
            "Avalonia.Controls.SelectableTextBlock",
            // Wave F. Calendar days are DateTime, not DateTimeOffset, so they cross as
            // yyyy-MM-dd through AvnCalendarDate rather than the picker "o" form.
            "Avalonia.Controls.Calendar",
            "Avalonia.Controls.CalendarDatePicker",
            // Wave G. Content chrome. PageTransition and LayoutTransform are interfaces
            // with no ABI shape; Label.Target is IInputElement, not a projected control.
            "Avalonia.Controls.Carousel",
            "Avalonia.Controls.TransitioningContentControl",
            "Avalonia.Controls.Label",
            "Avalonia.Controls.Separator",
            "Avalonia.Controls.GroupBox",
            "Avalonia.Controls.UserControl",
            "Avalonia.Controls.LayoutTransformControl",
            // Wave H. Shapes. Fill/Stroke are brushes. Path.Data is Geometry with Parse/ToString.
            // Points collections stay gaps. Shape is abstract.
            "Avalonia.Controls.Shapes.Shape",
            "Avalonia.Controls.Shapes.Rectangle",
            "Avalonia.Controls.Shapes.Ellipse",
            "Avalonia.Controls.Shapes.Line",
            "Avalonia.Controls.Shapes.Path",
            "Avalonia.Controls.Shapes.Polygon",
            "Avalonia.Controls.Shapes.Polyline",
            "Avalonia.Controls.Shapes.Arc",
            "Avalonia.Controls.Shapes.Sector",
            // Wave I. Overlay and notifications. TrayIcon is an AvaloniaObject, not a Control.
            // NativeMenu, WindowIcon and ICommand stay gaps.
            "Avalonia.Controls.Primitives.Popup",
            "Avalonia.Controls.TrayIcon",
            "Avalonia.Controls.Notifications.WindowNotificationManager",
            "Avalonia.Controls.Notifications.NotificationCard",
            "Avalonia.Controls.RefreshContainer",
            // Wave J. CommandBar family, PipsPager, ThemeVariantScope. Command lists, Icon
            // and ThemeVariant stay gaps.
            "Avalonia.Controls.CommandBar",
            "Avalonia.Controls.CommandBarButton",
            "Avalonia.Controls.CommandBarToggleButton",
            "Avalonia.Controls.CommandBarSeparator",
            "Avalonia.Controls.PipsPager",
            "Avalonia.Controls.ThemeVariantScope",
            // Wave K. Icons and TableView. Inlines stay a gap. Column Width is a GridLength
            // string. Columns is a projected collection of TableViewColumn.
            "Avalonia.Controls.IconElement",
            "Avalonia.Controls.PathIcon",
            "Avalonia.Controls.TableView",
            "Avalonia.Controls.TableViewColumn",
            "Avalonia.Controls.TableViewRow",
            "Avalonia.Controls.TableViewCell",
            "Avalonia.Controls.TextBox",
            "Avalonia.Controls.ScrollViewer",
            "Avalonia.Controls.Primitives.RangeBase",
            "Avalonia.Controls.Slider",
            "Avalonia.Controls.ProgressBar",
        ],
        IncludeMembers = new Dictionary<string, IReadOnlyList<string>>(StringComparer.Ordinal)
        {
            ["Avalonia.AvaloniaObject"] = [],
            ["Avalonia.StyledElement"] = ["Classes", "Name"],
            ["Avalonia.Controls.Control"] =
            [
                "Width", "Height", "MinWidth", "MinHeight", "MaxWidth", "MaxHeight",
                "Margin", "HorizontalAlignment", "VerticalAlignment", "IsVisible",
                "Opacity", "IsEnabled", "KeyDown", "PointerEntered", "PointerExited",
                "ContextMenu", "ContextFlyout", "IsLoaded", "Loaded", "Unloaded",
            ],
            ["Avalonia.Controls.ContentControl"] =
                ["Content", "HorizontalContentAlignment", "VerticalContentAlignment"],
            ["Avalonia.Controls.Primitives.HeaderedContentControl"] = ["Header"],
            ["Avalonia.Controls.ItemsControl"] = ["Items", "ItemCount", "ScrollIntoView"],
            ["Avalonia.Controls.Primitives.HeaderedItemsControl"] = ["Header"],
            ["Avalonia.Controls.Primitives.SelectingItemsControl"] =
            [
                "SelectedIndex", "SelectionChanged",
                "AutoScrollToSelectedItem", "IsTextSearchEnabled", "WrapSelection",
            ],
            ["Avalonia.Controls.Primitives.HeaderedSelectingItemsControl"] = ["Header"],
            ["Avalonia.Controls.Decorator"] = ["Child", "Padding"],
            ["Avalonia.Controls.Border"] =
                ["Background", "BorderBrush", "BorderThickness", "CornerRadius", "BackgroundSizing",
                 "ClipToBoundsRadius"],
            ["Avalonia.Controls.Panel"] = ["Background", "Children"],
            ["Avalonia.Controls.Grid"] =
                ["ShowGridLines", "RowSpacing", "ColumnSpacing", "ColumnDefinitions", "RowDefinitions"],
            ["Avalonia.Controls.Canvas"] = [],
            ["Avalonia.Controls.DockPanel"] = ["LastChildFill", "HorizontalSpacing", "VerticalSpacing"],
            ["Avalonia.Controls.Window"] =
            [
                "Title", "CanResize", "WindowState", "Show", "Close", "Hide",
                "SizeToContent", "ShowActivated", "ShowInTaskbar", "CanMinimize",
                "CanMaximize", "WindowStartupLocation", "WindowDecorations",
                "ClosingBehavior", "ExtendClientAreaToDecorationsHint",
                "ExtendClientAreaTitleBarHeightHint", "IsExtendedIntoWindowDecorations",
                "WindowDecorationMargin", "OffScreenMargin", "IsDialog", "Closing",
            ],
            ["Avalonia.Controls.StackPanel"] =
                ["Orientation", "Spacing", "AreHorizontalSnapPointsRegular", "AreVerticalSnapPointsRegular"],
            ["Avalonia.Controls.TextBlock"] =
            [
                "Text", "FontSize", "FontWeight", "FontFamily", "FontStyle", "FontStretch",
                "Foreground", "Background", "Padding", "TextAlignment", "LetterSpacing",
                "LineSpacing", "LineHeight", "BaselineOffset", "MaxLines", "TextWrapping",
            ],
            ["Avalonia.Controls.Image"] =
                ["Source", "Stretch", "StretchDirection", "BlendMode"],
            ["Avalonia.Controls.Button"] =
                ["ClickMode", "IsDefault", "IsCancel", "IsPressed", "Click", "Flyout"],
            ["Avalonia.Controls.Primitives.ToggleButton"] =
                ["IsChecked", "IsThreeState", "IsCheckedChanged"],
            ["Avalonia.Controls.CheckBox"] = [],
            ["Avalonia.Controls.RadioButton"] = ["GroupName"],
            ["Avalonia.Controls.ToggleSwitch"] = ["OnContent", "OffContent"],
            ["Avalonia.Controls.Expander"] =
                ["ExpandDirection", "IsExpanded", "Expanded", "Collapsed"],
            ["Avalonia.Controls.ListBox"] = ["SelectionMode", "SelectAll", "UnselectAll"],
            ["Avalonia.Controls.ComboBox"] =
            [
                "PlaceholderText", "IsDropDownOpen", "IsEditable", "MaxDropDownHeight",
                "Text", "PlaceholderForeground", "Clear", "DropDownOpened", "DropDownClosed",
            ],
            ["Avalonia.Controls.ListBoxItem"] = ["IsSelected"],
            ["Avalonia.Controls.ComboBoxItem"] = [],
            // TabControl inherits Items and SelectedIndex from SelectingItemsControl, so it only
            // publishes what it declares itself.
            ["Avalonia.Controls.TabControl"] =
                ["TabStripPlacement", "HorizontalContentAlignment", "VerticalContentAlignment"],
            // TabItem.TabStripPlacement is a Dock? that the TabControl writes; a nullable enum
            // has no ABI shape of its own, so only IsSelected crosses.
            ["Avalonia.Controls.TabItem"] = ["IsSelected"],
            // TreeView derives from ItemsControl rather than SelectingItemsControl, so it carries
            // Items but no SelectedIndex. SelectedItem/SelectedItems are object/IList and stay in
            // the gap report.
            ["Avalonia.Controls.TreeView"] =
            [
                "AutoScrollToSelectedItem", "SelectionMode", "SelectAll", "UnselectAll",
                "ExpandSubTree", "CollapseSubTree", "SelectionChanged",
            ],
            ["Avalonia.Controls.TreeViewItem"] =
                ["IsExpanded", "IsSelected", "Level", "Expanded", "Collapsed"],
            // ToolTip is projected for its attached properties; as a control it adds nothing
            // over ContentControl.
            ["Avalonia.Controls.ToolTip"] = [],
            // A flyout is shown imperatively: there is no attached-property pipeline for a
            // COM-valued property, so ShowAt/Hide are how a flyout reaches a control.
            ["Avalonia.Controls.Primitives.FlyoutBase"] =
                ["IsOpen", "Target", "ShowAt", "Hide", "Opened", "Closed"],
            // PopupFlyoutBase re-declares ShowAt/Hide as sealed overrides; they are inherited
            // from IAvnFlyoutBase rather than published twice. Placement flags cross as I32.
            ["Avalonia.Controls.Primitives.PopupFlyoutBase"] =
            [
                "Placement", "ShowMode", "HorizontalOffset", "VerticalOffset",
                "OverlayDismissEventPassThrough", "Opening", "Closing",
                "Popup",
                "PlacementAnchor", "PlacementGravity", "PlacementConstraintAdjustment",
            ],
            ["Avalonia.Controls.Flyout"] = ["Content"],
            // Menu is imperative, unlike the view-model NativeMenu: MenuBase owns the open
            // state and Menu inherits it, declaring nothing of its own.
            ["Avalonia.Controls.MenuBase"] = ["IsOpen", "Open", "Close", "Opened", "Closed"],
            ["Avalonia.Controls.Menu"] = [],
            // Command and CommandParameter are an ICommand and an object; HotKey and
            // InputGesture are KeyGestures. All four stay in the gap report. Click is the
            // imperative equivalent and it does cross.
            ["Avalonia.Controls.MenuItem"] =
            [
                "Icon", "IsSelected", "IsSubMenuOpen", "StaysOpenOnClick", "ToggleType",
                "IsChecked", "GroupName", "Click", "SubmenuOpened",
                "HasSubMenu", "IsTopLevel", "Open", "Close",
            ],
            ["Avalonia.Controls.SplitView"] =
            [
                "IsPaneOpen", "DisplayMode", "PanePlacement", "OpenPaneLength",
                "CompactPaneLength", "Pane", "PaneBackground", "UseLightDismissOverlayMode",
                "PaneOpened", "PaneClosed",
            ],
            // SelectedDateChanged carries DateTimeOffset? fields and event payloads have no
            // converter hook, so it is a gap; the date properties themselves do cross.
            ["Avalonia.Controls.DatePicker"] =
            [
                "SelectedDate", "MinYear", "MaxYear", "DayVisible", "MonthVisible",
                "YearVisible", "DayFormat", "MonthFormat", "YearFormat", "Clear",
                "VerticalContentAlignment",
            ],
            ["Avalonia.Controls.TimePicker"] =
            [
                "SelectedTime", "MinuteIncrement", "SecondIncrement", "ClockIdentifier",
                "UseSeconds", "Clear", "VerticalContentAlignment",
            ],
            ["Avalonia.Controls.WrapPanel"] =
            [
                "Orientation", "ItemWidth", "ItemHeight", "ItemSpacing", "LineSpacing",
                "ItemsAlignment",
            ],
            ["Avalonia.Controls.Primitives.UniformGrid"] =
                ["Rows", "Columns", "FirstColumn", "RowSpacing", "ColumnSpacing"],
            ["Avalonia.Controls.RelativePanel"] = [],
            ["Avalonia.Controls.Viewbox"] = ["Child", "Stretch", "StretchDirection"],
            ["Avalonia.Controls.FlexPanel"] =
            [
                "Direction", "JustifyContent", "AlignItems", "AlignContent", "Wrap",
                "ColumnSpacing", "RowSpacing",
            ],
            ["Avalonia.Controls.Primitives.Thumb"] = [],
            ["Avalonia.Controls.GridSplitter"] =
            [
                "ResizeDirection", "ResizeBehavior", "ShowsPreview", "KeyboardIncrement",
                "DragIncrement",
            ],
            ["Avalonia.Controls.RepeatButton"] = ["Interval", "Delay"],
            ["Avalonia.Controls.DropDownButton"] = [],
            ["Avalonia.Controls.SplitButton"] = ["Click", "Flyout"],
            ["Avalonia.Controls.ToggleSplitButton"] = ["IsChecked", "IsCheckedChanged"],
            ["Avalonia.Controls.HyperlinkButton"] = ["IsVisited", "NavigateUri"],
            ["Avalonia.Controls.ContextMenu"] =
            [
                "HorizontalOffset", "VerticalOffset", "Placement", "WindowManagerAddShadowHint",
                "PlacementTarget",
                "PlacementAnchor", "PlacementGravity", "PlacementConstraintAdjustment",
                "PlacementRect",
            ],
            ["Avalonia.Controls.MenuFlyout"] = ["Items"],
            ["Avalonia.Controls.Spinner"] = [],
            ["Avalonia.Controls.ButtonSpinner"] =
                ["AllowSpin", "ShowButtonSpinner", "ButtonSpinnerLocation"],
            ["Avalonia.Controls.NumericUpDown"] =
            [
                "Value", "Minimum", "Maximum", "Increment", "Text", "PlaceholderText",
                "IsReadOnly", "ClipValueToMinMax", "AllowSpin", "ShowButtonSpinner",
                "ButtonSpinnerLocation", "FormatString",
                "PlaceholderForeground", "HorizontalContentAlignment", "VerticalContentAlignment",
                "TextAlignment", "InnerLeftContent", "InnerRightContent", "ValueChanged",
            ],
            ["Avalonia.Controls.AutoCompleteBox"] =
            [
                "Text", "PlaceholderText", "MinimumPrefixLength", "MaxDropDownHeight",
                "IsDropDownOpen", "FilterMode", "IsTextCompletionEnabled",
                "CaretIndex", "ClearSelectionOnLostFocus", "SearchText", "MaxLength",
                "PlaceholderForeground", "InnerLeftContent", "InnerRightContent",
                "PopulateComplete", "DropDownOpened", "DropDownClosed",
            ],
            ["Avalonia.Controls.MaskedTextBox"] =
                ["Mask", "AsciiOnly", "HidePromptOnLeave", "ResetOnPrompt", "ResetOnSpace",
                 "MaskCompleted", "MaskFull", "PromptChar"],
            ["Avalonia.Controls.SelectableTextBlock"] =
            [
                "SelectionStart", "SelectionEnd", "SelectedText", "CanCopy", "Copy",
                "SelectionBrush", "SelectionForegroundBrush", "SelectAll", "ClearSelection",
                "CopyingToClipboard",
            ],
            ["Avalonia.Controls.Calendar"] =
            [
                "SelectedDate", "DisplayDate", "DisplayDateStart", "DisplayDateEnd",
                "DisplayMode", "SelectionMode", "IsTodayHighlighted", "FirstDayOfWeek",
                "HeaderBackground", "IsWeekNumberVisible", "WeekNumberRule",
                "AllowTapRangeSelection",
            ],
            ["Avalonia.Controls.CalendarDatePicker"] =
            [
                "SelectedDate", "DisplayDate", "DisplayDateStart", "DisplayDateEnd",
                "IsDropDownOpen", "IsTodayHighlighted", "SelectedDateFormat",
                "CustomDateFormatString", "Text", "PlaceholderText", "IsWeekNumberVisible",
                "FirstDayOfWeek", "UseFloatingPlaceholder", "PlaceholderForeground",
                "HorizontalContentAlignment", "VerticalContentAlignment", "WeekNumberRule",
                "CalendarOpened", "CalendarClosed", "Clear",
            ],
            ["Avalonia.Controls.Carousel"] =
                ["IsSwipeEnabled", "ViewportFraction", "IsSwiping", "Next", "Previous"],
            ["Avalonia.Controls.TransitioningContentControl"] = ["IsTransitionReversed"],
            ["Avalonia.Controls.Label"] = [],
            ["Avalonia.Controls.Separator"] = [],
            ["Avalonia.Controls.GroupBox"] = [],
            ["Avalonia.Controls.UserControl"] = [],
            ["Avalonia.Controls.LayoutTransformControl"] = ["UseRenderTransform"],
            ["Avalonia.Controls.Shapes.Shape"] =
            [
                "Fill", "Stroke", "StrokeThickness", "Stretch", "StrokeDashOffset",
                "StrokeLineCap", "StrokeJoin", "StrokeMiterLimit",
            ],
            ["Avalonia.Controls.Shapes.Rectangle"] = ["RadiusX", "RadiusY"],
            ["Avalonia.Controls.Shapes.Ellipse"] = [],
            ["Avalonia.Controls.Shapes.Line"] = ["StartPoint", "EndPoint"],
            ["Avalonia.Controls.Shapes.Path"] = ["Data"],
            ["Avalonia.Controls.Shapes.Polygon"] = ["FillRule"],
            ["Avalonia.Controls.Shapes.Polyline"] = ["FillRule"],
            ["Avalonia.Controls.Shapes.Arc"] = ["StartAngle", "SweepAngle"],
            ["Avalonia.Controls.Shapes.Sector"] = ["StartAngle", "SweepAngle"],
            ["Avalonia.Controls.Primitives.Popup"] =
            [
                "Child", "IsOpen", "Placement", "HorizontalOffset", "VerticalOffset",
                "IsLightDismissEnabled", "Topmost", "WindowManagerAddShadowHint",
                "OverlayDismissEventPassThrough",
                "InheritsTransform", "PlacementTarget", "TakesFocusFromNativeControl",
                "ShouldUseOverlayLayer", "IsUsingOverlayLayer", "IsPointerOverPopup",
                "Opened", "Closed", "Open", "Close",
                "PlacementAnchor", "PlacementGravity", "PlacementConstraintAdjustment",
                "PlacementRect",
            ],
            ["Avalonia.Controls.TrayIcon"] = ["ToolTipText", "IsVisible"],
            ["Avalonia.Controls.Notifications.WindowNotificationManager"] = ["Position", "MaxItems"],
            ["Avalonia.Controls.Notifications.NotificationCard"] =
                ["IsClosed", "NotificationType", "IsClosing", "Close"],
            ["Avalonia.Controls.RefreshContainer"] =
                ["PullDirection", "IsMouseEnabled", "RequestRefresh"],
            ["Avalonia.Controls.CommandBar"] =
            [
                "Content", "DefaultLabelPosition", "IsDynamicOverflowEnabled",
                "OverflowButtonVisibility", "IsOpen", "IsSticky",
                "ItemWidthBottom", "ItemWidthRight", "ItemWidthCollapsed",
                "HasSecondaryCommands", "IsOverflowButtonVisible",
            ],
            ["Avalonia.Controls.CommandBarButton"] =
                ["Label", "IsCompact", "DynamicOverflowOrder", "LabelPosition", "IsInOverflow"],
            ["Avalonia.Controls.CommandBarToggleButton"] =
                ["Label", "IsCompact", "DynamicOverflowOrder", "LabelPosition", "IsInOverflow"],
            ["Avalonia.Controls.CommandBarSeparator"] = ["IsCompact", "IsInOverflow"],
            ["Avalonia.Controls.PipsPager"] =
            [
                "MaxVisiblePips", "NumberOfPages", "SelectedPageIndex", "Orientation",
                "IsNextButtonVisible", "IsPreviousButtonVisible", "SelectedIndexChanged",
            ],
            ["Avalonia.Controls.ThemeVariantScope"] = [],
            ["Avalonia.Controls.IconElement"] = [],
            ["Avalonia.Controls.PathIcon"] = ["Data"],
            ["Avalonia.Controls.TableView"] = ["CanUserResizeColumns"],
            ["Avalonia.Controls.TableViewColumn"] =
            [
                "Header", "Width", "MinWidth", "MaxWidth", "IsVisible",
                "HorizontalContentAlignment", "CanUserResize",
                "ActualWidth", "CanUserEffectivelyResize",
            ],
            ["Avalonia.Controls.TableViewRow"] = [],
            ["Avalonia.Controls.TableViewCell"] = [],
            ["Avalonia.Controls.Primitives.TemplatedControl"] =
            [
                "Background", "BorderBrush", "BorderThickness", "CornerRadius", "FontSize",
                "FontFamily", "FontStyle", "FontWeight", "FontStretch", "LetterSpacing",
                "Foreground", "Padding",
            ],
            ["Avalonia.Controls.TextBox"] =
            [
                "Text", "PlaceholderText", "AcceptsReturn", "AcceptsTab", "IsReadOnly",
                "CaretIndex", "SelectionStart", "SelectionEnd", "MaxLength", "MaxLines",
                "MinLines", "LineHeight", "RevealPassword", "TextWrapping", "NewLine",
                "IsUndoEnabled", "UndoLimit", "CanUndo", "CanRedo", "CanCut", "CanCopy",
                "CanPaste", "Clear", "Cut", "Copy", "Paste", "Undo", "Redo", "TextChanged",
                "SelectedText", "HorizontalContentAlignment", "VerticalContentAlignment",
                "TextAlignment", "SelectionBrush", "SelectionForegroundBrush", "CaretBrush",
                "IsInactiveSelectionHighlightEnabled", "ClearSelectionOnLostFocus",
                "UseFloatingPlaceholder", "PlaceholderForeground", "InnerLeftContent",
                "InnerRightContent", "SelectAll", "ClearSelection", "ScrollToLine", "GetLineCount",
                "PasswordChar",
                "CopyingToClipboard", "CuttingToClipboard", "PastingFromClipboard",
            ],
            ["Avalonia.Controls.ScrollViewer"] =
            [
                "BringIntoViewOnFocusChange", "HorizontalScrollBarVisibility",
                "VerticalScrollBarVisibility", "AllowAutoHide", "IsScrollChainingEnabled",
                "IsScrollInertiaEnabled", "IsDeferredScrollingEnabled", "IsExpanded",
                "LineUp", "LineDown", "LineLeft", "LineRight", "PageUp", "PageDown",
                "PageLeft", "PageRight", "ScrollToHome", "ScrollToEnd", "ScrollChanged",
                "Extent", "Offset", "Viewport", "LargeChange", "SmallChange",
                "HorizontalSnapPointsType", "VerticalSnapPointsType",
                "HorizontalSnapPointsAlignment", "VerticalSnapPointsAlignment",
            ],
            ["Avalonia.Controls.Primitives.RangeBase"] =
                ["Minimum", "Maximum", "Value", "SmallChange", "LargeChange", "ValueChanged"],
            ["Avalonia.Controls.Slider"] =
                ["Orientation", "IsDirectionReversed", "IsSnapToTickEnabled", "TickFrequency", "TickPlacement"],
            ["Avalonia.Controls.ProgressBar"] =
                ["IsIndeterminate", "ShowProgressText", "ProgressTextFormat", "Orientation", "Percentage"],
        },
        MemberOverrides = new Dictionary<string, MarshallingOverride>(StringComparer.Ordinal)
        {
            ["Avalonia.Controls.ContentControl.Content"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.Panel.Children"] = new()
            {
                Kind = MarshallingKind.ComCollection,
                InterfaceName = "Avalonia.Host.Com.IAvnControlList",
                ElementInterfaceName = "Avalonia.Host.Com.IAvnControl",
                ElementKind = MarshallingKind.ComInterface,
                IsNullable = false,
            },
            ["Avalonia.Controls.ItemsControl.Items"] = new()
            {
                Kind = MarshallingKind.ComCollection,
                InterfaceName = "Avalonia.Host.Com.IAvnItemList",
                ElementInterfaceName = "Avalonia.Host.Com.IAvnControl",
                ElementKind = MarshallingKind.ComInterface,
                IsNullable = false,
            },
            ["Avalonia.StyledElement.Classes"] = new()
            {
                Kind = MarshallingKind.ComCollection,
                InterfaceName = "Avalonia.Host.Com.IAvnStringList",
                ElementKind = MarshallingKind.StringUtf16,
                IsNullable = false,
            },
            // Grid's track definitions cross as the same comma-separated length list that
            // ColumnDefinitions/RowDefinitions already parse and print, not as a projected
            // collection of definition objects. The host wrapper converts with the type's own
            // Parse/ToString, so nothing here needs an interface of its own.
            ["Avalonia.Controls.Primitives.TemplatedControl.FontFamily"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                IsNullable = false,
            },
            ["Avalonia.Controls.TextBlock.FontFamily"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                IsNullable = false,
            },
            ["Avalonia.Controls.Control.ContextMenu"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnContextMenu",
                IsNullable = true,
            },
            ["Avalonia.Controls.Control.ContextFlyout"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnFlyoutBase",
                IsNullable = true,
            },
            ["Avalonia.Controls.TextBox.InnerLeftContent"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.TextBox.InnerRightContent"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.AutoCompleteBox.InnerLeftContent"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.AutoCompleteBox.InnerRightContent"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.NumericUpDown.InnerLeftContent"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.NumericUpDown.InnerRightContent"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.Grid.ColumnDefinitions"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                IsNullable = false,
            },
            ["Avalonia.Controls.Grid.RowDefinitions"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                IsNullable = false,
            },
            ["Avalonia.Controls.Decorator.Child"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.Primitives.HeaderedContentControl.Header"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.Primitives.HeaderedItemsControl.Header"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.Primitives.HeaderedSelectingItemsControl.Header"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.Flyout.Content"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.MenuItem.Icon"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.Button.Flyout"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnFlyoutBase",
                IsNullable = true,
            },
            ["Avalonia.Controls.SplitButton.Flyout"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnFlyoutBase",
                IsNullable = true,
            },
            ["Avalonia.Controls.SplitView.Pane"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.Viewbox.Child"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.HyperlinkButton.NavigateUri"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnUri",
                IsNullable = true,
            },
            ["Avalonia.Controls.MenuFlyout.Items"] = new()
            {
                Kind = MarshallingKind.ComCollection,
                InterfaceName = "Avalonia.Host.Com.IAvnItemList",
                ElementInterfaceName = "Avalonia.Host.Com.IAvnControl",
                ElementKind = MarshallingKind.ComInterface,
                IsNullable = false,
            },
            ["Avalonia.Controls.NumericUpDown.Value"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnDecimal",
                IsNullable = true,
            },
            ["Avalonia.Controls.NumericUpDown.Minimum"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnDecimalValue",
                IsNullable = false,
            },
            ["Avalonia.Controls.NumericUpDown.Maximum"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnDecimalValue",
                IsNullable = false,
            },
            ["Avalonia.Controls.NumericUpDown.Increment"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnDecimalValue",
                IsNullable = false,
            },
            ["Avalonia.Controls.Calendar.SelectedDate"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnCalendarDate",
                IsNullable = true,
            },
            ["Avalonia.Controls.Calendar.DisplayDate"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnCalendarDateValue",
                IsNullable = false,
            },
            ["Avalonia.Controls.Calendar.DisplayDateStart"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnCalendarDate",
                IsNullable = true,
            },
            ["Avalonia.Controls.Calendar.DisplayDateEnd"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnCalendarDate",
                IsNullable = true,
            },
            ["Avalonia.Controls.CalendarDatePicker.SelectedDate"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnCalendarDate",
                IsNullable = true,
            },
            ["Avalonia.Controls.CalendarDatePicker.DisplayDate"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnCalendarDateValue",
                IsNullable = false,
            },
            ["Avalonia.Controls.CalendarDatePicker.DisplayDateStart"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnCalendarDate",
                IsNullable = true,
            },
            ["Avalonia.Controls.CalendarDatePicker.DisplayDateEnd"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnCalendarDate",
                IsNullable = true,
            },
            ["Avalonia.Controls.Shapes.Path.Data"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnGeometry",
                IsNullable = true,
            },
            ["Avalonia.Controls.Primitives.Popup.PlacementTarget"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.ContextMenu.PlacementTarget"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.Primitives.PopupFlyoutBase.Popup"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnPopup",
                IsNullable = false,
            },
            ["Avalonia.Controls.Primitives.Popup.Child"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.CommandBar.Content"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.PathIcon.Data"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnGeometry",
                IsNullable = true,
            },
            ["Avalonia.Controls.TableViewColumn.Header"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.TableViewColumn.Width"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                IsNullable = false,
            },
            // The projection has no date/time ABI shape, so a date crosses as an ISO-8601
            // string through a host-side converter, the same mechanism Image.Source uses. The
            // wire form is the invariant round-trip "o" format; reading always produces it and
            // writing accepts any spelling the invariant parser takes, including a bare
            // yyyy-MM-dd. A null or empty string clears SelectedDate.
            ["Avalonia.Controls.DatePicker.SelectedDate"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnDateTimeOffset",
                IsNullable = true,
            },
            // MinYear/MaxYear have no absent state, so they take the non-nullable converter:
            // clearing one fails the call rather than silently meaning "today".
            ["Avalonia.Controls.DatePicker.MinYear"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnDateTimeOffsetValue",
                IsNullable = false,
            },
            ["Avalonia.Controls.DatePicker.MaxYear"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnDateTimeOffsetValue",
                IsNullable = false,
            },
            // A TimePicker selection is a time of day, not a duration, so it crosses as
            // ISO-8601 HH:mm:ss rather than as an ISO-8601 PnDTnHnMnS duration.
            ["Avalonia.Controls.TimePicker.SelectedTime"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnTimeSpan",
                IsNullable = true,
            },
            // Image.Source is an IImage, which is a managed interface with no ABI shape. It
            // crosses as the *source string* the host resolves into a bitmap: an absolute or
            // relative file path, or a file://, avares:// or resm: URI. The host remembers which
            // string produced which bitmap, so a read returns the string the ABI set; an image
            // that came from XAML or from managed code reads back as null.
            ["Avalonia.Controls.Image.Source"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnImageSource",
                IsNullable = true,
            },
            ["Avalonia.Controls.ToggleSwitch.OnContent"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
            ["Avalonia.Controls.ToggleSwitch.OffContent"] = new()
            {
                Kind = MarshallingKind.ComInterface,
                InterfaceName = "Avalonia.Host.Com.IAvnControl",
                IsNullable = true,
            },
        },
        EventOverrides = new Dictionary<string, EventProjection>(StringComparer.Ordinal)
        {
            ["Avalonia.Controls.Button.Click"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.Primitives.ToggleButton.IsCheckedChanged"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.TextBox.TextChanged"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.TextBox.CopyingToClipboard"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.TextBox.CuttingToClipboard"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.TextBox.PastingFromClipboard"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.SelectableTextBlock.CopyingToClipboard"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.ScrollViewer.ScrollChanged"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.ComboBox.DropDownOpened"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.ComboBox.DropDownClosed"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.PipsPager.SelectedIndexChanged"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.AutoCompleteBox.DropDownOpened"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.AutoCompleteBox.DropDownClosed"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.NumericUpDown.ValueChanged"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.CalendarDatePicker.CalendarOpened"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.CalendarDatePicker.CalendarClosed"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.Primitives.RangeBase.ValueChanged"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.Expander.Expanded"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.Expander.Collapsed"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.Primitives.SelectingItemsControl.SelectionChanged"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            // TreeView derives from ItemsControl, so its SelectionChanged is its own event
            // rather than the SelectingItemsControl one.
            ["Avalonia.Controls.TreeView.SelectionChanged"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.TreeViewItem.Expanded"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.TreeViewItem.Collapsed"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.Primitives.FlyoutBase.Opened"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.Primitives.FlyoutBase.Closed"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.Primitives.PopupFlyoutBase.Opening"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            // Closing is the one wave B event with a payload: the handler may veto the close
            // by writing back Cancel, exactly as Control.KeyDown writes back Handled.
            ["Avalonia.Controls.Primitives.PopupFlyoutBase.Closing"] = new()
            {
                PayloadKind = EventPayloadKind.Fields,
                Parameters = [new() { Name = "Cancel", Direction = ParameterDirection.InOut }],
            },
            ["Avalonia.Controls.Primitives.Popup.Opened"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.Primitives.Popup.Closed"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.MenuBase.Opened"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.MenuBase.Closed"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.MenuItem.Click"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.SplitButton.Click"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.ToggleSplitButton.IsCheckedChanged"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.MenuItem.SubmenuOpened"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.SplitView.PaneOpened"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.SplitView.PaneClosed"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.Control.KeyDown"] = new()
            {
                PayloadKind = EventPayloadKind.Fields,
                Parameters =
                [
                    new() { Name = "Key" },
                    new() { Name = "PhysicalKey" },
                    new() { Name = "KeyModifiers" },
                    new() { Name = "KeySymbol" },
                    new() { Name = "Handled", Direction = ParameterDirection.InOut },
                ],
            },
            ["Avalonia.Controls.Control.PointerEntered"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.Control.PointerExited"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.Control.Loaded"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
            ["Avalonia.Controls.Control.Unloaded"] = new()
            {
                PayloadKind = EventPayloadKind.None,
            },
        },
        AttachedProperties = new Dictionary<string, IReadOnlyList<string>>(StringComparer.Ordinal)
        {
            ["Avalonia.Controls.Grid"] =
                ["Column", "Row", "ColumnSpan", "RowSpan", "IsSharedSizeScope"],
            ["Avalonia.Controls.Canvas"] = ["Left", "Top", "Right", "Bottom"],
            ["Avalonia.Controls.DockPanel"] = ["Dock"],
            ["Avalonia.Controls.ToolTip"] =
            [
                "Tip", "IsOpen", "Placement", "HorizontalOffset", "VerticalOffset",
                "ShowDelay", "BetweenShowDelay", "ShowOnDisabled", "ServiceEnabled",
            ],
            ["Avalonia.Controls.RelativePanel"] =
            [
                "AlignLeftWithPanel", "AlignRightWithPanel", "AlignTopWithPanel",
                "AlignBottomWithPanel", "AlignHorizontalCenterWithPanel",
                "AlignVerticalCenterWithPanel",
            ],
        },
        AttachedPropertyOverrides = new Dictionary<string, MarshallingOverride>(StringComparer.Ordinal)
        {
            // ToolTip.Tip is an object so that XAML can hang an arbitrary control off it. Over
            // the ABI it is a string and nothing else: setting one stores the string, and
            // reading one returns null when the tip is a control rather than text. Projecting a
            // control as a tip is a later wave.
            ["Avalonia.Controls.ToolTip.Tip"] = new()
            {
                Kind = MarshallingKind.StringUtf16,
                StringConverterTypeName = "Avalonia.Host.Com.AvnToolTipTip",
                IsNullable = true,
            },
        },
    };
}
