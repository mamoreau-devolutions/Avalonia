using System;
using Avalonia;
using Avalonia.Controls;
using Avalonia.Controls.ApplicationLifetimes;
using Avalonia.Styling;
using Avalonia.Threading;
using System.Runtime.InteropServices;
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
                ShutdownMode = ShutdownMode.OnLastWindowClose,
            };
            _lifetime = lifetime;

            AppBuilder.Configure<HostApplication>()
                .UseWin32()
                .UseSkia()
                .UseHarfBuzz()
                .SetupWithLifetime(lifetime);

            lifetime.Startup += (_, _) =>
            {
                var started = handler.OnStarted();
                if (started < 0)
                    Marshal.ThrowExceptionForHR(started);
            };

            lifetime.Start(Array.Empty<string>());
            return HResults.S_OK;
        }
        catch (Exception e)
        {
            return AbiError.Capture(e);
        }
    }

    public int Shutdown()
    {
        try
        {
            _lifetime?.Shutdown();
            return HResults.S_OK;
        }
        catch (Exception e)
        {
            return AbiError.Capture(e);
        }
    }

    public int GetRequestedThemeVariant(out int value)
        {
            value = 0;
            try
            {
                Dispatcher.UIThread.VerifyAccess();
                value = ToAbiTheme(Application.Current?.RequestedThemeVariant);
                return HResults.S_OK;
            }
            catch (Exception e)
            {
                return AbiError.Capture(e);
            }
        }

        public int SetRequestedThemeVariant(int value)
        {
            try
            {
                Dispatcher.UIThread.VerifyAccess();
                var application = Application.Current
                    ?? throw new InvalidOperationException("Avalonia application is not running.");
                application.RequestedThemeVariant = FromAbiTheme(value);
                return HResults.S_OK;
            }
            catch (Exception e)
            {
                return AbiError.Capture(e);
            }
        }

        public int GetActualThemeVariant(out int value)
        {
            value = 0;
            try
            {
                Dispatcher.UIThread.VerifyAccess();
                value = ToAbiTheme(Application.Current?.ActualThemeVariant);
                return HResults.S_OK;
            }
            catch (Exception e)
            {
                return AbiError.Capture(e);
            }
        }

        public int TryGetResource(
            string? key,
            int themeVariant,
            out int found,
            out IAvnResourceValue? value)
        {
            found = 0;
            value = null;
            if (key is null)
                return HResults.E_POINTER;
            try
            {
                Dispatcher.UIThread.VerifyAccess();
                var application = Application.Current
                    ?? throw new InvalidOperationException("Avalonia application is not running.");
                if (!application.TryGetResource(key, FromAbiTheme(themeVariant), out var resource))
                    return HResults.S_OK;
                value = new AvnResourceValue(resource);
                found = 1;
                return HResults.S_OK;
            }
            catch (Exception e)
            {
                return AbiError.Capture(e);
            }
        }

        private static ThemeVariant FromAbiTheme(int value) => value switch
        {
            0 => ThemeVariant.Default,
            1 => ThemeVariant.Light,
            2 => ThemeVariant.Dark,
            _ => throw new ArgumentOutOfRangeException(nameof(value)),
        };

    private static int ToAbiTheme(ThemeVariant? value)
    {
        if (value is null || value == ThemeVariant.Default)
            return 0;
        if (value == ThemeVariant.Light)
            return 1;
        if (value == ThemeVariant.Dark)
            return 2;
        throw new NotSupportedException($"Custom theme variant '{value.Key}' is not supported by the ABI.");
    }
}
