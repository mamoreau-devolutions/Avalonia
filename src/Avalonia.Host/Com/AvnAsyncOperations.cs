using System;
using System.Collections.Concurrent;
using System.Runtime.InteropServices;
using System.Threading;
using System.Threading.Tasks;

namespace Avalonia.Host.Com;

internal sealed class AvnAsyncOperations
{
    private readonly ConcurrentDictionary<long, CancellationTokenSource> _operations = new();
    private long _nextOperationId;

    public int Start(
        IAvnAsyncCompletion? completion,
        Func<CancellationToken, Task<AvnAsyncValue>> operation,
        out long operationId)
    {
        operationId = 0;
        if (completion is null)
            return HResults.E_POINTER;

        var id = Interlocked.Increment(ref _nextOperationId);
        var cancellation = new CancellationTokenSource();
        if (!_operations.TryAdd(id, cancellation))
            return HResults.E_FAIL;

        operationId = id;
        _ = Run(id, cancellation, completion, operation);
        return HResults.S_OK;
    }

    public int Cancel(long operationId)
    {
        if (!_operations.TryGetValue(operationId, out var cancellation))
            return HResults.E_INVALIDARG;
        cancellation.Cancel();
        return HResults.S_OK;
    }

    public void CancelAll()
    {
        foreach (var cancellation in _operations.Values)
            cancellation.Cancel();
    }

    private async Task Run(
        long operationId,
        CancellationTokenSource cancellation,
        IAvnAsyncCompletion completion,
        Func<CancellationToken, Task<AvnAsyncValue>> operation)
    {
        int hresult;
        AvnAsyncValue value;
        string? error;
        try
        {
            value = await operation(cancellation.Token);
            cancellation.Token.ThrowIfCancellationRequested();
            hresult = HResults.S_OK;
            error = null;
        }
        catch (OperationCanceledException)
        {
            hresult = HResults.E_ABORT;
            value = AvnAsyncValue.None;
            error = "The asynchronous operation was canceled.";
        }
        catch (Exception e)
        {
            hresult = Marshal.GetHRForException(e);
            value = AvnAsyncValue.None;
            error = e.ToString();
        }
        finally
        {
            _operations.TryRemove(operationId, out _);
            cancellation.Dispose();
        }

        try
        {
            Complete(completion, operationId, hresult, value, error);
        }
        catch (Exception e)
        {
            _ = AbiError.Capture(e);
        }
    }

    private static void Complete(
        IAvnAsyncCompletion completion,
        long operationId,
        int hresult,
        AvnAsyncValue value,
        string? error)
    {
        var completionResult = completion.Complete(
            operationId,
            hresult,
            value.Kind,
            value.Integer,
            value.Double,
            value.String,
            error);
        if (completionResult < 0)
            Marshal.ThrowExceptionForHR(completionResult);
    }
}

internal readonly record struct AvnAsyncValue(
    int Kind,
    long Integer,
    double Double,
    string? String)
{
    public static AvnAsyncValue None => default;

    public static AvnAsyncValue FromString(string? value) =>
        new(4, 0, 0, value);
}
