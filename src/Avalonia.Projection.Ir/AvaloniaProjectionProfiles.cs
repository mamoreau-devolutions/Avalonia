namespace Avalonia.Projection.Ir;

public static class AvaloniaProjectionProfiles
{
    public static ProjectionPolicy ObjectModelKernel { get; } = new()
    {
        // Wave A adds seven brand-new interfaces (Image, the tab pair, the tree pair,
        // HeaderedItemsControl and ToolTip) and widens no existing one, so every previously
        // published interface keeps the IID it last shipped and the new ones publish at
        // version 1. The default is therefore 1 and every older interface is pinned to the
        // version whose flattened vtable it still matches.
        DefaultProjectedTypeAbiVersion = 1,
        AbiVersions = new Dictionary<string, int>(StringComparer.Ordinal)
        {
            // AvaloniaObject projects no members, so its vtable is byte-identical to
            // version 2. Republishing it under a new IID would be a gratuitous break.
            ["Avalonia.Host.Com.IAvnAvaloniaObject"] = 2,
            // StyledElement, Control and Decorator have gained nothing since version 3 and none
            // of their bases have either, so their flattened vtables are byte-identical to
            // version 3 and they keep the IIDs they published there.
            ["Avalonia.Host.Com.IAvnStyledElement"] = 3,
            ["Avalonia.Host.Com.IAvnControl"] = 3,
            ["Avalonia.Host.Com.IAvnDecorator"] = 3,
            // Everything the completeness wave left alone. None of these sits below
            // ContentControl, Button, ToggleButton, ListBox, ComboBox or Grid, so their
            // flattened vtables are byte-identical to version 4.
            ["Avalonia.Host.Com.IAvnBorder"] = 4,
            ["Avalonia.Host.Com.IAvnPanel"] = 4,
            ["Avalonia.Host.Com.IAvnCanvas"] = 4,
            ["Avalonia.Host.Com.IAvnDockPanel"] = 4,
            ["Avalonia.Host.Com.IAvnStackPanel"] = 4,
            ["Avalonia.Host.Com.IAvnTextBlock"] = 4,
            ["Avalonia.Host.Com.IAvnTemplatedControl"] = 4,
            ["Avalonia.Host.Com.IAvnItemsControl"] = 4,
            ["Avalonia.Host.Com.IAvnSelectingItemsControl"] = 4,
            ["Avalonia.Host.Com.IAvnTextBox"] = 4,
            ["Avalonia.Host.Com.IAvnRangeBase"] = 4,
            ["Avalonia.Host.Com.IAvnSlider"] = 4,
            ["Avalonia.Host.Com.IAvnProgressBar"] = 4,
            // The completeness and definitions waves widened these and nothing has moved them
            // since, so they stay on the version 5 IIDs they published there.
            ["Avalonia.Host.Com.IAvnContentControl"] = 5,
            ["Avalonia.Host.Com.IAvnHeaderedContentControl"] = 5,
            ["Avalonia.Host.Com.IAvnExpander"] = 5,
            ["Avalonia.Host.Com.IAvnButton"] = 5,
            ["Avalonia.Host.Com.IAvnToggleButton"] = 5,
            ["Avalonia.Host.Com.IAvnCheckBox"] = 5,
            ["Avalonia.Host.Com.IAvnRadioButton"] = 5,
            ["Avalonia.Host.Com.IAvnToggleSwitch"] = 5,
            ["Avalonia.Host.Com.IAvnListBox"] = 5,
            ["Avalonia.Host.Com.IAvnComboBox"] = 5,
            ["Avalonia.Host.Com.IAvnListBoxItem"] = 5,
            ["Avalonia.Host.Com.IAvnComboBoxItem"] = 5,
            ["Avalonia.Host.Com.IAvnScrollViewer"] = 5,
            ["Avalonia.Host.Com.IAvnWindow"] = 5,
            ["Avalonia.Host.Com.IAvnGrid"] = 5,
            // The factory grew a creator per new control plus GetToolTipStatics, so its vtable
            // moved and it republishes at version 3.
            ["Avalonia.Host.Com.IAvnControlFactory"] = 3,
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
            ],
            ["Avalonia.Controls.ContentControl"] =
                ["Content", "HorizontalContentAlignment", "VerticalContentAlignment"],
            ["Avalonia.Controls.Primitives.HeaderedContentControl"] = ["Header"],
            ["Avalonia.Controls.ItemsControl"] = ["Items"],
            ["Avalonia.Controls.Primitives.HeaderedItemsControl"] = ["Header"],
            ["Avalonia.Controls.Primitives.SelectingItemsControl"] =
                ["SelectedIndex", "SelectionChanged"],
            ["Avalonia.Controls.Decorator"] = ["Child", "Padding"],
            ["Avalonia.Controls.Border"] =
                ["Background", "BorderBrush", "BorderThickness", "CornerRadius", "BackgroundSizing"],
            ["Avalonia.Controls.Panel"] = ["Background", "Children"],
            ["Avalonia.Controls.Grid"] =
                ["ShowGridLines", "RowSpacing", "ColumnSpacing", "ColumnDefinitions", "RowDefinitions"],
            ["Avalonia.Controls.Canvas"] = [],
            ["Avalonia.Controls.DockPanel"] = ["LastChildFill", "HorizontalSpacing", "VerticalSpacing"],
            ["Avalonia.Controls.Window"] = ["Title", "CanResize", "WindowState", "Show", "Close"],
            ["Avalonia.Controls.StackPanel"] = ["Orientation", "Spacing"],
            ["Avalonia.Controls.TextBlock"] =
                ["Text", "FontSize", "FontWeight", "Foreground", "Padding", "TextAlignment"],
            ["Avalonia.Controls.Image"] =
                ["Source", "Stretch", "StretchDirection", "BlendMode"],
            ["Avalonia.Controls.Button"] =
                ["ClickMode", "IsDefault", "IsCancel", "IsPressed", "Click"],
            ["Avalonia.Controls.Primitives.ToggleButton"] =
                ["IsChecked", "IsThreeState", "IsCheckedChanged"],
            ["Avalonia.Controls.CheckBox"] = [],
            ["Avalonia.Controls.RadioButton"] = ["GroupName"],
            ["Avalonia.Controls.ToggleSwitch"] = ["OnContent", "OffContent"],
            ["Avalonia.Controls.Expander"] =
                ["ExpandDirection", "IsExpanded", "Expanded", "Collapsed"],
            ["Avalonia.Controls.ListBox"] = ["SelectionMode", "SelectAll", "UnselectAll"],
            ["Avalonia.Controls.ComboBox"] =
                ["PlaceholderText", "IsDropDownOpen", "IsEditable", "MaxDropDownHeight"],
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
            ["Avalonia.Controls.Primitives.TemplatedControl"] =
            [
                "Background", "BorderBrush", "BorderThickness", "CornerRadius", "FontSize",
                "Foreground",
            ],
            ["Avalonia.Controls.TextBox"] =
            [
                "Text", "PlaceholderText", "AcceptsReturn", "AcceptsTab", "IsReadOnly",
                "CaretIndex", "SelectionStart", "SelectionEnd", "MaxLength", "MaxLines",
                "MinLines", "LineHeight", "RevealPassword", "TextWrapping", "NewLine",
                "IsUndoEnabled", "UndoLimit", "CanUndo", "CanRedo", "CanCut", "CanCopy",
                "CanPaste", "Clear", "Cut", "Copy", "Paste", "Undo", "Redo", "TextChanged",
            ],
            ["Avalonia.Controls.ScrollViewer"] =
            [
                "BringIntoViewOnFocusChange", "HorizontalScrollBarVisibility",
                "VerticalScrollBarVisibility", "AllowAutoHide", "IsScrollChainingEnabled",
                "IsScrollInertiaEnabled", "IsDeferredScrollingEnabled", "IsExpanded",
                "LineUp", "LineDown", "LineLeft", "LineRight", "PageUp", "PageDown",
                "PageLeft", "PageRight", "ScrollToHome", "ScrollToEnd", "ScrollChanged",
            ],
            ["Avalonia.Controls.Primitives.RangeBase"] =
                ["Minimum", "Maximum", "Value", "SmallChange", "LargeChange", "ValueChanged"],
            ["Avalonia.Controls.Slider"] =
                ["Orientation", "IsDirectionReversed", "IsSnapToTickEnabled", "TickFrequency", "TickPlacement"],
            ["Avalonia.Controls.ProgressBar"] =
                ["IsIndeterminate", "ShowProgressText", "ProgressTextFormat", "Orientation"],
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
            ["Avalonia.Controls.ScrollViewer.ScrollChanged"] = new()
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
