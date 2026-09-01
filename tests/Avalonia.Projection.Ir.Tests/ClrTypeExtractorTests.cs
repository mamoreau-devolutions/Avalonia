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

        var classes = Type(ir, "IAvnStyledElement").Properties.Single();
        Assert.Equal(MarshallingKind.StringUtf16, classes.ElementKind);
        Assert.Contains(ir.AttachedProperties, property =>
            property.OwnerName == nameof(Grid) && property.Name == "Row");
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
