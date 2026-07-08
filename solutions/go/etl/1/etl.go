package etl

import (
	"strings"
)

func Transform(in map[int][]string) map[string]int {
	result := map[string]int{}
	for score, v := range in {
		for _, letter := range v {
			result[strings.ToLower(letter)] = score
		}
	}
	return result
}
