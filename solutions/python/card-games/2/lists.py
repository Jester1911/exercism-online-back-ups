"""Functions for tracking poker hands and assorted card tasks.

Python list documentation: https://docs.python.org/3/tutorial/datastructures.html
"""


def get_rounds(number: int) -> list[int]:
    """Create a list containing the current and next two round numbers.

    :param number: int - current round number.
    :return: list - current round and the two that follow.
    """
    rounds = list(range(number, number + 3))

    return rounds


def concatenate_rounds(rounds_1, rounds_2):
    """Concatenate two lists of round numbers.

    :param rounds_1: list - first rounds played.
    :param rounds_2: list - second set of rounds played.
    :return: list - all rounds played.
    """

    return rounds_1 + rounds_2


def list_contains_round(rounds: list[int], number: int) -> bool:
    """Check if the list of rounds contains the specified number.

    :param rounds: list - rounds played.
    :param number: int - round number.
    :return: bool - was the round played?
    """

    return number in rounds


def card_average(hand: list[int]) -> float:
    """Calculate and returns the average card value from the list.

    :param hand: list - cards in hand.
    :return: float - average value of the cards in the hand.
    """

    total = 0
    for item in hand:
        total += item

    return total / len(hand)


def approx_average_is_average(hand: list[int]) -> bool:
    """Return if the (average of first and last card values) OR ('middle' card) == calculated average.

    :param hand: list - cards in hand.
    :return: bool - does one of the approximate averages equal the `true average`?
    """

    # sort hand in ascending order
    actual_avg = card_average(hand)
    first_last = (hand[0] + hand[len(hand) - 1]) / 2
    median_value = hand[(len(hand) - 1) // 2]

    print(f'Actual average is: {actual_avg}')
    print(f'First Last: {first_last}')
    print(f'Median: {median_value}\n')

    return actual_avg in (median_value, first_last)


def average_even_is_average_odd(hand: list[int]) -> bool:
    """Return if the (average of even indexed card values) == (average of odd indexed card values).

    :param hand: list - cards in hand.
    :return: bool - are even and odd averages equal?
    """
    even_sum = 0
    number_of_even = 0
    odd_sum = 0
    number_of_odd = 0

    for index, item in enumerate(hand):
        if index % 2 == 0:
            even_sum += item
            number_of_even += 1
        else:
            odd_sum += item
            number_of_odd += 1

    return even_sum / number_of_even == odd_sum / number_of_odd


def maybe_double_last(hand: list[int]) -> list[int]:
    """Multiply a Jack card value in the last index position by 2.

    :param hand: list - cards in hand.
    :return: list - hand with Jacks (if present) value doubled.
    """

    if hand[-1] == 11:
        hand[-1] = 22

    return hand
