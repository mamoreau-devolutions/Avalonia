using System;
using System.Linq;
using Avalonia.Controls;
using Avalonia.Controls.Primitives;
using Avalonia.Projection.Ir;
using Xunit;

namespace Avalonia.Projection.Ir.Tests;

public class ClrTypeExtractorTests
{
    private static readonly Type[] KernelTypes =
    [
        typeof(AvaloniaObject),
        typeof(StyledElement),
        typeof(Control),
        typeof(ContentControl),
        typeof(HeaderedContentControl),
        typeof(ItemsControl),
        typeof(SelectingItemsControl),
        typeof(Decorator),
        typeof(Border),
        typeof(Panel),
        typeof(Grid),
        typeof(Canvas),
        typeof(DockPanel),
        typeof(Window),
        typeof(StackPanel),
        typeof(TextBlock),
        typeof(TemplatedControl),
        typeof(Button),
        typeof(ToggleButton),
        typeof(CheckBox),
        typeof(RadioButton),
        typeof(ToggleSwitch),
        typeof(Expander),
        typeof(ListBox),
        typeof(ComboBox),
        typeof(ListBoxItem),
        typeof(ComboBoxItem),
        typeof(TextBox),
        typeof(ScrollViewer),
        typeof(RangeBase),
        typeof(Slider),
        typeof(ProgressBar),
    ];

    [Fact]
    public void Projects_kernel_types_properties_commands_and_nearest_bases()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        Assert.Equal(ProjectionIr.CurrentVersion, ir.Version);
        Assert.Equal(KernelTypes.Length, ir.Types.Count);

        var contentControl = Type(ir, "IAvnContentControl");
        Assert.Equal("Avalonia.Host.Com.IAvnTemplatedControl", contentControl.BaseFullName);
        var content = Assert.Single(contentControl.Properties);
        Assert.Equal(MarshallingKind.ComInterface, content.Kind);
        Assert.Equal("Avalonia.Host.Com.IAvnControl", content.InterfaceName);
        Assert.True(content.IsNullable);

        var window = Type(ir, "IAvnWindow");
        Assert.Equal("Avalonia.Host.Com.IAvnContentControl", window.BaseFullName);
        Assert.Contains(window.Properties, p => p.Name == nameof(Window.Title));
        Assert.Contains(window.Methods, m => m.Name == nameof(Window.Show) && m.Parameters.Count == 0);
        Assert.Contains(window.Methods, m => m.Name == nameof(Window.Close) && m.Parameters.Count == 0);

        var stackPanel = Type(ir, "IAvnStackPanel");
        Assert.Equal("Avalonia.Host.Com.IAvnPanel", stackPanel.BaseFullName);
        Assert.Equal(MarshallingKind.I32, stackPanel.Properties.Single(p => p.Name == nameof(StackPanel.Orientation)).Kind);
        Assert.Equal(MarshallingKind.F64, stackPanel.Properties.Single(p => p.Name == nameof(StackPanel.Spacing)).Kind);
        var children = Type(ir, "IAvnPanel").Properties.Single(p => p.Name == nameof(Panel.Children));
        Assert.Equal(MarshallingKind.ComCollection, children.Kind);
        Assert.Equal("Avalonia.Host.Com.IAvnControlList", children.InterfaceName);
        Assert.Equal("Avalonia.Host.Com.IAvnControl", children.ElementInterfaceName);
        Assert.Equal(MarshallingKind.ComInterface, children.ElementKind);

        var text = Type(ir, "IAvnTextBlock").Properties.Single(p => p.Name == nameof(TextBlock.Text));
        Assert.Equal(MarshallingKind.StringUtf16, text.Kind);
        Assert.True(text.IsNullable);

        var click = Assert.Single(Type(ir, "IAvnButton").Events);
        Assert.Equal(nameof(Button.Click), click.Name);
        Assert.Equal("Avalonia.Host.Com.IAvnButtonClickHandler", click.HandlerInterfaceName);
        Assert.Equal(EventPayloadKind.None, click.PayloadKind);
        Assert.False(string.IsNullOrWhiteSpace(click.HandlerInterfaceIid));

