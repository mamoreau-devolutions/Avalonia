param(
    [Parameter(Mandatory)]
    [ValidatePattern('^[a-z][a-z0-9_]*$')]
    [string]$Name,
    [Parameter(Mandatory)]
    [string]$Destination
)

$ErrorActionPreference = "Stop"

$templateDir = Join-Path $PSScriptRoot "templates\avalonia-app"
if (-not (Test-Path $templateDir))
{
    throw "Template directory not found at $templateDir"
}
if (Test-Path $Destination)
{
    throw "Destination '$Destination' already exists."
}

Copy-Item $templateDir $Destination -Recurse
Get-ChildItem -Path $Destination -Recurse -Directory -Filter "target" |
    Remove-Item -Recurse -Force
Remove-Item -Path (Join-Path $Destination "Cargo.lock") -ErrorAction SilentlyContinue

$cargoToml = Join-Path $Destination "Cargo.toml"
$content = Get-Content $cargoToml -Raw
$content = $content.Replace("avalonia-app-template", $Name)
Set-Content -Path $cargoToml -Value $content -NoNewline

Write-Host "Created '$Name' at $Destination."
Write-Host "Next steps:"
Write-Host "  1. Update the 'avalonia' path dependency in $cargoToml to point at" `
    "your Avalonia checkout (or vendor rust/avalonia + rust/avalonia-sys)."
Write-Host "  2. cargo build --release --manifest-path `"$Destination\Cargo.toml`""
Write-Host "  3. Publish/copy a matching Avalonia.Host next to the built binary --" `
    "rust\package.ps1 produces that layout -- then run the binary directly."
