//
// Created by Alex Beccaro on 22/01/18.
//

#ifndef PROJECT_EULER_PROBLEM74_HPP
#define PROJECT_EULER_PROBLEM74_HPP

#include <vector>

namespace problems {
    class problem74 {
    private:
        /**
         * Calculates the length of the chain starting from n using memoization
         * @param n The starting number
         * @param memory The memory of already computed chain lengths
         * @param factorials Pre-calculated factorials
         * @param chain Elements already found in current chain
         * @return The length of the chain starting from n
         */
        static uint32_t chain_length(uint32_t n, std::vector<uint32_t>& memory,
                                     const std::vector<uint32_t>& factorials, std::vector<uint64_t>& chain);
    public:
        /**
         * Solves problem
         * @param ub The upper bound for starting numbers to consider
         * @return The solution
         */
        static uint32_t solve(uint32_t ub = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM74_HPP
