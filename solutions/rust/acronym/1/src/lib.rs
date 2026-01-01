pub fn abbreviate(phrase: &str) -> String {
    // Trim leading and trailing whitespace
    let s: String = phrase.trim().to_string();
    // Split by whitespace or hyphen
    let mut v: Vec<String> = s
        .split(|c: char| c == '-' || c == ' ')
        .filter(|s| !s.is_empty() || s.contains("-"))
        .map(|s| s.to_string())
        .collect();

    // Filter out non-alphabetic
    for word in &mut v {
        *word = word.chars().filter(|c| c.is_alphabetic()).collect();
    }

    // Two main cases we need to check:
    //    - The word has more than one uppercase letter, but not all uppercase
    //       -> Take both capital letters
    //    - Else, take first letter

    let mut capital_letters: Vec<char> = Vec::new();
    for word in &mut v {
        if contains_more_than_one_capital_letter_but_not_all(word) {
            let letters: Vec<char> = uppercase_letters_in_string(word);
            capital_letters.extend(letters);
        } else if let Some(c) = word.chars().next() {
            capital_letters.push(c.to_ascii_uppercase())
        }
    }

    let result: String = capital_letters.iter().collect();
    result
}

pub fn contains_more_than_one_capital_letter_but_not_all(s: &str) -> bool {
    let num_capital_letters = s.chars().filter(|c| c.is_ascii_uppercase()).count();
    num_capital_letters > 1 && num_capital_letters < s.len()
}

pub fn uppercase_letters_in_string(s: &str) -> Vec<char> {
    if !contains_more_than_one_capital_letter_but_not_all(s) {
        vec![]
    } else {
        s.chars().filter(|c| c.is_ascii_uppercase()).collect()
    }
}
