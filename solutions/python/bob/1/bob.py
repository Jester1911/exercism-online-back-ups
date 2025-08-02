def response(hey_bob: str) -> str:
    if len(hey_bob.strip()) > 1:
        if hey_bob.strip()[len(hey_bob.strip()) - 1] is '?':
            if hey_bob.isupper():
                return "Calm down, I know what I'm doing!"
            else:
                return "Sure."
        elif hey_bob.strip().isupper():
            return "Whoa, chill out!"
        else:
            return "Whatever."
    else:
        return "Fine. Be that way!"
