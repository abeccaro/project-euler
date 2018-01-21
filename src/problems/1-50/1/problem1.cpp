//
// Created by Alex Beccaro on 18/01/18.
//

#include "problem1.hpp"

namespace problems {
    uint problem1::multiplesSum(uint n, uint ub) {
        uint sum = 0;

        for (uint i = 1; n * i < ub; i++)
            sum += n * i;

        return sum;
    }

    uint problem1::solve(uint ub) {
        const uint N1 = 3;
        const uint N2 = 5;

        return multiplesSum(N1, ub) + multiplesSum(N2, ub) - multiplesSum(N1 * N2, ub);
    }
}