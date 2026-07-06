// Package gigasecond should have a package comment that summarizes what it's about.
// https://golang.org/doc/effective_go.html#commentary
package gigasecond

// import path for the time package from the standard library
import "time"

var gigasecond = 1000000000

// AddGigasecond should have a comment documenting it.
func AddGigasecond(t time.Time) time.Time {
	// time.Duration() necessary to cast constant as time datatype
	result := t.Add(time.Second * time.Duration(gigasecond))
	return result
}
