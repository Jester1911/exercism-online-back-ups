#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype> 
#include <vector>

namespace luhn {
    
    std::string stripSpaces(const char* input);
    bool isAllDigits(std::string input);
    bool valid(const char* input);

}  // namespace luhn
