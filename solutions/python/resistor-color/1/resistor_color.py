"""
    black: 0
    brown: 1
    red: 2
    orange: 3
    yellow: 4
    green: 5
    blue: 6
    violet: 7
    grey: 8
    white: 9
"""


def color_map() -> dict[str, int]:
    colors_mapping = {
        "black": 0,
        "brown": 1,
        "red": 2,
        "orange": 3,
        "yellow": 4,
        "green": 5,
        "blue": 6,
        "violet": 7,
        "grey": 8,
        "white": 9
    }

    return colors_mapping


def color_code(color: str) -> int:
    color_mapping: dict[str, int] = {
        "black": 0,
        "brown": 1,
        "red": 2,
        "orange": 3,
        "yellow": 4,
        "green": 5,
        "blue": 6,
        "violet": 7,
        "grey": 8,
        "white": 9
    }

    return color_mapping[color]


def colors():
    result: list[str] = []
    # keys are string name of colors; value is the list index the color name should be stored
    color_mapping = color_map()
    for key in color_mapping.keys():
        result.insert(color_mapping[key], key)

    return result
