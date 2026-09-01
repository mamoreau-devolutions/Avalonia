# Rust view models with managed AXAML

`rust_vm_axaml` validates the application architecture suggested by Avalonia
maintainers:

- Rust owns application state, collection mutations, commands, and background
  work.
- Managed AXAML owns the presentation tree, Fluent templates, compiled
  bindings, and accessibility.
- A generated COM-shaped model/sink contract carries state transitions without
  exposing controls to the Rust model.

The generated `SampleViewModelAdapter` implements presentation-facing property
notification and commands. It forwards edits and commands over the stable,
ID-based `IAvnRustViewModel` transport implemented by Rust. Rust publishes
resulting state through `IAvnRustVmSink`; sink calls from Rust workers are
dispatched to Avalonia's UI thread.

## Generated application contract

`view-model.ir.json` is the source of truth for model, property, collection,
command, and view IDs. The generator produces:

- typed Rust model traits, sinks, dispatch, and `AppScope::mount_*` methods
- managed compiled-binding adapters in the presentation project
- an AOT-rooted host view registry
- [a readable contract report](view-model.contract.md)

The handwritten Rust and managed interop layers know only the generic
transport. Adding an application model or view does not add methods to that
transport or require handwritten host dispatch.

The current transport supports string, integer, Boolean, and double scalar
properties, plus observable string collections. Command parameters reference
writable string properties. IDs are explicit positive integers and remain
stable when schema entries are reordered.

## Project boundaries

`Avalonia.Rust.Interop` contains only the neutral generated-COM interfaces.
`RustViewModelSample.Managed` owns AXAML, its generated adapter, and view
code-behind. `Avalonia.Host` references presentation assemblies and consumes
only the generated registry. A product host can replace the sample
presentation project with its own generated view assemblies.

The adapter detaches the Rust sink when its window closes. Updates already in
flight are dispatched to the UI thread only while the adapter remains alive;
late updates after detach are ignored. `AppScope` keeps the Rust model and
mounted top-level alive until deterministic application-scope cleanup.

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
