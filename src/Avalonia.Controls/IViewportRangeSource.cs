namespace Avalonia.Controls;

/// <summary>
/// An items source that can realize a visible index range on demand.
/// <see cref="TableView"/> (and other virtualizing presenters) call this after
/// layout with the realized row range so a windowed collection can request
/// pages for the viewport instead of waiting on indexer misses.
/// </summary>
public interface IViewportRangeSource
{
    /// <summary>
    /// Ensures elements in <paramref name="firstIndex"/>..<paramref name="lastIndex"/>
    /// (inclusive) are requested. Implementations must not block the UI thread.
    /// </summary>
    void EnsureVisibleRange(int firstIndex, int lastIndex);
}
