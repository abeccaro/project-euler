//
// Created by Alex Beccaro on 12/12/17.
//

#include "problem10.hpp"
#include <primes.hpp>

namespace problems {
    ulong problem10::solve(uint ub) {
        std::vector<uint> p = primes::primes_up_to(ub);

        ulong sum = 0;
        for (const auto& prime : p)
            sum += prime;
        return sum;
    }
}