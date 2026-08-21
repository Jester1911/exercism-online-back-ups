static class LogLine
{
    public static string Message(string logLine)
    {
        ArgumentNullException.ThrowIfNull(logLine);
        var colonIdx = logLine.IndexOf(':');
        if (colonIdx >= 0 && colonIdx + 1 < logLine.Length - 1) 
        {
            return logLine[(colonIdx + 1)..].Trim();
        }
        return "";
    }

    public static string LogLevel(string logLine)
    {
        ArgumentNullException.ThrowIfNull(logLine);
        var colonIdx = logLine.IndexOf(':');
        if (colonIdx >= 0 && colonIdx - 1 <= logLine.Length) {
            return logLine[..logLine.IndexOf(':')].ToLower().Replace("[", "").Replace("]", "");
        }
        return "";
    }

    public static string Reformat(string logLine)
    {
        ArgumentNullException.ThrowIfNull(logLine);
        var message = LogLine.Message(logLine);
        var logLevel = LogLine.LogLevel(logLine);
        return $"{message} ({logLevel})";
    }
}
