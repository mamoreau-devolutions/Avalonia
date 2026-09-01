namespace Avalonia.Projection.Ir;

public static class AvaloniaProjectionProfiles
{
    public static ProjectionPolicy ObjectModelKernel { get; } = new()
    {
        IncludeTypeNames =
        [
            "Avalonia.AvaloniaObject",
            "Avalonia.Controls.Control",
            "Avalonia.Controls.ContentControl",
            "Avalonia.Controls.Panel",
            "Avalonia.Controls.Window",
            "Avalonia.Controls.StackPanel",
            "Avalonia.Controls.TextBlock",
            "Avalonia.Controls.Button",
        ],
        IncludeMembers = new Dictionary<string, IReadOnlyList<string>>(StringComparer.Ordinal)
        {
            ["Avalonia.AvaloniaObject"] = [],
            ["Avalonia.Controls.Control"] = ["IsEnabled"],
            ["Avalonia.Controls.ContentControl"] = ["Content"],
            ["Avalonia.Controls.Panel"] = ["Children"],
            ["Avalonia.Controls.Window"] = ["Title", "Show", "Close"],
            ["Avalonia.Controls.StackPanel"] = ["Orientation", "Spacing"],
            ["Avalonia.Controls.TextBlock"] = ["Text"],
            ["Avalonia.Controls.Button"] = [],
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
                IsNullable = false,
            },
        },
    };
}
