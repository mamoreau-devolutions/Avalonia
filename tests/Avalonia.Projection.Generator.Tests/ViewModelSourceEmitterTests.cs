using System;
using System.Linq;
using Avalonia.Projection.Ir;
using Xunit;

namespace Avalonia.Projection.Generator.Tests;

public class ViewModelSourceEmitterTests
{
    [Fact]
    public void Emits_deterministic_csharp_rust_and_contract_output()
    {
        var ir = SampleIr();

        var csharpFirst = ViewModelSourceEmitter.EmitCSharp(ir);
        var csharpSecond = ViewModelSourceEmitter.EmitCSharp(ir);
        var rustFirst = ViewModelSourceEmitter.EmitRust(ir);
        var rustSecond = ViewModelSourceEmitter.EmitRust(ir);
        var contractFirst = ViewModelSourceEmitter.EmitContract(ir);
        var contractSecond = ViewModelSourceEmitter.EmitContract(ir);

        Assert.Equal(csharpFirst.Keys.OrderBy(k => k, StringComparer.Ordinal), csharpSecond.Keys.OrderBy(k => k, StringComparer.Ordinal));
        foreach (var key in csharpFirst.Keys)
            Assert.Equal(csharpFirst[key], csharpSecond[key]);
        Assert.Equal(rustFirst, rustSecond);
        Assert.Equal(
            ViewModelSourceEmitter.EmitRust(ir, externalConsumer: true),
            ViewModelSourceEmitter.EmitRust(ir, externalConsumer: true));
        Assert.Equal(contractFirst, contractSecond);
    }

    [Fact]
    public void Emits_a_managed_static_class_exposing_a_rust_value_converter_instance()
    {
        var ir = SampleIr();
        var files = ViewModelSourceEmitter.EmitCSharp(ir);

        Assert.True(files.ContainsKey("CountToLabelConverter.g.cs"));
        var source = files["CountToLabelConverter.g.cs"];
        Assert.Contains("namespace Avalonia.Rust.Sample.Generated;", source, StringComparison.Ordinal);
        Assert.Contains("public static class CountToLabelConverter", source, StringComparison.Ordinal);
        Assert.Contains("public static IValueConverter Instance { get; } = new RustValueConverter(1, false);", source, StringComparison.Ordinal);
    }

    [Fact]
    public void Emits_a_named_rust_trait_method_per_converter_without_raw_ids_and_a_dispatch_bridge()
    {
        var ir = SampleIr();
        var rust = ViewModelSourceEmitter.EmitRust(ir);

        Assert.Contains("pub trait ValueConverters: Send + Sync + 'static {", rust, StringComparison.Ordinal);
        Assert.Contains("fn count_to_label(&self, value: i64) -> String;", rust, StringComparison.Ordinal);
        Assert.Contains("impl<T: ValueConverters> crate::value_converter::ValueConverterDispatch for ValueConvertersDispatch<T>", rust, StringComparison.Ordinal);
        Assert.Contains("(1, ConversionDirection::Convert) =>", rust, StringComparison.Ordinal);
        Assert.Contains("self.converters.count_to_label(value)", rust, StringComparison.Ordinal);
        Assert.Contains("pub fn register_value_converters(&self, converters: impl ValueConverters)", rust, StringComparison.Ordinal);

        // A convert-back-incapable converter must not gain a `_back` method.
        Assert.DoesNotContain("count_to_label_back", rust, StringComparison.Ordinal);
    }

    [Fact]
    public void Emits_collection_operations_by_element_kind()
    {
        var rust = ViewModelSourceEmitter.EmitRust(SampleIr());
        var csharp = ViewModelSourceEmitter.EmitCSharp(SampleIr())["SampleViewModelAdapter.g.cs"];

        Assert.Contains("remove_items(&self, index: i32) -> crate::Result<()> { self.0.remove_string_at(1, index) }", rust, StringComparison.Ordinal);
        Assert.Contains("move_items(&self, from_index: i32, to_index: i32) -> crate::Result<()> { self.0.move_string_item(1, from_index, to_index) }", rust, StringComparison.Ordinal);
        Assert.Contains("clear_items(&self) -> crate::Result<()> { self.0.clear_string_collection(1) }", rust, StringComparison.Ordinal);
        Assert.Contains("remove_tasks(&self, index: i32) -> crate::Result<()> { self.0.remove_model_at(2, index) }", rust, StringComparison.Ordinal);
        Assert.Contains("move_tasks(&self, from_index: i32, to_index: i32) -> crate::Result<()> { self.0.move_model_item(2, from_index, to_index) }", rust, StringComparison.Ordinal);
        Assert.Contains("clear_tasks(&self) -> crate::Result<()> { self.0.clear_model_collection(2) }", rust, StringComparison.Ordinal);
        Assert.Contains("DisposeNestedAdapters();", csharp, StringComparison.Ordinal);
        Assert.Contains("try { _model.Detach(); }", csharp, StringComparison.Ordinal);
        Assert.Contains("finally", csharp, StringComparison.Ordinal);
    }

