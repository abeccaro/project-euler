//
// Created by Alex Beccaro on 12/12/17.
//

#include "problem10.hpp"
#include <primes.hpp>

using std::vector;
using primes::primes_up_to;

namespace problems {
    uint64_t problem10::solve(uint32_t ub) {
        vector<uint32_t> p = primes_up_to(ub);

        uint64_t sum = 0;
        for (const auto& prime : p)
            sum += prime;
        return sum;
    }
}