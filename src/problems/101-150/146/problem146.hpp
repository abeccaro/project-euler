//
// Created by Alex Beccaro on 20/01/2020.
//

#ifndef PROJECT_EULER_PROBLEM146_HPP
#define PROJECT_EULER_PROBLEM146_HPP

#include "cstdint"
#include "vector"

namespace problems {
    class problem146 {
    private:
        static const std::vector<uint64_t> first_primes;

        /**
         * Checks quickly if given number n is a candidate to problem conditions. This helps reducing the numbers to actually
         * prime check using complex (slower) algorithms
         * @param n: The number to check
         * @return true if n is a valid candidate, false if a fast check fails
         */
        static bool is_candidate(uint64_t n);

    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint64_t solve(uint64_t ub = 150000000);
    };
}


#endif //PROJECT_EULER_PROBLEM146_HPP
