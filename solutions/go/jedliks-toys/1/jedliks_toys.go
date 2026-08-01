package jedlik

import "fmt"

// Drive decrements battery by batteryDrain and increments distance by speed.
func (car *Car) Drive() {
	if (car.battery - car.batteryDrain) > 0 {
		car.battery -= car.batteryDrain
		car.distance += car.speed
	}
}

// DisplayDistance returns the distance driven as a formatted string.
func (car Car) DisplayDistance() string {
	s := fmt.Sprintf("Driven %d meters", car.distance)
	return s
}

// DisplayBattery returns the remaining battery amount as a formatted string.
func (car Car) DisplayBattery() string {
	s := fmt.Sprintf("Battery at %d%%", car.battery)
	return s
}

// CanFinish determines if a car can finish a given race, interpreted as a boolean.
func (car Car) CanFinish(trackDistance int) bool {
	numDrives := (car.battery / car.batteryDrain)
	canDriveDistance := numDrives * car.speed
	return trackDistance <= canDriveDistance
}

// Your first steps could be to read through the tasks, and create
// these functions with their correct parameter lists and return types.
// The function body only needs to contain `panic("")`.
//
// This will make the tests compile, but they will fail.
// You can then implement the function logic one by one and see
// an increasing number of tests passing as you implement more
// functionality.
