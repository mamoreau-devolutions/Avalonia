using System;
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
}
