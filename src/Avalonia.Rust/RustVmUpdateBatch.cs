using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.ComponentModel;
using Avalonia.Rust.Interop;
using Avalonia.Threading;

namespace Avalonia.Rust;

public enum RustVmUpdateKind
{
    SetString = 1, SetInteger, SetBoolean, SetDouble, SetNull, SetModel,
    AddString, AddModel, InsertString, InsertModel, ReplaceString, ReplaceModel,
    RemoveAt, MoveItem, ReplaceStringSnapshot, ReplaceModelSnapshot,
    SetCommandEnabled, SetPropertyError, ClearCollection,
}

public enum RustVmBatchOutcome { Applied, Stale, Cancelled, Error }

public sealed class BatchObservableCollection<T> : ObservableCollection<T>
{
    public void ReplaceSnapshot(IReadOnlyList<T> values)
    {
        ArgumentNullException.ThrowIfNull(values);
        Items.Clear();
        foreach (var value in values)
            Items.Add(value);
        OnPropertyChanged(new PropertyChangedEventArgs(nameof(Count)));
        OnPropertyChanged(new PropertyChangedEventArgs("Item[]"));
        OnCollectionChanged(new NotifyCollectionChangedEventArgs(NotifyCollectionChangedAction.Reset));
    }
}

/// <summary>IR-generated adapters implement this to atomically replace snapshots.</summary>
public interface IRustVmStringSnapshotSink
{
    int ReplaceStringSnapshot(int collectionId, IReadOnlyList<string> values);
}

/// <summary>IR-generated adapters implement this to atomically replace model snapshots.</summary>
public interface IRustVmModelSnapshotSink
{
    int ReplaceModelSnapshot(int collectionId, IReadOnlyList<IAvnRustViewModel> values);
}

public interface IRustVmBatchSchema
{
    int PropertyKind(int propertyId);
    bool IsCommand(int commandId);
    int CollectionKind(int collectionId);
    int CollectionCount(int collectionId);
}

internal static unsafe class RustVmBatchReader
{
    internal static int ReadText(IAvnRustVmUpdateOperation operation, out string? value)
    {
        value = null;
        var hr = operation.GetTextLength(out var length);
        if (hr < 0 || length < 0)
            return hr < 0 ? hr : unchecked((int)0x80070057);
        var buffer = new char[length + 1];
        fixed (char* pointer = buffer)
            hr = operation.CopyText(pointer, buffer.Length);
        if (hr >= 0)
            value = new string(buffer, 0, length);
        return hr;
    }

    internal static int ReadSnapshotText(IAvnRustVmUpdateBatch batch, int operation, int item, out string value)
    {
        value = string.Empty;
        var hr = batch.GetSnapshotStringLength(operation, item, out var length);
        if (hr < 0 || length < 0)
            return hr < 0 ? hr : unchecked((int)0x80070057);
        var buffer = new char[length + 1];
        fixed (char* pointer = buffer)
            hr = batch.CopySnapshotString(operation, item, pointer, buffer.Length);
        if (hr >= 0)
            value = new string(buffer, 0, length);
        return hr;
    }

    internal static void Complete(IAvnRustVmUpdateBatch batch, RustVmBatchOutcome outcome, int error = 0)
    {
        try { _ = batch.Complete((int)outcome, error); } catch { }
    }
}

/// <summary>Shared nonblocking submission plumbing for IR-generated adapters.</summary>
public static class RustVmBatchSubmission
{
    private const int InvalidArgument = unchecked((int)0x80070057);

    public static int Submit(
        IAvnRustVmSink sink,
        IAvnRustVmSink2 sink2,
        IAvnRustVmUpdateBatch? batch,
        Func<long> getLastGeneration,
        Action<long> setLastGeneration,
        Func<bool> isAlive)
    {
        if (batch is null)
            return InvalidArgument;
        try
        {
            // Do not call into `batch` here. The foreign immutable object is
            // read only from this queued UI callback.
            Dispatcher.UIThread.Post(() => Apply(sink, sink2, batch, getLastGeneration, setLastGeneration, isAlive));
            return 0;
        }
        catch { return unchecked((int)0x80004005); }
    }

