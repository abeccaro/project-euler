//
// Created by Alex Beccaro on 12/03/18.
//

#ifndef PROJECT_EULER_PROBLEM96_HPP
#define PROJECT_EULER_PROBLEM96_HPP

#include <vector>
#include <iostream>

using uint = unsigned int;
using std::vector;
using std::istream;
using std::ostream;

namespace problems {
    class problem96 {
    private:
        class sudoku {
        private:
            /**
             * The grid representation. 0s are considered missing values
             */
            vector<vector<uint>> m;

            /**
             * The size of the grid
             */
            uint size;

            /**
             * The size of the internal boxes
             */
            uint box_size;

            /**
             * Checks if the number in position (row, col) is valid.
             * @param row The row of the number to check
             * @param col The column of the number to check
             * @return True if the number is valid, false otherwise
             */
            bool is_valid_value(uint row, uint col);
        public:
            /**
             * Creates an empty sudoku of specified size
             * @param size The size
             */
            sudoku(uint size = 9);

            /**
             * Creates a sudoku from an existing one represented as vector
             * @param v The vector representation of sudoku. This is supposed by row
             */
            sudoku(const vector<uint>& v);

            /**
             * Solves the sudoku if possible
             * @param row The row of the next element to consider
             * @param col The column of the next element to consider
             * @return True if sudoku has been solved, false otherwise
             */
            bool solve(uint row = 0, uint col = 0);

            /**
             * returns reference to the nth row of matrix representation
             * @param index The row index
             * @return The specified row
             */
            const vector<uint>& operator[](uint index);
        };
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint solve();
    };
}


#endif //PROJECT_EULER_PROBLEM96_HPP
