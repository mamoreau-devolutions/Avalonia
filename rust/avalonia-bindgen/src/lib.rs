mod emit;
mod emit_safe;
mod ir;

pub use emit::emit_sys_module;
pub use emit_safe::emit_safe_module;
pub use ir::ProjectionIr;

pub fn generate_from_json(json: &str) -> Result<String, serde_json::Error> {
    let ir: ProjectionIr = serde_json::from_str(json)?;
    Ok(emit_sys_module(&ir))
}

pub fn generate_safe_from_json(json: &str) -> Result<String, serde_json::Error> {
    let ir: ProjectionIr = serde_json::from_str(json)?;
    Ok(emit_safe_module(&ir))
}

#[cfg(test)]
mod tests {
    use super::*;

    const FIXTURE: &str = r#"
    {
      "version": 1,
      "sourceAssembly": "Avalonia.Host",
      "types": [
        {
          "name": "IAvnEcho",
          "fullName": "Avalonia.Host.Com.IAvnEcho",
          "kind": "Interface",
          "iid": "6B2E8F10-4C91-4E3A-9A77-1F0C2B3A4D11",
          "methods": [
            {
              "name": "Ping",
              "returnKind": "I32",
              "preserveSig": true,
              "parameters": [
                { "name": "value", "kind": "I32", "direction": "In" },
                { "name": "result", "kind": "I32", "direction": "Out" }
              ]
            },
            {
              "name": "EchoString",
              "returnKind": "I32",
              "preserveSig": true,
              "parameters": [
                { "name": "input", "kind": "StringUtf16", "direction": "In", "isNullable": true },
                { "name": "output", "kind": "StringUtf16", "direction": "Out", "isNullable": true }
              ]
            },
            {
              "name": "Fail",
              "returnKind": "I32",
              "preserveSig": true,
              "parameters": []
            }
          ]
        }
      ]
    }
    "#;

    #[test]
    fn emits_fixture_echo_surface() {
        let src = generate_from_json(FIXTURE).unwrap();
        assert!(src.contains("pub struct IAvnEcho"));
        assert!(src.contains("data1: 0x6B2E8F10"));
        assert!(src.contains("pub fn ping"));
        assert!(src.contains("pub fn echo_string"));
        assert!(src.contains("pub fn fail"));
        assert!(src.contains("unsafe impl ComInterface for IAvnEcho"));
        assert!(!src.contains("unsupported"));
    }

    #[test]
    fn checked_in_sys_bindings_match_shared_ir() {
        let ir = include_str!("../../projection.ir.json");
        let expected = include_str!("../../avalonia-sys/src/generated.rs");
        assert_eq!(generate_from_json(ir).unwrap(), expected);
    }

    #[test]
    fn checked_in_safe_bindings_match_shared_ir() {
        let ir = include_str!("../../projection.ir.json");
        let expected = include_str!("../../avalonia/src/generated.rs");
        assert_eq!(generate_safe_from_json(ir).unwrap(), expected);
    }
}
