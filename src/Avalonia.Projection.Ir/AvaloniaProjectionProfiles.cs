namespace Avalonia.Projection.Ir;

public static class AvaloniaProjectionProfiles
{
    public static ProjectionPolicy ObjectModelKernel { get; } = new()
    {
        IncludeTypeNames =
        [
            "Avalonia.AvaloniaObject",
            "Avalonia.StyledElement",
            "Avalonia.Controls.Control",
            "Avalonia.Controls.ContentControl",
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
            "Avalonia.Controls.TextBox",
            "Avalonia.Controls.ScrollViewer",
            "Avalonia.Controls.Primitives.RangeBase",
            "Avalonia.Controls.Slider",
            "Avalonia.Controls.ProgressBar",
        ],
        IncludeMembers = new Dictionary<string, IReadOnlyList<string>>(StringComparer.Ordinal)
        {
            ["Avalonia.AvaloniaObject"] = [],
            ["Avalonia.StyledElement"] = ["Classes"],
            ["Avalonia.Controls.Control"] = ["IsEnabled"],
            ["Avalonia.Controls.ContentControl"] = ["Content"],
            ["Avalonia.Controls.Decorator"] = ["Child"],
            ["Avalonia.Controls.Border"] = ["BackgroundSizing"],
            ["Avalonia.Controls.Panel"] = ["Children"],
            ["Avalonia.Controls.Grid"] = ["ShowGridLines", "RowSpacing", "ColumnSpacing"],
            ["Avalonia.Controls.Canvas"] = [],
            ["Avalonia.Controls.DockPanel"] = ["LastChildFill", "HorizontalSpacing", "VerticalSpacing"],
            ["Avalonia.Controls.Window"] = ["Title", "Show", "Close"],
            ["Avalonia.Controls.StackPanel"] = ["Orientation", "Spacing"],
            ["Avalonia.Controls.TextBlock"] = ["Text"],
            ["Avalonia.Controls.Button"] = ["Click"],
            ["Avalonia.Controls.Primitives.ToggleButton"] = ["IsChecked", "IsCheckedChanged"],
            ["Avalonia.Controls.CheckBox"] = [],
            ["Avalonia.Controls.Primitives.TemplatedControl"] = [],
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
