package techpalace

import "strings"

// WelcomeMessage returns a welcome message for the customer.
func WelcomeMessage(customer string) string {
	preface := "Welcome to the Tech Palace, "
	return preface + strings.ToUpper(customer)
}

// AddBorder adds a border to a welcome message.
func AddBorder(welcomeMsg string, numStarsPerLine int) string {
	border := strings.Repeat("*", numStarsPerLine)
	s := border + "\n" + welcomeMsg + "\n" + border
	return s
}

// CleanupMessage cleans up an old marketing message.
func CleanupMessage(oldMsg string) string {
	s := ""
	s = strings.ReplaceAll(oldMsg, "*", "")
	s = strings.TrimSpace(s)
	return s
}
