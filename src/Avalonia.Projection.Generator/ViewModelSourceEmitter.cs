using System.Globalization;
using System.Text;
using System.Text.Json;
using Avalonia.Projection.Ir;

namespace Avalonia.Projection.Generator;

public static class ViewModelSourceEmitter
{
    public static IReadOnlyDictionary<string, string> EmitCSharp(ViewModelIr ir)
    {
        ir.Validate();
        var files = new Dictionary<string, string>(StringComparer.Ordinal);
        foreach (var enumDefinition in ir.Enums)
            files[$"{enumDefinition.Name}.g.cs"] = EmitCSharpEnum(enumDefinition);
        foreach (var model in ir.Models)
        {
            files[$"{model.Name}Adapter.g.cs"] = EmitCSharpAdapter(ir, model);
            files[$"{model.Name}Metadata.g.cs"] = EmitCSharpMetadata(ir, model);
        }
        foreach (var converter in ir.Converters)
            files[$"{converter.Name}Converter.g.cs"] = EmitCSharpConverter(converter);
        files["RustViewRegistry.g.cs"] = EmitRegistry(ir);
        return files;
    }

    public static string EmitRust(ViewModelIr ir, bool externalConsumer = false)
    {
        ir.Validate();
        var sb = new StringBuilder(
            "//! Generated from view-model.ir.json. Do not edit.\n\n");
        if (externalConsumer)
            sb.AppendLine("#![allow(dead_code)]\n");
        foreach (var enumDefinition in ir.Enums)
            EmitRustEnum(sb, enumDefinition);
        foreach (var model in ir.Models)
            EmitRustModel(sb, ir, model, ir.Views.Where(view => view.Model == model.Name), externalConsumer);
        EmitRustConverters(sb, ir.Converters, externalConsumer);
        return sb.ToString().TrimEnd() + "\n";
    }

    public static string EmitContract(ViewModelIr ir)
    {
        ir.Validate();
        var sb = new StringBuilder();
        sb.AppendLine("# Generated Rust view-model contract");
        sb.AppendLine();
        sb.AppendLine($"Schema version: `{ir.Version}`");
        if (ir.Enums.Count > 0)
        {
            sb.AppendLine();
            sb.AppendLine("## Enums");
            sb.AppendLine();
            sb.AppendLine("| ID | Name | Members |");
            sb.AppendLine("| ---: | --- | --- |");
            foreach (var enumDefinition in ir.Enums)
            {
                var members = string.Join(", ", enumDefinition.Members.Select(member => $"`{member.Name}` = {member.Value}"));
                sb.AppendLine($"| {enumDefinition.Id} | `{enumDefinition.Name}` | {members} |");
            }
        }
        foreach (var model in ir.Models)
        {
            sb.AppendLine();
            sb.AppendLine($"## Model `{model.Name}` (`{model.Id}`)");
            sb.AppendLine();
            sb.AppendLine("| Kind | ID | Name | Type | Direction |");
            sb.AppendLine("| --- | ---: | --- | --- | --- |");
            foreach (var property in model.Properties)
            {
                var type = property.Kind switch
                {
                    ViewModelValueKind.Enum => $"Enum `{property.EnumName}`",
                    ViewModelValueKind.Model => $"Model `{property.ModelName}`",
                    _ => $"`{property.Kind}`",
                };
                var nullable = property.Nullable ? ", nullable" : "";
                var direction = property.Kind == ViewModelValueKind.Model
                    ? "Rust to managed"
                    : property.Writable ? "Rust and managed" : "Rust to managed";
                sb.AppendLine($"| Property | {property.Id} | `{property.Name}` | {type}{nullable} | {direction} |");
            }
            foreach (var collection in model.Collections)
            {
                var type = collection.ElementKind == ViewModelValueKind.Model
                    ? $"Model `{collection.ElementModelName}`"
                    : $"`{collection.ElementKind}`";
                sb.AppendLine($"| Collection | {collection.Id} | `{collection.Name}` | {type} | Rust to managed |");
            }
            foreach (var command in model.Commands)
            {
                var parameter = command.ParameterProperty is null
                    ? "None"
                    : $"`{command.ParameterProperty}`";
                sb.AppendLine($"| {(command.IsAsync ? "Async command" : "Command")} | {command.Id} | `{command.Name}` | {parameter} | Managed to Rust |");
            }
        }
        if (ir.Converters.Count > 0)
        {
            sb.AppendLine();
            sb.AppendLine("## Value converters");
            sb.AppendLine();
            sb.AppendLine("| ID | Name | Value | Parameter | Result | ConvertBack | Used by |");
            sb.AppendLine("| ---: | --- | --- | --- | --- | --- | --- |");
            foreach (var converter in ir.Converters)
            {
                var parameter = converter.ParameterKind is { } parameterKind ? $"`{parameterKind}`" : "None";
                var usedBy = ir.Views.Where(view => view.Converters.Contains(converter.Name)).Select(view => view.Name).ToArray();
                var usedByText = usedBy.Length == 0 ? "-" : string.Join(", ", usedBy.Select(name => $"`{name}`"));
                sb.AppendLine(
                    $"| {converter.Id} | `{converter.Name}` | `{converter.ValueKind}` | {parameter} | `{converter.ResultKind}` | {(converter.SupportsConvertBack ? "Yes" : "No")} | {usedByText} |");
            }
        }
        if (ir.Views.Count > 0)
        {
            sb.AppendLine();
            sb.AppendLine("## Views");
            sb.AppendLine();
            sb.AppendLine("| ID | Name | Model | Managed type | Binding path |");
            sb.AppendLine("| ---: | --- | --- | --- | --- |");
            foreach (var view in ir.Views)
                sb.AppendLine(
                    $"| {view.Id} | `{view.Name}` | `{view.Model}` | `{view.ManagedTypeName}` | {(view.DynamicBindings ? "Dynamic Rust metadata" : "Generated CLR properties")} |");
        }
        return sb.ToString();
    }

