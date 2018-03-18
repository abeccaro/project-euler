//
// Created by Alex Beccaro on 18/01/18.
//

#include "problem1.hpp"

namespace problems {
    uint32_t problem1::multiplesSum(uint32_t n, uint32_t ub) {
        uint32_t sum = 0;

        for (uint32_t i = 1; n * i < ub; i++)
            sum += n * i;

        return sum;
    }

    uint32_t problem1::solve(uint32_t ub) {
        const uint32_t n1 = 3;
        const uint32_t n2 = 5;

        return multiplesSum(n1, ub) + multiplesSum(n2, ub) - multiplesSum(n1 * n2, ub);
    }
}