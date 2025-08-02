def leap_year(year) -> bool:
    """Determine if a given year is a leap year.

    Leap years are:
        - Every year evenly divisible by 4.
        - Unless the year is evenly divisible by 100. In this case,
        the year is only a leap year if it is evenly divisible by
        400.
    """

    if year % 100 == 0:
        if year % 400 == 0:
            return True
    elif year % 4 == 0:
        return True

    return False
