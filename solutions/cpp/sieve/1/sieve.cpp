#include "sieve.h"
#include<unordered_set>
#include<vector>
#include<map>
#include<iostream>

namespace sieve {

    std::vector<int> primes(int number) {
        // Early returns
        if (number <= 1) {
            return std::vector<int>{};
        }

        // Init unordered map
        std::map<int, bool> checkedNumbers{};
        for (int i = 2; i <= number; ++i) {
            checkedNumbers.emplace(i, false);
        }

        std::vector<int> foundPrimes{};
        // Algorithm
        for (int i = 2; i <= number; ++i){
            auto it = checkedNumbers.find(i);
            if (it != checkedNumbers.end()){
                if (it->second == false) {
                    // mark all multiples of found prime in range[2..number]
                    for (int j = 2*i; j <= number; j+=i) {
                        auto it = checkedNumbers.find(j);
                        if (it != checkedNumbers.end()) {
                            checkedNumbers[j] = true;
                        }
                    }
                }
            }
        }

        // iterate over map, pushing keys with false value to vector
        for (const auto& pair : checkedNumbers) {
            if (pair.second == false) {
                foundPrimes.push_back(pair.first);
            }
        }

        return foundPrimes;
    }

}  // namespace sieve
