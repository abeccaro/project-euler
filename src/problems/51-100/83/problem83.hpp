//
// Created by Alex Beccaro on 28/01/18.
//

#ifndef PROJECT_EULER_PROBLEM83_HPP
#define PROJECT_EULER_PROBLEM83_HPP

#include <vector>

using uint = unsigned int;
using ulong = unsigned long;
using std::vector;

namespace problems {
    class problem83 {
    private:
        /**
         * Representation of a number in input matrix with relative data
         */
        struct entry {
            ulong row;      // row index
            ulong col;      // column index
            uint value;     // number value
            uint distance;  // upper bound for sum of numbers from top-left to this entry

            /**
             * Constructor that sets position in matrix and value
             * @param row The row index
             * @param col The column index
             * @param value The number value
             */
            entry(ulong row, ulong col, uint value);
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
        static uint best_path_sum(const vector<vector<uint>>& matrix);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint solve();
    };
}


#endif //PROJECT_EULER_PROBLEM83_HPP
