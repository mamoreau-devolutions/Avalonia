param(
    [ValidateSet("x64", "arm64")]
    [string]$Architecture = "x64",
    [switch]$RunExamples
)

$ErrorActionPreference = "Stop"
$repositoryRoot = Split-Path -Parent $PSScriptRoot
$rid = "win-$Architecture"

dotnet publish "$repositoryRoot\src\Avalonia.Host\Avalonia.Host.csproj" `
    -c Release -r $rid
if ($LASTEXITCODE -ne 0)
{
    exit $LASTEXITCODE
}

$env:AVN_HOST_NATIVE_LIB = Join-Path $repositoryRoot `
    "src\Avalonia.Host\bin\Release\net10.0\$rid\publish\Avalonia.Host.dll"

cargo test --manifest-path "$PSScriptRoot\Cargo.toml" --workspace
if ($LASTEXITCODE -ne 0)
{
    exit $LASTEXITCODE
}

if ($RunExamples)
{
    cargo run --manifest-path "$PSScriptRoot\Cargo.toml" `
        -p avalonia --example hello_world
    exit $LASTEXITCODE
}
