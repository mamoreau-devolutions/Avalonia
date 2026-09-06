# rustolonia

First-class Rust bindings for Avalonia, projected over a nano-COM ABI served by a
NativeAOT host. This directory isolates the Rust-bindings effort from the rest of
the Avalonia repository; it is laid out to eventually become the root of its own
repository.

## Layout

| Directory | Contents |
|---|---|
| `rust/` | The Rust workspace: `avalonia` (safe bindings), `avalonia-sys` (ABI bindings), `avalonia-bindgen` (IR → Rust generator), templates, build scripts, and the checked-in IR (`projection.ir.json`, `view-model.ir.json`) |
| `host/` | `Avalonia.Host` — the C# NativeAOT host that serves the ABI, plus its generated object model |
| `projection/` | The projection pipeline: `Avalonia.Projection.Ir` (IR + extractor), `Avalonia.Projection.Generator` (C#/header emitters), `Avalonia.Projection.Tool` and `Avalonia.ViewModelProjection.Tool` (IR generators) |
| `interop/` | `Avalonia.Rust` and `Avalonia.Rust.Interop` — the managed-side view-model interop layer |
| `tests/` | `Avalonia.Host.Tests`, `Avalonia.Projection.Ir.Tests`, `Avalonia.Projection.Generator.Tests` |
| `samples/` | `RustViewModelSample.Managed` — the sample presentation project the host consumes |

While this tree still builds against the in-repo Avalonia source, `Directory.Build.props`
here re-establishes the repository's shared build imports (versioning, signing,
analyzers). `rust/regenerate-and-build.ps1` and friends locate the Avalonia
repository root from their own position.

## CI note

GitHub executes workflows only from the repository root `.github/workflows/`.
The live workflow is `.github/workflows/avalonia-rust.yml` (repo root); the copy
under `rustolonia/.github/workflows/` is the seed for this tree's future
standalone repository and does not run from here.

## Still living outside this directory

The TableView control family changes and their unit tests remain under
`src/Avalonia.Controls` / `tests/Avalonia.Controls.UnitTests` because they
patch shared Avalonia controls; extracting them is a follow-up once the
Avalonia-side review lands. See `rustolonia-isolation-remaining.md` in the
session artifacts for the full decision list (framework ProjectReferences,
`build/` MSBuild infrastructure, native platform builds, root config).
