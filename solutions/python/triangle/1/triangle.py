def sides_greater_than_zero(sides: list) -> bool:
    """Determine if all sides are greater than zero"""
    for side in sides:
        if side <= 0:
            return False

    return True


def triangle_equality_rule(sides: list) -> bool:
    """Determine if the sides follow the Triangle Sides Rule"""
    if sides[0] <= sides[1] + sides[2]:
        if sides[1] <= sides[0] + sides[2]:
            if sides[2] <= sides[0] + sides[1]:
                return True

    return False


def viable_triangle(sides: list) -> bool:
    """Determine if the values in sides makes a triangle viable"""
    if sides_greater_than_zero(sides):
        if triangle_equality_rule(sides):
            return True

    return False


def equilateral(sides: list) -> bool:
    """Determine if sides result in Equilateral Triangle"""
    if viable_triangle(sides):
        if len(set(sides)) == 1:
            return True

    return False


def isosceles(sides: list) -> bool:
    """Determine if sides result in Isosceles Triangle"""
    if viable_triangle(sides):
        if not scalene(sides):
            return len(set(sides)) >= 1

    return False


def scalene(sides: list) -> bool:
    """Determine if sides result in Scalene triangle"""
    # Scalene Triangles have three unique sides
    # So if we convert the side List to a Set, we should count
    # 3 elements for a Scalene. Additionally, the length of the
    # set should be equal to the length of the list

    if viable_triangle(sides):
        return len(sides) == len(set(sides))
    else:
        return False