        var isChecked = Type(ir, "IAvnToggleButton").Properties.Single();
        Assert.Equal(MarshallingKind.NullableBool, isChecked.Kind);

        var controlEvents = Type(ir, "IAvnControl").Events;
        Assert.Equal(3, controlEvents.Count);
        var keyDown = controlEvents.Single(@event => @event.Name == "KeyDown");
        Assert.Equal(EventPayloadKind.Fields, keyDown.PayloadKind);
        Assert.Equal(5, keyDown.Parameters.Count);
        Assert.Equal(
            ParameterDirection.InOut,
            keyDown.Parameters.Single(parameter => parameter.Name == "Handled").Direction);
        Assert.All(
            controlEvents.Where(@event => @event.Name.StartsWith("Pointer", StringComparison.Ordinal)),
            @event => Assert.Equal(EventPayloadKind.None, @event.PayloadKind));
        Assert.All(
            Type(ir, "IAvnControl").Properties.Where(property =>
                property.Name is nameof(Control.Width) or nameof(Control.Height)),
            property => Assert.Equal(MarshallingKind.F64, property.Kind));

        var toggleSwitch = Type(ir, "IAvnToggleSwitch");
        Assert.Equal("Avalonia.Host.Com.IAvnToggleButton", toggleSwitch.BaseFullName);
        Assert.All(toggleSwitch.Properties, property =>
            Assert.Equal("Avalonia.Host.Com.IAvnControl", property.InterfaceName));

        var expander = Type(ir, "IAvnExpander");
        Assert.Equal("Avalonia.Host.Com.IAvnHeaderedContentControl", expander.BaseFullName);
        Assert.Equal(2, expander.Events.Count);

        var items = Type(ir, "IAvnItemsControl").Properties.Single();
        Assert.Equal("Avalonia.Host.Com.IAvnItemList", items.InterfaceName);
        Assert.Equal(MarshallingKind.ComInterface, items.ElementKind);

