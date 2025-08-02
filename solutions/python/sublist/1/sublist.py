"""
This exercise stub and the test suite contain several enumerated constants.

Enumerated constants can be done with a NAME assigned to an arbitrary,
but unique value. An integer is traditionally used because it’s memory
efficient.
It is a common practice to export both constants and functions that work with
those constants (ex. the constants in the os, subprocess and re modules).

You can learn more here: https://en.wikipedia.org/wiki/Enumerated_type
"""

# Possible sublist categories.
# Change the values as you see fit.
SUBLIST = 3
SUPERLIST = 2
EQUAL = 1
UNEQUAL = 0


def find_sublist_index(sublist, biglist):
    """Determines if sublist is in biglist and returns starting index"""
    # sliding window
    sublen = len(sublist)
    for i in range(len(biglist) - sublen + 1):
        if biglist[i:i + sublen] == sublist:
            return i
    return -1  # Not found


def sublist(list_one, list_two):
    # map the lists into strings. This should make checking
    # if one is a sublist of another, or equal, easier.
    a = ",".join(map(str, list_one))
    b = ",".join(map(str, list_two))

    smaller_len = min(len(a), len(b))
    result = 0

    if a == b:
        result = EQUAL

    elif a in b:
        start_idx = find_sublist_index(list_one, list_two)
        if start_idx != -1:
            result = SUBLIST

    elif b in a:
        start_idx = find_sublist_index(list_two, list_one)
        if start_idx != -1:
            result = SUPERLIST
    else:
        result = UNEQUAL

    return result
