//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM56_HPP
#define PROJECT_EULER_PROBLEM56_HPP

#include "cstdint"

namespace problems {
    class problem56 {
    public:
        /**
         * Solves problem
         * @param base_ub The upper bound for bases to consider
         * @param exp_ub The upper bound for exponents to consider
         * @return The solution
         */
        static uint32_t solve(uint32_t base_ub = 100, uint32_t exp_ub = 100);
    };
}


#endif //PROJECT_EULER_PROBLEM56_HPP
