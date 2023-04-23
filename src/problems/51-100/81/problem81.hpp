//
// Created by Alex Beccaro on 25/01/18.
//

#ifndef PROJECT_EULER_PROBLEM81_HPP
#define PROJECT_EULER_PROBLEM81_HPP

#include "cstdint"
#include "vector"

namespace problems {
    class problem81 {
    private:
        /**
         * Calculate the minimum sum of numbers in path from row,col to bottom-right of matrix only going right or down.
         * Matrix is assumed to be rectangular
         * @param matrix The matrix of numbers (assumed rectangular)
         * @param row The starting row
         * @param col The starting column
         * @param mem Previously calculated values
         * @return The minimum sum
         */
        static uint32_t best_path_sum(const std::vector<std::vector<uint32_t>>& matrix, uint32_t row, uint32_t col,
                                      std::vector<std::vector<uint32_t>>& mem);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM81_HPP
