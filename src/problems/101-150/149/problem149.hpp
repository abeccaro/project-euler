//
// Created by Alex Beccaro on 02/08/2021.
//

#ifndef PROJECT_EULER_PROBLEM149_HPP
#define PROJECT_EULER_PROBLEM149_HPP

#include <cstdint>
#include <vector>


namespace problems {
    class problem149 {
    private:
        /**
         * Generates a size x size grid using sequentially the indicated "Lagged Fibonacci Generator"
         * @param size The size of the grid (side)
         * @return The populated grid
         */
        static std::vector<std::vector<int64_t>> generate_grid(uint32_t size);

    public:
        /**
         * Calculates greatest sum of (any number of) adjacent entries in any direction (horizontal, vertical,
         * diagonal or anti-diagonal)
         * @param n The size of the grid (side)
         * @return The greatest sum of adjacent entries in any direction
         */
        static int64_t solve(uint32_t n = 2000);
    };
}


#endif //PROJECT_EULER_PROBLEM149_HPP
