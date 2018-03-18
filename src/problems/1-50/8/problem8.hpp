//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM8_HPP
#define PROJECT_EULER_PROBLEM8_HPP

#include <cstdint>

namespace problems {
    class problem8 {
    public:
        /**
         * Solves problem
         * @param digits The number of adjacent digits to sum
         * @return The solution
         */
        static uint64_t solve(uint32_t digits = 13);
    };
}

#endif //PROJECT_EULER_PROBLEM8_HPP
