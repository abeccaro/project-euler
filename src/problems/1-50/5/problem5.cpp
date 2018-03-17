//
// Created by Alex Beccaro on 11/12/17.
//

#include "problem5.hpp"
#include "generics.hpp"

using generics::lcm;

namespace problems {
    ulong problem5::solve(ulong max_divisor) {
        std::vector<ulong> divisors;
        for (ulong i = 2; i <= max_divisor; i++)
            divisors.push_back(i);

        return lcm(divisors);
    }
}