//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM9_HPP
#define PROJECT_EULER_PROBLEM9_HPP

#include <cstdint>

namespace problems {
    class problem9 {
    public:
        /**
         * Solves problem
         * @param sum The sum of pythagorean triplet
         * @return The solution
         */
        static uint32_t solve(uint32_t sum = 1000);
    };
}

#endif //PROJECT_EULER_PROBLEM9_HPP
