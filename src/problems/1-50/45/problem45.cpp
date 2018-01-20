//
// Created by Alex Beccaro on 07/01/18.
//

#include "problem45.hpp"
#include <series/figurate_number.hpp>

using series::figurate_number;

namespace problems {
    bool problem45::is_pentagonal(ulong n) {
        auto x = (sqrt(24 * n + 1) + 1) / 6;

        return (ulong) x == x;
    }

    ulong problem45::solve(uint n) {
        figurate_number<ulong> hexagonals(6);
        ulong result;

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