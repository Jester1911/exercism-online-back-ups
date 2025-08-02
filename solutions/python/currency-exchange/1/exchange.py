"""Functions for calculating steps in exchanging currency.

Python numbers documentation: https://docs.python.org/3/library/stdtypes.html#numeric-types-int-float-complex

Overview of exchanging currency when travelling: https://www.compareremit.com/money-transfer-tips/guide-to-exchanging-currency-for-overseas-travel/
"""


def exchange_money(budget: float, exchange_rate: float) -> float:
    """

    :param budget: float - amount of money you are planning to exchange.
    :param exchange_rate: float - unit value of the foreign currency.
    :return: float - exchanged value of the foreign currency you can receive.
    """

    if exchange_rate > 0:
        return budget / exchange_rate
    else:
        return 0


def get_change(budget: float, exchanging_value: float) -> float:
    """

    :param budget: float - amount of money you own.
    :param exchanging_value: float - amount of your money you want to exchange now.
    :return: float - amount left of your starting currency after exchanging.
    """

    if budget - exchanging_value >= 0:
        return budget - exchanging_value
    else:
        raise ValueError("Budget - Exchange Value cannot be negative.")


def get_value_of_bills(denomination: int, number_of_bills: int) -> int:
    """

    :param denomination: int - the value of a bill.
    :param number_of_bills: int - total number of bills.
    :return: int - calculated value of the bills.
    """

    return denomination * number_of_bills


def get_number_of_bills(amount: float, denomination: int) -> int:
    """

    :param amount: float - the total starting value.
    :param denomination: int - the value of a single bill.
    :return: int - number of bills that can be obtained from the amount.
    """

    return int(amount // denomination)


def get_leftover_of_bills(amount: float, denomination: int) -> float:
    """

    :param amount: float - the total starting value.
    :param denomination: int - the value of a single bill.
    :return: float - the amount that is "leftover", given the current denomination.
    """

    if denomination > 0:
        return amount % denomination
    else:
        return 0


def exchangeable_value(budget: float, exchange_rate: float, spread: float, denomination: int) -> int:
    """

    :param budget: float - the amount of your money you are planning to exchange.
    :param exchange_rate: float - the unit value of the foreign currency.
    :param spread: int - percentage that is taken as an exchange fee.
    :param denomination: int - the value of a single bill.
    :return: int - maximum value you can get.
    """

    eff_exchange_rate = exchange_rate + (exchange_rate * spread * 0.01)
    exchanged_value = exchange_money(budget=budget, exchange_rate=eff_exchange_rate)
    num_bills = get_number_of_bills(amount=exchanged_value, denomination=denomination)
    value_bills = get_value_of_bills(denomination=denomination, number_of_bills=num_bills)

    return value_bills
