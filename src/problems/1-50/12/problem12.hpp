//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM12_HPP
#define PROJECT_EULER_PROBLEM12_HPP

#include "cstdint"

namespace problems {
    class problem12 {
    public:
        /**
         * Solves problem
         * @param divs The number of requested divisors
         * @return The solution
         */
        static uint32_t solve(uint32_t divs = 500);
    };
}

#endif //PROJECT_EULER_PROBLEM12_HPP
