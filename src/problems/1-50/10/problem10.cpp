//
// Created by Alex Beccaro on 12/12/17.
//

#include "problem10.hpp"
#include <primes.hpp>

namespace problems {
    /**
     * Specifies values, solves problem and outputs solution and calculation time.
     * @return The exit code
     */
    ulong problem10::solve(uint ub) {
        vector<uint> p = primes::primes_up_to(ub);

        ulong sum = 0;
        for (const auto& prime : p)
            sum += prime;
        return sum;
    }
}