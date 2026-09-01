using System;
using System.Threading;
using Avalonia.Host.Ownership;
using Xunit;

namespace Avalonia.Host.Tests;

public unsafe class MicroComOwnershipTests
{
    [Fact]
    public void Final_release_notifies_managed_owner_and_removes_subscription_without_gc()
    {
        var probe = new MicroComOwnershipProbe();
        var pointer = probe.GetNativePointer();
        var before = ProjectionDiagnostics.Capture();

        Assert.NotEqual(0, pointer);
        Assert.Equal(42, GetValue(pointer));
        Assert.Equal(0u, Release(pointer));

        var after = ProjectionDiagnostics.Capture();
        Assert.Equal(
            before.NativeOwnershipReleases + 1,
            after.NativeOwnershipReleases);
        Assert.Equal(before.ActiveSubscriptions - 1, after.ActiveSubscriptions);
    }

    [Fact]
    public void Worker_release_invalidates_immediately_and_schedules_managed_cleanup()
    {
        Action? scheduledCleanup = null;
        var probe = new MicroComOwnershipProbe(cleanup => scheduledCleanup = cleanup);
        var pointer = probe.GetNativePointer();
        var before = ProjectionDiagnostics.Capture();
        uint remaining = uint.MaxValue;

        var thread = new Thread(() => remaining = Release(pointer));
        thread.Start();
        thread.Join();

        Assert.Equal(0u, remaining);
        var released = ProjectionDiagnostics.Capture();
        Assert.Equal(
            before.NativeOwnershipReleases + 1,
            released.NativeOwnershipReleases);
        Assert.Equal(before.ActiveSubscriptions, released.ActiveSubscriptions);
        Assert.NotNull(scheduledCleanup);

        scheduledCleanup();
        Assert.Equal(
            before.ActiveSubscriptions - 1,
            ProjectionDiagnostics.Capture().ActiveSubscriptions);
    }

    private static int GetValue(nint pointer)
    {
        var vtable = *(nint**)pointer;
        var getValue = (delegate* unmanaged[Stdcall]<nint, int*, int>)vtable[3];
        var value = 0;
        Assert.Equal(0, getValue(pointer, &value));
        return value;
    }

    private static uint Release(nint pointer)
    {
        var vtable = *(nint**)pointer;
        var release = (delegate* unmanaged[Stdcall]<nint, uint>)vtable[2];
        return release(pointer);
    }
}
