//
// Created by Alex Beccaro on 08/01/18.
//

#include "problem50.hpp"
#include <primes.hpp>
#include <series/primes.hpp>

using primes::is_prime;
using series::primes;

using ulong = unsigned long;

namespace problems {
    uint problem50::solve(uint ub) {
        primes<uint> p;
        uint result = 0;
        uint max_n_primes = 0, max_sum = 0;

        for (auto i = p.begin(); result == 0; i++) {
            ulong sum = *i;
            uint n_primes = 1;

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