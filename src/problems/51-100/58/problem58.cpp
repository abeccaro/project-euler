//
// Created by Alex Beccaro on 09/01/18.
//

#include "problem58.hpp"
#include <primes.hpp>

using primes::is_prime;

using ulong = unsigned long;

namespace problems {
    uint problem58::solve(double treshold) {
        ulong last = 1;
        for (uint side = 3, primes = 0; true; side += 2) {
            uint increment = side - 1;
            ulong n1 = last + increment;
            ulong n2 = n1 + increment;
            ulong n3 = n2 + increment;
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