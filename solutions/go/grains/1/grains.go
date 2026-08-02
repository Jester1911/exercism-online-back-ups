package grains

import "errors"

func Square(number int) (uint64, error) {
	if number < 1 || number > 64 {
		return 0, errors.New("not a valid square number")
	}

	var result uint64 = 1
	for i := 1; i < number; i++ {
		result *= 2
	}
	return result, nil
}

func Total() uint64 {
	var result uint64 = 0
	for i := 1; i <= 64; i++ {
		current, err := Square(i)
		if err != nil {
			return 0
		}
		result += current
	}
	return result
}
