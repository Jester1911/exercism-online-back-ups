package luhn

import (
	"strconv"
	"strings"
)

func Valid(id string) bool {
	clean := strings.ReplaceAll(id, " ", "")
	var result int64 = 0
	double := false

	if len(clean) <= 1 {
		return false
	}
	for i := len(clean) - 1; i >= 0; i-- {
		num, err := strconv.ParseInt(string(clean[i]), 10, 64)
		if err != nil {
			return false
		}

		if double {
			num *= 2
			if num > 9 {
				num -= 9
			}
			result += num
			double = false
		} else {
			result += num
			double = true
		}
	}

	return result%10 == 0
}
