def calc_aliquot_sum(number: int) -> int:
    aliquot_sum = 0
    for divisor in range(1, number):
        if number % divisor == 0:
            aliquot_sum += divisor

    return aliquot_sum


def classify(number: int) -> str:
    """ A perfect number equals the sum of its positive divisors.

    :param number: int a positive integer
    :return: str the classification of the input integer
    """

    if number < 1:
        raise ValueError('Classification is only possible for positive integers.')

    aliquot_sum = calc_aliquot_sum(number)

    if aliquot_sum == number:
        return 'perfect'
    elif number < aliquot_sum:
        return 'abundant'
    else:
        return 'deficient'
