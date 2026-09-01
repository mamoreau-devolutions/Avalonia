namespace Avalonia.Projection.Ir;

public sealed class ProjectedType
{
    public required string Name { get; init; }
    public required string FullName { get; init; }
    public required ProjectedTypeKind Kind { get; init; }
    public string? Iid { get; init; }
    public string? BaseFullName { get; init; }
    public string? ManagedFullName { get; init; }
    public bool IsConstructible { get; init; }
    public IReadOnlyList<ProjectedMethod> Methods { get; init; } = [];
    public IReadOnlyList<ProjectedProperty> Properties { get; init; } = [];
    public IReadOnlyList<ProjectedEvent> Events { get; init; } = [];
}

public sealed class ProjectedProperty
{
    public required string Name { get; init; }
    public required MarshallingKind Kind { get; init; }
    public bool CanRead { get; init; }
    public bool CanWrite { get; init; }
    public string? InterfaceName { get; init; }
    public string? InterfaceIid { get; init; }
    public string? ElementInterfaceName { get; init; }
    public string? ManagedTypeName { get; init; }
    public bool IsNullable { get; init; }
}
