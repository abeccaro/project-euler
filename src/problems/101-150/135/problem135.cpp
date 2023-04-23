//
// Created by Alex Beccaro on 05/12/2019.
//

#include "problem135.hpp"
#include "vector"


using std::vector;


namespace problems {

    uint64_t problem135::solve(uint64_t ub, uint32_t n) {
        uint32_t res = 0;

        std::vector<uint32_t> counts(ub - 1, 0);
        for (uint64_t k = 1; k <= ub / 4; k++) {
            uint64_t k2 = k * k;
            for (uint64_t x = 2 * k - 1; x < ub; x--) {
                uint64_t x2 = x * x;
                if (4 * k2 <= x2)
                    break;
                uint64_t a = 4 * k2 - x2;
                if (a < ub)
                    counts[a - 1] += (k > x && x != 0) ? 2 : 1;
                else
                    break;
            }
        }

        for (uint32_t i = 1; i < ub; i++)
            if (counts[i - 1] == n)
                res++;

        return res;
    }

}