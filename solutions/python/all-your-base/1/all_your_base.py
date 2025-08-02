def rebase(input_base: int, digits: list[int], output_base: int) -> list[int]:
    # 1. Convert to intermediate base-10
    # 2. I think "mod base" will get the resulting values in each digit
    # 3. Positional Notation
    #   ...(digit * base^3) + (digit * base^2) + (digit * base^1) + (digit * base^0)

    if input_base < 2:
        raise ValueError("input base must be >= 2")
    elif output_base < 2:
        raise ValueError("output base must be >= 2")
    elif len(digits) == 0:
        return [0]
    else:
        for idx, digit in enumerate(digits):
            if digit != 0:
                break
            elif idx == len(digits) - 1:
                return [0]

    rev_digits = reversed(digits)
    base_10_num = 0
    for index, digit in enumerate(rev_digits):
        if digit < 0 or digit >= input_base:
            raise ValueError("all digits must satisfy 0 <= d < input base")

        base_10_num += digit * (input_base ** index)

    power = 1
    new_digits: list[int] = []
    while base_10_num > 0:
        curr_digit = base_10_num % (output_base ** power)
        # classical division of the previous power to get the positional coefficient for this power
        new_digits.append(curr_digit // (output_base ** (power - 1)))
        # subtract out the digit we have just calculated from total
        base_10_num -= curr_digit
        power += 1

    return list(reversed(new_digits))
