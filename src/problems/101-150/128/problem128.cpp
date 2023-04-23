//
// Created by Alex Beccaro on 23/11/2019.
//

#include "problem128.hpp"
#include "primes.hpp"


using primes::is_prime;


namespace problems {

    uint64_t problem128::solve(uint32_t n) {
        if (n <= 2)
            return n;

        uint32_t count = 2;
        uint64_t x = 2;
        for (uint64_t i = 8; count < n; i += 6 * x, x++) {
            // check difference between first and last tile of xth ring
            if (!is_prime(6 * x - 1))
                continue;

            // first tile of the xth ring
            // first check is for tile on top-left, second for tile on top-right
            if (is_prime(6 * x + 1) && is_prime(6 * (2 * x + 1) - 1)) {
                count++;
                if (count == n)
                    return i;
            }

            // last tile of the xth ring
            // first check is for tile on top-right, second for tile on bottom-left
            if (is_prime(6 * (x + 1) - 1) && is_prime(6 * (2 * x - 1) - 1)) {
                count++;
                if (count == n)
                    return i + 6 * x - 1;
            }
        }
    }

}