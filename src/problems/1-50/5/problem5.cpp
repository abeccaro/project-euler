//
// Created by Alex Beccaro on 11/12/17.
//

#include "problem5.hpp"
#include "generics.hpp"

using generics::lcm;

namespace problems {
    /**
     * Specifies values, solves problem and outputs solution and calculation time.
     * @return The exit code
     */
    ulong problem5::solve(ulong max_divisor) {
        vector<ulong> divisors;
        for (ulong i = 2; i <= max_divisor; i++)
            divisors.push_back(i);

        return lcm(divisors);
    }
}