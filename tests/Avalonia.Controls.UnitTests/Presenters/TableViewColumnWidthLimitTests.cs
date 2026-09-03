using Avalonia.Collections;
using Avalonia.Controls.Presenters;
using Avalonia.UnitTests;
using Xunit;

namespace Avalonia.Controls.UnitTests.Presenters;

/// <summary>
/// Per-column minimum and maximum widths. They apply to every width mode, not
/// just interactive resizing, so a narrow window cannot collapse a column that
/// declared a floor.
/// </summary>
public sealed class TableViewColumnWidthLimitTests : ScopedTestBase
{
    [Fact]
    public void UpdateActualWidths_Clamps_A_Pixel_Column_To_Its_Minimum()
    {
        var columns = new AvaloniaList<TableViewColumn>
        {
            new() { Width = new GridLength(40), MinWidth = 100 },
        };

        TableViewLayoutHelper.UpdateActualWidths(columns, 500, false, 1.0);

        Assert.Equal(100, columns[0].ActualWidth);
    }

    [Fact]
    public void UpdateActualWidths_Clamps_A_Pixel_Column_To_Its_Maximum()
    {
        var columns = new AvaloniaList<TableViewColumn>
        {
            new() { Width = new GridLength(400), MaxWidth = 120 },
        };

        TableViewLayoutHelper.UpdateActualWidths(columns, 500, false, 1.0);

        Assert.Equal(120, columns[0].ActualWidth);
    }

    [Fact]
    public void UpdateActualWidths_Clamps_A_Star_Column_To_Its_Minimum()
    {
        var columns = new AvaloniaList<TableViewColumn>
        {
            new() { Width = new GridLength(1, GridUnitType.Star), MinWidth = 260 },
            new() { Width = new GridLength(1, GridUnitType.Star) },
        };

        TableViewLayoutHelper.UpdateActualWidths(columns, 200, false, 1.0);

        Assert.Equal(260, columns[0].ActualWidth);
        Assert.Equal(100, columns[1].ActualWidth);
    }

    [Fact]
    public void A_Minimum_Greater_Than_The_Maximum_Wins()
    {
        var columns = new AvaloniaList<TableViewColumn>
        {
            new() { Width = new GridLength(40), MinWidth = 200, MaxWidth = 100 },
        };

        TableViewLayoutHelper.UpdateActualWidths(columns, 500, false, 1.0);

        Assert.Equal(200, columns[0].ActualWidth);
    }

    [Fact]
    public void Unconstrained_Columns_Keep_Their_Previous_Distribution()
    {
        var columns = new AvaloniaList<TableViewColumn>
        {
            new() { Width = new GridLength(1, GridUnitType.Star) },
            new() { Width = new GridLength(3, GridUnitType.Star) },
        };

        TableViewLayoutHelper.UpdateActualWidths(columns, 400, false, 1.0);

        Assert.Equal(100, columns[0].ActualWidth);
        Assert.Equal(300, columns[1].ActualWidth);
    }

    [Fact]
    public void Width_Limits_Reject_Negative_And_NaN_Values()
    {
        var column = new TableViewColumn();

        Assert.Throws<System.ArgumentException>(() => column.MinWidth = -1);
        Assert.Throws<System.ArgumentException>(() => column.MaxWidth = double.NaN);
        Assert.Equal(0, column.MinWidth);
        Assert.Equal(double.PositiveInfinity, column.MaxWidth);
    }
}
