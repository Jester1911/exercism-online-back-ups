package darts

import "math"

func euclideanDistance(x, y float64) float64 {
	return math.Sqrt(x*x + y*y)
}

func Score(x, y float64) int {
	distance := euclideanDistance(x, y)
	score := 0

	if distance > 10 {
		score = 0
	} else if distance > 5 {
		score = 1
	} else if distance > 1 {
		score = 5
	} else {
		score = 10
	}

	return score
}
