#include "difference_of_squares.h"
#include <cmath>

namespace difference_of_squares {

    int difference(int number) {
        return square_of_sum(number) - sum_of_squares(number);
    }
    
    int square_of_sum(int number) {
        int sum{0};
        for (int i = 1; i <= number; i++) {
            sum += i;
        }
        return std::pow(sum, 2);
    }
    
    int sum_of_squares(int number) {
        int sumSquares{0};
        for (int i = 1; i <= number; i++) {
            sumSquares += std::pow(i, 2);
        }
        return sumSquares;
    }

}  // namespace difference_of_squares
