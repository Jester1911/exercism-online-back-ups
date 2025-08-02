#pragma once
#include <unordered_set>
#include <vector>

namespace sum_of_multiples {

    void collectMultiples(const int level, const int itemBase, std::unordered_set<int>& container);
    int to(std::vector<int>items, int level);
    
}  // namespace sum_of_multiples
