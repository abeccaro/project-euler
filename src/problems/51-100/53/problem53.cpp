//
// Created by Alex Beccaro on 09/01/18.
//

#include "problem53.hpp"
#include "generics.hpp"

using generics::binomial_coefficient;
using boost::multiprecision::uint1024_t;

namespace problems {
    uint32_t problem53::solve(uint32_t max_n, uint32_t threshold) {
        uint32_t result = 0;

        for (uint1024_t n = 1; n <= max_n; n++)
            for (uint1024_t r = 1; r <= n; r++)
                if (binomial_coefficient(n, r) > threshold)
                    result++;

        return result;
    }
}