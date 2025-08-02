def is_pangram(sentence: str) -> bool:
    """Determine if a sentence is a pangram.

    A pangram sentence is a string of lowercase letters that includes an
    instance of every letter in the alphabet.

    :param sentence:
    :type sentence:
    """
    # create an empty set then add each letter of the string to it. The set will guarantee the
    # insances of the letters are unique and, if the sentence is a pangram, the set's size will be
    # 26.
    # Need to make the sentence lowercase, as uppercase letters are not equal to lowercase, and
    # check that the letter is alphabetic
    letters = set()

    # need to make the sentence all lowercase, because uppercase and lowercase letters are
    # different strings; e.g. unique to the set
    lowercase_sentence = sentence.lower()
    for letter in lowercase_sentence:
        if letter.isalpha():
            letters.add(letter)

    return len(letters) == 26
