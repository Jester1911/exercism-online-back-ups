package phonenumber

import (
	"errors"
	"strings"
	"unicode"
)

func Number(phoneNumber string) (string, error) {
	// acceptable format: NXX NXX-XXXX
	// N = 2..9
	// X = 0..9

	// define function to reject/filter improper runes/spaces
	filter := func(r rune) rune {
		if unicode.IsDigit(r) {
			return r
		} else {
			return -1
		}
	}

	// define function to check N digits for proper values; e.g. 2..9
	nDigitsValid := func(s string) (bool, error) {
		if len(s) == 11 {
			if s[1] == '0' || s[1] == '1' {
				return false, errors.New("invalid N digit")
			} else if s[4] == '0' || s[4] == '1' {
				return false, errors.New("invalid N digit")
			}
		} else if len(s) == 10 {
			if s[0] == '0' || s[0] == '1' {
				return false, errors.New("invalid N digit")
			} else if s[3] == '0' || s[3] == '1' {
				return false, errors.New("invalid N digit")
			}
		} else {
			return false, errors.New("incorrect length")
		}
		return true, nil
	}

	clean := strings.Map(filter, phoneNumber) // either 10 or 11 digits
	isValidN, err := nDigitsValid(clean)      // validated N digits or not
	if err != nil || !isValidN {
		return "", err
	}
	if len(clean) == 11 {
		if clean[0] != '1' {
			return "", errors.New("country code is not 1")
		}
	} else if len(clean) != 10 {
		return "", errors.New("phone number has incorrect length")
	}

	// Return 10 digit number, minus country code if present
	if len(clean) == 11 {
		return clean[1:], nil
	} else {
		return clean, nil
	}
}

func AreaCode(phoneNumber string) (string, error) {
	s, err := Number(phoneNumber)
	if err != nil {
		return "", err
	}
	if len(s) == 11 {
		return s[1:4], nil
	} else {
		return s[0:3], nil
	}
}

func Format(phoneNumber string) (string, error) {
	s, err := Number(phoneNumber)
	if err != nil {
		return "", err
	}
	result := "(" + s[0:3] + ") " + s[3:6] + "-" + s[6:]
	return result, nil
}
