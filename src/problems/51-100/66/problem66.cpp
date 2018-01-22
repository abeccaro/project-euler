//
// Created by Alex Beccaro on 16/01/18.
//

#include "problem66.hpp"
#include <fraction.hpp>
#include <series/sqrt_convergents.hpp>

using fractions::fraction;
using series::sqrt_convergents;

namespace problems {
    uint problem66::solve(uint ub) {
        uint result = 0;
        uint256_t max_x = 0;

        for (uint n = 2; n <= ub; n++) {
            auto root = (uint) sqrt(n);
            if (root * root == n) // perfect square
                continue;

            sqrt_convergents<uint128_t> c(n);

            for (auto j = c.begin(); j < c.end(); j++) {
                uint256_t x = j->numerator();
                uint256_t y = j->denominator();

                if (x * x - (n * y * y) == 1) {
                    if (x > max_x) {
                        max_x = x;
                        result = n;
                    }
                    break;
                }
            }
        }

        return result;
    }
}