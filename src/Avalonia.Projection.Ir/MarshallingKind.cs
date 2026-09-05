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

    /// <summary>
    /// Appended after TimeSpanI64 so every previously published ordinal stays put.
    /// A <see cref="System.DateTime"/> carried as its int64 UTC tick count.
    /// </summary>
    DateTimeI64,

    /// <summary>
    /// Appended after DateTimeI64 so every previously published ordinal stays put.
    /// A <see cref="Avalonia.PixelPoint"/> carried as two int32 components.
    /// </summary>
    PixelPointI32,

    /// <summary>
    /// Appended after PixelPointI32 so every previously published ordinal stays put.
    /// A nano-COM <c>IAvnDataTemplate</c> wrapping
    /// <c>Avalonia.Controls.Templates.IDataTemplate</c>.
    /// </summary>
    DataTemplate,

    /// <summary>
    /// Appended after DataTemplate so every previously published ordinal stays put.
    /// A nano-COM <c>IAvnItemFilter</c> wrapping AutoCompleteBox's
    /// <c>AutoCompleteFilterPredicate&lt;object?&gt;</c>.
    /// </summary>
    ItemFilter,

    /// <summary>
    /// Appended after ItemFilter so every previously published ordinal stays put.
    /// A nano-COM <c>IAvnTextFilter</c> wrapping AutoCompleteBox's
    /// <c>AutoCompleteFilterPredicate&lt;string?&gt;</c>.
    /// </summary>
    TextFilter,
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
