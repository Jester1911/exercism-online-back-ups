package anagram

import (
	"maps"
	"strings"
	"unicode"
)

func Detect(subject string, candidates []string) []string {
	// Using map to ensure subject and candidate words have same runes and
	// same quantity of each rune.

	results := []string{}
	targetLetters := make(map[rune]int)
	for _, r := range subject {
		targetLetters[unicode.ToLower(r)]++
	}

	for _, word := range candidates {

		// Checking that subject and candidate are not same word, as check via map
		// will not catch this; e.g. map will check rune value/quantity but not
		// sequencing
		if strings.EqualFold(subject, word) {
			continue
		}

		curr := make(map[rune]int)
		for _, r := range word {
			curr[unicode.ToLower(r)]++
		}

		if maps.Equal(targetLetters, curr) {
			results = append(results, word)
		}
	}
	return results
}
