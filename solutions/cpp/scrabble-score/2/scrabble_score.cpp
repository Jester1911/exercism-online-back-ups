#include "scrabble_score.h"
#include <string>
#include <array>

namespace scrabble_score {

    std::unordered_map<char, int> buildLookUpCache() {
        std::unordered_map<char, int> cache{};
        std::array<char, 10> one{'A', 'E', 'I', 'O', 'U', 'L', 'N', 'R', 'S', 'T'};
        std::array<char, 2> two{'D', 'G'};
        std::array<char, 4> three{'B', 'C', 'M', 'P'};
        std::array<char, 5> four{'F', 'H', 'V', 'W', 'Y'};
        std::array<char, 1> five{'K'};
        std::array<char, 2> eight{'J', 'X'};
        std::array<char, 2> ten{'Q', 'Z'};
        
        for (char c : one) {
            cache[c] = 1;
        }
    
        for (char c : two) {
            cache[c] = 2;
        }
    
        for (char c : three) {
            cache[c] = 3;
        }
    
        for (char c : four) {
            cache[c] = 4;
        }
    
        for (char c : five) {
            cache[c] = 5;
        }
    
        for (char c : eight) {
            cache[c] = 8;
        }
    
        for (char c : ten) {
            cache[c] = 10;
        }
    
        return cache;
    }
    
    int score(std::string input) {
        const std::unordered_map<char, int> lookUp{buildLookUpCache()};
        int sum{0};

        for (char c : input) {
            auto it = lookUp.find(std::toupper(c));
            if (it != lookUp.end()) {
                sum += it->second;    
            }
                        
        }
        
        return sum;
    }

}  // namespace scrabble_score
