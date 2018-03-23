//
// Created by Alex Beccaro on 22/03/18.
//

#ifndef PROJECT_EULER_PROBLEM102_HPP
#define PROJECT_EULER_PROBLEM102_HPP

#include <cstdint>
#include <vector>

namespace problems {
    class problem102 {
    private:
        /**
         * Checks if point (px, py) is inside given triangle. Triangle is supposed in the format:
         * {p1x, p1y, p2x, p2y, p3x, p3y}
         * @param triangle The triangle points coordinates
         * @param px The x coordinate of point to check
         * @param py The y coordinate of point to check
         * @return True if the point is inside the triangle, false otherwise
         */
        static bool contains(const std::vector<int32_t>& triangle, int32_t px, int32_t py);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static int32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM102_HPP
