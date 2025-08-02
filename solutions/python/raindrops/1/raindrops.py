def is_divisible(number: int, divisor: int) -> bool:
    return number % divisor == 0


def convert(number):
    word = ""

    if is_divisible(number, 3):
        word += str("Pling")
    if is_divisible(number, 5):
        word += str("Plang")
    if is_divisible(number, 7):
        word += str("Plong")

    if len(word) == 0:
        return str(number)
    else:
        return word
