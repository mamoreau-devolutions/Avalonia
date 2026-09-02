using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.Marshalling;
using System.Threading;
using System.Windows.Input;
using Avalonia.Rust.Interop;
using Avalonia.Threading;

namespace Avalonia.Rust;

public enum RustViewModelValueKind
{
    String,
    Integer,
    Boolean,
    Double,

    /// <summary>
    /// An integer-backed named constant. Transported on the wire as
    /// <see cref="Integer"/>; the reflectable adapter boxes the concrete
    /// generated enum type (from <see cref="RustViewModelPropertyDescriptor.InitialValue"/>)
    /// so bindings and converters observe a real enum value, not a raw
    /// integer.
    /// </summary>
    Enum,

    /// <summary>
    /// A reference to another view model, exposed as a nested
    /// <see cref="ReflectableRustViewModelAdapter"/> built from
    /// <see cref="RustViewModelPropertyDescriptor.NestedDescriptor"/> (for a
    /// property) or <see cref="RustViewModelCollectionDescriptor.ElementDescriptor"/>
    /// (for a collection element). Always nullable for properties; never
    /// writable from managed code.
    /// </summary>
    Model,
}

public sealed class RustViewModelPropertyDescriptor(
    int id,
    string name,
    RustViewModelValueKind kind,
    bool writable,
    bool nullable,
    object? initialValue,
    RustViewModelDescriptor? nestedDescriptor = null)
{
    public int Id { get; } = id;
    public string Name { get; } = name;
    public RustViewModelValueKind Kind { get; } = kind;
    public bool Writable { get; } = writable;
    public bool Nullable { get; } = nullable;
    public object? InitialValue { get; } = initialValue;
    public RustViewModelDescriptor? NestedDescriptor { get; } = nestedDescriptor;
}

public sealed class RustViewModelCollectionDescriptor(
    int id,
    string name,
    RustViewModelValueKind elementKind,
    RustViewModelDescriptor? elementDescriptor = null)
{
    public int Id { get; } = id;
    public string Name { get; } = name;
    public RustViewModelValueKind ElementKind { get; } = elementKind;
    public RustViewModelDescriptor? ElementDescriptor { get; } = elementDescriptor;
}

public sealed class RustViewModelCommandDescriptor(
    int id,
    string name,
    bool isAsync,
    string? parameterProperty)
{
    public int Id { get; } = id;
    public string Name { get; } = name;
    public bool IsAsync { get; } = isAsync;
    public string? ParameterProperty { get; } = parameterProperty;
}

public sealed class RustViewModelDescriptor(
    int id,
    string name,
    IReadOnlyList<RustViewModelPropertyDescriptor> properties,
    IReadOnlyList<RustViewModelCollectionDescriptor> collections,
    IReadOnlyList<RustViewModelCommandDescriptor> commands)
{
    public int Id { get; } = id;
    public string Name { get; } = name;
    public IReadOnlyList<RustViewModelPropertyDescriptor> Properties { get; } = properties;
    public IReadOnlyList<RustViewModelCollectionDescriptor> Collections { get; } = collections;
    public IReadOnlyList<RustViewModelCommandDescriptor> Commands { get; } = commands;
}

