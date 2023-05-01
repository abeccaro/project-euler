//
// Created by Alex Beccaro on 29/04/2023.
//

#ifndef PROJECT_EULER_PROBLEM163_HPP
#define PROJECT_EULER_PROBLEM163_HPP


#include "series/figurate_number.hpp"

namespace problems {
    class problem163 {
    private:
        /**
         * Triangular numbers used in calculations
         */
        static series::figurate_number<uint32_t> triangular;

        /**
         * Coefficients used in calculations in a loop for T_n, T_(n-1), etc
         */
         static std::vector<uint32_t> coefficients;
    public:
        /**
         * Counts how many triangles there are in an equilateral triangle with medians of size n
         * @param n The size of the triangle
         * @return The number of different triangles
         */
        static uint32_t solve(uint32_t n = 36);
    };
}


#endif //PROJECT_EULER_PROBLEM163_HPP
