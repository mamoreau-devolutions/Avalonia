using System;
using System.IO;
using System.Linq;
using Avalonia.Controls;
using Avalonia.Controls.Primitives;
using Avalonia.Host.Com;
using Avalonia.Projection.Generator;
using Avalonia.Projection.Ir;
using Xunit;

namespace Avalonia.Projection.Generator.Tests;

public class ComSourceEmitterTests
{
    /// <summary>Every type the object-model kernel projects, in the order the profile lists them.</summary>
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
        typeof(TextBox),
        typeof(ScrollViewer),
        typeof(RangeBase),
        typeof(Slider),
        typeof(ProgressBar),
    ];

    [Fact]
    public void Emits_fixture_interfaces_with_stable_guids_and_preserve_sig()
    {
        var ir = ComInterfaceExtractor.Extract(typeof(IAvnEcho).Assembly, new ProjectionPolicy
        {
            IncludeNamespaces = ["Avalonia.Host.Com"],
        });
        var files = ComSourceEmitter.Emit(ir);

        Assert.True(files.ContainsKey("IAvnEcho.g.cs"));
        Assert.True(files.ContainsKey("IAvnActivationFactory.g.cs"));

        var echo = files["IAvnEcho.g.cs"];
        Assert.Contains("[GeneratedComInterface(StringMarshalling = StringMarshalling.Utf16)]", echo, StringComparison.Ordinal);
        Assert.Contains("[Guid(\"6B2E8F10-4C91-4E3A-9A77-1F0C2B3A4D11\")]", echo, StringComparison.Ordinal);
        Assert.Contains("[PreserveSig]", echo, StringComparison.Ordinal);
        Assert.Contains("int Ping(int value, out int result);", echo, StringComparison.Ordinal);
        Assert.Contains("int EchoString(string? input, out string? output);", echo, StringComparison.Ordinal);
        Assert.Contains("int Fail();", echo, StringComparison.Ordinal);

        var factory = files["IAvnActivationFactory.g.cs"];
        Assert.Contains("[Guid(\"6B2E8F10-4C91-4E3A-9A77-1F0C2B3A4D10\")]", factory, StringComparison.Ordinal);
        Assert.Contains("int CreateEcho(out IAvnEcho? echo);", factory, StringComparison.Ordinal);
    }

    [Fact]
    public void Emits_generalized_kernel_interfaces_wrappers_runtime_and_factory()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);

        var files = ComSourceEmitter.Emit(ir);

        var button = files["IAvnButton.g.cs"];
        Assert.Contains("public partial interface IAvnButton : IAvnContentControl", button, StringComparison.Ordinal);
        Assert.Contains("public sealed partial class AvnButton : IAvnButton", button, StringComparison.Ordinal);
        Assert.Contains("public int SetContent(IAvnControl? value)", button, StringComparison.Ordinal);
        Assert.Contains("_value.Content = (global::System.Object)ProjectionRuntime.Unwrap(value)!;", button, StringComparison.Ordinal);
        Assert.Contains("int AdviseClick(IAvnButtonClickHandler? handler, out long subscriptionId);", button, StringComparison.Ordinal);
        Assert.Contains("eventSource.Click += callback;", button, StringComparison.Ordinal);
        Assert.Contains("eventSource.Click -= callback", button, StringComparison.Ordinal);

        var control = files["IAvnControl.g.cs"];
        Assert.Contains("int SetWidth(double value);", control, StringComparison.Ordinal);
        Assert.Contains("int SetHeight(double value);", control, StringComparison.Ordinal);
        Assert.Contains(
            "handler.Invoke((int)eventArgs.Key, (int)eventArgs.PhysicalKey, (int)eventArgs.KeyModifiers, eventArgs.KeySymbol, ref handled)",
            control,
            StringComparison.Ordinal);
        Assert.Contains("eventArgs.Handled = handled != 0;", control, StringComparison.Ordinal);
        Assert.Contains("int AdvisePointerEntered(IAvnControlPointerEnteredHandler? handler", control, StringComparison.Ordinal);
        Assert.Contains("int AdvisePointerExited(IAvnControlPointerExitedHandler? handler", control, StringComparison.Ordinal);
        Assert.Contains(
            "int Invoke(int Key, int PhysicalKey, int KeyModifiers, string? KeySymbol, ref int Handled);",
            files["IAvnControlKeyDownHandler.g.cs"],
            StringComparison.Ordinal);

        var clickHandler = files["IAvnButtonClickHandler.g.cs"];
        Assert.Contains("public partial interface IAvnButtonClickHandler", clickHandler, StringComparison.Ordinal);
        Assert.Contains("int Invoke();", clickHandler, StringComparison.Ordinal);

        var window = files["IAvnWindow.g.cs"];
        Assert.Contains("int GetTitle(out string? value);", window, StringComparison.Ordinal);
        Assert.Contains("public int Show()", window, StringComparison.Ordinal);
        Assert.Contains("_value.Show();", window, StringComparison.Ordinal);

        var toggleSwitch = files["IAvnToggleSwitch.g.cs"];
        Assert.Contains("public partial interface IAvnToggleSwitch : IAvnToggleButton", toggleSwitch, StringComparison.Ordinal);
        Assert.Contains("int SetOnContent(IAvnControl? value);", toggleSwitch, StringComparison.Ordinal);
        Assert.Contains("int SetOffContent(IAvnControl? value);", toggleSwitch, StringComparison.Ordinal);

        var expander = files["IAvnExpander.g.cs"];
        Assert.Contains("public partial interface IAvnExpander : IAvnHeaderedContentControl", expander, StringComparison.Ordinal);
        Assert.Contains("int AdviseExpanded(IAvnExpanderExpandedHandler? handler", expander, StringComparison.Ordinal);

        var runtime = files["ProjectionRuntime.g.cs"];
        Assert.Contains("global::Avalonia.Controls.Button typed => new AvnButton(typed)", runtime, StringComparison.Ordinal);
        Assert.Contains("ConditionalWeakTable<global::Avalonia.AvaloniaObject, IAvnAvaloniaObject>", runtime, StringComparison.Ordinal);
        Assert.Contains("internal static int TrackedObjectIdCount => s_objects.Count;", runtime, StringComparison.Ordinal);
        Assert.Contains("internal static int LiveManagedObjectCount", runtime, StringComparison.Ordinal);

        var factory = files["IAvnControlFactory.g.cs"];
        Assert.Contains("int CreateButton(out IAvnButton? value);", factory, StringComparison.Ordinal);
        Assert.Contains("int CreateWindow(out IAvnWindow? value);", factory, StringComparison.Ordinal);

        var list = files["IAvnControlList.g.cs"];
        Assert.Contains("int GetAt(int index, out IAvnControl? value);", list, StringComparison.Ordinal);
        Assert.Contains("int Add(IAvnControl? value);", list, StringComparison.Ordinal);
        Assert.Contains("ProjectionRuntime.Wrap((global::Avalonia.Controls.Control)_value[index]!)", list, StringComparison.Ordinal);

        var items = files["IAvnItemList.g.cs"];
        Assert.Contains("private readonly global::Avalonia.Controls.ItemCollection _value;", items, StringComparison.Ordinal);
        Assert.Contains("ProjectionRuntime.Wrap((global::Avalonia.Controls.Control)_value[index]!)", items, StringComparison.Ordinal);

        var roots = files["ProjectionAotRoots.g.cs"];
        Assert.Contains("typeof(AvnButton)", roots, StringComparison.Ordinal);
        Assert.Contains("typeof(AvnControlList)", roots, StringComparison.Ordinal);
        Assert.Contains("typeof(AvnWindow)", roots, StringComparison.Ordinal);
        Assert.Contains(
            "global::Avalonia.Host.ProjectionDiagnostics.WrapperCreated();",
            button,
            StringComparison.Ordinal);
        Assert.Contains(
            "global::Avalonia.Host.ProjectionDiagnostics.SubscriptionAdded();",
            button,
            StringComparison.Ordinal);

        var gridStatics = files["IAvnGridStatics.g.cs"];
        Assert.Contains("int SetRow(IAvnControl? target, int value);", gridStatics, StringComparison.Ordinal);

        var stringList = files["IAvnStringList.g.cs"];
        Assert.Contains("int Add(string value);", stringList, StringComparison.Ordinal);
    }

    [Fact]
    public void Emits_grid_definitions_as_strings_converted_by_the_managed_types_own_parse()
    {
        var ir = ClrTypeExtractor.Extract(
            [typeof(AvaloniaObject), typeof(StyledElement), typeof(Control), typeof(Panel), typeof(Grid)],
            AvaloniaProjectionProfiles.ObjectModelKernel);
        var grid = ComSourceEmitter.Emit(ir)["IAvnGrid.g.cs"];

        // The ABI slot is a plain non-nullable UTF-16 string in both directions.
        foreach (var expected in new[]
                 {
                     "int GetColumnDefinitions(out string value);",
                     "int SetColumnDefinitions(string value);",
                     "int GetRowDefinitions(out string value);",
                     "int SetRowDefinitions(string value);",
                 })
        {
            Assert.Contains(expected, grid, StringComparison.Ordinal);
        }

        // The wrapper converts with ColumnDefinitions/RowDefinitions' own round trip rather
        // than assigning a string straight onto a definition collection.
        foreach (var expected in new[]
                 {
                     "value = _value.ColumnDefinitions.ToString();",
                     "_value.ColumnDefinitions = global::Avalonia.Controls.ColumnDefinitions.Parse(value);",
                     "value = _value.RowDefinitions.ToString();",
                     "_value.RowDefinitions = global::Avalonia.Controls.RowDefinitions.Parse(value);",
                 })
        {
            Assert.Contains(expected, grid, StringComparison.Ordinal);
        }

        // No definition object crosses, so no interface is minted for one.
        Assert.DoesNotContain("IAvnColumnDefinition", grid, StringComparison.Ordinal);
        Assert.DoesNotContain("IAvnRowDefinition", grid, StringComparison.Ordinal);
    }

    [Fact]
    public void Emits_image_source_as_a_string_converted_by_the_host_side_converter()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);
        var image = ComSourceEmitter.Emit(ir)["IAvnImage.g.cs"];

        Assert.Contains("public partial interface IAvnImage : IAvnControl", image, StringComparison.Ordinal);
        // The slot is a nullable string, because an image with no source is not an empty path.
        Assert.Contains("int GetSource(out string? value);", image, StringComparison.Ordinal);
        Assert.Contains("int SetSource(string? value);", image, StringComparison.Ordinal);
        // Neither half touches IImage: the host converter owns the whole conversion.
        Assert.Contains(
            "value = global::Avalonia.Host.Com.AvnImageSource.ToAbi(_value.Source);",
            image,
            StringComparison.Ordinal);
        Assert.Contains(
            "_value.Source = global::Avalonia.Host.Com.AvnImageSource.FromAbi(value);",
            image,
            StringComparison.Ordinal);
        Assert.DoesNotContain("_value.Source.ToString()", image, StringComparison.Ordinal);
        Assert.DoesNotContain("global::Avalonia.Media.IImage.Parse", image, StringComparison.Ordinal);
    }

    [Fact]
    public void Emits_tool_tip_statics_with_a_nullable_string_tip()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);
        var files = ComSourceEmitter.Emit(ir);
        var statics = files["IAvnToolTipStatics.g.cs"];

        Assert.Contains(
            "int GetTip(IAvnControl? target, out string? value);",
            statics,
            StringComparison.Ordinal);
        Assert.Contains(
            "int SetTip(IAvnControl? target, string? value);",
            statics,
            StringComparison.Ordinal);
        Assert.Contains(
            "value = global::Avalonia.Host.Com.AvnToolTipTip.ToAbi(result);",
            statics,
            StringComparison.Ordinal);
        Assert.Contains(
            "global::Avalonia.Controls.ToolTip.SetTip(control, global::Avalonia.Host.Com.AvnToolTipTip.FromAbi(value));",
            statics,
            StringComparison.Ordinal);
        // The scalar members are untouched by the string plumbing.
        Assert.Contains("int SetShowDelay(IAvnControl? target, int value);", statics, StringComparison.Ordinal);
        Assert.Contains("int GetPlacement(IAvnControl? target, out int value);", statics, StringComparison.Ordinal);
        // A scalar getter still zero-initialises without a null-forgiving operator.
        Assert.Contains("public int GetIsOpen(IAvnControl? target, out int value)", statics, StringComparison.Ordinal);
        Assert.Contains("        value = default;", statics, StringComparison.Ordinal);

        // The factory hands out the new statics object alongside the existing ones.
        var factory = files["IAvnControlFactory.g.cs"];
        Assert.Contains("int GetToolTipStatics(out IAvnToolTipStatics? value);", factory, StringComparison.Ordinal);
        Assert.Contains("int CreateImage(out IAvnImage? value);", factory, StringComparison.Ordinal);
        Assert.Contains("int CreateTabControl(out IAvnTabControl? value);", factory, StringComparison.Ordinal);
        Assert.Contains("int CreateTreeViewItem(out IAvnTreeViewItem? value);", factory, StringComparison.Ordinal);
        Assert.Contains("typeof(AvnToolTipStatics)", files["ProjectionAotRoots.g.cs"], StringComparison.Ordinal);
    }

    [Fact]
    public void Emits_the_wave_a_tab_and_tree_controls_over_their_real_bases()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);
        var files = ComSourceEmitter.Emit(ir);

        var tabControl = files["IAvnTabControl.g.cs"];
        Assert.Contains(
            "public partial interface IAvnTabControl : IAvnSelectingItemsControl",
            tabControl,
            StringComparison.Ordinal);
        Assert.Contains("int SetTabStripPlacement(int value);", tabControl, StringComparison.Ordinal);

        var tabItem = files["IAvnTabItem.g.cs"];
        Assert.Contains(
            "public partial interface IAvnTabItem : IAvnHeaderedContentControl",
            tabItem,
            StringComparison.Ordinal);
        Assert.Contains("int SetIsSelected(int value);", tabItem, StringComparison.Ordinal);

        // TreeView's subtree commands take a projected TreeViewItem and unwrap it back to the
        // Avalonia object rather than crossing an opaque handle.
        var treeView = files["IAvnTreeView.g.cs"];
        Assert.Contains(
            "public partial interface IAvnTreeView : IAvnItemsControl",
            treeView,
            StringComparison.Ordinal);
        Assert.Contains(
            "int ExpandSubTreeWithTreeViewItem(IAvnTreeViewItem item);",
            treeView,
            StringComparison.Ordinal);
        Assert.Contains(
            "_value.ExpandSubTree((global::Avalonia.Controls.TreeViewItem)ProjectionRuntime.Unwrap(item)!);",
            treeView,
            StringComparison.Ordinal);

        var treeViewItem = files["IAvnTreeViewItem.g.cs"];
        Assert.Contains(
            "public partial interface IAvnTreeViewItem : IAvnHeaderedItemsControl",
            treeViewItem,
            StringComparison.Ordinal);
        // Level is computed by the control, so the ABI publishes a getter and no setter.
        Assert.Contains("int GetLevel(out int value);", treeViewItem, StringComparison.Ordinal);
        Assert.DoesNotContain("int SetLevel(int value);", treeViewItem, StringComparison.Ordinal);
        Assert.Contains(
            "int AdviseExpanded(IAvnTreeViewItemExpandedHandler? handler",
            treeViewItem,
            StringComparison.Ordinal);
        Assert.Contains(
            "int AdviseCollapsed(IAvnTreeViewItemCollapsedHandler? handler",
            treeViewItem,
            StringComparison.Ordinal);

        var headered = files["IAvnHeaderedItemsControl.g.cs"];
        Assert.Contains(
            "public partial interface IAvnHeaderedItemsControl : IAvnItemsControl",
            headered,
            StringComparison.Ordinal);
        Assert.Contains("int SetHeader(IAvnControl? value);", headered, StringComparison.Ordinal);
    }

    [Fact]
    public void Checked_in_ir_and_host_sources_match_generator()
    {
        var ir = ClrTypeExtractor.Extract(KernelTypes, AvaloniaProjectionProfiles.ObjectModelKernel);
        var root = FindRepositoryRoot();

        Assert.Equal(
            Normalize(ir.ToJson()),
            Normalize(File.ReadAllText(Path.Combine(root, "rust", "projection.ir.json"))));

        var generatedDirectory = Path.Combine(root, "src", "Avalonia.Host", "Generated", "ObjectModel");
        foreach (var (name, source) in ComSourceEmitter.Emit(ir))
            Assert.Equal(Normalize(source), Normalize(File.ReadAllText(Path.Combine(generatedDirectory, name))));

        Assert.Equal(
            Normalize(NativeHeaderEmitter.Emit(ir)),
            Normalize(File.ReadAllText(Path.Combine(
                root,
                "rust",
                "avalonia-sys",
                "include",
                "avalonia-rust-abi.h"))));

        var header = NativeHeaderEmitter.Emit(ir);
        var buttonStart = header.IndexOf("struct IAvnButtonVtbl", StringComparison.Ordinal);
        var buttonEnd = header.IndexOf("struct IAvnButton {", buttonStart, StringComparison.Ordinal);
        var buttonHeader = header[buttonStart..buttonEnd];
        Assert.Contains("get_object_id", buttonHeader, StringComparison.Ordinal);
        Assert.Contains("#define I_AVN_BUTTON_ABI_VERSION 5", header, StringComparison.Ordinal);
        Assert.True(
            buttonHeader.IndexOf("get_object_id", StringComparison.Ordinal) <
            buttonHeader.IndexOf("get_classes", StringComparison.Ordinal));
    }

    [Fact]
    public void Checked_in_view_model_sources_match_generator()
    {
        var root = FindRepositoryRoot();
        var ir = ViewModelIr.FromJson(File.ReadAllText(Path.Combine(
            root,
            "rust",
            "view-model.ir.json")));
        var adapterDirectory = Path.Combine(
            root,
            "samples",
            "RustViewModelSample.Managed",
            "Generated");
        var registryDirectory = Path.Combine(
            root,
            "src",
            "Avalonia.Host",
            "Generated",
            "ViewModels");

        foreach (var (name, source) in ViewModelSourceEmitter.EmitCSharp(ir))
        {
            var directory = name == "RustViewRegistry.g.cs"
                ? registryDirectory
                : adapterDirectory;
            Assert.Equal(
                Normalize(source),
                Normalize(File.ReadAllText(Path.Combine(directory, name))));
        }
        Assert.Equal(
            Normalize(ViewModelSourceEmitter.EmitRust(ir)),
            Normalize(File.ReadAllText(Path.Combine(
                root,
                "rust",
                "avalonia",
                "src",
                "generated_view_models.rs"))));
        Assert.Equal(
            Normalize(ViewModelSourceEmitter.EmitContract(ir)),
            Normalize(File.ReadAllText(Path.Combine(
                root,
                "rust",
                "view-model.contract.md"))));
    }

    private static string FindRepositoryRoot()
    {
        for (var current = new DirectoryInfo(AppContext.BaseDirectory);
             current is not null;
             current = current.Parent)
        {
            var gitPath = Path.Combine(current.FullName, ".git");
            if (Directory.Exists(gitPath) || File.Exists(gitPath))
                return current.FullName;
        }
        throw new DirectoryNotFoundException("Could not locate repository root.");
    }

    private static string Normalize(string value) =>
        value.Replace("\r\n", "\n", StringComparison.Ordinal).TrimEnd();
}
