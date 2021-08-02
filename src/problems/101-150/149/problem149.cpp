//
// Created by Alex Beccaro on 02/08/2021.
//

#include "problem149.hpp"
#include <vector>

using std::vector;
using std::max;


namespace problems {

    vector<vector<int64_t>> problem149::generate_grid(uint32_t size) {
        vector<int64_t> s = {};

        for (int64_t k = 1; k <= size * size; k++) {
            if (k <= 55)
                s.push_back((100003 - 200003*k + 300007*k*k*k) % 1000000 - 500000);
            else
                s.push_back((s[k-25] + s[k-56] + 1000000) % 1000000 - 500000);
        }

        vector<vector<int64_t>> grid = {};
        for (uint32_t r = 0; r < size; r++) {
            grid.emplace_back(size);
            for (uint32_t c = 0; c < size; c++)
                grid[r][c] = s[r*size + c];
        }

        return grid;
    }

    int64_t problem149::solve(uint32_t n) {
        vector<vector<int64_t>> grid = generate_grid(n);

        int64_t best = 0;

        // rows
        for (auto& row : grid) {
            int64_t best_sum = 0;
            for (auto& value : row) {
                best_sum = max(0ll, best_sum + value);
                best = max(best, best_sum);
            }
        }

        // columns
        for (uint32_t col = 0; col < n; col++) {
            int64_t best_sum = 0;
            for (auto& row : grid) {
                best_sum = max(0ll, best_sum + row[col]);
                best = max(best, best_sum);
            }
        }

        // diagonals
        for (uint32_t row = 0; row < n; row++) {
            int64_t best_sum_bottom_right = 0;
            for (uint32_t i = 0; i < n - row; i++) {
                best_sum_bottom_right = max(0ll, best_sum_bottom_right + grid[row + i][i]);
                best = max(best, best_sum_bottom_right);
            }

            int64_t best_sum_top_right = 0;
            for (uint32_t i = 0; i <= row; i++) {
                best_sum_top_right = max(0ll, best_sum_top_right + grid[row - i][i]);
                best = max(best, best_sum_top_right);
            }

            int64_t best_sum_bottom_left = 0;
            for (uint32_t i = 0; i < n - row; i++) {
                best_sum_bottom_left = max(0ll, best_sum_bottom_left + grid[row + i][n - 1 - i]);
                best = max(best, best_sum_bottom_left);
            }

            int64_t best_sum_top_left = 0;
            for (uint32_t i = 0; i <= row; i++) {
                best_sum_top_left = max(0ll, best_sum_top_left + grid[row - i][n - 1 - i]);
                best = max(best, best_sum_top_left);
            }
        }

        return best;
    }

}