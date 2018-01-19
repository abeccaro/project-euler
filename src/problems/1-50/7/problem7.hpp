//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM7_HPP
#define PROJECT_EULER_PROBLEM7_HPP


using uint = unsigned int;
using ulong = unsigned long;

namespace problems {

    class problem7 {
    public:
        /**
         * Solves problem
         * @param position The ordinal of requested prime
         * @return The solution
         */
        static uint solve(ulong position = 10001);
    };
}

#endif //PROJECT_EULER_PROBLEM7_HPP
