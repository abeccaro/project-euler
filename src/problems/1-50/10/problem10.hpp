//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM10_HPP
#define PROJECT_EULER_PROBLEM10_HPP

#include "cstdint"

namespace problems {
    class problem10 {
    public:
        /**
         * Solves problem
         * @param ub The upper bound of primes to sum
         * @return The solution
         */
        static uint64_t solve(uint32_t ub = 2000000);
    };
}

#endif //PROJECT_EULER_PROBLEM10_HPP
