//
// Created by Alex Beccaro on 11/12/17.
//

#include "problem5.hpp"
#include "generics.hpp"

using std::vector;
using generics::lcm;

namespace problems {
    uint64_t problem5::solve(uint32_t max_divisor) {
        vector<uint64_t> divisors;
        for (uint32_t i = 2; i <= max_divisor; i++)
            divisors.push_back(i);

        return lcm(divisors);
    }
}