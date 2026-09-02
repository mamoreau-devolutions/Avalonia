#!/usr/bin/env bash
set -euo pipefail
if [[ $# -ne 2 ]]; then
  echo "Usage: $0 <producer-root> <consumer-manifest>" >&2
  exit 2
fi
exec python3 "$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)/build-app.py" --producer-root "$1" --manifest "$2"
