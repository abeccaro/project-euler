//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM5_HPP
#define PROJECT_EULER_PROBLEM5_HPP

#include "cstdint"

namespace problems {

    class problem5 {
    public:
        /**
         * Solves problem
         * @param max_divisor The highest divisor of requested number
         * @return The solution
         */
        static uint64_t solve(uint32_t max_divisor = 20);
    };
}

#endif //PROJECT_EULER_PROBLEM5_HPP
