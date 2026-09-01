using System.Runtime.InteropServices;
using System.Runtime.InteropServices.Marshalling;

namespace Avalonia.Host.Com;

[GeneratedComInterface(StringMarshalling = StringMarshalling.Utf16)]
[Guid(AvnGuids.IAvnRustViewModel)]
public partial interface IAvnRustViewModel
{
    [PreserveSig]
    int Attach(IAvnRustVmSink? sink);

    [PreserveSig]
    int Detach();

    [PreserveSig]
    int SetName(string? value);

    [PreserveSig]
    int Increment();

    [PreserveSig]
    int AddItem(string? value);

    [PreserveSig]
    int BeginSave();
}

[GeneratedComInterface(StringMarshalling = StringMarshalling.Utf16)]
[Guid(AvnGuids.IAvnRustVmSink)]
public partial interface IAvnRustVmSink
{
    [PreserveSig]
    int SetName(string? value);

    [PreserveSig]
    int SetCount(int value);

    [PreserveSig]
    int AddItem(string? value);

    [PreserveSig]
    int SetStatus(string? value);
}
