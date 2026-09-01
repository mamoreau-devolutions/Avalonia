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

    #[test]
    fn factory_slots_are_sorted_by_interface_name() {
        let ir: ProjectionIr =
            serde_json::from_str(include_str!("../../projection.ir.json")).unwrap();
        let generated = emit_sys_module(&ir);
        let mut slots: Vec<_> = ir
            .types
            .iter()
            .filter(|ty| ty.is_constructible)
            .map(|ty| {
                let suffix = ty.name.strip_prefix("IAvn").unwrap();
                (
                    &ty.full_name,
                    generated
                        .find(&format!("    create_{}:", to_snake(suffix)))
                        .unwrap(),
                )
            })
            .collect();
        slots.sort_by_key(|(_, position)| *position);

        assert!(slots.windows(2).all(|pair| pair[0].0 < pair[1].0));
    }

    fn to_snake(value: &str) -> String {
        let mut output = String::new();
        for (index, character) in value.chars().enumerate() {
            if character.is_uppercase() && index > 0 {
                output.push('_');
            }
            output.push(character.to_ascii_lowercase());
        }
        output
    }
}
