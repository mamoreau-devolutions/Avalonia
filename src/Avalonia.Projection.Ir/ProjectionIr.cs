using System.Text.Json;
using System.Text.Json.Serialization;

namespace Avalonia.Projection.Ir;

public sealed class ProjectionIr
{
    public const int CurrentVersion = 12;

    public int Version { get; init; } = CurrentVersion;
    public string? SourceAssembly { get; init; }
    public string? FactoryIid { get; init; }
    public int FactoryAbiVersion { get; init; } = 1;

    /// <summary>
    /// The projected solid-brush interface, present only when a member marshals as
    /// <see cref="MarshallingKind.Brush"/>.
    /// </summary>
    public string? BrushInterfaceName { get; init; }
    public string? BrushInterfaceIid { get; init; }
    public int BrushAbiVersion { get; init; } = 1;

    public IReadOnlyList<ProjectedType> Types { get; init; } = [];
    public IReadOnlyList<ProjectedEnum> Enums { get; init; } = [];
    public IReadOnlyList<ProjectedAttachedProperty> AttachedProperties { get; init; } = [];
    public IReadOnlyList<SkippedMember> Skipped { get; init; } = [];

    public static JsonSerializerOptions JsonOptions { get; } = new()
    {
        WriteIndented = true,
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
        DefaultIgnoreCondition = JsonIgnoreCondition.WhenWritingNull,
    };

    public string ToJson() => JsonSerializer.Serialize(this, JsonOptions);

    public static ProjectionIr FromJson(string json) =>
        JsonSerializer.Deserialize<ProjectionIr>(json, JsonOptions)
        ?? throw new InvalidOperationException("IR JSON deserialized to null.");
}
