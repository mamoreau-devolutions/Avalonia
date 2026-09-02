param(
    [Parameter(Mandatory)][string]$ProducerRoot,
    [Parameter(Mandatory)][string]$Manifest
)
$ErrorActionPreference = 'Stop'
& python (Join-Path $PSScriptRoot 'build-app.py') --producer-root $ProducerRoot --manifest $Manifest
exit $LASTEXITCODE
