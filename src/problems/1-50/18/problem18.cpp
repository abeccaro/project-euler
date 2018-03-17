//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem18.hpp"
#include <input.hpp>

using namespace input;

namespace problems {
    uint problem18::best_path_sum(const vector<vector<uint>>& triangle, uint row, uint col) {
        if (row == triangle.size() - 1)
            return triangle[row][col];

        return triangle[row][col] +
                std::max(best_path_sum(triangle, row + 1, col), best_path_sum(triangle, row + 1, col + 1));
    }

    uint problem18::solve() {
        vector<vector<uint>> triangle = read_matrix<uint>(problems_folder + "1-50/18/input.txt");
        return best_path_sum(triangle);
    }
}