using System.Reflection;
using System.Security.Cryptography;
using System.Text;

namespace Avalonia.Projection.Ir;

public static class ClrTypeExtractor
{
    private static readonly NullabilityInfoContext Nullability = new();

    public static ProjectionIr Extract(IEnumerable<Type> sourceTypes, ProjectionPolicy policy)
    {
        var selected = sourceTypes
            .Where(policy.Includes)
            .Distinct()
            .OrderBy(t => t.FullName, StringComparer.Ordinal)
            .ToArray();
        var projectedNames = selected.ToDictionary(
            t => t,
            t => $"{policy.ProjectionNamespace}.IAvn{t.Name}");
        var types = new List<ProjectedType>(selected.Length);
        var skipped = new List<SkippedMember>();

        foreach (var type in selected)
            types.Add(ProjectType(type, selected, projectedNames, policy, skipped));

        return new ProjectionIr
        {
            SourceAssembly = string.Join(
                ",",
                selected.Select(t => t.Assembly.GetName().Name).Distinct(StringComparer.Ordinal)),
            FactoryIid = CreateDeterministicIid($"{policy.ProjectionNamespace}.IAvnControlFactory"),
            Types = types,
            Enums = ExtractEnums(selected, policy),
            Skipped = skipped,
        };
    }

    public static string CreateDeterministicIid(string projectedFullName)
    {
        var hash = SHA256.HashData(Encoding.UTF8.GetBytes(
            $"Avalonia.Rust.Projection/v{ProjectionIr.CurrentVersion}/{projectedFullName}"));
        Span<byte> guidBytes = stackalloc byte[16];
        hash.AsSpan(0, guidBytes.Length).CopyTo(guidBytes);
        guidBytes[7] = (byte)((guidBytes[7] & 0x0f) | 0x50);
        guidBytes[8] = (byte)((guidBytes[8] & 0x3f) | 0x80);
        return new Guid(guidBytes).ToString("D").ToUpperInvariant();
    }

    private static ProjectedType ProjectType(
        Type type,
        IReadOnlyCollection<Type> selected,
        IReadOnlyDictionary<Type, string> projectedNames,
        ProjectionPolicy policy,
        List<SkippedMember> skipped)
    {
        var properties = new List<ProjectedProperty>();
        var methods = new List<ProjectedMethod>();
        var flags = BindingFlags.Public | BindingFlags.Instance;

        foreach (var property in type.GetProperties(flags).OrderBy(p => p.MetadataToken))
        {
            if (!policy.Includes(type, property))
            {
                if (property.DeclaringType == type)
                    Skip(skipped, type, property.Name, "Not included by projection policy");
                continue;
            }

            if (!TryMapMemberType(
                    property,
                    type,
                    property.PropertyType,
                    projectedNames,
                    policy,
                    out var kind,
                    out var interfaceName,
                    out var isNullable,
                    out var reason))
            {
                Skip(skipped, type, property.Name, reason!);
                continue;
            }

            properties.Add(new ProjectedProperty
            {
                Name = property.Name,
                Kind = kind,
                InterfaceName = interfaceName,
                InterfaceIid = kind == MarshallingKind.ComCollection
                    ? CreateDeterministicIid(interfaceName!)
                    : null,
                ElementInterfaceName = policy.TryGetOverride(type, property, out var memberOverride)
                    ? memberOverride.ElementInterfaceName
                    : null,
                ManagedTypeName = property.PropertyType.FullName,
                IsNullable = isNullable,
                CanRead = property.GetMethod?.IsPublic == true,
                CanWrite = property.SetMethod?.IsPublic == true,
            });
        }

        foreach (var method in type.GetMethods(flags)
                     .Where(m => !m.IsSpecialName)
                     .OrderBy(m => m.MetadataToken))
        {
            if (!policy.Includes(type, method))
            {
                if (method.DeclaringType == type)
                    Skip(skipped, type, FormatMethod(method), "Not included by projection policy");
                continue;
            }

            if (!TryProjectMethod(method, projectedNames, out var projected, out var reason))
            {
                Skip(skipped, type, FormatMethod(method), reason!);
                continue;
            }

            methods.Add(projected);
        }

        var projectedFullName = projectedNames[type];
        return new ProjectedType
        {
            Name = $"IAvn{type.Name}",
            FullName = projectedFullName,
            ManagedFullName = type.FullName ?? type.Name,
            Kind = ProjectedTypeKind.Class,
            Iid = CreateDeterministicIid(projectedFullName),
            BaseFullName = FindProjectedBase(type.BaseType, selected, projectedNames),
            IsConstructible = !type.IsAbstract && type.GetConstructor(Type.EmptyTypes) is not null,
            Properties = properties,
            Methods = methods,
        };
    }

