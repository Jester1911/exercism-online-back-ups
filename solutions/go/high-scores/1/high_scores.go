package highscores

import "sort"

type HighScores struct {
	scores []int
}

// NewHighScores returns a new HighScores object.
func NewHighScores(scores []int) *HighScores {
	s := &HighScores{
		scores: scores,
	}
	return s
}

// Scores returns all the scores.
func (s *HighScores) Scores() []int {
	return s.scores
}

// Latest returns the latest (last) score.
func (s *HighScores) Latest() int {
	return s.scores[len(s.scores)-1]
}

// PersonalBest returns the best (highest) score.
func (s *HighScores) PersonalBest() int {
	if len(s.scores) == 0 {
		return 0
	} else if len(s.scores) == 1 {
		return s.scores[0]
	}

	// establish current for future compares
	highest := s.scores[0]
	for _, v := range s.scores {
		highest = max(v, highest)
	}
	return highest
}

// TopThree returns the top three scores.
func (s *HighScores) TopThree() []int {
	c := make([]int, len(s.scores))
	copy(c, s.scores)
	sort.Slice(c, func(i, j int) bool {
		return c[i] > c[j]
	})
	// guard against less than three in slice
	if len(c) < 3 {
		return c
	}
	return c[:3]
}
