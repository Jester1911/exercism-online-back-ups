// INFO: Headers from the standard library should be inserted at the top via
// #include <LIBRARY_NAME>
#include <cmath>

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    return 8.0 * hourly_rate;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    double normalizedDiscount = 1.0 - (discount * 0.01);
    double discountedPrice{before_discount*normalizedDiscount};
    
    return discountedPrice;
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    int BILLABLE_DAYS_IN_MONTH{22};
    double discountedHourlyRate{apply_discount(hourly_rate, discount)};
    double discountedDailyRate{daily_rate(discountedHourlyRate)};
    double discountedMonthlyRate{(BILLABLE_DAYS_IN_MONTH*discountedDailyRate)};
    
    return (int)std::ceil(discountedMonthlyRate);
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    // TODO: Implement a function that takes a budget, an hourly rate, and a
    // discount, and calculates how many complete days of work that covers.
    double discountedHourlyRate{apply_discount(hourly_rate, discount)};
    double discountedDailyRate{daily_rate(discountedHourlyRate)};
    int maxFullDaysInBudget{0};
    if (discountedDailyRate > 0) {
        maxFullDaysInBudget = budget / discountedDailyRate;
    }

    return maxFullDaysInBudget;



    
}