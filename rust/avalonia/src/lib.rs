#[rustfmt::skip]
mod generated;
mod runtime;

pub use generated::*;
pub use runtime::{App, AppContext, AsControl, EventSubscription, ResourceValue, ThemeVariant};

#[derive(Debug)]
pub enum Error {
    Abi(avalonia_sys::Error),
    Load(String),
    NoUiContext,
    InvalidEnumValue(i32),
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
        }
    }
}

impl std::error::Error for Error {}

pub type Result<T> = std::result::Result<T, Error>;
