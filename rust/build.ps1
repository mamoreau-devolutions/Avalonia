param(
    [ValidateSet("x64", "arm64")]
    [string]$Architecture = "x64",
    [switch]$RunExamples
)

$ErrorActionPreference = "Stop"
$repositoryRoot = Split-Path -Parent $PSScriptRoot
$nativeArchitecture = switch ([System.Runtime.InteropServices.RuntimeInformation]::OSArchitecture)
{
    "X64" { "x64"; break }
    "Arm64" { "arm64"; break }
    default { throw "Unsupported Windows CPU architecture: $([System.Runtime.InteropServices.RuntimeInformation]::OSArchitecture)" }
}
if ($Architecture -ne $nativeArchitecture)
{
    throw "win-$Architecture requires a Windows runner with a matching $Architecture CPU because cargo tests execute native binaries."
}
$rid = "win-$Architecture"
$rustTarget = if ($Architecture -eq "x64") { "x86_64-pc-windows-msvc" } else { "aarch64-pc-windows-msvc" }
$rustFlagsVariable = "CARGO_TARGET_$($rustTarget.ToUpperInvariant().Replace('-', '_'))_RUSTFLAGS"
$rustFlags = [Environment]::GetEnvironmentVariable($rustFlagsVariable, "Process")
if ($rustFlags -notlike "*target-feature=+crt-static*")
{
    [Environment]::SetEnvironmentVariable(
        $rustFlagsVariable,
        "$rustFlags -C target-feature=+crt-static".Trim(),
        "Process")
}

dotnet publish "$repositoryRoot\src\Avalonia.Host\Avalonia.Host.csproj" `
    -c Release -r $rid -p:AvaloniaRustHostPlatform=Win32
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
