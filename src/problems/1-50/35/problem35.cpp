//
// Created by Alex Beccaro on 19/12/17.
//

#include "problem35.hpp"
#include <generics.hpp>
#include <primes.hpp>

using std::vector;
using generics::rotations;
using primes::is_prime;
using primes::primes_up_to;

namespace problems {
    uint32_t problem35::solve(uint32_t ub) {
        vector<uint64_t> primes = primes_up_to<uint64_t>(ub - 1);

        uint32_t result = 0;
        for (const auto &prime : primes) {
            vector<uint64_t> rots = rotations(prime);

            if (all_of(rots.begin() + 1, rots.end(), [](uint64_t n) { return is_prime(n); }))
                result++;
        }
        return result;
    }
}