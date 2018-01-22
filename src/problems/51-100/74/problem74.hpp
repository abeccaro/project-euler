//
// Created by Alex Beccaro on 22/01/18.
//

#ifndef PROJECT_EULER_PROBLEM74_HPP
#define PROJECT_EULER_PROBLEM74_HPP

#include <vector>

using uint = unsigned int;
using ulong = unsigned long;
using std::vector;

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
        static uint chain_length(uint n, vector<uint>& memory,
                                 const vector<uint>& factorials, vector<ulong>& chain);
    public:
        /**
         * Solves problem
         * @param ub The upper bound for starting numbers to consider
         * @return The solution
         */
        static uint solve(uint ub = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM74_HPP
