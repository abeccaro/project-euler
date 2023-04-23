//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM50_HPP
#define PROJECT_EULER_PROBLEM50_HPP

#include "cstdint"

namespace problems {
    class problem50 {
    public:
        /**
         * Solves problem
         * @param ub The upper bound for primes to consider
         * @return The solution
         */
        static uint32_t solve(uint32_t ub = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM50_HPP
