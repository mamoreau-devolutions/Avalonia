# Rust view models with managed AXAML

`rust_vm_axaml` validates the application architecture suggested by Avalonia
maintainers:

- Rust owns application state, collection mutations, commands, and background
  work.
- Managed AXAML owns the presentation tree, Fluent templates, compiled
  bindings, and accessibility.
- A generated COM-shaped model/sink contract carries state transitions without
  exposing controls to the Rust model.

The managed `RustVmAdapter` implements presentation-facing property
notification and commands. It forwards edits and commands to
`IAvnRustViewModel`, which is implemented by Rust. Rust publishes resulting
state through `IAvnRustVmSink`; sink calls from Rust workers are dispatched to
Avalonia's UI thread.

The NativeAOT sample proves:

- initial Rust state flowing into compiled AXAML
- a two-way text edit flowing into Rust and back
- a synchronous Rust command updating a bound count
- a Rust-owned collection mutation updating a bound ListBox
- Rust background work publishing asynchronous status
- deterministic model/sink detachment when the window closes

This is the recommended full-application direction. The generated code-first
builder remains useful for small tools, tests, and applications that do not
want AXAML. Future projection growth should be justified by one of these two
application modes rather than raw API-coverage goals.
