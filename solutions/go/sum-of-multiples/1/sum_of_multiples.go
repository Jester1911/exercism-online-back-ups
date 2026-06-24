package sumofmultiples

func SumMultiples(limit int, divisors ...int) int {
	var multiples = []int{}
	for _, divisor := range divisors {
		multiples = append(multiples, findMultiplesBaseLessThanTarget(limit, divisor)...)
	}

	seen := make(map[int]bool)
	var multiplesSet = []int{}

	for _, val := range multiples {
		if !seen[val] {
			seen[val] = true
			multiplesSet = append(multiplesSet, val)
		}
	}

	sum := 0
	for _, val := range multiplesSet {
		sum += val
	}
	return sum
}

func findMultiplesBaseLessThanTarget(target int, base int) []int {
	if target == 0 || base == 0 {
		return []int{0}
	}

	var multiples = []int{}
	for multiple := 1; base*multiple < target; multiple++ {
		multiples = append(multiples, base*multiple)
	}
	return multiples
}
