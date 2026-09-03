namespace Avalonia.Projection.Ir;

public static class AvaloniaProjectionProfiles
{
    public static ProjectionPolicy ObjectModelKernel { get; } = new()
    {
        // The completeness wave widens the flattened vtables of Avalonia.Controls.ContentControl,
        // Button, Primitives.ToggleButton, ListBox and ComboBox, so every projected interface at
        // or below one of them gets a new IID at version 5. The interfaces whose flattened vtable
        // did not move are pinned below and keep the IID they last published.
        DefaultProjectedTypeAbiVersion = 5,
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
            // ContentControl, Button, ToggleButton, ListBox or ComboBox, so their flattened
            // vtables are byte-identical to version 4.
            ["Avalonia.Host.Com.IAvnBorder"] = 4,
            ["Avalonia.Host.Com.IAvnPanel"] = 4,
            ["Avalonia.Host.Com.IAvnCanvas"] = 4,
            ["Avalonia.Host.Com.IAvnDockPanel"] = 4,
            ["Avalonia.Host.Com.IAvnGrid"] = 4,
            ["Avalonia.Host.Com.IAvnStackPanel"] = 4,
            ["Avalonia.Host.Com.IAvnTextBlock"] = 4,
            ["Avalonia.Host.Com.IAvnTemplatedControl"] = 4,
            ["Avalonia.Host.Com.IAvnItemsControl"] = 4,
            ["Avalonia.Host.Com.IAvnSelectingItemsControl"] = 4,
            ["Avalonia.Host.Com.IAvnTextBox"] = 4,
            ["Avalonia.Host.Com.IAvnRangeBase"] = 4,
            ["Avalonia.Host.Com.IAvnSlider"] = 4,
            ["Avalonia.Host.Com.IAvnProgressBar"] = 4,
            // The factory gained CreateSolidColorBrush at version 2 and gains no slot here.
            ["Avalonia.Host.Com.IAvnControlFactory"] = 2,
        },
        IncludeTypeNames =
        [
            "Avalonia.AvaloniaObject",
            "Avalonia.StyledElement",
            "Avalonia.Controls.Control",
            "Avalonia.Controls.ContentControl",
            "Avalonia.Controls.Primitives.HeaderedContentControl",
            "Avalonia.Controls.ItemsControl",
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
            ["Avalonia.Controls.Primitives.SelectingItemsControl"] =
                ["SelectedIndex", "SelectionChanged"],
            ["Avalonia.Controls.Decorator"] = ["Child", "Padding"],
            ["Avalonia.Controls.Border"] =
                ["Background", "BorderBrush", "BorderThickness", "CornerRadius", "BackgroundSizing"],
            ["Avalonia.Controls.Panel"] = ["Background", "Children"],
            ["Avalonia.Controls.Grid"] = ["ShowGridLines", "RowSpacing", "ColumnSpacing"],
            ["Avalonia.Controls.Canvas"] = [],
            ["Avalonia.Controls.DockPanel"] = ["LastChildFill", "HorizontalSpacing", "VerticalSpacing"],
            ["Avalonia.Controls.Window"] = ["Title", "CanResize", "WindowState", "Show", "Close"],
            ["Avalonia.Controls.StackPanel"] = ["Orientation", "Spacing"],
            ["Avalonia.Controls.TextBlock"] =
                ["Text", "FontSize", "FontWeight", "Foreground", "Padding", "TextAlignment"],
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
        },
    };
}
