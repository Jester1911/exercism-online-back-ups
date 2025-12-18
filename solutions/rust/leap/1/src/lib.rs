pub fn is_leap_year(year: u64) -> bool {
    if year.is_multiple_of(100) {
        if year.is_multiple_of(400) {
            return true;
        }
    } else if year.is_multiple_of(4) {
        return true;
    }

    false
}
