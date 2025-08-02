def get_color_values() -> dict[str, int]:
    """Return dictionary of resistor color as k and resistor value as v"""
    color_values: dict[str, int] = {
        'black': 0,
        'brown': 1,
        'red': 2,
        'orange': 3,
        'yellow': 4,
        'green': 5,
        'blue': 6,
        'violet': 7,
        'grey': 8,
        'white': 9,
    }

    return color_values


def value(colors: str) -> int:
    # get first two colors out of string, discard any colors after first two
    c = [colors[0], colors[1]]

    # get mapping of color to values
    mapping = get_color_values()

    # map color names to values
    vals = [mapping[k] for k in c]

    result = vals[0] * 10 + vals[1]

    return result
