//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM17_HPP
#define PROJECT_EULER_PROBLEM17_HPP

using uint = unsigned int;

namespace problems {
    class problem17 {
    private:
        /**
         * Calculates the number of letters used for a given number up to 1000.
         * @param n The number
         * @return The number of letters
         */
        static uint letters(uint n);
    public:
        /**
         * Solves problem
         * @param ub The upper bound of numbers to consider
         * @return The solution
         */
        static uint solve(uint ub = 1000);
    };
}


#endif //PROJECT_EULER_PROBLEM17_HPP
