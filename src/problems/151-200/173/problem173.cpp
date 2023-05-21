//
// Created by Alex Beccaro on 21/05/2023.
//

#include "problem173.hpp"


namespace problems {
    uint64_t problem173::solve(uint32_t max_tiles) {
        uint64_t result = 0;

        for (uint64_t i = 1, j = max_tiles / (4 * i); j > i; i++, j = max_tiles / (4 * i))
            result += j - i;

        return result;
    }
}