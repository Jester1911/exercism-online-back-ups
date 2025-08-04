#include "run_length_encoding.h"
#include<cctype>


namespace run_length_encoding {

    std::string encode(const char* input) {
        std::string result{""};
        std::string lastLetter{input[0]};
        std::string currentLetter{""};
        int currentRun{0};

        // Handle empty string
        if (*input == '\0') {
            return "";
        }
        
        // Algorithm
        for (size_t i = 0; input[i] != '\0'; ++i) {
            currentLetter = input[i];
            if (currentLetter == lastLetter) {
                ++currentRun;
            } else {
                if (currentRun == 1) {
                    result += lastLetter;
                    lastLetter = currentLetter;
                } else {
                    result += std::to_string(currentRun) + lastLetter;
                    lastLetter = currentLetter;
                    currentRun = 1;
                }
            }
        }

        // To handle very last character before EOF
        if (currentRun == 1) {
            result += lastLetter;
        } else {
            result += std::to_string(currentRun) + lastLetter;
        }
        
        return result;
    }

    std::string decode(std::string input) {
        std::string result{""};
        std::string number{""};
        std::string tempStr{""};
        char current;

        // Algorithm
        for(int i = 0; input[i] != '\0'; ++i) {
            current = input[i];

            if (std::isalpha(current) || std::isspace(current)) {
                if (!number.empty()) {
                    tempStr = std::string(static_cast<size_t>(std::stoi(number)), current);
                    result += tempStr;
                    number = "";
                } else {
                    result += current;
                    number = "";
                }
            } else {
                number+= current;
            }
        }

        return result;
    }
    
}  // namespace run_length_encoding