[GeneratedComClass]
public sealed partial class ReflectableRustViewModelAdapter :
    IAvnRustVmSink,
    IAvnRustVmSink2,
    INotifyPropertyChanged,
    INotifyDataErrorInfo,
    IReflectableType,
    IDisposable
{
    private const int InvalidArgument = unchecked((int)0x80070057);
    private readonly IAvnRustViewModel _model;
    private readonly Action<Action> _dispatch;
    private readonly Dictionary<int, RuntimeProperty> _propertiesById = [];
    private readonly Dictionary<int, RuntimeCollection> _collectionsById = [];
    private readonly Dictionary<int, DelegateCommand> _commandsById = [];
    private readonly Dictionary<string, string> _errors = new(StringComparer.Ordinal);
    private readonly Dictionary<string, RuntimeMember> _membersByName =
        new(StringComparer.Ordinal);
    private readonly TypeInfo _typeInfo;
    private int _disposed;

    public ReflectableRustViewModelAdapter(
        IAvnRustViewModel model,
        RustViewModelDescriptor descriptor,
        Action<Action>? dispatch = null)
    {
        _model = model ?? throw new ArgumentNullException(nameof(model));
        ArgumentNullException.ThrowIfNull(descriptor);
        _dispatch = dispatch ?? Dispatch;

        foreach (var property in descriptor.Properties)
        {
            var runtimeProperty = new RuntimeProperty(property);
            _propertiesById.Add(property.Id, runtimeProperty);
            _membersByName.Add(
                property.Name,
                new RuntimeMember(
                    property.Name,
                    ValueType(property),
                    property.Writable,
                    () => runtimeProperty.Value,
                    value => SetProperty(runtimeProperty, value)));
        }

        foreach (var collection in descriptor.Collections)
        {
            var runtimeCollection = new RuntimeCollection(collection);
            _collectionsById.Add(collection.Id, runtimeCollection);
            _membersByName.Add(
                collection.Name,
                new RuntimeMember(
                    collection.Name,
                    typeof(ObservableCollection<object?>),
                    false,
                    () => runtimeCollection.Items,
                    null));
        }

        foreach (var command in descriptor.Commands)
        {
            var value = new DelegateCommand(() => Execute(command));
            _commandsById.Add(command.Id, value);
            _membersByName.Add(
                command.Name,
                new RuntimeMember(
                    command.Name,
                    typeof(ICommand),
                    false,
                    () => value,
                    null));
        }

        _typeInfo = new ReflectableTypeInfo(_membersByName);
        try
        {
            Check(_model.Attach(this));
        }
        catch
        {
            try
            {
                _model.Detach();
            }
            catch
            {
            }
            DisposeNestedAdapters();
            throw;
        }
    }

    public event PropertyChangedEventHandler? PropertyChanged;
    public event EventHandler<DataErrorsChangedEventArgs>? ErrorsChanged;

    public bool HasErrors => _errors.Count > 0;

    public TypeInfo GetTypeInfo() => _typeInfo;

    public IEnumerable GetErrors(string? propertyName) =>
        propertyName is not null && _errors.TryGetValue(propertyName, out var message)
            ? new[] { message }
            : Array.Empty<string>();

    public object? GetMemberValue(string memberName)
    {
        ArgumentException.ThrowIfNullOrEmpty(memberName);
        return _membersByName.TryGetValue(memberName, out var member)
            ? member.GetValue()
            : throw new MissingMemberException(
                $"Rust view model does not define member '{memberName}'.");
    }

    public void SetMemberValue(string memberName, object? value)
    {
        ArgumentException.ThrowIfNullOrEmpty(memberName);
        if (!_membersByName.TryGetValue(memberName, out var member))
        {
            throw new MissingMemberException(
                $"Rust view model does not define member '{memberName}'.");
        }
        if (!member.CanWrite)
            throw new InvalidOperationException($"Rust view-model member '{memberName}' is read-only.");
        member.SetValue(value);
    }

    public int SetString(int propertyId, string? value) =>
        ApplyProperty(propertyId, RustViewModelValueKind.String, value);

    public int SetInteger(int propertyId, long value) =>
        ApplyProperty(propertyId, RustViewModelValueKind.Integer, value);

    public int SetBoolean(int propertyId, int value) =>
        ApplyProperty(propertyId, RustViewModelValueKind.Boolean, value != 0);

    public int SetDouble(int propertyId, double value) =>
        ApplyProperty(propertyId, RustViewModelValueKind.Double, value);

    public int AddString(int collectionId, string? value) => InsertStringCore(collectionId, null, value);

    public int InsertString(int collectionId, int index, string? value) => InsertStringCore(collectionId, index, value);

    public int ReplaceString(int collectionId, int index, string? value)
    {
        if (!_collectionsById.TryGetValue(collectionId, out var collection) ||
            collection.Descriptor.ElementKind != RustViewModelValueKind.String)
        {
            return InvalidArgument;
        }
        return Apply(() =>
        {
            if ((uint)index >= (uint)collection.Items.Count)
                return InvalidArgument;
            collection.Items[index] = value ?? "";
            return 0;
        });
    }

    public int AddModel(int collectionId, IAvnRustViewModel? model) => InsertModelCore(collectionId, null, model);

    public int InsertModel(int collectionId, int index, IAvnRustViewModel? model) => InsertModelCore(collectionId, index, model);

    public int ReplaceModel(int collectionId, int index, IAvnRustViewModel? model)
    {
        if (model is null ||
            !_collectionsById.TryGetValue(collectionId, out var collection) ||
            collection.Descriptor.ElementKind != RustViewModelValueKind.Model)
        {
            return InvalidArgument;
        }
        return Apply(() =>
        {
            if ((uint)index >= (uint)collection.Items.Count)
                return InvalidArgument;
            var previous = collection.Items[index] as ReflectableRustViewModelAdapter;
            collection.Items[index] =
                new ReflectableRustViewModelAdapter(model, collection.Descriptor.ElementDescriptor!, _dispatch);
            previous?.Dispose();
            return 0;
        });
    }

    public int RemoveAt(int collectionId, int index)
    {
        if (!_collectionsById.TryGetValue(collectionId, out var collection))
            return InvalidArgument;
        return Apply(() =>
        {
            if ((uint)index >= (uint)collection.Items.Count)
                return InvalidArgument;
            var removed = collection.Items[index];
            collection.Items.RemoveAt(index);
            (removed as ReflectableRustViewModelAdapter)?.Dispose();
            return 0;
        });
    }

    public int MoveItem(int collectionId, int fromIndex, int toIndex)
    {
        if (!_collectionsById.TryGetValue(collectionId, out var collection))
            return InvalidArgument;
        return Apply(() =>
        {
            if ((uint)fromIndex >= (uint)collection.Items.Count || (uint)toIndex >= (uint)collection.Items.Count)
                return InvalidArgument;
            collection.Items.Move(fromIndex, toIndex);
            return 0;
        });
    }

    public int ClearCollection(int collectionId)
    {
        if (!_collectionsById.TryGetValue(collectionId, out var collection))
            return InvalidArgument;
        return Apply(() =>
        {
            foreach (var item in collection.Items)
                (item as ReflectableRustViewModelAdapter)?.Dispose();
            collection.Items.Clear();
        });
    }

    public int SetNull(int propertyId)
    {
        if (!_propertiesById.TryGetValue(propertyId, out var property) || !property.Descriptor.Nullable)
            return InvalidArgument;
        return Apply(() =>
        {
            if (property.Value is null)
                return;
            property.Value = null;
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(property.Descriptor.Name));
        });
    }

    public int SetModel(int propertyId, IAvnRustViewModel? model)
    {
        if (!_propertiesById.TryGetValue(propertyId, out var property) ||
            property.Descriptor.Kind != RustViewModelValueKind.Model)
        {
            return InvalidArgument;
        }
        return Apply(() =>
        {
            var previous = property.Value as ReflectableRustViewModelAdapter;
            property.Value = model is null
                ? null
                : new ReflectableRustViewModelAdapter(model, property.Descriptor.NestedDescriptor!, _dispatch);
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(property.Descriptor.Name));
            previous?.Dispose();
        });
    }

    public int SetCommandEnabled(int commandId, int enabled)
    {
        if (!_commandsById.TryGetValue(commandId, out var command))
            return InvalidArgument;
        return Apply(() => command.SetEnabled(enabled != 0));
    }

    public int SetPropertyError(int propertyId, string? message)
    {
        if (!_propertiesById.TryGetValue(propertyId, out var property))
            return InvalidArgument;
        return Apply(() => SetError(property.Descriptor.Name, message));
    }

    public void Dispose()
    {
        if (Interlocked.Exchange(ref _disposed, 1) == 0)
        {
            try
            {
                Check(_model.Detach());
            }
            finally
            {
                DisposeNestedAdapters();
            }
        }
    }

    private void DisposeNestedAdapters()
    {
        foreach (var property in _propertiesById.Values)
        {
            if (property.Descriptor.Kind == RustViewModelValueKind.Model)
                TryDispose(property.Value as ReflectableRustViewModelAdapter);
        }
        foreach (var collection in _collectionsById.Values)
        {
            if (collection.Descriptor.ElementKind != RustViewModelValueKind.Model)
                continue;
            foreach (var item in collection.Items)
                TryDispose(item as ReflectableRustViewModelAdapter);
        }
    }

    private static void TryDispose(IDisposable? value)
    {
        try
        {
            value?.Dispose();
        }
        catch
        {
        }
    }

    private int InsertStringCore(int collectionId, int? index, string? value)
    {
        if (!_collectionsById.TryGetValue(collectionId, out var collection) ||
            collection.Descriptor.ElementKind != RustViewModelValueKind.String)
        {
            return InvalidArgument;
        }
        return Apply(() =>
        {
            var target = index ?? collection.Items.Count;
            if ((uint)target > (uint)collection.Items.Count)
                return InvalidArgument;
            collection.Items.Insert(target, value ?? "");
            return 0;
        });
    }

    private int InsertModelCore(int collectionId, int? index, IAvnRustViewModel? model)
    {
        if (model is null ||
            !_collectionsById.TryGetValue(collectionId, out var collection) ||
            collection.Descriptor.ElementKind != RustViewModelValueKind.Model)
        {
            return InvalidArgument;
        }
        return Apply(() =>
        {
            var target = index ?? collection.Items.Count;
            if ((uint)target > (uint)collection.Items.Count)
                return InvalidArgument;
            collection.Items.Insert(
                target,
                new ReflectableRustViewModelAdapter(model, collection.Descriptor.ElementDescriptor!, _dispatch));
            return 0;
        });
    }

    private int ApplyProperty(int propertyId, RustViewModelValueKind wireKind, object? rawValue)
    {
        if (!_propertiesById.TryGetValue(propertyId, out var property) ||
            WireKind(property.Descriptor.Kind) != wireKind)
        {
            return InvalidArgument;
        }

        if (property.Descriptor.Kind == RustViewModelValueKind.Enum &&
            !Enum.IsDefined(property.Value!.GetType(), rawValue!))
        {
            return InvalidArgument;
        }

        object? value = property.Descriptor.Kind switch
        {
            RustViewModelValueKind.Enum => Enum.ToObject(property.Value!.GetType(), rawValue!),
            RustViewModelValueKind.String when !property.Descriptor.Nullable => rawValue ?? "",
            _ => rawValue,
        };

        return Apply(() =>
        {
            if (Equals(property.Value, value))
                return;

            property.Value = value;
            PropertyChanged?.Invoke(
                this,
                new PropertyChangedEventArgs(property.Descriptor.Name));
        });
    }

    private int Apply(Action action) => Apply(() =>
    {
        action();
        return 0;
    });

    private int Apply(Func<int> action)
    {
        if (Volatile.Read(ref _disposed) != 0)
            return 0;

        var hresult = 0;
        void ApplyIfAlive()
        {
            if (Volatile.Read(ref _disposed) == 0)
            {
                try
                {
                    hresult = action();
                }
                catch
                {
                    hresult = unchecked((int)0x80004005);
                }
            }
        }

        try
        {
            _dispatch(ApplyIfAlive);
        }
        catch
        {
            return unchecked((int)0x80004005);
        }

        return hresult;
    }

    private void SetError(string propertyName, string? message)
    {
        if (message is null)
        {
            if (_errors.Remove(propertyName))
                ErrorsChanged?.Invoke(this, new DataErrorsChangedEventArgs(propertyName));
        }
        else
        {
            _errors[propertyName] = message;
            ErrorsChanged?.Invoke(this, new DataErrorsChangedEventArgs(propertyName));
        }
    }

    private void SetProperty(RuntimeProperty property, object? value)
    {
        if (!property.Descriptor.Writable)
            throw new InvalidOperationException(
                $"Rust view-model property '{property.Descriptor.Name}' is read-only.");

        var result = WireKind(property.Descriptor.Kind) switch
        {
            RustViewModelValueKind.String =>
                _model.SetString(property.Descriptor.Id, Convert.ToString(value, CultureInfo.InvariantCulture)),
            RustViewModelValueKind.Integer =>
                _model.SetInteger(property.Descriptor.Id, Convert.ToInt64(value, CultureInfo.InvariantCulture)),
            RustViewModelValueKind.Boolean =>
                _model.SetBoolean(property.Descriptor.Id, Convert.ToBoolean(value, CultureInfo.InvariantCulture) ? 1 : 0),
            RustViewModelValueKind.Double =>
                _model.SetDouble(property.Descriptor.Id, Convert.ToDouble(value, CultureInfo.InvariantCulture)),
            _ => throw new ArgumentOutOfRangeException(),
        };
        Check(result);
    }

    private void Execute(RustViewModelCommandDescriptor command)
    {
        var parameter = command.ParameterProperty is null
            ? null
            : (string?)_membersByName[command.ParameterProperty].GetValue();
        Check(command.IsAsync
            ? _model.BeginAsync(command.Id, parameter)
            : _model.Execute(command.Id, parameter));
    }

    private static RustViewModelValueKind WireKind(RustViewModelValueKind kind) =>
        kind == RustViewModelValueKind.Enum ? RustViewModelValueKind.Integer : kind;

    private static Type ValueType(RustViewModelPropertyDescriptor descriptor) => descriptor.Kind switch
    {
        RustViewModelValueKind.String => typeof(string),
        RustViewModelValueKind.Integer => typeof(long),
        RustViewModelValueKind.Boolean => typeof(bool),
        RustViewModelValueKind.Double => typeof(double),
        RustViewModelValueKind.Enum => descriptor.InitialValue?.GetType() ?? typeof(long),
        RustViewModelValueKind.Model => typeof(ReflectableRustViewModelAdapter),
        _ => throw new ArgumentOutOfRangeException(nameof(descriptor)),
    };

    private static void Dispatch(Action action)
    {
        if (Dispatcher.UIThread.CheckAccess())
            action();
        else
            Dispatcher.UIThread.Invoke(action);
    }

    private static void Check(int hresult)
    {
        if (hresult < 0)
            Marshal.ThrowExceptionForHR(hresult);
    }

    private sealed class RuntimeProperty(RustViewModelPropertyDescriptor descriptor)
    {
        public RustViewModelPropertyDescriptor Descriptor { get; } = descriptor;
        public object? Value { get; set; } = descriptor.InitialValue;
    }

    private sealed class RuntimeCollection(RustViewModelCollectionDescriptor descriptor)
    {
        public RustViewModelCollectionDescriptor Descriptor { get; } = descriptor;
        public ObservableCollection<object?> Items { get; } = [];
    }

    private sealed class RuntimeMember(
        string name,
        Type propertyType,
        bool canWrite,
        Func<object?> getValue,
        Action<object?>? setValue)
    {
        public string Name { get; } = name;
        public Type PropertyType { get; } = propertyType;
        public bool CanWrite { get; } = canWrite;
        public object? GetValue() => getValue();
        public void SetValue(object? value) => setValue!(value);
    }

    private sealed class ReflectableTypeInfo(
        IReadOnlyDictionary<string, RuntimeMember> members)
        : TypeDelegator(typeof(ReflectableRustViewModelAdapter))
    {
        [UnconditionalSuppressMessage(
            "Trimming",
            "IL2094",
            Justification = "Dynamic Rust members are returned from explicit metadata, not the delegated CLR type.")]
        protected override PropertyInfo? GetPropertyImpl(
            string name,
            BindingFlags bindingAttr,
            Binder? binder,
            Type? returnType,
            Type[]? types,
            ParameterModifier[]? modifiers)
        {
            if (!members.TryGetValue(name, out var member) ||
                returnType is not null && returnType != member.PropertyType ||
                types is { Length: > 0 })
            {
                return null;
            }

            return new ReflectablePropertyInfo(member);
        }

        [UnconditionalSuppressMessage(
            "Trimming",
            "IL2094",
            Justification = "Dynamic Rust members are returned from explicit metadata, not the delegated CLR type.")]
        public override PropertyInfo[] GetProperties(BindingFlags bindingAttr)
        {
            var properties = new PropertyInfo[members.Count];
            var index = 0;
            foreach (var member in members.Values)
                properties[index++] = new ReflectablePropertyInfo(member);
            return properties;
        }
    }

    private sealed class ReflectablePropertyInfo(RuntimeMember member) : PropertyInfo
    {
        public override PropertyAttributes Attributes => PropertyAttributes.None;
        public override bool CanRead => true;
        public override bool CanWrite => member.CanWrite;
        public override Type PropertyType => member.PropertyType;
        public override Type DeclaringType => typeof(ReflectableRustViewModelAdapter);
        public override string Name => member.Name;
        public override Type ReflectedType => typeof(ReflectableRustViewModelAdapter);

        public override MethodInfo[] GetAccessors(bool nonPublic) => [];
        public override MethodInfo? GetGetMethod(bool nonPublic) => null;
        public override ParameterInfo[] GetIndexParameters() => [];
        public override MethodInfo? GetSetMethod(bool nonPublic) => null;
        public override object[] GetCustomAttributes(bool inherit) => [];
        public override object[] GetCustomAttributes(Type attributeType, bool inherit) => [];
        public override bool IsDefined(Type attributeType, bool inherit) => false;

        public override object? GetValue(
            object? obj,
            BindingFlags invokeAttr,
            Binder? binder,
            object?[]? index,
            CultureInfo? culture)
        {
            ValidateTarget(obj);
            return member.GetValue();
        }

        public override void SetValue(
            object? obj,
            object? value,
            BindingFlags invokeAttr,
            Binder? binder,
            object?[]? index,
            CultureInfo? culture)
        {
            ValidateTarget(obj);
            if (!member.CanWrite)
                throw new ArgumentException($"Property '{member.Name}' is read-only.");
            member.SetValue(value);
        }

        private static void ValidateTarget(object? target)
        {
            if (target is not ReflectableRustViewModelAdapter)
                throw new TargetException("The target is not a Rust view-model adapter.");
        }
    }

    public sealed class DelegateCommand(Action execute) : ICommand
    {
        private bool _canExecute = true;

        public event EventHandler? CanExecuteChanged;
        public bool CanExecute(object? parameter) => _canExecute;
        public void Execute(object? parameter) => execute();

        public void SetEnabled(bool value)
        {
            if (_canExecute == value)
                return;
            _canExecute = value;
            CanExecuteChanged?.Invoke(this, EventArgs.Empty);
        }
    }
}
