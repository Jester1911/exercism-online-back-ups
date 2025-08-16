#include "collatz_conjecture.h"
#include <string>
#include <stdexcept>
#include <iostream>

namespace collatz_conjecture {

    int algo(int& number) {
        int divisor{2};
        int steps{0};
        
        while (number % divisor == 0) {
            divisor *= 2;
            ++steps;
        }

        if (divisor > 2) {
            divisor /= 2;
        }
        
        if (number % divisor == 0) {
            number /= divisor;
        } else {
            number = 3 * number + 1;
            ++steps;
        }

        return steps;
    }
    
    int steps(int number) {
        int count{0};

        // Guard clause
        if (number < 1) {
            throw std::domain_error("Input is less than 1.");
        }
        
        while (number > 1 ) {            
            std::cout << "Number: " << std::to_string(number) << std::endl;
            count += algo(number);
        }

        return count;
    }

}  // namespace collatz_conjecture
