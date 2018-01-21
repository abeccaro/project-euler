//
// Created by Alex Beccaro on 21/01/18.
//

#include "problem69.hpp"
#include <generics.hpp>

using generics::totient;
using primes::prime_factors;

namespace problems {
    uint problem69::solve(uint ub) {
        double max = 0;
        uint argmax = 0;

        for (uint i = 2; i <= ub; i++) {
            double x = (double) i / totient<ulong>(i);
            if (x > max) {
                max = x;
                argmax = i;
            }
        }

        return argmax;
    }
}
