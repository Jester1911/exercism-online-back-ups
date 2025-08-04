#include "rotational_cipher.h"
#include <string>
#include <vector>
namespace rotational_cipher {

    // Caesar cipher shifts letters in relation to their alphabet position 
    // by n letters to the right. 
    // To handle wrap around of the end of the alphabet, we do mod 26
    // static_cast<unsigned char> when using isupper() and islower() as
    // using those functions on a negative value results in UB.
    
    std::string rotate(std::string input, int shiftBy) {
        std::vector<std::string> uppercase{};
        std::vector<std::string> lowercase{};
        std::string result{""};

        // Init vectors for mapping by building out vectors of letters so that positional 
        // shifts can be resolved by indexing into vectors
        for (int i = 0; i < 26; ++i) {
            uppercase.push_back(std::string(1, 'A' + i));
            lowercase.push_back(std::string(1, 'a' + i));
        }

        // Algorithm
        for (char c : input) {
            if (std::isupper(static_cast<unsigned char>(c))) {
                result += uppercase[((c - 'A' + shiftBy) % 26)];
                
            } else if (std::islower(static_cast<unsigned char>(c))) {
                result += lowercase[((c - 'a' + shiftBy) % 26)];
                
            } else {
                // Retain whitespace, numbers, and punctuation as-is
                result += std::string(1, static_cast<unsigned char>(c));
            }
        }
        
        return result;
    }

    
}  // namespace rotational_cipher
