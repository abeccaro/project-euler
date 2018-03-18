//
// Created by Alex Beccaro on 28/01/18.
//

#ifndef PROJECT_EULER_PROBLEM83_HPP
#define PROJECT_EULER_PROBLEM83_HPP

#include <vector>

namespace problems {
    class problem83 {
    private:
        /**
         * Representation of a number in input matrix with relative data
         */
        struct entry {
            uint64_t row;      // row index
            uint64_t col;      // column index
            uint32_t value;     // number value
            uint32_t distance;  // upper bound for sum of numbers from top-left to this entry

            /**
             * Constructor that sets position in matrix and value
             * @param row The row index
             * @param col The column index
             * @param value The number value
             */
            entry(uint64_t row, uint64_t col, uint32_t value);
        };

        /**
         * Comparator for entry pointers
         */
        struct entry_comparer {
            bool operator() (const entry *a, const entry *b);
        };

        /**
         * Calculates the sum of the best path from top-left element to bottom-right one.
         * All four directions are allowed.
         * @param matrix The matrix of numbers
         * @return The sum of numbers in the best path
         */
        static uint32_t best_path_sum(const std::vector<std::vector<uint32_t>>& matrix);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM83_HPP
