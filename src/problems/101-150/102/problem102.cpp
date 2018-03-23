//
// Created by Alex Beccaro on 22/03/18.
//

#include "problem102.hpp"
#include <input.hpp>

using std::vector;

using input::read_matrix;
using input::problems_folder;

namespace problems {
    // Uses barycentric coordinates
    bool problem102::contains(const std::vector<int32_t>& t, int32_t px, int32_t py) {
        float d = (t[3] - t[5]) * (t[0] - t[4]) + (t[4] - t[2]) * (t[1] - t[5]);

        float b1 = ((t[3] - t[5]) * (px - t[4]) + (t[4] - t[2]) * (py - t[5])) / d;
        float b2 = ((t[5] - t[1]) * (px - t[4]) + (t[0] - t[4]) * (py - t[5])) / d;
        float b3 = 1 - b1 - b2;

        return b1 >= 0 && b2 >= 0 && b3 >= 0;
    }

    int32_t problem102::solve() {
        vector<vector<int32_t>> triangles = read_matrix<int32_t>(problems_folder + "/101-150/102/input.txt");
        uint32_t result = 0;

        for (const auto& t : triangles)
            if (contains(t, 0, 0))
                result++;

        return result;
    }
}