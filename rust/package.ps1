param(
    [Parameter(Mandatory)]
    [ValidateSet("win-x64", "win-arm64")]
    [string]$Rid,
    [ValidateSet("Debug", "Release")]
    [string]$Configuration = "Release",
    [string]$Example = "hello_world",
    [string]$OutputRoot,
    [switch]$SkipCargoBuild
)

$ErrorActionPreference = "Stop"
$repositoryRoot = Split-Path -Parent $PSScriptRoot
if (-not $OutputRoot)
{
    $OutputRoot = Join-Path $PSScriptRoot "artifacts"
}
$destination = Join-Path $OutputRoot $Rid
$rustTarget = switch ($Rid)
{
    "win-x64" { "x86_64-pc-windows-msvc" }
    "win-arm64" { "aarch64-pc-windows-msvc" }
    default { throw "No Rust target triple is configured for RID '$Rid'." }
}
$rustFlagsVariable = "CARGO_TARGET_$($rustTarget.ToUpperInvariant().Replace('-', '_'))_RUSTFLAGS"
$rustFlags = [Environment]::GetEnvironmentVariable($rustFlagsVariable, "Process")
if ($rustFlags -notlike "*target-feature=+crt-static*")
{
    [Environment]::SetEnvironmentVariable(
        $rustFlagsVariable,
        "$rustFlags -C target-feature=+crt-static".Trim(),
        "Process")
}
$installedRustTargets = & rustup target list --installed
if ($LASTEXITCODE -ne 0 -or $installedRustTargets -notcontains $rustTarget)
{
    throw "Rust target '$rustTarget' required for RID '$Rid' is missing. Install it with: rustup target add $rustTarget"
}

Write-Host "==> Publishing Avalonia.Host ($Rid, $Configuration)"
dotnet publish "$repositoryRoot\src\Avalonia.Host\Avalonia.Host.csproj" `
    -c $Configuration -r $Rid -p:AvaloniaRustHostPlatform=Win32
if ($LASTEXITCODE -ne 0)
{
    exit $LASTEXITCODE
}

$publishDir = Join-Path $repositoryRoot "src\Avalonia.Host\bin\$Configuration\net10.0\$Rid\publish"
$hostFile = Join-Path $publishDir "Avalonia.Host.dll"
if (-not (Test-Path $hostFile))
{
    throw "NativeAOT host was not produced at $hostFile"
}

if (Test-Path $destination)
{
    Remove-Item $destination -Recurse -Force
}
New-Item -ItemType Directory -Path $destination -Force | Out-Null

Write-Host "==> Copying host and native dependencies into $destination"
Copy-Item $hostFile $destination
foreach ($dependency in @("libSkiaSharp.dll", "libHarfBuzzSharp.dll"))
{
    $dependencyPath = Join-Path $publishDir $dependency
    if (Test-Path $dependencyPath)
    {
        Copy-Item $dependencyPath $destination
    }
    Copy-Item (Join-Path $repositoryRoot "licence.md") $destination
}

if (-not $SkipCargoBuild)
{
    Write-Host "==> Building Rust example '$Example' ($Configuration) next to the host"
    $cargoArgs = @("build", "--manifest-path", "$repositoryRoot\rust\Cargo.toml", "-p", "avalonia", "--example", $Example, "--target", $rustTarget)
    $profileDirectory = "debug"
    if ($Configuration -eq "Release")
    {
        $cargoArgs += "--release"
        $profileDirectory = "release"
    }
    cargo @cargoArgs
    if ($LASTEXITCODE -ne 0)
    {
        exit $LASTEXITCODE
    }
    $exePath = Join-Path $repositoryRoot "rust\target\$rustTarget\$profileDirectory\examples\$Example.exe"
    if (-not (Test-Path $exePath))
    {
        throw "Rust example binary was not produced at $exePath"
    }
    Copy-Item $exePath $destination
}

if ($env:AVALONIA_RUST_SIGN_COMMAND)
{
    $signer = $env:AVALONIA_RUST_SIGN_COMMAND
    if (-not (Test-Path $signer -PathType Leaf))
    {
        throw "AVALONIA_RUST_SIGN_COMMAND must be the path to a signing wrapper executable or script."
    }
    Write-Host "==> Signing executable artifacts with AVALONIA_RUST_SIGN_COMMAND"
    Get-ChildItem $destination -File | Where-Object { $_.Extension -in @(".dll", ".exe") } | ForEach-Object {
        Write-Host "    signing $($_.Name)"
        & $signer $_.FullName
        if ($LASTEXITCODE -ne 0)
        {
            throw "Signing command failed for $($_.Name)"
        }
    }
}
else
{
    Write-Host "AVALONIA_RUST_SIGN_COMMAND is not set; skipping signing." `
        "Set it to a trusted signing wrapper executable/script path; it receives each artifact path as its only argument." `
        "This script never downloads a signing tool."
}

Write-Host "==> Writing deterministic CycloneDX delivery SBOM"
python "$PSScriptRoot\generate-sbom.py" --rid $Rid --bundle $destination
if ($LASTEXITCODE -ne 0)
{
    exit $LASTEXITCODE
}

Write-Host "==> Writing checksums.sha256"
$checksumPath = Join-Path $destination "checksums.sha256"
Get-ChildItem $destination -File |
    Where-Object { $_.Name -ne "checksums.sha256" } |
    Sort-Object Name |
    ForEach-Object {
        $hash = (Get-FileHash $_.FullName -Algorithm SHA256).Hash.ToLowerInvariant()
        "$hash *$($_.Name)"
    } |
    Set-Content -Path $checksumPath -Encoding ascii

Write-Host "Package layout ready at $destination"
Get-ChildItem $destination | Select-Object Name, Length | Format-Table -AutoSize
