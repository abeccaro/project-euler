//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM26_HPP
#define PROJECT_EULER_PROBLEM26_HPP

#include "cstdint"

namespace problems {
    class problem26 {
    public:
        /**
         * Solves problem
         * @param ub The maximum denominator to check
         * @return The solution
         */
        static uint32_t solve(uint32_t ub = 1000);
    };
}


#endif //PROJECT_EULER_PROBLEM26_HPP
