//
// Created by Alex Beccaro on 09/01/18.
//

#include "problem58.hpp"
#include "primes.hpp"

using primes::is_prime;

namespace problems {
    uint32_t problem58::solve(double treshold) {
        uint64_t last = 1;
        for (uint32_t side = 3, primes = 0; true; side += 2) {
            uint32_t increment = side - 1;
            uint64_t n1 = last + increment;
            uint64_t n2 = n1 + increment;
            uint64_t n3 = n2 + increment;
            last = n3 + increment;

            if (is_prime(n1))
                primes++;
            if (is_prime(n2))
                primes++;
            if (is_prime(n3))
                primes++;

            if (100 * primes / (2 * side - 1) < treshold)
                return side;
        }
    }
}