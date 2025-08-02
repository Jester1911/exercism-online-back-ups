"""Functions to help play and score a game of blackjack.

How to play blackjack:    https://bicyclecards.com/how-to-play/blackjack/
"Standard" playing cards: https://en.wikipedia.org/wiki/Standard_52-card_deck
"""


def determine_higher_non_ace_non_royal(card_one: str, card_two: str) -> str:
    """Return higher card of two non-Ace, non-Royal cards"""
    if ord(card_one) > ord(card_two):
        return card_one
    else:
        return card_two


def either_card_is_value(card_one: str, card_two: str, target_card: str) -> bool:
    """Returns True if either cards are equal to the target card"""
    if card_one is target_card or card_two is target_card:
        return True
    else:
        return False


def value_of_card(card: str) -> int:
    """Determine the scoring value of a card.

    :param card: str - given card.
    :return: int - value of a given card.  See below for values.

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 1
    3.  '2' - '10' = numerical value.
    """
    value = 0

    if card.isdigit():
        value = int(card)
    elif card in ('J', 'Q', 'K'):
        value = 10
    elif card is 'A':
        value = 1

    return value


def higher_card(card_one: str, card_two: str) -> str or tuple:
    """Determine which card has a higher value in the hand.

    :param card_one, card_two: str - cards dealt in hand.  See below for values.
    :return: str or tuple - resulting Tuple contains both cards if they are of equal value.

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 1
    3.  '2' - '10' = numerical value.
    """

    # Use ord to determine unicode equivalent. I believe
    # unicode stores English characters and numbers in ascending
    # order
    if card_one == card_two:
        return card_one, card_two
    elif card_one in ('10', 'J', 'Q', 'K') and card_two in ('10', 'J', 'Q', 'K'):
        return card_one, card_two
    elif card_one in ('10', 'J', 'Q', 'K'):
        return card_one
    elif card_two in ('10', 'J', 'Q', 'K'):
        return card_two
    elif card_one is 'A':
        return card_two
    elif card_two is 'A':
        return card_one
    else:
        return determine_higher_non_ace_non_royal(card_one, card_two)


def value_of_ace(card_one: str, card_two: str) -> int:
    """Calculate the most advantageous value for the ace card.

    :param card_one, card_two: str - card dealt. See below for values.
    :return: int - either 1 or 11 value of the upcoming ace card.

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 11 (if already in hand)
    3.  '2' - '10' = numerical value.
    """

    hand_value = 0
    delta_to_21 = 0

    if either_card_is_value(card_one, card_two, 'A'):
        hand_value += 11

    if card_one in ('J', 'Q', 'K'):
        hand_value += 10

    if card_two in ('J', 'Q', 'K'):
        hand_value += 10

    if card_one.isdigit():
        hand_value += value_of_card(card_one)

    if card_two.isdigit():
        hand_value += value_of_card(card_two)

    delta_to_21 = 21 - hand_value

    if delta_to_21 >= 11:
        return 11
    else:
        return 1


def is_blackjack(card_one: str, card_two: str) -> bool:
    """Determine if the hand is a 'natural' or 'blackjack'.

    :param card_one, card_two: str - card dealt. See below for values.
    :return: bool - is the hand is a blackjack (two cards worth 21).

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 11 (if already in hand)
    3.  '2' - '10' = numerical value.
    """

    if not (either_card_is_value(card_one, card_two, 'A')):
        return False
    elif card_one is 'A':
        if card_two in ('10', 'J', 'Q', 'K'):
            return True

    elif card_two is 'A':
        if card_one in ('10', 'J', 'Q', 'K'):
            return True

    return False


def can_split_pairs(card_one: str, card_two: str) -> bool:
    """Determine if a player can split their hand into two hands.

    :param card_one, card_two: str - cards dealt.
    :return: bool - can the hand be split into two pairs? (i.e. cards are of the same value).
    """

    if card_one is card_two:
        return True
    elif card_one in ('10', 'J', 'Q', 'K'):
        if card_two in ('10', 'J', 'Q', 'K'):
            return True

    return False


def can_double_down(card_one, card_two):
    """Determine if a blackjack player can place a double down bet.

    :param card_one, card_two: str - first and second cards in hand.
    :return: bool - can the hand can be doubled down? (i.e. totals 9, 10 or 11 points).
    """

    pair_value = value_of_card(card_one) + value_of_card(card_two)

    if pair_value in (9, 10, 11):
        return True
    else:
        return False
