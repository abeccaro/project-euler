//
// Created by Alex Beccaro on 21/05/2023.
//

#ifndef PROJECT_EULER_PROBLEM174_HPP
#define PROJECT_EULER_PROBLEM174_HPP


#include "cstdint"

namespace problems {
    class problem174 {
    public:
        /**
         * Calculates the sum of N(n) for 1 <= n <= max_n where N(n) the number of t ≤ 1000000 such that t is type L(n).
         * t represents the number of tiles used and L(n) is the type for which there are n different laminae using t
         * tiles.
         * @param max_tiles The maximum number of tiles to form laminae
         * #@param max_n The upper bound for N(n)
         * @return The sum of N(n) for 1 <= n <= max_n
         */
        static uint64_t solve(uint32_t max_tiles = 1000000, uint32_t max_n = 10);
    };
}


#endif //PROJECT_EULER_PROBLEM174_HPP
