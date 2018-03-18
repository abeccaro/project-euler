//
// Created by Alex Beccaro on 02/03/18.
//

#include "problem94.hpp"

namespace problems {
    uint32_t problem94::solve(uint32_t ub) {
        uint32_t result = 0;

        uint64_t u = 1;
        uint64_t v = 2;
        uint64_t p;

        for (int i = 1; ; i = -i) {
            uint64_t temp = 2 * u + v + i;

            v = 3 * u + 2 * v + i;
            u = temp;
            p = 3 * u + i;

            if (p > ub)
                break;

            uint64_t num = v * (u + i);
            if (num % 4 == 0)
                result += p;
        }

        return result;
    }
}