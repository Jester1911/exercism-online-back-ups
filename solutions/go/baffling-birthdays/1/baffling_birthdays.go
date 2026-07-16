package bafflingbirthdays

import (
	"math"
	"math/rand/v2"
	"time"
)

type yearMonthDay struct {
	year  int
	month time.Month
	day   int
}

type monthDay struct {
	month time.Month
	day   int
}

func SharedBirthday(dates []time.Time) bool {

	// build birthday map for later comparison
	birthdayCount := make(map[monthDay]int)
	for _, v := range dates {
		key := monthDay{v.Month(), v.Day()}
		birthdayCount[key]++
	}

	// iterate to find any birthdays where count > 1
	for _, v := range birthdayCount {
		if v > 1 {
			return true
		}
	}
	return false
}

func RandomBirthdates(size int) []time.Time {
	yearInSeconds := 365 * 24 * 60 * 60
	result := make([]time.Time, 0, size)

	for range size {
		secs := time.Duration((rand.Float64() * float64(yearInSeconds))) * time.Second
		birthday := time.Now().Add(-1 * secs)
		result = append(result, birthday)
	}
	return result
}

func EstimatedProbability(size int) float64 {
	// approximation from wikipedia "Birthday Problem"
	//    P = 1 - e^(-1 *size^2 / 730)
	probabilityAsDecimal := 1 - math.Exp(-1.0*float64(size*size)/730.0)
	return probabilityAsDecimal * 100.0
}
