using System.Collections.Generic;
using Avalonia.Rust.Interop;
using Avalonia.Rust.Sample.Generated;
using Xunit;

namespace Avalonia.Host.Tests;

public class RustVmAdapterTests
{
    [Fact]
    public void Adapter_forwards_presentation_commands_to_model_and_sink()
    {
        var model = new Model();
        using var adapter = new SampleViewModelAdapter(model);

        Assert.Equal("Initial", adapter.Name);
        Assert.Equal(2, adapter.Count);
        Assert.Equal(["First"], adapter.Items);

        adapter.Name = "Edited";
        adapter.IncrementCommand.Execute(null);
        adapter.NewItem = "Second";
        adapter.AddCommand.Execute(null);
        adapter.SaveCommand.Execute(null);

        Assert.Equal("Edited", model.Name);
        Assert.Equal(1, model.IncrementCalls);
        Assert.Equal(["Second"], model.AddedItems);
        Assert.Equal(1, model.SaveCalls);
        Assert.Equal("", adapter.NewItem);

        var sink = model.Sink;
        adapter.Dispose();
        Assert.Equal(1, model.DetachCalls);
        Assert.Equal(0, sink.SetString(1, "late"));
        Assert.Equal("Edited", adapter.Name);
        Assert.True(sink.SetString(999, "invalid") < 0);
        Assert.True(sink.SetInteger(1, 42) < 0);
        Assert.True(sink.AddString(999, "invalid") < 0);
        adapter.Dispose();
        Assert.Equal(1, model.DetachCalls);
    }

    [Fact]
    public void Repeated_attach_detach_balances()
    {
        for (var index = 0; index < 100; index++)
        {
            var model = new Model();
            new SampleViewModelAdapter(model).Dispose();
            Assert.Equal(1, model.DetachCalls);
        }
    }

    private sealed class Model : IAvnRustViewModel
    {
        private IAvnRustVmSink? _sink;

        public string Name { get; private set; } = "";

        public int IncrementCalls { get; private set; }

        public List<string> AddedItems { get; } = [];

        public int SaveCalls { get; private set; }

        public int DetachCalls { get; private set; }

        public IAvnRustVmSink Sink => _sink!;

        public int Attach(IAvnRustVmSink? sink)
        {
            _sink = sink;
            sink!.SetString(1, "Initial");
            sink.SetInteger(2, 2);
            sink.AddString(1, "First");
            return 0;
        }

        public int Detach()
        {
            DetachCalls++;
            _sink = null;
            return 0;
        }

        public int SetString(int propertyId, string? value)
        {
            if (propertyId == 1)
            {
                Name = value ?? "";
                _sink!.SetString(1, Name);
            }
            else if (propertyId == 3)
                _sink!.SetString(3, value);
            else
                return unchecked((int)0x80070057);
            return 0;
        }

        public int SetInteger(int propertyId, long value) =>
            unchecked((int)0x80070057);

        public int SetBoolean(int propertyId, int value) =>
            unchecked((int)0x80070057);

        public int SetDouble(int propertyId, double value) =>
            unchecked((int)0x80070057);

        public int Execute(int commandId, string? parameter)
        {
            if (commandId == 1)
                IncrementCalls++;
            else if (commandId == 2)
            {
                AddedItems.Add(parameter ?? "");
                _sink!.AddString(1, parameter);
                _sink.SetString(3, "");
            }
            else
                return unchecked((int)0x80070057);
            return 0;
        }

        public int BeginAsync(int commandId, string? parameter)
        {
            Assert.Equal(3, commandId);
            SaveCalls++;
            return 0;
        }
    }
}
