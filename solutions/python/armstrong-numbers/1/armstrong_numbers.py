def is_armstrong_number(number) -> bool:
    """Determine if a number is an Armstrong number

    An Armstrong number is a number that is the sum of its own digits, each raised
    to the number of digits of the number. This implies that all Armstrong
    numbers must be positive.
        ex: 9 is an Armstrong number: 9 -> 9^1 = 9
        ex: 10 is not an Armstrong number: 10 -> 1^2 + 0^2 != 10

    :param number:
    :type number:

    :return: True if number is an Armstrong number, False otherwise.
    """

    digits = [int(d) for d in str(number)]  # get each digit of the number
    num_digits = len(digits)
    value = sum(x ** num_digits for x in digits)  # perform Armstrong algorithm

    return number == value
