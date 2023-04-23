//
// Created by Alex Beccaro on 21/01/18.
//

#ifndef PROJECT_EULER_PROBLEM70_HPP
#define PROJECT_EULER_PROBLEM70_HPP

#include "cstdint"
#include "vector"

namespace problems {
    class problem70 {
    public:
        /**
         * Solves problem
         * @param ub The upper bound for numbers to consider
         * @return The solution
         */
        static uint32_t solve(uint32_t ub = 10000000);
    };
}


#endif //PROJECT_EULER_PROBLEM70_HPP
