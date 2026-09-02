using System.Text.Json;
using System.Text.Json.Serialization;

namespace Avalonia.Projection.Ir;

public sealed class ViewModelIr
{
    public const int CurrentVersion = 2;

    public int Version { get; init; } = CurrentVersion;
    public IReadOnlyList<ViewModelEnumDefinition> Enums { get; init; } = [];
    public IReadOnlyList<ViewModelDefinition> Models { get; init; } = [];
    public IReadOnlyList<ViewDefinition> Views { get; init; } = [];
    public IReadOnlyList<ValueConverterDefinition> Converters { get; init; } = [];

    public static ViewModelIr FromJson(string json)
    {
        var value = JsonSerializer.Deserialize<ViewModelIr>(json, JsonOptions)
            ?? throw new InvalidOperationException("View-model IR deserialized to null.");
        value.Validate();
        return value;
    }

    public string ToJson()
    {
        Validate();
        return JsonSerializer.Serialize(this, JsonOptions);
    }

    public void Validate()
    {
        if (Version != CurrentVersion)
            throw new InvalidOperationException($"Unsupported view-model IR version {Version}.");
        EnsurePositiveIds(Enums, enumDefinition => enumDefinition.Id, "enum");
        EnsurePositiveIds(Models, model => model.Id, "model");
        EnsurePositiveIds(Views, view => view.Id, "view");
        EnsurePositiveIds(Converters, converter => converter.Id, "converter");
        EnsureUnique(Enums, enumDefinition => enumDefinition.Id, "enum ID");
        EnsureUnique(Enums, enumDefinition => enumDefinition.Name, "enum name");
        EnsureUnique(Models, model => model.Id, "model ID");
        EnsureUnique(Models, model => model.Name, "model name");
        EnsureUnique(Views, view => view.Id, "view ID");
        EnsureUnique(Views, view => view.Name, "view name");
        EnsureUnique(Converters, converter => converter.Id, "converter ID");
        EnsureUnique(Converters, converter => converter.Name, "converter name");

        var modelNames = Models.Select(model => model.Name).ToHashSet(StringComparer.Ordinal);
        var enumsByName = Enums.ToDictionary(enumDefinition => enumDefinition.Name, StringComparer.Ordinal);
        var converterNames = Converters.Select(converter => converter.Name).ToHashSet(StringComparer.Ordinal);

        foreach (var enumDefinition in Enums)
        {
            EnsureNotBlank(enumDefinition.Name, "Enum name");
            EnsureNotBlank(enumDefinition.ManagedNamespace, $"Managed namespace for enum '{enumDefinition.Name}'");
            if (enumDefinition.Members.Count == 0)
                throw new InvalidOperationException($"Enum '{enumDefinition.Name}' must declare at least one member.");
            EnsureUnique(enumDefinition.Members, member => member.Name, $"{enumDefinition.Name} member name");
            EnsureUnique(enumDefinition.Members, member => member.Value, $"{enumDefinition.Name} member value");
            foreach (var member in enumDefinition.Members)
                EnsureNotBlank(member.Name, $"Member name in enum '{enumDefinition.Name}'");
        }

        foreach (var view in Views)
        {
            EnsureNotBlank(view.Name, "View name");
            EnsureNotBlank(view.ManagedTypeName, $"Managed type for view '{view.Name}'");
            if (!modelNames.Contains(view.Model))
                throw new InvalidOperationException(
                    $"View '{view.Name}' references unknown model '{view.Model}'.");
            foreach (var converter in view.Converters)
            {
                if (!converterNames.Contains(converter))
                    throw new InvalidOperationException(
                        $"View '{view.Name}' references unknown converter '{converter}'.");
            }
        }

        foreach (var converter in Converters)
        {
            EnsureNotBlank(converter.Name, "Converter name");
            EnsureNotBlank(converter.ManagedNamespace, $"Managed namespace for converter '{converter.Name}'");
            if (!IsScalarKind(converter.ValueKind))
                throw new InvalidOperationException(
                    $"Converter '{converter.Name}' has an unsupported value kind '{converter.ValueKind}'; converters only support string/integer/boolean/double.");
            if (!IsScalarKind(converter.ResultKind))
                throw new InvalidOperationException(
                    $"Converter '{converter.Name}' has an unsupported result kind '{converter.ResultKind}'; converters only support string/integer/boolean/double.");
            if (converter.ParameterKind is { } parameterKind && (!Enum.IsDefined(parameterKind) || !IsScalarKind(parameterKind)))
                throw new InvalidOperationException(
                    $"Converter '{converter.Name}' has an invalid parameter kind.");
        }

        foreach (var model in Models)
        {
            EnsureNotBlank(model.Name, "Model name");
            EnsureNotBlank(model.ManagedNamespace, $"Managed namespace for model '{model.Name}'");
            EnsurePositiveIds(model.Properties, property => property.Id, $"{model.Name} property");
            EnsurePositiveIds(model.Collections, collection => collection.Id, $"{model.Name} collection");
            EnsurePositiveIds(model.Commands, command => command.Id, $"{model.Name} command");
            EnsureUnique(model.Properties, property => property.Id, $"{model.Name} property ID");
            EnsureUnique(model.Properties, property => property.Name, $"{model.Name} property name");
            EnsureUnique(model.Collections, collection => collection.Id, $"{model.Name} collection ID");
            EnsureUnique(model.Collections, collection => collection.Name, $"{model.Name} collection name");
            EnsureUnique(model.Commands, command => command.Id, $"{model.Name} command ID");
            EnsureUnique(model.Commands, command => command.Name, $"{model.Name} command name");

            var properties = model.Properties
                .ToDictionary(property => property.Name, StringComparer.Ordinal);
            foreach (var property in model.Properties)
            {
                EnsureNotBlank(property.Name, $"Property name in model '{model.Name}'");
                ValidateInitialValue(model, property);
                ValidateEnumProperty(model, property, enumsByName);
                ValidateModelProperty(model, property, modelNames);
            }
            foreach (var collection in model.Collections)
            {
                EnsureNotBlank(collection.Name, $"Collection name in model '{model.Name}'");
                switch (collection.ElementKind)
                {
                    case ViewModelValueKind.String:
                        break;
                    case ViewModelValueKind.Model:
                        if (collection.ElementModelName is null)
                            throw new InvalidOperationException(
                                $"Collection '{model.Name}.{collection.Name}' must declare 'elementModelName'.");
                        if (!modelNames.Contains(collection.ElementModelName))
                            throw new InvalidOperationException(
                                $"Collection '{model.Name}.{collection.Name}' references unknown model '{collection.ElementModelName}'.");
                        break;
                    default:
                        throw new InvalidOperationException(
                            $"Collection '{model.Name}.{collection.Name}' must contain strings or nested view models.");
                }
            }
            foreach (var command in model.Commands)
            {
                EnsureNotBlank(command.Name, $"Command name in model '{model.Name}'");
                if (command.ParameterProperty is null)
                    continue;
                if (!properties.TryGetValue(command.ParameterProperty, out var property))
                    throw new InvalidOperationException(
                        $"Command '{model.Name}.{command.Name}' references unknown parameter property '{command.ParameterProperty}'.");
                if (!property.Writable)
                    throw new InvalidOperationException(
                        $"Command parameter property '{model.Name}.{property.Name}' must be writable.");
                if (property.Kind != ViewModelValueKind.String)
                    throw new InvalidOperationException(
                        $"Command parameter property '{model.Name}.{property.Name}' must be a string.");
                if (property.Nullable)
                    throw new InvalidOperationException(
                        $"Command parameter property '{model.Name}.{property.Name}' must not be nullable.");
            }
        }

        ValidateAcyclicModelGraph();
    }

