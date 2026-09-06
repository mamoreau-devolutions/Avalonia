#!/usr/bin/env pwsh
#Requires -Version 7.0
param(
    [ValidateSet('Debug', 'Release')]
    [string]$Configuration = 'Release',
    [switch]$SkipManagedBuild,
    [switch]$Test,
    [switch]$ValidateTemplate,
    [string]$PackageRid
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'
$PSNativeCommandUseErrorActionPreference = $true
# rustolonia/rust/<script> -> the Avalonia repository root is three levels up
$repositoryRoot = Split-Path -Parent (Split-Path -Parent $PSScriptRoot)

Write-Host '==> [1/4] Regenerating object-model projection IR, C# COM sources, and native ABI header'
dotnet run --project (Join-Path $repositoryRoot 'rustolonia' 'projection' 'Avalonia.Projection.Tool') -c $Configuration -- `
    (Join-Path $repositoryRoot 'rustolonia' 'rust' 'projection.ir.json') `
    (Join-Path $repositoryRoot 'rustolonia' 'host' 'Generated' 'ObjectModel') `
    (Join-Path $repositoryRoot 'rustolonia' 'rust' 'avalonia-sys' 'include' 'avalonia-rust-abi.h')
if ($LASTEXITCODE -ne 0)
{
    exit $LASTEXITCODE
}

Write-Host "==> [1/4] Regenerating Rust sys/safe bindings from projection IR"
Push-Location "$repositoryRoot\rustolonia\rust"
try
{
    cargo run -p avalonia-bindgen -- `
        (Join-Path '.' 'projection.ir.json') `
        (Join-Path '.' 'avalonia-sys' 'src' 'generated.rs') `
        (Join-Path '.' 'avalonia' 'src' 'generated.rs')
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
dotnet run --project (Join-Path $repositoryRoot 'rustolonia' 'projection' 'Avalonia.ViewModelProjection.Tool') -c $Configuration -- `
    (Join-Path $repositoryRoot 'rustolonia' 'rust' 'view-model.ir.json') `
    (Join-Path $repositoryRoot 'rustolonia' 'samples' 'RustViewModelSample.Managed' 'Generated') `
    (Join-Path $repositoryRoot 'rustolonia' 'host' 'Generated' 'ViewModels') `
    (Join-Path $repositoryRoot 'rustolonia' 'rust' 'avalonia' 'src' 'generated_view_models.rs') `
    (Join-Path $repositoryRoot 'rustolonia' 'rust' 'view-model.contract.md')
if ($LASTEXITCODE -ne 0)
{
    exit $LASTEXITCODE
}

Push-Location "$repositoryRoot\rustolonia\rust"
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
    dotnet build (Join-Path $repositoryRoot 'rustolonia' 'host' 'Avalonia.Host.csproj') -c $Configuration
    if ($LASTEXITCODE -ne 0)
    {
        exit $LASTEXITCODE
    }
}

Write-Host "==> [3/4] Building the Rust workspace"
$cargoArgs = @('--manifest-path', (Join-Path $repositoryRoot 'rustolonia' 'rust' 'Cargo.toml'), '--workspace')
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
    Write-Host "==> [3/4] Validating the external consumer template compiles standalone"
    $templateConsumer = Join-Path $repositoryRoot 'rustolonia' 'rust' 'target' 'template-validation'
    Remove-Item $templateConsumer -Recurse -Force -ErrorAction SilentlyContinue
    & (Join-Path $PSScriptRoot 'new-app.ps1') -Name template_validation -Destination $templateConsumer -ProducerRoot $repositoryRoot
    dotnet run --project (Join-Path $repositoryRoot 'rustolonia' 'projection' 'Avalonia.ViewModelProjection.Tool') -c $Configuration -- `
        (Join-Path $templateConsumer 'view-model.ir.json') `
        (Join-Path $templateConsumer 'managed' 'Generated') `
        (Join-Path $templateConsumer 'generated') `
        (Join-Path $templateConsumer 'generated' 'generated_view_models.rs') `
        (Join-Path $templateConsumer 'generated' 'view-model.contract.md') `
        --external-rust
    cargo check --manifest-path (Join-Path $templateConsumer 'Cargo.toml')
    if ($LASTEXITCODE -ne 0)
    {
        exit $LASTEXITCODE
    }
    Remove-Item $templateConsumer -Recurse -Force
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
