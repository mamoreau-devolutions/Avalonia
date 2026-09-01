using System.Runtime.InteropServices;
using System.Runtime.InteropServices.Marshalling;

namespace Avalonia.Host.Com;

[GeneratedComInterface(StringMarshalling = StringMarshalling.Utf16)]
[Guid(AvnGuids.IAvnApplication)]
public partial interface IAvnApplication
{
    [PreserveSig]
    int Run(IAvnAppHandler? handler);

    [PreserveSig]
    int Shutdown();

    [PreserveSig]
    int GetRequestedThemeVariant(out int value);

    [PreserveSig]
    int SetRequestedThemeVariant(int value);

    [PreserveSig]
    int GetActualThemeVariant(out int value);

    [PreserveSig]
    int TryGetResource(string? key, int themeVariant, out int found, out IAvnResourceValue? value);

    [PreserveSig]
    int StartDelay(int milliseconds, IAvnAsyncCompletion? completion, out long operationId);

    [PreserveSig]
    int StartClipboardSetText(
        IAvnWindow? window,
        string? text,
        IAvnAsyncCompletion? completion,
        out long operationId);

    [PreserveSig]
    int StartClipboardGetText(
        IAvnWindow? window,
        IAvnAsyncCompletion? completion,
        out long operationId);

    [PreserveSig]
    int CancelAsyncOperation(long operationId);

    [PreserveSig]
    int CreateRustVmWindow(IAvnRustViewModel? model, out IAvnWindow? window);
}
