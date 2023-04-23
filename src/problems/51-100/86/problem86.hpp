//
// Created by Alex Beccaro on 25/02/18.
//

#ifndef PROJECT_EULER_PROBLEM86_HPP
#define PROJECT_EULER_PROBLEM86_HPP

#include "cstdint"

namespace problems {
    class problem86 {
    private:
        /**
         * Calculates the number of ways to choose two numbers x and y such that 1 <= x <= y <= m and x + y = sum
         * @param sum The sum of the numbers
         * @param m The maximum number valid
         * @return The number of x, y valid combinations
         */
        static uint32_t sum_combinations(uint32_t sum, uint32_t m);
    public:
        /**
         * Solves problem
         * @param n The number of integral solutions to find
         * @return The solution
         */
        static uint32_t solve(uint32_t n = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM86_HPP
