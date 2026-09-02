using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Avalonia.Projection.Ir;
using Xunit;

namespace Avalonia.Projection.Ir.Tests;

public class ViewModelIrTests
{
    [Fact]
    public void Checked_in_schema_is_valid_and_roundtrips()
    {
        var path = Path.Combine(FindRepositoryRoot(), "rust", "view-model.ir.json");
        var ir = ViewModelIr.FromJson(File.ReadAllText(path));

        Assert.Equal(ViewModelIr.CurrentVersion, ir.Version);
        Assert.Equal(3, ir.Models.Count);
        var model = ir.Models.Single(candidate => candidate.Name == "SampleViewModel");
        Assert.Equal(8, model.Properties.Count);
        Assert.Equal(9, model.Commands.Count);
        Assert.True(model.Commands.Single(command => command.Name == "Save").IsAsync);
        var enumDefinition = Assert.Single(ir.Enums);
        Assert.Equal("Priority", enumDefinition.Name);
        Assert.Equal(3, enumDefinition.Members.Count);
        Assert.Equal(
            Normalize(File.ReadAllText(path)),
            Normalize(ir.ToJson()));
    }

    [Fact]
    public void Duplicate_ids_are_rejected()
    {
        var ir = new ViewModelIr
        {
            Models =
            [
                new() { Id = 1, Name = "One", ManagedNamespace = "Tests" },
                new() { Id = 1, Name = "Two", ManagedNamespace = "Tests" },
            ],
        };

        Assert.Throws<InvalidOperationException>(() => ir.Validate());
    }

    [Fact]
    public void Non_string_collections_are_rejected()
    {
        var ir = CreateModel(collections:
        [
            new() { Id = 1, Name = "Values", ElementKind = ViewModelValueKind.Integer },
        ]);

        Assert.Throws<InvalidOperationException>(() => ir.Validate());
    }

    [Fact]
    public void Non_string_command_parameters_are_rejected()
    {
        var ir = CreateModel(
            properties:
        [
            new()
            {
                Id = 1,
                Name = "Count",
                Kind = ViewModelValueKind.Integer,
                Writable = true,
            },
        ],
            commands:
        [
            new() { Id = 1, Name = "SetCount", ParameterProperty = "Count" },
        ]);

        Assert.Throws<InvalidOperationException>(() => ir.Validate());
    }

    [Fact]
    public void Model_collections_are_accepted_when_the_element_model_exists()
    {
        var ir = new ViewModelIr
        {
            Models =
            [
                new()
                {
                    Id = 1,
                    Name = "Parent",
                    ManagedNamespace = "Tests",
                    Collections = [new() { Id = 1, Name = "Children", ElementKind = ViewModelValueKind.Model, ElementModelName = "Child" }],
                },
                new() { Id = 2, Name = "Child", ManagedNamespace = "Tests" },
            ],
        };

        ir.Validate(); // does not throw
    }

    [Fact]
    public void Model_collections_referencing_unknown_models_are_rejected()
    {
        var ir = CreateModel(collections:
        [
            new() { Id = 1, Name = "Children", ElementKind = ViewModelValueKind.Model, ElementModelName = "DoesNotExist" },
        ]);

        Assert.Throws<InvalidOperationException>(() => ir.Validate());
    }

    [Fact]
    public void Recursive_model_properties_are_rejected_before_descriptor_generation()
    {
        var ir = new ViewModelIr
        {
            Models =
            [
                new()
                {
                    Id = 1, Name = "Parent", ManagedNamespace = "Tests",
                    Properties = [new() { Id = 1, Name = "Child", Kind = ViewModelValueKind.Model, ModelName = "Child", Nullable = true }],
                },
                new()
                {
                    Id = 2, Name = "Child", ManagedNamespace = "Tests",
                    Properties = [new() { Id = 1, Name = "Parent", Kind = ViewModelValueKind.Model, ModelName = "Parent", Nullable = true }],
                },
            ],
        };

        var error = Assert.Throws<InvalidOperationException>(() => ir.Validate());
        Assert.Contains("Recursive view-model schema graph", error.Message);
        Assert.Contains("Parent -> Child -> Parent", error.Message);
    }

    [Fact]
    public void Recursive_model_collections_are_rejected_before_descriptor_generation()
    {
        var ir = new ViewModelIr
        {
            Models =
            [
                new()
                {
                    Id = 1, Name = "Node", ManagedNamespace = "Tests",
                    Collections = [new() { Id = 1, Name = "Children", ElementKind = ViewModelValueKind.Model, ElementModelName = "Node" }],
                },
            ],
        };

        Assert.Contains(
            "Recursive view-model schema graph",
            Assert.Throws<InvalidOperationException>(() => ir.Validate()).Message);
    }

