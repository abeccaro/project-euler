//
// Created by Alex Beccaro on 17/09/2022.
//

#ifndef PROJECT_EULER_PROBLEM159_HPP
#define PROJECT_EULER_PROBLEM159_HPP


#include "cstdint"

namespace problems {
    class problem159 {
    public:
        /**
         * Calculates the sum of the maximum digital root sum on numbers up to ub excluded
         * @param ub The upper bounds for numbers to consider
         * @return The sum of the maximum digital root sum
         */
        static uint64_t solve(uint64_t ub = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM159_HPP
