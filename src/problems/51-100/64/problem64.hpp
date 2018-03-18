//
// Created by Alex Beccaro on 21/01/18.
//

#ifndef PROJECT_EULER_PROBLEM64_HPP
#define PROJECT_EULER_PROBLEM64_HPP

#include <cstdint>

namespace problems {
    class problem64 {
    public:
        /**
         * Solves problem
         * @param ub The upper bound for numbers to check
         * @return The solution
         */
        static uint32_t solve(uint32_t ub = 10000);
    };
}


#endif //PROJECT_EULER_PROBLEM64_HPP
