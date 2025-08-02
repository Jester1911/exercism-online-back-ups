def prepare_isbn_text(isbn: str) -> str:
    # if len(isbn) == 12, valid hyphen indices are: 1, 5, 11
    result = ''
    if len(isbn) == 10:
        for i, char in enumerate(isbn):
            if i == 9:
                if char.lower() == 'x' or char.isdigit():
                    result = isbn
            elif not char.isdigit():
                break
    elif len(isbn) == 13:
        for i in reversed(range(len(isbn))):
            # check digits where hyphens can exist
            if i == 12:
                if isbn[i].lower() != 'x' and not isbn[12].isdigit():
                    break
            elif (i == 11) or (i == 5) or (i == 1):
                if isbn[i] != '-':
                    break
            else:
                # check all digits expected to be numbers
                if not isbn[i].isdigit():
                    break
                else:
                    if i == 0:
                        result = isbn.replace('-', '')
    return result


def calculate_isbn_sum(isbn: str) -> int:
    """Accepts a preprocessed ISBN string of length 10 and performs ISBN algorithm"""
    if len(isbn) != 10:
        return -1
    else:
        check_char = isbn[9].lower()
        total = 0
        # Sum leftmost digits to right before check char
        for idx in range(0, len(isbn)):
            if idx == 9:
                # Determine check_char value and sum
                if check_char.isdigit():
                    total += int(check_char)
                else:
                    total += 10
            else:
                # All non-check char digits
                total += ((10 - idx) * int(isbn[idx]))

        return total % 11


def is_valid(isbn: str) -> bool:
    preprocessed_isbn = prepare_isbn_text(isbn)
    if len(preprocessed_isbn) != 0:
        return calculate_isbn_sum(preprocessed_isbn) == 0
    else:
        return False
