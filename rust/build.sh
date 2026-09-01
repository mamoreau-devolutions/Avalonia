#!/usr/bin/env bash
set -euo pipefail

architecture="${1:-x64}"
case "$architecture" in
    x64|arm64) ;;
    *)
        echo "Usage: $0 [x64|arm64]" >&2
        exit 2
        ;;
esac

script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
repository_root="$(cd -- "$script_dir/.." && pwd)"
rid="linux-$architecture"
dotnet="${DOTNET:-dotnet}"
dotnet_artifacts="${AVN_DOTNET_ARTIFACTS:-$script_dir/target/dotnet-$rid}"
cargo_target="${CARGO_TARGET_DIR:-$script_dir/target/cargo-$rid}"
host="$dotnet_artifacts/publish/Avalonia.Host/release_$rid/Avalonia.Host.so"

if [[ ! -f "$repository_root/external/Avalonia.DBus/src/Avalonia.DBus/Avalonia.DBus.csproj" ]]; then
    echo "Initialize Linux sources with: git submodule update --init external/Avalonia.DBus" >&2
    exit 1
fi

"$dotnet" publish "$repository_root/src/Avalonia.Host/Avalonia.Host.csproj" \
    -c Release \
    -r "$rid" \
    -p:AvaloniaRustHostPlatform=X11 \
    --artifacts-path "$dotnet_artifacts"

if [[ ! -f "$host" ]]; then
    echo "NativeAOT host was not produced at $host" >&2
    exit 1
fi

export AVN_HOST_NATIVE_LIB="$host"
export CARGO_TARGET_DIR="$cargo_target"
cargo test --manifest-path "$script_dir/Cargo.toml" --workspace
echo "Linux NativeAOT host: $host"
