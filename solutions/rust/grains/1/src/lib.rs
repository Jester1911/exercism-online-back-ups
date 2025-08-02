pub fn square(s: u32) -> u64 {
    2_u64.pow(s-1) as u64
}

pub fn total() -> u64 {
    let mut total : u64 = 0;
    for i in 1..65 {
        total += square(i);
    }
    total
}
