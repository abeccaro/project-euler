//
// Created by Alex Beccaro on 17/05/2023.
//

#ifndef PROJECT_EULER_PROBLEM171_HPP
#define PROJECT_EULER_PROBLEM171_HPP


#include "cstdint"
#include "map"
#include "vector"

namespace problems {
    class problem171 {
    private:
        /**
         * Vector of squares from 0 to maximum obtainable sum
         */
        static std::vector<uint32_t> squares;

        /**
         * Vector of powers of 10 up to 10^9
         */
         static std::vector<uint64_t> powers_ten;

         /**
          * Map of results for function numbers_sum
          */
         static std::map<std::pair<uint32_t, uint32_t>, std::pair<uint32_t, uint64_t>> mem;

         /**
          * Counts and sums all numbers with up to given number of digits such that the sum of the squares of their
          * digits adds to given sum. The resulting sum is stored mod 10^9.
          * @param sum The target sum for the squares of the digits
          * @param digits The maximum number of digits the numbers can have
          * @return The pair (count, sum) for all numbers with the requested property
          */
         static std::pair<uint32_t, uint64_t> numbers_sum(uint32_t sum, uint32_t digits);
    public:
        /**
         * Calculates the last nine digits of the sum of all n, 0 < n < 10^digits, such that the sum of the squares of
         * their digits is a perfect square.
         * @param digits The maximum number of digits to consider
         * @return The sum of requested numbers mod 10^9
         */
        static uint64_t solve(uint32_t digits = 20);
    };
}


#endif //PROJECT_EULER_PROBLEM171_HPP
