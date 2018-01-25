//
// Created by Alex Beccaro on 25/01/18.
//

#ifndef PROJECT_EULER_PROBLEM82_HPP
#define PROJECT_EULER_PROBLEM82_HPP

#include <vector>

using uint = unsigned int;
using std::vector;

namespace problems {
    class problem82 {
    private:
        /**
         * Calculate the minimum sum of numbers in path from row,col to last column of matrix only going right, up or
         * down.
         * Matrix is assumed to be rectangular
         * @param matrix The matrix of numbers (assumed rectangular)
         * @param row The starting row
         * @param col The starting column
         * @param mem Previously calculated values
         * @return The minimum sum
         */
        static uint best_path_sum(const vector<vector<uint>>& matrix, uint row, uint col, vector<vector<uint>>& mem);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint solve();
    };
}


#endif //PROJECT_EULER_PROBLEM82_HPP
