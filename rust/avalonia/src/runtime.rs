use crate::{Error, Result, Window};
use avalonia_sys as sys;
use std::any::Any;
use std::cell::RefCell;
use std::fmt;
use std::marker::PhantomData;
use std::ops::Deref;
use std::path::Path;
use std::rc::Rc;
use std::sync::{Arc, Mutex};

#[repr(i32)]
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum ThemeVariant {
    Default = 0,
    Light = 1,
    Dark = 2,
}

#[derive(Clone, Debug, PartialEq)]
pub enum ResourceValue {
    Null,
    Boolean(bool),
    Integer(i64),
    Double(f64),
    String(String),
    Color(u32),
}

thread_local! {
    static FACTORY: RefCell<Option<sys::ComPtr<sys::IAvnControlFactory>>> = const { RefCell::new(None) };
}

pub trait AsControl {
    fn as_control(&self) -> Result<sys::ComPtr<sys::IAvnControl>>;
}

pub struct EventSubscription {
    unsubscribe: Option<Box<dyn Fn() -> sys::Result<()> + Send>>,
    _thread_affinity: PhantomData<Rc<()>>,
}

impl EventSubscription {
    pub(crate) fn new(unsubscribe: impl Fn() -> sys::Result<()> + Send + 'static) -> Self {
        Self {
            unsubscribe: Some(Box::new(unsubscribe)),
            _thread_affinity: PhantomData,
        }
    }

    pub fn unsubscribe(&mut self) -> Result<()> {
        if let Some(unsubscribe) = self.unsubscribe.as_ref() {
            unsubscribe()?;
            self.unsubscribe = None;
        }
        Ok(())
    }

    fn into_persistent(mut self) -> PersistentSubscription {
        PersistentSubscription {
            unsubscribe: self.unsubscribe.take(),
        }
    }
}

struct PersistentSubscription {
    unsubscribe: Option<Box<dyn Fn() -> sys::Result<()> + Send>>,
}

impl Drop for PersistentSubscription {
    fn drop(&mut self) {
        if let Some(unsubscribe) = self.unsubscribe.as_ref() {
            let _ = unsubscribe();
        }
    }
}

impl fmt::Debug for EventSubscription {
    fn fmt(&self, formatter: &mut fmt::Formatter<'_>) -> fmt::Result {
        formatter
            .debug_struct("EventSubscription")
            .field("active", &self.unsubscribe.is_some())
            .finish()
    }
}

impl Drop for EventSubscription {
    fn drop(&mut self) {
        if let Some(unsubscribe) = self.unsubscribe.as_ref() {
            let _ = unsubscribe();
        }
    }
}

pub struct App {
    application: sys::ComPtr<sys::IAvnApplication>,
    controls: sys::ComPtr<sys::IAvnControlFactory>,
    dispatcher: sys::ComPtr<sys::IAvnDispatcher>,
    _host: sys::Host,
}

#[derive(Clone)]
pub struct AppScope {
    context: AppContext,
    state: Arc<AppScopeState>,
}

struct AppScopeState {
    subscriptions: Mutex<Vec<PersistentSubscription>>,
    objects: Mutex<Vec<Box<dyn Any + Send>>>,
}

impl AppScope {
    fn new(context: AppContext) -> Self {
        Self {
            context,
            state: Arc::new(AppScopeState {
                subscriptions: Mutex::new(Vec::new()),
                objects: Mutex::new(Vec::new()),
            }),
        }
    }

    pub fn mount(&self, window: Window) -> Result<()> {
        window.raw.show()?;
        self.state
            .objects
            .lock()
            .expect("application object scope lock poisoned")
            .push(Box::new(window));
        Ok(())
    }

    pub(crate) fn retain_subscription(&self, subscription: EventSubscription) {
        self.state
            .subscriptions
            .lock()
            .expect("application subscription scope lock poisoned")
            .push(subscription.into_persistent());
    }

    fn clear(&self) {
        self.state
            .subscriptions
            .lock()
            .expect("application subscription scope lock poisoned")
            .clear();
        self.state
            .objects
            .lock()
            .expect("application object scope lock poisoned")
            .clear();
    }
}

impl Deref for AppScope {
    type Target = AppContext;

    fn deref(&self) -> &Self::Target {
        &self.context
    }
}

impl fmt::Debug for AppScope {
    fn fmt(&self, formatter: &mut fmt::Formatter<'_>) -> fmt::Result {
        formatter.debug_struct("AppScope").finish_non_exhaustive()
    }
}