        var styledElement = Type(ir, "IAvnStyledElement");
        var classes = styledElement.Properties.Single(property => property.Name == "Classes");
        Assert.Equal(MarshallingKind.StringUtf16, classes.ElementKind);
        var name = styledElement.Properties.Single(property => property.Name == nameof(StyledElement.Name));
        Assert.Equal(MarshallingKind.StringUtf16, name.Kind);
        Assert.True(name.IsNullable);
        Assert.Contains(ir.AttachedProperties, property =>
            property.OwnerName == nameof(Grid) && property.Name == "Row");
    }

    [Fact]
    public void Projects_layout_members_onto_control_decorator_and_window()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        var control = Type(ir, "IAvnControl");
        Assert.Equal(
            MarshallingKind.Thickness,
            control.Properties.Single(property => property.Name == nameof(Control.Margin)).Kind);
        Assert.All(
            control.Properties.Where(property => property.Name is
                nameof(Control.MinWidth) or nameof(Control.MinHeight) or
                nameof(Control.MaxWidth) or nameof(Control.MaxHeight) or nameof(Control.Opacity)),
            property => Assert.Equal(MarshallingKind.F64, property.Kind));
        Assert.Equal(
            MarshallingKind.Bool,
            control.Properties.Single(property => property.Name == nameof(Control.IsVisible)).Kind);
        Assert.All(
            control.Properties.Where(property => property.Name is
                nameof(Control.HorizontalAlignment) or nameof(Control.VerticalAlignment)),
            property =>
            {
                Assert.Equal(MarshallingKind.I32, property.Kind);
                Assert.True(property.CanRead && property.CanWrite);
            });
        Assert.All(
            new[] { "HorizontalAlignment", "VerticalAlignment", "WindowState" },
            enumName => Assert.Contains(ir.Enums, projected => projected.Name == enumName));

        Assert.Equal(
            MarshallingKind.Thickness,
            Type(ir, "IAvnDecorator").Properties
                .Single(property => property.Name == nameof(Decorator.Padding)).Kind);

        var window = Type(ir, "IAvnWindow");
        Assert.Equal(
            MarshallingKind.Bool,
            window.Properties.Single(property => property.Name == nameof(Window.CanResize)).Kind);
        Assert.Equal(
            MarshallingKind.I32,
            window.Properties.Single(property => property.Name == nameof(Window.WindowState)).Kind);
    }

    [Fact]
    public void Layout_members_keep_the_abi_version_of_the_interfaces_they_widened()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        // AvaloniaObject projects no members, so its flattened vtable is unchanged and it
        // must keep the IID it published at version 2.
        var avaloniaObject = Type(ir, "IAvnAvaloniaObject");
        Assert.Equal(2, avaloniaObject.AbiVersion);
        Assert.Equal(
            ClrTypeExtractor.CreateDeterministicIid(avaloniaObject.FullName, 2),
            avaloniaObject.Iid);

        // StyledElement, Control and Decorator gained nothing in the chrome wave and neither
        // did any of their bases, so their flattened vtables still match version 3 exactly.
        Assert.All(
            new[] { "IAvnStyledElement", "IAvnControl", "IAvnDecorator" },
            name =>
            {
                var type = Type(ir, name);
                Assert.Equal(3, type.AbiVersion);
                Assert.Equal(
                    ClrTypeExtractor.CreateDeterministicIid(type.FullName, 3),
                    type.Iid);
            });
    }

    [Fact]
    public void Chrome_members_bump_the_abi_version_of_every_widened_interface()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);
        string[] unmoved =
            ["IAvnAvaloniaObject", "IAvnStyledElement", "IAvnControl", "IAvnDecorator"];

        // Border, Panel, TemplatedControl and TextBlock all grew slots, so they and every
        // interface below them republish under a version 4 IID.
        Assert.All(
            ir.Types.Where(type => !unmoved.Contains(type.Name)),
            type =>
            {
                Assert.Equal(4, type.AbiVersion);
                Assert.Equal(
                    ClrTypeExtractor.CreateDeterministicIid(type.FullName, 4),
                    type.Iid);
                Assert.NotEqual(
                    ClrTypeExtractor.CreateDeterministicIid(type.FullName, 3),
                    type.Iid);
            });

        // The factory grew CreateSolidColorBrush, so it republishes too.
        Assert.Equal(2, ir.FactoryAbiVersion);
        Assert.Equal(
            ClrTypeExtractor.CreateDeterministicIid("Avalonia.Host.Com.IAvnControlFactory", 2),
            ir.FactoryIid);
    }

    [Fact]
    public void Projects_solid_brushes_and_the_remaining_chrome_members()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        Assert.Equal("Avalonia.Host.Com.IAvnBrush", ir.BrushInterfaceName);
        Assert.Equal(1, ir.BrushAbiVersion);
        Assert.Equal(
            ClrTypeExtractor.CreateDeterministicIid("Avalonia.Host.Com.IAvnBrush", 1),
            ir.BrushInterfaceIid);

        // Every IBrush member projects as the one brush interface and is always nullable,
        // because a control with no brush reports a null pointer rather than a colour.
        var brushMembers = new[]
        {
            (Type: "IAvnBorder", Member: nameof(Border.Background)),
            (Type: "IAvnBorder", Member: nameof(Border.BorderBrush)),
            (Type: "IAvnPanel", Member: nameof(Panel.Background)),
            (Type: "IAvnTemplatedControl", Member: nameof(TemplatedControl.Background)),
            (Type: "IAvnTemplatedControl", Member: nameof(TemplatedControl.BorderBrush)),
            (Type: "IAvnTemplatedControl", Member: nameof(TemplatedControl.Foreground)),
            (Type: "IAvnTextBlock", Member: nameof(TextBlock.Foreground)),
        };
        Assert.All(brushMembers, entry =>
        {
            var property = Type(ir, entry.Type).Properties
                .Single(candidate => candidate.Name == entry.Member);
            Assert.Equal(MarshallingKind.Brush, property.Kind);
            Assert.Equal("Avalonia.Host.Com.IAvnBrush", property.InterfaceName);
            Assert.Equal(ir.BrushInterfaceIid, property.InterfaceIid);
            Assert.True(property.IsNullable);
            Assert.True(property.CanRead && property.CanWrite);
        });

        var border = Type(ir, "IAvnBorder");
        Assert.Equal(
            MarshallingKind.Thickness,
            border.Properties.Single(p => p.Name == nameof(Border.BorderThickness)).Kind);
        Assert.Equal(
            MarshallingKind.CornerRadius,
            border.Properties.Single(p => p.Name == nameof(Border.CornerRadius)).Kind);

        var templated = Type(ir, "IAvnTemplatedControl");
        Assert.Equal(
            MarshallingKind.F64,
            templated.Properties.Single(p => p.Name == nameof(TemplatedControl.FontSize)).Kind);

        var textBlock = Type(ir, "IAvnTextBlock");
        Assert.Equal(
            MarshallingKind.Thickness,
            textBlock.Properties.Single(p => p.Name == nameof(TextBlock.Padding)).Kind);
        Assert.All(
            textBlock.Properties.Where(p => p.Name is
                nameof(TextBlock.FontWeight) or nameof(TextBlock.TextAlignment)),
            property => Assert.Equal(MarshallingKind.I32, property.Kind));
        Assert.All(
            new[] { "FontWeight", "TextAlignment" },
            enumName => Assert.Contains(ir.Enums, projected => projected.Name == enumName));

        // Gradient/drawing/visual brushes are deliberately out of scope, so nothing else in
        // the object model may claim the brush kind.
        Assert.DoesNotContain(
            ir.Types.SelectMany(type => type.Properties),
            property => property.Kind == MarshallingKind.Brush &&
                property.InterfaceName != "Avalonia.Host.Com.IAvnBrush");
    }

    [Fact]
    public void Chrome_members_are_not_duplicated_onto_derived_interfaces()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        // Background is declared once on Panel and once on TemplatedControl; a derived
        // interface that re-declared it would add a second pair of slots for one property.
        Assert.All(
            new[] { "IAvnGrid", "IAvnCanvas", "IAvnDockPanel", "IAvnStackPanel" },
            name => Assert.DoesNotContain(
                Type(ir, name).Properties,
                property => property.Name == nameof(Panel.Background)));
        Assert.All(
            new[] { "IAvnButton", "IAvnContentControl", "IAvnWindow", "IAvnTextBox" },
            name => Assert.DoesNotContain(
                Type(ir, name).Properties,
                property => property.Name is nameof(TemplatedControl.Background)
                    or nameof(TemplatedControl.Foreground)));
    }

    [Fact]
    public void Produces_stable_unique_iids_and_explicit_gap_report()
    {
        var first = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);
        var second = ClrTypeExtractor.Extract(KernelTypes.Reverse(), AvaloniaProjectionProfiles.ObjectModelKernel);

        Assert.Equal(
            first.Types.Select(t => (t.FullName, t.Iid)),
            second.Types.Select(t => (t.FullName, t.Iid)));
        Assert.Equal(first.Types.Count, first.Types.Select(t => t.Iid).Distinct().Count());
        Assert.Contains(first.Skipped, s =>
            s.Owner == typeof(Button).FullName &&
            s.Member == nameof(Button.IsDefault) &&
            s.Reason == "Not included by projection policy");
    }

    [Fact]
    public void Iids_are_versioned_per_interface_not_by_ir_schema()
    {
        const string name = "Avalonia.Host.Com.IAvnButton";

        Assert.Equal(
            ClrTypeExtractor.CreateDeterministicIid(name, 1),
            ClrTypeExtractor.CreateDeterministicIid(name));
        Assert.NotEqual(
            ClrTypeExtractor.CreateDeterministicIid(name, 1),
            ClrTypeExtractor.CreateDeterministicIid(name, 2));
    }

    private static ProjectedType Type(ProjectionIr ir, string name) =>
        ir.Types.Single(t => t.Name == name);
}
