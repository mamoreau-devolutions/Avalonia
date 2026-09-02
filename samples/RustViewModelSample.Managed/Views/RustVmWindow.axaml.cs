using System;
using Avalonia.Controls;
using Avalonia.Interactivity;
using Avalonia.Markup.Xaml;
using Avalonia.Rust.Interop;
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

    /// <summary>
    /// Cycles the `Priority` enum property through its members. Not part of
    /// the generated surface: an ordinary managed two-way write, exactly like
    /// setting any other writable property, proving enum values round-trip
    /// through the existing `Integer` transport without a dedicated ABI kind.
    /// </summary>
    private void OnCyclePriorityClick(object? sender, RoutedEventArgs e)
    {
        _adapter.Priority = _adapter.Priority switch
        {
            Priority.Low => Priority.Normal,
            Priority.Normal => Priority.High,
            _ => Priority.Low,
        };
    }
}