    private static bool TryProjectMethod(
        MethodInfo method,
        IReadOnlyDictionary<Type, string> projectedNames,
        out ProjectedMethod projected,
        out string? reason)
    {
        projected = null!;
        reason = null;
        if (method.ReturnType != typeof(void))
        {
            reason = $"Return type '{method.ReturnType.FullName}' is not supported for projected commands";
            return false;
        }

        var parameters = new List<ProjectedParameter>();
        foreach (var parameter in method.GetParameters())
        {
            var parameterType = parameter.ParameterType;
            if (parameterType.IsByRef)
            {
                reason = $"Parameter '{parameter.Name}' is by-ref";
                return false;
            }

            if (!TryMapType(
                    parameterType,
                    projectedNames,
                    out var kind,
                    out var interfaceName,
                    out var typeReason))
            {
                reason = $"Parameter '{parameter.Name}': {typeReason}";
                return false;
            }

            parameters.Add(new ProjectedParameter
            {
                Name = parameter.Name ?? "arg",
                Kind = kind,
                InterfaceName = interfaceName,
                ManagedTypeName = parameterType.FullName,
                IsNullable = IsNullable(parameter),
                Direction = ParameterDirection.In,
            });
        }

        projected = new ProjectedMethod
        {
            Name = AbiMethodName(method),
            ManagedName = method.Name,
            ReturnKind = MarshallingKind.I32,
            PreserveSig = true,
            Parameters = parameters,
        };
        return true;
    }

    private static bool TryMapMemberType(
        PropertyInfo member,
        Type projectionOwner,
        Type type,
        IReadOnlyDictionary<Type, string> projectedNames,
        ProjectionPolicy policy,
        out MarshallingKind kind,
        out string? interfaceName,
        out bool isNullable,
        out string? reason)
    {
        if (policy.TryGetOverride(projectionOwner, member, out var value))
        {
            kind = value.Kind;
            interfaceName = value.InterfaceName;
            isNullable = value.IsNullable ?? IsNullable(member);
            reason = null;
            if (kind == MarshallingKind.ComInterface && string.IsNullOrWhiteSpace(interfaceName))
            {
                reason = "COM interface override requires InterfaceName";
                return false;
            }
            if (kind == MarshallingKind.ComCollection &&
                (string.IsNullOrWhiteSpace(interfaceName) || string.IsNullOrWhiteSpace(value.ElementInterfaceName)))
            {
                reason = "COM collection override requires InterfaceName and ElementInterfaceName";
                return false;
            }
            return true;
        }

        isNullable = IsNullable(member);
        return TryMapType(type, projectedNames, out kind, out interfaceName, out reason);
    }

    private static bool TryMapType(
        Type type,
        IReadOnlyDictionary<Type, string> projectedNames,
        out MarshallingKind kind,
        out string? interfaceName,
        out string? reason)
    {
        interfaceName = null;
        reason = null;
        type = Nullable.GetUnderlyingType(type) ?? type;

        if (type == typeof(int) || type.IsEnum)
            kind = MarshallingKind.I32;
        else if (type == typeof(long))
            kind = MarshallingKind.I64;
        else if (type == typeof(float))
            kind = MarshallingKind.F32;
        else if (type == typeof(double))
            kind = MarshallingKind.F64;
        else if (type == typeof(bool))
            kind = MarshallingKind.Bool;
        else if (type == typeof(string))
            kind = MarshallingKind.StringUtf16;
        else if (projectedNames.TryGetValue(type, out interfaceName))
            kind = MarshallingKind.ComInterface;
        else
        {
            kind = MarshallingKind.Unsupported;
            reason = $"Type '{type.FullName}' is not marshallable";
            return false;
        }

        return true;
    }

    private static string? FindProjectedBase(
        Type? baseType,
        IReadOnlyCollection<Type> selected,
        IReadOnlyDictionary<Type, string> projectedNames)
    {
        while (baseType is not null)
        {
            if (selected.Contains(baseType))
                return projectedNames[baseType];
            baseType = baseType.BaseType;
        }
        return null;
    }

    private static bool IsNullable(PropertyInfo property) =>
        Nullability.Create(property).ReadState == NullabilityState.Nullable;

    private static bool IsNullable(ParameterInfo parameter) =>
        Nullability.Create(parameter).ReadState == NullabilityState.Nullable;

    private static void Skip(List<SkippedMember> skipped, Type owner, string member, string reason) =>
        skipped.Add(new SkippedMember
        {
            Owner = owner.FullName ?? owner.Name,
            Member = member,
            Reason = reason,
        });

    private static string FormatMethod(MethodInfo method) =>
        $"{method.Name}({string.Join(", ", method.GetParameters().Select(p => p.ParameterType.Name))})";

    private static string AbiMethodName(MethodInfo method)
    {
        var parameters = method.GetParameters();
        return parameters.Length == 0
            ? method.Name
            : method.Name + "With" + string.Join("And", parameters.Select(p =>
                (Nullable.GetUnderlyingType(p.ParameterType) ?? p.ParameterType).Name));
    }

    private static IReadOnlyList<ProjectedEnum> ExtractEnums(
        IEnumerable<Type> selected,
        ProjectionPolicy policy) =>
        selected
            .SelectMany(type => type.GetProperties(BindingFlags.Public | BindingFlags.Instance)
                .Where(property => policy.Includes(type, property))
                .Select(property => Nullable.GetUnderlyingType(property.PropertyType) ?? property.PropertyType))
            .Where(type => type.IsEnum)
            .Distinct()
            .OrderBy(type => type.FullName, StringComparer.Ordinal)
            .Select(type => new ProjectedEnum
            {
                Name = type.Name,
                FullName = type.FullName ?? type.Name,
                Values = Enum.GetNames(type)
                    .Zip(Enum.GetValues(type).Cast<object>())
                    .Select(pair => new ProjectedEnumValue
                    {
                        Name = pair.First,
                        Value = Convert.ToInt32(pair.Second),
                    })
                    .ToArray(),
            })
            .ToArray();
}
