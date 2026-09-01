use avalonia_sys::{app_handler, ComPtr, Error, Host, IUnknown, AVN_E_FIXTURE, E_NOINTERFACE};
use std::path::PathBuf;
use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::Arc;

fn host_path() -> PathBuf {
    if let Ok(p) = std::env::var("AVN_HOST_NATIVE_LIB") {
        return PathBuf::from(p);
    }
    let root = PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../..");
    let candidates = [
        "src/Avalonia.Host/bin/Release/net10.0/win-x64/publish/Avalonia.Host.dll",
        "src/Avalonia.Host/bin/Release/net10.0/win-arm64/publish/Avalonia.Host.dll",
        "src/Avalonia.Host/bin/Debug/net10.0/win-x64/publish/Avalonia.Host.dll",
    ];
    for rel in candidates {
        let p = root.join(rel);
        if p.exists() {
            return p;
        }
    }
    panic!(
        "Avalonia.Host native library not found. Publish with \
         `dotnet publish src/Avalonia.Host/Avalonia.Host.csproj -c Release -r win-x64` \
         or set AVN_HOST_NATIVE_LIB."
    );
}

fn load() -> Host {
    let path = host_path();
    assert!(path.exists(), "missing {}", path.display());
    Host::load(&path).unwrap_or_else(|e| panic!("load {}: {e}", path.display()))
}

#[test]
fn ping_increments() {
    let host = load();
    let factory = host.activation_factory().unwrap();
    let echo = factory.create_echo().unwrap();
    assert_eq!(echo.ping(41).unwrap(), 42);
}

#[test]
fn echo_string_roundtrips() {
    let host = load();
    let factory = host.activation_factory().unwrap();
    let echo = factory.create_echo().unwrap();
    assert_eq!(echo.echo_string(&host, "hello nano-COM").unwrap(), "hello nano-COM");
}

#[test]
fn fail_returns_fixture_hresult() {
    let host = load();
    let factory = host.activation_factory().unwrap();
    let echo = factory.create_echo().unwrap();
    assert_eq!(echo.fail(), AVN_E_FIXTURE);
}

#[test]
fn query_interface_identity() {
    let host = load();
    let factory = host.activation_factory().unwrap();
    let echo = factory.create_echo().unwrap();
    let unk1 = echo.as_iunknown().unwrap();
    let unk2 = echo.as_iunknown().unwrap();
    assert_eq!(unk1.as_raw() as usize, unk2.as_raw() as usize);
}

#[test]
fn unknown_iid_returns_e_nointerface() {
    let host = load();
    let factory = host.activation_factory().unwrap();
    let echo = factory.create_echo().unwrap();
    #[repr(C)]
    struct Bogus;
    unsafe impl avalonia_sys::ComInterface for Bogus {
        const IID: avalonia_sys::Guid = avalonia_sys::Guid {
            data1: 0x11111111,
            data2: 0x2222,
            data3: 0x3333,
            data4: [0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB],
        };
    }
    let err = echo.query_interface::<Bogus>().unwrap_err();
    assert_eq!(err.0, E_NOINTERFACE);
}

#[test]
fn drop_releases_without_crash() {
    let host = load();
    let factory = host.activation_factory().unwrap();
    let echo = factory.create_echo().unwrap();
    let extra = echo.clone();
    drop(echo);
    assert_eq!(extra.ping(0).unwrap(), 1);
    drop(extra);
}

#[test]
fn two_echo_instances_are_distinct() {
    let host = load();
    let factory = host.activation_factory().unwrap();
    let a = factory.create_echo().unwrap().as_iunknown().unwrap();
    let b = factory.create_echo().unwrap().as_iunknown().unwrap();
    assert_ne!(a.as_raw() as usize, b.as_raw() as usize);
}

#[test]
fn factory_creates_application() {
    let host = load();
    let factory = host.activation_factory().unwrap();
    let app = factory.create_application().unwrap();
    let _ = app.as_iunknown().unwrap();
}

#[test]
fn factory_unknown_qi_succeeds() {
    let host = load();
    let factory = host.activation_factory().unwrap();
    let unk: ComPtr<IUnknown> = factory.as_iunknown().unwrap();
    let _again = unk
        .query_interface::<avalonia_sys::IAvnActivationFactory>()
        .unwrap();
}

#[test]
fn application_runs_generated_object_model_through_rust_handler() {
    let host = load();
    let activation = host.activation_factory().unwrap();
    let application = activation.create_application().unwrap();
    let controls = activation.create_control_factory().unwrap();
    let called = Arc::new(AtomicBool::new(false));
    let called_from_handler = called.clone();
    let handler = app_handler(move || {
        let button = controls.create_button()?;
        let text = controls.create_text_block()?;

        assert!(button.get_is_enabled()?);
        button.set_is_enabled(false)?;
        assert!(!button.get_is_enabled()?);

        let text_as_control = text.query_interface::<avalonia_sys::IAvnControl>()?;
        button.set_content(Some(&text_as_control))?;
        let content = button.get_content()?.unwrap();
        assert_eq!(text.object_id()?, content.object_id()?);

        let panel = controls.create_stack_panel()?;
        let children = panel.get_children()?;
        children.add(&text_as_control)?;
        let button_as_control = button.query_interface::<avalonia_sys::IAvnControl>()?;
        children.add(&button_as_control)?;
        assert_eq!(children.len()?, 2);
        assert_eq!(children.get(0)?.object_id()?, text.object_id()?);
        children.remove(1)?;
        assert_eq!(children.len()?, 1);
        children.clear()?;
        assert_eq!(children.len()?, 0);

        called_from_handler.store(true, Ordering::SeqCst);
        Err(Error(AVN_E_FIXTURE))
    });

    let error = application.run(&handler).unwrap_err();
    assert_eq!(
        error.0,
        AVN_E_FIXTURE,
        "host startup failed: {}",
        host.last_error().unwrap_or_default()
    );
    assert!(called.load(Ordering::SeqCst));
}
