/// Return the Hamming distance between the strings,
/// or None if the lengths are mismatched.
pub fn hamming_distance(s1: &str, s2: &str) -> Option<usize> {
    if s1.len() != s2.len() {
        return None;
    }

    let mut seq_diff: usize = 0;
    for (a, b) in s1.chars().zip(s2.chars()) {
        if a != b {
            seq_diff += 1;
        }
    }
    Some(seq_diff)
}
