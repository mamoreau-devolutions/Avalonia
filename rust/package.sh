#!/usr/bin/env bash
set -euo pipefail

rid="${1:-}"
configuration="${2:-Release}"
example="${3:-hello_world}"

case "$rid" in
    linux-x64) rust_target="x86_64-unknown-linux-gnu" ;;
    linux-arm64) rust_target="aarch64-unknown-linux-gnu" ;;
    osx-x64) rust_target="x86_64-apple-darwin" ;;
    osx-arm64) rust_target="aarch64-apple-darwin" ;;
    *)
        echo "Usage: $0 <linux-x64|linux-arm64|osx-x64|osx-arm64> [Debug|Release] [example]" >&2
        exit 2
        ;;
esac
if ! rustup target list --installed | grep -Fxq "$rust_target"; then
    echo "Rust target '$rust_target' required for RID '$rid' is missing. Install it with: rustup target add $rust_target" >&2
    exit 1
fi

script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
repository_root="$(cd -- "$script_dir/.." && pwd)"

case "$rid" in
    linux-*)
        platform="X11"
        host_extension="so"
        expected_os="Linux"
        architecture="${rid#linux-}"
        ;;
    osx-*)
        platform="OSX"
        host_extension="dylib"
        expected_os="Darwin"
        architecture="${rid#osx-}"
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
            echo "$rid packaging requires a macOS runner with a matching $architecture CPU." >&2
            exit 1
        fi
        ;;
esac

if [[ "$(uname -s)" != "$expected_os" ]]; then
    echo "$rid packaging must run on $expected_os." >&2
    exit 1
fi

case "$(uname -m)" in
    x86_64) native_architecture="x64" ;;
    arm64|aarch64) native_architecture="arm64" ;;
    *) echo "Unsupported CPU architecture: $(uname -m)" >&2; exit 1 ;;
esac
if [[ "$architecture" != "$native_architecture" ]]; then
    echo "$rid packaging requires a runner with a matching $architecture CPU because the package smoke tests execute the Rust binary." >&2
    exit 1
fi

if [[ "$platform" == "X11" && ! -f "$repository_root/external/Avalonia.DBus/src/Avalonia.DBus/Avalonia.DBus.csproj" ]]; then
    echo "Initialize Linux sources with: git submodule update --init external/Avalonia.DBus" >&2
    exit 1
fi

output_root="${AVN_PACKAGE_OUTPUT:-$script_dir/artifacts}"
mkdir -p "$output_root"
output_root="$(cd -- "$output_root" && pwd)"
destination="$output_root/$rid"

dotnet_artifacts="${AVN_DOTNET_ARTIFACTS:-$script_dir/target/dotnet-$rid}"
if [[ "$platform" == "OSX" ]]; then
    xcodebuild \
        -project "$repository_root/native/Avalonia.Native/src/OSX/Avalonia.Native.OSX.xcodeproj/" \
        -configuration "$configuration" \
        ARCHS="$xcode_architecture" \
        "CONFIGURATION_BUILD_DIR=$repository_root/Build/Products/Release"
fi

echo "==> Publishing Avalonia.Host ($rid, $configuration)"
dotnet publish "$repository_root/src/Avalonia.Host/Avalonia.Host.csproj" \
    -c "$configuration" \
    -r "$rid" \
    -p:AvaloniaRustHostPlatform="$platform" \
    --artifacts-path "$dotnet_artifacts"

configuration_lower="$(printf '%s' "$configuration" | tr '[:upper:]' '[:lower:]')"
publish_dir="$dotnet_artifacts/publish/Avalonia.Host/${configuration_lower}_$rid"
host_file="$publish_dir/Avalonia.Host.$host_extension"
if [[ ! -f "$host_file" ]]; then
    echo "NativeAOT host was not produced at $host_file" >&2
    exit 1
fi

rm -rf "$destination"
mkdir -p "$destination"

echo "==> Copying host and native dependencies into $destination"
cp "$host_file" "$destination/"
while IFS= read -r -d '' dependency; do
    [[ "$dependency" == "$host_file" ]] || cp "$dependency" "$destination/"
