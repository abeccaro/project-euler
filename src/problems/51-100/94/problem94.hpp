//
// Created by Alex Beccaro on 02/03/18.
//

#ifndef PROJECT_EULER_PROBLEM94_HPP
#define PROJECT_EULER_PROBLEM94_HPP

#include <cstdint>

namespace problems {
    class problem94 {
    public:
        /**
         * Solves problem
         * @param ub The upper bound for triangles perimeter
         * @return The solution
         */
        static uint32_t solve(uint32_t ub = 1000000000);
    };
}


#endif //PROJECT_EULER_PROBLEM94_HPP
