//
// Created by Alex Beccaro on 21/01/18.
//

#ifndef PROJECT_EULER_PROBLEM67_HPP
#define PROJECT_EULER_PROBLEM67_HPP

#include "cstdint"
#include "vector"
#include "map"

namespace problems {
    class problem67 {
    private:
        static uint32_t calculate_best_paths(const std::vector<std::vector<uint32_t>>& matrix,
                                             std::map<std::pair<uint32_t, uint32_t>, uint32_t>& memory,
                                             uint32_t row, uint32_t col);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM67_HPP
