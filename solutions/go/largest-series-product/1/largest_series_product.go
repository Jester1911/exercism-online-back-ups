package largestseriesproduct

import (
	"errors"
	"unicode"
)

func LargestSeriesProduct(digits string, span int) (int64, error) {
	slice := make([]rune, 0, len(digits))
	for _, r := range digits {
		slice = append(slice, r)
	}

	l, r := 0, span
	if r > len(slice) || r < 0 {
		return 0, errors.New("span invalid or invalid window")
	}

	var result int64 = 0
	for l < len(slice) && r-1 < len(slice) {
		chunk := slice[l:r]
		val, err := seriesProduct(chunk)
		if err != nil {
			return 0, err
		}
		result = max(result, val)

		// slide window
		l++
		r++
	}
	return result, nil
}

func seriesProduct(digits []rune) (int64, error) {
	var product int64 = 1
	for _, r := range digits {
		if !unicode.IsDigit(r) {
			return 0, errors.New("rune is not a valid number")
		}
		product *= int64(r - '0')
	}
	return product, nil
}
