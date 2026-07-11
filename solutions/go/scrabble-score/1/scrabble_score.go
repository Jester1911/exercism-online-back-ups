package scrabblescore

import (
	"unicode"
)

func Score(word string) int {
	one := []rune{'A', 'E', 'I', 'O', 'U', 'L', 'N', 'R', 'S', 'T'}
	two := []rune{'D', 'G'}
	three := []rune{'B', 'C', 'M', 'P'}
	four := []rune{'F', 'H', 'V', 'W', 'Y'}
	five := []rune{'K'}
	eight := []rune{'J', 'X'}
	ten := []rune{'Q', 'Z'}
	letterVal := make(map[rune]int)

	for _, l := range one {
		letterVal[l] = 1
	}

	for _, l := range two {
		letterVal[l] = 2
	}

	for _, l := range three {
		letterVal[l] = 3
	}

	for _, l := range four {
		letterVal[l] = 4
	}

	for _, l := range five {
		letterVal[l] = 5
	}

	for _, l := range eight {
		letterVal[l] = 8
	}

	for _, l := range ten {
		letterVal[l] = 10
	}

	sum := 0
	for _, r := range word {
		value, ok := letterVal[unicode.ToUpper(r)]
		if !ok {
			return 0
		}
		sum += value
	}
	return sum
}
