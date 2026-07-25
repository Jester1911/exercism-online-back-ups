package chessboard

import (
	"maps"
	"slices"
)

// File represents a vertical column of squares on a cheesboard.
type File [8]bool

// Chessboard represents all squares in a cheesboard. Its implementation is a map of
// eight Files (columns) with keys 'A'...'H'. Each File has a length of 8, which
// represent the distinct rows of a chessboard, labeled 1..8 from bottom.
type Chessboard map[string]File

// CountInFile returns how many squares are occupied in the chessboard,
// within the given file.
func CountInFile(cb Chessboard, file string) int {
	column, ok := cb[file]
	if !ok {
		return 0
	}

	count := 0
	for _, v := range column {
		if v {
			count++
		}
	}
	return count
}

// CountInRank returns how many squares are occupied in the chessboard,
// within the given rank.
func CountInRank(cb Chessboard, rank int) int {
	if rank < 1 || rank > 8 {
		return 0
	}

	count := 0
	for _, column := range cb {
		if column[rank-1] {
			count++
		}
	}
	return count
}

// CountAll should count how many squares are present in the chessboard.
func CountAll(cb Chessboard) int {
	numberColumns := len(cb)
	return numberColumns * 8
}

// CountOccupied returns how many squares are occupied in the chessboard.
func CountOccupied(cb Chessboard) int {
	count := 0
	keys := slices.Collect(maps.Keys(cb))
	for _, k := range keys {
		count += CountInFile(cb, k)
	}
	return count
}
