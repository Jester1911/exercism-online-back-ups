package lasagnamaster

func PreparationTime(layers []string, timePerLayer int) int {
	numLayers := len(layers)
	if timePerLayer == 0 {
		timePerLayer = 2
	}
	return numLayers * timePerLayer
}

func Quantities(layers []string) (int, float64) {
	noodleLayerGrams := 50
	sauceLayerLiters := 0.2
	noodlesTotMass := 0
	sauceTotVolume := 0.0

	for _, v := range layers {
		if v == "noodles" {
			noodlesTotMass += noodleLayerGrams
		}

		if v == "sauce" {
			sauceTotVolume += sauceLayerLiters
		}
	}
	return noodlesTotMass, sauceTotVolume

}

func AddSecretIngredient(friendRecipe []string, ownRecipe []string) {
	specialIngredient := friendRecipe[len(friendRecipe)-1]
	ownRecipe[len(ownRecipe)-1] = specialIngredient
}

func ScaleRecipe(quantities []float64, portions int) []float64 {
	resultQuantities := make([]float64, 0, len(quantities))
	for _, v := range quantities {
		resultQuantities = append(resultQuantities, v*(float64(portions)/2.0))
	}
	return resultQuantities
}

// Your first steps could be to read through the tasks, and create
// these functions with their correct parameter lists and return types.
// The function body only needs to contain `panic("")`.
//
// This will make the tests compile, but they will fail.
// You can then implement the function logic one by one and see
// an increasing number of tests passing as you implement more
// functionality.
