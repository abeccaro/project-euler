//
// Created by Alex Beccaro on 18/12/17.
//

#include "problem28.hpp"

namespace problems {
    uint problem28::solve(uint size) {
        uint result = 1;
        for (uint i = 3; i <= size; i += 2)
            for (uint j = 0; j < 4; j++) // for each diagonal starting from top-right anticlockwise
                result += i * i - j * (i - 1);
        return result;
    }
}