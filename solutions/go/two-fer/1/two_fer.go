// This is a "stub" file.  It's a little start on your solution.
// It's not a complete solution though; you have to write some code.

// Package twofer should have a package comment that summarizes what it's about.
// https://golang.org/doc/effective_go.html#commentary
package twofer

// ShareWith returns a string whose value changes if the name is empty or not.
func ShareWith(name string) string {

	s := ""

	if name == "" {
		s = "One for you, one for me."
	} else {
		s = "One for " + name + ", one for me."
	}

	return s
}
