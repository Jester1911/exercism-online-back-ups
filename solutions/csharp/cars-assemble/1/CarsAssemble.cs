static class AssemblyLine
{
    public static double SuccessRate(int speed)
    {
        double rate = speed switch
        {
            <= 0 => 0.0,
            <= 4 => 1.0,
            <= 8 => 0.9,
            <= 9 => 0.8,
            _ => 0.77,
        };
        return rate;
    }
    
    public static double ProductionRatePerHour(int speed)
    {
        const double partsPerHourPerSpeed = 221.0;
        return (double)speed * partsPerHourPerSpeed * SuccessRate(speed);
    }

    public static int WorkingItemsPerMinute(int speed)
    {
        const double minsInHour = 60.0;
        return (int)(ProductionRatePerHour(speed) / minsInHour);
    }
}
