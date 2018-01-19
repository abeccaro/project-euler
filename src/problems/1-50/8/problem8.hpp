//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM8_HPP
#define PROJECT_EULER_PROBLEM8_HPP

using uint = unsigned int;
using ulong = unsigned long;

namespace problems {
    class problem8 {
    public:
        /**
         * Solves problem
         * @param digits The number of adjacent digits to sum
         * @return The solution
         */
        static ulong solve(uint digits = 13);
    };
}

#endif //PROJECT_EULER_PROBLEM8_HPP
