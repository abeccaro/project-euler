//
// Created by Alex Beccaro on 13/03/18.
//

#include "problem100.hpp"

namespace problems {
    uint64_t problem100::solve(uint64_t lb) {
        uint64_t a = 1;
        uint64_t b = 1; // total number of discs
        uint64_t x = 1; // number of blue discs

        while (b <= lb) {
            uint64_t new_a = 3 * a + 4 * b - 2;
            b = 2 * a + 3 * b - 1;
            a = new_a;
            x = (a + 1) / 2;
        }

        return x;
    }
}