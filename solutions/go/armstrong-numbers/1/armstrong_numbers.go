package armstrongnumbers

import (
	"math"
	"strconv"
	"unicode"
)

// IsNumber returns true if the number is an Armstrong number, false otherwise.
// An Armstrong Number is a number that is the sum of its own digits each to the
// power of the total number of digits
func IsNumber(n int) bool {
	asString := strconv.Itoa(n)
	numDigits := float64(len(asString))
	sum := 0

	for _, r := range asString {
		if unicode.IsDigit(r) {
			num := int(r) - int('0')
			sum += int(math.Pow(float64(num), numDigits))
		} else {
			return false
		}
	}

	return sum == n

}
