#include "eliuds_eggs.h"
#include <cmath>

namespace chicken_coop {

    int positions_to_quantity(int number) {
        int numEggs{0};
        int digitPow{31};
    

        // number comes in as decimal; determine if odd so that 
        // we only deal with powers of 2 after this section.
        if (number % 2 == 1) {
            --number;
            ++numEggs;
        }

        while (number > 0) {
            if (static_cast<int>(number / (pow(2, digitPow)))  == 1) {
                number -= pow(2, digitPow);
                ++numEggs;
                --digitPow;
            } else {
                --digitPow;
            }
        }
        
        return numEggs;
    }

}  // namespace chicken_coop
