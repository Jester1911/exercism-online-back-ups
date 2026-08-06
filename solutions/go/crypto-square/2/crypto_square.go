package cryptosquare

import (
	"math"
	"unicode"
)

// Encode takes a message (string) and encodes it via the Square Cypher, outputting
// the encoded message as a string.
func Encode(pt string) string {
	// Remove spaces and punctuation
	// Chunk message into c x r matrix (square/rectangle)
	// Invariants:
	//   col * row >= len(pt)
	//   col >= row
	//   c - r <= 1; equal number (square) or row less than col by 1
	if len(pt) == 0 {
		return ""
	}

	runes := []rune{}
	for _, r := range pt {
		if !(unicode.IsLetter(r) || unicode.IsNumber(r)) {
			continue
		}
		runes = append(runes, unicode.ToLower(r))
	}

	if len(runes) == 0 {
		return ""
	}

	r, c := numRowsAndColumns(len(runes))
	matrix := chunkRuneSlice(runes, c)

	// Create perfect square
	for len(matrix[r-1]) < c {
		matrix[r-1] = append(matrix[r-1], ' ')
	}

	coded := ""
	for i := range c {
		for j := range r {
			coded += string(matrix[j][i])
			if j == r-1 && i != c-1 {
				coded += " "
			}
		}
	}

	return coded
}

func numRowsAndColumns(length int) (r, c int) {
	root := math.Sqrt(float64(length))
	rootAsInt := int(root)
	// check if perfect square, thus r and c are the same
	if rootAsInt*rootAsInt == length {
		return int(root), int(root)
	}

	rootCeil := int(math.Ceil(root))
	rootFloor := int(math.Floor(root))

	if rootFloor*rootCeil >= length {
		return rootFloor, rootCeil
	}

	if rootCeil*rootCeil >= length {
		return rootCeil, rootCeil
	}

	row := int(math.Ceil(root))
	col := int(math.Ceil(root) + 1)

	// if not perfect square, round up root for c, then round up root + 1 for r
	return row, col
}

func chunkRuneSlice(runes []rune, n int) [][]rune {
	var chunks [][]rune

	for i := 0; i < len(runes); i += n {
		end := i + n
		end = min(end, len(runes))
		chunks = append(chunks, runes[i:end])
	}

	return chunks
}
