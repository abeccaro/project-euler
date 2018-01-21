//
// Created by Alex Beccaro on 19/12/17.
//

#include "problem35.hpp"
#include <generics.hpp>
#include <primes.hpp>

using generics::rotations;
using primes::is_prime;
using primes::primes_up_to;

namespace problems {
    uint problem35::solve(uint ub) {
        vector<ulong> primes = primes_up_to((ulong) ub-1);

        uint result = 0;
        for (const auto &prime : primes) {
            vector<ulong> rots = rotations(prime);

            if (all_of(rots.begin() + 1, rots.end(), [](ulong n) { return is_prime(n); }))
                result++;
        }
        return result;
    }
}