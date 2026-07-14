package interest

// InterestRate returns the interest rate for the provided balance.
func InterestRate(balance float64) float32 {
	ratePercent := 0.0
	if balance < 0 {
		ratePercent = 3.213
	} else if balance < 1000.0 {
		ratePercent = 0.5
	} else if balance < 5000.0 {
		ratePercent = 1.621
	} else {
		ratePercent = 2.475
	}

	return float32(ratePercent)
}

// Interest calculates the interest for the provided balance.
func Interest(balance float64) float64 {
	rate := float64(InterestRate(balance))
	return balance * (rate / 100.0)
}

// AnnualBalanceUpdate calculates the annual balance update, taking into account the interest rate.
func AnnualBalanceUpdate(balance float64) float64 {
	return balance + Interest(balance)
}

// YearsBeforeDesiredBalance calculates the minimum number of years required to reach the desired balance.
func YearsBeforeDesiredBalance(balance, targetBalance float64) int {
	years := 0
	currentBalance := balance
	for currentBalance < targetBalance {
		years++
		currentBalance = AnnualBalanceUpdate(currentBalance)
	}
	return years
}
