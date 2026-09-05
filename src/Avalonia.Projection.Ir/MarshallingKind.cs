using System.Text.Json.Serialization;

namespace Avalonia.Projection.Ir;

[JsonConverter(typeof(JsonStringEnumConverter))]
public enum MarshallingKind
{
    Unsupported,
    Void,
    I32,
    I64,
    F32,
    F64,
    Bool,
    NullableBool,
    StringUtf16,
    ComInterface,
    ComCollection,
    Thickness,
    CornerRadius,
    Size,
    Point,
    Rect,
    Color,

    /// <summary>
    /// Appended rather than grouped with the interface kinds so every previously published
    /// ordinal stays put.
    /// </summary>
    Brush,

    /// <summary>
    /// Appended after Brush so every previously published ordinal stays put.
    /// Two doubles, identical in layout to <see cref="Point"/>.
    /// </summary>
    Vector,

    /// <summary>
    /// Appended after Vector so every previously published ordinal stays put.
    /// A single UTF-16 code unit (<see cref="char"/> / <c>uint16_t</c>).
    /// </summary>
    CharUtf16,

    /// <summary>
    /// Appended after CharUtf16 so every previously published ordinal stays put.
    /// A nano-COM <c>IAvnCommand</c> wrapping <c>System.Windows.Input.ICommand</c>.
    /// </summary>
    Command,

    /// <summary>
    /// Appended after Command so every previously published ordinal stays put.
    /// A tagged scalar: None, UTF-16 text, I32, F64 or Bool, matching the
    /// closed set `object` command parameters can carry across the ABI.
    /// </summary>
    Variant,

    /// <summary>
    /// Appended after Variant so every previously published ordinal stays put.
    /// A <see cref="System.TimeSpan"/> carried as its int64 tick count.
    /// </summary>
    TimeSpanI64,
}

[JsonConverter(typeof(JsonStringEnumConverter))]
public enum ParameterDirection
{
    In,
    Out,
    InOut,
}

[JsonConverter(typeof(JsonStringEnumConverter))]
public enum ProjectedTypeKind
{
    Interface,
    Class,
    Struct,
    Enum,
}
