pub fn reverse(input: &str) -> String {
    // &str is an immutable ref to a String, including the memory location
    // of the Strings beginning and its length

    let reversed: Vec<char> = input.chars().rev().collect();
    let result = reversed.iter().collect::<String>();

    return result;
}
