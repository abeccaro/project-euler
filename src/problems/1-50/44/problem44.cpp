/*
 * Created by Alex Beccaro on 07/01/18.
 *
 * N.B.: This algorithm was obtained with the help of a problem forum comment (https://projecteuler.net/thread=44#3218).
 * The previous version didn't check that found solution was actually correct but assumed it.
 */

#include "problem44.hpp"
#include <series/figurate_number.hpp>

using series::figurate_number;

namespace problems {
    bool problem44::is_pentagonal(uint n) {
        auto x = (sqrt(24 * n + 1) + 1) / 6;

        return (uint) x == x;
    }

    bool problem44::is_double_pentagonal(uint n) {
        if (n % 2 != 0)
            return false;

        return is_pentagonal(n / 2);
    }

    uint problem44::solve() {
        figurate_number<uint> p(5);
        uint result = 0;

        for (uint m = 1; result == 0; m++)
            for (uint k = 0; k < m; k++)
                if (is_double_pentagonal(p[m] + p[k]) && is_double_pentagonal(p[m] - p[k])) {
                    result = p[k];
                    break;
                }

        return result;
    }
}