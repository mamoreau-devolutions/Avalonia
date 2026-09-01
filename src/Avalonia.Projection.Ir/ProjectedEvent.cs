using System.Text.Json.Serialization;

namespace Avalonia.Projection.Ir;

public sealed class ProjectedEvent
{
    public required string Name { get; init; }
    public required string HandlerInterfaceName { get; init; }
    public required string HandlerInterfaceIid { get; init; }
    public required EventPayloadKind PayloadKind { get; init; }
    public string? ManagedHandlerTypeName { get; init; }
    public IReadOnlyList<ProjectedParameter> Parameters { get; init; } = [];
}

[JsonConverter(typeof(JsonStringEnumConverter))]
public enum EventPayloadKind
{
    None,
    Fields,
}
