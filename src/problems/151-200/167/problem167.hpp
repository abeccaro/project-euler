//
// Created by Alex Beccaro on 02/05/2023.
//

#ifndef PROJECT_EULER_PROBLEM167_HPP
#define PROJECT_EULER_PROBLEM167_HPP


#include "cstdint"
#include "utility"

namespace problems {
    class problem167 {
    private:
        /**
         * Calculates the period length and total difference for the sequence U(2, v) with v odd >= 5
         * @param v The second number in the sequence
         * @return The length and total difference of the period
         */
        static std::pair<uint64_t, uint64_t> find_period(uint64_t v);

        /**
         * Calculates the k-th term of the sequence U(2, v) with v odd >= 5
         * @param v The second number in the sequence
         * @param k The index of the requested number (starting from 1)
         * @return The k-th number of U(2, v)
         */
        static uint64_t ulam2(uint64_t v, uint64_t k);
    public:
        /**
         * Calculates the sum of U(2, 2a+1)_(10^11) for 2 <= a <= n
         * @param n The upper bound for Ulam sequences
         * @return The sum of the 10^11-th terms of considered Ulam sequences
         */
        static uint64_t solve(uint32_t n = 10, uint64_t k = 100000000000);
    };
}


#endif //PROJECT_EULER_PROBLEM167_HPP
