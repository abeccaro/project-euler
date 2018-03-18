//
// Created by Alex Beccaro on 23/01/18.
//

#ifndef PROJECT_EULER_PROBLEM76_HPP
#define PROJECT_EULER_PROBLEM76_HPP

#include <vector>

namespace problems {
    class problem76 {
    private:
        /**
         * Calculates the number of ways of writing the integer n as a sum of positive integers, not considering order
         * @param n The number
         * @param memory The memory of already calculated counts
         * @return
         */
        static uint64_t partitions(uint32_t n, std::vector<uint64_t>& memory);
    public:
        /**
         * Solves problem
         * @param n The number
         * @return The solution
         */
        static uint64_t solve(uint32_t n = 100);
    };
}


#endif //PROJECT_EULER_PROBLEM76_HPP
