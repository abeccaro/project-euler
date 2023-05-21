//
// Created by Alex Beccaro on 21/05/2023.
//

#ifndef PROJECT_EULER_PROBLEM173_HPP
#define PROJECT_EULER_PROBLEM173_HPP


#include "cstdint"

namespace problems {
    class problem173 {
    public:
        /**
         * Calculates how many different square laminae can be formed using up to max_tiles tiles
         * @param max_tiles The maximum number of tiles to form laminae
         * @return The number of different square laminae that can be formed
         */
        static uint64_t solve(uint32_t max_tiles = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM173_HPP
