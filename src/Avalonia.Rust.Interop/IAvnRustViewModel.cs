using System.Runtime.InteropServices;
using System.Runtime.InteropServices.Marshalling;

namespace Avalonia.Rust.Interop;

[GeneratedComInterface(StringMarshalling = StringMarshalling.Utf16)]
[Guid("6B2E8F10-4C91-4E3A-9A77-1F0C2B3A4D24")]
public partial interface IAvnRustViewModel
{
    [PreserveSig]
    int Attach(IAvnRustVmSink? sink);

    [PreserveSig]
    int Detach();

    [PreserveSig]
    int SetString(int propertyId, string? value);

    [PreserveSig]
    int SetInteger(int propertyId, long value);

    [PreserveSig]
    int SetBoolean(int propertyId, int value);

    [PreserveSig]
    int SetDouble(int propertyId, double value);

    [PreserveSig]
    int Execute(int commandId, string? parameter);

    [PreserveSig]
    int BeginAsync(int commandId, string? parameter);
}

[GeneratedComInterface(StringMarshalling = StringMarshalling.Utf16)]
[Guid("6B2E8F10-4C91-4E3A-9A77-1F0C2B3A4D25")]
public partial interface IAvnRustVmSink
{
    [PreserveSig]
    int SetString(int propertyId, string? value);

    [PreserveSig]
    int SetInteger(int propertyId, long value);

    [PreserveSig]
    int SetBoolean(int propertyId, int value);

    [PreserveSig]
    int SetDouble(int propertyId, double value);

    [PreserveSig]
    int AddString(int collectionId, string? value);
}

/// <summary>
/// A second, independently versioned sink interface. Carries the transport
/// added for nested view models, nullable values, collection insert/remove/
/// replace/move/clear, command <c>CanExecute</c> state, and validation-error
/// projection, without widening the <see cref="IAvnRustVmSink"/> vtable. A
/// generated adapter always implements both; Rust queries for this interface
/// once at attach time and surfaces an explicit ABI error if it is missing
/// rather than silently degrading.
/// </summary>
[GeneratedComInterface(StringMarshalling = StringMarshalling.Utf16)]
[Guid("6B2E8F10-4C91-4E3A-9A77-1F0C2B3A4D26")]
public partial interface IAvnRustVmSink2
{
    /// <summary>Publishes that a nullable scalar property now has no value.</summary>
    [PreserveSig]
    int SetNull(int propertyId);

    /// <summary>Publishes a nested view-model property (null clears it).</summary>
    [PreserveSig]
    int SetModel(int propertyId, IAvnRustViewModel? model);

    /// <summary>Appends a nested view-model item to a model-kind collection.</summary>
    [PreserveSig]
    int AddModel(int collectionId, IAvnRustViewModel? model);

    [PreserveSig]
    int InsertString(int collectionId, int index, string? value);

    [PreserveSig]
    int InsertModel(int collectionId, int index, IAvnRustViewModel? model);

    [PreserveSig]
    int ReplaceString(int collectionId, int index, string? value);

    [PreserveSig]
    int ReplaceModel(int collectionId, int index, IAvnRustViewModel? model);

    [PreserveSig]
    int RemoveAt(int collectionId, int index);

    [PreserveSig]
    int MoveItem(int collectionId, int fromIndex, int toIndex);

    /// <summary>Clears a collection. Managed raises a single Reset notification.</summary>
    [PreserveSig]
    int ClearCollection(int collectionId);

    /// <summary>Publishes a command's current <c>ICommand.CanExecute</c> state.</summary>
    [PreserveSig]
    int SetCommandEnabled(int commandId, int enabled);

    /// <summary>Publishes (or clears, when <paramref name="message"/> is null) a validation error for a property.</summary>
    [PreserveSig]
    int SetPropertyError(int propertyId, string? message);
}

/// <summary>
/// Immutable, versioned update-batch capability.  This interface is deliberately
/// separate from the v1 and v2 sink vtables: applications that publish from a
/// worker must use this capability rather than the synchronous per-member calls.
/// </summary>
[GeneratedComInterface(StringMarshalling = StringMarshalling.Utf16)]
[Guid("6B2E8F10-4C91-4E3A-9A77-1F0C2B3A4D27")]
public partial interface IAvnRustVmSink3
{
    /// <summary>
    /// Enqueues an immutable batch. This call never applies the batch or invokes
    /// the batch object; the adapter reads it later from one UI dispatcher item.
    /// </summary>
    [PreserveSig]
    int SubmitBatch(IAvnRustVmUpdateBatch? batch);
}

/// <summary>
/// Read-only nano-COM representation of a Rust-authored update batch.
/// Implementations must be immutable for their complete COM lifetime.
/// </summary>
[GeneratedComInterface(StringMarshalling = StringMarshalling.Utf16)]
[Guid("6B2E8F10-4C91-4E3A-9A77-1F0C2B3A4D28")]
public partial interface IAvnRustVmUpdateBatch
{
    [PreserveSig]
    int GetGeneration(out long generation);

    [PreserveSig]
    int GetOperationCount(out int count);

    [PreserveSig]
    int GetOperation(int index, out IAvnRustVmUpdateOperation? operation);

    [PreserveSig]
    int GetSnapshotItemCount(int operationIndex, out int count);

    [PreserveSig]
    int GetSnapshotStringLength(int operationIndex, int itemIndex, out int length);

    [PreserveSig]
    unsafe int CopySnapshotString(int operationIndex, int itemIndex, char* destination, int capacity);

    [PreserveSig]
    int GetSnapshotModel(int operationIndex, int itemIndex, out IAvnRustViewModel? model);

    /// <summary>Completes a queued batch after its UI-thread outcome is known.</summary>
    [PreserveSig]
    int Complete(int outcome, int error);
}

/// <summary>One immutable operation in an <see cref="IAvnRustVmUpdateBatch"/>.</summary>
[GeneratedComInterface(StringMarshalling = StringMarshalling.Utf16)]
[Guid("6B2E8F10-4C91-4E3A-9A77-1F0C2B3A4D29")]
public partial interface IAvnRustVmUpdateOperation
{
    [PreserveSig]
    int GetKind(out int kind);

    [PreserveSig]
    int GetTargetId(out int targetId);

    [PreserveSig]
    int GetIndex(out int index);

    [PreserveSig]
    int GetIndex2(out int index);

    [PreserveSig]
    int GetInteger(out long value);

    [PreserveSig]
    int GetDouble(out double value);

    [PreserveSig]
    int GetBoolean(out int value);

    [PreserveSig]
    int GetTextLength(out int length);

    [PreserveSig]
    unsafe int CopyText(char* destination, int capacity);

    [PreserveSig]
    int GetModel(out IAvnRustViewModel? model);
}
