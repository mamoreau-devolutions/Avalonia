import importlib.util
import json
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path


MODULE = Path(__file__).parents[1] / "build-app.py"
SPEC = importlib.util.spec_from_file_location("build_app", MODULE)
build_app = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(build_app)


class ConsumerManifestTests(unittest.TestCase):
    def write_manifest(self, root, **overrides):
        for relative in ("managed/App.csproj", "view-model.ir.json", "Cargo.toml"):
            path = root / relative
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text("", encoding="utf-8")
        document = {
            "version": 1, "presentationProject": "managed/App.csproj",
            "viewModelIr": "view-model.ir.json", "generatedAdaptersDirectory": "managed/Generated",
            "generatedRegistryFile": "generated/RustViewRegistry.g.cs",
            "generatedRustFile": "generated/generated.rs", "generatedContractFile": "generated/contract.md",
            "cargoManifest": "Cargo.toml", "packageName": "consumer", "rid": "win-x64",
            "configuration": "Release", "outputDirectory": "artifacts/win-x64",
        }
        document.update(overrides)
        path = root / "avalonia-app.json"
        path.write_text(json.dumps(document), encoding="utf-8")
        return path

    def test_manifest_resolves_consumer_paths(self):
        with tempfile.TemporaryDirectory(dir=Path(__file__).parent) as directory:
            manifest = self.write_manifest(Path(directory))
            document = build_app.load_manifest(manifest)
            self.assertEqual("consumer", document["binary"])
            self.assertEqual((Path(directory) / "managed/App.csproj").resolve(),
                             document["_paths"]["presentationProject"])

    def test_manifest_rejects_unknown_and_missing_paths(self):
        with tempfile.TemporaryDirectory(dir=Path(__file__).parent) as directory:
            manifest = self.write_manifest(Path(directory), unexpected=True)
            with self.assertRaisesRegex(ValueError, "unknown field"):
                build_app.load_manifest(manifest)
            manifest = self.write_manifest(Path(directory), viewModelIr="missing.json")
            with self.assertRaisesRegex(ValueError, "viewModelIr does not exist"):
                build_app.load_manifest(manifest)

    def test_checksums_are_sorted_and_repeatable(self):
        with tempfile.TemporaryDirectory(dir=Path(__file__).parent) as directory:
            bundle = Path(directory)
            (bundle / "z.bin").write_bytes(b"z")
            (bundle / "a.bin").write_bytes(b"a")
            build_app.write_checksums(bundle)
            first = (bundle / "checksums.sha256").read_bytes()
            build_app.write_checksums(bundle)
            self.assertEqual(first, (bundle / "checksums.sha256").read_bytes())
            self.assertTrue(first.decode("ascii").endswith("*z.bin\n"))

    def test_delivery_sbom_is_repeatable(self):
        with tempfile.TemporaryDirectory(dir=Path(__file__).parent) as directory:
            bundle = Path(directory)
            (bundle / "app.exe").write_bytes(b"consumer")
            sbom = Path(__file__).parents[1] / "generate-sbom.py"
            command = [sys.executable, sbom, "--rid", "win-x64", "--bundle", bundle]
            subprocess.run(command, check=True)
            first = (bundle / "sbom.cdx.json").read_bytes()
            subprocess.run(command, check=True)
            self.assertEqual(first, (bundle / "sbom.cdx.json").read_bytes())

    def test_windows_msvc_consumers_link_the_crt_statically(self):
        environment = {"CARGO_TARGET_X86_64_PC_WINDOWS_MSVC_RUSTFLAGS": "-C opt-level=2"}

        result = build_app.configure_rust_environment(
            environment,
            "x86_64-pc-windows-msvc")

        self.assertEqual(
            "-C opt-level=2 -C target-feature=+crt-static",
            result["CARGO_TARGET_X86_64_PC_WINDOWS_MSVC_RUSTFLAGS"])
        build_app.configure_rust_environment(result, "x86_64-pc-windows-msvc")
        self.assertEqual(
            "-C opt-level=2 -C target-feature=+crt-static",
            result["CARGO_TARGET_X86_64_PC_WINDOWS_MSVC_RUSTFLAGS"])

    def test_non_msvc_consumers_keep_their_rust_environment(self):
        environment = {"RUSTFLAGS": "-C opt-level=2"}

        result = build_app.configure_rust_environment(
            environment,
            "x86_64-unknown-linux-gnu")

        self.assertEqual(environment, result)


if __name__ == "__main__":
    unittest.main()
