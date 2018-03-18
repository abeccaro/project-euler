//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM32_HPP
#define PROJECT_EULER_PROBLEM32_HPP

#include <cstdint>

namespace problems {
    class problem32 {
    private:
        /**
         * Combine given numbers appending b's digits at the end of a
         * @param a The first number
         * @param b The second number
         * @return The number of different ways to make 'pence' pence
         */
        static uint64_t combine(uint32_t a, uint32_t b);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM32_HPP
