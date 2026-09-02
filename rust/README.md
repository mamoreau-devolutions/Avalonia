# Avalonia for Rust

This experimental workspace provides an idiomatic Rust API over an Avalonia
.NET 10 NativeAOT shared library. Both the managed nano-COM wrappers and Rust
bindings are generated from `projection.ir.json`; examples are consumers, not
binding specifications.

The native ownership contract and the MicroCom-versus-handle-table decision
are documented in [OWNERSHIP.md](OWNERSHIP.md).
The executor-neutral completion ABI and clipboard integration are documented
in [ASYNC.md](ASYNC.md).
The Rust-state/managed-presentation application model is documented in
[VIEW_MODELS.md](VIEW_MODELS.md).
Platform host selection and the Windows/Linux/macOS validation are documented in
[PLATFORMS.md](PLATFORMS.md).
The application template, one-command build, native host discovery,
packaging/checksums/signing, and SBOM scope are documented in
[PRODUCTIZATION.md](PRODUCTIZATION.md).
Release compatibility and versioning rules are documented in
[COMPATIBILITY.md](COMPATIBILITY.md).

## Prerequisites

- Windows 10 or later, Linux with X11, or macOS
- .NET SDK 10
- A current stable Rust toolchain

## Build and test

On Windows, from the repository root:

```powershell
.\rust\build.ps1
```

The script publishes the Win32 NativeAOT host, points
`AVN_HOST_NATIVE_LIB` at it, and runs the complete Rust workspace tests.
Use `-Architecture arm64` for Windows ARM64.

On Linux:

```bash
git submodule update --init external/Avalonia.DBus
./rust/build.sh
```

The Linux script publishes the X11 NativeAOT host with an origin-relative
native dependency runpath and runs the same Rust workspace tests. Pass `arm64`
for Linux ARM64, on a matching ARM64 runner; the tests execute native binaries.

On macOS, the same script builds `libAvaloniaNative.dylib` through Xcode,
publishes the Avalonia.Native-backed NativeAOT host, and runs the Rust
workspace tests:

```bash
./rust/build.sh
```

Run it on an Intel Mac for `osx-x64` or an Apple Silicon Mac for `osx-arm64`;
pass `arm64` on Apple Silicon.

To run an example:

```powershell
$env:AVN_HOST_NATIVE_LIB = (Resolve-Path `
  .\src\Avalonia.Host\bin\Release\net10.0\win-x64\publish\Avalonia.Host.dll)
cargo run --manifest-path .\rust\Cargo.toml -p avalonia --example hello_world
```

The examples progress from a basic window (`hello_world`) through a port of
`AppWithoutLifetime` and the Button, Slider, TextBox, ToggleSwitch, ComboBox,
ListBox, RadioButton, and Expander portion of `WinUIEmbedSample`
(`control_basics`), including its typed keyboard, hover, and asynchronous
clipboard interactions.
`text_test_input` ports the editable text, live preview, and new-window
interaction from the top of `TextTestApp`. `progress_bar` ports the interactive
core of ControlCatalog's `ProgressBarPage`, and `scroll_viewer` ports its basic
`ScrollViewerPage` controls and command surface.

`rust_vm_axaml` demonstrates the alternate application model: presentation is
precompiled managed AXAML while state, edits, collection mutations, commands,
and asynchronous work are owned by Rust. `rust_dynamic_vm_axaml` uses the same
Rust model through generated runtime metadata and the AOT-safe `RustBinding`
markup extension. The dynamic adapter also implements `IReflectableType` for
JIT reflection bindings; NativeAOT applications use `RustBinding` because
Avalonia's general reflection binding requires dynamic code. Both examples
also register a Rust-authored `IValueConverter` (`CountToLabel`, formatting
`Count` as text) through the same generated `ValueConverters` trait; see
[VIEW_MODELS.md](VIEW_MODELS.md#rust-value-converters) for the transport and
lifetime rules. Both examples also exercise nested view models, nullable
values, enums, ordered collection edits, command `CanExecute` state, and
validation-error projection through a second, independently versioned sink
interface (`IAvnRustVmSink2`); see
[VIEW_MODELS.md](VIEW_MODELS.md#real-application-data-model-support).

AXAML is compiled during the managed build for NativeAOT applications.
`AvaloniaRuntimeXamlLoader` uses `System.Reflection.Emit`; preserving Avalonia
metadata with trimming or runtime directives does not make runtime AXAML
available when NativeAOT disables dynamic code. A future JIT-only development
host may offer runtime AXAML without changing the release path.

## Regenerate bindings

The one-command `regenerate-and-build.ps1` / `regenerate-and-build.sh`
(see [PRODUCTIZATION.md](PRODUCTIZATION.md#one-command-developer-workflow))
run every step below plus the managed and Rust builds; the commands here
are what it runs, spelled out for anyone changing the pipeline itself:

```powershell
dotnet run --project .\src\Avalonia.Projection.Tool `
  -- .\rust\projection.ir.json `
  .\src\Avalonia.Host\Generated\ObjectModel `
  .\rust\avalonia-sys\include\avalonia-rust-abi.h

Push-Location .\rust
cargo run -p avalonia-bindgen -- `
  .\projection.ir.json `
  .\avalonia-sys\src\generated.rs `
  .\avalonia\src\generated.rs
