//
// Created by Alex Beccaro on 22/01/18.
//

#ifndef PROJECT_EULER_PROBLEM72_HPP
#define PROJECT_EULER_PROBLEM72_HPP

using ulong = unsigned long;

namespace problems {
    class problem72 {
    public:
        /**
         * Solves problem
         * @param ub The upper bound for denominators to consider
         * @return The solution
         */
        static ulong solve(ulong ub = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM72_HPP
