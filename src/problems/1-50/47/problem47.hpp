//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM47_HPP
#define PROJECT_EULER_PROBLEM47_HPP

#include <cstdint>

namespace problems {
    class problem47 {
    public:
        /**
         * Solves problem
         * @param n The number of consecutive numbers
         * @param factors The number of distinct prime factors
         * @return The solution
         */
        static uint32_t solve(uint32_t n = 4, uint32_t factors = 4);
    };
}


#endif //PROJECT_EULER_PROBLEM47_HPP
