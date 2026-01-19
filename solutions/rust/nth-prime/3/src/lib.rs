pub fn nth(n: u32) -> u32 {
    let upper_bound = estimate_prime_upper_bound(n);
    let mut is_prime = vec![true; upper_bound as usize];
    let mut primes: Vec<u32> = Vec::new();
    is_prime[0] = false;
    is_prime[1] = false;

    while primes.len() != ((n + 1) as usize) {
        let current_base = is_prime
            .iter()
            .enumerate()
            .filter(|&(_, is_p)| *is_p)
            .nth(primes.len())
            .map(|(idx, _)| idx)
            .unwrap() as u32;
        primes.push(current_base);

        let mut multiplier = 2;

        while current_base * multiplier < upper_bound {
            is_prime[(current_base * multiplier) as usize] = false;
            multiplier += 1;
        }
    }

    *primes.last().unwrap()
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
