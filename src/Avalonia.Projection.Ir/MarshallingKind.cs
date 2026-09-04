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
