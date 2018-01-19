//
// Created by Alex Beccaro on 18/01/18.
//

#include "problem1.hpp"

namespace problems {
    /**
     * Calculates the sum of all multiples of given number below given upperBound.
     * @param n The number
     * @param upperBound The upper bound
     * @return The sum of multiples
     */
    uint problem1::multiplesSum(uint n, uint upper_bound) {
        uint sum = 0;

        for (uint i = 1; n * i < upper_bound; i++)
            sum += n * i;

        return sum;
    }

    /**
     * Specifies values, solves problem and outputs solution and execution time.
     * @return The result
     */
    uint problem1::solve(uint ub) {
        const uint N1 = 3;
        const uint N2 = 5;

        return multiplesSum(N1, ub) + multiplesSum(N2, ub) - multiplesSum(N1 * N2, ub);
    }
}