    private static string EmitCSharpAdapter(ViewModelIr ir, ViewModelDefinition model)
    {
        var sb = new StringBuilder();
        sb.AppendLine("// <auto-generated />");
        sb.AppendLine("#nullable enable");
        sb.AppendLine("using System;");
        sb.AppendLine("using System.Collections;");
        sb.AppendLine("using System.Collections.Generic;");
        sb.AppendLine("using System.Collections.ObjectModel;");
        sb.AppendLine("using System.ComponentModel;");
        sb.AppendLine("using System.Runtime.CompilerServices;");
        sb.AppendLine("using System.Runtime.InteropServices;");
        sb.AppendLine("using System.Runtime.InteropServices.Marshalling;");
        sb.AppendLine("using System.Threading;");
        sb.AppendLine("using System.Windows.Input;");
        sb.AppendLine("using Avalonia.Rust.Interop;");
        sb.AppendLine("using Avalonia.Threading;");
        sb.AppendLine();
        sb.AppendLine($"namespace {model.ManagedNamespace};");
        sb.AppendLine();
        sb.AppendLine("[GeneratedComClass]");
        sb.AppendLine($"public sealed partial class {model.Name}Adapter : IAvnRustVmSink, IAvnRustVmSink2, INotifyPropertyChanged, INotifyDataErrorInfo, IDisposable");
        sb.AppendLine("{");
        sb.AppendLine("    private readonly IAvnRustViewModel _model;");
        sb.AppendLine("    private readonly Action<Action> _dispatch;");
        sb.AppendLine("    private readonly Dictionary<string, string> _errors = new(StringComparer.Ordinal);");
        sb.AppendLine("    private int _disposed;");
        foreach (var property in model.Properties)
            sb.AppendLine($"    private {CSharpType(ir, property)} _{Lower(property.Name)} = {CSharpInitial(ir, property)};");
        sb.AppendLine();
        sb.AppendLine($"    public {model.Name}Adapter(IAvnRustViewModel model, Action<Action>? dispatch = null)");
        sb.AppendLine("    {");
        sb.AppendLine("        _model = model;");
        sb.AppendLine("        _dispatch = dispatch ?? Dispatch;");
        foreach (var command in model.Commands)
        {
            var invocation = command.IsAsync ? "BeginAsync" : "Execute";
            var parameter = command.ParameterProperty is null
                ? "null"
                : command.ParameterProperty;
            sb.AppendLine($"        {command.Name}Command = new DelegateCommand(() => Check(_model.{invocation}({command.Id}, {parameter})));");
        }
        sb.AppendLine("        try");
        sb.AppendLine("        {");
        sb.AppendLine("            Check(_model.Attach(this));");
        sb.AppendLine("        }");
        sb.AppendLine("        catch");
        sb.AppendLine("        {");
        sb.AppendLine("            try { _model.Detach(); }");
        sb.AppendLine("            catch { }");
        sb.AppendLine("            DisposeNestedAdapters();");
        sb.AppendLine("            throw;");
        sb.AppendLine("        }");
        sb.AppendLine("    }");
        sb.AppendLine();
        sb.AppendLine("    public event PropertyChangedEventHandler? PropertyChanged;");
        sb.AppendLine("    public event EventHandler<DataErrorsChangedEventArgs>? ErrorsChanged;");
        sb.AppendLine();
        foreach (var property in model.Properties)
        {
            sb.AppendLine($"    public {CSharpType(ir, property)} {property.Name}");
            sb.AppendLine("    {");
            sb.AppendLine($"        get => _{Lower(property.Name)};");
            if (property.Writable)
            {
                sb.AppendLine("        set");
                sb.AppendLine("        {");
                sb.AppendLine($"            if (Equals(_{Lower(property.Name)}, value))");
                sb.AppendLine("                return;");
                sb.AppendLine($"            Check(_model.Set{TransportSuffix(WireKind(property.Kind))}({property.Id}, {CSharpToTransport(property, "value")}));");
                sb.AppendLine("        }");
            }
            sb.AppendLine("    }");
            sb.AppendLine();
        }
        foreach (var collection in model.Collections)
            sb.AppendLine($"    public ObservableCollection<{CSharpElementType(ir, collection.ElementKind, collection.ElementModelName)}> {collection.Name} {{ get; }} = [];");
        if (model.Collections.Count > 0)
            sb.AppendLine();
        foreach (var command in model.Commands)
            sb.AppendLine($"    public DelegateCommand {command.Name}Command {{ get; }}");
        sb.AppendLine();
        sb.AppendLine("    public bool HasErrors => _errors.Count > 0;");
        sb.AppendLine();
        sb.AppendLine("    public IEnumerable GetErrors(string? propertyName) =>");
        sb.AppendLine("        propertyName is not null && _errors.TryGetValue(propertyName, out var message)");
        sb.AppendLine("            ? new[] { message }");
        sb.AppendLine("            : Array.Empty<string>();");
        sb.AppendLine();
        EmitCSharpSinkMethods(sb, ir, model);
        sb.AppendLine("    public void Dispose()");
        sb.AppendLine("    {");
        sb.AppendLine("        if (Interlocked.Exchange(ref _disposed, 1) == 0)");
        sb.AppendLine("        {");
        sb.AppendLine("            try");
        sb.AppendLine("            {");
        sb.AppendLine("                Check(_model.Detach());");
        sb.AppendLine("            }");
        sb.AppendLine("            finally");
        sb.AppendLine("            {");
        sb.AppendLine("                DisposeNestedAdapters();");
        sb.AppendLine("            }");
        sb.AppendLine("        }");
        sb.AppendLine("    }");
        sb.AppendLine();
        sb.AppendLine("    private void DisposeNestedAdapters()");
        sb.AppendLine("    {");
        foreach (var property in model.Properties.Where(property => property.Kind == ViewModelValueKind.Model))
            sb.AppendLine($"        TryDispose(_{Lower(property.Name)});");
        foreach (var collection in model.Collections.Where(collection => collection.ElementKind == ViewModelValueKind.Model))
            sb.AppendLine($"        foreach (var item in {collection.Name}) TryDispose(item);");
        sb.AppendLine("    }");
        sb.AppendLine();
        sb.AppendLine("    private static void TryDispose(IDisposable? value)");
        sb.AppendLine("    {");
        sb.AppendLine("        try { value?.Dispose(); }");
        sb.AppendLine("        catch { }");
        sb.AppendLine("    }");
        sb.AppendLine();
        sb.AppendLine("    private int Apply(Action action) => Apply(() =>");
        sb.AppendLine("    {");
        sb.AppendLine("        action();");
        sb.AppendLine("        return 0;");
        sb.AppendLine("    });");
        sb.AppendLine();
        sb.AppendLine("    private int Apply(Func<int> action)");
        sb.AppendLine("    {");
        sb.AppendLine("        if (Volatile.Read(ref _disposed) != 0) return 0;");
        sb.AppendLine("        var hresult = 0;");
        sb.AppendLine("        void ApplyIfAlive()");
        sb.AppendLine("        {");
        sb.AppendLine("            if (Volatile.Read(ref _disposed) == 0)");
        sb.AppendLine("            {");
        sb.AppendLine("                try { hresult = action(); }");
        sb.AppendLine("                catch { hresult = unchecked((int)0x80004005); }");
        sb.AppendLine("            }");
        sb.AppendLine("        }");
        sb.AppendLine("        try { _dispatch(ApplyIfAlive); }");
        sb.AppendLine("        catch { return unchecked((int)0x80004005); }");
        sb.AppendLine("        return hresult;");
        sb.AppendLine("    }");
        sb.AppendLine();
        sb.AppendLine("    private static void Dispatch(Action action)");
        sb.AppendLine("    {");
        sb.AppendLine("        if (Dispatcher.UIThread.CheckAccess()) action();");
        sb.AppendLine("        else Dispatcher.UIThread.Invoke(action);");
        sb.AppendLine("    }");
        sb.AppendLine();
        sb.AppendLine("    private static void Check(int hresult)");
        sb.AppendLine("    {");
        sb.AppendLine("        if (hresult < 0) Marshal.ThrowExceptionForHR(hresult);");
        sb.AppendLine("    }");
        sb.AppendLine();
        sb.AppendLine("    private void SetField<T>(ref T field, T value, [CallerMemberName] string? propertyName = null)");
        sb.AppendLine("    {");
        sb.AppendLine("        if (Equals(field, value)) return;");
        sb.AppendLine("        field = value;");
        sb.AppendLine("        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));");
        sb.AppendLine("    }");
        sb.AppendLine();
        sb.AppendLine("    private void SetError(string propertyName, string? message)");
        sb.AppendLine("    {");
        sb.AppendLine("        if (message is null)");
        sb.AppendLine("        {");
        sb.AppendLine("            if (_errors.Remove(propertyName))");
        sb.AppendLine("                ErrorsChanged?.Invoke(this, new DataErrorsChangedEventArgs(propertyName));");
        sb.AppendLine("        }");
        sb.AppendLine("        else");
        sb.AppendLine("        {");
        sb.AppendLine("            _errors[propertyName] = message;");
        sb.AppendLine("            ErrorsChanged?.Invoke(this, new DataErrorsChangedEventArgs(propertyName));");
        sb.AppendLine("        }");
        sb.AppendLine("    }");
        sb.AppendLine();
        sb.AppendLine("    public sealed class DelegateCommand(Action execute) : ICommand");
        sb.AppendLine("    {");
        sb.AppendLine("        private bool _canExecute = true;");
        sb.AppendLine();
        sb.AppendLine("        public event EventHandler? CanExecuteChanged;");
        sb.AppendLine("        public bool CanExecute(object? parameter) => _canExecute;");
        sb.AppendLine("        public void Execute(object? parameter) => execute();");
        sb.AppendLine();
        sb.AppendLine("        public void SetEnabled(bool value)");
        sb.AppendLine("        {");
        sb.AppendLine("            if (_canExecute == value) return;");
        sb.AppendLine("            _canExecute = value;");
        sb.AppendLine("            CanExecuteChanged?.Invoke(this, EventArgs.Empty);");
        sb.AppendLine("        }");
        sb.AppendLine("    }");
        sb.AppendLine("}");
        return sb.ToString();
    }

