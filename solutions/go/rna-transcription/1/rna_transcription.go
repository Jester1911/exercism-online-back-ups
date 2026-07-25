package rnatranscription

func ToRNA(dna string) string {
	dnaToRna := map[rune]rune{
		'G': 'C',
		'C': 'G',
		'T': 'A',
		'A': 'U',
	}

	s := ""
	for _, r := range dna {
		s += string(dnaToRna[r])
	}
	return s
}
