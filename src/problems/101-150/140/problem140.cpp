//
// Created by Alex Beccaro on 09/12/2019.
//

#include "problem140.hpp"
#include <vector>


namespace problems {

    int64_t problem140::solve(uint64_t n) {
        int32_t count = 0;
        int64_t res = 0;

        // From 5x² - y² + 14 x + 1 = 0 using https://www.alpertron.com.ar/QUAD.HTM
        std::vector<std::pair<int64_t, int64_t>> sols = {{-4, 5}, {-3, 2}, {-3, -2}, {2, -7}, {0, -1}, {0, 1}};

        for (int i = 0; count < n; i++) {
            auto sol = sols[i % sols.size()];
            int64_t x = sol.first;
            int64_t y = sol.second;

            int64_t new_x = -9 * x - 4 * y - 14;
            sol.second = -20 * x - 9 * y - 28;
            sol.first = new_x;
            sols[i % sols.size()] = sol;

            if (sol.first > 0) {
                count++;
                res += sol.first;
            }
        }

        return res;
    }

}