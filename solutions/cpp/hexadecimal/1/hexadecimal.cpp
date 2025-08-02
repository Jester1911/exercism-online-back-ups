#include "hexadecimal.h"
#include <string>
#include <cctype>
#include <cmath>
#include <vector>

namespace hexadecimal {

    unsigned int hexDigitToDec(char c) {
        if (std::isdigit(c)) {
            return static_cast<unsigned int> (c - '0');
            
        } else if (std::isalpha(c)) {
            int n = c - 'a';
            n = n + 10;
            if ( n > 15) {
                return 999;
            }
            return static_cast<unsigned int> (n);
        }
        return 0;
    }

    unsigned int convert(const char* input) {
        std::vector<unsigned int> digits{};
        int weight{0};
        unsigned int sum{0};
        
        for (int i = 0; input[i] != '\0'; ++i) {
            digits.push_back(hexDigitToDec(input[i]));
        }

        for (size_t i = digits.size(); i-- > 0;) {
            // guard clause to detect invalid input string
            if (digits[i] == 999) {
                return 0;
            }
            // since hexDigitToDec already returns each hex digit as 0..15, 
            // but does not take into account base (e.g. 16), we use 16 as base
            // for exponentiation
            sum += digits[i] * pow(16, weight);
            weight += 1;
        }
        return sum;
    }



    

}  // namespace hexadecimal
