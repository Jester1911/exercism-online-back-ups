#include "prime_factors.h"
#include <vector>


namespace prime_factors {

    /*    
        1. Choose a number -> see if it cleanly divides into the bigger number
        - If yes, continue dividing new result
        - If no, increment divisor and try again with number
        2. You are done dividing when the result is 1 

    */

    
    std::vector<long long> of(long long number) {
        long long divisor{2};
        long long left{number};
        std::vector<long long> primes{};

        // Early Return
        if (number == 1) {
            return std::vector<long long>{};
        }

        while (divisor <= left) {
            if (left % divisor == 0) {
                primes.push_back(divisor);
                left /= divisor;
            } else {
                ++divisor;
            }
        } 
        return primes;
    }

}  // namespace prime_factors
