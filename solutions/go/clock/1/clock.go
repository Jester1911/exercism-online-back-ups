package clock

import (
	"fmt"
)

// Define the Clock type here.
type Clock struct {
	Hour   int
	Minute int
}

func New(h, m int) Clock {
	c := Clock{}

	mins := 60*h + m

	if mins < 0 {
		c = c.Subtract(-1 * mins)
	} else {
		c = c.Add(mins)
	}

	return Clock{Hour: c.Hour, Minute: c.Minute}
}

func (c Clock) Add(m int) Clock {
	result := Clock{}
	addMinute := m % 60
	addHour := m / 60

	if c.Minute+addMinute >= 60 {
		addHour++
	}
	result.Minute = (c.Minute + addMinute) % 60

	if c.Hour+addHour >= 24 {
		result.Hour = (c.Hour + addHour) % 24
	} else {
		result.Hour = c.Hour + addHour
	}
	return result
}

func (c Clock) Subtract(m int) Clock {
	result := Clock{}
	subMinute := m % 60
	subHour := (m / 60) % 24

	if c.Minute-subMinute < 0 {
		subHour++
		result.Minute = 60 + (c.Minute - subMinute)
	} else {
		result.Minute = c.Minute - subMinute
	}

	if c.Hour-subHour < 0 {
		result.Hour = 24 + (c.Hour - subHour)
	} else {
		result.Hour = c.Hour - subHour
	}
	return result
}

func (c Clock) String() string {
	s := fmt.Sprintf("%02d:%02d", c.Hour, c.Minute)
	return s

}
