//
// Created by Alex Beccaro on 07/01/18.
//

#include "problem44.hpp"
#include "series/figurate_number.hpp"

using series::figurate_number;

namespace problems {
    bool problem44::is_pentagonal(uint32_t n) {
        auto x = (sqrt(24 * n + 1) + 1) / 6;

        return (uint32_t) x == x;
    }

    bool problem44::is_double_pentagonal(uint32_t n) {
        if (n % 2 != 0)
            return false;

        return is_pentagonal(n / 2);
    }

    uint32_t problem44::solve() {
        figurate_number<uint32_t> p(5);
        uint32_t result = 0;

        for (uint32_t m = 1; result == 0; m++)
            for (uint32_t k = 0; k < m; k++)
                if (is_double_pentagonal(p[m] + p[k]) && is_double_pentagonal(p[m] - p[k])) {
                    result = p[k];
                    break;
                }

        return result;
    }
}