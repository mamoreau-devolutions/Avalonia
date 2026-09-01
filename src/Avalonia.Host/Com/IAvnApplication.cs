using System.Runtime.InteropServices;
using System.Runtime.InteropServices.Marshalling;

namespace Avalonia.Host.Com;

[GeneratedComInterface(StringMarshalling = StringMarshalling.Utf16)]
[Guid(AvnGuids.IAvnApplication)]
public partial interface IAvnApplication
{
    [PreserveSig]
    int Run(IAvnAppHandler? handler);

    [PreserveSig]
    int Shutdown();
}
