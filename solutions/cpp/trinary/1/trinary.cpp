#include "trinary.h"
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <cctype>

namespace trinary {

    std::vector<std::string> string_to_vec_string(std::string input) {
        std::vector<std::string> result;
        for (char c : input) {
            result.push_back(std::string(1, c));
            std::cout << "Individual digit: " << std::string(1, c) << "\n";
        }
        return result;
    }

    std::vector<int> vec_string_to_vec_int(std::vector<std::string> input) {
        std::vector<int> result;
        for (std::string s : input) {
            // return empty vec if string element is not a number
            if (!std::isdigit(s[0])) {
                return {};
            }
            
            int parsedNum = (std::stoi(s));
            
            std::cout << "Parsed Num: " << parsedNum << "\n";
            
            if (parsedNum < 0 || parsedNum > 2) {
                return {};
            } else {
                result.push_back(parsedNum);
            }
        }
        return result;
    }

    int convert_trinary_digit(int number, int digit_pos) {
        int result{0};
        result = number * std::pow(3, digit_pos - 1);
        return result;
    }
    
    int to_decimal(std::string input) {
        // string to vec<std::string>
        std::vector<std::string> vecStr{string_to_vec_string(input)};
        std::vector<int> vecInt{vec_string_to_vec_int(vecStr)};
        int convertedNum{0};
        
        int vecLength = vecInt.size();
        std::cout << "Vector Length: " << vecLength << "\n";
        // Guard clause if invalid number encountered in parsing
        if (vecLength == 0) {
            return 0;
        }

        int digitCounter{1};
        int i{vecLength};
        while (i > 0) {
            convertedNum += convert_trinary_digit(vecInt.back(), digitCounter);
            vecInt.pop_back();
            ++digitCounter;
            --i;
        }

        return convertedNum;
    }

}  // namespace trinary
