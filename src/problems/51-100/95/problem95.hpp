//
// Created by Alex Beccaro on 07/03/18.
//

#ifndef PROJECT_EULER_PROBLEM95_HPP
#define PROJECT_EULER_PROBLEM95_HPP

#include <vector>

namespace problems {
    class problem95 {
    private:
        /**
         * Calculates the length of the eventual chain that starts from n. If there is no chain 1 is returned.
         * @param n The starting number
         * @param memory The memory of already calculated lengths
         * @param div_sums Pre-calculated sums of divisors
         * @param chain Numbers found since first call
         * @return The length of the chain starting from n, or 1 if there is no chain.
         */
        static uint32_t chain_length(uint32_t n, std::vector<uint32_t>& memory, const std::vector<uint32_t>& div_sums,
                                     std::vector<uint32_t>& chain);
    public:
        /**
         * Solves problem
         * @param ub The upper bound for numbers in considered chains
         * @return The solution
         */
        static uint32_t solve(uint32_t ub = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM95_HPP
