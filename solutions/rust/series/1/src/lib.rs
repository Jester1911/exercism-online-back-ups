pub fn series(digits: &str, len: usize) -> Vec<String> {
    // TODO! ("What are the series of length {len} in string {digits:?}")
    let v_chars: Vec<char> = digits.chars().collect();
    let mut result: Vec<String> = Vec::new();

    if len > digits.len() || len == 0 {
        return result;
    }

    for w in v_chars.windows(len) {
        let sub: String = w.iter().collect();
        result.push(sub);
    }
    result
}
