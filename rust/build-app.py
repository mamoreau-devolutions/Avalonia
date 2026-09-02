#!/usr/bin/env python3
"""Build and package an external Rust/AXAML consumer against a pinned producer."""

import argparse
import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

RID_TARGETS = {
    "win-x64": ("x86_64-pc-windows-msvc", "Win32", ".dll", ".exe"),
    "win-arm64": ("aarch64-pc-windows-msvc", "Win32", ".dll", ".exe"),
    "linux-x64": ("x86_64-unknown-linux-gnu", "X11", ".so", ""),
    "linux-arm64": ("aarch64-unknown-linux-gnu", "X11", ".so", ""),
    "osx-x64": ("x86_64-apple-darwin", "OSX", ".dylib", ""),
    "osx-arm64": ("aarch64-apple-darwin", "OSX", ".dylib", ""),
}
PATH_FIELDS = ("presentationProject", "viewModelIr", "generatedAdaptersDirectory",
               "generatedRegistryFile", "generatedRustFile", "generatedContractFile",
               "cargoManifest", "outputDirectory")
REQUIRED = ("version",) + PATH_FIELDS[:-1] + ("packageName", "rid", "configuration", "outputDirectory")


def fail(message):
    raise ValueError(f"Invalid consumer manifest: {message}")


def resolve(manifest_path, value):
    path = Path(value)
    return (path if path.is_absolute() else manifest_path.parent / path).resolve()


def load_manifest(manifest_path):
    try:
        document = json.loads(manifest_path.read_text(encoding="utf-8"))
    except json.JSONDecodeError as error:
        fail(f"{manifest_path}: invalid JSON: {error.msg}")
    if not isinstance(document, dict):
        fail("the document must be an object")
    unknown = set(document) - set(REQUIRED) - {"binary"}
    if unknown:
        fail(f"unknown field(s): {', '.join(sorted(unknown))}")
    missing = [field for field in REQUIRED if field not in document]
    if missing:
        fail(f"missing required field(s): {', '.join(missing)}")
    if document["version"] != 1:
        fail("version must be 1")
    for field in PATH_FIELDS:
        if not isinstance(document[field], str) or not document[field]:
            fail(f"{field} must be a non-empty string")
    if document["rid"] not in RID_TARGETS:
        fail(f"rid must be one of: {', '.join(RID_TARGETS)}")
    if document["configuration"] not in ("Debug", "Release"):
        fail("configuration must be Debug or Release")
    for field in ("packageName", "binary"):
        if field in document and (not isinstance(document[field], str) or
                                  not re.fullmatch(r"[A-Za-z0-9][A-Za-z0-9_-]*", document[field])):
            fail(f"{field} must be a Cargo package/binary name")
    document["binary"] = document.get("binary", document["packageName"])
    document["_paths"] = {field: resolve(manifest_path, document[field]) for field in PATH_FIELDS}
    for field in ("presentationProject", "viewModelIr", "cargoManifest"):
        if not document["_paths"][field].is_file():
            fail(f"{field} does not exist: {document['_paths'][field]}")
    return document


def run(command, cwd=None, env=None):
    print("==>", " ".join(f'"{part}"' if " " in str(part) else str(part) for part in command))
    subprocess.run([str(part) for part in command], cwd=cwd, env=env, check=True)


def copy_files(source, destination, extension):
    for path in sorted(source.glob(f"*{extension}")):
        if path.is_file():
            shutil.copy2(path, destination / path.name)


def remove_tree(path):
    if path.exists():
        shutil.rmtree(path)
    if path.exists():
        raise ValueError(f"Could not remove stale artifact directory: {path}")


def write_checksums(bundle):
    entries = []
    for path in sorted(bundle.iterdir(), key=lambda item: item.name):
        if path.is_file() and path.name != "checksums.sha256":
            entries.append(f"{hashlib.sha256(path.read_bytes()).hexdigest()} *{path.name}\n")
    (bundle / "checksums.sha256").write_text("".join(entries), encoding="ascii", newline="\n")


