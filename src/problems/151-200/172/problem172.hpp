//
// Created by Alex Beccaro on 21/05/2023.
//

#ifndef PROJECT_EULER_PROBLEM172_HPP
#define PROJECT_EULER_PROBLEM172_HPP


#include "cstdint"

namespace problems {
    class problem172 {
    public:
        /**
         * Calculates how many numbers with given amount of digits there are such that no digit occurs more than three
         * times
         * @param digits The number of digits of numbers to consider
         * @return The count of the number with given amount of digits such that no digit occurs more than three times
         */
        static uint64_t solve(uint32_t digits = 18);
    };
}


#endif //PROJECT_EULER_PROBLEM172_HPP
