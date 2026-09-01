using Avalonia.Host.Com;
using Xunit;

namespace Avalonia.Host.Tests;

public class GeneratedObjectModelTests
{
    [Fact]
    public void Factory_creates_projected_controls_and_forwards_properties()
    {
        var factory = new AvnControlFactory();

        Assert.Equal(0, factory.CreateButton(out var button));
        Assert.Equal(0, factory.CreateTextBlock(out var text));
        Assert.NotNull(button);
        Assert.NotNull(text);

        Assert.Equal(0, text.SetText("Hello from IR"));
        Assert.Equal(0, button.SetContent(text));
        Assert.Equal(0, button.GetContent(out var content));
        Assert.NotNull(content);

        Assert.Equal(0, text.GetObjectId(out var expectedId));
        Assert.Equal(0, content.GetObjectId(out var actualId));
        Assert.Equal(expectedId, actualId);
    }

    [Fact]
    public void Derived_control_implements_generated_base_interfaces()
    {
        var factory = new AvnControlFactory();
        Assert.Equal(0, factory.CreateButton(out var button));
        Assert.NotNull(button);

        Assert.IsAssignableFrom<IAvnContentControl>(button);
        Assert.IsAssignableFrom<IAvnControl>(button);
        Assert.IsAssignableFrom<IAvnAvaloniaObject>(button);
    }
}
