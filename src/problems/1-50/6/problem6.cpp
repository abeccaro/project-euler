//
// Created by Alex Beccaro on 12/12/17.
//

#include "problem6.hpp"

namespace problems {
    uint64_t problem6::solve(uint32_t n) {
        uint64_t sumOfSquares = 0, squareOfSum = 0;

        for (uint32_t i = 1; i <= n; i++) {
            sumOfSquares += i * i;
            squareOfSum += i;
        }
        squareOfSum *= squareOfSum;

        return squareOfSum - sumOfSquares;
    }
}