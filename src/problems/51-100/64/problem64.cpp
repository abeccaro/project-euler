//
// Created by Alex Beccaro on 14/01/18.
//

#include "problem64.hpp"
#include <cmath>
#include <vector>

using std::vector;

namespace problems {
    uint32_t problem64::solve(uint32_t ub) {
        uint32_t result = 0;

        for (uint32_t i = 2; i <= ub; i++) {
            vector<uint32_t> period;

            auto a_0 = (uint32_t) sqrt(i);
            uint32_t a = a_0;
            uint32_t m = 0;
            uint32_t d = 1;

            if (a * a == i) // perfect square
                continue;

            do {
                m = d * a - m;
                d = (i - m * m) / d;
                a = (a_0 + m) / d;

                period.push_back(a);
            } while (period.back() != a_0 * 2);

            if (period.size() % 2 == 1)
                result++;
        }

        return result;
    }
}