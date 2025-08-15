#include "lasagna_master.h"

namespace lasagna_master {

int preparationTime(const std::vector<std::string>& layers, int avgPrepTime) {
    return layers.size() * avgPrepTime;
}

amount quantities(const std::vector<std::string>& items) {
    int NOODLE_MASS_G{50};
    double SAUCE_VOLUME_L{0.2};
    amount result{};
    
    for (std::string item : items) {
        if (item == "noodles") {
            result.noodles += NOODLE_MASS_G;
        } else if (item == "sauce") {
            result.sauce += SAUCE_VOLUME_L;
        }
    }
    return result;
}

void addSecretIngredient(std::vector<std::string>& mine, const std::vector<std::string>& theirs) {
    if (mine.size() > 0 && theirs.size() > 0) {
        mine[mine.size() - 1] = theirs[theirs.size() - 1];
    }
}

void addSecretIngredient(std::vector<std::string>& mine, std::string theirs) {
    if (mine.size() > 0) {
        mine[mine.size() - 1] = theirs;
    }
}

std::vector<double> scaleRecipe(std::vector<double> twoPortionQuantity, int desiredQuantities) {
    double multiplier{desiredQuantities * 0.5};
    std::vector<double> result{};

    for (double item : twoPortionQuantity) {
        result.push_back(item * multiplier);
    }
    
    return result;
}
    
}  // namespace lasagna_master
