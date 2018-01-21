//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM29_HPP
#define PROJECT_EULER_PROBLEM29_HPP

using uint = unsigned int;

namespace problems {
    class problem29 {
    public:
        /**
         * Solves problem
         * @param max_base The upper bound for base
         * @param max_exp The upper bound for exponent
         * @return The solution
         */
        static uint solve(uint max_base = 100, uint max_exp = 100);
    };
}


#endif //PROJECT_EULER_PROBLEM29_HPP