    private static void Apply(
        IAvnRustVmSink sink, IAvnRustVmSink2 sink2, IAvnRustVmUpdateBatch batch,
        Func<long> getLastGeneration, Action<long> setLastGeneration, Func<bool> isAlive)
    {
        try
        {
            if (!isAlive()) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Cancelled); return; }
            var hr = batch.GetGeneration(out var generation);
            if (hr < 0) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, hr); return; }
            if (generation <= getLastGeneration()) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Stale); return; }
            hr = batch.GetOperationCount(out var count);
            if (hr < 0 || count < 0) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, InvalidArgument); return; }
            var entries = new List<(RustVmUpdateKind Kind, int Target, int Index, int Index2, long Integer, double Double, int Boolean, string? Text, IAvnRustViewModel? Model, List<string>? Strings, List<IAvnRustViewModel>? Models)>();
            for (var i = 0; i < count; i++)
            {
                hr = batch.GetOperation(i, out var operation);
                if (hr < 0 || operation is null) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, InvalidArgument); return; }
                hr = operation.GetKind(out var kind);
                if (hr < 0 || !Enum.IsDefined(typeof(RustVmUpdateKind), kind)) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, InvalidArgument); return; }
                hr = operation.GetTargetId(out var target); if (hr < 0) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, hr); return; }
                hr = operation.GetIndex(out var index); if (hr < 0) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, hr); return; }
                hr = operation.GetIndex2(out var index2); if (hr < 0) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, hr); return; }
                hr = operation.GetInteger(out var integer); if (hr < 0) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, hr); return; }
                hr = operation.GetDouble(out var number); if (hr < 0) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, hr); return; }
                hr = operation.GetBoolean(out var boolean); if (hr < 0) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, hr); return; }
                hr = RustVmBatchReader.ReadText(operation, out var text); if (hr < 0) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, hr); return; }
                hr = operation.GetModel(out var model); if (hr < 0) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, hr); return; }
                List<string>? snapshot = null;
                if ((RustVmUpdateKind)kind == RustVmUpdateKind.ReplaceStringSnapshot)
                {
                    hr = batch.GetSnapshotItemCount(i, out var itemCount);
                    if (hr < 0 || itemCount < 0) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, InvalidArgument); return; }
                    snapshot = new List<string>(itemCount);
                    for (var item = 0; item < itemCount; item++)
                    {
                        hr = RustVmBatchReader.ReadSnapshotText(batch, i, item, out var value);
                        if (hr < 0) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, hr); return; }
                        snapshot.Add(value);
                    }
                }
                List<IAvnRustViewModel>? models = null;
                if ((RustVmUpdateKind)kind == RustVmUpdateKind.ReplaceModelSnapshot)
                {
                    hr = batch.GetSnapshotItemCount(i, out var itemCount);
                    if (hr < 0 || itemCount < 0) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, InvalidArgument); return; }
                    models = new List<IAvnRustViewModel>(itemCount);
                    for (var item = 0; item < itemCount; item++)
                    {
                        hr = batch.GetSnapshotModel(i, item, out var nested);
                        if (hr < 0 || nested is null) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, InvalidArgument); return; }
                        models.Add(nested);
                    }
                }
                entries.Add(((RustVmUpdateKind)kind, target, index, index2, integer, number, boolean, text, model, snapshot, models));
            }
            if (sink is not IRustVmBatchSchema schema || !Validate(entries, schema))
            {
                RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, InvalidArgument);
                return;
            }
            foreach (var entry in entries)
            {
                hr = entry.Kind switch
                {
                    RustVmUpdateKind.SetString => sink.SetString(entry.Target, entry.Text),
                    RustVmUpdateKind.SetInteger => sink.SetInteger(entry.Target, entry.Integer),
                    RustVmUpdateKind.SetBoolean => sink.SetBoolean(entry.Target, entry.Boolean),
                    RustVmUpdateKind.SetDouble => sink.SetDouble(entry.Target, entry.Double),
                    RustVmUpdateKind.SetNull => sink2.SetNull(entry.Target),
                    RustVmUpdateKind.SetModel => sink2.SetModel(entry.Target, entry.Model),
                    RustVmUpdateKind.AddString => sink.AddString(entry.Target, entry.Text),
                    RustVmUpdateKind.AddModel => sink2.AddModel(entry.Target, entry.Model),
                    RustVmUpdateKind.InsertString => sink2.InsertString(entry.Target, entry.Index, entry.Text),
                    RustVmUpdateKind.InsertModel => sink2.InsertModel(entry.Target, entry.Index, entry.Model),
                    RustVmUpdateKind.ReplaceString => sink2.ReplaceString(entry.Target, entry.Index, entry.Text),
                    RustVmUpdateKind.ReplaceModel => sink2.ReplaceModel(entry.Target, entry.Index, entry.Model),
                    RustVmUpdateKind.RemoveAt => sink2.RemoveAt(entry.Target, entry.Index),
                    RustVmUpdateKind.MoveItem => sink2.MoveItem(entry.Target, entry.Index, entry.Index2),
                    RustVmUpdateKind.SetCommandEnabled => sink2.SetCommandEnabled(entry.Target, entry.Boolean),
                    RustVmUpdateKind.SetPropertyError => sink2.SetPropertyError(entry.Target, entry.Text),
                    RustVmUpdateKind.ClearCollection => sink2.ClearCollection(entry.Target),
                    RustVmUpdateKind.ReplaceStringSnapshot when sink is IRustVmStringSnapshotSink snapshots =>
                        snapshots.ReplaceStringSnapshot(entry.Target, entry.Strings!),
                    RustVmUpdateKind.ReplaceModelSnapshot when sink is IRustVmModelSnapshotSink snapshots =>
                        snapshots.ReplaceModelSnapshot(entry.Target, entry.Models!),
                    _ => InvalidArgument,
                };
                if (hr < 0) { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, hr); return; }
            }
            setLastGeneration(generation);
            RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Applied);
        }
        catch { RustVmBatchReader.Complete(batch, RustVmBatchOutcome.Error, unchecked((int)0x80004005)); }
    }

    private static bool Validate(
        List<(RustVmUpdateKind Kind, int Target, int Index, int Index2, long Integer, double Double, int Boolean, string? Text, IAvnRustViewModel? Model, List<string>? Strings, List<IAvnRustViewModel>? Models)> entries,
        IRustVmBatchSchema schema)
    {
        var counts = new Dictionary<int, int>();
        var modelMutationCount = 0;
        foreach (var entry in entries)
        {
            var propertyKind = schema.PropertyKind(entry.Target);
            if (entry.Kind is RustVmUpdateKind.SetString or RustVmUpdateKind.SetInteger or RustVmUpdateKind.SetBoolean or RustVmUpdateKind.SetDouble or RustVmUpdateKind.SetNull or RustVmUpdateKind.SetModel or RustVmUpdateKind.SetPropertyError)
            {
                if (propertyKind == 0) return false;
                if (entry.Kind == RustVmUpdateKind.SetString && propertyKind != 1) return false;
                if (entry.Kind == RustVmUpdateKind.SetInteger && propertyKind != 2) return false;
                if (entry.Kind == RustVmUpdateKind.SetBoolean && propertyKind != 3) return false;
                if (entry.Kind == RustVmUpdateKind.SetDouble && propertyKind != 4) return false;
                if (entry.Kind == RustVmUpdateKind.SetModel && (propertyKind != 6 || entry.Model is null)) return false;
                if (entry.Kind == RustVmUpdateKind.SetModel) modelMutationCount++;
                continue;
            }
            if (entry.Kind == RustVmUpdateKind.SetCommandEnabled) { if (!schema.IsCommand(entry.Target)) return false; else continue; }
            var kind = schema.CollectionKind(entry.Target);
            if (kind == 0) return false;
            if (!counts.TryGetValue(entry.Target, out var count)) counts[entry.Target] = count = schema.CollectionCount(entry.Target);
            var valid = entry.Index >= 0 && entry.Index < count;
            var insert = entry.Index >= 0 && entry.Index <= count;
            switch (entry.Kind)
            {
                case RustVmUpdateKind.AddString when kind == 1: counts[entry.Target]++; break;
                case RustVmUpdateKind.AddModel when kind == 6 && entry.Model is not null: modelMutationCount++; counts[entry.Target]++; break;
                case RustVmUpdateKind.InsertString when kind == 1 && insert: counts[entry.Target]++; break;
                case RustVmUpdateKind.InsertModel when kind == 6 && insert && entry.Model is not null: modelMutationCount++; counts[entry.Target]++; break;
                case RustVmUpdateKind.ReplaceString when kind == 1 && valid: break;
                case RustVmUpdateKind.ReplaceModel when kind == 6 && valid && entry.Model is not null: modelMutationCount++; break;
                case RustVmUpdateKind.RemoveAt when valid: counts[entry.Target]--; break;
                case RustVmUpdateKind.MoveItem when valid && entry.Index2 >= 0 && entry.Index2 < count: break;
                case RustVmUpdateKind.ClearCollection: counts[entry.Target] = 0; break;
                case RustVmUpdateKind.ReplaceStringSnapshot when kind == 1: counts[entry.Target] = entry.Strings!.Count; break;
                case RustVmUpdateKind.ReplaceModelSnapshot when kind == 6: modelMutationCount++; counts[entry.Target] = entry.Models!.Count; break;
                default: return false;
            }
        }
        // Generated adapters construct nested adapters as part of their existing
        // v2 sink methods. Until that ABI gains a staging callback, accepting a
        // mixed batch would make a later attach failure observable after scalar
        // mutation. Restrict such a batch to one model replacement, whose
        // generated method stages before it installs, rather than violate atomicity.
        return modelMutationCount == 0 || (modelMutationCount == 1 && entries.Count == 1);
    }
}
