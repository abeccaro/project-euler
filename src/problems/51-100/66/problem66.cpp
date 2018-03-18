//
// Created by Alex Beccaro on 16/01/18.
//

#include "problem66.hpp"
#include <fraction.hpp>
#include <series/sqrt_convergents.hpp>

using boost::multiprecision::uint128_t;
using boost::multiprecision::uint256_t;
using fractions::fraction;
using series::sqrt_convergents;

namespace problems {
    uint32_t problem66::solve(uint32_t ub) {
        uint32_t result = 0;
        uint256_t max_x = 0;

        for (uint32_t n = 2; n <= ub; n++) {
            auto root = (uint32_t) sqrt(n);
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