    private static void EmitCSharpSinkMethods(StringBuilder sb, ViewModelIr ir, ViewModelDefinition model)
    {
        foreach (var wireKind in ScalarWireKinds)
        {
            var properties = model.Properties.Where(property => WireKind(property.Kind) == wireKind).ToArray();
            sb.AppendLine($"    public int Set{TransportSuffix(wireKind)}(int propertyId, {CSharpTransportType(wireKind)} value) => propertyId switch");
            sb.AppendLine("    {");
            foreach (var property in properties)
            {
                if (property.Kind == ViewModelValueKind.Enum)
                {
                    var enumType = CSharpEnumTypeName(ir, property.EnumName!);
                    sb.AppendLine(
                        $"        {property.Id} => !global::System.Enum.IsDefined(typeof({enumType}), value) ? unchecked((int)0x80070057) : Apply(() => SetField(ref _{Lower(property.Name)}, {CSharpFromTransport(ir, property, "value")}, nameof({property.Name}))),");
                }
                else
                {
                    sb.AppendLine($"        {property.Id} => Apply(() => SetField(ref _{Lower(property.Name)}, {CSharpFromTransport(ir, property, "value")}, nameof({property.Name}))),");
                }
            }
            sb.AppendLine("        _ => unchecked((int)0x80070057),");
            sb.AppendLine("    };");
            sb.AppendLine();
        }

        var nullableProperties = model.Properties.Where(property => property.Nullable && property.Kind != ViewModelValueKind.Model).ToArray();
        sb.AppendLine("    public int SetNull(int propertyId) => propertyId switch");
        sb.AppendLine("    {");
        foreach (var property in nullableProperties)
            sb.AppendLine($"        {property.Id} => Apply(() => SetField(ref _{Lower(property.Name)}, null, nameof({property.Name}))),");
        sb.AppendLine("        _ => unchecked((int)0x80070057),");
        sb.AppendLine("    };");
        sb.AppendLine();

        var modelProperties = model.Properties.Where(property => property.Kind == ViewModelValueKind.Model).ToArray();
        sb.AppendLine("    public int SetModel(int propertyId, IAvnRustViewModel? model) => propertyId switch");
        sb.AppendLine("    {");
        foreach (var property in modelProperties)
        {
            var adapterType = CSharpModelAdapterTypeName(ir, property.ModelName!);
            sb.AppendLine($"        {property.Id} => Apply(() =>");
            sb.AppendLine("        {");
            sb.AppendLine($"            var previous = _{Lower(property.Name)};");
            sb.AppendLine($"            _{Lower(property.Name)} = model is null ? null : new {adapterType}(model, _dispatch);");
            sb.AppendLine($"            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof({property.Name})));");
            sb.AppendLine("            previous?.Dispose();");
            sb.AppendLine("        }),");
        }
        sb.AppendLine("        _ => unchecked((int)0x80070057),");
        sb.AppendLine("    };");
        sb.AppendLine();

        var modelCollections = model.Collections.Where(collection => collection.ElementKind == ViewModelValueKind.Model).ToArray();
        var stringCollections = model.Collections.Where(collection => collection.ElementKind == ViewModelValueKind.String).ToArray();

        sb.AppendLine("    public int AddModel(int collectionId, IAvnRustViewModel? model) => collectionId switch");
        sb.AppendLine("    {");
        foreach (var collection in modelCollections)
        {
            var adapterType = CSharpModelAdapterTypeName(ir, collection.ElementModelName!);
            sb.AppendLine($"        {collection.Id} => model is null ? unchecked((int)0x80070057) : Apply(() => {collection.Name}.Add(new {adapterType}(model, _dispatch))),");
        }
        sb.AppendLine("        _ => unchecked((int)0x80070057),");
        sb.AppendLine("    };");
        sb.AppendLine();

        sb.AppendLine("    public int InsertString(int collectionId, int index, string? value) => collectionId switch");
        sb.AppendLine("    {");
        foreach (var collection in stringCollections)
            sb.AppendLine($"        {collection.Id} => Apply(() => {{ if ((uint)index > (uint){collection.Name}.Count) return unchecked((int)0x80070057); {collection.Name}.Insert(index, value ?? \"\"); return 0; }}),");
        sb.AppendLine("        _ => unchecked((int)0x80070057),");
        sb.AppendLine("    };");
        sb.AppendLine();

        sb.AppendLine("    public int InsertModel(int collectionId, int index, IAvnRustViewModel? model) => collectionId switch");
        sb.AppendLine("    {");
        foreach (var collection in modelCollections)
        {
            var adapterType = CSharpModelAdapterTypeName(ir, collection.ElementModelName!);
            sb.AppendLine($"        {collection.Id} => model is null ? unchecked((int)0x80070057) : Apply(() => {{ if ((uint)index > (uint){collection.Name}.Count) return unchecked((int)0x80070057); {collection.Name}.Insert(index, new {adapterType}(model, _dispatch)); return 0; }}),");
        }
        sb.AppendLine("        _ => unchecked((int)0x80070057),");
        sb.AppendLine("    };");
        sb.AppendLine();

        sb.AppendLine("    public int ReplaceString(int collectionId, int index, string? value) => collectionId switch");
        sb.AppendLine("    {");
        foreach (var collection in stringCollections)
            sb.AppendLine($"        {collection.Id} => Apply(() => {{ if ((uint)index >= (uint){collection.Name}.Count) return unchecked((int)0x80070057); {collection.Name}[index] = value ?? \"\"; return 0; }}),");
        sb.AppendLine("        _ => unchecked((int)0x80070057),");
        sb.AppendLine("    };");
        sb.AppendLine();

        sb.AppendLine("    public int ReplaceModel(int collectionId, int index, IAvnRustViewModel? model) => collectionId switch");
        sb.AppendLine("    {");
        foreach (var collection in modelCollections)
        {
            var adapterType = CSharpModelAdapterTypeName(ir, collection.ElementModelName!);
            sb.AppendLine($"        {collection.Id} => model is null ? unchecked((int)0x80070057) : Apply(() =>");
            sb.AppendLine("        {");
            sb.AppendLine($"            if ((uint)index >= (uint){collection.Name}.Count) return unchecked((int)0x80070057);");
            sb.AppendLine($"            var previous = {collection.Name}[index];");
            sb.AppendLine($"            {collection.Name}[index] = new {adapterType}(model, _dispatch);");
            sb.AppendLine("            previous.Dispose();");
            sb.AppendLine("            return 0;");
            sb.AppendLine("        }),");
        }
        sb.AppendLine("        _ => unchecked((int)0x80070057),");
        sb.AppendLine("    };");
        sb.AppendLine();

        sb.AppendLine("    public int RemoveAt(int collectionId, int index) => collectionId switch");
        sb.AppendLine("    {");
        foreach (var collection in stringCollections)
            sb.AppendLine($"        {collection.Id} => Apply(() => {{ if ((uint)index >= (uint){collection.Name}.Count) return unchecked((int)0x80070057); {collection.Name}.RemoveAt(index); return 0; }}),");
        foreach (var collection in modelCollections)
        {
            sb.AppendLine($"        {collection.Id} => Apply(() =>");
            sb.AppendLine("        {");
            sb.AppendLine($"            if ((uint)index >= (uint){collection.Name}.Count) return unchecked((int)0x80070057);");
            sb.AppendLine($"            var item = {collection.Name}[index];");
            sb.AppendLine($"            {collection.Name}.RemoveAt(index);");
            sb.AppendLine("            item.Dispose();");
            sb.AppendLine("            return 0;");
            sb.AppendLine("        }),");
        }
        sb.AppendLine("        _ => unchecked((int)0x80070057),");
        sb.AppendLine("    };");
        sb.AppendLine();

        sb.AppendLine("    public int MoveItem(int collectionId, int fromIndex, int toIndex) => collectionId switch");
        sb.AppendLine("    {");
        foreach (var collection in model.Collections)
            sb.AppendLine($"        {collection.Id} => Apply(() => {{ if ((uint)fromIndex >= (uint){collection.Name}.Count || (uint)toIndex >= (uint){collection.Name}.Count) return unchecked((int)0x80070057); {collection.Name}.Move(fromIndex, toIndex); return 0; }}),");
        sb.AppendLine("        _ => unchecked((int)0x80070057),");
        sb.AppendLine("    };");
        sb.AppendLine();

        sb.AppendLine("    public int ClearCollection(int collectionId) => collectionId switch");
        sb.AppendLine("    {");
        foreach (var collection in stringCollections)
            sb.AppendLine($"        {collection.Id} => Apply({collection.Name}.Clear),");
        foreach (var collection in modelCollections)
        {
            sb.AppendLine($"        {collection.Id} => Apply(() =>");
            sb.AppendLine("        {");
            sb.AppendLine($"            foreach (var item in {collection.Name}) item.Dispose();");
            sb.AppendLine($"            {collection.Name}.Clear();");
            sb.AppendLine("        }),");
        }
        sb.AppendLine("        _ => unchecked((int)0x80070057),");
        sb.AppendLine("    };");
        sb.AppendLine();

        sb.AppendLine("    public int SetCommandEnabled(int commandId, int enabled) => commandId switch");
        sb.AppendLine("    {");
        foreach (var command in model.Commands)
            sb.AppendLine($"        {command.Id} => Apply(() => {command.Name}Command.SetEnabled(enabled != 0)),");
        sb.AppendLine("        _ => unchecked((int)0x80070057),");
        sb.AppendLine("    };");
        sb.AppendLine();

        sb.AppendLine("    public int SetPropertyError(int propertyId, string? message) => propertyId switch");
        sb.AppendLine("    {");
        foreach (var property in model.Properties)
            sb.AppendLine($"        {property.Id} => Apply(() => SetError(nameof({property.Name}), message)),");
        sb.AppendLine("        _ => unchecked((int)0x80070057),");
        sb.AppendLine("    };");
        sb.AppendLine();

        sb.AppendLine("    public int AddString(int collectionId, string? value) => collectionId switch");
        sb.AppendLine("    {");
        foreach (var collection in stringCollections)
            sb.AppendLine($"        {collection.Id} => Apply(() => {collection.Name}.Add(value ?? \"\")),");
        sb.AppendLine("        _ => unchecked((int)0x80070057),");
        sb.AppendLine("    };");
        sb.AppendLine();
    }

