# Platform hosts

The Rust ABI and generated view-model pipeline are platform-neutral. The
NativeAOT host selects one Avalonia windowing backend at publish time:

| Host platform | Runtime identifiers | Backend | Build entry point |
| --- | --- | --- | --- |
| Windows | `win-x64`, `win-arm64` | Win32 | `build.ps1` |
| Linux | `linux-x64`, `linux-arm64` | X11 | `build.sh` |

`AvaloniaRustHostPlatform` controls the compile-time selection. The shared
host contains the nano-COM ABI, ownership runtime, generated control
projection, and generated view registry. `RustHostPlatform` contains only
backend setup and the Win32 OLE thread scope.

Linux publishes the host with a `$ORIGIN` runpath. Consequently
`libSkiaSharp.so` and `libHarfBuzzSharp.so` are resolved beside
`Avalonia.Host.so` without requiring a process-wide `LD_LIBRARY_PATH`.

## Linux build

Initialize the DBus source submodule once:

```bash
git submodule update --init external/Avalonia.DBus
```

Then publish the X11 NativeAOT host and run the complete Rust workspace:

```bash
./rust/build.sh
```

Pass `arm64` for Linux ARM64. `DOTNET` can select a non-default SDK binary.
WSL users can keep expensive intermediate files on the Linux filesystem:

```bash
DOTNET="$HOME/.dotnet/dotnet" \
AVN_DOTNET_ARTIFACTS="$HOME/.cache/avalonia-rust/dotnet-linux-x64" \
CARGO_TARGET_DIR="$HOME/.cache/avalonia-rust/cargo-linux-x64" \
./rust/build.sh
```

The X11 host requires the standard Avalonia Linux runtime libraries, including
X11, fontconfig, and OpenGL/EGL or software-rendering dependencies.

## Cross-platform gate result

The generated `rust_vm_axaml` application was published and launched through
the Linux X11 NativeAOT host under WSLg. The same generated Rust model and
managed AXAML presentation handled:

- two-way model text editing
- synchronous command dispatch
- observable collection insertion
- Rust worker-thread status publication
- normal window shutdown

No platform-specific ABI or generated model code was added. The tested
`linux-x64` host is 21.8 MB, plus 11.2 MB for Skia and 2.8 MB for HarfBuzz.
The corresponding `win-x64` host is approximately 20 MB before its two native
rendering dependencies.

The sample interaction performs six calls for initial attachment/state and
twelve calls for the edit, increment, add, and async-save flow. Platform
selection does not add boundary calls. Its application schema is 72 lines and
generates 216 lines of Rust model API, managed adapter, and host registry.

**Decision:** Rust-owned view models with managed compiled AXAML remain the
recommended full-application architecture. The platform gate no longer blocks
model work. Code-first control projection should still expand only when either
application mode demonstrates a concrete missing capability.
