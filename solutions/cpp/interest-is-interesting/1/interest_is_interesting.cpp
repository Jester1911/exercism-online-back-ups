
struct DollarAndInterest {
    double amount;
    double interest;
};





// interest_rate returns the interest rate for the provided balance.
double interest_rate(double balance) {
    double interest{0.0};

    if (balance < 0) {
        interest = 3.213;
    } else if (balance < 1000.0) {
        interest = 0.5;
    } else if (balance < 5000.0) {
        interest = 1.621;
    } else {
        interest = 2.475;
    }

    return interest;
}

// yearly_interest calculates the yearly interest for the provided balance.
double yearly_interest(double balance) {
    double accruedInterest{0.0};
    accruedInterest = interest_rate(balance) * 0.01 * balance;
    
    return accruedInterest;
}

// annual_balance_update calculates the annual balance update, taking into
// account the interest rate.
double annual_balance_update(double balance) {
    double yearEndBalance{0.0};
    yearEndBalance = yearly_interest(balance) + balance;
    return yearEndBalance;
}

// years_until_desired_balance calculates the minimum number of years required
// to reach the desired balance.
int years_until_desired_balance(double balance, double target_balance) {
    double currentBalance{balance};
    int yearsToAchieve{0};

    for (; currentBalance < target_balance; ++yearsToAchieve) {
        currentBalance = annual_balance_update(currentBalance);
    }

    return yearsToAchieve;




    
    return 0;
}