# Geometry value-type marshalling

Avalonia geometry value types cross the nano-COM ABI **by value** as blittable,
sequential structs instead of as COM objects. This keeps `Margin`, `Padding`,
`BorderThickness`, `CornerRadius` and friends cheap to read and write, and it
avoids a COM object per rectangle.

## The structs

Every struct is `LayoutKind.Sequential` / `#[repr(C)]`, contains only `double`
(`f64`) or `uint32_t` (`u32`) fields, and therefore has an identical layout in
the C header, the C# host, and Rust.

| `MarshallingKind` | CLR type               | ABI struct        | Safe Rust type | Fields (in order)                          | Size |
| ----------------- | ---------------------- | ----------------- | -------------- | ------------------------------------------ | ---- |
| `Thickness`       | `Avalonia.Thickness`   | `AvnThickness`    | `Thickness`    | `left`, `top`, `right`, `bottom`           | 32   |
| `CornerRadius`    | `Avalonia.CornerRadius`| `AvnCornerRadius` | `CornerRadius` | `top_left`, `top_right`, `bottom_right`, `bottom_left` | 32 |
| `Size`            | `Avalonia.Size`        | `AvnSize`         | `Size`         | `width`, `height`                          | 16   |
| `Point`           | `Avalonia.Point`       | `AvnPoint`        | `Point`        | `x`, `y`                                   | 16   |
| `Rect`            | `Avalonia.Rect`        | `AvnRect`         | `Rect`         | `x`, `y`, `width`, `height`                | 32   |
| `Color`           | `Avalonia.Media.Color` | `AvnColor`        | `Color`        | `argb` (packed `u32`)                      | 4    |

`AvnColor` carries a single packed **ARGB** integer that matches
`Avalonia.Media.Color.ToUInt32()` exactly: `(A << 24) | (R << 16) | (G << 8) | B`.
The safe Rust `Color` splits it back into `a`, `r`, `g`, `b` bytes; converting in
either direction is lossless.

## Where each declaration comes from

Everything is generated from the shared projection IR by
`rust/regenerate-and-build.ps1`:

- `src/Avalonia.Projection.Ir/GeometryMarshalling.cs` is the managed source of
  truth (kind, CLR type, ABI name, field list, conversion style).
- `ComSourceEmitter` writes the C# structs into
  `src/Avalonia.Host/Generated/ObjectModel/ProjectionStructs.g.cs`, each with
  `FromAvalonia`/`ToAvalonia` helpers.
- `NativeHeaderEmitter` writes the `typedef struct Avn*` declarations into
  `rust/avalonia-sys/include/avalonia-rust-abi.h`.
- `rust/avalonia-bindgen/src/geometry.rs` is the Rust-side source of truth; it
  emits the `#[repr(C)]` structs into `avalonia-sys` and the ergonomic structs
  with `From`/`Into` bridges into the safe `avalonia` crate.

## ABI shape in vtables

A projected property of a geometry kind occupies the usual pair of slots and
passes the struct by value on the way in and by pointer on the way out:

```c
AvnHResult (AVN_CALL *get_margin)(IAvnControl* self, AvnThickness* value);
AvnHResult (AVN_CALL *set_margin)(IAvnControl* self, AvnThickness value);
```

## Layout members

The layout wave allowlists the first live geometry-carrying members, alongside
the scalar and enum layout members that belong with them:

| Projected interface | Members |
| ------------------- | ------- |
| `IAvnStyledElement` | `Name` (`string?`) |
| `IAvnControl`       | `Margin` (`Thickness`), `HorizontalAlignment`, `VerticalAlignment`, `MinWidth`, `MinHeight`, `MaxWidth`, `MaxHeight`, `IsVisible`, `Opacity` |
| `IAvnDecorator`     | `Padding` (`Thickness`) |
| `IAvnWindow`        | `CanResize`, `WindowState` |

`Avalonia.Controls.Control` has no `Padding`, so `Padding` sits on `Decorator`
(and therefore on `Border`), matching Avalonia's own hierarchy. Width and Height
were already on `Control`, so `Window` inherits them.

`HorizontalAlignment`, `VerticalAlignment` and `WindowState` are carried as
`int32_t` and projected into the safe crate as Rust enums with `TryFrom<i32>`.

In safe Rust each member is a `set_*`/`get_*` pair plus a chaining builder, and
`Thickness` gains `const` helpers so a caller never repeats a scalar:

```rust
let readout = TextBlock::new()?
    .text("Laid out from Rust")?
    .margin(Thickness::symmetric(12.0, 4.0))?
    .horizontal_alignment(HorizontalAlignment::Right)?
    .max_width(320.0)?;
readout.set_margin(Thickness::uniform(8.0))?;
```

`Thickness::uniform`, `Thickness::symmetric` and `CornerRadius::uniform` are
emitted from the `helpers` column of `avalonia-bindgen`'s geometry table, so a
new geometry struct opts into them declaratively.

## Versioning of the widened vtables

Nano-COM vtables are flattened, so widening `IAvnStyledElement` and
`IAvnControl` moves every slot of every interface that inherits from them. All
of those interfaces therefore republish at `abiVersion` 3 under a fresh IID; the
version 2 IIDs are retired rather than reused. `IAvnAvaloniaObject` projects no
members, its vtable is byte-identical, and it deliberately keeps its version 2
IID — a stale consumer that queries for it still gets exactly the contract it
was compiled against. `IAvnControlFactory`, the collection interfaces, and the
event handler interfaces are unchanged, because they carry interface pointers
rather than the widened layouts.

## Host constraint: same-assembly structs

`Avalonia.Host` builds with `EnableRuntimeMarshalling=true`, so it does **not**
carry `[assembly: DisableRuntimeMarshalling]`. Under that setting the COM
interface source generator only accepts a user-defined struct in a
`[GeneratedComInterface]` signature when the struct is declared in the same
compilation. That is why `ProjectionStructs.g.cs` is emitted directly into
`Avalonia.Host` alongside the generated interfaces. A separate assembly that
wants to declare its own COM interface over these structs must apply
`[assembly: DisableRuntimeMarshalling]` (equivalently, leave
`EnableRuntimeMarshalling` unset so `build/TrimmingEnable.props` applies it).

`IAvnGeometryEcho` / `AvnGeometryEcho` are ABI fixtures in `Avalonia.Host` that
echo every struct back through a real CCW/RCW round trip. They are not part of
the projected object model and are not reachable from `IAvnControlFactory`, so
adding members there never widens a published control vtable.
