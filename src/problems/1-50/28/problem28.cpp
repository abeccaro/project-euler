//
// Created by Alex Beccaro on 18/12/17.
//

#include "problem28.hpp"

namespace problems {
    uint32_t problem28::solve(uint32_t size) {
        uint32_t result = 1;
        for (uint32_t i = 3; i <= size; i += 2)
            for (uint32_t j = 0; j < 4; j++) // for each diagonal starting from top-right anticlockwise
                result += i * i - j * (i - 1);
        return result;
    }
}