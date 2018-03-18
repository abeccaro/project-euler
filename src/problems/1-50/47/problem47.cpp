//
// Created by Alex Beccaro on 07/01/18.
//

#include "problem47.hpp"
#include <primes.hpp>
#include <iostream>

using primes::prime_factors;

namespace problems {
    uint32_t problem47::solve(uint32_t n, uint32_t factors) {
        uint32_t result;
        uint32_t found = 0;

        for (uint32_t i = 1; found < n; i++)
            if (prime_factors(i).size() == factors) {
                found++;
                if (found == n)
                    result = i - n + 1;
            } else
                found = 0;

        return result;
    }
}