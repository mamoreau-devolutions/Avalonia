# Generated Rust view-model contract

Schema version: `1`

## Model `SampleViewModel` (`1`)

| Kind | ID | Name | Type | Direction |
| --- | ---: | --- | --- | --- |
| Property | 1 | `Name` | `String` | Rust and managed |
| Property | 2 | `Count` | `Integer` | Rust to managed |
| Property | 3 | `NewItem` | `String` | Rust and managed |
| Property | 4 | `Status` | `String` | Rust to managed |
| Collection | 1 | `Items` | `String` | Rust to managed |
| Command | 1 | `Increment` | None | Managed to Rust |
| Command | 2 | `Add` | `NewItem` | Managed to Rust |
| Async command | 3 | `Save` | None | Managed to Rust |

## Views

| ID | Name | Model | Managed type |
| ---: | --- | --- | --- |
| 1 | `RustVmWindow` | `SampleViewModel` | `Avalonia.Rust.Sample.Views.RustVmWindow` |
