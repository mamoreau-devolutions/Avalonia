using System.Text.Json;
using System.Text.Json.Serialization;

namespace Avalonia.Projection.Ir;

public sealed class ViewModelIr
{
    public const int CurrentVersion = 1;

    public int Version { get; init; } = CurrentVersion;
    public IReadOnlyList<ViewModelDefinition> Models { get; init; } = [];
    public IReadOnlyList<ViewDefinition> Views { get; init; } = [];

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
        EnsurePositiveIds(Models, model => model.Id, "model");
        EnsurePositiveIds(Views, view => view.Id, "view");
        EnsureUnique(Models, model => model.Id, "model ID");
        EnsureUnique(Models, model => model.Name, "model name");
        EnsureUnique(Views, view => view.Id, "view ID");
        EnsureUnique(Views, view => view.Name, "view name");

        var modelNames = Models.Select(model => model.Name).ToHashSet(StringComparer.Ordinal);
        foreach (var view in Views)
        {
            EnsureNotBlank(view.Name, "View name");
            EnsureNotBlank(view.ManagedTypeName, $"Managed type for view '{view.Name}'");
            if (!modelNames.Contains(view.Model))
                throw new InvalidOperationException(
                    $"View '{view.Name}' references unknown model '{view.Model}'.");
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
            }
            foreach (var collection in model.Collections)
            {
                EnsureNotBlank(collection.Name, $"Collection name in model '{model.Name}'");
                if (collection.ElementKind != ViewModelValueKind.String)
                    throw new InvalidOperationException(
                        $"Collection '{model.Name}.{collection.Name}' must contain strings.");
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
            }
        }
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
            ViewModelValueKind.Integer =>
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
            _ => true,
        };
        if (invalid)
            throw new InvalidOperationException(
                $"Property '{model.Name}.{property.Name}' has an initializer for a different value kind.");
    }

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
}

public enum ViewModelValueKind
{
    String,
    Integer,
    Boolean,
    Double,
}