    private static string EmitCSharpMetadata(ViewModelIr ir, ViewModelDefinition model)
    {
        var sb = new StringBuilder();
        sb.AppendLine("// <auto-generated />");
        sb.AppendLine("#nullable enable");
        sb.AppendLine("using Avalonia.Rust;");
        sb.AppendLine();
        sb.AppendLine($"namespace {model.ManagedNamespace};");
        sb.AppendLine();
        sb.AppendLine($"public static class {model.Name}Metadata");
        sb.AppendLine("{");
        sb.AppendLine($"    public static RustViewModelDescriptor Descriptor {{ get; }} = new(");
        sb.AppendLine($"        {model.Id},");
        sb.AppendLine($"        {JsonSerializer.Serialize(model.Name)},");
        sb.AppendLine("        [");
        foreach (var property in model.Properties)
        {
            var nestedDescriptor = property.Kind == ViewModelValueKind.Model
                ? $"{CSharpModelMetadataTypeName(ir, property.ModelName!)}.Descriptor"
                : "null";
            sb.AppendLine(
                $"            new({property.Id}, {JsonSerializer.Serialize(property.Name)}, RustViewModelValueKind.{property.Kind}, {property.Writable.ToString().ToLowerInvariant()}, {property.Nullable.ToString().ToLowerInvariant()}, {CSharpInitial(ir, property)}, {nestedDescriptor}),");
        }
        sb.AppendLine("        ],");
        sb.AppendLine("        [");
        foreach (var collection in model.Collections)
        {
            var elementDescriptor = collection.ElementKind == ViewModelValueKind.Model
                ? $"{CSharpModelMetadataTypeName(ir, collection.ElementModelName!)}.Descriptor"
                : "null";
            sb.AppendLine($"            new({collection.Id}, {JsonSerializer.Serialize(collection.Name)}, RustViewModelValueKind.{collection.ElementKind}, {elementDescriptor}),");
        }
        sb.AppendLine("        ],");
        sb.AppendLine("        [");
        foreach (var command in model.Commands)
        {
            var parameter = command.ParameterProperty is null
                ? "null"
                : JsonSerializer.Serialize(command.ParameterProperty);
            sb.AppendLine(
                $"            new({command.Id}, {JsonSerializer.Serialize(command.Name + "Command")}, {command.IsAsync.ToString().ToLowerInvariant()}, {parameter}),");
        }
        sb.AppendLine("        ]);");
        sb.AppendLine("}");
        return sb.ToString();
    }

