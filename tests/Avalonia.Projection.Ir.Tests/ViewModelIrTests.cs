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
        var model = Assert.Single(ir.Models);
        Assert.Equal("SampleViewModel", model.Name);
        Assert.Equal(4, model.Properties.Count);
        Assert.Equal(3, model.Commands.Count);
        Assert.True(model.Commands.Single(command => command.Name == "Save").IsAsync);
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
        IReadOnlyList<ViewModelCommand>? commands = null) => new()
    {
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
