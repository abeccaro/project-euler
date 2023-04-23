//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM48_HPP
#define PROJECT_EULER_PROBLEM48_HPP

#include "cstdint"
#include "vector"

namespace problems {
    class problem48 {
    public:
        /**
         * Solves problem
         * @param ub The upper bound of numbers
         * @return The solution
         */
        static std::vector<uint32_t> solve(uint32_t ub = 1000);
    };
}


#endif //PROJECT_EULER_PROBLEM48_HPP
