#include "hamming.h"
#include <string>
#include <stdexcept>

namespace hamming {

    int compute(std::string a, std::string b) {
        if (a.size() != b.size()) {
            throw std::domain_error("Input strings must be of equal length.");
        }

        // Algorithm
        int diffs{0};
        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                ++diffs;
            }
        }

        return diffs;
    }

}  // namespace hamming