    private static string EmitRegistry(ViewModelIr ir)
    {
        var sb = new StringBuilder();
        sb.AppendLine("// <auto-generated />");
        sb.AppendLine("#nullable enable");
        sb.AppendLine("using System;");
        sb.AppendLine("using Avalonia.Controls;");
        sb.AppendLine("using Avalonia.Rust;");
        sb.AppendLine("using Avalonia.Rust.Interop;");
        sb.AppendLine("using Avalonia.Threading;");
        sb.AppendLine();
        sb.AppendLine("namespace Avalonia.Host.Generated.ViewModels;");
        sb.AppendLine();
        sb.AppendLine("internal static class RustViewRegistry");
        sb.AppendLine("{");
        sb.AppendLine("    internal static Window Create(int viewId, IAvnRustViewModel model) => viewId switch");
        sb.AppendLine("    {");
        foreach (var view in ir.Views)
        {
            var model = ir.Models.Single(model => model.Name == view.Model);
            if (view.DynamicBindings)
            {
                sb.AppendLine(
                    $"        {view.Id} => CreateDynamic<global::{view.ManagedTypeName}>(model, global::{model.ManagedNamespace}.{model.Name}Metadata.Descriptor),");
            }
            else
            {
                sb.AppendLine($"        {view.Id} => new global::{view.ManagedTypeName}(model),");
            }
        }
        sb.AppendLine("        _ => throw new global::System.ArgumentOutOfRangeException(nameof(viewId)),");
        sb.AppendLine("    };");
        sb.AppendLine();
        sb.AppendLine("    private static TWindow CreateDynamic<TWindow>(");
        sb.AppendLine("        IAvnRustViewModel model,");
        sb.AppendLine("        RustViewModelDescriptor descriptor)");
        sb.AppendLine("        where TWindow : Window, new()");
        sb.AppendLine("    {");
        sb.AppendLine("        var adapter = new ReflectableRustViewModelAdapter(model, descriptor, Dispatch);");
        sb.AppendLine("        try");
        sb.AppendLine("        {");
        sb.AppendLine("            var window = new TWindow { DataContext = adapter };");
        sb.AppendLine("            window.Closed += (_, _) => adapter.Dispose();");
        sb.AppendLine("            return window;");
        sb.AppendLine("        }");
        sb.AppendLine("        catch");
        sb.AppendLine("        {");
        sb.AppendLine("            adapter.Dispose();");
        sb.AppendLine("            throw;");
        sb.AppendLine("        }");
        sb.AppendLine("    }");
        sb.AppendLine();
        sb.AppendLine("    private static void Dispatch(Action action)");
        sb.AppendLine("    {");
        sb.AppendLine("        if (Dispatcher.UIThread.CheckAccess())");
        sb.AppendLine("            action();");
        sb.AppendLine("        else");
        sb.AppendLine("            Dispatcher.UIThread.Invoke(action);");
        sb.AppendLine("    }");
        sb.AppendLine("}");
        return sb.ToString();
    }

    private static void EmitRustModel(
        StringBuilder sb,
        ViewModelIr ir,
        ViewModelDefinition model,
        IEnumerable<ViewDefinition> views,
        bool externalConsumer)
    {
        var traitName = model.Name;
        var sinkName = $"{model.Name}Sink";
        var stringCollections = model.Collections.Where(collection => collection.ElementKind == ViewModelValueKind.String).ToArray();
        var modelCollections = model.Collections.Where(collection => collection.ElementKind == ViewModelValueKind.Model).ToArray();
        sb.AppendLine("#[derive(Clone, Debug)]");
        sb.AppendLine($"pub struct {sinkName}(crate::view_model::ViewModelSink);");
        sb.AppendLine();
        sb.AppendLine($"impl {sinkName} {{");
        foreach (var property in model.Properties)
            sb.AppendLine($"    pub fn {RustPropertySetterBody(property)}");
        foreach (var collection in stringCollections)
        {
            sb.AppendLine($"    pub fn add_{Snake(collection.Name)}(&self, value: impl AsRef<str>) -> crate::Result<()> {{ self.0.add_string({collection.Id}, value) }}");
            sb.AppendLine($"    pub fn insert_{Snake(collection.Name)}(&self, index: i32, value: impl AsRef<str>) -> crate::Result<()> {{ self.0.insert_string({collection.Id}, index, value) }}");
            sb.AppendLine($"    pub fn replace_{Snake(collection.Name)}(&self, index: i32, value: impl AsRef<str>) -> crate::Result<()> {{ self.0.replace_string({collection.Id}, index, value) }}");
        }
        foreach (var collection in modelCollections)
        {
            var elementTrait = collection.ElementModelName!;
            sb.AppendLine($"    pub fn add_{Snake(collection.Name)}(&self, value: impl {elementTrait}) -> crate::Result<()> {{ self.0.add_model({collection.Id}, {elementTrait}Dispatch {{ model: value }}) }}");
            sb.AppendLine($"    pub fn insert_{Snake(collection.Name)}(&self, index: i32, value: impl {elementTrait}) -> crate::Result<()> {{ self.0.insert_model({collection.Id}, index, {elementTrait}Dispatch {{ model: value }}) }}");
            sb.AppendLine($"    pub fn replace_{Snake(collection.Name)}(&self, index: i32, value: impl {elementTrait}) -> crate::Result<()> {{ self.0.replace_model({collection.Id}, index, {elementTrait}Dispatch {{ model: value }}) }}");
        }
        foreach (var collection in stringCollections)
        {
            sb.AppendLine($"    pub fn remove_{Snake(collection.Name)}(&self, index: i32) -> crate::Result<()> {{ self.0.remove_string_at({collection.Id}, index) }}");
            sb.AppendLine($"    pub fn move_{Snake(collection.Name)}(&self, from_index: i32, to_index: i32) -> crate::Result<()> {{ self.0.move_string_item({collection.Id}, from_index, to_index) }}");
            sb.AppendLine($"    pub fn clear_{Snake(collection.Name)}(&self) -> crate::Result<()> {{ self.0.clear_string_collection({collection.Id}) }}");
        }
        foreach (var collection in modelCollections)
        {
            sb.AppendLine($"    pub fn remove_{Snake(collection.Name)}(&self, index: i32) -> crate::Result<()> {{ self.0.remove_model_at({collection.Id}, index) }}");
            sb.AppendLine($"    pub fn move_{Snake(collection.Name)}(&self, from_index: i32, to_index: i32) -> crate::Result<()> {{ self.0.move_model_item({collection.Id}, from_index, to_index) }}");
            sb.AppendLine($"    pub fn clear_{Snake(collection.Name)}(&self) -> crate::Result<()> {{ self.0.clear_model_collection({collection.Id}) }}");
        }
        foreach (var command in model.Commands)
            sb.AppendLine($"    pub fn set_{Snake(command.Name)}_enabled(&self, enabled: bool) -> crate::Result<()> {{ self.0.set_command_enabled({command.Id}, enabled) }}");
        foreach (var property in model.Properties.Where(property => property.Kind != ViewModelValueKind.Model))
            sb.AppendLine($"    pub fn set_{Snake(property.Name)}_error(&self, message: Option<&str>) -> crate::Result<()> {{ self.0.set_property_error({property.Id}, message) }}");
        sb.AppendLine("}");
        sb.AppendLine();
        sb.AppendLine($"pub trait {traitName}: Send + 'static {{");
        sb.AppendLine($"    fn attach(&mut self, sink: {sinkName}) -> crate::Result<()>;");
        sb.AppendLine("    fn detach(&mut self) -> crate::Result<()>;");
        foreach (var property in model.Properties.Where(property => property.Writable))
            sb.AppendLine($"    fn set_{Snake(property.Name)}(&mut self, value: {RustPropertyType(ir, property)}) -> crate::Result<()>;");
        foreach (var command in model.Commands)
        {
            var parameter = command.ParameterProperty is null
                ? ""
                : $", value: {RustOwnedType(model.Properties.Single(property => property.Name == command.ParameterProperty).Kind)}";
            sb.AppendLine($"    fn {Snake(command.Name)}(&mut self{parameter}) -> crate::Result<()>;");
        }
        sb.AppendLine("}");
        sb.AppendLine();
        sb.AppendLine($"struct {traitName}Dispatch<T: {traitName}> {{ model: T }}");
        sb.AppendLine();
        sb.AppendLine($"impl<T: {traitName}> crate::view_model::DynamicViewModel for {traitName}Dispatch<T> {{");
        sb.AppendLine($"    fn attach(&mut self, sink: crate::view_model::ViewModelSink) -> crate::Result<()> {{ self.model.attach({sinkName}(sink)) }}");
        sb.AppendLine("    fn detach(&mut self) -> crate::Result<()> { self.model.detach() }");
        EmitRustPropertyDispatch(sb, model, ViewModelValueKind.String);
        EmitRustPropertyDispatch(sb, model, ViewModelValueKind.Integer);
        EmitRustPropertyDispatch(sb, model, ViewModelValueKind.Boolean);
        EmitRustPropertyDispatch(sb, model, ViewModelValueKind.Double);
        EmitRustCommandDispatch(sb, model, asyncCommands: false);
        EmitRustCommandDispatch(sb, model, asyncCommands: true);
        sb.AppendLine("}");
        sb.AppendLine();
        foreach (var view in views)
        {
            if (externalConsumer)
                sb.AppendLine($"pub fn mount_{Snake(view.Name)}(scope: &crate::AppScope, model: impl {traitName}) -> crate::Result<()> {{ scope.mount_dynamic_view_model({view.Id}, {traitName}Dispatch {{ model }}) }}");
            else
                sb.AppendLine($"impl crate::AppScope {{ pub fn mount_{Snake(view.Name)}(&self, model: impl {traitName}) -> crate::Result<()> {{ self.mount_dynamic_view_model({view.Id}, {traitName}Dispatch {{ model }}) }} }}");
            if (view.Converters.Count > 0)
            {
                if (externalConsumer)
                    sb.AppendLine($"pub fn mount_{Snake(view.Name)}_with_converters<C: ValueConverters>(");
                else
                {
                    sb.AppendLine("impl crate::AppScope {");
                    sb.AppendLine($"    pub fn mount_{Snake(view.Name)}_with_converters<C: ValueConverters>(");
                    sb.AppendLine("        &self,");
                }
                if (externalConsumer)
                    sb.AppendLine("    scope: &crate::AppScope,");
                sb.AppendLine($"        model: impl {traitName},");
                sb.AppendLine($"        converters: C,");
                sb.AppendLine($"    ) -> crate::Result<()> {{");
                sb.AppendLine(externalConsumer
                    ? "        register_value_converters(scope, converters)?;"
                    : "        self.register_value_converters(converters)?;");
                sb.AppendLine(externalConsumer
                    ? $"        mount_{Snake(view.Name)}(scope, model)"
                    : $"        self.mount_{Snake(view.Name)}(model)");
                sb.AppendLine($"    }}");
                if (!externalConsumer)
                    sb.AppendLine("}");
            }
        }
        sb.AppendLine();
    }

