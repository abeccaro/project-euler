//
// Created by Alex Beccaro on 05/12/18.
//

#include "problem107.hpp"
#include <input.hpp>

using std::vector;
using std::find;

using input::read_matrix;
using input::problems_folder;


namespace problems {
    uint32_t problem107::solve() {
        vector<vector<uint32_t>> matrix = read_matrix<uint32_t>(problems_folder + "/101-150/107/input.txt");
        uint32_t original_sum = 0;
        for (uint32_t i = 0; i < matrix.size(); i++)
            for (uint32_t j = i+1; j < matrix[i].size(); j++)
                original_sum += matrix[i][j];

        uint32_t sum = 0;
        vector<uint32_t> reached(1);

        while (reached.size() != matrix.size()) {
            uint32_t min = std::numeric_limits<uint32_t>::max();
            uint32_t min_i = 0;

            for (const auto& r : reached) {
                vector<uint32_t> row = matrix[r];

                for (uint32_t i = 0; i < row.size(); i++) {
                    auto it = find(reached.begin(), reached.end(), i);

                    if (it == reached.end() && row[i] != 0 && row[i] < min) {
                        min = row[i];
                        min_i = i;
                    }
                }
            }

            sum += min;
            reached.push_back(min_i);
        }

        return original_sum - sum;
    }
}