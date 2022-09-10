//
// Created by Alex Beccaro on 04/09/2022.
//

#ifndef PROJECT_EULER_PROBLEM155_HPP
#define PROJECT_EULER_PROBLEM155_HPP


#include <cstdint>

namespace problems {
    class problem155 {
    public:
        /**
         * Calculates the number of distinct total capacitance values we can obtain when using up to n equal-valued
         * capacitors
         * @param n The maximum number of capacitors used
         * @return The number of distinct total capacitance values
         */
        static uint32_t solve(uint32_t n = 18);
    };
}


#endif //PROJECT_EULER_PROBLEM155_HPP
