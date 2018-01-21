//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM55_HPP
#define PROJECT_EULER_PROBLEM55_HPP

using uint = unsigned int;

namespace problems {
    class problem55 {
    public:
        /**
         * Solves problem
         * @param ub The upper bound of numbers to check
         * @param iterations The number of iterations after which a number is considered a Lychrel number
         * @return The solution
         */
        static uint solve(uint ub = 10000, uint iterations = 50);
    };
}


#endif //PROJECT_EULER_PROBLEM55_HPP
