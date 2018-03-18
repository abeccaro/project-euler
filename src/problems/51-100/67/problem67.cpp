//
// Created by Alex Beccaro on 21/01/18.
//

#include "problem67.hpp"
#include <input.hpp>

using std::vector;
using std::map;
using std::pair;

using input::read_matrix;
using input::problems_folder;

namespace problems {
    uint32_t problem67::calculate_best_paths(const vector<vector<uint32_t>>& matrix,
                                         map<pair<uint32_t, uint32_t>, uint32_t>& memory,
                                         uint32_t row, uint32_t col) {
        pair<uint32_t, uint32_t> key(row, col);
        if (memory.find(key) != memory.end())
            return memory[key];

        if (row == matrix.size() - 1) {
            uint32_t value = matrix.back()[col];
            memory[key] = value;
            return value;
        }

        uint32_t left = calculate_best_paths(matrix, memory, row + 1, col);
        uint32_t right = calculate_best_paths(matrix, memory, row + 1, col + 1);
        uint32_t best = matrix[row][col] + std::max(left, right);
        memory[key] = best;
        return best;
    }

    uint32_t problem67::solve() {
        vector<vector<uint32_t>> matrix = read_matrix<uint32_t>(problems_folder + "51-100/67/input.txt");
        map<pair<uint32_t, uint32_t>, uint32_t> memory;

        return calculate_best_paths(matrix, memory, 0, 0);
    }
}
