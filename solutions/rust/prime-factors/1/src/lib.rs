pub fn factors(n: u64) -> Vec<u64> {
    let mut num = n;
    let mut prime_factors: Vec<u64> = Vec::new();
    let mut divisor: u64 = 2;

    while num != 1 && divisor <= num {
        println!("Number is: {num}. Divisor is {divisor}");
        if num.is_multiple_of(divisor) {
            num /= divisor;
            prime_factors.push(divisor);
        } else {
            divisor += 1;
        }
    }
    prime_factors
}
