# Asynchronous interop

The async ABI is executor-neutral. Avalonia starts an operation and retains a
Rust COM completion object. Completion crosses the ABI once with:

- operation ID
- HRESULT
- tagged primitive value
- copied UTF-16 string value
- copied error text

`AsyncOperation<T>` implements `std::future::Future`; it does not depend on
Tokio or another runtime. Completion stores the result under a mutex, removes
the registered waker, and calls `wake`. The caller's executor decides where
the continuation is polled.

Dropping a pending future calls `CancelAsyncOperation`. Managed operations own
a `CancellationTokenSource`, complete with `E_ABORT`, and remove their registry
entry exactly once. A native completion failure is captured but never causes a
second completion attempt.

`AppScope::spawn` is a small optional executor for UI work. It schedules polls
through `IAvnDispatcher`, owns tasks for the scope lifetime, and drops pending
futures during scope cleanup. External executors can poll `AsyncOperation<T>`
directly instead.

Clipboard text read/write is the first real consumer. On Windows the host
initializes OLE around the Avalonia application lifetime because a Rust
executable has no managed `[STAThread]` entry point.
