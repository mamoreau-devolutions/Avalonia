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
    public IReadOnlyDictionary<string, EventProjection> EventOverrides { get; init; } =
        new Dictionary<string, EventProjection>(StringComparer.Ordinal);
    public IReadOnlyDictionary<string, IReadOnlyList<string>> AttachedProperties { get; init; } =
        new Dictionary<string, IReadOnlyList<string>>(StringComparer.Ordinal);

    /// <summary>
    /// Marshalling overrides for attached properties, keyed by
    /// <c>{owner full name}.{attached property name}</c>. An attached property whose CLR type
    /// is not directly marshallable needs one of these or it is reported as a gap.
    /// </summary>
    public IReadOnlyDictionary<string, MarshallingOverride> AttachedPropertyOverrides { get; init; } =
        new Dictionary<string, MarshallingOverride>(StringComparer.Ordinal);

    public IReadOnlyDictionary<string, int> AbiVersions { get; init; } =
        new Dictionary<string, int>(StringComparer.Ordinal);
    public int DefaultProjectedTypeAbiVersion { get; init; } = 1;
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

    public bool TryGetEventOverride(Type projectionOwner, EventInfo member, out EventProjection value) =>
        EventOverrides.TryGetValue(
            $"{projectionOwner.FullName}.{member.Name}",
            out value!);

    public bool TryGetAttachedOverride(Type owner, string attachedPropertyName, out MarshallingOverride value) =>
        AttachedPropertyOverrides.TryGetValue(
            $"{owner.FullName}.{attachedPropertyName}",
            out value!);

    public int GetAbiVersion(string projectedInterfaceName) =>
        AbiVersions.TryGetValue(projectedInterfaceName, out var version) ? version : 1;

    public int GetProjectedTypeAbiVersion(string projectedInterfaceName) =>
        AbiVersions.TryGetValue(projectedInterfaceName, out var version)
            ? version
            : DefaultProjectedTypeAbiVersion;
}

public sealed class EventProjection
{
    public required EventPayloadKind PayloadKind { get; init; }
    public IReadOnlyList<EventParameterProjection> Parameters { get; init; } = [];
}

public sealed class EventParameterProjection
{
    public required string Name { get; init; }
    public ParameterDirection Direction { get; init; } = ParameterDirection.In;
}

public sealed class MarshallingOverride
{
    public required MarshallingKind Kind { get; init; }
    public string? InterfaceName { get; init; }
    public string? ElementInterfaceName { get; init; }
    public MarshallingKind? ElementKind { get; init; }
    public bool? IsNullable { get; init; }

    /// <summary>
    /// A host-side static class that owns both halves of the string conversion for a member
    /// whose CLR type cannot own them itself — an interface, or <c>object</c>. It must expose
    /// <c>public static string? ToAbi(T value)</c> and <c>public static T FromAbi(string? value)</c>.
    /// Only meaningful when <see cref="Kind"/> is <see cref="MarshallingKind.StringUtf16"/>.
    /// </summary>
    public string? StringConverterTypeName { get; init; }
}
