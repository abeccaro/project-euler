//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM4_HPP
#define PROJECT_EULER_PROBLEM4_HPP

#include "cstdint"

namespace problems {

    class problem4 {
    public:
        /**
         * Solves problem
         * @param digits The number of digits of factors
         * @return The solution
         */
        static uint32_t solve(uint32_t digits = 3);
    };
}

#endif //PROJECT_EULER_PROBLEM4_HPP
