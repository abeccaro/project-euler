//
// Created by Alex Beccaro on 07/01/2019.
//

#ifndef PROJECT_EULER_PROBLEM115_HPP
#define PROJECT_EULER_PROBLEM115_HPP

#include "cstdint"
#include "vector"

namespace problems {
    class problem115 {
    private:
        /**
         * Calculates the number of ways a row of length 'l' can be filled following problem rules.
         * The smaller problems result is a vector of at least l elements, where each one is the number of
         * ways to fill a rule of length equal to index, starting from 0.
         *
         * @param l The length of the row
         * @param m The minimum size of the blocks
         * @param mem The values for results of smaller problems
         * @return The number of ways to fill a row of length 'l'
         */
        static uint64_t fill_combinations(uint32_t l, uint32_t m, const std::vector<uint64_t>& mem);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint64_t solve(uint32_t size = 50, uint64_t ub = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM115_HPP
