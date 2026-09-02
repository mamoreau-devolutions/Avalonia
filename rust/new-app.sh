#!/usr/bin/env bash
set -euo pipefail

name="${1:-}"
destination="${2:-}"
if [[ -z "$name" || -z "$destination" ]]; then
    echo "Usage: $0 <name> <destination>" >&2
    exit 2
fi
if [[ ! "$name" =~ ^[a-z][a-z0-9_]*$ ]]; then
    echo "Name '$name' must be a valid lowercase Cargo package name (e.g. my_app)." >&2
    exit 2
fi
if [[ -e "$destination" ]]; then
    echo "Destination '$destination' already exists." >&2
    exit 1
fi

script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
template_dir="$script_dir/templates/avalonia-app"
if [[ ! -d "$template_dir" ]]; then
    echo "Template directory not found at $template_dir" >&2
    exit 1
fi

mkdir -p "$(dirname -- "$destination")"
cp -R "$template_dir" "$destination"
rm -rf "$destination/target" "$destination/Cargo.lock"
sed -i.bak "s/avalonia-app-template/$name/" "$destination/Cargo.toml"
rm -f "$destination/Cargo.toml.bak"

echo "Created '$name' at $destination."
echo "Next steps:"
echo "  1. Update the 'avalonia' path dependency in $destination/Cargo.toml to point"
echo "     at your Avalonia checkout (or vendor rust/avalonia + rust/avalonia-sys)."
echo "  2. cargo build --release --manifest-path $destination/Cargo.toml"
echo "  3. Publish/copy a matching Avalonia.Host next to the built binary --"
echo "     rust/package.sh produces that layout -- then run the binary directly."
