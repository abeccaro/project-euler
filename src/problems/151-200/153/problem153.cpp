//
// Created by Alex Beccaro on 27/08/2022.
//

#include "problem153.hpp"
#include <cmath>

namespace problems {
    uint64_t problem153::solve(uint64_t ub) {
        auto root = (uint64_t) sqrt(ub);
        uint64_t result = 0;

        // divisors with a, b > 0 and a != b
        // same as looping on generics::coprime_pairs(root) but without using memory to improve performance
        for (uint64_t a = 0, b = 1, c = 1, d = root; c < d;) {
            uint64_t sum2 = c*c + d*d;
            for (uint64_t g = 1; g * sum2 <= ub; g++) {
                uint64_t multiples = ub / (g * sum2);
                result += 2 * g * (c + d) * multiples;
            }

            uint64_t k = (root + b) / d;
            uint64_t temp = a;
            a = c;
            c = k * c - temp;
            temp = b;
            b = d;
            d = k * d - temp;
        }

        // integer divisors
        result += ub * ub;
        for (uint64_t n = 1; n <= ub; n++)
            result -= ub % n;

        // divisors with a = b
        for (uint64_t i = 1; i <= ub / 2; i++) {
            uint64_t multiples = ub / (2 * i);
            result += 2 * i * multiples;
        }

        return result;
    }
}