using System;
using System.IO;
using Avalonia.Projection.Generator;
using Avalonia.Projection.Ir;

var externalRust = args.Length == 6 && args[5] == "--external-rust";
if (args.Length != 5 && !externalRust)
{
    Console.Error.WriteLine(
        "Usage: Avalonia.ViewModelProjection.Tool <view-model-ir> <adapter-output-directory> <registry-output-directory> <rust-output> <contract-output> [--external-rust]");
    return 2;
}

var ir = ViewModelIr.FromJson(File.ReadAllText(Path.GetFullPath(args[0])));
var adapterDirectory = Path.GetFullPath(args[1]);
var registryDirectory = Path.GetFullPath(args[2]);
var rustPath = Path.GetFullPath(args[3]);
var contractPath = Path.GetFullPath(args[4]);
Directory.CreateDirectory(adapterDirectory);
Directory.CreateDirectory(registryDirectory);
Directory.CreateDirectory(Path.GetDirectoryName(rustPath)!);
Directory.CreateDirectory(Path.GetDirectoryName(contractPath)!);

foreach (var existing in Directory.EnumerateFiles(adapterDirectory, "*.g.cs"))
    File.Delete(existing);
foreach (var existing in Directory.EnumerateFiles(registryDirectory, "RustViewRegistry.g.cs"))
    File.Delete(existing);
foreach (var (name, source) in ViewModelSourceEmitter.EmitCSharp(ir))
{
    var directory = name == "RustViewRegistry.g.cs"
        ? registryDirectory
        : adapterDirectory;
    File.WriteAllText(Path.Combine(directory, name), source);
}
File.WriteAllText(rustPath, ViewModelSourceEmitter.EmitRust(ir, externalRust));
File.WriteAllText(contractPath, ViewModelSourceEmitter.EmitContract(ir));

Console.WriteLine(
    $"Generated {ir.Models.Count} view model(s) and {ir.Views.Count} view(s).");
return 0;
