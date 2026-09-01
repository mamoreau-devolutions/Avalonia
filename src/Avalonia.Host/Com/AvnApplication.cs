using System;
using Avalonia;
using Avalonia.Controls;
using Avalonia.Controls.ApplicationLifetimes;
using System.Runtime.InteropServices.Marshalling;

namespace Avalonia.Host.Com;

[GeneratedComClass]
public partial class AvnApplication : IAvnApplication
{
    private ClassicDesktopStyleApplicationLifetime? _lifetime;

    public int Run(IAvnAppHandler? handler)
    {
        if (handler is null)
            return HResults.E_POINTER;

        try
        {
            var lifetime = new ClassicDesktopStyleApplicationLifetime
            {
                ShutdownMode = ShutdownMode.OnExplicitShutdown,
            };
            _lifetime = lifetime;

            AppBuilder.Configure<HostApplication>()
                .UseWin32()
                .UseSkia()
                .UseHarfBuzz()
                .SetupWithLifetime(lifetime);

            var started = handler.OnStarted();
            if (started < 0)
                return started;

            lifetime.Start(Array.Empty<string>());
            return HResults.S_OK;
        }
        catch
        {
            return HResults.E_FAIL;
        }
    }

    public int Shutdown()
    {
        try
        {
            _lifetime?.Shutdown();
            return HResults.S_OK;
        }
        catch
        {
            return HResults.E_FAIL;
        }
    }
}