    /// <summary>
    /// Builds the named per-property sink setter method body for the
    /// `impl {Model}Sink` block. Covers non-nullable scalars (unchanged
    /// shape), nullable strings (`Option&lt;T&gt;` publishing `set_null` for
    /// `None`), enums (cast to the wire's `Integer` transport), and nested
    /// view-model properties (always `Option`, routed through the generic
    /// `set_model`).
    /// </summary>
    private static string RustPropertySetterBody(ViewModelProperty property)
    {
        var name = Snake(property.Name);
        return property.Kind switch
        {
            ViewModelValueKind.Model =>
                $"set_{name}<M: {property.ModelName}>(&self, value: Option<M>) -> crate::Result<()> {{ self.0.set_model({property.Id}, value.map(|model| {property.ModelName}Dispatch {{ model }})) }}",
            ViewModelValueKind.Enum when property.Nullable =>
                throw new InvalidOperationException("Nullable enum properties are not supported."),
            ViewModelValueKind.Enum =>
                $"set_{name}(&self, value: {property.EnumName}) -> crate::Result<()> {{ self.0.set_integer({property.Id}, value as i64) }}",
            ViewModelValueKind.String when property.Nullable =>
                $"set_{name}(&self, value: Option<impl AsRef<str>>) -> crate::Result<()> {{ match value {{ Some(value) => self.0.set_string({property.Id}, value), None => self.0.set_null({property.Id}) }} }}",
            _ =>
                $"set_{name}(&self, value: {RustInputType(property.Kind)}) -> crate::Result<()> {{ self.0.set_{Snake(TransportSuffix(property.Kind))}({property.Id}, value) }}",
        };
    }

    private static string RustPropertyType(ViewModelIr ir, ViewModelProperty property) => property.Kind switch
    {
        ViewModelValueKind.Enum => property.EnumName!,
        _ => RustOwnedType(property.Kind),
    };

    private static void EmitRustConverters(StringBuilder sb, IReadOnlyList<ValueConverterDefinition> converters, bool externalConsumer)
    {
        if (converters.Count == 0)
            return;

        var anyParameterUsed = converters.Any(converter => converter.ParameterKind is not null);
        var parameterName = anyParameterUsed ? "parameter" : "_parameter";

        sb.AppendLine("pub trait ValueConverters: Send + Sync + 'static {");
        foreach (var converter in converters)
        {
            var forwardParameter = converter.ParameterKind is { } forwardParameterKind
                ? $", parameter: {RustOwnedType(forwardParameterKind)}"
                : "";
            sb.AppendLine($"    fn {Snake(converter.Name)}(&self, value: {RustOwnedType(converter.ValueKind)}{forwardParameter}) -> {RustOwnedType(converter.ResultKind)};");
            if (converter.SupportsConvertBack)
            {
                var backParameter = converter.ParameterKind is { } backParameterKind
                    ? $", parameter: {RustOwnedType(backParameterKind)}"
                    : "";
                sb.AppendLine($"    fn {Snake(converter.Name)}_back(&self, value: {RustOwnedType(converter.ResultKind)}{backParameter}) -> {RustOwnedType(converter.ValueKind)};");
            }
        }
        sb.AppendLine("}");
        sb.AppendLine();
        sb.AppendLine("struct ValueConvertersDispatch<T: ValueConverters> { converters: T }");
        sb.AppendLine();
        sb.AppendLine("impl<T: ValueConverters> crate::value_converter::ValueConverterDispatch for ValueConvertersDispatch<T> {");
        sb.AppendLine("    fn convert(");
        sb.AppendLine("        &self,");
        sb.AppendLine("        converter_id: i32,");
        sb.AppendLine("        direction: crate::ConversionDirection,");
        sb.AppendLine("        value: crate::ScalarValue,");
        sb.AppendLine($"        {parameterName}: crate::ScalarValue,");
        sb.AppendLine("        _target_kind: crate::ScalarKind,");
        sb.AppendLine("        _culture: &str,");
        sb.AppendLine("    ) -> crate::Result<crate::ScalarValue> {");
        sb.AppendLine("        use crate::{ConversionDirection, ScalarValue};");
        sb.AppendLine("        match (converter_id, direction) {");
        foreach (var converter in converters)
        {
            sb.AppendLine($"            ({converter.Id}, ConversionDirection::Convert) => {{");
            sb.AppendLine($"                let value = {DecodeScalarMatch("value", converter.ValueKind, converter.Id, "converter-value")};");
            if (converter.ParameterKind is { } forwardParameterKind2)
                sb.AppendLine($"                let parameter = {DecodeScalarMatch(parameterName, forwardParameterKind2, converter.Id, "converter-parameter")};");
            var forwardCall = converter.ParameterKind is null
                ? $"self.converters.{Snake(converter.Name)}(value)"
                : $"self.converters.{Snake(converter.Name)}(value, parameter)";
            sb.AppendLine($"                Ok({EncodeScalarExpr(forwardCall, converter.ResultKind)})");
            sb.AppendLine("            }");
            if (converter.SupportsConvertBack)
            {
                sb.AppendLine($"            ({converter.Id}, ConversionDirection::ConvertBack) => {{");
                sb.AppendLine($"                let value = {DecodeScalarMatch("value", converter.ResultKind, converter.Id, "converter-value")};");
                if (converter.ParameterKind is { } backParameterKind2)
                    sb.AppendLine($"                let parameter = {DecodeScalarMatch(parameterName, backParameterKind2, converter.Id, "converter-parameter")};");
                var backCall = converter.ParameterKind is null
                    ? $"self.converters.{Snake(converter.Name)}_back(value)"
                    : $"self.converters.{Snake(converter.Name)}_back(value, parameter)";
                sb.AppendLine($"                Ok({EncodeScalarExpr(backCall, converter.ValueKind)})");
                sb.AppendLine("            }");
            }
        }
        sb.AppendLine("            _ => Err(crate::Error::InvalidViewModelMember { kind: \"converter\", id: converter_id }),");
        sb.AppendLine("        }");
        sb.AppendLine("    }");
        sb.AppendLine("}");
        sb.AppendLine();
        if (externalConsumer)
        {
            sb.AppendLine("pub fn register_value_converters(scope: &crate::AppScope, converters: impl ValueConverters) -> crate::Result<()> {");
            sb.AppendLine("    scope.register_value_converter_dispatch(ValueConvertersDispatch { converters })");
            sb.AppendLine("}");
        }
        else
        {
            sb.AppendLine("impl crate::AppScope {");
            sb.AppendLine("    pub fn register_value_converters(&self, converters: impl ValueConverters) -> crate::Result<()> {");
            sb.AppendLine("        self.register_value_converter_dispatch(ValueConvertersDispatch { converters })");
            sb.AppendLine("    }");
            sb.AppendLine("}");
        }
        sb.AppendLine();
    }

