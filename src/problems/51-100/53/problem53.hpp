//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM53_HPP
#define PROJECT_EULER_PROBLEM53_HPP

#include "cstdint"

namespace problems {
    class problem53 {
    public:
        /**
         * Solves problem
         * @param max_n The maximum n in "n choose r" calculations
         * @return The solution
         */
        static uint32_t solve(uint32_t max_n = 100, uint32_t threshold = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM53_HPP
