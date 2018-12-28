//
// Created by Alex Beccaro on 27/12/18.
//

#ifndef PROJECT_EULER_PROBLEM112_HPP
#define PROJECT_EULER_PROBLEM112_HPP

#include <cstdint>
#include <string>

namespace problems {
    class problem112 {
    private:
        /**
         * Tests given number to determine if it is a bouncy number
         * @param n The number to test
         * @return True if given number is bouncy, false otherwise
         */
        static bool is_bouncy(uint32_t n);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve(double percentage = 0.99);
    };
}


#endif //PROJECT_EULER_PROBLEM112_HPP
