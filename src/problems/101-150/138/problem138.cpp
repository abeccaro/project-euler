//
// Created by Alex Beccaro on 06/12/2019.
//

#include "problem138.hpp"


namespace problems {

    uint64_t problem138::solve(uint32_t n) {
        uint64_t res = 0;
        uint64_t x = 1, y = 2;

        for (uint32_t i = 0; i < n; i++) {
            uint64_t x_new = 9 * x + 4 * y;
            y = 20 * x + 9 * y;
            x = x_new;

            res += x;
        }

        return res;
    }

}