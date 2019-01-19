//
// Created by Alex Beccaro on 19/01/2019.
//

#include "problem120.hpp"


namespace problems {

    uint64_t problem120::solve(uint32_t ub) {
        uint64_t res = 0;
        uint32_t r_max = 0;

        for (uint32_t a = 3; a <= ub; a++) {
            if (a % 2 == 0)
                r_max += a - 2;
            else
                r_max += 3 * (a - 1);

            res += r_max;
        }

        return res;
    }

}