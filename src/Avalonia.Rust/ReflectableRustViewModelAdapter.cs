using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.Linq;
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
    IAvnRustVmSink3,
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
    private readonly object _batchGate = new();
    private int _disposed;
    private long _lastBatchGeneration = -1;

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

    /// <summary>
    /// Posts exactly one UI work item and deliberately does not inspect <paramref name="batch"/>
    /// on this COM call stack. This is the worker-safe publication path; the legacy sink
    /// members above remain synchronous only for ABI compatibility.
    /// </summary>
    public int SubmitBatch(IAvnRustVmUpdateBatch? batch)
    {
        if (batch is null)
            return InvalidArgument;

        try
        {
            Dispatcher.UIThread.Post(() => ApplyBatch(batch));
            return 0;
        }
        catch
        {
            // Completion is posted as well: a Rust callback is never made on SubmitBatch's stack.
            Dispatcher.UIThread.Post(() => RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, unchecked((int)0x80004005)));
            return unchecked((int)0x80004005);
        }
    }

    public void Dispose()
    {
        lock (_batchGate)
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

    private void ApplyBatch(IAvnRustVmUpdateBatch batch)
    {
        lock (_batchGate)
        {
            if (Volatile.Read(ref _disposed) != 0)
            {
                RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Cancelled);
                return;
            }

            try
            {
                var hr = batch.GetGeneration(out var generation);
                if (hr < 0)
                {
                    RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, hr);
                    return;
                }
                // Equal generations are stale too.  This gives duplicates a deterministic outcome
                // and makes the highest generation win regardless of worker submission order.
                if (generation <= Volatile.Read(ref _lastBatchGeneration))
                {
                    RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Stale);
                    return;
                }

                hr = batch.GetOperationCount(out var count);
                if (hr < 0 || count < 0)
                {
                    RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, hr < 0 ? hr : InvalidArgument);
                    return;
                }

                var entries = new List<BatchEntry>(count);
                for (var index = 0; index < count; index++)
                {
                    hr = batch.GetOperation(index, out var operation);
                    if (hr < 0 || operation is null || !TryRead(operation, out var entry, out hr))
                    {
                        RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, hr < 0 ? hr : InvalidArgument);
                        return;
                    }
                    if (entry.Kind is RustVmUpdateKind.ReplaceStringSnapshot or RustVmUpdateKind.ReplaceModelSnapshot)
                    {
                        if (!TryReadSnapshot(batch, index, entry, out hr))
                        {
                            RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, hr);
                            return;
                        }
                    }
                    entries.Add(entry);
                }

                if (!ValidateAndStage(entries, out hr))
                {
                    DisposeStaged(entries);
                    RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, hr);
                    return;
                }

                Commit(entries);
                Volatile.Write(ref _lastBatchGeneration, generation);
                RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Applied);
            }
            catch (BatchCancelledException)
            {
                RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Cancelled);
            }
            catch
            {
                RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, unchecked((int)0x80004005));
            }
    }
        }

        private bool TryRead(IAvnRustVmUpdateOperation operation, out BatchEntry entry, out int hr)
        {
            entry = new BatchEntry();
            hr = operation.GetKind(out var kind);
            if (hr < 0 || !Enum.IsDefined(typeof(RustVmUpdateKind), kind))
                return false;
            entry.Kind = (RustVmUpdateKind)kind;
            hr = operation.GetTargetId(out entry.Target);
            if (hr < 0) return false;
            hr = operation.GetIndex(out entry.Index);
            if (hr < 0) return false;
            hr = operation.GetIndex2(out entry.Index2);
            if (hr < 0) return false;
            hr = operation.GetInteger(out entry.Integer);
            if (hr < 0) return false;
            hr = operation.GetDouble(out entry.Double);
            if (hr < 0) return false;
            hr = operation.GetBoolean(out entry.Boolean);
            if (hr < 0) return false;
            hr = RustVmBatchReader.ReadText(operation, out entry.Text);
            if (hr < 0) return false;
            hr = operation.GetModel(out entry.Model);
            return hr >= 0;
        }

        private bool TryReadSnapshot(IAvnRustVmUpdateBatch batch, int operationIndex, BatchEntry entry, out int hr)
        {
            hr = batch.GetSnapshotItemCount(operationIndex, out var count);
            if (hr < 0 || count < 0)
            {
                hr = hr < 0 ? hr : InvalidArgument;
                return false;
            }
            entry.Snapshot = new List<object?>(count);
            for (var item = 0; item < count; item++)
            {
                if (entry.Kind == RustVmUpdateKind.ReplaceStringSnapshot)
                {
                    hr = RustVmBatchReader.ReadSnapshotText(batch, operationIndex, item, out var value);
                    if (hr < 0) return false;
                    entry.Snapshot.Add(value);
                }
                else
                {
                    hr = batch.GetSnapshotModel(operationIndex, item, out var model);
                    if (hr < 0 || model is null)
                    {
                        hr = hr < 0 ? hr : InvalidArgument;
                        return false;
                    }
                    entry.Snapshot.Add(model);
                }
            }
            return true;
        }

        private bool ValidateAndStage(List<BatchEntry> entries, out int hr)
        {
            hr = 0;
            var counts = _collectionsById.ToDictionary(pair => pair.Key, pair => pair.Value.Items.Count);
            foreach (var entry in entries)
            {
                if (Volatile.Read(ref _disposed) != 0)
                    throw new BatchCancelledException();
                if (!ValidateEntry(entry, counts))
                {
                    hr = InvalidArgument;
                    return false;
                }
                try
                {
                    if (entry.Kind is RustVmUpdateKind.SetModel or RustVmUpdateKind.AddModel or RustVmUpdateKind.InsertModel or RustVmUpdateKind.ReplaceModel)
                        entry.StagedModel = new ReflectableRustViewModelAdapter(entry.Model!, ModelDescriptor(entry), _dispatch);
                    else if (entry.Kind == RustVmUpdateKind.ReplaceModelSnapshot)
                    {
                        var staged = new List<object?>();
                        try
                        {
                            foreach (var model in entry.Snapshot!.Cast<IAvnRustViewModel>())
                                staged.Add(new ReflectableRustViewModelAdapter(model, ModelDescriptor(entry), _dispatch));
                            entry.StagedSnapshot = staged;
                        }
                        catch
                        {
                            foreach (var adapter in staged)
                                TryDispose(adapter as IDisposable);
                            throw;
                        }
                    }
                }
                catch
                {
                    hr = unchecked((int)0x80004005);
                    return false;
                }
            }
            return true;
        }

        private bool ValidateEntry(BatchEntry entry, Dictionary<int, int> counts)
        {
            if (entry.Kind is RustVmUpdateKind.SetString or RustVmUpdateKind.SetInteger or RustVmUpdateKind.SetBoolean or RustVmUpdateKind.SetDouble or RustVmUpdateKind.SetNull or RustVmUpdateKind.SetModel or RustVmUpdateKind.SetPropertyError)
            {
                if (!_propertiesById.TryGetValue(entry.Target, out var property))
                    return false;
                return entry.Kind switch
                {
                    RustVmUpdateKind.SetString => WireKind(property.Descriptor.Kind) == RustViewModelValueKind.String,
                    RustVmUpdateKind.SetInteger => WireKind(property.Descriptor.Kind) == RustViewModelValueKind.Integer &&
                        (property.Descriptor.Kind != RustViewModelValueKind.Enum || Enum.IsDefined(property.Value!.GetType(), entry.Integer)),
                    RustVmUpdateKind.SetBoolean => WireKind(property.Descriptor.Kind) == RustViewModelValueKind.Boolean,
                    RustVmUpdateKind.SetDouble => WireKind(property.Descriptor.Kind) == RustViewModelValueKind.Double,
                    RustVmUpdateKind.SetNull => property.Descriptor.Nullable,
                    RustVmUpdateKind.SetModel => property.Descriptor.Kind == RustViewModelValueKind.Model && entry.Model is not null,
                    _ => true,
                };
            }
            if (entry.Kind == RustVmUpdateKind.SetCommandEnabled)
                return _commandsById.ContainsKey(entry.Target);
            if (!_collectionsById.TryGetValue(entry.Target, out var collection) || !counts.TryGetValue(entry.Target, out var count))
                return false;
            var models = collection.Descriptor.ElementKind == RustViewModelValueKind.Model;
            var strings = collection.Descriptor.ElementKind == RustViewModelValueKind.String;
            var validIndex = entry.Index >= 0 && entry.Index < count;
            var insertIndex = entry.Index >= 0 && entry.Index <= count;
            switch (entry.Kind)
            {
                case RustVmUpdateKind.AddString when strings: counts[entry.Target] = count + 1; return true;
                case RustVmUpdateKind.AddModel when models && entry.Model is not null: counts[entry.Target] = count + 1; return true;
                case RustVmUpdateKind.InsertString when strings && insertIndex: counts[entry.Target] = count + 1; return true;
                case RustVmUpdateKind.InsertModel when models && insertIndex && entry.Model is not null: counts[entry.Target] = count + 1; return true;
                case RustVmUpdateKind.ReplaceString when strings && validIndex: return true;
                case RustVmUpdateKind.ReplaceModel when models && validIndex && entry.Model is not null: return true;
                case RustVmUpdateKind.RemoveAt when validIndex: counts[entry.Target] = count - 1; return true;
                case RustVmUpdateKind.MoveItem when validIndex && entry.Index2 >= 0 && entry.Index2 < count: return true;
                case RustVmUpdateKind.ReplaceStringSnapshot when strings: counts[entry.Target] = entry.Snapshot!.Count; return true;
                case RustVmUpdateKind.ReplaceModelSnapshot when models: counts[entry.Target] = entry.Snapshot!.Count; return true;
                default: return false;
            }
        }

        private RustViewModelDescriptor ModelDescriptor(BatchEntry entry) =>
            entry.Kind == RustVmUpdateKind.SetModel
                ? _propertiesById[entry.Target].Descriptor.NestedDescriptor!
                : _collectionsById[entry.Target].Descriptor.ElementDescriptor!;

        private void Commit(IEnumerable<BatchEntry> entries)
        {
            foreach (var entry in entries)
            {
                if ((entry.Kind is RustVmUpdateKind.SetString or RustVmUpdateKind.SetInteger or
                    RustVmUpdateKind.SetBoolean or RustVmUpdateKind.SetDouble or RustVmUpdateKind.SetNull or
                    RustVmUpdateKind.SetModel or RustVmUpdateKind.SetPropertyError) &&
                    _propertiesById.TryGetValue(entry.Target, out var property))
                {
                    object? value = entry.Kind switch
                    {
                        RustVmUpdateKind.SetString => property.Descriptor.Nullable ? entry.Text : entry.Text ?? "",
                        RustVmUpdateKind.SetInteger when property.Descriptor.Kind == RustViewModelValueKind.Enum => Enum.ToObject(property.Value!.GetType(), entry.Integer),
                        RustVmUpdateKind.SetInteger => entry.Integer,
                        RustVmUpdateKind.SetBoolean => entry.Boolean != 0,
                        RustVmUpdateKind.SetDouble => entry.Double,
                        RustVmUpdateKind.SetNull => null,
                        RustVmUpdateKind.SetModel => entry.StagedModel,
                        _ => property.Value,
                    };
                    if (entry.Kind == RustVmUpdateKind.SetPropertyError) { SetError(property.Descriptor.Name, entry.Text); continue; }
                    if ((entry.Kind is RustVmUpdateKind.SetString or RustVmUpdateKind.SetInteger or
                        RustVmUpdateKind.SetBoolean or RustVmUpdateKind.SetDouble or RustVmUpdateKind.SetNull or
                        RustVmUpdateKind.SetModel) && !Equals(property.Value, value))
                    {
                        var previous = property.Value as ReflectableRustViewModelAdapter;
                        property.Value = value;
                        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(property.Descriptor.Name));
                        previous?.Dispose();
                    }
                    continue;
                }
                if (entry.Kind == RustVmUpdateKind.SetCommandEnabled) { _commandsById[entry.Target].SetEnabled(entry.Boolean != 0); continue; }
                var collection = _collectionsById[entry.Target].Items;
                switch (entry.Kind)
                {
                    case RustVmUpdateKind.AddString: collection.Add(entry.Text ?? ""); break;
                    case RustVmUpdateKind.AddModel: collection.Add(entry.StagedModel); break;
                    case RustVmUpdateKind.InsertString: collection.Insert(entry.Index, entry.Text ?? ""); break;
                    case RustVmUpdateKind.InsertModel: collection.Insert(entry.Index, entry.StagedModel); break;
                    case RustVmUpdateKind.ReplaceString: collection[entry.Index] = entry.Text ?? ""; break;
                    case RustVmUpdateKind.ReplaceModel: ReplaceAndDispose(collection, entry.Index, entry.StagedModel); break;
                    case RustVmUpdateKind.RemoveAt: RemoveAndDispose(collection, entry.Index); break;
                    case RustVmUpdateKind.MoveItem: collection.Move(entry.Index, entry.Index2); break;
                    case RustVmUpdateKind.ReplaceStringSnapshot: ReplaceSnapshot(collection, entry.Snapshot!); break;
                    case RustVmUpdateKind.ReplaceModelSnapshot: ReplaceSnapshot(collection, entry.StagedSnapshot!); break;
                }
            }
        }

        private static void ReplaceAndDispose(ObservableCollection<object?> collection, int index, object? value)
        {
            var old = collection[index];
            collection[index] = value;
            (old as IDisposable)?.Dispose();
        }

        private static void RemoveAndDispose(ObservableCollection<object?> collection, int index)
        {
            var old = collection[index];
            collection.RemoveAt(index);
            (old as IDisposable)?.Dispose();
        }

        private static void ReplaceSnapshot(ObservableCollection<object?> collection, IReadOnlyList<object?> values)
        {
            var old = collection.ToArray();
            if (collection is BatchObservableCollection<object?> batch)
                batch.ReplaceSnapshot(values);
            else
            {
                collection.Clear();
                foreach (var value in values) collection.Add(value);
            }
            foreach (var item in old) (item as IDisposable)?.Dispose();
        }

        private static void DisposeStaged(IEnumerable<BatchEntry> entries)
        {
            foreach (var entry in entries)
            {
                TryDispose(entry.StagedModel);
                if (entry.StagedSnapshot is not null)
                    foreach (var item in entry.StagedSnapshot) TryDispose(item as IDisposable);
            }
        }

    private sealed class BatchEntry
        {
            public RustVmUpdateKind Kind;
            public int Target;
            public int Index;
            public int Index2;
            public long Integer;
            public double Double;
            public int Boolean;
            public string? Text;
            public IAvnRustViewModel? Model;
            public List<object?>? Snapshot;
            public ReflectableRustViewModelAdapter? StagedModel;
            public List<object?>? StagedSnapshot;
    }

    private sealed class BatchCancelledException : Exception;

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
        public BatchObservableCollection<object?> Items { get; } = [];
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
