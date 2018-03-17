//
// Created by Alex Beccaro on 14/01/18.
//

#include "problem63.hpp"
#include <generics.hpp>

using boost::multiprecision::uint128_t;
using generics::digits;

namespace problems {
    uint problem63::solve() {
        const uint MAX_BASE = 9; // 10^x will always have x+1 digits so bases range is [1,9]
        const uint MAX_EXP = 21; // log_10(9^x) + 1 = x gives 21.8... so the maximum exponent to check is 21

        uint result = 0;
        for (uint b = 1; b <= MAX_BASE; b++) {
            uint128_t n = 1;
            for (uint e = 1; e <= MAX_EXP; e++) {
                n *= b;
                if (digits(n).size() == e)
                    result++;
            }
        }
        return result;
    }
}