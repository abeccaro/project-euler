//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM18_HPP
#define PROJECT_EULER_PROBLEM18_HPP

#include "cstdint"
#include "vector"

namespace problems {
    class problem18 {
    private:
        /**
         * Calculates the sum of the number in the highest sum path in given triangle from top to bottom.
         * @param triangle The triangle
         * @param row The starting element row
         * @param col The starting element column
         * @return The sum of the best path
         */
        static uint32_t best_path_sum(const std::vector<std::vector<uint32_t>>& triangle,
                                      uint32_t row = 0, uint32_t col = 0);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM18_HPP
