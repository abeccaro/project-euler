//
// Created by Alex Beccaro on 16/05/2023.
//

#ifndef PROJECT_EULER_PROBLEM170_HPP
#define PROJECT_EULER_PROBLEM170_HPP


#include "cstdint"

namespace problems {
    class problem170 {
    private:
        /**
         * Checks if the number formed by given digits is pandigital 0 to 9
         * @param digits The digits of the number
         * @return True if the number is pandigital 0 to 9, false otherwise
         */
        static bool is_pandigital(std::vector<uint32_t>& digits);

        /**
         * Splits in 2 given digits and returns the list of all pairs that can be obtained this way
         * @param number_digits The digits
         * @return The list of all couples of numbers obtained by splitting given number digits in 2
         */
        static std::vector<std::pair<uint32_t, uint32_t>> split(const std::vector<uint32_t>& number_digits);
    public:
        /**
         * Calculates the largest 0 to 9 pandigital 10-digit concatenated product of an integer with two or more other
         * integers, such that the concatenation of the input numbers is also a 0 to 9 pandigital 10-digit number
         * @return The calculated number
         */
        static uint64_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM170_HPP
