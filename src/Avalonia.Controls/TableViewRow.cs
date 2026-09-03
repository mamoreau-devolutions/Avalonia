using System.Diagnostics;
using Avalonia.Automation.Peers;
using Avalonia.Collections;
using Avalonia.Controls.Metadata;
using Avalonia.Controls.Presenters;
using Avalonia.Controls.Primitives;

namespace Avalonia.Controls;

/// <summary>
/// A row container in a <see cref="TableView"/>.
/// </summary>
[TemplatePart(PartCellsPresenter, typeof(TableViewCellsPresenter))]
public class TableViewRow : ListBoxItem
{
    private const string PartCellsPresenter = "PART_CellsPresenter";

    private TableViewCellsPresenter? _cellsPresenter;

    internal AvaloniaList<TableViewColumn>? Columns { get; set; }

    /// <summary>
    /// The realized cells presenter, or null before the template is applied.
    /// </summary>
    /// <remarks>
    /// A row's template hosts the cells presenter directly rather than through
    /// a <see cref="ContentPresenter"/>, so the inherited
    /// <see cref="ContentControl.Presenter"/> is not the way to reach it.
    /// </remarks>
    internal TableViewCellsPresenter? CellsPresenter => _cellsPresenter;

    /// <inheritdoc />
    protected override void OnApplyTemplate(TemplateAppliedEventArgs e)
    {
        base.OnApplyTemplate(e);

        if (_cellsPresenter is not null)
        {
            Debug.Assert(_cellsPresenter.Row == this);
            _cellsPresenter.RemoveCells();
            _cellsPresenter.Row = null;
        }

        _cellsPresenter = e.NameScope.Find<TableViewCellsPresenter>(PartCellsPresenter);

        if (_cellsPresenter is not null)
        {
            Debug.Assert(_cellsPresenter.Row is null);
            _cellsPresenter.Row = this;
            _cellsPresenter.RebuildCells();
        }
    }

    internal void ClearCells()
        => _cellsPresenter?.ClearCells();

    internal void InvalidateCellsMeasure()
        => _cellsPresenter?.InvalidateMeasure();

    internal void RebuildCells()
        => _cellsPresenter?.RebuildCells();

    internal void RefreshCell(int columnIndex)
        => _cellsPresenter?.RefreshCell(columnIndex);

    /// <inheritdoc />
    protected override AutomationPeer OnCreateAutomationPeer()
        => new TableViewRowAutomationPeer(this);
}