done < <(find "$publish_dir" -maxdepth 1 -type f \( -name '*.so' -o -name '*.so.*' -o -name '*.dylib' \) -print0)
cp "$repository_root/licence.md" "$destination/"

if [[ "$platform" == "OSX" && ! -f "$destination/libAvaloniaNative.dylib" ]]; then
    echo "libAvaloniaNative.dylib was not published with the macOS host." >&2
    exit 1
fi

skip_cargo_build="${AVN_PACKAGE_SKIP_CARGO_BUILD:-}"
if [[ -z "$skip_cargo_build" ]]; then
    cargo_target="${CARGO_TARGET_DIR:-$script_dir/target/cargo-$rid}"
    cargo_args=(build --manifest-path "$script_dir/Cargo.toml" -p avalonia --example "$example" --target "$rust_target")
    profile_dir="debug"
    if [[ "$configuration" == "Release" ]]; then
        cargo_args+=(--release)
        profile_dir="release"
    fi
    echo "==> Building Rust example '$example' ($configuration) next to the host"
    CARGO_TARGET_DIR="$cargo_target" cargo "${cargo_args[@]}"
    exe_path="$cargo_target/$rust_target/$profile_dir/examples/$example"
    if [[ ! -f "$exe_path" ]]; then
        echo "Rust example binary was not produced at $exe_path" >&2
        exit 1
    fi
    cp "$exe_path" "$destination/"
fi

if [[ -n "${AVALONIA_RUST_SIGN_COMMAND:-}" ]]; then
    signer="$AVALONIA_RUST_SIGN_COMMAND"
    if [[ ! -f "$signer" || ! -x "$signer" ]]; then
        echo "AVALONIA_RUST_SIGN_COMMAND must be an executable signing wrapper or executable script." >&2
        exit 1
    fi
    echo "==> Signing executable artifacts with AVALONIA_RUST_SIGN_COMMAND"
    for artifact in "$destination"/*; do
        case "$artifact" in *.so|*.so.*|*.dylib|*/"$example") ;; *) continue ;; esac
        echo "    signing $(basename -- "$artifact")"
        "$signer" "$artifact"
    done
else
    echo "AVALONIA_RUST_SIGN_COMMAND is not set; skipping signing." \
        "Set it to a trusted signing wrapper executable/script path; it receives each artifact path as its only argument." \
        "This script never downloads a signing tool."
fi

echo "==> Writing deterministic CycloneDX delivery SBOM"
python3 "$script_dir/generate-sbom.py" --rid "$rid" --bundle "$destination"

echo "==> Writing checksums.sha256"
manifest_tmp="$output_root/.checksums.sha256.$rid.$$"
if [[ -e "$manifest_tmp" ]]; then
    echo "Refusing to overwrite an existing temporary checksum manifest: $manifest_tmp" >&2
    exit 1
fi
(
    cd "$destination"
    trap 'rm -f "$manifest_tmp"' EXIT
    shopt -s nullglob
    : > "$manifest_tmp"
    for artifact in *; do
        [[ -f "$artifact" && "$artifact" != "checksums.sha256" ]] || continue
        if command -v sha256sum >/dev/null; then
            hash="$(sha256sum -- "$artifact" | awk '{print $1}')"
        else
            hash="$(shasum -a 256 -- "$artifact" | awk '{print $1}')"
        fi
        printf '%s *%s\n' "$hash" "$artifact" >> "$manifest_tmp"
    done
    mv "$manifest_tmp" checksums.sha256
    trap - EXIT
    while IFS= read -r entry; do
        artifact="${entry#* \*}"
        if [[ "$artifact" == "$entry" || "$artifact" == "checksums.sha256" || ! -f "$artifact" ]]; then
            echo "Checksum manifest contains a missing or invalid artifact path: $entry" >&2
            exit 1
        fi
    done < checksums.sha256
)

echo "Package layout ready at $destination"
ls -l "$destination"
