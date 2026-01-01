#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

pub fn sublist(first_list: &[i32], second_list: &[i32]) -> Comparison {
    // Answer is List A with respect to List B
    //
    // Algo: Use windows to slide across slices and compare
    let mut result: Comparison = Comparison::Unequal;

    if is_either_list_empty(first_list, second_list) {
        if first_list.is_empty() && second_list.is_empty() {
            result = Comparison::Equal;
        } else if first_list.is_empty() {
            result = Comparison::Sublist;
        } else {
            result = Comparison::Superlist;
        }
    } else if first_list.len() == second_list.len() {
        // Equality
        if is_superlist(first_list, second_list) {
            result = Comparison::Equal;
        }
    } else if first_list.len() < second_list.len() {
        // Sublist of B
        if is_sublist(first_list, second_list) {
            result = Comparison::Sublist;
        }
    } else {
        // Superlist of B
        if is_superlist(first_list, second_list) {
            result = Comparison::Superlist;
        }
    }

    result
}

fn is_either_list_empty<T: PartialEq>(a: &[T], b: &[T]) -> bool {
    a.is_empty() || b.is_empty()
}

fn is_sublist<T: PartialEq>(a: &[T], b: &[T]) -> bool {
    b.windows(a.len()).any(|x| x == a)
}

fn is_superlist<T: PartialEq>(a: &[T], b: &[T]) -> bool {
    is_sublist(b, a)
}
