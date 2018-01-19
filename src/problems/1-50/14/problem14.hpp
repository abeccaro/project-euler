//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM14_HPP
#define PROJECT_EULER_PROBLEM14_HPP

#include <vector>

using uint = unsigned int;
using std::vector;

namespace problems {
    class problem14 {
    private:
        /**
         * Finds the length of the Collatz chain starting from n. It uses a vector for memoization.
         * @param n The starting number
         * @param memory The vector with already calculated lengths
         * @return The length of the chain
         */
        static uint collatz_length(uint n, vector<uint>& memory);
    public:
        /**
         * Solves problem
         * @param ub The upper bound of starting numbers to check
         * @return The solution
         */
        static uint solve(uint ub = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM14_HPP
