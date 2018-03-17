//
// Created by Alex Beccaro on 18/12/17.
//

#include "problem27.hpp"
#include <series/primes.hpp>
#include <primes.hpp>
#include <iostream>

using primes::is_prime;
using series::primes;

namespace problems {
    int problem27::solve(uint ub_a, uint ub_b) {
        primes<uint> p;
        std::vector<uint> ps = p.get_while([ub_b](uint n) { return n <= ub_b; });
        uint max_primes = 0;
        int max_a, max_b;

        for (long a = -(long) ub_a + 1; a < ub_a; a++)
            for (const auto &b : ps) {
                uint count = 0;

                for (int n = 0; is_prime(n * n + a * n + b); n++)
                    count++;

                if (count > max_primes) {
                    max_primes = count;
                    max_a = a;
                    max_b = b;
                }
            }

        return max_a * max_b;
    }
}