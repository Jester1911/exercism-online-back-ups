#pragma once
#include <vector>
#include <string>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(const std::vector<std::string>& layers, int AvgLayerTime = 2);

amount quantities(const std::vector<std::string>& items);

void addSecretIngredient(std::vector<std::string>& mine, const std::vector<std::string>& theirs);

void addSecretIngredient(std::vector<std::string>& mine, std::string theirs);

std::vector<double> scaleRecipe(std::vector<double> twoPortionQuantity, int desiredQuantities);




    
}  // namespace lasagna_master
