//
// Created by Alex Beccaro on 01/03/18.
//

#ifndef PROJECT_EULER_PROBLEM92_HPP
#define PROJECT_EULER_PROBLEM92_HPP

#include <vector>

using std::vector;
using uint = unsigned int;

namespace problems {
    class problem92 {
    private:
        /**
         * Checks if chain obtained by summing the squares of number digits loops at 89
         * @param n The number to check
         * @param mem The memory vector
         * @return True if chain reaches 89, false otherwise
         */
        static bool chains_to_89(uint n, vector<uint>& mem);
    public:
        /**
         * Solves problem
         * @param ub The upper bound of number to consider
         * @return The solution
         */
        static uint solve(uint ub);
    };
}


#endif //PROJECT_EULER_PROBLEM92_HPP
