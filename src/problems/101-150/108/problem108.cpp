//
// Created by Alex Beccaro on 05/12/18.
//

#include "problem108.hpp"
#import <primes.hpp>

using std::vector;

using primes::prime_factors_multeplicity;

namespace problems {
    uint32_t problem108::solve(uint32_t n) {
        uint32_t step = 6; // empirical
        for (uint64_t i = step; ; i += step) {
            auto pf = prime_factors_multeplicity(i);

            uint32_t solutions = 1;
            for (const auto& p : pf)
                solutions *= 2 * p.second + 1;
            solutions = (solutions + 1) / 2;

            if (solutions > n)
                return i;
        }
    }
}