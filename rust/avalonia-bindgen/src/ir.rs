use serde::Deserialize;

#[derive(Debug, Deserialize)]
#[serde(rename_all = "camelCase")]
pub struct ProjectionIr {
    pub version: i32,
    pub source_assembly: Option<String>,
    #[serde(default)]
    pub types: Vec<ProjectedType>,
    #[serde(default)]
    pub skipped: Vec<SkippedMember>,
}

#[derive(Debug, Deserialize)]
#[serde(rename_all = "camelCase")]
pub struct ProjectedType {
    pub name: String,
    pub full_name: String,
    pub kind: String,
    pub iid: Option<String>,
    pub base_full_name: Option<String>,
    #[serde(default)]
    pub methods: Vec<ProjectedMethod>,
}

#[derive(Debug, Deserialize)]
#[serde(rename_all = "camelCase")]
pub struct ProjectedMethod {
    pub name: String,
    pub return_kind: String,
    #[serde(default)]
    pub preserve_sig: bool,
    #[serde(default)]
    pub parameters: Vec<ProjectedParameter>,
}

#[derive(Debug, Deserialize)]
#[serde(rename_all = "camelCase")]
pub struct ProjectedParameter {
    pub name: String,
    pub kind: String,
    pub direction: String,
    pub interface_name: Option<String>,
    #[serde(default)]
    pub is_nullable: bool,
}

#[derive(Debug, Deserialize)]
pub struct SkippedMember {
    pub owner: String,
    pub member: String,
    pub reason: String,
}