    private static string DecodeScalarMatch(string variable, ViewModelValueKind kind, int converterId, string what)
    {
        var pattern = kind switch
        {
            ViewModelValueKind.String => "ScalarValue::String(value) => value",
            ViewModelValueKind.Integer => "ScalarValue::Int64(value) => value",
            ViewModelValueKind.Boolean => "ScalarValue::Boolean(value) => value",
            ViewModelValueKind.Double => "ScalarValue::Double(value) => value",
            _ => throw new ArgumentOutOfRangeException(nameof(kind)),
        };
        return $"match {variable} {{ {pattern}, ScalarValue::Unset => return Ok(ScalarValue::Unset), ScalarValue::DoNothing => return Ok(ScalarValue::DoNothing), ScalarValue::Null => return Ok(ScalarValue::Null), _ => return Err(crate::Error::InvalidViewModelMember {{ kind: \"{what}\", id: {converterId} }}) }}";
    }

    private static string EncodeScalarExpr(string expression, ViewModelValueKind kind) => kind switch
    {
        ViewModelValueKind.String => $"ScalarValue::String({expression})",
        ViewModelValueKind.Integer => $"ScalarValue::Int64({expression})",
        ViewModelValueKind.Boolean => $"ScalarValue::Boolean({expression})",
        ViewModelValueKind.Double => $"ScalarValue::Double({expression})",
        _ => throw new ArgumentOutOfRangeException(nameof(kind)),
    };

    private static string EmitCSharpConverter(ValueConverterDefinition converter)
    {
        var sb = new StringBuilder();
        sb.AppendLine("// <auto-generated />");
        sb.AppendLine("#nullable enable");
        sb.AppendLine("using Avalonia.Data.Converters;");
        sb.AppendLine("using Avalonia.Rust;");
        sb.AppendLine();
        sb.AppendLine($"namespace {converter.ManagedNamespace};");
        sb.AppendLine();
        sb.AppendLine($"public static class {converter.Name}Converter");
        sb.AppendLine("{");
        sb.AppendLine(
            $"    public static IValueConverter Instance {{ get; }} = new RustValueConverter({converter.Id}, {(converter.SupportsConvertBack ? "true" : "false")});");
        sb.AppendLine("}");
        return sb.ToString();
    }

    private static void EmitRustPropertyDispatch(
        StringBuilder sb,
        ViewModelDefinition model,
        ViewModelValueKind wireKind)
    {
        var transport = Snake(TransportSuffix(wireKind));
        var properties = model.Properties
            .Where(property => property.Writable && WireKind(property.Kind) == wireKind)
            .ToArray();
        var valueName = properties.Length == 0 ? "_value" : "value";
        sb.AppendLine($"    fn set_{transport}(&mut self, property_id: i32, {valueName}: {RustOwnedType(wireKind)}) -> crate::Result<()> {{");
        if (properties.Length == 0)
        {
            sb.AppendLine("        Err(crate::Error::InvalidViewModelMember { kind: \"property\", id: property_id })");
            sb.AppendLine("    }");
            return;
        }
        sb.AppendLine("        match property_id {");
        foreach (var property in properties)
        {
            if (property.Kind == ViewModelValueKind.Enum)
            {
                sb.AppendLine($"            {property.Id} => self.model.set_{Snake(property.Name)}({property.EnumName}::try_from(value).map_err(|_| crate::Error::InvalidViewModelMember {{ kind: \"property\", id: property_id }})?),");
            }
            else
            {
                sb.AppendLine($"            {property.Id} => self.model.set_{Snake(property.Name)}(value),");
            }
        }
        sb.AppendLine($"            _ => Err(crate::Error::InvalidViewModelMember {{ kind: \"property\", id: property_id }}),");
        sb.AppendLine("        }");
        sb.AppendLine("    }");
    }

    private static void EmitRustCommandDispatch(
        StringBuilder sb,
        ViewModelDefinition model,
        bool asyncCommands)
    {
        var method = asyncCommands ? "begin_async" : "execute";
        var commands = model.Commands.Where(command => command.IsAsync == asyncCommands).ToArray();
        var parameterName = commands.Any(command => command.ParameterProperty is not null)
            ? "parameter"
            : "_parameter";
        sb.AppendLine($"    fn {method}(&mut self, command_id: i32, {parameterName}: Option<String>) -> crate::Result<()> {{");
        sb.AppendLine("        match command_id {");
        foreach (var command in commands)
        {
            var argument = command.ParameterProperty is null
                ? ""
                : "parameter.unwrap_or_default()";
            sb.AppendLine($"            {command.Id} => self.model.{Snake(command.Name)}({argument}),");
        }
        sb.AppendLine($"            _ => Err(crate::Error::InvalidViewModelMember {{ kind: \"command\", id: command_id }}),");
        sb.AppendLine("        }");
        sb.AppendLine("    }");
    }

    private static readonly ViewModelValueKind[] ScalarWireKinds =
    [
        ViewModelValueKind.String,
        ViewModelValueKind.Integer,
        ViewModelValueKind.Boolean,
        ViewModelValueKind.Double,
    ];

    /// <summary>
    /// The scalar transport an application-facing <see cref="ViewModelValueKind"/>
    /// rides on. Only <see cref="ViewModelValueKind.Enum"/> maps to a
    /// different wire kind (<see cref="ViewModelValueKind.Integer"/>); every
    /// other scalar kind is its own wire kind. <see cref="ViewModelValueKind.Model"/>
    /// has no scalar wire representation (it uses `SetModel`/`AddModel`/etc.)
    /// and must never be passed here.
    /// </summary>
    private static ViewModelValueKind WireKind(ViewModelValueKind kind) => kind switch
    {
        ViewModelValueKind.Enum => ViewModelValueKind.Integer,
        _ => kind,
    };

