//
// Created by Alex Beccaro on 11/12/17.
//

#include <iostream>
#include "Primes.h"

using namespace std;

namespace primes {
    /*
     * Calculates all given number prime factors using division trial.
     * Complexity: O(√n).
     */
    vector<int> primeFactors(long n) {
        vector<int> factors;

        if (n % 2 == 0)
            factors.push_back(2);

        for (int i = 3; i * i <= n; i = i+2) {
            if (n % i == 0)
                factors.push_back(i);
            while (n % i == 0)
                n /= i;
        }

        if (n > 2)
            factors.push_back(n);

        return factors;
    }
}