#[derive(Clone, Debug)]
pub struct AppContext {
    application: sys::ComPtr<sys::IAvnApplication>,
    dispatcher: sys::ComPtr<sys::IAvnDispatcher>,
}

impl AppContext {
    pub fn check_access(&self) -> Result<bool> {
        Ok(self.dispatcher.check_access()?)
    }

    pub fn post(&self, callback: impl FnOnce() + Send + 'static) -> Result<()> {
        let action = sys::action(move || {
            callback();
            Ok(())
        });
        Ok(self.dispatcher.post(&action)?)
    }

    pub fn shutdown(&self) -> Result<()> {
        Ok(self.application.shutdown()?)
    }

    pub fn requested_theme_variant(&self) -> Result<ThemeVariant> {
        theme_variant(self.application.requested_theme_variant()?)
    }

    pub fn set_requested_theme_variant(&self, value: ThemeVariant) -> Result<()> {
        Ok(self.application.set_requested_theme_variant(value as i32)?)
    }

    pub fn actual_theme_variant(&self) -> Result<ThemeVariant> {
        theme_variant(self.application.actual_theme_variant()?)
    }

    pub fn find_resource(
        &self,
        key: impl AsRef<str>,
        theme: ThemeVariant,
    ) -> Result<Option<ResourceValue>> {
        let key: Vec<u16> = key.as_ref().encode_utf16().chain(Some(0)).collect();
        self.application
            .try_get_resource(&key, theme as i32)?
            .map(resource_value)
            .transpose()
    }
}

impl App {
    pub fn load_from_env() -> Result<Self> {
        let path = std::env::var_os("AVN_HOST_NATIVE_LIB")
            .ok_or_else(|| Error::Load("AVN_HOST_NATIVE_LIB is not set".to_string()))?;
        Self::load(path)
    }

    pub fn load(path: impl AsRef<Path>) -> Result<Self> {
        let host = sys::Host::load(path).map_err(|error| Error::Load(error.to_string()))?;
        let activation = host.activation_factory()?;
        let application = activation.create_application()?;
        let controls = activation.create_control_factory()?;
        let dispatcher = activation.create_dispatcher()?;
        Ok(Self {
            application,
            controls,
            dispatcher,
            _host: host,
        })
    }

    pub fn run(
        self,
        callback: impl FnOnce(&AppScope) -> Result<()> + Send + 'static,
    ) -> Result<()> {
        let controls = self.controls.clone();
        let context = AppContext {
            application: self.application.clone(),
            dispatcher: self.dispatcher.clone(),
        };
        let scope = AppScope::new(context);
        let cleanup_scope = scope.clone();
        let handler = sys::app_handler(move || callback(&scope).map_err(to_abi_error));
        FACTORY.with(|current| {
            let previous = current.replace(Some(controls));
            let result = self.application.run(&handler);
            cleanup_scope.clear();
            current.replace(previous);
            Ok(result?)
        })
    }
}

pub(crate) fn with_factory<T>(
    callback: impl FnOnce(&sys::ComPtr<sys::IAvnControlFactory>) -> sys::Result<T>,
) -> Result<T> {
    FACTORY.with(|factory| {
        let factory = factory.borrow();
        let factory = factory.as_ref().ok_or(Error::NoUiContext)?;
        Ok(callback(factory)?)
    })
}

fn to_abi_error(error: Error) -> sys::Error {
    match error {
        Error::Abi(error) => error,
        Error::Load(_) | Error::NoUiContext | Error::InvalidEnumValue(_) => sys::Error(sys::E_FAIL),
    }
}

fn theme_variant(value: i32) -> Result<ThemeVariant> {
    match value {
        0 => Ok(ThemeVariant::Default),
        1 => Ok(ThemeVariant::Light),
        2 => Ok(ThemeVariant::Dark),
        value => Err(Error::InvalidEnumValue(value)),
    }
}

fn resource_value(value: sys::ComPtr<sys::IAvnResourceValue>) -> Result<ResourceValue> {
    Ok(match value.kind()? {
        0 => ResourceValue::Null,
        1 => ResourceValue::Boolean(value.boolean()?),
        2 => ResourceValue::Integer(value.integer()?),
        3 => ResourceValue::Double(value.double()?),
        4 => ResourceValue::String(unsafe {
            sys::take_utf16(value.string()?).ok_or(Error::Abi(sys::Error(sys::E_POINTER)))?
        }),
        5 => ResourceValue::Color(value.color()?),
        kind => return Err(Error::InvalidEnumValue(kind)),
    })
}
