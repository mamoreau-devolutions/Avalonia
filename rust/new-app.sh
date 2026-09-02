#!/usr/bin/env bash
set -euo pipefail

name="${1:-}"
destination="${2:-}"
producer_root="${3:-}"
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
producer_root="${producer_root:-$(cd -- "$script_dir/.." && pwd)}"
template_dir="$script_dir/templates/avalonia-app"
if [[ ! -d "$template_dir" ]]; then
    echo "Template directory not found at $template_dir" >&2
    exit 1
fi

mkdir -p "$(dirname -- "$destination")"
cp -R "$template_dir" "$destination"
rm -rf "$destination/target" "$destination/Cargo.lock"
escaped_producer_root="${producer_root//\\/\\\\}"
escaped_producer_root="${escaped_producer_root//&/\\&}"
escaped_producer_root="${escaped_producer_root//|/\\|}"
while IFS= read -r -d '' file; do
    sed -i.bak -e "s|__AVALONIA_APP_NAME__|$name|g" -e "s|__AVALONIA_PRODUCER_ROOT__|$escaped_producer_root|g" "$file"
    rm -f "$file.bak"
done < <(find "$destination" -type f -print0)

echo "Created '$name' at $destination."
echo "Next steps:"
echo "  1. Pin '$producer_root' to the compatible Avalonia producer commit/submodule."
echo "  2. $producer_root/rust/build-app.sh $producer_root $destination/avalonia-app.json"
