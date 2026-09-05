using System.Text.Json;
using System.Text.Json.Serialization;

namespace Avalonia.Projection.Ir;

public sealed class ProjectionIr
{
    public const int CurrentVersion = 16;

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

    /// <summary>
    /// The projected command interface, present only when a member marshals as
    /// <see cref="MarshallingKind.Command"/>.
    /// </summary>
    public string? CommandInterfaceName { get; init; }
    public string? CommandInterfaceIid { get; init; }
    public int CommandAbiVersion { get; init; } = 1;

    /// <summary>
    /// The CanExecuteChanged handler interface paired with the projected command,
    /// present only when a member marshals as <see cref="MarshallingKind.Command"/>.
    /// </summary>
    public string? CommandHandlerInterfaceName { get; init; }
    public string? CommandHandlerInterfaceIid { get; init; }

    /// <summary>
    /// The projected data-template interface, present only when a member marshals as
    /// <see cref="MarshallingKind.DataTemplate"/>.
    /// </summary>
    public string? TemplateInterfaceName { get; init; }
    public string? TemplateInterfaceIid { get; init; }

    /// <summary>
    /// The projected AutoCompleteBox filter interfaces, present only when a member
    /// marshals as <see cref="MarshallingKind.ItemFilter"/> or
    /// <see cref="MarshallingKind.TextFilter"/>.
    /// </summary>
    public string? ItemFilterInterfaceName { get; init; }
    public string? ItemFilterInterfaceIid { get; init; }
    public string? TextFilterInterfaceName { get; init; }
    public string? TextFilterInterfaceIid { get; init; }

    /// <summary>
    /// The projected notification interface, present only when a member marshals as
    /// <see cref="MarshallingKind.Notification"/>.
    /// </summary>
    public string? NotificationInterfaceName { get; init; }
    public string? NotificationInterfaceIid { get; init; }
    public string? NotificationHandlerInterfaceIid { get; init; }

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
