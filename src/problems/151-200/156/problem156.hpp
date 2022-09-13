//
// Created by Alex Beccaro on 12/09/2022.
//

#ifndef PROJECT_EULER_PROBLEM156_HPP
#define PROJECT_EULER_PROBLEM156_HPP


#include <cstdint>

namespace problems {
    class problem156 {
    private:
        /**
         * Counts the total number of digits d that are contained in numbers from 0 to n
         * @param n The last number to consider
         * @param d The digit to count
         * @return The total digit count
         */
        static uint64_t f(uint64_t n, uint64_t d);

        /**
         * Calculates the sum of all numbers n for which f(n,d) = n.
         * @param d The digit tou count
         * @return The sum of numbers n that satisfy f(n,d) = n
         */
        static uint64_t s(uint64_t d);

    public:
        /**
         * Calculates the sum of s(d) for 1 <= d <= 9
         * @return The sum
         */
        static uint64_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM156_HPP
