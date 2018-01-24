//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM78_HPP
#define PROJECT_EULER_PROBLEM78_HPP

#include <vector>

using uint = unsigned int;
using std::vector;

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
        static long partitions(uint n, vector<int>& memory, vector<uint>& p);
    public:
        /**
         * Solves problem
         * @param n The divisor that p(n) must have
         * @return The solution
         */
        static uint solve(uint n = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM78_HPP
