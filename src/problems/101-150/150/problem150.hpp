//
// Created by Alex Beccaro on 02/08/2021.
//

#ifndef PROJECT_EULER_PROBLEM150_HPP
#define PROJECT_EULER_PROBLEM150_HPP

#include "cstdint"
#include "vector"
#include "map"


namespace problems {
    class problem150 {
    public:
        /**
         * Generates a triangle with size n using sequentially the indicated Linear Congruential Generator
         * @param n The size of the triangle (side)
         * @return The populated triangle expressed as matrix
         */
        static std::vector<std::vector<int64_t>> generate_triangle(uint32_t n);

    public:
        /**
         * Calculates smallest sum of any sub-triangle of the randomly generated triangle
         * @param n The size of the triangle (side)
         * @return The smallest sum of any sub-triangle
         */
        static int64_t solve(uint32_t n = 1000);
    };
}


#endif //PROJECT_EULER_PROBLEM150_HPP
