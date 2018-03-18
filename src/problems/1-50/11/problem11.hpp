//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM11_HPP
#define PROJECT_EULER_PROBLEM11_HPP

#include <cstdint>

namespace problems {
    class problem11 {
    public:
        /**
         * Solves problem
         * @param size The number of adjacent numbers to multiply
         * @return The solution
         */
        static uint32_t solve(uint32_t size = 4);
    };
}

#endif //PROJECT_EULER_PROBLEM11_HPP
