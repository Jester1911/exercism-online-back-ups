public static class LogAnalysis 
{
    public static string SubstringAfter(this string str, string separator)
    {
        ArgumentNullException.ThrowIfNull(str);
        ArgumentNullException.ThrowIfNull(separator);
        var separatorIdx = str.IndexOf(separator);
        if  (separatorIdx == -1 || separatorIdx + 1 >= str.Length) 
        {
            return str;
        }
        return str[(str.IndexOf(separator) + separator.Length)..];
    }

    public static string SubstringBetween(this string str, string start, string end)
    {
        ArgumentNullException.ThrowIfNull(str);
        ArgumentNullException.ThrowIfNull(start);
        ArgumentNullException.ThrowIfNull(end);
        var startIdx = str.IndexOf(start);
        var endIdx = str.IndexOf(end);
        if (startIdx == -1 || endIdx == -1 || startIdx >= endIdx) return str;
        return str[(startIdx + start.Length)..endIdx];
    }

    public static string Message(this string str)
    {
        ArgumentNullException.ThrowIfNull(str);
        var colonIdx = str.IndexOf(":");
        if (colonIdx == -1) return str;
        return str[(colonIdx + 1)..].Trim();
    }

    public static string LogLevel(this string str)
    {
        ArgumentNullException.ThrowIfNull(str);
        var startIdx = str.IndexOf("[");
        var endIx = str.IndexOf("]");
        if (startIdx < 0 || endIx < 0 || startIdx >= endIx)
        {
            return str;
        }
        return str[(startIdx+"[".Length)..endIx];
    }
}