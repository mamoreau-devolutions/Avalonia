namespace Avalonia.Projection.Ir;

public sealed class ProjectionPolicy
{
    public IReadOnlyList<string> IncludeNamespaces { get; init; } = [];
    public IReadOnlyList<string> IncludeTypeNames { get; init; } = [];
    public IReadOnlyList<string> ExcludeTypeNames { get; init; } = [];

    public bool Includes(Type type)
    {
        var fullName = type.FullName ?? type.Name;
        if (ExcludeTypeNames.Contains(fullName, StringComparer.Ordinal))
            return false;
        if (IncludeTypeNames.Contains(fullName, StringComparer.Ordinal))
            return true;
        if (IncludeNamespaces.Count == 0 && IncludeTypeNames.Count == 0)
            return true;
        var ns = type.Namespace ?? "";
        return IncludeNamespaces.Any(n =>
            ns.Equals(n, StringComparison.Ordinal) ||
            ns.StartsWith(n + ".", StringComparison.Ordinal));
    }
}
