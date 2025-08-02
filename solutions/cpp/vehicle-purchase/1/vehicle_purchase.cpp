#include "vehicle_purchase.h"

namespace vehicle_purchase {

// needs_license determines whether a license is needed to drive a type of
// vehicle. Only "car" and "truck" require a license.
bool needs_license(std::string kind) {
    if (kind == "car" || kind == "truck"){
        return true;
    } else {
        return false;
    }
}

// choose_vehicle recommends a vehicle for selection. It always recommends the
// vehicle that comes first in lexicographical order.
std::string choose_vehicle(std::string option1, std::string option2) {
    std::string choice{""};
    if (option1 < option2) {
        choice = option1;
    } else {
        choice = option2;
    }

    return choice + " is clearly the better choice.";
}

// calculate_resell_price calculates how much a vehicle can resell for at a
// certain age.
double calculate_resell_price(double original_price, double age) {
    double LESS_THAN_THREE_YEAR{0.8};
    double AT_LEAST_TEN_YEAR{0.5};
    double AT_LEAST_3_LESS_TEN{0.7};
    double price{0};
    
    if (age < 3.0) {
        price = original_price * LESS_THAN_THREE_YEAR;    
    } else if (age >= 10.0) {
        price = original_price * AT_LEAST_TEN_YEAR;
    } else {
        price = original_price * AT_LEAST_3_LESS_TEN;
    }
    
    return price;
}

}  // namespace vehicle_purchase