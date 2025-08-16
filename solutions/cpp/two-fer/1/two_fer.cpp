#include "two_fer.h"
#include <string>

namespace two_fer {
    std::string prefix{"One for "};
    std::string suffix{", one for me."};
    
    std::string two_fer(std::string name) {
        if (name.empty()) {
            return prefix + "you" + suffix;
        } else {
            return prefix + name + suffix;
        }
    }
}  