    [Fact]
    public void Emits_a_back_method_only_when_convert_back_is_declared()
    {
        var ir = SampleIr(
        [
            new ValueConverterDefinition
            {
                Id = 1,
                Name = "CountToLabel",
                ManagedNamespace = "Avalonia.Rust.Sample.Generated",
                ValueKind = ViewModelValueKind.Integer,
                ResultKind = ViewModelValueKind.String,
                SupportsConvertBack = true,
            },
        ]);

        var rust = ViewModelSourceEmitter.EmitRust(ir);

        Assert.Contains("fn count_to_label(&self, value: i64) -> String;", rust, StringComparison.Ordinal);
        Assert.Contains("fn count_to_label_back(&self, value: String) -> i64;", rust, StringComparison.Ordinal);
        Assert.Contains("(1, ConversionDirection::ConvertBack) =>", rust, StringComparison.Ordinal);

        var files = ViewModelSourceEmitter.EmitCSharp(ir);
        Assert.Contains("new RustValueConverter(1, true);", files["CountToLabelConverter.g.cs"], StringComparison.Ordinal);
    }

    [Fact]
    public void Preserves_existing_mount_api_and_adds_a_with_converters_variant_only_for_declaring_views()
    {
        var ir = SampleIr();
        var rust = ViewModelSourceEmitter.EmitRust(ir);

        Assert.Contains(
            "impl crate::AppScope { pub fn mount_rust_vm_window(&self, model: impl SampleViewModel) -> crate::Result<()> { self.mount_dynamic_view_model(1, SampleViewModelDispatch { model }) } }",
            rust,
            StringComparison.Ordinal);
        Assert.Contains("pub fn mount_rust_vm_window_with_converters<C: ValueConverters>(", rust, StringComparison.Ordinal);
    }

    [Fact]
    public void Emits_external_consumer_functions_without_inherent_foreign_type_implementations()
    {
        var rust = ViewModelSourceEmitter.EmitRust(SampleIr(), externalConsumer: true);

        Assert.Contains(
            "pub fn mount_rust_vm_window(scope: &crate::AppScope, model: impl SampleViewModel)",
            rust,
            StringComparison.Ordinal);
        Assert.Contains("#![allow(dead_code)]", rust, StringComparison.Ordinal);
        Assert.Contains(
            "pub fn register_value_converters(scope: &crate::AppScope, converters: impl ValueConverters)",
            rust,
            StringComparison.Ordinal);
        Assert.DoesNotContain("impl crate::AppScope { pub fn mount_rust_vm_window", rust, StringComparison.Ordinal);
    }

    [Fact]
    public void Emits_no_converter_artifacts_when_the_schema_declares_none()
    {
        var ir = new ViewModelIr
        {
            Models = SampleModels(),
            Views =
            [
                new ViewDefinition
                {
                    Id = 1,
                    Name = "RustVmWindow",
                    Model = "SampleViewModel",
                    ManagedTypeName = "Avalonia.Rust.Sample.Views.RustVmWindow",
                },
            ],
            Converters = [],
        };

        var rust = ViewModelSourceEmitter.EmitRust(ir);
        var files = ViewModelSourceEmitter.EmitCSharp(ir);

        Assert.DoesNotContain("ValueConverters", rust, StringComparison.Ordinal);
        Assert.DoesNotContain("register_value_converters", rust, StringComparison.Ordinal);
        Assert.False(files.ContainsKey("CountToLabelConverter.g.cs"));
    }

    [Fact]
    public void Includes_value_converters_in_the_readable_contract_report()
    {
        var ir = SampleIr();
        var contract = ViewModelSourceEmitter.EmitContract(ir);

        Assert.Contains("## Value converters", contract, StringComparison.Ordinal);
        Assert.Contains("| 1 | `CountToLabel` | `Integer` | None | `String` | No |", contract, StringComparison.Ordinal);
        Assert.Contains("`RustVmWindow`", contract, StringComparison.Ordinal);
    }

