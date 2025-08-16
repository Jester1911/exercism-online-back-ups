#pragma once
#include <unordered_map>
#include <string>

namespace scrabble_score {

    std::unordered_map<char, int> buildLookUpCache();

    int score(std::string);

}  // namespace scrabble_score
