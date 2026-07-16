// Package weather has exported variables and functions that are responsible
// for formatting and returning a sentence concerning the weather in an area.
package weather

var (
	// CurrentCondition is a string variable that is used to describe the
	// current weather condition in the area described by CurrentLocation.
	CurrentCondition string
	// CurrentLocation is a string variabel that identifies the location whose
	// weather is being described.
	CurrentLocation string
)

// Forecast accepts two string variables: city and condition. It then uses the
// those two string variables to format and return a string identifying the
// area and the current weather.
func Forecast(city, condition string) string {
	CurrentLocation, CurrentCondition = city, condition
	return CurrentLocation + " - current weather condition: " + CurrentCondition
}
