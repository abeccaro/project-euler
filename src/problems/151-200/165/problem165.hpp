//
// Created by Alex Beccaro on 29/04/2023.
//

#ifndef PROJECT_EULER_problem165_HPP
#define PROJECT_EULER_problem165_HPP


#include "cstdint"
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
        /**
         * Generates the 5000 segments using the "Blum Blum Shub" rng as described in the problem
         * @return The vector of segments
         */
        static std::vector<geometry::segment<int32_t>> generate_segments();
    };
}


#endif //PROJECT_EULER_problem165_HPP
