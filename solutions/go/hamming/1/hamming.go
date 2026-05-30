package hamming

import "errors"

// Distance calculates the occurence of differences between strings.
// Returns error on strings of different lengths.
func Distance(a, b string) (int, error) {
	if len(a) != len(b) {
		return 0, errors.New("unequal length string inputs")
	}

	diffs := 0
	for i := 0; i < len(a); i++ {
		if a[i] != b[i] {
			diffs++
		}
	}
	return diffs, nil
}
