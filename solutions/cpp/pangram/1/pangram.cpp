#include "pangram.h"
#include <string>
#include <unordered_set>
#include <cctype>


namespace pangram {
    
    bool is_pangram(std::string input) {
        std::unordered_set<char> letterSet{};
        const size_t UNIQUE_LETTERS{26};
        char lower{'a'};
        
        for (char c : input) {
            if (std::isalpha(c)) {
                lower = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
                letterSet.insert(lower);
            }
        }

        return letterSet.size() == UNIQUE_LETTERS;    
    }

}  // namespace pangram
