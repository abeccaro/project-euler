//
// Created by Alex Beccaro on 25/02/18.
//

#ifndef PROJECT_EULER_PROBLEM86_HPP
#define PROJECT_EULER_PROBLEM86_HPP

using uint = unsigned int;

namespace problems {
    class problem86 {
    private:
        /**
         * Calculates the number of ways to choose two numbers x and y such that 1 <= x <= y <= m and x + y = sum
         * @param sum The sum of the numbers
         * @param m The maximum number valid
         * @return The number of x, y valid combinations
         */
        static uint sum_combinations(uint sum, uint m);
    public:
        /**
         * Solves problem
         * @param n The number of integral solutions to find
         * @return The solution
         */
        static uint solve(uint n = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM86_HPP
