def is_isogram(string: str) -> bool:
    letters_seen = {}
    if len(string) == 0:
        return True

    for char in string:
        # Lower so as not to miss a repeated letter in different cases
        lowered = char.lower()
        if lowered in ' -':
            continue
        if letters_seen.get(lowered):
            return False
        else:
            letters_seen[lowered] = True
    if len(string) == 0:
        return False
    return True