cargo fmt --all
Pop-Location

dotnet run --project .\src\Avalonia.ViewModelProjection.Tool -- `
  .\rust\view-model.ir.json `
  .\samples\RustViewModelSample.Managed\Generated `
  .\src\Avalonia.Host\Generated\ViewModels `
  .\rust\avalonia\src\generated_view_models.rs `
  .\rust\view-model.contract.md
```

Public control coverage is declared in
`src\Avalonia.Projection.Ir\AvaloniaProjectionProfiles.cs`. Unsupported
members remain visible in `projection.ir.gaps.txt`. New samples must widen
that shared policy and the generators when blocked; sample-specific host
bindings are not accepted.

The view-model command generates typed Rust traits and sinks, managed binding
adapters, the host's view registry, Rust-authored `IValueConverter` traits and
managed converter instances, and the readable `view-model.contract.md` report
from one versioned schema. Application names are confined to generated files
and the managed presentation project; the interop transport and handwritten
Rust runtime remain model-independent. The schema now also declares
schema-wide enums and nested-model/nullable/collection-element-kind
properties (see [VIEW_MODELS.md](VIEW_MODELS.md#real-application-data-model-support));
these ride the existing versioned `IAvnRustVmSink`/`IAvnRustVmSink2`
transport rather than a per-application ABI. Stage 27 additionally introduces
the independently versioned `IAvnRustVmSink3` immutable batch capability.
Worker and high-volume publishers must use generated named batch builders:
submission is one nonblocking dispatcher post, stale/equal generations are
rejected deterministically, and completion is asynchronous. Both the generated
and reflectable adapters apply a batch through one shared staged transactional
engine, so a batch either applies whole or leaves state and notifications
untouched.

## Start a new application

Copy the [`templates/avalonia-app`](templates/avalonia-app) scaffold to
bootstrap a new Rust application against the same generated API these
examples use:

```powershell
.\rust\new-app.ps1 -Name my_app -Destination .\my_app
```

```bash
./rust/new-app.sh my_app ~/src/my_app
```

The scaffold is an external consumer with managed AXAML and view-model IR, not
an in-repository sample. Pin the producer checkout (prefer a Git submodule) to
the commit which supplies the Rust crates and host, then build it in one step:

```powershell
& .\producer\rust\build-app.ps1 -ProducerRoot .\producer `
  -Manifest .\my_app\avalonia-app.json
```

The manifest selects the managed presentation project, IR, Cargo package and
normal binary, RID, configuration, and adjacent output directory. The tool
generates consumer adapters/registry/Rust API, then formats and builds Cargo,
builds AXAML, publishes a NativeAOT host with those exact external inputs, and
creates a checksummed CycloneDX bundle. See [PRODUCTIZATION.md](PRODUCTIZATION.md).

`Avalonia.Host`, `Avalonia.Rust`, `Avalonia.Rust.Interop`, and the projection
tool/generator projects are currently non-packable, and the `rust/*` crates
are source-only (`publish = false`). None of this stage's new artifacts are
published as NuGet packages; see
[PRODUCTIZATION.md#sbom-eu-cra-scope](PRODUCTIZATION.md#sbom-eu-cra-scope)
for why that keeps them outside the repository's CycloneDX SBOM generation,
and what would need to change first if that ever changes.