    private void ValidateAcyclicModelGraph()
    {
        var edges = Models.ToDictionary(
            model => model.Name,
            model => model.Properties
                .Where(property => property.Kind == ViewModelValueKind.Model)
                .Select(property => property.ModelName!)
                .Concat(model.Collections
                    .Where(collection => collection.ElementKind == ViewModelValueKind.Model)
                    .Select(collection => collection.ElementModelName!))
                .ToArray(),
            StringComparer.Ordinal);
        var states = new Dictionary<string, VisitState>(StringComparer.Ordinal);
        var path = new List<string>();

        foreach (var model in Models)
            Visit(model.Name);

        void Visit(string model)
        {
            if (states.TryGetValue(model, out var state))
            {
                if (state == VisitState.Visiting)
                {
                    var start = path.IndexOf(model);
                    var cycle = path.Skip(start).Append(model);
                    throw new InvalidOperationException(
                        $"Recursive view-model schema graph is not supported: {string.Join(" -> ", cycle)}.");
                }

                return;
            }

            states.Add(model, VisitState.Visiting);
            path.Add(model);
            foreach (var child in edges[model])
                Visit(child);
            path.RemoveAt(path.Count - 1);
            states[model] = VisitState.Visited;
        }
    }

    private enum VisitState
    {
        Visiting,
        Visited,
    }

