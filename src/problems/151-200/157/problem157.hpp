//
// Created by Alex Beccaro on 13/09/2022.
//

#ifndef PROJECT_EULER_PROBLEM157_HPP
#define PROJECT_EULER_PROBLEM157_HPP


#include "cstdint"

namespace problems {
    class problem157 {
    public:
        /**
         * Calculates the number of combinations of a, b, p, n that solve the diophantine equation 1/a + 1/b = p/(10^n)
         * for n up to given number
         * @param n_max The maximum exponent for the power of ten
         * @return The number of solutions
         */
        static uint32_t solve(uint32_t n_max = 9);
    };
}


#endif //PROJECT_EULER_PROBLEM157_HPP
