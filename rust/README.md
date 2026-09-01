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

## Prerequisites

- Windows 10 or later
- .NET SDK 10
- A current stable Rust toolchain

## Build and test

From the repository root:

```powershell
.\rust\build.ps1
```

The script publishes the Win32 NativeAOT host, points
`AVN_HOST_NATIVE_LIB` at it, and runs the complete Rust workspace tests.
Use `-Architecture arm64` for Windows ARM64.

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
and asynchronous work are owned by Rust.

## Regenerate bindings

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
```

Public control coverage is declared in
`src\Avalonia.Projection.Ir\AvaloniaProjectionProfiles.cs`. Unsupported
members remain visible in `projection.ir.gaps.txt`. New samples must widen
that shared policy and the generators when blocked; sample-specific host
bindings are not accepted.

`Avalonia.Host` is currently non-packable. If it becomes a shipped NuGet
package, its native library and bundled dependencies must be added to the
repository's CycloneDX SBOM generation.
