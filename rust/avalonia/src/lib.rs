#[rustfmt::skip]
mod generated;
#[rustfmt::skip]
mod generated_view_models;
mod async_runtime;
pub mod data_shapes;
mod runtime;
pub mod storage;
pub mod value_converter;
pub mod view_model;

pub use async_runtime::{AsyncOperation, AsyncValue};
pub use data_shapes::{CancellationToken, MapKey, RangeBatch, RangeRequest};
pub use generated::*;
pub use generated_view_models::*;
pub use runtime::{
    discover_host_path, App, AppContext, AppScope, AsControl, EventSubscription, ResourceValue,
    ThemeVariant, HOST_NATIVE_LIB_ENV_VAR,
};
pub use storage::{
    ActivationEvent, DragDropEffects, FileDropEvent, FileTypeFilter, FolderPickerOptions,
    OpenFilePickerOptions, PickerOutcome, SaveFilePickerOptions, StorageCapabilities, StorageItem,
    StorageItemKind, StorageLocation, StoragePickerOperation, WellKnownFolder,
};
pub use value_converter::{ConversionDirection, ScalarKind, ScalarValue};

#[derive(Debug)]
pub enum Error {
    Abi(avalonia_sys::Error),
    Load(String),
    NoUiContext,
    InvalidEnumValue(i32),
    InvalidAsyncValue,
    InvalidViewModelMember { kind: &'static str, id: i32 },
    Async { hresult: i32, message: String },
}

impl From<avalonia_sys::Error> for Error {
    fn from(value: avalonia_sys::Error) -> Self {
        Self::Abi(value)
    }
}

impl std::fmt::Display for Error {
    fn fmt(&self, formatter: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Self::Abi(error) => error.fmt(formatter),
            Self::Load(error) => write!(formatter, "failed to load Avalonia host: {error}"),
            Self::NoUiContext => {
                formatter.write_str("Avalonia controls must be created inside App::run")
            }
            Self::InvalidEnumValue(value) => {
                write!(formatter, "invalid projected enum value {value}")
            }
            Self::InvalidAsyncValue => formatter.write_str("invalid asynchronous result value"),
            Self::InvalidViewModelMember { kind, id } => {
                write!(formatter, "invalid view-model {kind} ID {id}")
            }
            Self::Async { hresult, message } => {
                write!(
                    formatter,
                    "asynchronous operation failed (0x{hresult:08X}): {message}"
                )
            }
        }
    }
}

impl std::error::Error for Error {}

pub type Result<T> = std::result::Result<T, Error>;
