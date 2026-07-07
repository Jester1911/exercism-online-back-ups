package isbnverifier

import (
	"strconv"
	"strings"
)

func IsValidISBN(isbn string) bool {
	clean := strings.ReplaceAll(isbn, "-", "")
	if len(clean) != 10 {
		return false
	}

	var result int64 = 0
	for i, r := range clean {
		if r == 'X' {
			if i != 9 {
				return false
			} else {
				result += 10 * (10 - int64(i))
			}
		} else {
			num, err := strconv.ParseInt(string(r), 10, 64)
			if err != nil {
				return false
			}

			result += num * (10 - int64(i))
		}

	}
	return result%11 == 0
}
