#include "triangle.h"
#include <stdexcept>
#include <unordered_map>

namespace triangle {

    bool isTriangle(float a, float b, float c) {

        if ((a == 0) || (b == 0) || (c == 0)) {
            return false;
        } else if ((a + b >= c) && (b + c >= a) && (a+ c >= b)) {
            return true;
        } else {
            return false;
        }
    }

    flavor kind(float a, float b, float c) {

        std::unordered_map<float, int> sides;
        sides[a]++;
        sides[b]++;
        sides[c]++;
        
        if (!isTriangle(a, b, c)){
            throw std::domain_error("Inputs do not make a Triangle");
        }

        for (const std::pair<float, int> side : sides) {
            if (side.second == 3) {
                return flavor::equilateral;
            } else if (side.second == 2) {
                return flavor::isosceles;
            }
        }
        return flavor::scalene;
    }

}  // namespace triangle
