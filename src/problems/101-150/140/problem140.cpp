//
// Created by Alex Beccaro on 09/12/2019.
//

#include "problem140.hpp"
#include <vector>


namespace problems {

    uint64_t problem140::solve(uint64_t n) {
        int count = 0;
        long res = 0;

        // From 5x² - y² + 14⁢x + 1 = 0 using https://www.alpertron.com.ar/QUAD.HTM
        std::vector<std::pair<long, long> > sols = {{-4, 5}, {-3, 2}, {-3, -2}, {2, -7}, {0, -1}, {0, 1}};

        for (int i = 0; count < n; i++) {
            auto sol = sols[i % sols.size()];
            long x = sol.first;
            long y = sol.second;

            long new_x = -9 * x - 4 * y - 14;
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