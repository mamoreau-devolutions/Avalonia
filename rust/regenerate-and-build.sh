#!/usr/bin/env bash
set -euo pipefail

configuration="${1:-Release}"
skip_managed_build="${AVN_SKIP_MANAGED_BUILD:-}"
run_tests="${AVN_RUN_CARGO_TESTS:-}"
validate_template="${AVN_VALIDATE_TEMPLATE:-}"
package_rid="${AVN_PACKAGE_RID:-}"

script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
repository_root="$(cd -- "$script_dir/.." && pwd)"

echo "==> [1/4] Regenerating object-model projection IR, C# COM sources, and native ABI header"
dotnet run --project "$repository_root/src/Avalonia.Projection.Tool" -c "$configuration" -- \
    "$repository_root/rust/projection.ir.json" \
    "$repository_root/src/Avalonia.Host/Generated/ObjectModel" \
    "$repository_root/rust/avalonia-sys/include/avalonia-rust-abi.h"

echo "==> [1/4] Regenerating Rust sys/safe bindings from projection IR"
(
    cd "$script_dir"
    cargo run -p avalonia-bindgen -- \
        ./projection.ir.json \
        ./avalonia-sys/src/generated.rs \
        ./avalonia/src/generated.rs
)

echo "==> [1/4] Regenerating view-model adapters/registry/Rust model/contract from the canonical view-model IR"
dotnet run --project "$repository_root/src/Avalonia.ViewModelProjection.Tool" -c "$configuration" -- \
    "$repository_root/rust/view-model.ir.json" \
    "$repository_root/samples/RustViewModelSample.Managed/Generated" \
    "$repository_root/src/Avalonia.Host/Generated/ViewModels" \
    "$repository_root/rust/avalonia/src/generated_view_models.rs" \
    "$repository_root/rust/view-model.contract.md"

(
    cd "$script_dir"
    cargo fmt --all
)

if [[ -z "$skip_managed_build" ]]; then
    echo "==> [2/4] Building managed AXAML (RustViewModelSample.Managed via Avalonia.Host)"
    dotnet build "$repository_root/src/Avalonia.Host/Avalonia.Host.csproj" -c "$configuration"
fi

echo "==> [3/4] Building the Rust workspace"
if [[ -n "$run_tests" ]]; then
    cargo test --manifest-path "$script_dir/Cargo.toml" --workspace
else
    cargo build --manifest-path "$script_dir/Cargo.toml" --workspace
fi

if [[ -n "$validate_template" ]]; then
    echo "==> [3/4] Validating the external consumer template compiles standalone"
    template_consumer="$script_dir/target/template-validation"
    rm -rf "$template_consumer"
    "$script_dir/new-app.sh" template_validation "$template_consumer" "$repository_root"
    cargo check --manifest-path "$template_consumer/Cargo.toml"
    rm -rf "$template_consumer"
fi

if [[ -n "$package_rid" ]]; then
    echo "==> [4/4] Packaging the NativeAOT host and a Rust example for $package_rid"
    "$script_dir/package.sh" "$package_rid" "$configuration"
fi

echo "Regeneration and build complete."
