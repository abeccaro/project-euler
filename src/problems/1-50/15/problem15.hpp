//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM15_HPP
#define PROJECT_EULER_PROBLEM15_HPP

#include <boost/multiprecision/cpp_int.hpp>

using uint = unsigned int;
using boost::multiprecision::uint128_t;

namespace problems {
    class problem15 {
    public:
        /**
         * Solves problem
         * @param width The width of the grid
         * @param height The height of the grid
         * @return The solution
         */
        static uint128_t solve(uint width = 20, uint height = 20);
    };
}


#endif //PROJECT_EULER_PROBLEM15_HPP
