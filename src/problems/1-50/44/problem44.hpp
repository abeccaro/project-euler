//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM44_HPP
#define PROJECT_EULER_PROBLEM44_HPP

using uint = unsigned int;

namespace problems {
    class problem44 {
    private:
        /**
         * Checks if given number is pentagonal
         * @param n The number to check
         * @return True if n is pentagonal, false otherwise
         */
        static bool is_pentagonal(uint n);

        /**
         * Checks if given number is the double of a pentagonal number
         * @param n The number to check
         * @return True if n is the double of a pentagonal number, false otherwise
         */
        static bool is_double_pentagonal(uint n);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint solve();
    };
}


#endif //PROJECT_EULER_PROBLEM44_HPP
