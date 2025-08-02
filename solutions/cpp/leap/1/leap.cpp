#include "leap.h"

namespace leap {

bool is_leap_year(int currentYear) {
    bool isLeapYear{false};
    if (currentYear % 100 == 0) {
        if (currentYear % 400 == 0) {
            isLeapYear = true;
        } else {
            isLeapYear = false;
        }
    } else if (currentYear % 4 == 0){
        isLeapYear = true;
    } else {
        isLeapYear = false;
    }

    return isLeapYear;
}

}  // namespace leap
