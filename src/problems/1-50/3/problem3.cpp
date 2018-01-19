//
// Created by Alex Beccaro on 11/12/17.
//

#include "problem3.hpp"
#include "primes.hpp"

using primes::prime_factors;

namespace problems {
    ulong problem3::solve(ulong n) {
        return prime_factors(n).back();
    }
}