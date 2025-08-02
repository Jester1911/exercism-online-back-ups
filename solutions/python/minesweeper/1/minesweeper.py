def get_value_at_row_col(table: list[str], row: int, col: int) -> str:
    """Returns string found at row-column of list"""
    return table[row][col]


def annotate(minefield: list[str]) -> list[str]:
    result: list[str] = []
    last_row_idx = len(minefield) - 1

    for row_idx, row in enumerate(minefield):

        if len(row) != len(minefield[0]):
            raise ValueError("The board is invalid with current input.")

        last_col_idx = len(row) - 1
        s = ''

        for col_idx, col in enumerate(row):
            mine_count = 0

            if col == "*":
                s += '*'
                continue
            elif col != ' ':
                raise ValueError("The board is invalid with current input.")

            # adjacent col to left
            if col_idx - 1 >= 0:
                if get_value_at_row_col(minefield, row_idx, col_idx - 1) == "*":
                    mine_count += 1

            # adjacent column to right
            if col_idx + 1 <= last_col_idx:
                if get_value_at_row_col(minefield, row_idx, col_idx + 1) == "*":
                    mine_count += 1

            if row_idx - 1 >= 0:
                # previous row, same col (directly above)
                if get_value_at_row_col(minefield, row_idx - 1, col_idx) == "*":
                    mine_count += 1

                if col_idx - 1 >= 0:
                    # previous row, previous column (diagonal up left)
                    if get_value_at_row_col(minefield, row_idx - 1, col_idx - 1) == "*":
                        mine_count += 1

                if col_idx + 1 <= last_col_idx:
                    # previous row, next column (diagonal up right)
                    if get_value_at_row_col(minefield, row_idx - 1, col_idx + 1) == "*":
                        mine_count += 1

            if row_idx + 1 <= last_row_idx:
                # next row, same col (directly below)
                if get_value_at_row_col(minefield, row_idx + 1, col_idx) == "*":
                    mine_count += 1

                if col_idx - 1 >= 0:
                    # next row, previous col (diagonal down left)
                    if get_value_at_row_col(minefield, row_idx + 1, col_idx - 1) == "*":
                        mine_count += 1

                if col_idx + 1 <= last_col_idx:
                    # next row, next col (diagonal down right)
                    if get_value_at_row_col(minefield, row_idx + 1, col_idx + 1) == "*":
                        mine_count += 1

            if mine_count == 0:
                s += ' '
            else:
                s += str(mine_count)
        # add formatted row
        result.append(s)

    return result
