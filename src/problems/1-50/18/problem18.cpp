//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem18.hpp"
#include <input.hpp>

using std::vector;
using input::read_matrix;
using input::problems_folder;

namespace problems {
    uint32_t problem18::best_path_sum(const vector<vector<uint32_t>>& triangle, uint32_t row, uint32_t col) {
        if (row == triangle.size() - 1)
            return triangle[row][col];

        return triangle[row][col] +
                std::max(best_path_sum(triangle, row + 1, col), best_path_sum(triangle, row + 1, col + 1));
    }

    uint32_t problem18::solve() {
        vector<vector<uint32_t>> triangle = read_matrix<uint32_t>(problems_folder + "1-50/18/input.txt");
        return best_path_sum(triangle);
    }
}