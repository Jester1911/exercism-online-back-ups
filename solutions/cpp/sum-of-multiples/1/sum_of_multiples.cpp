#include "sum_of_multiples.h"

namespace sum_of_multiples {

    void collectMultiples(const int level, const int itemBase, std::unordered_set<int>& container)     {
        int current{itemBase};
        
        while (true) {
            if (current < level) {
                container.insert(current);
                current+=itemBase;
            } else {
                break;
            }
        }
    }
    
    int to(std::vector<int>items, int level) {
        std::unordered_set<int> uniqueMultiples{};
        int sum{0};

        for (int item: items){
            collectMultiples(level, item, uniqueMultiples);
        }

        for (int multiple : uniqueMultiples) {
            sum+=multiple;
        }
        return sum;
    }
    
}  // namespace sum_of_multiples
