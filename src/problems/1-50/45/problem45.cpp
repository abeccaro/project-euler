//
// Created by Alex Beccaro on 07/01/18.
//

#include "problem45.hpp"
#include "series/figurate_number.hpp"

using series::figurate_number;

namespace problems {
    bool problem45::is_pentagonal(uint64_t n) {
        auto x = (sqrt(24 * n + 1) + 1) / 6;

        return (uint64_t) x == x;
    }

    uint64_t problem45::solve(uint32_t n) {
        figurate_number<uint64_t> hexagonals(6);
        uint64_t result;

        for (auto i = hexagonals.begin(); i < hexagonals.end(); i++)
            if (is_pentagonal(*i)) { // all hexagonal numbers are also triangular numbers
                if (n <= 1) {
                    result = *i;
                    break;
                } else
                    n--;
            }

        return result;
    }
}