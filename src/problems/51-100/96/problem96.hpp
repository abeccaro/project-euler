//
// Created by Alex Beccaro on 12/03/18.
//

#ifndef PROJECT_EULER_PROBLEM96_HPP
#define PROJECT_EULER_PROBLEM96_HPP

#include <vector>
#include <iostream>

namespace problems {
    class problem96 {
    private:
        class sudoku {
        private:
            /**
             * The grid representation. 0s are considered missing values
             */
            std::vector<std::vector<uint32_t>> m;

            /**
             * The size of the grid
             */
            uint32_t size;

            /**
             * The size of the internal boxes
             */
            uint32_t box_size;

            /**
             * Checks if the number in position (row, col) is valid.
             * @param row The row of the number to check
             * @param col The column of the number to check
             * @return True if the number is valid, false otherwise
             */
            bool is_valid_value(uint32_t row, uint32_t col);
        public:
            /**
             * Creates an empty sudoku of specified size
             * @param size The size
             */
            sudoku(uint32_t size = 9);

            /**
             * Creates a sudoku from an existing one represented as vector
             * @param v The vector representation of sudoku. This is supposed by row
             */
            sudoku(const std::vector<uint32_t>& v);

            /**
             * Solves the sudoku if possible
             * @param row The row of the next element to consider
             * @param col The column of the next element to consider
             * @return True if sudoku has been solved, false otherwise
             */
            bool solve(uint32_t row = 0, uint32_t col = 0);

            /**
             * returns reference to the nth row of matrix representation
             * @param index The row index
             * @return The specified row
             */
            const std::vector<uint32_t>& operator[](uint32_t index);
        };
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM96_HPP
