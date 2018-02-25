//
// Created by Alex Beccaro on 25/02/18.
//

#include <algorithm>
#include <cmath>
#include "problem86.hpp"

namespace problems {
    uint problem86::sum_combinations(uint sum, uint m) {
        return (m < sum ? m + 1 : sum) - (uint) std::ceil(sum / 2.0f);
    }

    uint problem86::solve(uint n) {
        uint m, solutions = 0;

        for (m = 1; solutions <= n; m++) {
            uint square = m * m;
            for (uint i = 2; i <= 2 * m; i++) {
                uint sol = i * i + square;
                auto root = std::sqrt(sol);

                if (root == (uint) root)
                    solutions += sum_combinations(i, m);
            }
        }

        return m - 1;
    }
}