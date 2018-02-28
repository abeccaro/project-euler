//
// Created by Alex Beccaro on 28/02/18.
//

#ifndef PROJECT_EULER_PROBLEM91_HPP
#define PROJECT_EULER_PROBLEM91_HPP

using uint = unsigned int;

namespace problems {
    class problem91 {
    private:
        /**
         * Checks if triangle formed by (0, 0), (x1, y1) and (x2, y2) has a right angle.
         * First point is supposed to be left to the other (x1 <= x2)
         * @param x1 The x coordinate of the first point
         * @param y1 The y coordinate of the first point
         * @param x2 The x coordinate of the second point
         * @param y2 The y coordinate of the second point
         * @return True if formed triangle has a rect angle, false otherwise
         */
        static bool has_right_angle(uint x1, uint y1, uint x2, uint y2);
    public:
        /**
         * Solves problem
         * @param max_x The maximum value for x coordinate
         * @param max_y The maximum value for x coordinate
         * @return The solution
         */
        static uint solve(uint max_x = 50, uint max_y = 50);
    };
}


#endif //PROJECT_EULER_PROBLEM91_HPP
