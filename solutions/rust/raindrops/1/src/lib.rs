pub fn raindrops(n: u32) -> String {
    let mut s: String = String::new();

    if is_divisible_by_3(n) {
        s.push_str("Pling");
    }

    if is_divisible_by_5(n) {
        s.push_str("Plang");
    }

    if is_divisible_by_7(n) {
        s.push_str("Plong");
    }

    if s.is_empty() {
        s.push_str(&n.to_string());
    }

    s
}

pub fn is_divisible_by_3(n: u32) -> bool {
    if n.is_multiple_of(3) {
        return true;
    }
    false
}

pub fn is_divisible_by_5(n: u32) -> bool {
    if n.is_multiple_of(5) {
        return true;
    }
    false
}

pub fn is_divisible_by_7(n: u32) -> bool {
    if n.is_multiple_of(7) {
        return true;
    }
    false
}
