//
// Created by Alex Beccaro on 15/01/2020.
//

#ifndef PROJECT_EULER_PROBLEM144_HPP
#define PROJECT_EULER_PROBLEM144_HPP

#include <cstdint>

namespace problems {
    class problem144 {
    private:
        /**
         * 2D point representation
         */
        struct point {
        private:
            /**
             * If the difference between two coordinates are less than this value they are considered equal
             */
            constexpr const static double epsilon = 0.0001;

        public:
            /**
             * x and y coordinates of the point
             */
            double x, y;

            /**
             * Constructors
             */
            point();
            point(double x, double y);

            /**
             * Comparison operators
             */
            bool operator ==(const point& other) const;
            bool operator !=(const point& other) const;
        };

    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM144_HPP
