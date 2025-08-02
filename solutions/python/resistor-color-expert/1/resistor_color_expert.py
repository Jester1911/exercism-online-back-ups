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


def get_tolerance(tolerance: str) -> str | None:
    tolerance_values = {
        'grey': '±0.05%',
        'violet': '±0.1%',
        'blue': '±0.25%',
        'green': '±0.5%',
        'brown': '±1%',
        'red': '±2%',
        'gold': '±5%',
        'silver': '±10%'
    }

    if tolerance in tolerance_values.keys():
        return tolerance_values[tolerance]


def resistor_label(colors: list[str]) -> str:
    if len(colors) == 1:
        return '0 ohms'

    first_digit = get_color_value(colors[0])
    second_digit = get_color_value(colors[1])
    if len(colors) == 4:
        num_zeros = get_color_value(colors[2])
        total = ((first_digit * 10) + second_digit) * (10 ** num_zeros)
    elif len(colors) == 5:
        num_zeros = get_color_value(colors[3])
        third_digit = get_color_value(colors[2])
        total = ((first_digit * 100) + (second_digit * 10) + third_digit) * (10 ** num_zeros)

    if len(colors) == 4:
        tolerance = ' ' + get_tolerance(colors[3])
    elif len(colors) == 5:
        tolerance = ' ' + get_tolerance(colors[4])
    else:
        tolerance = ''

    s = ''

    if total >= 10 ** 9:
        first_part = total / (10 ** 9)
        if first_part % 1 == 0:
            first_part = int(first_part)
        s = str(first_part) + ' gigaohms' + tolerance

    elif total >= 10 ** 6:
        first_part = total / (10 ** 6)
        if first_part % 1 == 0:
            first_part = int(first_part)
        s = str(first_part) + ' megaohms' + tolerance

    elif total >= 10 ** 3:
        first_part = total / (10 ** 3)
        if first_part % 1 == 0:
            first_part = int(first_part)
        s = str(first_part) + ' kiloohms' + tolerance

    else:
        s = str(total) + ' ohms' + tolerance

    return s
