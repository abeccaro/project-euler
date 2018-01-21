//
// Created by Alex Beccaro on 12/12/17.
//

#include "problem6.hpp"

namespace problems {
    ulong problem6::solve(ulong n) {
        ulong sumOfSquares = 0, squareOfSum = 0;

        for (ulong i = 1; i <= n; i++) {
            sumOfSquares += i * i;
            squareOfSum += i;
        }
        squareOfSum *= squareOfSum;

        return squareOfSum - sumOfSquares;
    }
}