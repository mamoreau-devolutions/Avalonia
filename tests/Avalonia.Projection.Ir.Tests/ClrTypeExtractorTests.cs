using System;
using System.Collections.Generic;
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
        typeof(HeaderedItemsControl),
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
        typeof(Image),
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
        typeof(TabControl),
        typeof(TabItem),
        typeof(TreeView),
        typeof(TreeViewItem),
        typeof(ToolTip),
        typeof(FlyoutBase),
        typeof(PopupFlyoutBase),
        typeof(Flyout),
        typeof(MenuBase),
        typeof(Menu),
        typeof(HeaderedSelectingItemsControl),
        typeof(MenuItem),
        typeof(SplitView),
        typeof(DatePicker),
        typeof(TimePicker),
        typeof(WrapPanel),
        typeof(UniformGrid),
        typeof(RelativePanel),
        typeof(Viewbox),
        typeof(FlexPanel),
        typeof(Thumb),
        typeof(GridSplitter),
        typeof(RepeatButton),
        typeof(DropDownButton),
        typeof(SplitButton),
        typeof(ToggleSplitButton),
        typeof(HyperlinkButton),
        typeof(ContextMenu),
        typeof(MenuFlyout),
        typeof(Spinner),
        typeof(ButtonSpinner),
        typeof(NumericUpDown),
        typeof(AutoCompleteBox),
        typeof(MaskedTextBox),
        typeof(SelectableTextBlock),
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
        var content = contentControl.Properties.Single(p => p.Name == nameof(ContentControl.Content));
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

        var isChecked = Type(ir, "IAvnToggleButton").Properties
            .Single(property => property.Name == nameof(ToggleButton.IsChecked));
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

        // StyledElement, Control and Decorator have gained nothing since the layout wave and
        // neither has any of their bases, so their flattened vtables still match version 3
        // exactly.
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
    public void Chrome_members_keep_the_abi_version_of_the_interfaces_they_widened()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        // Border, Panel, TemplatedControl and TextBlock grew slots in the chrome wave and
        // nothing since has moved them or anything above them, so they and the interfaces that
        // derive from them without gaining anything stay on their version 4 IIDs.
        Assert.All(
            new[]
            {
                "IAvnBorder", "IAvnPanel", "IAvnCanvas", "IAvnDockPanel",
                "IAvnStackPanel", "IAvnTextBlock", "IAvnTemplatedControl", "IAvnItemsControl",
                "IAvnSelectingItemsControl", "IAvnTextBox", "IAvnRangeBase", "IAvnSlider",
                "IAvnProgressBar",
            },
            name =>
            {
                var type = Type(ir, name);
                Assert.Equal(4, type.AbiVersion);
                Assert.Equal(
                    ClrTypeExtractor.CreateDeterministicIid(type.FullName, 4),
                    type.Iid);
            });

        // The factory grew a creator per wave A control plus GetToolTipStatics, then one per
        // constructible wave B type, then one per constructible wave C type, so it has moved
        // three times off the version 2 IID it published for CreateSolidColorBrush.
        Assert.Equal(7, ir.FactoryAbiVersion);
        Assert.Equal(
            ClrTypeExtractor.CreateDeterministicIid("Avalonia.Host.Com.IAvnControlFactory", 7),
            ir.FactoryIid);
    }

    [Fact]
    public void Completeness_members_keep_the_abi_version_of_every_widened_interface()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        // ContentControl, Button, ToggleButton, ListBox and ComboBox all grew slots in the
        // completeness wave and Grid joined them in the definitions wave. Wave A adds only new
        // interfaces below them, so their flattened vtables still match version 5.
        string[] pinnedAtFive =
        [
            "IAvnContentControl", "IAvnHeaderedContentControl", "IAvnExpander", "IAvnButton",
            "IAvnToggleButton", "IAvnCheckBox", "IAvnRadioButton", "IAvnToggleSwitch",
            "IAvnListBox", "IAvnComboBox", "IAvnListBoxItem", "IAvnComboBoxItem",
            "IAvnScrollViewer", "IAvnWindow", "IAvnGrid",
        ];

        Assert.All(
            pinnedAtFive,
            name =>
            {
                var type = Type(ir, name);
                Assert.Equal(5, type.AbiVersion);
                Assert.Equal(
                    ClrTypeExtractor.CreateDeterministicIid(type.FullName, 5),
                    type.Iid);
            });

        Assert.All(
            ir.Types.Where(type => !pinnedAtFive.Contains(type.Name)),
            type => Assert.NotEqual(5, type.AbiVersion));
    }

    [Fact]
    public void Wave_a_controls_publish_new_interfaces_at_version_one()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        // Every wave A interface is brand new, so it publishes at version 1 rather than
        // inheriting the version its neighbours happen to sit on.
        Assert.All(
            new[]
            {
                "IAvnImage", "IAvnHeaderedItemsControl", "IAvnTabControl", "IAvnTabItem",
                "IAvnTreeView", "IAvnTreeViewItem", "IAvnToolTip",
            },
            name =>
            {
                var type = Type(ir, name);
                Assert.Equal(1, type.AbiVersion);
                Assert.Equal(
                    ClrTypeExtractor.CreateDeterministicIid(type.FullName, 1),
                    type.Iid);
            });

        // Wave A widens no existing interface, so nothing below the new types moved: every
        // interface that shipped before keeps the exact IID it last published.
        var pinned = new Dictionary<string, int>(StringComparer.Ordinal)
        {
            ["IAvnAvaloniaObject"] = 2,
            ["IAvnStyledElement"] = 3,
            ["IAvnControl"] = 3,
            ["IAvnDecorator"] = 3,
            ["IAvnItemsControl"] = 4,
            ["IAvnSelectingItemsControl"] = 4,
            ["IAvnContentControl"] = 5,
            ["IAvnHeaderedContentControl"] = 5,
        };
        Assert.All(pinned, entry =>
        {
            var type = Type(ir, entry.Key);
            Assert.Equal(entry.Value, type.AbiVersion);
            Assert.Equal(
                ClrTypeExtractor.CreateDeterministicIid(type.FullName, entry.Value),
                type.Iid);
        });
    }

    [Fact]
    public void Projects_the_wave_a_controls_onto_the_types_that_declare_them()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        // Image.Source is an IImage, which has no ABI shape, so it crosses as the source string
        // the host resolves into a bitmap. The converter, not the CLR type, owns the conversion.
        var image = Type(ir, "IAvnImage");
        Assert.Equal("Avalonia.Host.Com.IAvnControl", image.BaseFullName);
        var source = image.Properties.Single(property => property.Name == nameof(Image.Source));
        Assert.Equal(MarshallingKind.StringUtf16, source.Kind);
        Assert.Equal("Avalonia.Media.IImage", source.ManagedTypeName);
        Assert.Equal("Avalonia.Host.Com.AvnImageSource", source.StringConverterTypeName);
        Assert.True(source.IsNullable);
        Assert.True(source.CanRead && source.CanWrite);
        Assert.All(
            new[] { nameof(Image.Stretch), nameof(Image.StretchDirection), nameof(Image.BlendMode) },
            name => Assert.Equal(
                MarshallingKind.I32,
                image.Properties.Single(property => property.Name == name).Kind));

        // TabControl derives from SelectingItemsControl, so Items and SelectedIndex are
        // inherited rather than redeclared.
        var tabControl = Type(ir, "IAvnTabControl");
        Assert.Equal("Avalonia.Host.Com.IAvnSelectingItemsControl", tabControl.BaseFullName);
        Assert.Equal(
            [nameof(TabControl.HorizontalContentAlignment), nameof(TabControl.TabStripPlacement),
                nameof(TabControl.VerticalContentAlignment)],
            tabControl.Properties.Select(property => property.Name).OrderBy(n => n, StringComparer.Ordinal));

        var tabItem = Type(ir, "IAvnTabItem");
        Assert.Equal("Avalonia.Host.Com.IAvnHeaderedContentControl", tabItem.BaseFullName);
        Assert.Equal(
            MarshallingKind.Bool,
            tabItem.Properties.Single(property => property.Name == nameof(TabItem.IsSelected)).Kind);
        // TabItem.TabStripPlacement is a Dock?, and a nullable enum has no ABI shape, so it is
        // reported as a gap rather than silently flattened to a non-nullable enum.
        Assert.DoesNotContain(
            tabItem.Properties,
            property => property.Name == nameof(TabItem.TabStripPlacement));

        // TreeView is an ItemsControl, not a SelectingItemsControl, so it carries Items but no
        // SelectedIndex; the object-valued selection members stay in the gap report.
        var treeView = Type(ir, "IAvnTreeView");
        Assert.Equal("Avalonia.Host.Com.IAvnItemsControl", treeView.BaseFullName);
        Assert.DoesNotContain(treeView.Properties, property => property.Name == "SelectedIndex");
        Assert.Contains(ir.Skipped, skipped =>
            skipped.Owner == typeof(TreeView).FullName && skipped.Member == nameof(TreeView.SelectedItem));
        var expand = treeView.Methods.Single(method => method.ManagedName == nameof(TreeView.ExpandSubTree));
        Assert.Equal("Avalonia.Host.Com.IAvnTreeViewItem", expand.Parameters.Single().InterfaceName);
        Assert.Contains(treeView.Methods, method => method.Name == nameof(TreeView.UnselectAll));
        // TreeView declares its own SelectionChanged because it is not a SelectingItemsControl.
        var treeSelectionChanged = treeView.Events.Single();
        Assert.Equal("Avalonia.Host.Com.IAvnTreeViewSelectionChangedHandler", treeSelectionChanged.HandlerInterfaceName);
        Assert.Equal(EventPayloadKind.None, treeSelectionChanged.PayloadKind);

        // TreeViewItem's Header comes from HeaderedItemsControl and crosses as a control, the
        // same shape HeaderedContentControl.Header already uses.
        var treeViewItem = Type(ir, "IAvnTreeViewItem");
        Assert.Equal("Avalonia.Host.Com.IAvnHeaderedItemsControl", treeViewItem.BaseFullName);
        var header = Type(ir, "IAvnHeaderedItemsControl").Properties.Single();
        Assert.Equal(nameof(HeaderedItemsControl.Header), header.Name);
        Assert.Equal(MarshallingKind.ComInterface, header.Kind);
        Assert.Equal("Avalonia.Host.Com.IAvnControl", header.InterfaceName);
        Assert.All(
            new[] { nameof(TreeViewItem.IsExpanded), nameof(TreeViewItem.IsSelected) },
            name => Assert.Equal(
                MarshallingKind.Bool,
                treeViewItem.Properties.Single(property => property.Name == name).Kind));
        var level = treeViewItem.Properties.Single(property => property.Name == nameof(TreeViewItem.Level));
        Assert.True(level.CanRead);
        Assert.False(level.CanWrite);
        Assert.Equal(
            ["Collapsed", "Expanded"],
            treeViewItem.Events.Select(@event => @event.Name).OrderBy(n => n, StringComparer.Ordinal));
        Assert.All(treeViewItem.Events, @event => Assert.Equal(EventPayloadKind.None, @event.PayloadKind));
    }

    [Fact]
    public void Wave_b_controls_publish_new_interfaces_at_version_one()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        Assert.All(
            new[]
            {
                "IAvnFlyoutBase", "IAvnPopupFlyoutBase", "IAvnFlyout", "IAvnMenuBase", "IAvnMenu",
                "IAvnHeaderedSelectingItemsControl", "IAvnMenuItem", "IAvnSplitView",
                "IAvnDatePicker", "IAvnTimePicker",
            },
            name =>
            {
                var type = Type(ir, name);
                Assert.Equal(1, type.AbiVersion);
                Assert.Equal(
                    ClrTypeExtractor.CreateDeterministicIid(type.FullName, 1),
                    type.Iid);
            });

        // A flyout is an AvaloniaObject rather than a Control, so nothing existing sits above
        // the new interfaces and nothing existing moved.
        var pinned = new Dictionary<string, int>(StringComparer.Ordinal)
        {
            ["IAvnAvaloniaObject"] = 2,
            ["IAvnControl"] = 3,
            ["IAvnItemsControl"] = 4,
            ["IAvnSelectingItemsControl"] = 4,
            ["IAvnTemplatedControl"] = 4,
            ["IAvnContentControl"] = 5,
        };
        Assert.All(pinned, entry =>
        {
            var type = Type(ir, entry.Key);
            Assert.Equal(entry.Value, type.AbiVersion);
            Assert.Equal(
                ClrTypeExtractor.CreateDeterministicIid(type.FullName, entry.Value),
                type.Iid);
        });

        // Reusing a retired IID would silently hand a stale consumer a changed contract, so no
        // two projected interfaces may ever share one.
        Assert.Equal(
            ir.Types.Count,
            ir.Types.Select(type => type.Iid).Distinct(StringComparer.Ordinal).Count());
    }

    [Fact]
    public void Projects_the_flyout_trio_with_an_imperative_show_rather_than_an_attached_property()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        // FlyoutBase derives from AvaloniaObject, not Control, so the projected interface hangs
        // straight off IAvnAvaloniaObject and inserts no slot into anything that shipped.
        var flyoutBase = Type(ir, "IAvnFlyoutBase");
        Assert.Equal("Avalonia.Host.Com.IAvnAvaloniaObject", flyoutBase.BaseFullName);
        Assert.False(flyoutBase.IsConstructible);

        // ShowAt is how a flyout reaches a control: the attached-property pipeline carries
        // scalars and strings only, so there is no COM-valued AttachedFlyout in this wave.
        var showAt = flyoutBase.Methods.Single(method => method.ManagedName == "ShowAt");
        var placementTarget = showAt.Parameters.Single();
        Assert.Equal(MarshallingKind.ComInterface, placementTarget.Kind);
        Assert.Equal("Avalonia.Host.Com.IAvnControl", placementTarget.InterfaceName);
        Assert.Contains(flyoutBase.Methods, method => method.Name == "Hide");
        Assert.DoesNotContain(
            ir.AttachedProperties,
            property => property.Name is "AttachedFlyout" or "Flyout");
        Assert.Contains(ir.Skipped, skipped =>
            skipped.Owner == typeof(Button).FullName && skipped.Member == nameof(Button.Flyout));

        var target = flyoutBase.Properties.Single(property => property.Name == "Target");
        Assert.Equal(MarshallingKind.ComInterface, target.Kind);
        Assert.True(target.CanRead);
        Assert.False(target.CanWrite);

        // PopupFlyoutBase re-declares ShowAt/Hide as sealed overrides; the flattened vtable
        // publishes each exactly once, from the base that declares it.
        var popupFlyoutBase = Type(ir, "IAvnPopupFlyoutBase");
        Assert.Equal("Avalonia.Host.Com.IAvnFlyoutBase", popupFlyoutBase.BaseFullName);
        Assert.Empty(popupFlyoutBase.Methods);
        Assert.All(
            new[] { "Placement", "ShowMode" },
            name => Assert.Equal(
                MarshallingKind.I32,
                popupFlyoutBase.Properties.Single(property => property.Name == name).Kind));

        // The [Flags] placement members have no single-value name for a combined value, so they
        // stay in the gap report rather than crossing as an enum that cannot round trip.
        Assert.All(
            new[] { "PlacementAnchor", "PlacementGravity", "PlacementConstraintAdjustment" },
            name => Assert.DoesNotContain(
                popupFlyoutBase.Properties,
                property => property.Name == name));

        // Closing is the one wave B event with a payload, and Cancel is written back.
        var closing = popupFlyoutBase.Events.Single(@event => @event.Name == "Closing");
        Assert.Equal(EventPayloadKind.Fields, closing.PayloadKind);
        var cancel = closing.Parameters.Single();
        Assert.Equal("Cancel", cancel.Name);
        Assert.Equal(MarshallingKind.Bool, cancel.Kind);
        Assert.Equal(ParameterDirection.InOut, cancel.Direction);

        var flyout = Type(ir, "IAvnFlyout");
        Assert.Equal("Avalonia.Host.Com.IAvnPopupFlyoutBase", flyout.BaseFullName);
        Assert.True(flyout.IsConstructible);
        var content = flyout.Properties.Single(property => property.Name == "Content");
        Assert.Equal(MarshallingKind.ComInterface, content.Kind);
        Assert.Equal("Avalonia.Host.Com.IAvnControl", content.InterfaceName);
        Assert.Equal("System.Object", content.ManagedTypeName);
    }

    [Fact]
    public void Projects_the_imperative_menu_pair_without_an_icommand()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        // MenuBase owns the open state and the commands; Menu inherits all of it and declares
        // nothing, so Open/Close occupy one slot each rather than two.
        var menuBase = Type(ir, "IAvnMenuBase");
        Assert.Equal("Avalonia.Host.Com.IAvnSelectingItemsControl", menuBase.BaseFullName);
        Assert.Equal(
            ["Close", "Open"],
            menuBase.Methods.Select(method => method.Name).OrderBy(n => n, StringComparer.Ordinal));
        var isOpen = menuBase.Properties.Single();
        Assert.Equal("IsOpen", isOpen.Name);
        // The managed setter is protected, so the ABI publishes a getter only rather than
        // inventing a writable open state the control does not have.
        Assert.True(isOpen.CanRead);
        Assert.False(isOpen.CanWrite);

        var menu = Type(ir, "IAvnMenu");
        Assert.Equal("Avalonia.Host.Com.IAvnMenuBase", menu.BaseFullName);
        Assert.True(menu.IsConstructible);
        Assert.Empty(menu.Properties);
        Assert.Empty(menu.Methods);

        // MenuItem's Header comes from the newly projected HeaderedSelectingItemsControl, and
        // Items is inherited all the way from ItemsControl.
        var headered = Type(ir, "IAvnHeaderedSelectingItemsControl");
        Assert.Equal("Avalonia.Host.Com.IAvnSelectingItemsControl", headered.BaseFullName);
        var header = headered.Properties.Single();
        Assert.Equal(nameof(HeaderedSelectingItemsControl.Header), header.Name);
        Assert.Equal(MarshallingKind.ComInterface, header.Kind);
        Assert.Equal("Avalonia.Host.Com.IAvnControl", header.InterfaceName);

        var menuItem = Type(ir, "IAvnMenuItem");
        Assert.Equal("Avalonia.Host.Com.IAvnHeaderedSelectingItemsControl", menuItem.BaseFullName);
        var icon = menuItem.Properties.Single(property => property.Name == nameof(MenuItem.Icon));
        Assert.Equal(MarshallingKind.ComInterface, icon.Kind);
        Assert.Equal(
            MarshallingKind.Bool,
            menuItem.Properties.Single(property => property.Name == nameof(MenuItem.IsChecked)).Kind);
        Assert.Equal(
            MarshallingKind.I32,
            menuItem.Properties.Single(property => property.Name == nameof(MenuItem.ToggleType)).Kind);

        // Click replaces the command members: ICommand, object parameters and KeyGestures all
        // stay in the gap report rather than being approximated.
        Assert.Contains(menuItem.Events, @event =>
            @event.Name == nameof(MenuItem.Click) && @event.PayloadKind == EventPayloadKind.None);
        Assert.All(
            new[]
            {
                nameof(MenuItem.Command), nameof(MenuItem.CommandParameter),
                nameof(MenuItem.HotKey), nameof(MenuItem.InputGesture),
            },
            name =>
            {
                Assert.DoesNotContain(menuItem.Properties, property => property.Name == name);
                Assert.Contains(ir.Skipped, skipped =>
                    skipped.Owner == typeof(MenuItem).FullName && skipped.Member == name);
            });
    }

    [Fact]
    public void Projects_split_view_panes_as_controls_and_brushes()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        var splitView = Type(ir, "IAvnSplitView");
        Assert.Equal("Avalonia.Host.Com.IAvnContentControl", splitView.BaseFullName);

        var pane = splitView.Properties.Single(property => property.Name == nameof(SplitView.Pane));
        Assert.Equal(MarshallingKind.ComInterface, pane.Kind);
        Assert.Equal("Avalonia.Host.Com.IAvnControl", pane.InterfaceName);
        Assert.True(pane.IsNullable);

        var background = splitView.Properties
            .Single(property => property.Name == nameof(SplitView.PaneBackground));
        Assert.Equal(MarshallingKind.Brush, background.Kind);

        Assert.All(
            new[] { nameof(SplitView.DisplayMode), nameof(SplitView.PanePlacement) },
            name => Assert.Equal(
                MarshallingKind.I32,
                splitView.Properties.Single(property => property.Name == name).Kind));
        Assert.All(
            new[] { nameof(SplitView.OpenPaneLength), nameof(SplitView.CompactPaneLength) },
            name => Assert.Equal(
                MarshallingKind.F64,
                splitView.Properties.Single(property => property.Name == name).Kind));
        Assert.Equal(
            ["PaneClosed", "PaneOpened"],
            splitView.Events.Select(@event => @event.Name).OrderBy(n => n, StringComparer.Ordinal));
    }

    [Fact]
    public void Projects_picker_dates_and_times_as_converted_strings()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        // DateTimeOffset and TimeSpan have no ABI shape here, so they ride the same host-side
        // converter mechanism Image.Source uses rather than a minted date struct.
        var datePicker = Type(ir, "IAvnDatePicker");
        Assert.Equal("Avalonia.Host.Com.IAvnTemplatedControl", datePicker.BaseFullName);

        var selectedDate = datePicker.Properties
            .Single(property => property.Name == nameof(DatePicker.SelectedDate));
        Assert.Equal(MarshallingKind.StringUtf16, selectedDate.Kind);
        Assert.Equal("Avalonia.Host.Com.AvnDateTimeOffset", selectedDate.StringConverterTypeName);
        Assert.True(selectedDate.IsNullable);

        // MinYear/MaxYear have no absent state, so they take the non-nullable converter.
        Assert.All(
            new[] { nameof(DatePicker.MinYear), nameof(DatePicker.MaxYear) },
            name =>
            {
                var property = datePicker.Properties.Single(p => p.Name == name);
                Assert.Equal(MarshallingKind.StringUtf16, property.Kind);
                Assert.Equal(
                    "Avalonia.Host.Com.AvnDateTimeOffsetValue",
                    property.StringConverterTypeName);
                Assert.False(property.IsNullable);
            });
        Assert.Contains(datePicker.Methods, method => method.Name == nameof(DatePicker.Clear));

        // The change events carry DateTimeOffset? fields and an event payload has no converter
        // hook, so they are gaps rather than a silently lossy payload.
        Assert.Empty(datePicker.Events);
        Assert.Contains(ir.Skipped, skipped =>
            skipped.Owner == typeof(DatePicker).FullName &&
            skipped.Member == nameof(DatePicker.SelectedDateChanged));

        var timePicker = Type(ir, "IAvnTimePicker");
        var selectedTime = timePicker.Properties
            .Single(property => property.Name == nameof(TimePicker.SelectedTime));
        Assert.Equal(MarshallingKind.StringUtf16, selectedTime.Kind);
        Assert.Equal("Avalonia.Host.Com.AvnTimeSpan", selectedTime.StringConverterTypeName);
        Assert.True(selectedTime.IsNullable);
        Assert.Equal(
            MarshallingKind.I32,
            timePicker.Properties.Single(p => p.Name == nameof(TimePicker.MinuteIncrement)).Kind);
        Assert.Empty(timePicker.Events);
    }

    [Fact]
    public void Projects_tool_tip_attached_properties_with_a_string_tip()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        var tip = ir.AttachedProperties.Single(property =>
            property.OwnerName == nameof(ToolTip) && property.Name == "Tip");
        Assert.Equal("Avalonia.Host.Com.IAvnToolTipStatics", tip.StaticsInterfaceName);
        Assert.Equal(1, tip.StaticsInterfaceAbiVersion);
        // The managed property is an object; the ABI carries text and only text.
        Assert.Equal("System.Object", tip.ManagedTypeName);
        Assert.Equal(MarshallingKind.StringUtf16, tip.Kind);
        Assert.Equal("Avalonia.Host.Com.AvnToolTipTip", tip.StringConverterTypeName);
        Assert.True(tip.IsNullable);

        // The scalar tooltip members come through unchanged, and none of them is nullable.
        var scalars = ir.AttachedProperties
            .Where(property => property.OwnerName == nameof(ToolTip) && property.Name != "Tip")
            .ToArray();
        Assert.Equal(
            ["BetweenShowDelay", "HorizontalOffset", "IsOpen", "Placement", "ServiceEnabled",
                "ShowDelay", "ShowOnDisabled", "VerticalOffset"],
            scalars.Select(property => property.Name).OrderBy(n => n, StringComparer.Ordinal));
        Assert.All(scalars, property => Assert.False(property.IsNullable));
        Assert.All(scalars, property => Assert.Null(property.StringConverterTypeName));
        Assert.Equal(
            MarshallingKind.I32,
            scalars.Single(property => property.Name == "Placement").Kind);
        Assert.Contains(ir.Enums, projected => projected.FullName == "Avalonia.Controls.PlacementMode");

        // Every previously published attached-property group keeps its own statics interface.
        Assert.Equal(
            ["Avalonia.Host.Com.IAvnCanvasStatics", "Avalonia.Host.Com.IAvnDockPanelStatics",
                "Avalonia.Host.Com.IAvnGridStatics", "Avalonia.Host.Com.IAvnRelativePanelStatics",
                "Avalonia.Host.Com.IAvnToolTipStatics"],
            ir.AttachedProperties
                .Select(property => property.StaticsInterfaceName)
                .Distinct(StringComparer.Ordinal)
                .OrderBy(name => name, StringComparer.Ordinal));
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

        // ComboBox re-declares HorizontalContentAlignment and VerticalContentAlignment with
        // `new`, so the allowlist keeps them on ContentControl alone.
        Assert.All(
            new[] { "IAvnComboBox", "IAvnButton", "IAvnWindow" },
            name => Assert.DoesNotContain(
                Type(ir, name).Properties,
                property => property.Name is nameof(ContentControl.HorizontalContentAlignment)
                    or nameof(ContentControl.VerticalContentAlignment)));
    }

    [Fact]
    public void Projects_the_completeness_members_onto_the_types_that_declare_them()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        var contentControl = Type(ir, "IAvnContentControl");
        Assert.All(
            contentControl.Properties.Where(property => property.Name is
                nameof(ContentControl.HorizontalContentAlignment) or
                nameof(ContentControl.VerticalContentAlignment)),
            property =>
            {
                Assert.Equal(MarshallingKind.I32, property.Kind);
                Assert.True(property.CanRead && property.CanWrite);
            });

        var button = Type(ir, "IAvnButton");
        var clickMode = button.Properties.Single(p => p.Name == nameof(Button.ClickMode));
        Assert.Equal(MarshallingKind.I32, clickMode.Kind);
        Assert.Contains(ir.Enums, projected => projected.Name == nameof(ClickMode));
        Assert.All(
            button.Properties.Where(property => property.Name is
                nameof(Button.IsDefault) or nameof(Button.IsCancel)),
            property =>
            {
                Assert.Equal(MarshallingKind.Bool, property.Kind);
                Assert.True(property.CanRead && property.CanWrite);
            });

        // IsPressed is a read-only direct property: Avalonia raises it from input handling, so
        // it projects a getter and no setter.
        var isPressed = button.Properties.Single(p => p.Name == nameof(Button.IsPressed));
        Assert.Equal(MarshallingKind.Bool, isPressed.Kind);
        Assert.True(isPressed.CanRead);
        Assert.False(isPressed.CanWrite);

        var isThreeState = Type(ir, "IAvnToggleButton").Properties
            .Single(p => p.Name == nameof(ToggleButton.IsThreeState));
        Assert.Equal(MarshallingKind.Bool, isThreeState.Kind);

        var listBox = Type(ir, "IAvnListBox");
        Assert.Equal(
            MarshallingKind.I32,
            listBox.Properties.Single(p => p.Name == nameof(ListBox.SelectionMode)).Kind);
        Assert.Contains(ir.Enums, projected => projected.Name == nameof(SelectionMode));
        Assert.All(
            new[] { nameof(ListBox.SelectAll), nameof(ListBox.UnselectAll) },
            name => Assert.Contains(
                listBox.Methods,
                method => method.Name == name && method.Parameters.Count == 0));

        var comboBox = Type(ir, "IAvnComboBox");
        Assert.All(
            comboBox.Properties.Where(property => property.Name is
                nameof(ComboBox.IsDropDownOpen) or nameof(ComboBox.IsEditable)),
            property => Assert.Equal(MarshallingKind.Bool, property.Kind));
        Assert.Equal(
            MarshallingKind.F64,
            comboBox.Properties.Single(p => p.Name == nameof(ComboBox.MaxDropDownHeight)).Kind);
    }

    [Fact]
    public void Projects_grid_definitions_as_the_length_list_string_grid_already_parses()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        var grid = Type(ir, "IAvnGrid");
        Assert.All(
            new[] { nameof(Grid.ColumnDefinitions), nameof(Grid.RowDefinitions) },
            name =>
            {
                var property = grid.Properties.Single(candidate => candidate.Name == name);
                Assert.Equal(MarshallingKind.StringUtf16, property.Kind);
                Assert.True(property.CanRead && property.CanWrite);
                // Never null: an empty grid reports an empty list rather than a null pointer.
                Assert.False(property.IsNullable);
                // The managed type is retained so the emitter converts with the type's own
                // Parse/ToString instead of assigning a string to a definition collection.
                Assert.Equal($"Avalonia.Controls.{name}", property.ManagedTypeName);
                Assert.Null(property.InterfaceName);
                Assert.Null(property.ElementKind);
            });

        // The definition collections are not projected as types or collection interfaces of
        // their own, so nothing new is minted to carry them.
        Assert.DoesNotContain(
            ir.Types,
            type => type.Name is "IAvnColumnDefinitions" or "IAvnRowDefinitions"
                or "IAvnColumnDefinition" or "IAvnRowDefinition");
        Assert.DoesNotContain(
            ir.Types.SelectMany(type => type.Properties),
            property => property.Kind == MarshallingKind.ComCollection &&
                property.ManagedTypeName?.EndsWith("Definitions", StringComparison.Ordinal) == true);
    }

    [Fact]
    public void A_string_override_requires_the_managed_type_to_own_both_halves_of_the_round_trip()
    {
        // Grid's definitions qualify: both declare `static T Parse(string)` and override
        // ToString(), so the projection is a conversion the type itself owns.
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);
        Assert.Equal(2, Type(ir, "IAvnGrid").Properties
            .Count(property => property.ManagedTypeName is
                "Avalonia.Controls.ColumnDefinitions" or "Avalonia.Controls.RowDefinitions"));

        // A type without that pair is refused rather than projected with a guessed conversion.
        var policy = new ProjectionPolicy
        {
            IncludeTypeNames = [typeof(Panel).FullName!],
            IncludeMembers = new Dictionary<string, IReadOnlyList<string>>(StringComparer.Ordinal)
            {
                [typeof(Panel).FullName!] = [nameof(Panel.Children)],
            },
            MemberOverrides = new Dictionary<string, MarshallingOverride>(StringComparer.Ordinal)
            {
                [$"{typeof(Panel).FullName}.{nameof(Panel.Children)}"] =
                    new() { Kind = MarshallingKind.StringUtf16 },
            },
        };

        var refused = ClrTypeExtractor.Extract([typeof(Panel)], policy);
        Assert.Empty(refused.Types.Single().Properties);
        Assert.Contains(refused.Skipped, skipped =>
            skipped.Member == nameof(Panel.Children) &&
            skipped.Reason.Contains("Parse(string)", StringComparison.Ordinal));
    }

    [Fact]
    public void A_string_override_may_delegate_the_round_trip_to_a_host_side_converter()
    {
        // Image.Source is the reason this exists: IImage is an interface, so it can own neither
        // half of the round trip and the host converter owns both instead.
        var policy = new ProjectionPolicy
        {
            IncludeTypeNames = [typeof(Panel).FullName!],
            IncludeMembers = new Dictionary<string, IReadOnlyList<string>>(StringComparer.Ordinal)
            {
                [typeof(Panel).FullName!] = [nameof(Panel.Children)],
            },
            MemberOverrides = new Dictionary<string, MarshallingOverride>(StringComparer.Ordinal)
            {
                [$"{typeof(Panel).FullName}.{nameof(Panel.Children)}"] = new()
                {
                    Kind = MarshallingKind.StringUtf16,
                    StringConverterTypeName = "Some.Host.Converter",
                    IsNullable = true,
                },
            },
        };

        var ir = ClrTypeExtractor.Extract([typeof(Panel)], policy);
        var property = ir.Types.Single().Properties.Single();
        Assert.Equal(MarshallingKind.StringUtf16, property.Kind);
        Assert.Equal("Some.Host.Converter", property.StringConverterTypeName);
        Assert.True(property.IsNullable);
        Assert.DoesNotContain(ir.Skipped, skipped => skipped.Member == nameof(Panel.Children));
    }

    [Fact]
    public void An_attached_property_override_must_marshal_as_a_string()
    {
        var policy = new ProjectionPolicy
        {
            IncludeTypeNames = [typeof(Control).FullName!, typeof(ToolTip).FullName!],
            IncludeMembers = new Dictionary<string, IReadOnlyList<string>>(StringComparer.Ordinal)
            {
                [typeof(Control).FullName!] = [],
                [typeof(ToolTip).FullName!] = [],
            },
            AttachedProperties = new Dictionary<string, IReadOnlyList<string>>(StringComparer.Ordinal)
            {
                [typeof(ToolTip).FullName!] = ["Tip"],
            },
            AttachedPropertyOverrides = new Dictionary<string, MarshallingOverride>(StringComparer.Ordinal)
            {
                [$"{typeof(ToolTip).FullName}.Tip"] = new() { Kind = MarshallingKind.ComInterface },
            },
        };

        var ir = ClrTypeExtractor.Extract([typeof(Control), typeof(ToolTip)], policy);
        Assert.Empty(ir.AttachedProperties);
        Assert.Contains(ir.Skipped, skipped =>
            skipped.Member == "Tip" && skipped.Reason.Contains("string", StringComparison.Ordinal));
    }

    [Fact]
    public void Wave_c_layout_panels_publish_new_interfaces_at_version_one()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        Assert.All(
            new[]
            {
                "IAvnWrapPanel", "IAvnUniformGrid", "IAvnRelativePanel", "IAvnViewbox",
                "IAvnFlexPanel", "IAvnThumb", "IAvnGridSplitter",
            },
            name =>
            {
                var type = Type(ir, name);
                Assert.Equal(1, type.AbiVersion);
                Assert.Equal(
                    ClrTypeExtractor.CreateDeterministicIid(type.FullName, 1),
                    type.Iid);
                Assert.True(type.IsConstructible);
            });

        Assert.Equal("Avalonia.Host.Com.IAvnPanel", Type(ir, "IAvnWrapPanel").BaseFullName);
        Assert.Equal("Avalonia.Host.Com.IAvnPanel", Type(ir, "IAvnUniformGrid").BaseFullName);
        Assert.Equal("Avalonia.Host.Com.IAvnPanel", Type(ir, "IAvnRelativePanel").BaseFullName);
        Assert.Equal("Avalonia.Host.Com.IAvnPanel", Type(ir, "IAvnFlexPanel").BaseFullName);
        Assert.Equal("Avalonia.Host.Com.IAvnControl", Type(ir, "IAvnViewbox").BaseFullName);
        Assert.Equal("Avalonia.Host.Com.IAvnTemplatedControl", Type(ir, "IAvnThumb").BaseFullName);
        Assert.Equal("Avalonia.Host.Com.IAvnThumb", Type(ir, "IAvnGridSplitter").BaseFullName);

        var wrap = Type(ir, "IAvnWrapPanel");
        Assert.All(
            new[] { "Orientation", "ItemsAlignment" },
            name => Assert.Equal(
                MarshallingKind.I32,
                wrap.Properties.Single(property => property.Name == name).Kind));
        Assert.All(
            new[] { "ItemWidth", "ItemHeight", "ItemSpacing", "LineSpacing" },
            name => Assert.Equal(
                MarshallingKind.F64,
                wrap.Properties.Single(property => property.Name == name).Kind));
        Assert.Contains(ir.Enums, projected => projected.Name == nameof(WrapPanelItemsAlignment));

        var uniform = Type(ir, "IAvnUniformGrid");
        Assert.All(
            new[] { "Rows", "Columns", "FirstColumn" },
            name => Assert.Equal(
                MarshallingKind.I32,
                uniform.Properties.Single(property => property.Name == name).Kind));

        var viewbox = Type(ir, "IAvnViewbox");
        var child = viewbox.Properties.Single(property => property.Name == nameof(Viewbox.Child));
        Assert.Equal(MarshallingKind.ComInterface, child.Kind);
        Assert.Equal("Avalonia.Host.Com.IAvnControl", child.InterfaceName);
        Assert.True(child.IsNullable);

        var flex = Type(ir, "IAvnFlexPanel");
        Assert.All(
            new[] { "Direction", "JustifyContent", "AlignItems", "AlignContent", "Wrap" },
            name => Assert.Equal(
                MarshallingKind.I32,
                flex.Properties.Single(property => property.Name == name).Kind));
        Assert.Contains(ir.Enums, projected => projected.Name == nameof(FlexDirection));

        var splitter = Type(ir, "IAvnGridSplitter");
        Assert.All(
            new[] { "ResizeDirection", "ResizeBehavior" },
            name => Assert.Equal(
                MarshallingKind.I32,
                splitter.Properties.Single(property => property.Name == name).Kind));
        Assert.DoesNotContain(
            splitter.Properties,
            property => property.Name == nameof(GridSplitter.PreviewContent));

        var relativeStatics = ir.AttachedProperties
            .Where(property => property.OwnerName == nameof(RelativePanel))
            .Select(property => property.Name)
            .OrderBy(name => name, StringComparer.Ordinal)
            .ToArray();
        Assert.Equal(
            [
                "AlignBottomWithPanel", "AlignHorizontalCenterWithPanel", "AlignLeftWithPanel",
                "AlignRightWithPanel", "AlignTopWithPanel", "AlignVerticalCenterWithPanel",
            ],
            relativeStatics);
        Assert.All(
            ir.AttachedProperties.Where(property => property.OwnerName == nameof(RelativePanel)),
            property =>
            {
                Assert.Equal(MarshallingKind.Bool, property.Kind);
                Assert.False(property.IsNullable);
            });
        Assert.DoesNotContain(
            ir.AttachedProperties,
            property => property.Name is "Above" or "Below" or "LeftOf" or "RightOf"
                or "AlignLeftWith" or "Order" or "Grow" or "Shrink" or "Basis");

        Assert.Equal(7, ir.FactoryAbiVersion);
    }

    [Fact]
    public void Wave_d_button_family_publishes_new_interfaces_at_version_one()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        Assert.All(
            new[]
            {
                "IAvnRepeatButton", "IAvnDropDownButton", "IAvnSplitButton",
                "IAvnToggleSplitButton", "IAvnHyperlinkButton", "IAvnContextMenu",
                "IAvnMenuFlyout",
            },
            name =>
            {
                var type = Type(ir, name);
                Assert.Equal(1, type.AbiVersion);
                Assert.True(type.IsConstructible);
            });

        Assert.Equal("Avalonia.Host.Com.IAvnButton", Type(ir, "IAvnRepeatButton").BaseFullName);
        Assert.Equal("Avalonia.Host.Com.IAvnButton", Type(ir, "IAvnDropDownButton").BaseFullName);
        Assert.Equal("Avalonia.Host.Com.IAvnButton", Type(ir, "IAvnHyperlinkButton").BaseFullName);
        Assert.Equal("Avalonia.Host.Com.IAvnContentControl", Type(ir, "IAvnSplitButton").BaseFullName);
        Assert.Equal("Avalonia.Host.Com.IAvnSplitButton", Type(ir, "IAvnToggleSplitButton").BaseFullName);
        Assert.Equal("Avalonia.Host.Com.IAvnMenuBase", Type(ir, "IAvnContextMenu").BaseFullName);
        Assert.Equal("Avalonia.Host.Com.IAvnPopupFlyoutBase", Type(ir, "IAvnMenuFlyout").BaseFullName);

        var repeat = Type(ir, "IAvnRepeatButton");
        Assert.All(
            new[] { "Interval", "Delay" },
            name => Assert.Equal(
                MarshallingKind.I32,
                repeat.Properties.Single(property => property.Name == name).Kind));

        var hyperlink = Type(ir, "IAvnHyperlinkButton");
        var navigateUri = hyperlink.Properties.Single(property => property.Name == "NavigateUri");
        Assert.Equal(MarshallingKind.StringUtf16, navigateUri.Kind);
        Assert.Equal("Avalonia.Host.Com.AvnUri", navigateUri.StringConverterTypeName);
        Assert.True(navigateUri.IsNullable);

        var split = Type(ir, "IAvnSplitButton");
        Assert.Contains(split.Events, @event => @event.Name == "Click");
        Assert.DoesNotContain(split.Properties, property => property.Name == "Flyout");
        Assert.DoesNotContain(split.Properties, property => property.Name == "Command");

        var menuFlyout = Type(ir, "IAvnMenuFlyout");
        var items = menuFlyout.Properties.Single(property => property.Name == "Items");
        Assert.Equal(MarshallingKind.ComCollection, items.Kind);
        Assert.Equal("Avalonia.Host.Com.IAvnItemList", items.InterfaceName);

        Assert.Equal(7, ir.FactoryAbiVersion);
    }

    [Fact]
    public void Wave_e_input_controls_publish_new_interfaces_at_version_one()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        var spinner = Type(ir, "IAvnSpinner");
        Assert.Equal(1, spinner.AbiVersion);
        Assert.False(spinner.IsConstructible);
        Assert.Equal("Avalonia.Host.Com.IAvnContentControl", spinner.BaseFullName);

        Assert.All(
            new[]
            {
                "IAvnButtonSpinner", "IAvnNumericUpDown", "IAvnAutoCompleteBox",
                "IAvnMaskedTextBox", "IAvnSelectableTextBlock",
            },
            name =>
            {
                var type = Type(ir, name);
                Assert.Equal(1, type.AbiVersion);
                Assert.True(type.IsConstructible);
            });

        Assert.Equal("Avalonia.Host.Com.IAvnSpinner", Type(ir, "IAvnButtonSpinner").BaseFullName);
        Assert.Equal("Avalonia.Host.Com.IAvnTemplatedControl", Type(ir, "IAvnNumericUpDown").BaseFullName);
        Assert.Equal("Avalonia.Host.Com.IAvnTextBox", Type(ir, "IAvnMaskedTextBox").BaseFullName);
        Assert.Equal("Avalonia.Host.Com.IAvnTextBlock", Type(ir, "IAvnSelectableTextBlock").BaseFullName);

        var value = Type(ir, "IAvnNumericUpDown").Properties.Single(p => p.Name == "Value");
        Assert.Equal(MarshallingKind.StringUtf16, value.Kind);
        Assert.Equal("Avalonia.Host.Com.AvnDecimal", value.StringConverterTypeName);
        Assert.True(value.IsNullable);
        var minimum = Type(ir, "IAvnNumericUpDown").Properties.Single(p => p.Name == "Minimum");
        Assert.Equal("Avalonia.Host.Com.AvnDecimalValue", minimum.StringConverterTypeName);
        Assert.False(minimum.IsNullable);

        var selectedText = Type(ir, "IAvnSelectableTextBlock").Properties
            .Single(p => p.Name == "SelectedText");
        Assert.True(selectedText.CanRead);
        Assert.False(selectedText.CanWrite);

        Assert.Equal(7, ir.FactoryAbiVersion);
    }

    [Fact]
    public void Produces_stable_unique_iids_and_explicit_gap_report()    {
        var first = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);
        var second = ClrTypeExtractor.Extract(KernelTypes.Reverse(), AvaloniaProjectionProfiles.ObjectModelKernel);

        Assert.Equal(
            first.Types.Select(t => (t.FullName, t.Iid)),
            second.Types.Select(t => (t.FullName, t.Iid)));
        Assert.Equal(first.Types.Count, first.Types.Select(t => t.Iid).Distinct().Count());
        Assert.Contains(first.Skipped, s =>
            s.Owner == typeof(Button).FullName &&
            s.Member == nameof(Button.Flyout) &&
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
