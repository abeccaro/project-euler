//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM78_HPP
#define PROJECT_EULER_PROBLEM78_HPP

#include <vector>

namespace problems {
    class problem78 {
    private:
        /**
         * Calculates the number of partitions of n
         * @param n The number
         * @param memory The memory of previously obtained results
         * @param p Pre-calculated generalized pentagonal numbers
         * @return The number of partitions of n
         */
        static int64_t partitions(uint32_t n, std::vector<int32_t>& memory, std::vector<uint32_t>& p);
    public:
        /**
         * Solves problem
         * @param n The divisor that p(n) must have
         * @return The solution
         */
        static uint32_t solve(uint32_t n = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM78_HPP
