//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM1_HPP
#define PROJECT_EULER_PROBLEM1_HPP


using uint = unsigned int;

namespace problems {

    class problem1 {
    public:
        /**
         * Solves problem
         * @param ub The upper bound
         * @return The solution
         */
        static uint solve(uint ub = 1000);

    private:
        /**
         * Calculates the sum of all multiples of given number below given upper bound.
         * @param n The number
         * @param ub The upper bound
         * @return The sum of multiples
         */
        static uint multiplesSum(uint n, uint ub);
    };
}


#endif //PROJECT_EULER_PROBLEM1_HPP
