#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <cctype>

namespace trinary {

    std::vector<std::string> string_to_vec_string(std::string input);

    std::vector<int> vec_string_to_vec_int(std::vector<std::string> input);

    int convert_trinary_digit(int number, int digit_pos);
    
    int to_decimal(std::string);

}  // namespace trinary
