# Generated Rust view-model contract

Schema version: `3`

## Enums

| ID | Name | Members |
| ---: | --- | --- |
| 1 | `Priority` | `Low` = 0, `Normal` = 1, `High` = 2 |

## Model `SampleViewModel` (`1`)

| Kind | ID | Name | Type | Direction |
| --- | ---: | --- | --- | --- |
| Property | 1 | `Name` | `String` | Rust and managed |
| Property | 2 | `Count` | `Integer` | Rust to managed |
| Property | 3 | `NewItem` | `String` | Rust and managed |
| Property | 4 | `Status` | `String` | Rust to managed |
| Property | 5 | `Nickname` | `String`, nullable | Rust and managed |
| Property | 6 | `Priority` | Enum `Priority` | Rust and managed |
| Property | 7 | `Address` | Model `AddressViewModel`, nullable | Rust to managed |
| Property | 8 | `NewTaskTitle` | `String` | Rust and managed |
| Property | 9 | `SelectedTraceIndex` | `Integer` | Rust and managed |
| Property | 10 | `SelectedTraceKey` | `String` | Rust and managed |
| Property | 11 | `TraceSortDirection` | `String` | Rust to managed |
| Collection | 1 | `Items` | `String` | Rust to managed |
| Collection | 2 | `Tasks` | Model `TaskItemViewModel` | Rust to managed |
| Collection | 3 | `TraceRows` | Model `TraceRowViewModel` | Rust to managed |
| Command | 1 | `Increment` | None | Managed to Rust |
| Command | 2 | `Add` | `NewItem` | Managed to Rust |
| Async command | 3 | `Save` | None | Managed to Rust |
| Command | 4 | `ClearNickname` | None | Managed to Rust |
| Command | 5 | `ToggleAddress` | None | Managed to Rust |
| Command | 6 | `AddTask` | `NewTaskTitle` | Managed to Rust |
| Command | 7 | `RemoveFirstTask` | None | Managed to Rust |
| Command | 8 | `ShuffleTasks` | None | Managed to Rust |
| Command | 9 | `ClearTasks` | None | Managed to Rust |
| Command | 10 | `SortTraceRows` | None | Managed to Rust |

### Table `TraceRows`

| ID | Name | Header | Row path | Width | Resize | Sort | Alignment |
| ---: | --- | --- | --- | --- | --- | --- | --- |
| 1 | `Timestamp` | Timestamp | `Timestamp` | 150 | Yes | Yes | Left |
| 2 | `Severity` | Severity | `Severity` | 90 | Yes | Yes | Center |
| 3 | `Source` | Source | `Event.Source` | 120 | Yes | Yes | Left |
| 4 | `Message` | Message | `Message` | * | Yes | No | Left |
Selection: index `SelectedTraceIndex`, key `SelectedTraceKey`, row key `Event.Id`.
Sort: `SortTraceRows` command, initial column `Timestamp`, direction property `TraceSortDirection`.

## Model `AddressViewModel` (`2`)

| Kind | ID | Name | Type | Direction |
| --- | ---: | --- | --- | --- |
| Property | 1 | `Street` | `String` | Rust and managed |
| Property | 2 | `City` | `String` | Rust and managed |

## Model `TaskItemViewModel` (`3`)

| Kind | ID | Name | Type | Direction |
| --- | ---: | --- | --- | --- |
| Property | 1 | `Title` | `String` | Rust to managed |
| Property | 2 | `Done` | `Boolean` | Rust and managed |

## Model `TraceRowViewModel` (`4`)

| Kind | ID | Name | Type | Direction |
| --- | ---: | --- | --- | --- |
| Property | 1 | `Timestamp` | `String` | Rust to managed |
| Property | 2 | `Severity` | `String` | Rust to managed |
| Property | 3 | `Message` | `String` | Rust to managed |
| Property | 4 | `Event` | Model `TraceEventViewModel`, nullable | Rust to managed |

## Model `TraceEventViewModel` (`5`)

| Kind | ID | Name | Type | Direction |
| --- | ---: | --- | --- | --- |
| Property | 1 | `Id` | `String` | Rust to managed |
| Property | 2 | `Source` | `String` | Rust to managed |

## Value converters

| ID | Name | Value | Parameter | Result | ConvertBack | Used by |
| ---: | --- | --- | --- | --- | --- | --- |
| 1 | `CountToLabel` | `Integer` | None | `String` | No | `RustVmWindow`, `RustDynamicVmWindow` |

## Views

| ID | Name | Model | Managed type | Binding path |
| ---: | --- | --- | --- | --- |
| 1 | `RustVmWindow` | `SampleViewModel` | `Avalonia.Rust.Sample.Views.RustVmWindow` | Generated CLR properties |
| 2 | `RustDynamicVmWindow` | `SampleViewModel` | `Avalonia.Rust.Sample.Views.RustDynamicVmWindow` | Dynamic Rust metadata |
