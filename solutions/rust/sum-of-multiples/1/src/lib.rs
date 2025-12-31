use std::collections::HashSet;

pub fn sum_of_multiples(limit: u32, factors: &[u32]) -> u32 {
    // Rather than return Vector and have to join multiples Vecs into one, return Iterator
    let multiples: Vec<u32> = factors
        .iter()
        .flat_map(|&x| multiples_of_factor(limit, x))
        .collect();

    // Use HashSet to remove duplicate values
    let unique: HashSet<_> = multiples.into_iter().collect();

    // Return sum of unique multiples
    unique.iter().sum()
}

pub fn multiples_of_factor(limit: u32, number: u32) -> impl Iterator<Item = u32> {
    let mut value: u32 = number;
    let mut i: u32 = 1;
    let mut multiples: Vec<u32> = Vec::new();

    // Avoid loop if value is initially 0 -> infinite loop
    if value != 0 {
        while value < limit {
            multiples.push(value);
            i += 1;
            value = number * i;
        }
    }
    multiples.into_iter()
}
