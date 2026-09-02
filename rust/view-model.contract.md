# Generated Rust view-model contract

Schema version: `2`

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
| Collection | 1 | `Items` | `String` | Rust to managed |
| Collection | 2 | `Tasks` | Model `TaskItemViewModel` | Rust to managed |
| Command | 1 | `Increment` | None | Managed to Rust |
| Command | 2 | `Add` | `NewItem` | Managed to Rust |
| Async command | 3 | `Save` | None | Managed to Rust |
| Command | 4 | `ClearNickname` | None | Managed to Rust |
| Command | 5 | `ToggleAddress` | None | Managed to Rust |
| Command | 6 | `AddTask` | `NewTaskTitle` | Managed to Rust |
| Command | 7 | `RemoveFirstTask` | None | Managed to Rust |
| Command | 8 | `ShuffleTasks` | None | Managed to Rust |
| Command | 9 | `ClearTasks` | None | Managed to Rust |

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

## Value converters

| ID | Name | Value | Parameter | Result | ConvertBack | Used by |
| ---: | --- | --- | --- | --- | --- | --- |
| 1 | `CountToLabel` | `Integer` | None | `String` | No | `RustVmWindow`, `RustDynamicVmWindow` |

## Views

| ID | Name | Model | Managed type | Binding path |
| ---: | --- | --- | --- | --- |
| 1 | `RustVmWindow` | `SampleViewModel` | `Avalonia.Rust.Sample.Views.RustVmWindow` | Generated CLR properties |
| 2 | `RustDynamicVmWindow` | `SampleViewModel` | `Avalonia.Rust.Sample.Views.RustDynamicVmWindow` | Dynamic Rust metadata |
