package wordcount

import (
	"strings"
	"unicode"
)

type Frequency map[string]int

func WordCount(phrase string) Frequency {
	// check for runes that can remain in words; split by all else
	isSeparator := func(r rune) bool {
		if r == '\'' || unicode.IsLetter(r) || unicode.IsDigit(r) {
			return false
		} else {
			return true
		}
	}

	words := strings.FieldsFunc(phrase, isSeparator)

	// isSeparator can miss apostrophes not in contractions, but rather when used
	// as single quotes. Trim prefix and suffix to remove instances of single quotes.
	for i, s := range words {
		temp := s
		if len(s) > 0 {
			temp = strings.TrimPrefix(s, "'")
			temp = strings.TrimSuffix(temp, "'")
		}
		words[i] = temp
	}

	// count instances of each word
	count := map[string]int{}
	for _, s := range words {
		if len(s) > 0 {
			lowercase := strings.ToLower(s)
			count[lowercase]++
		}
	}
	return count
}
