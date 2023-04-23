//
// Created by Alex Beccaro on 21/01/18.
//

#include "problem69.hpp"
#include "generics.hpp"

using generics::totient;
using primes::prime_factors;

namespace problems {
    uint32_t problem69::solve(uint32_t ub) {
        double max = 0;
        uint32_t argmax = 0;

        for (uint32_t i = 2; i <= ub; i++) {
            double x = (double) i / totient<uint64_t>(i);
            if (x > max) {
                max = x;
                argmax = i;
            }
        }

        return argmax;
    }
}
