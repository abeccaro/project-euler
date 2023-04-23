//
// Created by Alex Beccaro on 24/11/2019.
//

#include "problem130.hpp"
#include "primes.hpp"


using primes::is_prime;


namespace problems {

    uint32_t problem130::solve(uint32_t n) {
        uint32_t found = 0, res = 0;

        for (uint32_t x = 7; found < n; x++) {
            if (x % 2 == 0 || x % 5 == 0 || is_prime(x))
                continue;

            uint64_t rk = 11 % x;
            for (uint32_t k = 2; ; k++, rk = (rk * 10 + 1) % x) {
                if (rk == 0) {
                    if ((x - 1) % k == 0) {
                        found++;
                        res += x;
                    }
                    break;
                }
            }
        }

        return res;
    }

}