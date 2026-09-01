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
    StringUtf16,
    ComInterface,
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
