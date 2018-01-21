//
// Created by Alex Beccaro on 07/01/18.
//

#include "problem47.hpp"
#include <primes.hpp>
#include <iostream>

using primes::prime_factors;

namespace problems {
    uint problem47::solve(uint n, uint factors) {
        uint result;
        uint found = 0;

        for (uint i = 1; found < n; i++)
            if (prime_factors(i).size() == factors) {
                found++;
                if (found == n)
                    result = i - n + 1;
            } else
                found = 0;

        return result;
    }
}