//
// Created by Alex Beccaro on 27/08/2022.
//

#include "problem153.hpp"
#include <vector>
#include <cmath>

using std::vector;
using std::pair;

namespace problems {
    uint64_t problem153::solve(uint64_t ub) {
        uint64_t result = 0;
        auto root = (uint64_t) sqrt(ub);

        // divisors with a, b > 0 and a != b using Farey sequence.
        // To optimize we stop when we reach 1/2 (considered at the end of the loop) and for each pair (a, b) we also
        // consider (b-a, b) to still use all coprime pairs
        uint64_t a = 1;
        uint64_t b = root;
        uint64_t c = (root + 1) / root;
        uint64_t d = ((root + 1) / root) * root - 1;

        while(b != 2) {
            uint64_t a2 = a * a;
            uint64_t b2 = b * b;

            for (uint64_t g = 1; g * (a2 + b2) <= ub; g++) {
                uint64_t multiples = ub / (g * (a2 + b2));
                result += 2 * g * (a + b) * multiples;
            }

            uint64_t z = b - a;
            uint64_t z2 = z * z;

            for (uint64_t g = 1; g * (z2 + b2) <= ub; g++) {
                uint64_t multiples = ub / (g * (z2 + b2));
                result += 2 * g * (z + b) * multiples;
            }

            uint64_t k = (root + b) / d;
            uint64_t new_c = k * c - a;
            uint64_t new_d = k * d - b;
            a = c;
            b = d;
            c = new_c;
            d = new_d;
        }

        for (uint64_t g = 1; g * 5 <= ub; g++) {
            uint64_t multiples = ub / (g * 5);
            result += 6 * g * multiples;
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