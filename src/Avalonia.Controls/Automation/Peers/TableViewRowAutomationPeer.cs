using System.Collections.Generic;
using System.Text;
using Avalonia.Controls;
using Avalonia.Controls.Presenters;
using Avalonia.Media;
using Avalonia.VisualTree;

namespace Avalonia.Automation.Peers
{
    /// <summary>
    /// Automation peer for a <see cref="TableViewRow"/>.
    /// </summary>
    /// <remarks>
    /// A row's data item is an arbitrary object, so the inherited
    /// <see cref="ContentControlAutomationPeer"/> fallback of
    /// <c>Content.ToString()</c> reports the item's CLR type name for any view
    /// model that does not override it - which is useless to a screen reader and
    /// to UI automation. This peer instead composes the name from the row's own
    /// cells, which is the text the user actually sees. An explicit
    /// <see cref="AutomationProperties.NameProperty"/> still wins, and the
    /// inherited behaviour is used when the row has no realized cells.
    /// </remarks>
    public class TableViewRowAutomationPeer : ListItemAutomationPeer
    {
        public TableViewRowAutomationPeer(TableViewRow owner)
            : base(owner)
        {
        }

        public new TableViewRow Owner => (TableViewRow)base.Owner;

        protected override AutomationControlType GetAutomationControlTypeCore()
            => AutomationControlType.DataItem;

        protected override string? GetNameCore()
        {
            var explicitName = AutomationProperties.GetName(Owner);
            if (!string.IsNullOrWhiteSpace(explicitName))
                return explicitName;

            var cells = GetCells();
            if (cells is null)
                return base.GetNameCore();

            var builder = new StringBuilder();
            foreach (var cell in cells)
            {
                var text = GetCellText(cell);
                if (string.IsNullOrWhiteSpace(text))
                    continue;
                if (builder.Length > 0)
                    builder.Append(' ');
                builder.Append(text);
            }

            return builder.Length > 0 ? builder.ToString() : base.GetNameCore();
        }

        private IEnumerable<TableViewCell>? GetCells()
        {
            if (Owner.CellsPresenter is not { } presenter)
                return null;

            var cells = new List<TableViewCell>(presenter.Children.Count);
            foreach (var child in presenter.Children)
            {
                if (child is TableViewCell cell)
                    cells.Add(cell);
            }

            return cells.Count > 0 ? cells : null;
        }

        private string? GetCellText(TableViewCell cell)
        {
            // A templated cell renders the row item itself, so its text has to
            // come from the realized content; only a value-bound cell may fall
            // back to the content's own string form.
            if (cell.Presenter?.Child is { } child)
            {
                if (FindText(child) is { } realized)
                    return realized;
                var childPeer = CreatePeerForElement(child);
                var childName = childPeer.GetName();
                if (!string.IsNullOrWhiteSpace(childName))
                    return childName;
            }

            var content = cell.Content;
            if (content is null || ReferenceEquals(content, Owner.Content))
                return null;
            return content as string ?? content.ToString();
        }

        /// <summary>
        /// Finds the text a realized cell actually shows. A templated cell may
        /// wrap its text in decoration (a border, a panel), so the whole
        /// subtree is searched rather than just the presenter's direct child.
        /// </summary>
        private static string? FindText(Visual root)
        {
            if (root is TextBlock text && !string.IsNullOrWhiteSpace(text.Text))
                return text.Text;
            foreach (var descendant in root.GetVisualDescendants())
            {
                if (descendant is TextBlock nested && !string.IsNullOrWhiteSpace(nested.Text))
                    return nested.Text;
            }

            return null;
        }
    }
}