    private static void ValidateInitialValue(
        ViewModelDefinition model,
        ViewModelProperty property)
    {
        var invalid = property.Kind switch
        {
            ViewModelValueKind.String =>
                property.InitialInteger is not null ||
                property.InitialBoolean is not null ||
                property.InitialDouble is not null,
            ViewModelValueKind.Integer or ViewModelValueKind.Enum =>
                property.InitialString is not null ||
                property.InitialBoolean is not null ||
                property.InitialDouble is not null,
            ViewModelValueKind.Boolean =>
                property.InitialString is not null ||
                property.InitialInteger is not null ||
                property.InitialDouble is not null,
            ViewModelValueKind.Double =>
                property.InitialString is not null ||
                property.InitialInteger is not null ||
                property.InitialBoolean is not null,
            ViewModelValueKind.Model =>
                property.InitialString is not null ||
                property.InitialInteger is not null ||
                property.InitialBoolean is not null ||
                property.InitialDouble is not null,
            _ => true,
        };
        if (invalid)
            throw new InvalidOperationException(
                $"Property '{model.Name}.{property.Name}' has an initializer for a different value kind.");
    }

    private static void ValidateEnumProperty(
        ViewModelDefinition model,
        ViewModelProperty property,
        IReadOnlyDictionary<string, ViewModelEnumDefinition> enumsByName)
    {
        if (property.Kind == ViewModelValueKind.Enum)
        {
            if (property.EnumName is null)
                throw new InvalidOperationException(
                    $"Property '{model.Name}.{property.Name}' must declare 'enumName'.");
            if (!enumsByName.TryGetValue(property.EnumName, out var enumDefinition))
                throw new InvalidOperationException(
                    $"Property '{model.Name}.{property.Name}' references unknown enum '{property.EnumName}'.");
            if (property.InitialInteger is { } initial &&
                !enumDefinition.Members.Any(member => member.Value == initial))
            {
                throw new InvalidOperationException(
                    $"Property '{model.Name}.{property.Name}' has an initial value that is not a member of enum '{property.EnumName}'.");
            }
            if (property.Nullable)
                throw new InvalidOperationException(
                    $"Property '{model.Name}.{property.Name}' is an enum property and cannot be nullable in this stage.");
        }
        else if (property.EnumName is not null)
        {
            throw new InvalidOperationException(
                $"Property '{model.Name}.{property.Name}' declares 'enumName' but is not an enum property.");
        }
    }

    private static void ValidateModelProperty(
        ViewModelDefinition model,
        ViewModelProperty property,
        IReadOnlySet<string> modelNames)
    {
        if (property.Kind == ViewModelValueKind.Model)
        {
            if (property.ModelName is null)
                throw new InvalidOperationException(
                    $"Property '{model.Name}.{property.Name}' must declare 'modelName'.");
            if (!modelNames.Contains(property.ModelName))
                throw new InvalidOperationException(
                    $"Property '{model.Name}.{property.Name}' references unknown model '{property.ModelName}'.");
            if (property.Writable)
                throw new InvalidOperationException(
                    $"Property '{model.Name}.{property.Name}' is a nested view model and cannot be writable from managed code.");
            if (!property.Nullable)
                throw new InvalidOperationException(
                    $"Property '{model.Name}.{property.Name}' is a nested view model and must be nullable.");
        }
        else if (property.ModelName is not null)
        {
            throw new InvalidOperationException(
                $"Property '{model.Name}.{property.Name}' declares 'modelName' but is not a nested view model.");
        }
        else if (property.Kind != ViewModelValueKind.String && property.Nullable)
        {
            throw new InvalidOperationException(
                $"Property '{model.Name}.{property.Name}' is nullable but only string and nested view-model properties support nullability in this stage.");
        }
    }

    private static bool IsScalarKind(ViewModelValueKind kind) =>
        kind is ViewModelValueKind.String or ViewModelValueKind.Integer or ViewModelValueKind.Boolean or ViewModelValueKind.Double;

    private static void EnsureNotBlank(string value, string description)
    {
        if (string.IsNullOrWhiteSpace(value))
            throw new InvalidOperationException($"{description} cannot be empty.");
    }

    private static void EnsurePositiveIds<T>(
        IEnumerable<T> values,
        Func<T, int> id,
        string description)
    {
        foreach (var value in values)
        {
            if (id(value) <= 0)
                throw new InvalidOperationException(
                    $"{description} ID '{id(value)}' must be positive.");
        }
    }

    private static void EnsureUnique<T, TKey>(
        IEnumerable<T> values,
        Func<T, TKey> key,
        string description)
        where TKey : notnull
    {
        var seen = new HashSet<TKey>();
        foreach (var value in values)
        {
            if (!seen.Add(key(value)))
                throw new InvalidOperationException($"Duplicate {description} '{key(value)}'.");
        }
    }

    private static JsonSerializerOptions JsonOptions { get; } = new()
    {
        WriteIndented = true,
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
        DefaultIgnoreCondition = JsonIgnoreCondition.WhenWritingNull,
        Converters = { new JsonStringEnumConverter() },
    };
}

