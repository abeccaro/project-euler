//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM48_HPP
#define PROJECT_EULER_PROBLEM48_HPP

#include <vector>

using uint = unsigned int;
using std::vector;

namespace problems {
    class problem48 {
    public:
        /**
         * Solves problem
         * @param ub The upper bound of numbers
         * @return The solution
         */
        static vector<uint> solve(uint ub = 1000);
    };
}


#endif //PROJECT_EULER_PROBLEM48_HPP
