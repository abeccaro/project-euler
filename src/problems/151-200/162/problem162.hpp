//
// Created by Alex Beccaro on 24/04/2023.
//

#ifndef PROJECT_EULER_problem162_HPP
#define PROJECT_EULER_problem162_HPP


#include "cstdint"
#include "vector"

namespace problems {
    class problem162 {
    private:
        /**
         * Counts how many numbers of n digits specify the requisites
         * @param n The length of the number in digits
         * @return The number of solutions of length n
         */
        static uint64_t count(uint64_t n);

        /**
         * Converts given number to its hexadecimal representation
         * @param n The number to convert
         * @return The hexadecimal representation of given number
         */
        static std::string to_hexadecimal_string(uint64_t n);
    public:
        /**
         * Calculates How many hexadecimal numbers containing at most n hexadecimal digits exist with all of the digits
         * 0,1, and A present at least once. The answer is returned in hexadecimal form.
         * @param n The maximum number of digits of numbers to consider
         * @return The number of hexadecimal numbers requested as hexadecimal number
         */
        static std::string solve(uint32_t n = 16);
    };
}


#endif //PROJECT_EULER_problem162_HPP
