#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace allergies {

    class Allergies {
    private:
        int score_{0};
        std::vector<std::string> hasAllergies_;

        // Shared allergy data (1 copy for all objects)
        inline static const std::unordered_map<int, std::string> allergyValues_{
            {1, "eggs"},
            {2, "peanuts"},
            {4, "shellfish"},
            {8, "strawberries"},
            {16, "tomatoes"},
            {32, "chocolate"},
            {64, "pollen"},
            {128, "cats"},
        };

        // Private helper methods
        std::string getAllergy(int key);
        void find_allergies();

    public:
        explicit Allergies(int score); // Constructor
        bool is_allergic_to(const std::string& allergy) const;
        std::unordered_set<std::string> get_allergies() const;
    };

    // Free function that Exercism wants
    Allergies allergy_test(int score);

} // namespace allergies
