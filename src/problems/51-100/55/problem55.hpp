//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM55_HPP
#define PROJECT_EULER_PROBLEM55_HPP

#include <cstdint>

namespace problems {
    class problem55 {
    public:
        /**
         * Solves problem
         * @param ub The upper bound of numbers to check
         * @param iterations The number of iterations after which a number is considered a Lychrel number
         * @return The solution
         */
        static uint32_t solve(uint32_t ub = 10000, uint32_t iterations = 50);
    };
}


#endif //PROJECT_EULER_PROBLEM55_HPP
