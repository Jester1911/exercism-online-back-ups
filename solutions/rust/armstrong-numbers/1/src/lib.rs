pub fn parse_digits_to_vec(num: u32) -> Vec<u32> {
    let s = num.to_string();
    let digits : Vec<u32> = s.chars().map(|c| c.to_digit(10).unwrap()).collect();
    digits
}

pub fn is_armstrong_number(num: u32) -> bool {
    let digits : Vec<u32> = parse_digits_to_vec(num);
    let length : u32 = digits.len() as u32;
    let mut sum = 0;
    for item in &digits {
        sum += item.pow(length);
    }

    num == sum
}


