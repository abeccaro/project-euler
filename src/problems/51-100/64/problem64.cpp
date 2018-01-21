//
// Created by Alex Beccaro on 14/01/18.
//

#include "problem64.hpp"
#include <cmath>
#include <vector>

using std::vector;

namespace problems {
    uint problem64::solve(uint ub) {
        uint result = 0;

        for (uint i = 2; i <= ub; i++) {
            vector<uint> period;

            auto a_0 = (uint) sqrt(i);
            uint a = a_0;
            uint m = 0;
            uint d = 1;

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