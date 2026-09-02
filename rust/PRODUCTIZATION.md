# Productizing the Rust application workflow

This documents the reusable, scripted path from "empty directory" to a
packaged Rust Avalonia application: the copyable project template, the
one-command regeneration/build loop, native host discovery, the deterministic
per-runtime-identifier (RID) artifact layout with checksums and an optional
signing hook, source-only crate packaging readiness, and the EU CRA CycloneDX
SBOM scope decision for everything this workflow ships.

Nothing here changes the generated ABI, the ownership contract, or the
view-model transport; see [README.md](README.md), [OWNERSHIP.md](OWNERSHIP.md),
[ASYNC.md](ASYNC.md), [VIEW_MODELS.md](VIEW_MODELS.md), and
[PLATFORMS.md](PLATFORMS.md) for those. Release compatibility, RID artifact
integrity, signing, and future SBOM requirements are defined in
[COMPATIBILITY.md](COMPATIBILITY.md).

## Application template

[`templates/avalonia-app`](templates/avalonia-app) is a minimal, copyable
Cargo project (a `Cargo.toml` with a path dependency on `avalonia`, plus a
`src/main.rs` that opens a window) meant to be copied outside this repository
to bootstrap a new application. `new-app.ps1` / `new-app.sh` do the copy and
package rename:

```powershell
.\rust\new-app.ps1 -Name my_app -Destination C:\src\my_app
```

```bash
./rust/new-app.sh my_app ~/src/my_app
```

The template is excluded from the `rust` Cargo workspace (see the `exclude`
entry in `Cargo.toml`) so it always resolves and builds as a standalone
crate, exactly as it will once copied elsewhere. `regenerate-and-build.ps1
-ValidateTemplate` / `AVN_VALIDATE_TEMPLATE=1 regenerate-and-build.sh`
`cargo check` it in place as a compile-only smoke test, and it is covered by
the packaging-readiness check below.

## One-command developer workflow

`regenerate-and-build.ps1` / `regenerate-and-build.sh` replace the four
previously separate, manually copy-pasted commands from README.md's
"Regenerate bindings" section with one:

1. Regenerate the object-model projection IR, generated C# COM sources, and
   the native ABI header from the current `AvaloniaObject`/`Control`
   assemblies (`Avalonia.Projection.Tool`).
2. Regenerate the Rust `avalonia-sys`/`avalonia` bindings from that IR
   (`avalonia-bindgen`), then `cargo fmt --all`.
3. Regenerate the managed adapters, host view registry, Rust view-model
   model/sink, and `view-model.contract.md` from the checked-in canonical
   `view-model.ir.json` (`Avalonia.ViewModelProjection.Tool`).
4. Build the managed AXAML (`dotnet build` on `Avalonia.Host`, which
   references `RustViewModelSample.Managed`) and build the Rust workspace
   (`cargo build --workspace`).

```powershell
.\rust\regenerate-and-build.ps1
```

```bash
./rust/regenerate-and-build.sh
```

Both scripts are idempotent when the IR hasn't changed (running them against
an unmodified `projection.ir.json`/`view-model.ir.json` reproduces byte-identical
generated output) and fail fast: each step's exit code stops the script before
the next one runs.

Useful switches/environment variables:

