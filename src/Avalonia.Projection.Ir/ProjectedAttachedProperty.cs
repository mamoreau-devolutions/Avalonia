namespace Avalonia.Projection.Ir;

public sealed class ProjectedAttachedProperty
{
    public required string OwnerName { get; init; }
    public required string OwnerManagedFullName { get; init; }
    public required string StaticsInterfaceName { get; init; }
    public required string StaticsInterfaceIid { get; init; }
    public required string Name { get; init; }
    public required MarshallingKind Kind { get; init; }
    public required string ManagedTypeName { get; init; }
}
