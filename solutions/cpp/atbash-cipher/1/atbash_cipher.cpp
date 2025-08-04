#include "atbash_cipher.h"
#include <unordered_map>
#include <string>
#include <iostream>

namespace atbash_cipher {

    /*
    //    Remember:
    //        - Numbers are unchanged
    //        - Punctuation is excluded
    //        - Characters are grouped into groups of 5
    //        - All characters are lowercase
    //        - lowercase 'a' = 97; lowercase 'z' = 122
    */

    std::string encode(std::string input) {
        std::unordered_map<std::string, std::string> letterMap{};
        int letterDelta{25};
        std::string result{""};

        // Init cypher letter mapping dictionary/map
        for (int i = 97; i <= 122; ++i){
            letterMap[std::string(1, static_cast<char>(i))] = std::string(1, static_cast<char>(i + letterDelta));
            letterDelta-=2;
        }

        // Algorithm
        int spaceCounter{0};
        
        for (char c : input) {

            // Leave digits unchanged
            if (std::isdigit(c)) {
                result += c;
                ++spaceCounter;
                
            } else if (std::isalpha(c)) {
                auto it = letterMap.find(std::string(1, std::tolower(c)));
                if (it != letterMap.end()) {
                    result += it->second;
                    ++spaceCounter;
                }
            }

            // Apply space when 5 letters encoded
            if (spaceCounter == 5) {
                result += " ";
                spaceCounter = 0;
            }
            
        }
        // Remove last character if space
        if (std::isspace(result[result.size() - 1])) {
            return result.substr(0, result.size() - 1);
        }
        
        return result;
    }

    std::string decode(std::string input) {
        std::unordered_map<std::string, std::string> letterMap{};
        int letterDelta{25};
        std::string result{""};

        // Init cypher letter mapping dictionary/map
        for (int i = 122; i >= 97; --i){
            letterMap[std::string(1, static_cast<char>(i))] = std::string(1, static_cast<char>(i - letterDelta));
            letterDelta-=2;
        }

        // Algorithm
        for (char c : input) {
            // Skip whitespace
            if (std::isspace(c)) {
                continue;
            }

            // Leave digits unchanged
            if (std::isdigit(c)) {
                result += c;  
            } else {
                auto it = letterMap.find(std::string(1, std::tolower(c)));
                if (it != letterMap.end()) {
                    result += it->second;
                }

            }
        }
        return result;
    }
}  // namespace atbash_cipher
