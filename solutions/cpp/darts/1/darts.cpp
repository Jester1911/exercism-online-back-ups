#include "darts.h"
#include <cmath>

namespace darts {

    double euclidean_distance(double x, double y) {
        double distance{0};
        distance = std::sqrt(x*x + y*y);
        return distance;
    }

    int score(double x, double y) {
        double distance{euclidean_distance(x, y)};
        int score{0};
        if (distance > 10) {
            score = 0;
        } else if (distance > 5 && distance <= 10) {
            score = 1;
        } else if (distance > 1 && distance <= 5) {
            score = 5;
        } else if (distance <= 1) {
            score = 10;
        }

        return score;
    }

}  // namespace darts