    private static string CSharpType(ViewModelIr ir, ViewModelProperty property) => property.Kind switch
    {
        ViewModelValueKind.String => property.Nullable ? "string?" : "string",
        ViewModelValueKind.Integer => "long",
        ViewModelValueKind.Boolean => "bool",
        ViewModelValueKind.Double => "double",
        ViewModelValueKind.Enum => CSharpEnumTypeName(ir, property.EnumName!),
        ViewModelValueKind.Model => $"{CSharpModelAdapterTypeName(ir, property.ModelName!)}?",
        _ => throw new ArgumentOutOfRangeException(nameof(property)),
    };

    private static string CSharpElementType(ViewModelIr ir, ViewModelValueKind elementKind, string? elementModelName) => elementKind switch
    {
        ViewModelValueKind.String => "string",
        ViewModelValueKind.Model => CSharpModelAdapterTypeName(ir, elementModelName!),
        _ => throw new ArgumentOutOfRangeException(nameof(elementKind)),
    };

    private static string CSharpScalarType(ViewModelValueKind wireKind) => wireKind switch
    {
        ViewModelValueKind.String => "string",
        ViewModelValueKind.Integer => "long",
        ViewModelValueKind.Boolean => "bool",
        ViewModelValueKind.Double => "double",
        _ => throw new ArgumentOutOfRangeException(nameof(wireKind)),
    };

    private static string CSharpTransportType(ViewModelValueKind wireKind) =>
        wireKind == ViewModelValueKind.Boolean ? "int" : CSharpScalarType(wireKind) + (wireKind == ViewModelValueKind.String ? "?" : "");

    private static string CSharpEnumTypeName(ViewModelIr ir, string enumName)
    {
        var enumDefinition = ir.Enums.Single(candidate => candidate.Name == enumName);
        return $"global::{enumDefinition.ManagedNamespace}.{enumDefinition.Name}";
    }

    private static string CSharpModelAdapterTypeName(ViewModelIr ir, string modelName)
    {
        var nestedModel = ir.Models.Single(candidate => candidate.Name == modelName);
        return $"global::{nestedModel.ManagedNamespace}.{nestedModel.Name}Adapter";
    }

    private static string CSharpModelMetadataTypeName(ViewModelIr ir, string modelName)
    {
        var nestedModel = ir.Models.Single(candidate => candidate.Name == modelName);
        return $"global::{nestedModel.ManagedNamespace}.{nestedModel.Name}Metadata";
    }

    private static string CSharpInitial(ViewModelIr ir, ViewModelProperty property) => property.Kind switch
    {
        ViewModelValueKind.String => property.Nullable
            ? (property.InitialString is null ? "null" : JsonSerializer.Serialize(property.InitialString))
            : JsonSerializer.Serialize(property.InitialString ?? ""),
        ViewModelValueKind.Integer => (property.InitialInteger ?? 0).ToString(CultureInfo.InvariantCulture) + "L",
        ViewModelValueKind.Boolean => (property.InitialBoolean ?? false) ? "true" : "false",
        ViewModelValueKind.Double => (property.InitialDouble ?? 0).ToString("R", CultureInfo.InvariantCulture) + "D",
        ViewModelValueKind.Enum => $"({CSharpEnumTypeName(ir, property.EnumName!)})({(property.InitialInteger ?? 0).ToString(CultureInfo.InvariantCulture)}L)",
        ViewModelValueKind.Model => "null",
        _ => throw new ArgumentOutOfRangeException(),
    };

    private static string CSharpToTransport(ViewModelProperty property, string value) => property.Kind switch
    {
        ViewModelValueKind.Boolean => $"({value} ? 1 : 0)",
        ViewModelValueKind.Enum => $"(long){value}",
        _ => value,
    };

    private static string CSharpFromTransport(ViewModelIr ir, ViewModelProperty property, string value) => property.Kind switch
    {
        ViewModelValueKind.String => property.Nullable ? value : $"{value} ?? \"\"",
        ViewModelValueKind.Boolean => $"{value} != 0",
        ViewModelValueKind.Enum => $"({CSharpEnumTypeName(ir, property.EnumName!)}){value}",
        _ => value,
    };

    private static string TransportSuffix(ViewModelValueKind wireKind) => wireKind switch
    {
        ViewModelValueKind.String => "String",
        ViewModelValueKind.Integer => "Integer",
        ViewModelValueKind.Boolean => "Boolean",
        ViewModelValueKind.Double => "Double",
        _ => throw new ArgumentOutOfRangeException(nameof(wireKind)),
    };

    private static string RustInputType(ViewModelValueKind kind) =>
        kind == ViewModelValueKind.String ? "impl AsRef<str>" : RustOwnedType(kind);

    private static string RustOwnedType(ViewModelValueKind kind) => kind switch
    {
        ViewModelValueKind.String => "String",
        ViewModelValueKind.Integer => "i64",
        ViewModelValueKind.Boolean => "bool",
        ViewModelValueKind.Double => "f64",
        _ => throw new ArgumentOutOfRangeException(nameof(kind)),
    };

    private static string EmitCSharpEnum(ViewModelEnumDefinition enumDefinition)
    {
        var sb = new StringBuilder();
        sb.AppendLine("// <auto-generated />");
        sb.AppendLine("#nullable enable");
        sb.AppendLine();
        sb.AppendLine($"namespace {enumDefinition.ManagedNamespace};");
        sb.AppendLine();
        sb.AppendLine($"public enum {enumDefinition.Name} : long");
        sb.AppendLine("{");
        foreach (var member in enumDefinition.Members)
            sb.AppendLine($"    {member.Name} = {member.Value},");
        sb.AppendLine("}");
        return sb.ToString();
    }

    private static void EmitRustEnum(StringBuilder sb, ViewModelEnumDefinition enumDefinition)
    {
        sb.AppendLine("#[repr(i64)]");
        sb.AppendLine("#[derive(Clone, Copy, Debug, PartialEq, Eq)]");
        sb.AppendLine($"pub enum {enumDefinition.Name} {{");
        foreach (var member in enumDefinition.Members)
            sb.AppendLine($"    {member.Name} = {member.Value},");
        sb.AppendLine("}");
        sb.AppendLine();
        sb.AppendLine($"impl std::convert::TryFrom<i64> for {enumDefinition.Name} {{");
        sb.AppendLine("    type Error = ();");
        sb.AppendLine("    fn try_from(value: i64) -> std::result::Result<Self, ()> {");
        sb.AppendLine("        match value {");
        foreach (var member in enumDefinition.Members)
            sb.AppendLine($"            {member.Value} => Ok(Self::{member.Name}),");
        sb.AppendLine("            _ => Err(()),");
        sb.AppendLine("        }");
        sb.AppendLine("    }");
        sb.AppendLine("}");
        sb.AppendLine();
    }

    private static string Lower(string value) =>
        char.ToLowerInvariant(value[0]) + value[1..];

    private static string Snake(string value)
    {
        var sb = new StringBuilder();
        for (var index = 0; index < value.Length; index++)
        {
            var character = value[index];
            if (char.IsUpper(character) && index > 0)
                sb.Append('_');
            sb.Append(char.ToLowerInvariant(character));
        }
        return sb.ToString();
    }
}
