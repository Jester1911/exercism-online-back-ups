ASCII_UPPER_START = ord('A')
ASCII_LOWER_START = ord('a')


def rotate(text: str, key: int) -> str:
    # Use the ASCII ordinal value to simplify the difficulty of shifting both
    # uppercase and lowercase letters
    #   ord() gives the ordinal number of a char
    #   char() gives the char represented by an ordinal number
    #   Based on IsUpper or IsLower, subtract the ordinal numbers of the ASCII starting uppercase
    #   or lowercase letters to get the letters offset in the alphabet, then apply the shift key,
    #   and lastly use mod 26 to find what the actual encrypted letter will be.
    encrypted = []
    shift_by = key % 26

    for char in text:
        if char.isalpha():
            if char.isupper():
                shifted_ord = (ord(char) - ASCII_UPPER_START + shift_by) % 26
                shifted = chr(ASCII_UPPER_START + shifted_ord)
            else:
                shifted_ord = (ord(char) - ASCII_LOWER_START + shift_by) % 26
                shifted = chr(ASCII_LOWER_START + shifted_ord)
        else:
            shifted = char

        encrypted.append(shifted)

    return ''.join(encrypted)
