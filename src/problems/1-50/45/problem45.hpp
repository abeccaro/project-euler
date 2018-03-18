//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM45_HPP
#define PROJECT_EULER_PROBLEM45_HPP

#include <cstdint>

namespace problems {
    class problem45 {
    private:
        /**
         * Checks if given number is pentagonal
         * @param n The number to check
         * @return True if n is pentagonal, false otherwise
         */
        static bool is_pentagonal(uint64_t n);
    public:
        /**
         * Solves problem
         * @param n The ordinal number of the solution to find
         * @return The solution
         */
        static uint64_t solve(uint32_t n = 3);
    };
}


#endif //PROJECT_EULER_PROBLEM45_HPP
