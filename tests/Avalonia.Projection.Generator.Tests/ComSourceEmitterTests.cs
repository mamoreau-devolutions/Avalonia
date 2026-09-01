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
        Type[] types =
        [
            typeof(AvaloniaObject),
            typeof(StyledElement),
            typeof(Control),
            typeof(ContentControl),
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
            typeof(ToggleSwitch),
            typeof(TextBox),
            typeof(ScrollViewer),
            typeof(RangeBase),
            typeof(Slider),
            typeof(ProgressBar),
        ];
        var ir = ClrTypeExtractor.Extract(types, AvaloniaProjectionProfiles.ObjectModelKernel);

        var files = ComSourceEmitter.Emit(ir);

        var button = files["IAvnButton.g.cs"];
        Assert.Contains("public partial interface IAvnButton : IAvnContentControl", button, StringComparison.Ordinal);
        Assert.Contains("public sealed partial class AvnButton : IAvnButton", button, StringComparison.Ordinal);
        Assert.Contains("public int SetContent(IAvnControl? value)", button, StringComparison.Ordinal);
        Assert.Contains("_value.Content = (global::System.Object)ProjectionRuntime.Unwrap(value)!;", button, StringComparison.Ordinal);
        Assert.Contains("int AdviseClick(IAvnButtonClickHandler? handler, out long subscriptionId);", button, StringComparison.Ordinal);
        Assert.Contains("_value.Click += callback;", button, StringComparison.Ordinal);
        Assert.Contains("_value.Click -= callback", button, StringComparison.Ordinal);

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

        var runtime = files["ProjectionRuntime.g.cs"];
        Assert.Contains("global::Avalonia.Controls.Button typed => new AvnButton(typed)", runtime, StringComparison.Ordinal);
        Assert.Contains("ConditionalWeakTable<global::Avalonia.AvaloniaObject, IAvnAvaloniaObject>", runtime, StringComparison.Ordinal);

        var factory = files["IAvnControlFactory.g.cs"];
        Assert.Contains("int CreateButton(out IAvnButton? value);", factory, StringComparison.Ordinal);
        Assert.Contains("int CreateWindow(out IAvnWindow? value);", factory, StringComparison.Ordinal);

        var list = files["IAvnControlList.g.cs"];
        Assert.Contains("int GetAt(int index, out IAvnControl? value);", list, StringComparison.Ordinal);
        Assert.Contains("int Add(IAvnControl? value);", list, StringComparison.Ordinal);
        Assert.Contains("ProjectionRuntime.Wrap(_value[index])", list, StringComparison.Ordinal);

        var roots = files["ProjectionAotRoots.g.cs"];
        Assert.Contains("typeof(AvnButton)", roots, StringComparison.Ordinal);
        Assert.Contains("typeof(AvnControlList)", roots, StringComparison.Ordinal);
        Assert.Contains("typeof(AvnWindow)", roots, StringComparison.Ordinal);

        var gridStatics = files["IAvnGridStatics.g.cs"];
        Assert.Contains("int SetRow(IAvnControl? target, int value);", gridStatics, StringComparison.Ordinal);

        var stringList = files["IAvnStringList.g.cs"];
        Assert.Contains("int Add(string value);", stringList, StringComparison.Ordinal);
    }

    [Fact]
    public void Checked_in_ir_and_host_sources_match_generator()
    {
        Type[] types =
        [
            typeof(AvaloniaObject),
            typeof(StyledElement),
            typeof(Control),
            typeof(ContentControl),
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
            typeof(ToggleSwitch),
            typeof(TextBox),
            typeof(ScrollViewer),
            typeof(RangeBase),
            typeof(Slider),
            typeof(ProgressBar),
        ];
        var ir = ClrTypeExtractor.Extract(types, AvaloniaProjectionProfiles.ObjectModelKernel);
        var root = FindRepositoryRoot();

        Assert.Equal(
            Normalize(ir.ToJson()),
            Normalize(File.ReadAllText(Path.Combine(root, "rust", "projection.ir.json"))));

        var generatedDirectory = Path.Combine(root, "src", "Avalonia.Host", "Generated", "ObjectModel");
        foreach (var (name, source) in ComSourceEmitter.Emit(ir))
            Assert.Equal(Normalize(source), Normalize(File.ReadAllText(Path.Combine(generatedDirectory, name))));
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
