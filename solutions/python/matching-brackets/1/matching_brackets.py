"""
    My approach for checking that all brackets, parentheses, and
    braces are balanced is to use a list. I will do a pass through
    the input and add all items to a list. If all items are balanced,
    I expect the list to:
        - Have a length that is even
        - That if I encounter an opening element (, {, [, the next
        special element I encounter should be:
            - A different opening element
            - The closing element of the previously opening type
"""

OPEN_BRACKET = '['
CLOSE_BRACKET = ']'
OPEN_BRACE = '{'
CLOSE_BRACE = '}'
OPEN_PAREN = '('
CLOSE_PAREN = ')'
TARGET_SET = {OPEN_BRACKET,
              CLOSE_BRACKET,
              OPEN_PAREN,
              CLOSE_PAREN,
              OPEN_BRACE,
              CLOSE_BRACE}

OPEN_SET = {OPEN_BRACE, OPEN_BRACKET, OPEN_PAREN}
CLOSE_SET = {CLOSE_BRACE, CLOSE_PAREN, CLOSE_BRACKET}

PARENS = (OPEN_PAREN, CLOSE_PAREN)
BRACKETS = (OPEN_BRACKET, CLOSE_BRACKET)
BRACES = (OPEN_BRACE, CLOSE_BRACE)

PAIRS = {OPEN_BRACE: CLOSE_BRACE, CLOSE_BRACE: OPEN_BRACE,
         OPEN_BRACKET: CLOSE_BRACKET, CLOSE_BRACKET: OPEN_BRACKET,
         OPEN_PAREN: CLOSE_PAREN, CLOSE_PAREN: OPEN_PAREN}


def equal_num_open_close(input_str: str, open: str, close: str) -> bool:
    "Determine if there is an equal number of open and close of same type"
    open_count = input_str.count(open)
    input_count = input_str.count(close)

    return open_count == input_count


def is_paired(input_string: str) -> bool:
    # empty string guard
    if len(input_string) == 0:
        return True

    print("Starting scratch program.")

    stripped_list = list(input_string)
    print(stripped_list)
    to_del = []
    for index, item in enumerate(stripped_list):
        if item not in TARGET_SET:
            to_del.append(index)

    for i in sorted(to_del, reverse=True):
        del stripped_list[i]

    targets = []
    equal_bracket = equal_num_open_close(input_string, OPEN_BRACKET, CLOSE_BRACKET)
    equal_parens = equal_num_open_close(input_string, OPEN_PAREN, CLOSE_PAREN)
    equal_braces = equal_num_open_close(input_string, OPEN_BRACE, CLOSE_BRACE)

    for item in stripped_list:
        if item in TARGET_SET:
            targets.append(item)

    print(targets)

    # Check that list is even
    if len(targets) % 2 != 0:
        return False
    elif not (equal_bracket and equal_parens and equal_braces):
        return False

    while len(targets) != 0:
        open_target = None, None
        for index, item in enumerate(targets):
            if item in OPEN_SET:
                open_target = index, item
                print(f"open_target: {open_target}")
            elif (item in CLOSE_SET) and (PAIRS[item] != open_target[1]):
                print(f"Open Target: {open_target}. Item in close set: {item}")
                return False
            elif item in CLOSE_SET:
                if PAIRS[item] == open_target[1]:
                    print(f"Open Target: {open_target}. Item in close set: {item}")

                    to_del = [index, open_target[0]]
                    for i in sorted(to_del, reverse=True):
                        del targets[i]
                    break

    return True