public sealed class ViewModelDefinition
{
    public required int Id { get; init; }
    public required string Name { get; init; }
    public required string ManagedNamespace { get; init; }
    public IReadOnlyList<ViewModelProperty> Properties { get; init; } = [];
    public IReadOnlyList<ViewModelCollection> Collections { get; init; } = [];
    public IReadOnlyList<ViewModelCommand> Commands { get; init; } = [];
}

public sealed class ViewModelProperty
{
    public required int Id { get; init; }
    public required string Name { get; init; }
    public required ViewModelValueKind Kind { get; init; }
    public bool Writable { get; init; }

    /// <summary>
    /// Whether the property may currently hold no value. Only string and
    /// nested view-model (<see cref="ViewModelValueKind.Model"/>) properties
    /// support nullability in this stage; a <see cref="ViewModelValueKind.Model"/>
    /// property is always nullable (there may be no nested view model yet).
    /// A nullable property is published outbound-only through a dedicated
    /// "became null" transport signal (see <c>IAvnRustVmSink2.SetNull</c>);
    /// inbound writes always carry a concrete value.
    /// </summary>
    public bool Nullable { get; init; }

    /// <summary>Name of the enum (from <see cref="ViewModelIr.Enums"/>) this property's values come from. Required when <see cref="Kind"/> is <see cref="ViewModelValueKind.Enum"/>.</summary>
    public string? EnumName { get; init; }

    /// <summary>Name of the nested model (from <see cref="ViewModelIr.Models"/>) this property refers to. Required when <see cref="Kind"/> is <see cref="ViewModelValueKind.Model"/>.</summary>
    public string? ModelName { get; init; }

    public string? InitialString { get; init; }
    public long? InitialInteger { get; init; }
    public bool? InitialBoolean { get; init; }
    public double? InitialDouble { get; init; }
}

public sealed class ViewModelCollection
{
    public required int Id { get; init; }
    public required string Name { get; init; }
    public required ViewModelValueKind ElementKind { get; init; }

    /// <summary>Name of the nested model each element is. Required when <see cref="ElementKind"/> is <see cref="ViewModelValueKind.Model"/>.</summary>
    public string? ElementModelName { get; init; }
}

public sealed class ViewModelCommand
{
    public required int Id { get; init; }
    public required string Name { get; init; }
    public bool IsAsync { get; init; }
    public string? ParameterProperty { get; init; }
}

public sealed class ViewDefinition
{
    public required int Id { get; init; }
    public required string Name { get; init; }
    public required string Model { get; init; }
    public required string ManagedTypeName { get; init; }
    public bool DynamicBindings { get; init; }

    /// <summary>
    /// Names of converters (from <see cref="ViewModelIr.Converters"/>) this
    /// view uses. Purely documentation for the generated contract report and
    /// the generated "with converters" mount API name; the generated
    /// converters trait always contains every schema-wide converter.
    /// </summary>
    public IReadOnlyList<string> Converters { get; init; } = [];
}

/// <summary>
/// A Rust-authored, pure <c>IValueConverter</c>. Converters are schema-wide
/// (not owned by a single model) because they must not read or lock any
/// view-model state; see <see cref="ViewDefinition.Converters"/> for which
/// views are documented to use a given converter.
/// </summary>
public sealed class ValueConverterDefinition
{
    public required int Id { get; init; }
    public required string Name { get; init; }
    public required string ManagedNamespace { get; init; }
    public required ViewModelValueKind ValueKind { get; init; }
    public ViewModelValueKind? ParameterKind { get; init; }
    public required ViewModelValueKind ResultKind { get; init; }
    public bool SupportsConvertBack { get; init; }
}

public enum ViewModelValueKind
{
    String,
    Integer,
    Boolean,
    Double,

    /// <summary>
    /// An integer-backed named constant set (see <see cref="ViewModelIr.Enums"/>).
    /// Transported on the wire as <see cref="Integer"/> (no new ABI kind);
    /// only the generated C#/Rust surface types it as a real enum.
    /// </summary>
    Enum,

    /// <summary>
    /// A reference to another model in <see cref="ViewModelIr.Models"/>,
    /// owned and republished wholesale by Rust. Always nullable and never
    /// writable from managed code (its own properties/commands are writable
    /// independently, through its own generated adapter).
    /// </summary>
    Model,
}

/// <summary>
/// An integer-backed named constant set shared by both the generated C# enum
/// and the generated Rust <c>#[repr(i64)]</c> enum. Member values are
/// explicit and stable, exactly like property/command/model IDs, so
/// reordering members in the schema cannot change the wire representation.
/// </summary>
public sealed class ViewModelEnumDefinition
{
    public required int Id { get; init; }
    public required string Name { get; init; }
    public required string ManagedNamespace { get; init; }
    public IReadOnlyList<ViewModelEnumMember> Members { get; init; } = [];
}

public sealed class ViewModelEnumMember
{
    public required string Name { get; init; }
    public required long Value { get; init; }
}
