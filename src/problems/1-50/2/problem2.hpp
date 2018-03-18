//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM2_HPP
#define PROJECT_EULER_PROBLEM2_HPP

#include <cstdint>

namespace problems {

    class problem2 {
    public:
        /**
         * Solves problem
         * @param ub The upper bound
         * @return The solution
         */
        static uint32_t solve(uint32_t ub = 4000000);
    };
}

#endif //PROJECT_EULER_PROBLEM2_HPP
