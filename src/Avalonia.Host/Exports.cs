using System;
using System.Diagnostics.CodeAnalysis;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.Marshalling;
using Avalonia.Host.Com;
using Avalonia.Host.Ownership;

namespace Avalonia.Host;

public static class Exports
{
    private static readonly StrategyBasedComWrappers Wrappers = new();

    [UnmanagedCallersOnly(EntryPoint = "avn_get_activation_factory")]
    [DynamicDependency(DynamicallyAccessedMemberTypes.All, typeof(AvnActivationFactory))]
    [DynamicDependency(DynamicallyAccessedMemberTypes.All, typeof(AvnEcho))]
    [DynamicDependency(DynamicallyAccessedMemberTypes.All, typeof(AvnApplication))]
    [DynamicDependency(DynamicallyAccessedMemberTypes.All, typeof(AvnDispatcher))]
    [DynamicDependency(DynamicallyAccessedMemberTypes.All, typeof(AvnResourceValue))]
    [DynamicDependency(DynamicallyAccessedMemberTypes.All, typeof(HostApplication))]
    public static unsafe int GetActivationFactory(nint* factory)
    {
        if (factory is null)
            return HResults.E_POINTER;

        try
        {
            ProjectionAotRoots.Preserve();
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

    [UnmanagedCallersOnly(EntryPoint = "avn_get_microcom_ownership_probe")]
    [DynamicDependency(DynamicallyAccessedMemberTypes.All, typeof(MicroComOwnershipProbe))]
    internal static unsafe int GetMicroComOwnershipProbe(nint* probe)
    {
        if (probe is null)
            return HResults.E_POINTER;
        try
        {
            *probe = new MicroComOwnershipProbe().GetNativePointer();
            return HResults.S_OK;
        }
        catch (Exception e)
        {
            *probe = 0;
            return AbiError.Capture(e);
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

    [UnmanagedCallersOnly(EntryPoint = "avn_get_last_error")]
    public static unsafe int GetLastError(nint* message)
    {
        if (message is null)
            return HResults.E_POINTER;
        var value = AbiError.Take();
        *message = value is null ? 0 : Marshal.StringToCoTaskMemUni(value);
        return HResults.S_OK;
    }
}
