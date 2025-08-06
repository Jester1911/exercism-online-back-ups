#include "high_scores.h"

#include <algorithm>
#include <iostream>

namespace arcade {

std::vector<int> HighScores::list_scores() {
    return scores;
}

int HighScores::latest_score() {
    return scores.back();
}

int HighScores::personal_best() {
    int highest{0};

    if (!scores.empty()) {
        highest = scores[0];
    }

    for (int score : scores) {
        if (score > highest) {
            highest = score;
        }
    }
    return highest;
}

std::vector<int> HighScores::top_three() {
    std::vector<int> cache{scores};
    std::vector<int> result;

    std::sort(cache.begin(), cache.end(), [](int a, int b) {
       return a > b;
    });

    size_t i{0};
    while (i < cache.size() && i < 3) {
        result.push_back(cache[i]);
        ++i;
    }

    return result;
}

}  // namespace arcade
