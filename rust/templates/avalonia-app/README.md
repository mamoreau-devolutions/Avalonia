# Avalonia Rust application template

Copy this directory outside the Avalonia repository (or anywhere in your own
project) to bootstrap a new Rust application on top of Avalonia's NativeAOT
host. `rust/new-app.ps1` / `rust/new-app.sh` do the copy and rename for you:

```powershell
.\rust\new-app.ps1 -Name my_app -Destination C:\src\my_app
```

```bash
./rust/new-app.sh my_app ~/src/my_app
```

Both scripts print a reminder to update the `avalonia` path dependency
below, since the template's own `../../avalonia` path only resolves while it
still lives inside this repository.

## What you get

- `Cargo.toml` with a path dependency on the `avalonia` crate. The crate is
  source-only and not published to crates.io (`publish = false`), so after
  copying you must point the dependency at either a checked-out Avalonia
  repository, a `git` dependency pinned to a compatible commit, or a vendored
  copy of `rust/avalonia` and `rust/avalonia-sys`. See
  [`../../PRODUCTIZATION.md`](../../PRODUCTIZATION.md#source-only-crate-packaging)
  for the packaging rationale.
- `src/main.rs` with a minimal window built from the generated control API.

## Building, packaging, and running

Build the app like any other Cargo binary crate:

```bash
cargo build --release
```

Then place a matching `Avalonia.Host` (and its `libSkiaSharp`/
`libHarfBuzzSharp` native dependencies) next to the compiled binary --
`rust/package.ps1` and `rust/package.sh` produce exactly that deterministic,
per-runtime-identifier layout for the samples in this repository, and work
unchanged against a copy of this template. See
[`../../PRODUCTIZATION.md`](../../PRODUCTIZATION.md) for the full workflow,
including checksums and the optional signing hook.

At run time the app finds the host automatically next to its own executable
(`avalonia::discover_host_path`); set `AVN_HOST_NATIVE_LIB` to point at a
different host during development, for example while iterating without
republishing after every change.
