param(
    [ValidateSet("Debug", "Release")]
    [string]$Configuration = "Release",
    [switch]$SkipManagedBuild,
    [switch]$Test,
    [switch]$ValidateTemplate,
    [string]$PackageRid
)

$ErrorActionPreference = "Stop"
$repositoryRoot = Split-Path -Parent $PSScriptRoot

Write-Host "==> [1/4] Regenerating object-model projection IR, C# COM sources, and native ABI header"
dotnet run --project "$repositoryRoot\src\Avalonia.Projection.Tool" -c $Configuration -- `
    "$repositoryRoot\rust\projection.ir.json" `
    "$repositoryRoot\src\Avalonia.Host\Generated\ObjectModel" `
    "$repositoryRoot\rust\avalonia-sys\include\avalonia-rust-abi.h"
if ($LASTEXITCODE -ne 0)
{
    exit $LASTEXITCODE
}

Write-Host "==> [1/4] Regenerating Rust sys/safe bindings from projection IR"
Push-Location "$repositoryRoot\rust"
try
{
    cargo run -p avalonia-bindgen -- `
        .\projection.ir.json `
        .\avalonia-sys\src\generated.rs `
        .\avalonia\src\generated.rs
    if ($LASTEXITCODE -ne 0)
    {
        exit $LASTEXITCODE
    }
}
finally
{
    Pop-Location
}

Write-Host "==> [1/4] Regenerating view-model adapters/registry/Rust model/contract from the canonical view-model IR"
dotnet run --project "$repositoryRoot\src\Avalonia.ViewModelProjection.Tool" -c $Configuration -- `
    "$repositoryRoot\rust\view-model.ir.json" `
    "$repositoryRoot\samples\RustViewModelSample.Managed\Generated" `
    "$repositoryRoot\src\Avalonia.Host\Generated\ViewModels" `
    "$repositoryRoot\rust\avalonia\src\generated_view_models.rs" `
    "$repositoryRoot\rust\view-model.contract.md"
if ($LASTEXITCODE -ne 0)
{
    exit $LASTEXITCODE
}

Push-Location "$repositoryRoot\rust"
try
{
    cargo fmt --all
    if ($LASTEXITCODE -ne 0)
    {
        exit $LASTEXITCODE
    }
}
finally
{
    Pop-Location
}

if (-not $SkipManagedBuild)
{
    Write-Host "==> [2/4] Building managed AXAML (RustViewModelSample.Managed via Avalonia.Host)"
    dotnet build "$repositoryRoot\src\Avalonia.Host\Avalonia.Host.csproj" -c $Configuration
    if ($LASTEXITCODE -ne 0)
    {
        exit $LASTEXITCODE
    }
}

Write-Host "==> [3/4] Building the Rust workspace"
$cargoArgs = @("--manifest-path", "$repositoryRoot\rust\Cargo.toml", "--workspace")
if ($Test)
{
    cargo test @cargoArgs
}
else
{
    cargo build @cargoArgs
}
if ($LASTEXITCODE -ne 0)
{
    exit $LASTEXITCODE
}

if ($ValidateTemplate)
{
    Write-Host "==> [3/4] Validating the copyable application template compiles standalone"
    cargo check --manifest-path "$repositoryRoot\rust\templates\avalonia-app\Cargo.toml"
    if ($LASTEXITCODE -ne 0)
    {
        exit $LASTEXITCODE
    }
}

if ($PackageRid)
{
    Write-Host "==> [4/4] Packaging the NativeAOT host and a Rust example for $PackageRid"
    & "$PSScriptRoot\package.ps1" -Rid $PackageRid -Configuration $Configuration
    if ($LASTEXITCODE -ne 0)
    {
        exit $LASTEXITCODE
    }
}

Write-Host "Regeneration and build complete."
