//
// Created by Alex Beccaro on 21/01/18.
//

#ifndef PROJECT_EULER_PROBLEM69_HPP
#define PROJECT_EULER_PROBLEM69_HPP

#include <vector>

using uint = unsigned int;
using std::vector;
using std::string;

namespace problems {
    class problem69 {
    public:
        /**
         * Solves problem
         * @param ub The upper bound for numbers to consider
         * @return The solution
         */
        static uint solve(uint ub = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM69_HPP
