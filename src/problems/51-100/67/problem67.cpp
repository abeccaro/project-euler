//
// Created by Alex Beccaro on 21/01/18.
//

#include "problem67.hpp"
#include <input.hpp>
#include <map>

using input::read_matrix;
using input::problems_folder;

namespace problems {
    uint problem67::calculate_best_paths(const vector<vector<uint>>& matrix,
                                         map<pair<uint, uint>, uint>& memory,
                                         uint row, uint col) {
        pair<uint, uint> key(row, col);
        if (memory.find(key) != memory.end())
            return memory[key];

        if (row == matrix.size() - 1) {
            uint value = matrix.back()[col];
            memory[key] = value;
            return value;
        }

        uint left = calculate_best_paths(matrix, memory, row + 1, col);
        uint right = calculate_best_paths(matrix, memory, row + 1, col + 1);
        uint best = matrix[row][col] + std::max(left, right);
        memory[key] = best;
        return best;
    }

    uint problem67::solve() {
        vector<vector<uint>> matrix = read_matrix<uint>(problems_folder + "51-100/67/input.txt");
        map<pair<uint, uint>, uint> memory;

        return calculate_best_paths(matrix, memory, 0, 0);
    }
}
