using System.Linq;
using Avalonia.Automation;
using Avalonia.Automation.Peers;
using Avalonia.Controls.Presenters;
using Avalonia.Controls.Primitives;
using Avalonia.Controls.Templates;
using Avalonia.Data;
using Avalonia.Styling;
using Avalonia.UnitTests;
using Avalonia.VisualTree;
using Xunit;

namespace Avalonia.Controls.UnitTests.Automation;

/// <summary>
/// A row's accessible name.
/// </summary>
/// <remarks>
/// A row's data item is an arbitrary object, so the inherited content-control
/// fallback of <c>Content.ToString()</c> reports the item's CLR type name for
/// any view model that does not override it - which is what a screen reader and
/// a UI automation client would then read out. The name is composed from the
/// row's own cells instead.
/// </remarks>
public sealed class TableViewRowAutomationPeerTests : ScopedTestBase
{
    [Fact]
    public void Row_Name_Comes_From_Cell_Values_Not_The_Item_Type_Name()
    {
        using var app = UnitTestApplication.Start(TestServices.MockPlatformRenderInterface);
        var target = CreateTarget();
        target.Columns.Add(new TableViewColumn { Binding = new Binding("Name") });
        target.Columns.Add(new TableViewColumn { Binding = new Binding("Severity") });
        target.ItemsSource = new[] { new Row("boot.log", "Warning") };
        Prepare(target);

        var row = (TableViewRow)target.GetRealizedContainers().Single();
        var peer = ControlAutomationPeer.CreatePeerForElement(row);

        Assert.Equal("boot.log Warning", peer.GetName());
        Assert.DoesNotContain("Row", peer.GetName()!);
    }

    [Fact]
    public void A_Templated_Cell_Contributes_The_Text_It_Actually_Renders()
    {
        using var app = UnitTestApplication.Start(TestServices.MockPlatformRenderInterface);
        var target = CreateTarget();
        target.Columns.Add(new TableViewColumn { Binding = new Binding("Name") });
        target.Columns.Add(new TableViewColumn
        {
            // A templated cell's content is the row item itself, so its text
            // has to come from the realized visual rather than ToString().
            CellTemplate = new FuncDataTemplate<Row>((_, _) =>
                new Border { Child = new TextBlock { [!TextBlock.TextProperty] = new Binding("Severity") } }),
        });
        target.ItemsSource = new[] { new Row("boot.log", "Warning") };
        Prepare(target);

        var row = (TableViewRow)target.GetRealizedContainers().Single();

        Assert.Equal("boot.log Warning", ControlAutomationPeer.CreatePeerForElement(row).GetName());
    }

    [Fact]
    public void An_Explicit_Automation_Name_Still_Wins()
    {
        using var app = UnitTestApplication.Start(TestServices.MockPlatformRenderInterface);
        var target = CreateTarget();
        target.Columns.Add(new TableViewColumn { Binding = new Binding("Name") });
        target.ItemsSource = new[] { new Row("boot.log", "Warning") };
        Prepare(target);

        var row = (TableViewRow)target.GetRealizedContainers().Single();
        AutomationProperties.SetName(row, "Explicit");

        Assert.Equal("Explicit", ControlAutomationPeer.CreatePeerForElement(row).GetName());
    }

    [Fact]
    public void A_Row_Without_Realized_Cells_Falls_Back_To_The_Inherited_Name()
    {
        using var app = UnitTestApplication.Start(TestServices.MockPlatformRenderInterface);
        var row = new TableViewRow { Content = "plain" };

        Assert.Equal("plain", ControlAutomationPeer.CreatePeerForElement(row).GetName());
    }

    [Fact]
    public void A_Row_Reports_The_Data_Item_Control_Type()
    {
        using var app = UnitTestApplication.Start(TestServices.MockPlatformRenderInterface);
        var row = new TableViewRow();

        Assert.Equal(
            AutomationControlType.DataItem,
            ControlAutomationPeer.CreatePeerForElement(row).GetAutomationControlType());
    }

    private static TableView CreateTarget() => new()
    {
        Template = Template(),
        ItemContainerTheme = RowTheme(),
    };

    private static void Prepare(TableView target)
    {
        target.Width = 300;
        target.Height = 200;
        var root = new TestRoot(target);
        root.LayoutManager.ExecuteInitialLayoutPass();
    }

    private static ControlTheme RowTheme() => new(typeof(TableViewRow))
    {
        Setters =
        {
            new Setter(
                TemplatedControl.TemplateProperty,
                new FuncControlTemplate<TableViewRow>((_, scope) =>
                    new TableViewCellsPresenter { Name = "PART_CellsPresenter" }.RegisterInNameScope(scope))),
        },
    };

    private static FuncControlTemplate Template() =>
        new FuncControlTemplate<TableView>((_, scope) =>
            new ItemsPresenter { Name = "PART_ItemsPresenter" }.RegisterInNameScope(scope));

    private sealed class Row(string name, string severity)
    {
        public string Name { get; } = name;

        public string Severity { get; } = severity;
    }
}
