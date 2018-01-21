//
// Created by Alex Beccaro on 21/01/18.
//

#ifndef PROJECT_EULER_PROBLEM70_HPP
#define PROJECT_EULER_PROBLEM70_HPP

#include <vector>

using uint = unsigned int;
using std::vector;
using std::string;

namespace problems {
    class problem70 {
    public:
        /**
         * Solves problem
         * @param ub The upper bound for numbers to consider
         * @return The solution
         */
        static uint solve(uint ub = 10000000);
    };
}


#endif //PROJECT_EULER_PROBLEM70_HPP
