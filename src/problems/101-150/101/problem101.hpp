//
// Created by Alex Beccaro on 21/03/18.
//

#ifndef PROJECT_EULER_PROBLEM101_HPP
#define PROJECT_EULER_PROBLEM101_HPP

#include "cstdint"
#include "functional"

namespace problems {
    class problem101 {
    private:
        /**
         * Default function for problem
         * @param x The x coordinate
         * @return The y coordinate
         */
        static int64_t default_fun(int32_t x);

        /**
         * Interpolates next value from given example points. Points are in the form: (1, y[0]), (2, y[1]), ...
         * @param y The y coordinates of given points
         * @return The y of interpolated next point in sequence
         */
        static int64_t lagrange_interpolate_next(const std::vector<int64_t>& y);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static int64_t solve(const std::function<int64_t (int32_t)>& fun = default_fun);
    };
}


#endif //PROJECT_EULER_PROBLEM101_HPP
