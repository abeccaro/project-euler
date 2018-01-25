//
// Created by Alex Beccaro on 25/12/17.
//

#include "problem81.hpp"
#include <input.hpp>

using input::read_matrix;

namespace problems {
    uint problem81::best_path_sum(const vector<vector<uint>> &matrix, uint row, uint col, vector<vector<uint>>& mem) {
        if (mem[row][col] != 0) // memory lookup
            return mem[row][col];

        if (row == matrix.size() - 1 && col == matrix[row].size() - 1) // if last row and last column
            return matrix[row][col];

        if (row == matrix.size() - 1) { // if last row but not last column
            uint res = matrix[row][col] + best_path_sum(matrix, row, col + 1, mem);
            mem[row][col] = res;
            return res;
        }

        if (col == matrix[row].size() - 1) { // if last column but not last row
            uint res = matrix[row][col] + best_path_sum(matrix, row + 1, col, mem);
            mem[row][col] = res;
            return res;
        }

        uint right = best_path_sum(matrix, row, col + 1, mem);
        uint down = best_path_sum(matrix, row + 1, col, mem);
        uint res = matrix[row][col] + min(right, down);

        mem[row][col] = res;
        return res;
    }

    uint problem81::solve() {
        vector<vector<uint>> matrix = read_matrix<uint>(input::PROBLEMS_FOLDER + "51-100/81/input.txt");
        vector<vector<uint>> mem(matrix.size());

        // 0-initialize memory
        for (uint i = 0; i < matrix.size(); i++)
            mem[i] = vector<uint>(matrix[i].size());

        return best_path_sum(matrix, 0, 0, mem);
    }
}