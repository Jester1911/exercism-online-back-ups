#include "secret_handshake.h"
#include <bitset>
#include <algorithm>

namespace secret_handshake {

const std::string determineAction(const size_t index) {
    const std::vector<std::string> actions{
        "wink", "double blink", "close your eyes",
            "jump", "reverse"
    };

    if (index <= 4) {
        return actions[index];
    } else {
        return "";
    }
}

    
std::vector<std::string> commands(int number) {
    std::bitset<8> bNumber(number); // map to bit set/array
    std::vector<std::string> actions{};
    
    for (size_t i = 0; i <= 4; i++) {
        if (bNumber[i]) {
            std::string s = determineAction(i);
            if (s != "") {
                actions.push_back(s);
    
                // Reverse and discard "reverse" element
                if (s == "reverse") {
                    actions.pop_back();
                    std::reverse(actions.begin(), actions.end());
                }
            }
        }
    }

    return actions;
}

}  // namespace secret_handshake
