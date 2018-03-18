//
// Created by Alex Beccaro on 11/12/17.
//

#include "problem3.hpp"
#include "primes.hpp"

using primes::prime_factors;

namespace problems {
    uint64_t problem3::solve(uint64_t n) {
        return prime_factors(n).back();
    }
}