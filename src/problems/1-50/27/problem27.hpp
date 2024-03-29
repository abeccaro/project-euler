//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM27_HPP
#define PROJECT_EULER_PROBLEM27_HPP

#include "cstdint"

namespace problems {
    class problem27 {
    public:
        /**
         * Solves problem
         * @param ub_a The maximum abs value of a
         * @param ub_b The maximum abs value of b
         * @return The solution
         */
        static int solve(uint32_t ub_a = 1000, uint32_t ub_b = 1000);
    };
}


#endif //PROJECT_EULER_PROBLEM27_HPP
