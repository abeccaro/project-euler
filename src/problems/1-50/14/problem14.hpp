//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM14_HPP
#define PROJECT_EULER_PROBLEM14_HPP

#include "cstdint"
#include "vector"

namespace problems {
    class problem14 {
    private:
        /**
         * Finds the length of the Collatz chain starting from n. It uses a vector for memoization.
         * @param n The starting number
         * @param memory The vector with already calculated lengths
         * @return The length of the chain
         */
        static uint32_t collatz_length(uint32_t n, std::vector<uint32_t>& memory);
    public:
        /**
         * Solves problem
         * @param ub The upper bound of starting numbers to check
         * @return The solution
         */
        static uint32_t solve(uint32_t ub = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM14_HPP
