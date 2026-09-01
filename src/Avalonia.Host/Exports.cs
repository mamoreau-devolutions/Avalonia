using System.Diagnostics.CodeAnalysis;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.Marshalling;
using Avalonia.Host.Com;

namespace Avalonia.Host;

public static class Exports
{
    private static readonly StrategyBasedComWrappers Wrappers = new();

    [UnmanagedCallersOnly(EntryPoint = "avn_get_activation_factory")]
    [DynamicDependency(DynamicallyAccessedMemberTypes.All, typeof(AvnActivationFactory))]
    [DynamicDependency(DynamicallyAccessedMemberTypes.All, typeof(AvnEcho))]
    [DynamicDependency(DynamicallyAccessedMemberTypes.All, typeof(AvnApplication))]
    [DynamicDependency(DynamicallyAccessedMemberTypes.All, typeof(HostApplication))]
    public static unsafe int GetActivationFactory(nint* factory)
    {
        if (factory is null)
            return HResults.E_POINTER;

        try
        {
            var obj = new AvnActivationFactory();
            *factory = Wrappers.GetOrCreateComInterfaceForObject(obj, CreateComInterfaceFlags.None);
            return HResults.S_OK;
        }
        catch
        {
            *factory = 0;
            return HResults.E_FAIL;
        }
    }

    /// <summary>
    /// Frees memory allocated by the host for ABI strings (Utf16StringMarshaller / CoTaskMem).
    /// Do not use ole32 CoTaskMemFree so this stays portable with nano-COM.
    /// </summary>
    [UnmanagedCallersOnly(EntryPoint = "avn_free")]
    public static unsafe void Free(void* ptr)
    {
        if (ptr is not null)
            Marshal.FreeCoTaskMem((nint)ptr);
    }
}
