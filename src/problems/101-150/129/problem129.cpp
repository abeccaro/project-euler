//
// Created by Alex Beccaro on 23/11/2019.
//

#include "problem129.hpp"


namespace problems {

    uint32_t problem129::solve(uint32_t n) {
        for (uint32_t x = n; ; x++) {
            if (x % 2 == 0 || x % 5 == 0)
                continue;

            uint64_t rk = 11 % x;
            for (uint32_t k = 2; ; k++, rk = (rk * 10 + 1) % x) {
                if (rk == 0) {
                    if (k > n)
                        return x;
                    else
                        break;
                }
            }
        }
    }

}