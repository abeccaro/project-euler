//
// Created by Alex Beccaro on 21/01/18.
//

#ifndef PROJECT_EULER_PROBLEM57_HPP
#define PROJECT_EULER_PROBLEM57_HPP

#include "cstdint"

namespace problems {
    class problem57 {
    public:
        /**
         * Solves problem
         * @param convergents The number of convergent to test
         * @return The solution
         */
        static uint32_t solve(uint32_t convergents = 1000);
    };
}


#endif //PROJECT_EULER_PROBLEM57_HPP
