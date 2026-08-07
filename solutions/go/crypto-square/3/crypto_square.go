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
	matrix := chunkByLengthN(runes, c)

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

// numRowsAndColumns accepts a length and uses the constraints of the Square Cypher
// to return numbers r, c that represent the rows and columns.
func numRowsAndColumns(length int) (r, c int) {
	root := math.Sqrt(float64(length))
	rootAsInt := int(root)
	// check if perfect square, thus r and c are the same
	if rootAsInt*rootAsInt == length {
		return int(root), int(root)
	}

	// determine how to adjust numbers to arrive at c and r within constraints
	rootCeil := int(math.Ceil(root))
	rootFloor := int(math.Floor(root))

	if rootFloor*rootCeil >= length {
		return rootFloor, rootCeil
	}

	return rootCeil, rootCeil
}

// chunkByLengthN returns a 2-D slice of runs, where each element is a slice of
// length n, with the possibility that the last chunk has a length < n.
func chunkByLengthN(runes []rune, n int) [][]rune {
	var chunks [][]rune

	for i := 0; i < len(runes); i += n {
		end := i + n
		end = min(end, len(runes))
		chunks = append(chunks, runes[i:end])
	}

	return chunks
}
