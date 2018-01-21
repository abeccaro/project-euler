//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM53_HPP
#define PROJECT_EULER_PROBLEM53_HPP

using uint = unsigned int;

namespace problems {
    class problem53 {
    public:
        /**
         * Solves problem
         * @param max_n The maximum n in "n choose r" calculations
         * @return The solution
         */
        static uint solve(uint max_n = 100);
    };
}


#endif //PROJECT_EULER_PROBLEM53_HPP
