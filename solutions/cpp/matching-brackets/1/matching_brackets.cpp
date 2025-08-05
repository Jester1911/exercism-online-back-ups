#include "matching_brackets.h"
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

namespace matching_brackets {

    /*
        Approach is to make a stack of opening characters. When any closing character is
        encountered, check the stack. If the top element matches the closing character,
        pop from the stack.
    */

    char getValueByKey (const std::unordered_map<char, char>& myMap, char k) {
        if (myMap.find(k) != myMap.end()) {
            auto it = myMap.find(k);
            return it->second;
        }

        return '0';
    }

    bool exists (const std::unordered_set<char>& mySet, char target) {
        if (mySet.find(target) != mySet.end()) {
            return true;
        }
        
        return false;
    }


    bool check (std::string input) {
        std::vector<char> opening{};
        const std::unordered_set<char> openSet {
            '(', '{', '[' 
            };
        const std::unordered_set<char> closeSet {
            ')', '}', ']' 
            };
        const std::unordered_map<char, char> pairs {
            { '(' , ')' }, { '{' , '}' }, { '[' , ']' }
            };

        // Algorithm
        for (char c : input) {
            if (matching_brackets::exists(closeSet, c)) {
                if (opening.size() > 0 && (matching_brackets::getValueByKey(pairs, opening.back()) == c)) {
                    opening.pop_back();
                } else {
                    return false; 
                }
            } else if (matching_brackets::exists(openSet, c)) {
                opening.push_back(c);
            }
        }

        if (opening.size() == 0 ) {
            return true;
        } else {
            return false;
        }
    }   



    

}  // namespace matching_brackets
