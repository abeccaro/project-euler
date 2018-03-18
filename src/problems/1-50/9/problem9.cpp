//
// Created by Alex Beccaro on 12/12/17.
//

#include "problem9.hpp"

namespace problems {
    uint32_t problem9::solve(uint32_t sum) {
        for (uint32_t a = 1; a <= sum / 3; a++)
            for (uint32_t b = a + 1; b < sum / 2; b++) {
                uint32_t c = sum - a - b;
                if (a * a + b * b == c * c)
                    return a * b * c;
            }
        return 0;
    }
}