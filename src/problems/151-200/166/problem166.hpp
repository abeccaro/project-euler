//
// Created by Alex Beccaro on 01/05/2023.
//

#ifndef PROJECT_EULER_PROBLEM166_HPP
#define PROJECT_EULER_PROBLEM166_HPP


#include "cstdint"

namespace problems {
    class problem166 {
    public:
        /**
         * Counts how many ways there are to fill a 4x4 grid with digits so that each row, each column, and both
         * diagonals have the same sum
         * @return The number of ways
         */
        static uint32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM166_HPP
