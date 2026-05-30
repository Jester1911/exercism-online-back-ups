package cars

// CalculateWorkingCarsPerHour calculates how many working cars are
// produced by the assembly line every hour.
func CalculateWorkingCarsPerHour(productionRate int, successRate float64) float64 {
	return float64(productionRate) * successRate / 100
}

// CalculateWorkingCarsPerMinute calculates how many working cars are
// produced by the assembly line every minute.
func CalculateWorkingCarsPerMinute(productionRate int, successRate float64) int {
	carsPerHour := CalculateWorkingCarsPerHour(productionRate, successRate)
	return int(carsPerHour / 60.0)
}

// CalculateCost works out the cost of producing the given number of cars.
func CalculateCost(carsCount int) uint {
	groupsOfTen := uint(carsCount / 10)
	individualCars := uint(carsCount) - groupsOfTen*10
	cost := uint(groupsOfTen*10*9500 + individualCars*10000)
	return cost
}
