def get_color_value(color: str) -> int | None:
    color_value = {
        'black': 0,
        'brown': 1,
        'red': 2,
        'orange': 3,
        'yellow': 4,
        'green': 5,
        'blue': 6,
        'violet': 7,
        'grey': 8,
        'white': 9
    }

    if color in color_value.keys():
        return color_value[color]


def get_metric_prefix(num_zeros: int) -> str | None:
    metric_prefix = {
        1: 'kilo',
        2: 'mega',
        3: 'giga'
    }

    if num_zeros in metric_prefix.keys():
        return metric_prefix[num_zeros]


def label(colors: list[str]) -> str:
    first_digit = get_color_value(colors[0])
    second_digit = get_color_value(colors[1])
    num_zeros = get_color_value(colors[2])
    total = ((first_digit * 10) + second_digit) * (10 ** num_zeros)
    s = ''

    if total >= 10 ** 9:
        first_part = total // (10 ** 9)
        s = str(first_part) + ' gigaohms'
    elif total >= 10 ** 6:
        first_part = total // (10 ** 6)
        s = str(first_part) + ' megaohms'
    elif total >= 10 ** 3:
        first_part = total // (10 ** 3)
        s = str(first_part) + ' kiloohms'
    else:
        s = str(total) + ' ohms'

    return s
