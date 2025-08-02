def square_root(number: int) -> int:
    # using an abbreviated Newton's approximation
    # approach. This only works because the problem states
    # that the square roots are Natural numbers.
    for x in range(1, number + 1):
        if (x * x) == number:
            return x
    return -1
