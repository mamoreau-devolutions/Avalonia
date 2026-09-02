using Avalonia.Controls;
using Avalonia.Markup.Xaml;
using Avalonia.Rust.Consumer.Generated;
using Avalonia.Rust.Interop;

namespace Avalonia.Rust.Consumer.Views;

public partial class MainWindow : Window
{
    private readonly MainViewModelAdapter _adapter;

    public MainWindow()
    {
        InitializeComponent();
        _adapter = null!;
    }

    public MainWindow(IAvnRustViewModel model)
        : this()
    {
        _adapter = new MainViewModelAdapter(model);
        DataContext = _adapter;
        Closed += (_, _) => _adapter.Dispose();
    }

    private void InitializeComponent() => AvaloniaXamlLoader.Load(this);
}
