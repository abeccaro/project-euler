//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM33_HPP
#define PROJECT_EULER_PROBLEM33_HPP

#include <cstdint>

namespace problems {
    class problem33 {
    private:
        /**
         * Checks if given fraction (n/d) is digit cancelling. Both n and d are supposed to have 2 digits.
         * @param n The numerator
         * @param d The denominator
         * @return true if fraction is digit cancelling, false otherwise
         */
        static bool is_digit_cancelling(uint32_t n, uint32_t d);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM33_HPP
