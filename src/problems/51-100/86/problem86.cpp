//
// Created by Alex Beccaro on 25/02/18.
//

#include <cmath>
#include "problem86.hpp"

namespace problems {
    uint32_t problem86::sum_combinations(uint32_t sum, uint32_t m) {
        return (m < sum ? m + 1 : sum) - (uint32_t) ceil(sum / 2.0f);
    }

    uint32_t problem86::solve(uint32_t n) {
        uint32_t m, solutions = 0;

        for (m = 1; solutions <= n; m++) {
            uint32_t square = m * m;
            for (uint32_t i = 2; i <= 2 * m; i++) {
                uint32_t sol = i * i + square;
                auto root = sqrt(sol);

                if (root == (uint32_t) root)
                    solutions += sum_combinations(i, m);
            }
        }

        return m - 1;
    }
}