#include "grains.h"
#include <cmath>

namespace grains {

unsigned long long square(int num) {
    unsigned long long value{static_cast<unsigned long long>(std::pow(2, num - 1))};
    return value;
}
    
 unsigned long long total() {
    unsigned long long sum{0};
    for (int i = 1; i <= 64; ++i) {
        sum += square(i);
    }
     return sum;
 }

}  // namespace grains
