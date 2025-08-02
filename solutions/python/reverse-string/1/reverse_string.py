def reverse(text):
    # str does not have a .reverse() method, but list does
    # make 'text' a list where each index is a str of length 1
    reversed = list(text)
    reversed.reverse()
    # collapse the list back into a str with .join()
    return "".join(reversed)