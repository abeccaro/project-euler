//
// Created by Alex Beccaro on 17/09/2022.
//

#ifndef PROJECT_EULER_PROBLEM159_HPP
#define PROJECT_EULER_PROBLEM159_HPP


#include <cstdint>
#include <vector>

namespace problems {
    class problem159 {
    private:
        /**
         * Divisors cache from 2 to ub - 1
         */
        static std::vector<std::vector<uint64_t>> divisors;

        /**
         * Maximum digital root sum cache from 2 to ub - 1
         */
        static std::vector<uint64_t> mdrs;

        /**
         * Calculates the maximum digital root sum for n.
         * Assumes that mdrs is correct for all proper divisors of n (!= 1).
         * @param n The number to calculate the mdrs of
         * @return The maximum digital root sum for n
         */
        static uint64_t calculate_mdrs(uint64_t n);

    public:
        /**
         * Calculates the sum of the maximum digital root sum on numbers up to ub excluded
         * @param ub The upper bounds for numbers to consider
         * @return The sum of the maximum digital root sum
         */
        static uint64_t solve(uint64_t ub = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM159_HPP
