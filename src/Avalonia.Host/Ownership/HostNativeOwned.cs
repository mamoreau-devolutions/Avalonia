using System;
using MicroCom.Runtime;

namespace Avalonia.Host.Ownership;

internal abstract class HostNativeOwned :
    IUnknown,
    IMicroComShadowContainer,
    IMicroComExceptionCallback
{
    private MicroComShadow? _shadow;
    private bool _destroyed;
    private readonly Action<Action> _scheduleCleanup;

    protected HostNativeOwned(Action<Action>? scheduleCleanup = null)
    {
        _scheduleCleanup = scheduleCleanup ?? (static cleanup => cleanup());
    }

    MicroComShadow? IMicroComShadowContainer.Shadow
    {
        get => _shadow;
        set => _shadow = value;
    }

    void IMicroComShadowContainer.OnReferencedFromNative()
    {
    }

    void IMicroComShadowContainer.OnUnreferencedFromNative()
    {
        if (_destroyed)
            return;
        _destroyed = true;
        _shadow?.Dispose();
        _shadow = null;
        ProjectionDiagnostics.NativeOwnershipReleased();
        _scheduleCleanup(Destroyed);
    }

    protected abstract void Destroyed();

    void IDisposable.Dispose()
    {
    }

    void IMicroComExceptionCallback.RaiseException(Exception e) =>
        _ = AbiError.Capture(e);
}
