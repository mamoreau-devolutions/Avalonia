using System;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.Marshalling;
using System.Windows.Input;
using Avalonia.Host.Com;
using Avalonia.Threading;

namespace Avalonia.Host.Views;

[GeneratedComClass]
public sealed partial class RustVmAdapter :
    IAvnRustVmSink,
    INotifyPropertyChanged,
    IDisposable
{
    private readonly IAvnRustViewModel _model;
    private string _name = "";
    private int _count;
    private string _newItem = "";
    private string _status = "Ready";

    public RustVmAdapter(IAvnRustViewModel model)
    {
        _model = model;
        IncrementCommand = new DelegateCommand(() => Check(_model.Increment()));
        AddCommand = new DelegateCommand(() =>
        {
            if (string.IsNullOrWhiteSpace(NewItem))
                return;
            Check(_model.AddItem(NewItem));
            NewItem = "";
        });
        SaveCommand = new DelegateCommand(() => Check(_model.BeginSave()));
        Check(_model.Attach(this));
    }

    public event PropertyChangedEventHandler? PropertyChanged;

    public string Name
    {
        get => _name;
        set
        {
            if (_name == value)
                return;
            Check(_model.SetName(value));
        }
    }

    public int Count => _count;

    public string NewItem
    {
        get => _newItem;
        set => SetField(ref _newItem, value);
    }

    public string Status => _status;

    public ObservableCollection<string> Items { get; } = [];

    public ICommand IncrementCommand { get; }

    public ICommand AddCommand { get; }

    public ICommand SaveCommand { get; }

    public int SetName(string? value) =>
        Apply(() => SetField(ref _name, value ?? "", nameof(Name)));

    public int SetCount(int value) =>
        Apply(() => SetField(ref _count, value, nameof(Count)));

    public int AddItem(string? value) =>
        Apply(() => Items.Add(value ?? ""));

    public int SetStatus(string? value) =>
        Apply(() => SetField(ref _status, value ?? "", nameof(Status)));

    public void Dispose() =>
        Check(_model.Detach());

    private int Apply(Action action)
    {
        if (Dispatcher.UIThread.CheckAccess())
            action();
        else
            Dispatcher.UIThread.Post(action);
        return 0;
    }

    private static void Check(int hresult)
    {
        if (hresult < 0)
            Marshal.ThrowExceptionForHR(hresult);
    }

    private void SetField<T>(
        ref T field,
        T value,
        [CallerMemberName] string? propertyName = null)
    {
        if (Equals(field, value))
            return;
        field = value;
        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
    }

    private sealed class DelegateCommand(Action execute) : ICommand
    {
        public event EventHandler? CanExecuteChanged
        {
            add { }
            remove { }
        }

        public bool CanExecute(object? parameter) => true;

        public void Execute(object? parameter) => execute();
    }
}
