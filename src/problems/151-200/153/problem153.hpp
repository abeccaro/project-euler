//
// Created by Alex Beccaro on 27/08/2022.
//

#ifndef PROJECT_EULER_PROBLEM153_HPP
#define PROJECT_EULER_PROBLEM153_HPP


#include <cstdint>

namespace problems {
    class problem153 {
    public:
        /**
         * Calculates the sum of the number of complex divisors for numbers from 1 to given upper bound
         * @param ub The upper bound for integers to use
         * @return The sum of the number of complex divisors
         */
        static uint64_t solve(uint64_t ub = 100000000);
    };
}


#endif //PROJECT_EULER_PROBLEM153_HPP
