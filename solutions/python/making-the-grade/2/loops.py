"""Functions for organizing and calculating student exam scores."""

FAIL_SCORE = 40


def round_scores(student_scores: list[int | float]) -> list[int]:
    """Round all provided student scores.

    :param student_scores: list - float or int of student exam scores.
    :return: list - student scores *rounded* to nearest integer value.
    """
    rounded_scores = []
    for score in student_scores:
        rounded_scores.append(round(score))

    return rounded_scores


def count_failed_students(student_scores: list[int | float]) -> int:
    """Count the number of failing students out of the group provided.

    :param student_scores: list - containing int student scores.
    :return: int - count of student scores at or below 40.
    """

    failed_students = 0
    for score in student_scores:
        if score <= FAIL_SCORE:
            failed_students += 1

    return failed_students


def above_threshold(student_scores, threshold):
    """Determine how many of the provided student scores were 'the best' based on the provided threshold.

    :param student_scores: list - of integer scores.
    :param threshold: int - threshold to cross to be the "best" score.
    :return: list - of integer scores that are at or above the "best" threshold.
    """

    scores_above_threshold = []
    for score in student_scores:
        if score >= threshold:
            scores_above_threshold.append(score)

    return scores_above_threshold


def letter_grades(highest: int):
    """Create a list of grade thresholds based on the provided highest grade.

    :param highest: int - value of highest exam score.
    :return: list - of lower threshold scores for each D-A letter grade interval.
            For example, where the highest score is 100, and failing is <= 40,
            The result would be [41, 56, 71, 86]:

            41 <= "D" <= 55
            56 <= "C" <= 70
            71 <= "B" <= 85
            86 <= "A" <= 100
    """

    # find the span between the highest score and 40, then divide by the number of
    # grade ranges to get the span between the UPPER THRESHOLD of each grade range
    upper_threshold = highest
    span = (highest - FAIL_SCORE) / 4

    upper = []
    for x in range(1, 5):
        upper.append(int(upper_threshold - span*x + 1))
        
    upper.sort()

    return upper


def student_ranking(student_scores: list[int], student_names: list[str]) -> list[str]:
    """Organize the student's rank, name, and grade information in descending order.

    :param student_scores: list - of scores in descending order.
    :param student_names: list - of string names by exam score in descending order.
    :return: list - of strings in format ["<rank>. <student name>: <score>"].
    """
    results = []

    for index, name in enumerate(student_names):
        entry = str(index + 1) + '. ' + name + ': ' + str(student_scores[index])
        results.append(entry)

    return results


def perfect_score(student_info: list) -> list:
    """Create a list that contains the name and grade of the first student to make a perfect score on the exam.

    :param student_info: list - of [<student name>, <score>] lists.
    :return: list - first `[<student name>, 100]` or `[]` if no student score of 100 is found.
    """

    for entry in student_info:
        if entry[1] == 100:
            return entry

    return []
