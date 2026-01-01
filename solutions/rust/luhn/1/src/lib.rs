/// Check a Luhn checksum.
pub fn is_valid(code: &str) -> bool {
    // convert referenc to owned String and remove whitespace
    let input: String = code.to_string().split_whitespace().collect();

    if input.len() < 2 {
        return false;
    }

    let v_chars: Vec<char> = input.chars().collect();
    let mut v_digits: Vec<u32> = Vec::new();

    for c in v_chars {
        if let Some(num) = c.to_digit(10) {
            v_digits.push(num);
        } else {
            println!("Failed to parse digit to u32.");
            return false;
        }
    }

    // Double every second from right
    let count = v_digits.len(); // Get a local copy of length here
    for x in v_digits[..count - 1].iter_mut().rev().step_by(2) {
        *x *= 2;
        if *x > 9 {
            *x -= 9;
        }
    }

    let sum: u32 = v_digits.iter().sum();

    sum.is_multiple_of(10)
}
