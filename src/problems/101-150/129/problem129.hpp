//
// Created by Alex Beccaro on 23/11/2019.
//

#ifndef PROJECT_EULER_PROBLEM129_HPP
#define PROJECT_EULER_PROBLEM129_HPP

#include "cstdint"

namespace problems {
    class problem129 {
    public:
        /**
         * Solves problem. Assuming gcd(n, 10) = 1
         * @return The solution
         */
        static uint32_t solve(uint32_t n = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM129_HPP