| PowerShell | Bash (env var) | Effect |
| --- | --- | --- |
| `-Configuration Debug` | `./regenerate-and-build.sh Debug` | Build configuration for the .NET regeneration tools and managed build (default `Release`). |
| `-SkipManagedBuild` | `AVN_SKIP_MANAGED_BUILD=1` | Skip step 4's `dotnet build`, e.g. when only the Rust side changed. |
| `-Test` | `AVN_RUN_CARGO_TESTS=1` | Run `cargo test --workspace` instead of `cargo build --workspace`. Requires a host discoverable per [Host discovery](#host-discovery) below (`rust/build.ps1`/`rust/build.sh` publish one; set `AVN_HOST_NATIVE_LIB` otherwise). |
| `-ValidateTemplate` | `AVN_VALIDATE_TEMPLATE=1` | Additionally `cargo check` the application template in place. |
| `-PackageRid <rid>` | `AVN_PACKAGE_RID=<rid>` | Additionally run [`package.ps1`/`package.sh`](#deterministic-per-rid-artifact-layout) for that RID. |

This script intentionally does not replace `rust/build.ps1` / `rust/build.sh`
(full RID publish plus `cargo test --workspace` against the exact published
host) or `package.ps1` / `package.sh` (below): it is the fast inner
regenerate/compile loop, and delegates to those for anything that needs a
real NativeAOT publish.

## Host discovery

`avalonia::App::load_from_env()` (used by every example and the template)
resolves the native `Avalonia.Host` library through `avalonia::discover_host_path()`:

1. **`AVN_HOST_NATIVE_LIB`** (the `avalonia::HOST_NATIVE_LIB_ENV_VAR` constant) -- an explicit
   override. If set, its value is used as-is, even if nothing exists at that
   path yet, so `Host::load` can surface a precise loader error instead of
   this function silently falling back to the next mechanism. This remains
   how `rust/build.ps1`/`rust/build.sh` point the workspace test suite at a
   freshly published host, and how you point a running app at a different
   host during development.
2. **Adjacent to the executable** -- otherwise, the platform host file name
   (`Avalonia.Host.dll` on Windows, `Avalonia.Host.so` on Linux,
   `Avalonia.Host.dylib` on macOS) is looked up next to
   `std::env::current_exe()`. This is what lets a packaged application run
   with no environment variable at all: [`package.ps1`/`package.sh`](#deterministic-per-rid-artifact-layout)
   copy the host and the application binary into the same directory.

If neither resolves, the error names both the environment variable and the
host file name it looked for next to the executable's directory. See
`rust/avalonia/src/runtime.rs` (`discover_host_path`, `HOST_NATIVE_LIB_ENV_VAR`)
for the implementation, `rust/avalonia/src/runtime.rs`'s
`host_discovery_tests` module for unit tests of the override/adjacent-lookup
precedence and error message, and `rust/avalonia/tests/host_discovery.rs` for
the same behavior exercised through the crate's public API.

## Deterministic per-RID artifact layout

`package.ps1` (Windows) / `package.sh` (Linux and macOS) publish the NativeAOT host for
one RID, build a Rust binary next to it, and lay both out identically
regardless of platform, under `rust/artifacts/<rid>/`:

```powershell
.\rust\package.ps1 -Rid win-x64
```

```bash
./rust/package.sh linux-x64
```

```bash
./rust/package.sh osx-arm64
```

Both produce, for every supported RID:

- `Avalonia.Host.<dll|so|dylib>` -- the published NativeAOT host.
- Its native rendering dependencies that publish alongside it
  (`libSkiaSharp`/`libHarfBuzzSharp`, plus `libAvaloniaNative.dylib` on
  macOS), copied only if present. `package.sh` copies every published `.so`,
  versioned `.so.*`, and `.dylib` dependency rather than maintaining a
  platform-specific allow-list.
- The requested Rust binary (`hello_world` by default; pass `-Example`/an
  extra argument to package a different example, or point `-OutputRoot`
  /`AVN_PACKAGE_OUTPUT` and build the copied application template the same
  way), placed **next to** the host so [host discovery](#host-discovery)
  finds it with no environment variable.
- `checksums.sha256` -- a `sha256sum -c`-compatible SHA-256 manifest of every
  other file in the directory, generated last so it never hashes itself.
- `licence.md` -- the repository licence copied into every delivery bundle.
- `sbom.cdx.json` -- a deterministic CycloneDX 1.5 delivery inventory,
  generated after optional signing and before checksums. It records SHA-256
  hashes for the host, Rust executable, bundled native libraries, and licence;
  it intentionally excludes itself and the checksum manifest to avoid a
  recursive hash.

The layout is deterministic: the same RID with the same configuration and
example always produces the same file set at the same relative paths, which
is what makes the adjacent-host discovery above reliable and what a release
pipeline can zip and publish unchanged.

Each supported RID has an explicit native Cargo target; package scripts reject
an absent target with the corresponding `rustup target add` command:

| RID | Cargo target |
| --- | --- |
| `win-x64` | `x86_64-pc-windows-msvc` |
| `win-arm64` | `aarch64-pc-windows-msvc` |
| `linux-x64` | `x86_64-unknown-linux-gnu` |
| `linux-arm64` | `aarch64-unknown-linux-gnu` |
| `osx-x64` | `x86_64-apple-darwin` |
| `osx-arm64` | `aarch64-apple-darwin` |

Linux and macOS packaging require a matching native CPU because their release
gate starts the packaged binary; this avoids treating a successfully
cross-compiled but unexecutable binary as a tested release artifact.

### Signing hook

Neither script downloads or bundles a signing tool -- that would be exactly
the kind of unverified-binary shortcut this workflow avoids. Instead, before
the SBOM and checksums are computed, both scripts check for
`AVALONIA_RUST_SIGN_COMMAND`. If set, it must be the path to a trusted local
wrapper executable (or executable script); the script invokes it once per
binary artifact with that artifact's path as a separate argument. The wrapper
owns all signer options and identity selection. No shell evaluation or command
template expansion is performed. If unset, signing is skipped with a message
explaining how to opt in; either way, the SBOM and checksums describe final
(optionally signed) bytes.

## Source-only crate packaging

`avalonia`, `avalonia-sys`, and `avalonia-bindgen` all set `publish = false`:
they are pinned to a matching `Avalonia.Host` build from the same checkout,
not to a versioned ABI contract suitable for crates.io. That is a deliberate
choice, not a gap -- but the crates are kept in a state where `cargo package`
would succeed if that ever changed: each has `description`, `license`,
`repository`, and (for the two application-facing crates) a `readme`
pointing at a real `README.md`. This is checked with:

```bash
cargo package --list -p avalonia-sys --allow-dirty
cargo package --list -p avalonia --allow-dirty
cargo package --list -p avalonia-bindgen --allow-dirty
```

## SBOM (EU CRA) scope

The repository's CycloneDX SBOM generation (`nukebuild/SbomGenerator.cs`,
`CreateSbom` target) walks published NuGet packages: for each one it resolves
the packed assemblies' NuGet dependency graph and, where a package bundles a
built webapp (Numerge-merged assemblies, npm-built browser bundles), that
bundled content too. It does not scan arbitrary files on disk, so it does not
need to be told about something that is never packed into a shipped NuGet
package.

Everything this stage adds stays outside a shipped NuGet package, by design,
and the checks below are what keep that true instead of assumed:

- **`Avalonia.Host`, `Avalonia.Rust`, `Avalonia.Rust.Interop`,
  `Avalonia.Projection.*`, `Avalonia.ViewModelProjection.Tool`** remain
  `IsPackable=false` (unchanged by this stage). None are referenced by
  `nukebuild/numerge.json`. A project only needs SBOM coverage once it is
  packed into a published `.nupkg`; do not flip `IsPackable` to `true` for
  any of these without also giving `nukebuild/SbomGenerator.cs` a way to
  attribute their dependencies (native libraries, bundled assemblies) to the
  resulting package first.
- **The `rust/*` crates** are source only (`publish = false`, see above) and
  are never vendored as compiled binaries into any NuGet package; they are
  consumed by `cargo`, entirely outside the NuGet/CycloneDX pipeline.
- **The `rust/package.ps1` / `rust/package.sh` output** (`Avalonia.Host` plus
  its native dependencies and a Rust binary, per RID) is not a NuGet package
  and is not produced by this repository's NuGet publish path -- it is a
  standalone build artifact distributed by whatever channel a consumer of
  this workflow chooses (for example a GitHub release). Its delivery scope is
  covered by `sbom.cdx.json`, which inventories exact per-RID files after
  signing, and by `checksums.sha256`, which covers that SBOM too. This does
  not change the NuGet SBOM generator because no new packable NuGet project
  or package delivery dependency is introduced.

## Tests

- `rust/avalonia/src/runtime.rs` (`host_discovery_tests` module) and
  `rust/avalonia/tests/host_discovery.rs` cover `discover_host_path`: the
  explicit override always winning (even to a nonexistent path), the
  adjacent-file lookup succeeding and failing, and the combined error naming
  both mechanisms -- all without requiring a published host.
- `regenerate-and-build.ps1 -ValidateTemplate` / `AVN_VALIDATE_TEMPLATE=1
  ./regenerate-and-build.sh` and direct `cargo check --manifest-path
  rust/templates/avalonia-app/Cargo.toml` compile-check the application
  template as a standalone crate.
- `cargo package --list` (see [Source-only crate packaging](#source-only-crate-packaging))
  is the packaging-readiness check for all three workspace crates.
- `package.ps1` / `package.sh` self-verify their own output shape (the
  publish step fails the script if the host file is missing, the cargo build
  step fails it if the binary is missing) and were run end to end for
  `win-x64` while developing this stage, confirming the host, its native
  dependencies, the Rust binary, and a matching `checksums.sha256` land
  together in one deterministic directory.
