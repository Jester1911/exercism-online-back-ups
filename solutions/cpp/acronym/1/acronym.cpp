#include "acronym.h"

namespace acronym {

    std::string acronym(std::string input) {
        std::string result{input[0]};
        bool getNextChar{false};

        // Should try to split input on whitespace or non-alpha chars
        // Then capitalize first element of every substring
        
        for (char c : input) {
            if (getNextChar && std::isalpha(c)) {
                result.push_back(std::toupper(c));
                getNextChar = false;
            }

            if (!std::isalnum(static_cast<unsigned char>(c))) {
                if (c != '\'') {
                    getNextChar = true;
                }
            }
        }
        return result;
    }

}  // namespace acronym
