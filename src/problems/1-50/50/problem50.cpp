//
// Created by Alex Beccaro on 08/01/18.
//

#include "problem50.hpp"
#include <primes.hpp>
#include <series/primes.hpp>

using primes::is_prime;
using series::primes;

namespace problems {
    uint32_t problem50::solve(uint32_t ub) {
        primes<uint32_t> p;
        uint32_t result = 0;
        uint32_t max_n_primes = 0, max_sum = 0;

        for (auto i = p.begin(); result == 0; i++) {
            uint64_t sum = *i;
            uint32_t n_primes = 1;

            for (auto j = i + 1; sum + *j < ub; j++) {
                sum += *j;
                n_primes++;

                if (n_primes > max_n_primes && is_prime(sum)) {
                    max_sum = sum;
                    max_n_primes = n_primes;
                }
            }

            if (n_primes < max_n_primes) {
                result = max_sum;
                break;
            }

            if (is_prime(sum)) {
                max_n_primes = n_primes;
                result = sum;
            }
        }

        return result;
    }
}