    [Fact]
    public void Rejects_duplicate_converter_ids_and_names()
    {
        var duplicateId = SampleIr(
        [
            new ValueConverterDefinition { Id = 1, Name = "A", ManagedNamespace = "N", ValueKind = ViewModelValueKind.Integer, ResultKind = ViewModelValueKind.String },
            new ValueConverterDefinition { Id = 1, Name = "B", ManagedNamespace = "N", ValueKind = ViewModelValueKind.Integer, ResultKind = ViewModelValueKind.String },
        ]);
        Assert.Throws<InvalidOperationException>(duplicateId.Validate);

        var duplicateName = SampleIr(
        [
            new ValueConverterDefinition { Id = 1, Name = "A", ManagedNamespace = "N", ValueKind = ViewModelValueKind.Integer, ResultKind = ViewModelValueKind.String },
            new ValueConverterDefinition { Id = 2, Name = "A", ManagedNamespace = "N", ValueKind = ViewModelValueKind.Integer, ResultKind = ViewModelValueKind.String },
        ]);
        Assert.Throws<InvalidOperationException>(duplicateName.Validate);
    }

    [Fact]
    public void Rejects_a_view_referencing_an_unknown_converter()
    {
        var badView = new ViewModelIr
        {
            Models = SampleModels(),
            Views =
            [
                SampleViews()[0],
                new ViewDefinition
                {
                    Id = 2,
                    Name = "RustDynamicVmWindow",
                    Model = "SampleViewModel",
                    ManagedTypeName = "Avalonia.Rust.Sample.Views.RustDynamicVmWindow",
                    DynamicBindings = true,
                    Converters = ["DoesNotExist"],
                },
            ],
            Converters = SampleConverters(),
        };

        Assert.Throws<InvalidOperationException>(badView.Validate);
    }

    [Fact]
    public void Enum_member_named_error_does_not_ambiguate_try_from_error_type()
    {
        var ir = new ViewModelIr
        {
            Models = SampleModels(),
            Views = SampleViews(),
            Converters = SampleConverters(),
            Enums =
            [
                new ViewModelEnumDefinition
                {
                    Id = 1,
                    Name = "Severity",
                    ManagedNamespace = "Avalonia.Rust.Sample.Generated",
                    Members =
                    [
                        new ViewModelEnumMember { Name = "Info", Value = 0 },
                        new ViewModelEnumMember { Name = "Error", Value = 1 },
                    ],
                },
            ],
        };

        var rust = ViewModelSourceEmitter.EmitRust(ir, externalConsumer: true);

        Assert.Contains(
            "fn try_from(value: i64) -> std::result::Result<Self, ()>",
            rust,
            StringComparison.Ordinal);
    }

    private static ViewModelIr SampleIr() => SampleIr(SampleConverters());

    private static ViewModelIr SampleIr(ValueConverterDefinition[] converters) => new()
    {
        Models = SampleModels(),
        Views = SampleViews(),
        Converters = converters,
    };

    private static ViewModelDefinition[] SampleModels() =>
    [
        new ViewModelDefinition
        {
            Id = 1,
            Name = "SampleViewModel",
            ManagedNamespace = "Avalonia.Rust.Sample.Generated",
            Properties =
            [
                new ViewModelProperty { Id = 2, Name = "Count", Kind = ViewModelValueKind.Integer },
            ],
            Collections =
            [
                new ViewModelCollection { Id = 1, Name = "Items", ElementKind = ViewModelValueKind.String },
                new ViewModelCollection { Id = 2, Name = "Tasks", ElementKind = ViewModelValueKind.Model, ElementModelName = "TaskItemViewModel" },
            ],
        },
        new ViewModelDefinition
        {
            Id = 2,
            Name = "TaskItemViewModel",
            ManagedNamespace = "Avalonia.Rust.Sample.Generated",
        },
    ];

    private static ViewDefinition[] SampleViews() =>
    [
        new ViewDefinition
        {
            Id = 1,
            Name = "RustVmWindow",
            Model = "SampleViewModel",
            ManagedTypeName = "Avalonia.Rust.Sample.Views.RustVmWindow",
            Converters = ["CountToLabel"],
        },
        new ViewDefinition
        {
            Id = 2,
            Name = "RustDynamicVmWindow",
            Model = "SampleViewModel",
            ManagedTypeName = "Avalonia.Rust.Sample.Views.RustDynamicVmWindow",
            DynamicBindings = true,
            Converters = ["CountToLabel"],
        },
    ];

    private static ValueConverterDefinition[] SampleConverters() =>
    [
        new ValueConverterDefinition
        {
            Id = 1,
            Name = "CountToLabel",
            ManagedNamespace = "Avalonia.Rust.Sample.Generated",
            ValueKind = ViewModelValueKind.Integer,
            ResultKind = ViewModelValueKind.String,
            SupportsConvertBack = false,
        },
    ];
}
