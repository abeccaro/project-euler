//
// Created by Alex Beccaro on 19/03/2025.
//

#ifndef PROJECT_EULER_PROBLEM176_HPP
#define PROJECT_EULER_PROBLEM176_HPP


#include "cstdint"
#include "series/primes.hpp"

namespace problems {
    class problem176 {
    public:
        /**
         * Finds the smallest integer that can be the length of a cathetus of exactly n different integer sided
         * right-angled triangles
         * @param n The number of triangles
         * @return The smallest length of a cathetus
         */
        static uint64_t solve(uint64_t n = 47547);
    };
}


#endif //PROJECT_EULER_PROBLEM176_HPP
