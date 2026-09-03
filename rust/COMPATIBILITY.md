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
Version 3 adds optional table metadata only. It reuses the existing
collection/property/command transport: compiled AXAML owns cell bindings and
the generated table descriptor contains no runtime reflection path.
Version 4 adds the stage 30 richer data shapes as optional members only:
`maps` on a model, `window`/`tree`/`recursive` on a collection, and
`resultModelName`/`supportsProgress`/`supportsCancellation` on a command. A
schema that declares any of them while claiming version 3 or lower is rejected
with an explicit upgrade message rather than being silently downgraded.
Version 5 adds the stage 31 command surfaces as optional members only: `menus`,
`recentFiles` and `displayPath` on a model. A schema that declares any of them
while claiming version 4 or lower is rejected the same way. These are
presentation and Rust-owned state only: menus bind the already generated command
and property surface and recent files ride the published string-collection
transport, so version 5 introduces no view-model ABI.

`projection.ir.json` version 12 adds the optional `brushInterfaceName`,
`brushInterfaceIid` and `brushAbiVersion` members, present only when a projected
member marshals as `Brush`. `MarshallingKind.Brush` was appended after the
geometry kinds rather than grouped with the interface kinds, so every previously
published ordinal is unmoved.

Version 13 adds two optional members, both host-side only. A projected property
and an attached property may carry `stringConverterTypeName`, naming the host
type that converts the member between its CLR type and the UTF-16 string in its
ABI slot, and an attached property may carry `isNullable`. Neither changes an ABI
slot: a reader that ignores both sees the same vtable it always did, and no
previously published ordinal moves.

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
example `IAvnRustVmSink2`, stage 29's `IAvnApplication3` desktop file
integration capability, stage 30's `IAvnRustVmSink4` richer data shapes,
`IAvnRustVmRangeBatch` windowed range payload, `IAvnRustRangeSource` and
`IAvnRustViewModel2`, or stage 31's `IAvnApplication4` clipboard command
capability and its host-owned `IAvnClipboardData` payload builder, or
`IAvnRustVmSink5` for scalar-number collection elements), then
negotiate/query it as optional capability.
A producer or host that predates an optional capability must report
`E_NOINTERFACE` explicitly; silently dropping the affected updates is not an
acceptable degradation.
Any unavoidable incompatible ABI change requires a new host ABI generation and
a coordinated major release.

The generated object model (`IAvnControl` and friends) is versioned by the
`abiVersion` recorded per interface in `projection.ir.json`, which is hashed
into the IID. Nano-COM vtables are flattened, so allowlisting a member on a base
type moves every derived interface's slots; every affected interface bumps its
`abiVersion` together and republishes under a fresh IID, and the previous IIDs
are retired rather than reused. An interface whose flattened vtable is
byte-identical keeps its IID, so a stale consumer that queries for it still
receives exactly the contract it compiled against. The layout wave took
`IAvnStyledElement`, `IAvnControl` and everything below them to version 3 while
`IAvnAvaloniaObject` stayed at version 2. The chrome wave then took
`IAvnBorder`, `IAvnPanel`, `IAvnTemplatedControl`, `IAvnTextBlock` and everything
below them to version 4, while `IAvnAvaloniaObject` stayed at 2 and
`IAvnStyledElement`, `IAvnControl` and `IAvnDecorator` stayed at 3 because their
own flattened vtables did not move. `IAvnControlFactory` gained
`create_solid_color_brush` and moved from version 1 to 2, and the new read-only
`IAvnBrush` starts at version 1. The completeness wave then took
`IAvnContentControl`, `IAvnButton`, `IAvnToggleButton`, `IAvnListBox`,
`IAvnComboBox` and everything below them to version 5; `IAvnControlFactory`
gained no slot and stays at 2, and every interface outside those subtrees —
including `IAvnItemsControl` and `IAvnSelectingItemsControl` — keeps the version
whose flattened vtable it still matches. The definitions wave then took
`IAvnGrid` alone from 4 to 5 for `column_definitions`/`row_definitions`: nothing
in the object model derives from `Grid`, the definitions cross as ordinary UTF-16
strings rather than as a new interface, and `IAvnControlFactory` again gained no
slot. All four IIDs `IAvnGrid` published at versions 1–4 are retired.

The new-controls wave A is the first that widens nothing: `IAvnImage`,
`IAvnHeaderedItemsControl`, `IAvnTabControl`, `IAvnTabItem`, `IAvnTreeView`,
`IAvnTreeViewItem`, `IAvnToolTip` and `IAvnToolTipStatics` are all brand new and
publish at version 1, and every interface that shipped before keeps the exact IID
it last published. The one thing that moves is `IAvnControlFactory`, which gains
a creator per new control plus `get_tool_tip_statics` and goes from 2 to 3. A
consumer compiled against the definitions wave therefore only has to requery the
factory; every control interface pointer it already holds stays valid.

`projection.ir.json` needs no schema change to carry a member whose CLR type is
not `string` but whose ABI slot is: the existing `kind` and `managedTypeName`
pair already says both, exactly as it does for an enum carried as `I32`. A
`StringUtf16` override on a non-string member is accepted when the managed type
declares `static T Parse(string)` and overrides `ToString()`, so the conversion
belongs to the type rather than to the generator — or, when the CLR type cannot
own either half (`Image.Source` is an `IImage`, `ToolTip.Tip` is an `object`),
when the profile names a host-side converter in `stringConverterTypeName`. That
field is a host-side detail only: the ABI slot is an ordinary UTF-16 string, so
neither the native header nor the Rust bindings read it, and a consumer that
ignores it sees no difference.

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
Windows Rust executables use the static MSVC CRT; adding a dependency that
reintroduces a redistributable runtime DLL is a delivery-scope change and must
update packaging, SBOM coverage, and compatibility validation together.

Official release artifacts must be signed with the platform-appropriate
signing identity before the SBOM and checksums are generated. The optional
`AVALONIA_RUST_SIGN_COMMAND` hook is a wrapper executable/script path that
receives an artifact path as a separate argument; unsigned local developer
artifacts are not release artifacts.

The Rust host and standalone Rust artifacts are not NuGet packages, so
`nukebuild/SbomGenerator.cs` remains unchanged. Their per-RID delivery scope
is instead represented by `rust/generate-sbom.ps1` in `sbom.cdx.json`, including
the host, Rust executable, bundled native binaries, and licence with SHA-256
hashes after signing.

## File type associations

Registering a document type is packaging metadata owned by whatever installer
or store channel a consumer uses. The application template ships copyable
Windows/Linux/macOS snippets (see
[DESKTOP_FILES.md](DESKTOP_FILES.md#file-type-associations)); this workflow
deliberately does not introduce MSIX packaging or platform installers, and the
snippets add nothing to the delivered per-RID bundle, so the SBOM delivery
scope is unchanged.
