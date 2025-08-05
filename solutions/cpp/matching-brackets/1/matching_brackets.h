#pragma once
#include <string>
#include <unordered_set>
#include <unordered_map>

namespace matching_brackets {
    char getValueByKey (const std::unordered_map<char, char>& myMap, char k);
    
    bool exists (const std::unordered_set<char>& mySet, char target);
    
    bool check (std::string input);

}  // namespace matching_brackets
