# Rust host compatibility policy

`Avalonia.Host`, the generated managed projection, and all crates in this
workspace are released in semver lockstep from one source revision. The crates
are `publish = false`; consumers must not mix a host or generated bindings from
one release with crates from another release.

## Generated IR

`projection.ir.json` and `view-model.ir.json` are versioned schemas. A
generator change must regenerate all checked-in managed, Rust, and contract
outputs in the same change. Additive, optional schema fields require a schema
version bump and readers that reject unsupported future versions clearly.
Removing or changing the meaning, type, ordering, or requiredness of an
existing field is breaking and requires a coordinated major release.

Consumer application manifests are independently versioned by
`consumer-app-manifest.schema.json`; version 1 is validated before any build
command runs. A consumer must pin the producer checkout/submodule commit that
provides its `avalonia` crate, projection tool, and `Avalonia.Host`. Do not mix
consumer-generated registry/adapters or Rust API from one producer revision
with a host from another.

## Native ABI

Published interface IIDs, vtable slot order, method signatures, calling
conventions, ownership rules, and error semantics are immutable. Never reuse an
IID for a changed interface and never insert a slot into an existing vtable.
Add a separately named, separately versioned interface with a new IID (for
example `IAvnRustVmSink2`), then negotiate/query it as optional capability.
Any unavoidable incompatible ABI change requires a new host ABI generation and
a coordinated major release.

## RID artifacts

Release artifacts are per RID and retain their exact names:
`Avalonia.Host.dll` (`win-*`), `Avalonia.Host.so` (`linux-*`), and
`Avalonia.Host.dylib` (`osx-*`). Each artifact directory contains the matching
native dependencies, `licence.md`, a deterministic `sbom.cdx.json` delivery
inventory, and a `checksums.sha256` manifest covering every delivered file
except the manifest itself. Verify it before distribution or launch. Every RID
maps to an explicit native Rust target triple; packaging and executable tests
require a matching runner CPU rather than silently producing an untested cross
architecture binary.
Never substitute dependencies or combine directories from different RIDs.

Official release artifacts must be signed with the platform-appropriate
signing identity before the SBOM and checksums are generated. The optional
`AVALONIA_RUST_SIGN_COMMAND` hook is a wrapper executable/script path that
receives an artifact path as a separate argument; unsigned local developer
artifacts are not release artifacts.

The Rust host and standalone Rust artifacts are not NuGet packages, so
`nukebuild/SbomGenerator.cs` remains unchanged. Their per-RID delivery scope
is instead represented by `rust/generate-sbom.py` in `sbom.cdx.json`, including
the host, Rust executable, bundled native binaries, and licence with SHA-256
hashes after signing.
