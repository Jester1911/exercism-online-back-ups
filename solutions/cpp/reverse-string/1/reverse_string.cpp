#include "reverse_string.h"

namespace reverse_string {

    std::string reverse_string(const char* input){
        int endIndex{-1};
        std::string result{""};

        for (int i = 0; *input != '\0'; ++i){
            ++input;
            ++endIndex;
        }

        // Move toward string beginning one index to come off \0
        --input;
        for (int i = endIndex; i >= 0; --i) {
            result += *input;
            --input;
        }

        return result;
    }

}  // namespace reverse_string
