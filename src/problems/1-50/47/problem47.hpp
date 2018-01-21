//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM47_HPP
#define PROJECT_EULER_PROBLEM47_HPP

using uint = unsigned int;

namespace problems {
    class problem47 {
    public:
        /**
         * Solves problem
         * @param n The number of consecutive numbers
         * @param factors The number of distinct prime factors
         * @return The solution
         */
        static uint solve(uint n = 4, uint factors = 4);
    };
}


#endif //PROJECT_EULER_PROBLEM47_HPP
