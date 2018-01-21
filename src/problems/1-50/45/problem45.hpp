//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM45_HPP
#define PROJECT_EULER_PROBLEM45_HPP

using uint = unsigned int;
using ulong = unsigned long;

namespace problems {
    class problem45 {
    private:
        /**
         * Checks if given number is pentagonal
         * @param n The number to check
         * @return True if n is pentagonal, false otherwise
         */
        static bool is_pentagonal(ulong n);
    public:
        /**
         * Solves problem
         * @param n The ordinal number of the solution to find
         * @return The solution
         */
        static ulong solve(uint n = 3);
    };
}


#endif //PROJECT_EULER_PROBLEM45_HPP
