package listops

// IntList is an abstraction of a list of integers which we can define methods on
type IntList []int

func (s IntList) Foldl(fn func(int, int) int, initial int) int {
	result := initial
	for _, v := range s {
		result = fn(result, v)
	}
	return result
}

func (s IntList) Foldr(fn func(int, int) int, initial int) int {
	result := initial
	for i := len(s) - 1; i >= 0; i-- {
		result = fn(s[i], result)
	}
	return result
}

func (s IntList) Filter(fn func(int) bool) IntList {
	result := make(IntList, 0)
	for _, v := range s {
		if fn(v) {
			result = append(result, v)
		}
	}
	return result
}

func (s IntList) Length() int {
	var count = 0
	for i, _ := range s {
		count = i
		count++
	}
	return count
}

func (s IntList) Map(fn func(int) int) IntList {
	result := make(IntList, len(s))
	for i, v := range s {
		result[i] = fn(v)
	}
	return result
}

func (s IntList) Reverse() IntList {
	result := make(IntList, len(s))
	pos := 0
	if s.Length() > 0 {
		for j := len(s) - 1; j >= 0; j-- {
			result[pos] = s[j]
			pos++
		}
	}

	return result
}

func (s IntList) Append(lst IntList) IntList {
	length := len(s) + len(lst)
	result := make(IntList, length)
	pos := 0
	for i, val := range s {
		result[i] = val
		pos++
	}
	for _, val := range lst {
		result[pos] = val
		pos++
	}
	return result
}

func (s IntList) Concat(lists []IntList) IntList {
	totLength := 0
	for _, v := range lists {
		totLength += len(v)
	}
	result := make(IntList, totLength)
	pos := 0
	for _, list := range lists {
		for _, v := range list {
			result[pos] = v
			pos++
		}
	}
	return result
}
