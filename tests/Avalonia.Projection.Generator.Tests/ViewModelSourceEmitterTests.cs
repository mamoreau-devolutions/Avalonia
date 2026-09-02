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
    public void Emits_named_immutable_batch_builders_without_application_raw_ids()
    {
        var rust = ViewModelSourceEmitter.EmitRust(SampleIr());
        var csharp = ViewModelSourceEmitter.EmitCSharp(SampleIr())["SampleViewModelAdapter.g.cs"];

        Assert.Contains("pub fn batch(&self, generation: i64) -> SampleViewModelSinkBatch", rust, StringComparison.Ordinal);
        Assert.Contains("pub fn replace_items_snapshot", rust, StringComparison.Ordinal);
        Assert.Contains("pub fn submit_batch(&self, batch: SampleViewModelSinkBatch)", rust, StringComparison.Ordinal);
        Assert.Contains("IAvnRustVmSink3", csharp, StringComparison.Ordinal);
        Assert.Contains("IRustVmStringSnapshotSink", csharp, StringComparison.Ordinal);
        Assert.Contains("ReplaceStringSnapshot", csharp, StringComparison.Ordinal);
    }

    [Fact]
    public void Emits_the_full_batch_operation_surface_for_both_collection_element_kinds()
    {
        var rust = ViewModelSourceEmitter.EmitRust(SampleIr());

        // String collections: every managed-validated collection operation is
        // reachable from a named builder, including clear.
        Assert.Contains("pub fn insert_items(&mut self, index: i32, value: impl AsRef<str>) { self.0.push_string(9, 1, index, value); }", rust, StringComparison.Ordinal);
        Assert.Contains("pub fn replace_items(&mut self, index: i32, value: impl AsRef<str>) { self.0.push_string(11, 1, index, value); }", rust, StringComparison.Ordinal);
        Assert.Contains("pub fn remove_items(&mut self, index: i32) { self.0.push_indices(13, 1, index, 0); }", rust, StringComparison.Ordinal);
        Assert.Contains("pub fn move_items(&mut self, from_index: i32, to_index: i32) { self.0.push_indices(14, 1, from_index, to_index); }", rust, StringComparison.Ordinal);
        Assert.Contains("pub fn clear_items(&mut self) { self.0.push_indices(19, 1, 0, 0); }", rust, StringComparison.Ordinal);

        // Nested-model collections additionally carry an ownership delta.
        Assert.Contains("pub fn insert_tasks(&mut self, index: i32, value: impl TaskItemViewModel) { self.0.push_model(10, 2, index,", rust, StringComparison.Ordinal);
        Assert.Contains("pub fn replace_tasks(&mut self, index: i32, value: impl TaskItemViewModel) { self.0.push_model(12, 2, index,", rust, StringComparison.Ordinal);
        Assert.Contains("pub fn remove_tasks(&mut self, index: i32) { self.0.push_model_indices(13, 2, index, 0); }", rust, StringComparison.Ordinal);
        Assert.Contains("pub fn clear_tasks(&mut self) { self.0.push_model_clear(2); }", rust, StringComparison.Ordinal);

        // Clearing an error is a distinct wire shape from an empty message.
        Assert.Contains("pub fn clear_count_error(&mut self) { self.0.push_clear_error(2); }", rust, StringComparison.Ordinal);
    }

    [Fact]
    public void Emits_a_batch_target_implementation_instead_of_a_bespoke_adapter_engine()
    {
        var csharp = ViewModelSourceEmitter.EmitCSharp(SampleIr())["SampleViewModelAdapter.g.cs"];

        // The adapter only describes itself and performs notification-free
        // stores; the shared coordinator owns validation, staging and ordering.
        Assert.Contains("IRustVmBatchTarget", csharp, StringComparison.Ordinal);
        Assert.Contains("private readonly RustVmBatchCoordinator _batch;", csharp, StringComparison.Ordinal);
        Assert.Contains("_batch = new RustVmBatchCoordinator(this, post);", csharp, StringComparison.Ordinal);
        Assert.Contains("bool IRustVmBatchTarget.TryGetProperty(int propertyId, out RustVmBatchProperty property)", csharp, StringComparison.Ordinal);
        Assert.Contains("bool IRustVmBatchTarget.TryGetCollection(int collectionId, out RustVmBatchCollectionInfo collection)", csharp, StringComparison.Ordinal);
        Assert.Contains("bool IRustVmBatchTarget.TryGetCommand(int commandId, out IRustVmBatchCommand command)", csharp, StringComparison.Ordinal);
        Assert.Contains("IDisposable IRustVmBatchTarget.CreateNestedElement(int collectionId, IAvnRustViewModel model)", csharp, StringComparison.Ordinal);
        Assert.Contains("bool IRustVmBatchTarget.CommitProperty(int propertyId, in RustVmBatchValue value, out IDisposable? replaced)", csharp, StringComparison.Ordinal);
        Assert.Contains("2 => new RustVmBatchCollectionInfo(nameof(Tasks), RustVmValueWireKind.Model, Tasks),", csharp, StringComparison.Ordinal);
        Assert.Contains("public int SubmitBatch(IAvnRustVmUpdateBatch? batch) => _batch.Submit(batch);", csharp, StringComparison.Ordinal);

        // Disposal goes through the non-reentrant gate rather than a raw flag.
        Assert.Contains("public void Dispose() => _batch.Dispose(DisposeCore);", csharp, StringComparison.Ordinal);
        Assert.Contains("if (_batch.IsClosed) return 0;", csharp, StringComparison.Ordinal);
        Assert.DoesNotContain("private int _disposed;", csharp, StringComparison.Ordinal);
        Assert.DoesNotContain("RustVmBatchSubmission", csharp, StringComparison.Ordinal);

        // Commands expose the notification-free batch surface.
        Assert.Contains("public sealed class DelegateCommand(Action execute) : ICommand, IRustVmBatchCommand", csharp, StringComparison.Ordinal);
        Assert.Contains("public bool SetEnabledCore(bool enabled)", csharp, StringComparison.Ordinal);
    }

    [Fact]
    public void Emits_distinct_constructor_overloads_rather_than_optional_parameters()
    {
        var csharp = ViewModelSourceEmitter.EmitCSharp(SampleIr())["SampleViewModelAdapter.g.cs"];

        // Optional parameters do not preserve CLR constructor signatures, so
        // every arity is emitted as its own overload for already-compiled callers.
        Assert.Contains(
            "public SampleViewModelAdapter(IAvnRustViewModel model) : this(model, null, null) { }",
            csharp,
            StringComparison.Ordinal);
        Assert.Contains(
            "public SampleViewModelAdapter(IAvnRustViewModel model, Action<Action>? dispatch) : this(model, dispatch, null) { }",
            csharp,
            StringComparison.Ordinal);
        Assert.Contains(
            "public SampleViewModelAdapter(IAvnRustViewModel model, Action<Action>? dispatch, Action<Action>? post)",
            csharp,
            StringComparison.Ordinal);
        Assert.DoesNotContain("Action<Action>? dispatch = null", csharp, StringComparison.Ordinal);
    }

    [Fact]
    public void Emits_exact_wire_kind_nullability_and_enum_domain_metadata_for_every_property()
    {
        var ir = new ViewModelIr
        {
            Models =
            [
                new ViewModelDefinition
                {
                    Id = 1,
                    Name = "SampleViewModel",
                    ManagedNamespace = "Avalonia.Rust.Sample.Generated",
                    Properties =
                    [
                        new ViewModelProperty { Id = 1, Name = "Name", Kind = ViewModelValueKind.String },
                        new ViewModelProperty { Id = 2, Name = "Nickname", Kind = ViewModelValueKind.String, Nullable = true },
                        new ViewModelProperty { Id = 3, Name = "Priority", Kind = ViewModelValueKind.Enum, EnumName = "Priority", InitialInteger = 0L },
                        new ViewModelProperty { Id = 4, Name = "Nested", Kind = ViewModelValueKind.Model, ModelName = "TaskItemViewModel", Nullable = true },
                    ],
                },
                new ViewModelDefinition
                {
                    Id = 2,
                    Name = "TaskItemViewModel",
                    ManagedNamespace = "Avalonia.Rust.Sample.Generated",
                },
            ],
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
            Enums =
            [
                new ViewModelEnumDefinition
                {
                    Id = 1,
                    Name = "Priority",
                    ManagedNamespace = "Avalonia.Rust.Sample.Generated",
                    Members = [new ViewModelEnumMember { Name = "Low", Value = 0 }],
                },
            ],
        };

        var csharp = ViewModelSourceEmitter.EmitCSharp(ir)["SampleViewModelAdapter.g.cs"];

        Assert.Contains("1 => new RustVmBatchProperty(nameof(Name), RustVmValueWireKind.String, false, false),", csharp, StringComparison.Ordinal);
        Assert.Contains("2 => new RustVmBatchProperty(nameof(Nickname), RustVmValueWireKind.String, true, false),", csharp, StringComparison.Ordinal);
        Assert.Contains("3 => new RustVmBatchProperty(nameof(Priority), RustVmValueWireKind.Integer, false, true),", csharp, StringComparison.Ordinal);
        // A nested model property is always clearable through SetNull.
        Assert.Contains("4 => new RustVmBatchProperty(nameof(Nested), RustVmValueWireKind.Model, true, false),", csharp, StringComparison.Ordinal);
        Assert.Contains(
            "3 => global::System.Enum.IsDefined(typeof(global::Avalonia.Rust.Sample.Generated.Priority), value),",
            csharp,
            StringComparison.Ordinal);

        // Rust gains a matching named clear for the nested-model property.
        Assert.Contains("pub fn clear_nested(&mut self) { self.0.push_model_null(4); }", ViewModelSourceEmitter.EmitRust(ir), StringComparison.Ordinal);
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
