package pangram

import "unicode"

func IsPangram(input string) bool {
	alphabet := []rune("abcdefghijklmnopqrstuvwxyz")
    runeMap := map[rune]int {}
    for _, r := range alphabet {
        runeMap[r] = 0
    }

    for _, r := range input {
		if !unicode.IsLetter(r) {
            continue
        }
        runeMap[unicode.ToLower(r)]++
    }
    for _, v := range runeMap {
        if v < 1 {
            return false
        }
    }
    return true   
}
