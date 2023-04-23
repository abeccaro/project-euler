//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM17_HPP
#define PROJECT_EULER_PROBLEM17_HPP

#include "cstdint"

namespace problems {
    class problem17 {
    private:
        /**
         * Calculates the number of letters used for a given number up to 1000.
         * @param n The number
         * @return The number of letters
         */
        static uint32_t letters(uint32_t n);
    public:
        /**
         * Solves problem
         * @param ub The upper bound of numbers to consider
         * @return The solution
         */
        static uint32_t solve(uint32_t ub = 1000);
    };
}


#endif //PROJECT_EULER_PROBLEM17_HPP