def package(producer_root, manifest_path, document):
    paths = document["_paths"]
    target, platform, host_extension, executable_extension = RID_TARGETS[document["rid"]]
    host_project = producer_root / "src" / "Avalonia.Host" / "Avalonia.Host.csproj"
    projection_tool = producer_root / "src" / "Avalonia.ViewModelProjection.Tool" / "Avalonia.ViewModelProjection.Tool.csproj"
    license_file = producer_root / "licence.md"
    for path, description in ((host_project, "Avalonia.Host project"), (projection_tool, "view-model projection tool"), (license_file, "licence")):
        if not path.is_file():
            raise ValueError(f"Producer root is invalid; missing {description}: {path}")

    for field in ("generatedAdaptersDirectory", "generatedRegistryFile", "generatedRustFile", "generatedContractFile"):
        paths[field].parent.mkdir(parents=True, exist_ok=True)
    run(["dotnet", "run", "--project", projection_tool, "-c", document["configuration"], "--",
         paths["viewModelIr"], paths["generatedAdaptersDirectory"], paths["generatedRegistryFile"].parent,
         paths["generatedRustFile"], paths["generatedContractFile"], "--external-rust"], cwd=producer_root)

    run(["cargo", "fmt", "--manifest-path", paths["cargoManifest"]])
    run(["dotnet", "build", paths["presentationProject"], "-c", document["configuration"],
         f"-p:AvaloniaProducerRoot={producer_root}"])
    cargo_environment = os.environ.copy()
    cargo_target = manifest_path.parent / ".avalonia" / "cargo-target"
    cargo_environment["CARGO_TARGET_DIR"] = str(cargo_target)
    cargo_arguments = ["cargo", "build", "--manifest-path", paths["cargoManifest"], "-p", document["packageName"],
                       "--bin", document["binary"], "--target", target]
    profile = "debug"
    if document["configuration"] == "Release":
        cargo_arguments.append("--release")
        profile = "release"
    run(cargo_arguments, env=cargo_environment)
    executable = cargo_target / target / profile / f"{document['binary']}{executable_extension}"
    if not executable.is_file():
        raise ValueError(f"Cargo did not produce the declared binary: {executable}")

    bundle = paths["outputDirectory"]
    staging = bundle.parent / f".{bundle.name}.avalonia-staging"
    remove_tree(staging)
    staging.mkdir(parents=True)
    try:
        run(["dotnet", "publish", host_project, "-c", document["configuration"], "-r", document["rid"],
             f"-p:AvaloniaRustHostPlatform={platform}",
             f"-p:AvaloniaRustPresentationProjects={paths['presentationProject']}",
             f"-p:AvaloniaRustViewRegistryFile={paths['generatedRegistryFile']}",
             f"-p:PublishDir={staging}"], cwd=producer_root)
        host = staging / f"Avalonia.Host{host_extension}"
        if not host.is_file():
            raise ValueError(f"NativeAOT host was not produced: {host}")
        remove_tree(bundle)
        bundle.mkdir(parents=True)
        shutil.copy2(host, bundle / host.name)
        copy_files(staging, bundle, ".dll" if host_extension == ".dll" else host_extension)
        shutil.copy2(executable, bundle / executable.name)
        shutil.copy2(license_file, bundle / "licence.md")

        signer = os.environ.get("AVALONIA_RUST_SIGN_COMMAND")
        if signer:
            signer_path = Path(signer)
            if not signer_path.is_file():
                raise ValueError("AVALONIA_RUST_SIGN_COMMAND must name a trusted signing wrapper file")
            for artifact in sorted(path for path in bundle.iterdir()
                                   if path.suffix.lower() in {".dll", ".exe", ".so", ".dylib"}):
                run([signer_path, artifact])
        run([sys.executable, producer_root / "rust" / "generate-sbom.py", "--rid", document["rid"],
             "--bundle", bundle])
        write_checksums(bundle)
    finally:
        remove_tree(staging)
    print(f"Package layout ready at {bundle}")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--producer-root", required=True, type=Path)
    parser.add_argument("--manifest", required=True, type=Path)
    args = parser.parse_args()
    try:
        manifest_path = args.manifest.resolve()
        if not manifest_path.is_file():
            fail(f"manifest does not exist: {manifest_path}")
        document = load_manifest(manifest_path)
        package(args.producer_root.resolve(), manifest_path, document)
    except (ValueError, subprocess.CalledProcessError) as error:
        print(error, file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
