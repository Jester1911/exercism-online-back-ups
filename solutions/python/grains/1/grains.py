def square(number):
    """Compute the number of grain on a given square"""

    # A Chess board has only 64 squares
    if number <= 0 or number > 64:
        raise ValueError('square must be between 1 and 64')

    # If we double the number of grain on each successive
    # square, the nth square has (2 ** (n-1))
    return 2 ** (number - 1)


def total():
    """Determine the total number of grains on a chess board"""
    total_grain = 0

    for square_num in range(1, 65):
        total_grain += square(square_num)

    return total_grain
