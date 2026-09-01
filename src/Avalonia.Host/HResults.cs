namespace Avalonia.Host;

internal static class HResults
{
    public const int S_OK = 0;
    public const int E_POINTER = unchecked((int)0x80004003);
    public const int E_FAIL = unchecked((int)0x80004005);
    public const int E_INVALIDARG = unchecked((int)0x80070057);

    /// <summary>Fixture-only failure used to prove PreserveSig HRESULT passthrough.</summary>
    public const int AVN_E_FIXTURE = unchecked((int)0xA7A70001);
}
