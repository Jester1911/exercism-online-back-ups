pub fn nth(n: u32) -> u32 {
    let upper_bound = estimate_prime_upper_bound(n + 1);
    let mut nums: Vec<u32> = (2..=upper_bound).collect();
    let mut primes: Vec<u32> = Vec::new();
    let mut current_prime: u32 = 2;
    let mut current_test = current_prime;

    while primes.len() < (n + 1) as usize || nums.len() > 0 {
        while current_test <= upper_bound {
            // println!("current test = {current_test}. current_prime = {current_prime}");
            if current_test.is_multiple_of(current_prime) {
                if let Some(idx) = nums.iter().position(|x| *x == current_test) {
                    nums.remove(idx);
                }
            }
            current_test += current_prime;
        }

        if current_test >= upper_bound {
            if let Some(value) = nums.first() {
                primes.push(current_prime);
                current_prime = *value;
                current_test = current_prime;

                // println!("Elements left in nums: {nums:?}");
            } else {
                primes.push(current_prime);
            }
        }
    }

    //println!("---------");
    // println!("Prime Elements: {primes:?}");
    // println!("---------");
    if let Some(value) = primes.get((n) as usize) {
        *value
    } else {
        1
    }
}

fn estimate_prime_upper_bound(n: u32) -> u32 {
    // estimate upper bound for prime: n * (ln (n) + ln(ln (n)))
    if n < 6 {
        15
    } else {
        let n_f = n as f64;
        let bound = n_f * (n_f.ln() + n_f.ln().ln());
        bound as u32
    }
}
