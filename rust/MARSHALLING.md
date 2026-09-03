# Value-type and solid brush marshalling

Avalonia geometry value types cross the nano-COM ABI **by value** as blittable,
sequential structs instead of as COM objects. This keeps `Margin`, `Padding`,
`BorderThickness`, `CornerRadius` and friends cheap to read and write, and it
avoids a COM object per rectangle. Brushes are the one chrome member that is
*not* a value type: they cross as a small read-only COM interface that carries a
solid colour and an opacity. `Grid`'s track definitions are the one member that
crosses as a **string**: they use the same comma-separated length list Avalonia
already parses and prints (see [Grid track definitions](#grid-track-definitions)).

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
- `src/Avalonia.Projection.Ir/BrushMarshalling.cs` is the equivalent for the
  solid brush interface (CLR types, ABI interface name, factory method name).
- `ComSourceEmitter` writes the C# structs into
  `src/Avalonia.Host/Generated/ObjectModel/ProjectionStructs.g.cs`, each with
  `FromAvalonia`/`ToAvalonia` helpers, and the brush interface plus its
  `AvnBrush` wrapper into `IAvnBrush.g.cs`.
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

## Solid brushes

`IBrush` is an interface, not a value type, and a real brush graph (gradient
stops, tile modes, drawings, visuals) has no blittable shape. Rather than
project that graph, the ABI projects the one case that chrome actually needs: a
**solid colour**.

`MarshallingKind.Brush` maps `Avalonia.Media.IBrush` onto a single generated COM
interface:

```c
struct IAvnBrushVtbl {
    /* IUnknown slots 0-2 */
    AvnHResult (AVN_CALL *get_color)(IAvnBrush* self, AvnColor* value);   /* slot 3 */
    AvnHResult (AVN_CALL *get_opacity)(IAvnBrush* self, double* value);   /* slot 4 */
};
```

`IAvnBrush` is deliberately **read-only**. The managed side hands out immutable
brushes that several controls may share, so a setter would let one caller repaint
another control. A brush is instead minted by the factory, which appends one slot:

```c
AvnHResult (AVN_CALL *create_solid_color_brush)(
    IAvnControlFactory* self, AvnColor color, double opacity, IAvnBrush** value);
```

Unlike the `create_*` control slots it has no dispatcher affinity, so it does not
verify UI-thread access.

### What crosses, and what fails

| Managed value                                   | `get_*`                                 | `set_*` |
| ----------------------------------------------- | --------------------------------------- | ------- |
| `null`                                          | `S_OK`, null pointer                    | clears the property |
| `ISolidColorBrush` (including `SolidColorBrush`) | `S_OK`, colour + opacity                | writes an `ImmutableSolidColorBrush` |
| gradient / drawing / visual brush                | `AVN_E_NONSOLIDBRUSH` (`0xA7A70002`)    | unreachable — the ABI cannot express one |

Reading a non-solid brush fails explicitly rather than degrading to a "nearest"
colour, because a silently wrong colour is worse than an error a caller can act
on. Inbound, every brush is materialised as
`Avalonia.Media.Immutable.ImmutableSolidColorBrush(color, opacity)`, so a set is
always a solid brush by construction and anything a source brush carried beyond
colour and opacity (transforms, gradient stops) is dropped rather than guessed.

Gradients, `DrawingBrush` and `VisualBrush` are out of scope for this ABI. A
future wave that needs them must add a separately named, separately versioned
interface rather than widening `IAvnBrush`.

In safe Rust the brush is a plain value; only crossing the ABI needs the factory:

```rust
let accent = Brush::solid(Color::rgb(0x00, 0x7A, 0xCC));
let card = Border::new()?
    .background(accent)?
    .border_brush(Brush::new(Color::rgb(0xAA, 0xBB, 0xCC), 0.5))?
    .border_thickness(Thickness::uniform(1.0))?
    .corner_radius(CornerRadius::uniform(4.0))?;
assert_eq!(card.get_background()?, Some(accent));
card.set_border_brush(None)?;
```

Getters return `Result<Option<Brush>>` and setters take `impl Into<Option<Brush>>`,
so `None` clears the property and a `Brush` needs no `Some`. `Color::rgb` is a
`const` opaque-colour constructor, so a consumer can define a palette as
constants.

## Chrome members

The chrome wave allowlists the members that make a control look like part of an
application rather than an unstyled box:

| Projected interface     | Members |
| ----------------------- | ------- |
| `IAvnBorder`            | `Background`, `BorderBrush`, `BorderThickness` (`Thickness`), `CornerRadius` |
| `IAvnPanel`             | `Background` |
| `IAvnTemplatedControl`  | `Background`, `BorderBrush`, `BorderThickness`, `CornerRadius`, `FontSize`, `Foreground` |
| `IAvnTextBlock`         | `FontSize`, `FontWeight`, `Foreground`, `Padding` (`Thickness`), `TextAlignment` |

Each brush member sits on the type that declares it in Avalonia, so `Background`
is published once on `Panel` and once on `TemplatedControl` rather than being
duplicated onto `Grid`, `Button`, `Window` and the rest — a derived interface
that re-declared it would spend a second pair of slots on one property.
`FontWeight` and `TextAlignment` join the IR enums and project as Rust enums with
`TryFrom<i32>`. Rust enums cannot carry two names for one discriminant, so
Avalonia's weight aliases collapse onto the first declared name: write
`FontWeight::DemiBold` rather than `SemiBold`, and `FontWeight::Black` rather
than `Heavy`.

## Control completeness members

The completeness wave allowlists the remaining scalar and enum members that a
consumer needs before it has to reach for XAML, on types the object model already
projects:

| Projected interface   | Members |
| --------------------- | ------- |
| `IAvnContentControl`  | `HorizontalContentAlignment`, `VerticalContentAlignment` |
| `IAvnButton`          | `ClickMode`, `IsDefault`, `IsCancel`, `IsPressed` (read-only) |
| `IAvnToggleButton`    | `IsThreeState` |
| `IAvnListBox`         | `SelectionMode`, `SelectAll()`, `UnselectAll()` |
| `IAvnComboBox`        | `IsDropDownOpen`, `IsEditable`, `MaxDropDownHeight` |

As with every other wave, each member sits on the type that declares it in
Avalonia. `ComboBox` re-declares `HorizontalContentAlignment` and
`VerticalContentAlignment` with `new`, so they stay published once on
`ContentControl` rather than costing a second pair of slots.

`IsPressed` is a read-only direct property that Avalonia raises from its own
input handling, so the ABI publishes `get_is_pressed` and no setter. In safe Rust
a read-only member drops the `get_` prefix and has no builder: `button.is_pressed()?`.

`ClickMode` and `SelectionMode` join the IR enums. `SelectionMode` is a `[Flags]`
enum, and — like `KeyModifiers` — it projects as a plain Rust enum carrying only
the declared modes. A combined value such as `Multiple | Toggle` therefore cannot
be written from Rust, and reading one that XAML set reports
`Error::InvalidEnumValue`. Bitmask-shaped enums need their own representation and
are deliberately left to a later wave.

`Command`, `Flyout`, `ISelectionModel` and `PasswordChar` remain out of scope:
the first three need reference graphs the ABI does not marshal, and `char` is not
a marshalling kind.

## Grid track definitions

`Grid.ColumnDefinitions` and `Grid.RowDefinitions` are collections of
`ColumnDefinition`/`RowDefinition` objects, but Avalonia already has a canonical
textual form for them — the comma-separated length list AXAML writes — and both
collections own both halves of that conversion: `static Parse(string)` and an
overridden `ToString()`. The ABI publishes that string rather than a projected
collection:

| Projected interface | Members |
| ------------------- | ------- |
| `IAvnGrid`          | `ColumnDefinitions`, `RowDefinitions` (both UTF-16 strings) |

```c
AvnHResult (AVN_CALL *get_column_definitions)(IAvnGrid* self, uint16_t** value);
AvnHResult (AVN_CALL *set_column_definitions)(IAvnGrid* self, const uint16_t* value);
```

```rust
grid.set_column_definitions("*,Auto,120")?;
assert_eq!(grid.get_column_definitions()?, "1*,Auto,120");
```

The host wrapper converts on both sides: a get is `ColumnDefinitions.ToString()`
and a set is `ColumnDefinitions.Parse(value)`. This is expressed in the profile
as an ordinary marshalling override to `StringUtf16` on a member whose CLR type
is not `string`; the extractor refuses such an override unless the managed type
declares `static T Parse(string)` and overrides `ToString()`, so the emitter
never guesses at a conversion. No definition object, list interface or factory
slot is minted, which is why this costs `IAvnGrid` four slots and nothing else.

### What the string does and does not carry

The list is **normalising, not byte-preserving**. `*` is shorthand for `1*`, and
whitespace between entries is a separator, so writing `"*, Auto, 120"` and
reading it back reports `"1*,Auto,120"`. A list that has already been normalised
is a fixed point: writing what the getter returned changes nothing. An empty grid
reports an empty string rather than a null pointer, and writing an empty string
clears the tracks — there is no null definition list.

The list carries only each track's `Width`/`Height`, because that is all
`ColumnDefinitions.ToString()` prints. `MinWidth`, `MaxWidth`, `MinHeight`,
`MaxHeight` and `SharedSizeGroup` on an individual definition are **not** in
scope of this ABI, and a set replaces the whole collection, so anything a
previous definition carried beyond its length is dropped rather than merged. That
is a deliberate v1 boundary rather than an oversight: a per-definition surface
needs its own separately named, separately versioned interfaces and is left to a
later wave. A consumer that needs shared size groups should keep those tracks in
AXAML.

A malformed entry fails the call — `Parse` throws and the `HRESULT` carries it
back — rather than being silently dropped or rounded to a nearest length, and the
previous definitions stay in place.

## Versioning of the widened vtables

Nano-COM vtables are flattened, so widening a base type moves every slot of every
interface that inherits from it. Each wave therefore republishes the affected
interfaces at a new `abiVersion` under a fresh IID; the retired IIDs are never
reused. An interface whose flattened vtable is byte-identical keeps its IID, so a
stale consumer that queries for it still gets exactly the contract it was
compiled against.

| Wave     | Widened                                                     | Version | Unchanged |
| -------- | ----------------------------------------------------------- | ------- | --------- |
| Layout   | `IAvnStyledElement`, `IAvnControl` and everything below them | 2 → 3   | `IAvnAvaloniaObject` (2) |
| Chrome   | `IAvnBorder`, `IAvnPanel`, `IAvnTemplatedControl`, `IAvnTextBlock` and everything below them | 3 → 4 | `IAvnAvaloniaObject` (2), `IAvnStyledElement`, `IAvnControl`, `IAvnDecorator` (3) |
| Completeness | `IAvnContentControl`, `IAvnButton`, `IAvnToggleButton`, `IAvnListBox`, `IAvnComboBox` and everything below them | 4 → 5 | `IAvnAvaloniaObject` (2), `IAvnStyledElement`, `IAvnControl`, `IAvnDecorator` (3), `IAvnBorder`, `IAvnPanel`, `IAvnGrid`, `IAvnCanvas`, `IAvnDockPanel`, `IAvnStackPanel`, `IAvnTextBlock`, `IAvnTemplatedControl`, `IAvnItemsControl`, `IAvnSelectingItemsControl`, `IAvnTextBox`, `IAvnRangeBase`, `IAvnSlider`, `IAvnProgressBar` (4) |
| Definitions | `IAvnGrid` alone | 4 → 5 | everything else, including `IAvnPanel`, `IAvnCanvas`, `IAvnDockPanel`, `IAvnStackPanel` (4) |

Nothing in the object model derives from `Grid`, so the definitions wave moves
exactly one interface. `IAvnGrid` has published versions 1–4 and now publishes 5;
all four earlier IIDs are retired for good.

`IAvnControlFactory` grew `create_solid_color_brush` and moved from version 1 to
2. Neither the completeness nor the definitions wave adds a factory slot, so it
stays at 2. `IAvnBrush` is brand new, so it starts at version 1. The collection
interfaces and the event handler interfaces are unchanged, because they carry
interface pointers rather than the widened layouts.

`Decorator` sits between `Control` and `Border`. The chrome wave added members to
`Border`, not to `Decorator`, and nothing was added to `Decorator`'s bases either,
so `IAvnDecorator` keeps the version 3 IID it published with the layout wave even
though `IAvnBorder` moved to 4. `ListBox` and `ComboBox` derive from
`SelectingItemsControl`, not from `ContentControl`, so they moved to 5 for their
own members while `IAvnItemsControl` and `IAvnSelectingItemsControl` stayed at 4.

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
