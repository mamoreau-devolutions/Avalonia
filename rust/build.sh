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
case "$(uname -s)" in
    Linux)
        platform="X11"
        rid="linux-$architecture"
        case "$(uname -m)" in
            x86_64) native_architecture="x64" ;;
            arm64|aarch64) native_architecture="arm64" ;;
            *) echo "Unsupported Linux CPU architecture: $(uname -m)" >&2; exit 1 ;;
        esac
        if [[ "$architecture" != "$native_architecture" ]]; then
            echo "$rid requires a Linux runner with a matching $architecture CPU because cargo tests execute native binaries." >&2
            exit 1
        fi
        ;;
    Darwin)
        platform="OSX"
        rid="osx-$architecture"
        case "$(uname -m)" in
            x86_64)
                native_architecture="x64"
                xcode_architecture="x86_64"
                ;;
            arm64)
                native_architecture="arm64"
                xcode_architecture="arm64"
                ;;
            *)
                echo "Unsupported macOS CPU architecture: $(uname -m)" >&2
                exit 1
                ;;
        esac
        if [[ "$architecture" != "$native_architecture" ]]; then
            echo "$rid requires a macOS runner with a matching $architecture CPU." >&2
            exit 1
        fi
        ;;
    *)
        echo "rust/build.sh supports Linux and macOS only." >&2
        exit 1
        ;;
esac
dotnet="${DOTNET:-dotnet}"
dotnet_artifacts="${AVN_DOTNET_ARTIFACTS:-$script_dir/target/dotnet-$rid}"
cargo_target="${CARGO_TARGET_DIR:-$script_dir/target/cargo-$rid}"
host_extension="so"
[[ "$platform" == "OSX" ]] && host_extension="dylib"
host="$dotnet_artifacts/publish/Avalonia.Host/release_$rid/Avalonia.Host.$host_extension"

if [[ "$platform" == "X11" && ! -f "$repository_root/external/Avalonia.DBus/src/Avalonia.DBus/Avalonia.DBus.csproj" ]]; then
    echo "Initialize Linux sources with: git submodule update --init external/Avalonia.DBus" >&2
    exit 1
fi

if [[ "$platform" == "OSX" ]]; then
    xcodebuild \
        -project "$repository_root/native/Avalonia.Native/src/OSX/Avalonia.Native.OSX.xcodeproj/" \
        -configuration Release \
        ARCHS="$xcode_architecture" \
        "CONFIGURATION_BUILD_DIR=$repository_root/Build/Products/Release"
fi

"$dotnet" publish "$repository_root/src/Avalonia.Host/Avalonia.Host.csproj" \
    -c Release \
    -r "$rid" \
    -p:AvaloniaRustHostPlatform="$platform" \
    --artifacts-path "$dotnet_artifacts"

if [[ ! -f "$host" ]]; then
    echo "NativeAOT host was not produced at $host" >&2
    exit 1
fi

export AVN_HOST_NATIVE_LIB="$host"
export CARGO_TARGET_DIR="$cargo_target"
cargo test --manifest-path "$script_dir/Cargo.toml" --workspace
echo "$rid NativeAOT host: $host"
