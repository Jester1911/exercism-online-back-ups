// ovenTime returns the amount in minutes that the lasagna should stay in the
// oven.
int ovenTime() {
    return 40;
}

/* remainingOvenTime returns the remaining
   minutes based on the actual minutes already in the oven.
*/
int remainingOvenTime(int actualMinutesInOven) {
    int remainingOvenTime = ovenTime() - actualMinutesInOven;
    
    return remainingOvenTime;
}

/* preparationTime returns an estimate of the preparation time based on the
   number of layers and the necessary time per layer.
*/
int preparationTime(int numberOfLayers) {
    int MINS_PREP_PER_LAYER{2};
    
    return numberOfLayers * MINS_PREP_PER_LAYER;
}

// elapsedTime calculates the total time spent to create and bake the lasagna so
// far.
int elapsedTime(int numberOfLayers, int actualMinutesInOven) {
    int prepTime = preparationTime(numberOfLayers);
    int totalTime = prepTime + actualMinutesInOven;
    
    return totalTime;
}
