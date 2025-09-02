#pragma once

#include <vector>
#include <string>


namespace secret_handshake {

    const std::string determineAction(const size_t index);
    
    std::vector<std::string> commands(int number);

}  // namespace secret_handshake
