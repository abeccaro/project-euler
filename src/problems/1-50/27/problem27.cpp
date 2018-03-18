//
// Created by Alex Beccaro on 18/12/17.
//

#include "problem27.hpp"
#include <series/primes.hpp>
#include <primes.hpp>
#include <iostream>

using std::vector;
using primes::is_prime;
using series::primes;

namespace problems {
    int32_t problem27::solve(uint32_t ub_a, uint32_t ub_b) {
        primes<uint32_t> p;
        vector<uint32_t> ps = p.get_while([ub_b](uint32_t n) { return n <= ub_b; });
        uint32_t max_primes = 0;
        int32_t max_a, max_b, signed_ub_a = (int32_t) ub_a;

        for (int32_t a = -signed_ub_a + 1; a < signed_ub_a; a++)
            for (const auto &b : ps) {
                uint32_t count = 1;

                for (int32_t n = 1; is_prime(n * n + a * n + b); n++)
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