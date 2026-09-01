using System;
using Avalonia.Controls;
using Avalonia.Rust.Interop;
using Avalonia.Markup.Xaml;
using Avalonia.Rust.Sample.Generated;

namespace Avalonia.Rust.Sample.Views;

public partial class RustVmWindow : Window
{
    private readonly SampleViewModelAdapter _adapter;

    public RustVmWindow()
    {
        InitializeComponent();
        _adapter = null!;
    }

    public RustVmWindow(IAvnRustViewModel model)
        : this()
    {
        _adapter = new SampleViewModelAdapter(model);
        DataContext = _adapter;
        Closed += (_, _) => _adapter.Dispose();
    }

    private void InitializeComponent() =>
        AvaloniaXamlLoader.Load(this);
}
