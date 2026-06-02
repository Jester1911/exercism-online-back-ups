package partyrobot

import (
	"fmt"
	"strconv"
)

// Welcome greets a person by name.
func Welcome(name string) string {
	return "Welcome to my party, " + name + "!"
}

// HappyBirthday wishes happy birthday to the birthday person and exclaims their age.
func HappyBirthday(name string, age int) string {
	sname := "Happy birthday " + name + "! "
	sage := "You are now " + strconv.Itoa(age) + " years old!"
	return sname + sage
}

// AssignTable assigns a table to each guest.
func AssignTable(name string, table int, neighbor, direction string, distance float64) string {
	// welcome
	s := Welcome(name) + "\n"

	// table assignment
	var tableNumber = strconv.Itoa(table)
	if len(tableNumber) < 2 {
		tableNumber = "00" + tableNumber
	} else if len(tableNumber) < 3 {
		tableNumber = "0" + tableNumber
	}

	tableLine := fmt.Sprintf("You have been assigned to table %s. Your table is %s, exactly %.1f meters from here.\n", tableNumber, direction, distance)

	// seat
	seat := fmt.Sprintf("You will be sitting next to %s.", neighbor)

	s += tableLine
	s += seat

	return s
}
