# Avalonia Rust external consumer

This is a real external consumer. Keep a pinned producer checkout or submodule
at `producer/` (or let `new-app` write its path), then run:

```powershell
.\producer\rust\build-app.ps1 -ProducerRoot .\producer -Manifest .\avalonia-app.json
```

`build-app` regenerates the managed adapters, NativeAOT registry, and Rust
view-model API from `view-model.ir.json`, compiles this AXAML project and Rust
binary, and writes the adjacent runnable bundle declared by the manifest.

Generated external bindings use a crate-root compatibility bridge. Keep the
`view_model` exports in `src/main.rs`, including `DynamicViewModel`,
`ViewModelSink`, `ViewModelBatch`, and `BatchCompletion`.
