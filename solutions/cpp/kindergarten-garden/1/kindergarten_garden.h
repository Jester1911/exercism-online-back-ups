#pragma once
#include <array>
#include <string>

namespace kindergarten_garden {

    enum class Plants {
        clover,
        grass,
        radishes,
        violets
    };

    Plants mapLetterToPlant(const char letter);

    std::array<Plants, 4> plants(std::string garden, std::string student);

}  // namespace kindergarten_garden
