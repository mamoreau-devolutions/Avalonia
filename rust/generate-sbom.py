#!/usr/bin/env python3
"""Create the deterministic CycloneDX delivery inventory for a Rust bundle."""

import argparse
import hashlib
import json
from pathlib import Path


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


parser = argparse.ArgumentParser()
parser.add_argument("--rid", required=True)
parser.add_argument("--bundle", required=True, type=Path)
args = parser.parse_args()

bundle = args.bundle.resolve()
output = bundle / "sbom.cdx.json"
bundle_id = hashlib.sha256(args.rid.encode()).hexdigest()
files = sorted(
    path for path in bundle.iterdir()
    if path.is_file() and path.name not in {"checksums.sha256", output.name}
)
components = [
    {
        "type": "file",
        "name": path.name,
        "version": args.rid,
        "hashes": [{"alg": "SHA-256", "content": sha256(path)}],
        "properties": [{"name": "avalonia:delivery-path", "value": path.name}],
    }
    for path in files
]
document = {
    "bomFormat": "CycloneDX",
    "specVersion": "1.5",
    "serialNumber": f"urn:uuid:{bundle_id[:8]}-{bundle_id[8:12]}-5{bundle_id[12:15]}-"
    f"8{bundle_id[15:18]}-{bundle_id[18:30]}",
    "version": 1,
    "metadata": {"component": {"type": "application", "name": "Avalonia Rust bundle", "version": args.rid}},
    "components": components,
}
output.write_text(json.dumps(document, indent=2, sort_keys=True) + "\n", encoding="utf-8")
