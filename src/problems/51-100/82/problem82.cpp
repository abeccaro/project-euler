//
// Created by Alex Beccaro on 25/01/18.
//

#include "problem82.hpp"
#include <input.hpp>

using input::read_matrix;

namespace problems {
    uint problem82::solve() {
        vector<vector<uint>> matrix = read_matrix<uint>(input::PROBLEMS_FOLDER + "51-100/82/input.txt");
        vector<vector<uint>> mem(matrix.size());

        // initialize memory (0 for every element but last column)
        for (uint i = 0; i < matrix.size(); i++)
            mem[i] = vector<uint>(matrix[i].size());
        for (uint i = 0; i < mem.size(); i++)
            mem[i].back() = matrix[i].back();

        // loop on columns from second to last to first and on rows from top to bottom
        for (uint c = matrix.size() - 1; c-- > 0;) {
            for (uint r = 0; r < mem.size(); r++) {
                // right way
                uint best = matrix[r][c] + mem[r][c+1];

                // up way (already calculated from row r-1)
                if (r > 0) {
                    uint best_up = matrix[r][c] + mem[r - 1][c];
                    best = min(best, best_up);
                }

                // down (still to calculate), try for every possible i steps down
                uint sum = matrix[r][c];
                uint ub = matrix.size() - r;
                for (uint i = 1; i < ub && sum < best; i++) {
                    sum += matrix[r+i][c];
                    uint current = sum + mem[r+i][c+1];
                    best = min(best, current);
                }

                // save result in memory
                mem[r][c] = best;
            }
        }

        // get minimum path cost from first column starting points
        uint res = mem[0][0];
        for (uint i = 1; i < mem.size(); i++)
            res = min(res, mem[i][0]);
        return res;
    }
}