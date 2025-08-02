#include "armstrong_numbers.h"
#include <cmath>
#include <vector>
#include <iostream>

namespace armstrong_numbers {

    bool is_armstrong_number(long number){
        int numDigits = (number == 0) ? 1 : std::log10(abs(number)) + 1;
        std::vector<int> vecDigits{};
        int divisor{1};
        int modulus{10};
        long result{0};

        // We need to get the value of each digit. We take the modulus 
        // to disregard heavier digit weights than currently processing,
        // then divide by a divisor that is the weight of the digit we are            // currently one.
        for (int i = 0; i < numDigits; ++i) {
            vecDigits.push_back((number % (modulus)) / divisor);
            modulus *= 10;
            divisor *= 10;
        }

        // Perform Armstrong algorithm here
        for (int n : vecDigits) {
            result += pow(n, numDigits);
            std:: cout << "n: " << n << "\n";
        }

        
        std::cout << "Input: " << number << "\n" << "Result: " << result << "\n";
        
        return result == number;
    }

}  // namespace armstrong_numbers
