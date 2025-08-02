"""
    1. Use a stack for the data structure
    2. The middle row should be the letter taken as input
    3. Use the ordinal ASCII number for finding how many rows to middle row;
        only capital letters needed
    4. There are n rows to the middle row and each row has (n - row number) leading and
        trailing spaces. Leading/Trailing spaces are reduced as you work towards the middle row.
    5. The spaces between letters after the first row and before the last row are equal to
        2 * (row number - 1) - 1. Internal spaces grow as you work towards the middle row.
    6. We should only have to build the list up to the middle row, then we take a slice of the first section up
        to but not including middle, reverse it, and append it.
"""


def get_num_rows_to_middle_row(letter: str) -> int:
    offset = ord(letter) - ord('A') + 1
    return offset


def get_spaces(num_spaces: int) -> str:
    spaces = ''
    for i in range(num_spaces):
        spaces += ' '

    return spaces


def rows(letter: str) -> list[str]:
    num_rows_to_middle = get_num_rows_to_middle_row(letter)
    # list elements represent rows
    diamond: list[str] = []

    # Guard for single row
    if letter == 'A':
        return ['A']

    for i in range(1, num_rows_to_middle + 1):
        if i == 1:
            s = get_spaces(num_rows_to_middle - 1)
            s += 'A'
            s += get_spaces(num_rows_to_middle - 1)
            diamond.append(s)

        elif i < num_rows_to_middle:
            s = get_spaces(num_rows_to_middle - i)
            s += chr(ord('A') + i - 1)
            s += get_spaces(2 * (i - 1) - 1)
            s += chr(ord('A') + i - 1)
            s += get_spaces(num_rows_to_middle - i)
            diamond.append(s)

        elif i == num_rows_to_middle:
            s = chr(ord('A') + i - 1)
            s += get_spaces(2 * (i - 1) - 1)
            s += chr(ord('A') + i - 1)
            diamond.append(s)

    for i, row in enumerate(diamond[::-1]):
        if i == 0:
            continue
        diamond.append(row)

    return diamond


def row_printer(rows: list[str]) -> None:
    for row in rows:
        print(row)
