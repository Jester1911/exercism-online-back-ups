def convert_letter(letter: str) -> str:
    letters = 'abcdefghijklmnopqrstuvwxyz'
    offset_to_end = ord(letter) - ord('a')
    return letters[26 - offset_to_end - 1]


def chunk_string(s: str, size: int) -> list[str]:
    """Breaks the string into evenly sized chunks of length `size`."""
    return [s[i:i + size] for i in range(0, len(s), size)]


def encode(plain_text: str) -> str:
    """Encoded text with Atbash Cipher and group in 5 letter chunks"""
    # numbers are left unchanged; punctuation is excluded

    encoded_text = []
    for idx, letter in enumerate(plain_text):
        if letter.isalpha():
            encoded_text.append(convert_letter(letter.lower()))
        elif letter.isdigit():
            encoded_text.append(letter)

    result = chunk_string("".join(encoded_text), 5)

    return ' '.join(result)


def decode(ciphered_text: str) -> str:
    decoded_text = []
    for idx, char in enumerate(ciphered_text):
        if char.isalpha():
            decoded_text.append(convert_letter(char.lower()))
        elif char.isdigit():
            decoded_text.append(char)

    return ''.join(decoded_text)
