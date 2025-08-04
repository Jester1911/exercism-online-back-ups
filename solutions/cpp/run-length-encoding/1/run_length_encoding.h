#pragma once
#include <string>

namespace run_length_encoding {
    

    std::string encode(const char* input);

    std::string decode(std::string input);

}  // namespace run_length_encoding
