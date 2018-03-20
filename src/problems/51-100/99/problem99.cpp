//
// Created by Alex Beccaro on 13/03/18.
//

#include "problem99.hpp"
#include <input.hpp>

using std::vector;

using input::read_matrix;
using input::problems_folder;

namespace problems {
    uint32_t problem99::solve() {
        vector<vector<uint32_t>> nums = read_matrix<uint32_t>(problems_folder + "51-100/99/input.txt");

        uint32_t result = 0;
        double max = 0;

        for (uint32_t i = 0; i < nums.size(); i++) {
            // from the formula for digit number: floor(log_10(n)) + 1
            // by not using floor we keep more information; +1 to all is irrelevant
            double approx_order = nums[i][1] * log10(nums[i][0]);

            if (approx_order > max) {
                max = approx_order;
                result = i + 1;
            }
        }

        return result;
    }
}