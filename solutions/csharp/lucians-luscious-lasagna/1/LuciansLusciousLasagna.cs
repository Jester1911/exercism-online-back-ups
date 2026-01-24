class Lasagna
{
    private int _oven_time_left = 40;
    private int _prep_time = 0;

    // TODO: define the 'ExpectedMinutesInOven()' method
    public int ExpectedMinutesInOven()
    {
        _oven_time_left = 40;
        return _oven_time_left;
    }

    // TODO: define the 'RemainingMinutesInOven()' method
    public int RemainingMinutesInOven(int mins)
    {
        _oven_time_left -= mins;
        return _oven_time_left;
    }

    // TODO: define the 'PreparationTimeInMinutes()' method
    public int PreparationTimeInMinutes(int layers)
    {
        _prep_time = 2 * layers;
        return _prep_time;
    }

    // TODO: define the 'ElapsedTimeInMinutes()' method
    public int ElapsedTimeInMinutes(int layers, int time_in_oven_mins)
    {
      return (2 * layers + time_in_oven_mins);
    }
}   
