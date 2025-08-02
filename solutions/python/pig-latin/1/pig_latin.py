def is_a_vowel(char) -> bool:
    return char in ('a', 'e', 'i', 'o', 'u')


def contains_a_vowel(word: str) -> bool:
    for char in word:
        if char in ('a', 'e', 'i', 'o', 'u'):
            return True

    return False


def first_vowel_position(word: str) -> int:
    """
    Finds the position of the first vowel in given word.

    Returned position is zero-based.
    If no vowel found, return -1.
    """
    for x in range(len(word)):
        if is_a_vowel(word[x]):
            return x
    return -1


def starts_with_vowel(word: str) -> bool:
    return is_a_vowel(word[0])


def starts_with_xr_yt_ay(word: str) -> bool:
    if word.find('xr') is 0:
        return True
    elif word.find('yt') is 0:
        return True
    elif word.find('ay') is 0:
        return True
    else:
        return False


def convert_word(text: str) -> str:
    first_vowel_pos = first_vowel_position(text)
    s = text

    if starts_with_vowel(text) or starts_with_xr_yt_ay(text):
        return text + "ay"
    else:
        if text.find("qu") >= 0:
            qu_pos = text.find("qu")
            s_list = list(s)
            if first_vowel_pos < qu_pos:
                s_list.append(s[:first_vowel_pos])
                del s_list[:first_vowel_pos]
                s_list.append("ay")
                return "".join(s_list)
            else:
                if qu_pos == 0:
                    s_list.append("qu")
                    del s_list[:2]
                    s_list.append("ay")
                    return "".join(s_list)
                else:
                    s_list.append(text[:qu_pos + 2])
                    del s_list[:qu_pos + 2]
                    s_list.append("ay")
                    return "".join(s_list)

        elif text.find("y") >= 0:
            y_pos = text.find("y")
            s_list = list(s)
            if contains_a_vowel(text) and first_vowel_pos < y_pos:
                s_list.append(s[:first_vowel_pos])
                del s_list[:first_vowel_pos]
                s_list.append("ay")
                return "".join(s_list)
            else:
                if y_pos == 0:
                    s_list.append("y")
                    del s_list[:1]
                    s_list.append("ay")
                    return "".join(s_list)
                else:
                    s_list.append(text[:y_pos])
                    del s_list[:y_pos]
                    s_list.append("ay")
                    return "".join(s_list)


        else:
            s_list = list(s)
            s_list.append(s[:first_vowel_pos])
            del s_list[:first_vowel_pos]
            s_list.append("ay")
            return "".join(s_list)


def translate(text: str) -> str:
    result = []
    for word in text.split():
        result.append(convert_word(word))

    return " ".join(result)
