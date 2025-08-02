def collatz_algo(number):
    """Execute the Collatz conjecture algorithm."""
    if number <= 0:
        raise ValueError('Only positive integers are allowed')

    if number % 2 == 0:
        return number // 2
    else:
        return number * 3 + 1


def steps(number):
    num_steps = 0
    while number != 1:
        number = collatz_algo(number)
        num_steps += 1

    return num_steps
