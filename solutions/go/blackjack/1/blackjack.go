package blackjack

// ParseCard returns the integer value of a card following blackjack ruleset.
func ParseCard(card string) int {
	val := 0
	switch card {
	case "ace":
		val = 11

	case "one":
		val = 1

	case "two":
		val = 2

	case "three":
		val = 3

	case "four":
		val = 4

	case "five":
		val = 5

	case "six":
		val = 6

	case "seven":
		val = 7

	case "eight":
		val = 8

	case "nine":
		val = 9

	case "ten", "jack", "queen", "king":
		val = 10

	default:
		val = 0
	}
	return val
}

// FirstTurn returns the decision for the first turn, given two cards of the
// player and one card of the dealer.
func FirstTurn(card1, card2, dealerCard string) string {
	myVal := ParseCard(card1) + ParseCard(card2)
	dealerVal := ParseCard(dealerCard)
	result := ""

	if myVal == 22 {
		result = "P"
	} else if myVal == 21 {
		if dealerVal < 10 {
			result = "W"
		} else {
			result = "S"
		}
	} else if myVal >= 17 && myVal <= 20 {
		result = "S"
	} else if myVal >= 12 && myVal <= 16 {
		if dealerVal >= 7 {
			result = "H"
		} else {
			result = "S"
		}
	} else if myVal <= 11 {
		result = "H"
	}

	return result
}
