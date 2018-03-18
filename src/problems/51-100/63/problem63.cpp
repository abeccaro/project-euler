//
// Created by Alex Beccaro on 14/01/18.
//

#include "problem63.hpp"
#include <generics.hpp>

using boost::multiprecision::uint128_t;
using generics::digits;

namespace problems {
    uint32_t problem63::solve() {
        const uint32_t max_base = 9; // 10^x will always have x+1 digits so bases range is [1,9]
        const uint32_t max_exp = 21; // log_10(9^x) + 1 = x gives 21.8... so the maximum exponent to check is 21

        uint32_t result = 0;
        for (uint32_t b = 1; b <= max_base; b++) {
            uint128_t n = 1;
            for (uint32_t e = 1; e <= max_exp; e++) {
                n *= b;
                if (digits(n).size() == e)
                    result++;
            }
        }
        return result;
    }
}