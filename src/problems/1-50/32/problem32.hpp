//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM32_HPP
#define PROJECT_EULER_PROBLEM32_HPP

using uint = unsigned int;
using ulong = unsigned long;

namespace problems {
    class problem32 {
    private:
        /**
         * Combine given numbers appending b's digits at the end of a
         * @param a The first number
         * @param b The second number
         * @return The number of different ways to make 'pence' pence
         */
        static ulong combine(uint a, uint b);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint solve();
    };
}


#endif //PROJECT_EULER_PROBLEM32_HPP
