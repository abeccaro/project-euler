//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM52_HPP
#define PROJECT_EULER_PROBLEM52_HPP

#include "cstdint"

namespace problems {
    class problem52 {
    public:
        /**
         * Solves problem
         * @param multiples The number of consecutive multiples with same digits
         * @return The solution
         */
        static uint32_t solve(uint32_t multiples = 6);
    };
}


#endif //PROJECT_EULER_PROBLEM52_HPP
