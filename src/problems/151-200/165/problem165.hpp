//
// Created by Alex Beccaro on 29/04/2023.
//

#ifndef PROJECT_EULER_problem165_HPP
#define PROJECT_EULER_problem165_HPP


#include "cstdint"
#include "fraction.hpp"
#include "optional"
#include "geometry/point.hpp"
#include "geometry/segment.hpp"
#include "vector"

namespace problems {
    class problem165 {

    public:
        /**
         * Counts how many distinct true intersection points are found among the 5000 line segments generated with the
         * "Blum Blum Shub" rng as described in the problem
         * @return The number of distinct true intersection points
         */
        static uint64_t solve();

    private:


        static std::vector<geometry::segment<fractions::fraction<int64_t>>> generate_segments();
    };
}


#endif //PROJECT_EULER_problem165_HPP
