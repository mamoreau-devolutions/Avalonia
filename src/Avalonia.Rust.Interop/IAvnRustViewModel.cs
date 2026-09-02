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