    [Fact]
    public void Enum_properties_require_a_declared_enum()
    {
        var ir = CreateModel(properties:
        [
            new() { Id = 1, Name = "Priority", Kind = ViewModelValueKind.Enum, Writable = true },
        ]);

        Assert.Throws<InvalidOperationException>(() => ir.Validate());
    }

    [Fact]
    public void Enum_properties_reject_an_initial_value_outside_the_declared_members()
    {
        var ir = CreateModel(
            properties:
        [
            new()
            {
                Id = 1,
                Name = "Priority",
                Kind = ViewModelValueKind.Enum,
                EnumName = "Priority",
                Writable = true,
                InitialInteger = 99,
            },
        ],
            enums:
        [
            new() { Id = 1, Name = "Priority", ManagedNamespace = "Tests", Members = [new() { Name = "Low", Value = 0 }] },
        ]);

        Assert.Throws<InvalidOperationException>(() => ir.Validate());
    }

    [Fact]
    public void Enum_properties_round_trip_with_a_declared_enum()
    {
        var ir = CreateModel(
            properties:
        [
            new()
            {
                Id = 1,
                Name = "Priority",
                Kind = ViewModelValueKind.Enum,
                EnumName = "Priority",
                Writable = true,
                InitialInteger = 1,
            },
        ],
            enums:
        [
            new()
            {
                Id = 1,
                Name = "Priority",
                ManagedNamespace = "Tests",
                Members = [new() { Name = "Low", Value = 0 }, new() { Name = "High", Value = 1 }],
            },
        ]);

        ir.Validate(); // does not throw
    }

    [Fact]
    public void Model_properties_must_be_nullable_and_not_writable()
    {
        var writable = CreateModel(properties:
        [
            new() { Id = 1, Name = "Address", Kind = ViewModelValueKind.Model, ModelName = "Model", Writable = true, Nullable = true },
        ]);
        Assert.Throws<InvalidOperationException>(() => writable.Validate());

        var notNullable = CreateModel(properties:
        [
            new() { Id = 1, Name = "Address", Kind = ViewModelValueKind.Model, ModelName = "Model", Writable = false, Nullable = false },
        ]);
        Assert.Throws<InvalidOperationException>(() => notNullable.Validate());
    }

    [Fact]
    public void Nullable_is_only_supported_for_string_and_model_properties()
    {
        var ir = CreateModel(properties:
        [
            new() { Id = 1, Name = "Count", Kind = ViewModelValueKind.Integer, Nullable = true },
        ]);

        Assert.Throws<InvalidOperationException>(() => ir.Validate());
    }

    [Fact]
    public void Non_positive_member_ids_are_rejected()
    {
        var ir = CreateModel(properties:
        [
            new() { Id = 0, Name = "Name", Kind = ViewModelValueKind.String },
        ]);

        Assert.Throws<InvalidOperationException>(() => ir.Validate());
    }

    [Fact]
    public void Initializer_must_match_property_kind()
    {
        var ir = CreateModel(properties:
        [
            new()
            {
                Id = 1,
                Name = "Name",
                Kind = ViewModelValueKind.String,
                InitialInteger = 1,
            },
        ]);

        Assert.Throws<InvalidOperationException>(() => ir.Validate());
    }

    private static ViewModelIr CreateModel(
        IReadOnlyList<ViewModelProperty>? properties = null,
        IReadOnlyList<ViewModelCollection>? collections = null,
        IReadOnlyList<ViewModelCommand>? commands = null,
        IReadOnlyList<ViewModelEnumDefinition>? enums = null) => new()
        {
            Enums = enums ?? [],
            Models =
        [
            new()
            {
                Id = 1,
                Name = "Model",
                ManagedNamespace = "Tests",
                Properties = properties ?? [],
                Collections = collections ?? [],
                Commands = commands ?? [],
            },
        ],
        };

    private static string FindRepositoryRoot()
    {
        for (var current = new DirectoryInfo(AppContext.BaseDirectory);
             current is not null;
             current = current.Parent)
        {
            var gitPath = Path.Combine(current.FullName, ".git");
            if (Directory.Exists(gitPath) || File.Exists(gitPath))
                return current.FullName;
        }
        throw new DirectoryNotFoundException("Could not locate repository root.");
    }

    private static string Normalize(string value) =>
        value.Replace("\r\n", "\n", StringComparison.Ordinal).Trim();
}
