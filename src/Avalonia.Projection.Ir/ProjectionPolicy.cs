using System.Reflection;

namespace Avalonia.Projection.Ir;

public sealed class ProjectionPolicy
{
    public IReadOnlyList<string> IncludeNamespaces { get; init; } = [];
    public IReadOnlyList<string> IncludeTypeNames { get; init; } = [];
    public IReadOnlyList<string> ExcludeTypeNames { get; init; } = [];
    public IReadOnlyDictionary<string, IReadOnlyList<string>> IncludeMembers { get; init; } =
        new Dictionary<string, IReadOnlyList<string>>(StringComparer.Ordinal);
    public IReadOnlyDictionary<string, MarshallingOverride> MemberOverrides { get; init; } =
        new Dictionary<string, MarshallingOverride>(StringComparer.Ordinal);
    public string ProjectionNamespace { get; init; } = "Avalonia.Host.Com";

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

    public bool Includes(Type projectionOwner, MemberInfo member)
    {
        var owner = projectionOwner.FullName ?? projectionOwner.Name;
        return IncludeMembers.TryGetValue(owner, out var members) &&
            members.Contains(member.Name, StringComparer.Ordinal);
    }

    public bool TryGetOverride(Type projectionOwner, MemberInfo member, out MarshallingOverride value) =>
        MemberOverrides.TryGetValue(
            $"{projectionOwner.FullName}.{member.Name}",
            out value!);
}

public sealed class MarshallingOverride
{
    public required MarshallingKind Kind { get; init; }
    public string? InterfaceName { get; init; }
    public string? ElementInterfaceName { get; init; }
    public bool? IsNullable { get; init; }
}
