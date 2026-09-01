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
