using System.Collections.Generic;
using Avalonia.Host.Com;
using Avalonia.Host.Views;
using Xunit;

namespace Avalonia.Host.Tests;

public class RustVmAdapterTests
{
    [Fact]
    public void Adapter_forwards_presentation_commands_to_model_and_sink()
    {
        var model = new Model();
        using var adapter = new RustVmAdapter(model);

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
    }

    private sealed class Model : IAvnRustViewModel
    {
        private IAvnRustVmSink? _sink;

        public string Name { get; private set; } = "";

        public int IncrementCalls { get; private set; }

        public List<string> AddedItems { get; } = [];

        public int SaveCalls { get; private set; }

        public int Attach(IAvnRustVmSink? sink)
        {
            _sink = sink;
            sink!.SetName("Initial");
            sink.SetCount(2);
            sink.AddItem("First");
            return 0;
        }

        public int Detach()
        {
            _sink = null;
            return 0;
        }

        public int SetName(string? value)
        {
            Name = value ?? "";
            _sink!.SetName(Name);
            return 0;
        }

        public int Increment()
        {
            IncrementCalls++;
            return 0;
        }

        public int AddItem(string? value)
        {
            AddedItems.Add(value ?? "");
            _sink!.AddItem(value);
            return 0;
        }

        public int BeginSave()
        {
            SaveCalls++;
            return 0;
        }
    }
}
