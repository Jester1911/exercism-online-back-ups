#include "allergies.h"
#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace allergies {

    Allergies::Allergies(int score) : score_{score} {
        find_allergies();
    }

    std::string Allergies::getAllergy(int key) {
        auto it = allergyValues_.find(key);
        if (it != allergyValues_.end()) {
            return it->second;
        }
        return ""; // Not found
    }

    void Allergies::find_allergies() {

        // adjust score_ to be <= 255
        while (score_ > 255) {
            score_ -= 256;
        }
        
        if (score_ % 2 == 1) {
            hasAllergies_.push_back(getAllergy(1));
            score_ -= 1;
        }

        for (int i = 7; i > 0; i--) {
            int currentValue = std::pow(2, i);
            if (currentValue <= score_) {
                hasAllergies_.push_back(getAllergy(currentValue));
                score_ -= currentValue;
            }
        }
    }

    bool Allergies::is_allergic_to(const std::string& allergy) const {
        for (const auto& a : hasAllergies_) {
            if (a == allergy) return true;
        }
        return false;
    }

    std::unordered_set<std::string> Allergies::get_allergies() const {
        return std::unordered_set<std::string>(
            hasAllergies_.begin(),
            hasAllergies_.end()
        );
    }

    Allergies allergy_test(int score) {
        return Allergies(score);
    }

} // namespace allergies
