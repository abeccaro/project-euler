//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM36_HPP
#define PROJECT_EULER_PROBLEM36_HPP

#include <cstdint>

namespace problems {
    class problem36 {
    public:
        /**
         * Solves problem
         * @param ub The upper bound of numbers to check
         * @return The solution
         */
        static uint32_t solve(uint32_t ub = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM36_HPP
