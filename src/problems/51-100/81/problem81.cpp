//
// Created by Alex Beccaro on 25/12/17.
//

#include "problem81.hpp"
#include <input.hpp>

using std::vector;
using input::read_matrix;
using input::problems_folder;

namespace problems {
    uint32_t problem81::best_path_sum(const vector<vector<uint32_t>> &matrix, uint32_t row, uint32_t col, vector<vector<uint32_t>>& mem) {
        if (mem[row][col] != 0) // memory lookup
            return mem[row][col];

        if (row == matrix.size() - 1 && col == matrix[row].size() - 1) // if last row and last column
            return matrix[row][col];

        if (row == matrix.size() - 1) { // if last row but not last column
            uint32_t res = matrix[row][col] + best_path_sum(matrix, row, col + 1, mem);
            mem[row][col] = res;
            return res;
        }

        if (col == matrix[row].size() - 1) { // if last column but not last row
            uint32_t res = matrix[row][col] + best_path_sum(matrix, row + 1, col, mem);
            mem[row][col] = res;
            return res;
        }

        uint32_t right = best_path_sum(matrix, row, col + 1, mem);
        uint32_t down = best_path_sum(matrix, row + 1, col, mem);
        uint32_t res = matrix[row][col] + std::min(right, down);

        mem[row][col] = res;
        return res;
    }

    uint32_t problem81::solve() {
        vector<vector<uint32_t>> matrix = read_matrix<uint32_t>(problems_folder + "51-100/81/input.txt");
        vector<vector<uint32_t>> mem(matrix.size());

        // 0-initialize memory
        for (uint32_t i = 0; i < matrix.size(); i++)
            mem[i] = vector<uint32_t>(matrix[i].size());

        return best_path_sum(matrix, 0, 0, mem);
    }
}