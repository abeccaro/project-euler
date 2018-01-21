//
// Created by Alex Beccaro on 12/12/17.
//

#include "problem9.hpp"

namespace problems {
    uint problem9::solve(uint sum) {
        for (uint a = 1; a <= sum / 3; a++)
            for (uint b = a + 1; b < sum / 2; b++) {
                uint c = sum - a - b;
                if (a * a + b * b == c * c)
                    return a * b * c;
            }
        return 0;
    }
}