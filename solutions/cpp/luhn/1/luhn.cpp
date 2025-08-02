#include "luhn.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype> 
#include <vector>

namespace luhn {

    std::string stripSpaces(const char* input) {
        std::string result(input);
        result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
        return result;
    }

    bool isAllDigits(std::string input) {
        for (char c : input) {
            if (!std::isdigit(static_cast<unsigned char>(c))) {
                return false; // Found a non-digit
            }
        }
        return !input.empty(); // Optional: false if string is empty
    }

    std::vector<int> parseDigits(const std::string& str) {
        std::vector<int> result(str.size());

        std::transform(str.begin(), str.end(), result.begin(), [](unsigned char c) {
            if (!std::isdigit(c)) {
                throw std::invalid_argument("Non-digit character found");
            }
            return c - '0';
        });

    return result;
}

    
    bool valid(const char* input) {
        std::string stripped(stripSpaces(input));
        bool isDigits(isAllDigits(stripped));
        int sumDigits {0};

        std::cout << stripped << "\n";
        
        // early return
        if (!(isDigits && (stripped.size() > 1))) {
            return false;
        }

        std::vector<int> vecDigits(parseDigits(stripped));
        bool doubleValue{false};
        
        for (std::size_t i = vecDigits.size(); i-- > 0;) {
           if (doubleValue) {
                vecDigits[i] = 2 * vecDigits[i];
                if (vecDigits[i] > 9) {
                    vecDigits[i] = vecDigits[i] - 9;
                }
           }

            doubleValue = !(doubleValue);
        }

        for (int n : vecDigits) {
            sumDigits += n;
        }

        std::cout << sumDigits << "\n";
        
        return (sumDigits % 10 == 0);

    }

}  // namespace luhn
