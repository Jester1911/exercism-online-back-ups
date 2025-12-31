use std::collections::HashSet;

pub fn brackets_are_balanced(string: &str) -> bool {
    let opening: HashSet<char> = "{([".chars().collect();
    let closing: HashSet<char> = "})]".chars().collect();
    let mut symbols: Vec<char> = Vec::new();

    for c in string.chars() {
        if opening.contains(&c) {
            symbols.push(c);
        } else if closing.contains(&c) {
            if let Some(val) = symbols.last() {
                if symbol_matches_partner(*val, c) {
                    // Closing symbol matches last opening in vector -> OK and Pop last opening from Vec
                    symbols.pop();
                } else {
                    // Closing symbol does not match opening -> Return False
                    return false;
                }
            } else {
                // Symbol vector is empty -> Return False
                return false;
            }
        }
    }
    // If list is empty -> All symbols encountered have been matched to counterpart
    symbols.is_empty()
}

pub fn symbol_matches_partner(opening: char, closing: char) -> bool {
    if closing == '}' {
        return opening == '{';
    } else if closing == ')' {
        return opening == '(';
    } else if closing == ']' {
        return opening == '[';
    }
    false
}
