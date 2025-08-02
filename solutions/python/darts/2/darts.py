import math

DISTANCE_SCORE = {1: 10, 5: 5, 10: 1}


def calculate_distance(x: int, y: int) -> float:
    distance = math.sqrt(x ** 2 + y ** 2)
    return distance


def distance_score(distance: float) -> int:
    if distance <= 1:
        return DISTANCE_SCORE[1]
    elif distance <= 5:
        return DISTANCE_SCORE[5]
    elif distance <= 10:
        return DISTANCE_SCORE[10]
    else:
        return 0


def score(x, y):
    distance = calculate_distance(x, y)
    value = distance_score(distance)

    return value
