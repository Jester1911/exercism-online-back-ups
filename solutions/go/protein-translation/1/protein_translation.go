package proteintranslation

import "errors"

var ErrInvalidBase = errors.New("no valid condon found")
var ErrStop = errors.New("encountered STOP condon")

var codonMap = map[string]string{
	"AUG": "Methionine",
	"UUU": "Phenylalanine",
	"UUC": "Phenylalanine",
	"UUA": "Leucine",
	"UUG": "Leucine",
	"UCU": "Serine",
	"UCC": "Serine",
	"UCA": "Serine",
	"UCG": "Serine",
	"UAU": "Tyrosine",
	"UAC": "Tyrosine",
	"UGU": "Cysteine",
	"UGC": "Cysteine",
	"UGG": "Tryptophan",
	"UAA": "STOP",
	"UAG": "STOP",
	"UGA": "STOP",
}

func FromRNA(rna string) ([]string, error) {
	result := []string{}
	input := []rune(rna)

	for i := 0; i < len(input); i += 3 {
		end := min(i+3, len(input))
		chunk := string(input[i:end])
		codon, err := FromCodon(chunk)
		if err != nil {
			if err == ErrInvalidBase {
				return result, err
			} else if err == ErrStop {
				break
			}
		} else {
			result = append(result, codon)
		}
	}

	return result, nil
}

func FromCodon(codon string) (string, error) {
	input := []rune(codon)
	result := ""

	for i := 0; i < len(input); i += 3 {
		end := min(i+3, len(input))
		chunk := string(input[i:end])
		value, exist := codonMap[chunk]
		if exist {
			result = value
		}
	}
	switch result {
	case "":
		return "", ErrInvalidBase
	case "STOP":
		return "", ErrStop
	default:
		return result, nil
	}
}
