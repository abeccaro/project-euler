//
// Created by Alex Beccaro on 24/11/2019.
//

#include "problem131.hpp"
#include "primes.hpp"


using primes::is_prime;


namespace problems {

    uint32_t problem131::solve(uint32_t ub) {
        uint32_t count = 0;

        for (uint64_t a = 1; ; a++) {
            uint64_t p = 3 * a * a + 3 * a + 1;
            if (p > ub)
                break;
            if (is_prime(p))
                count++;
        }

        return count;
    }

}