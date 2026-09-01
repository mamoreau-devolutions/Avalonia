using Avalonia.Controls;
using Avalonia.Host.Com;
using Avalonia.Markup.Xaml;

namespace Avalonia.Host.Views;

public partial class RustVmWindow : Window
{
    private readonly RustVmAdapter _adapter;

    public RustVmWindow()
    {
        InitializeComponent();
        _adapter = null!;
    }

    public RustVmWindow(IAvnRustViewModel model)
        : this()
    {
        _adapter = new RustVmAdapter(model);
        DataContext = _adapter;
        Closed += (_, _) => _adapter.Dispose();
    }

    private void InitializeComponent() =>
        AvaloniaXamlLoader.Load(this);
}
