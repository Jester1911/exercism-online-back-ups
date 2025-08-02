#pragma once

namespace triangle {

    enum class flavor {
        not_triangle,
        isosceles,
        equilateral,
        scalene
    };

    bool isTriangle(float a, float b, float c);
    
    flavor kind(float a, float b, float c);
    

}  // namespace triangle
