//
// Created by Alex Beccaro on 02/08/2021.
//

#include "problem150.hpp"
#include "generics.hpp"

using std::vector;
using std::min;
using generics::int_pow;


namespace problems {

    vector<vector<int64_t>> problem150::generate_triangle(uint32_t n) {
        vector<vector<int64_t>> grid = {};
        int64_t elements = n * (n + 1) / 2;
        vector<int64_t> s(elements);

        int64_t t = 0;
        int64_t mod = int_pow(2, 20);
        int64_t diff = int_pow(2, 19);
        for (int64_t k = 1; k <= elements; k++) {
            t = (615949*t + 797807) % mod;
            s[k-1] = t - diff;
        }

        uint32_t i = 0;
        for (uint32_t r = 0; r < n; r++) {
            grid.emplace_back(r+1);
            for (uint32_t c = 0; c <= r; c++) {
                grid[r][c] = s[i++];
            }
        }

        return grid;
    }

    int64_t problem150::solve(uint32_t n) {
        vector<vector<int64_t>> triangle = generate_triangle(n);
        int64_t result = 0;

        for (int32_t i = 0; i < n; i++) {
            // init partial sums
            vector<int64_t> sum(i, 0);
            for (int32_t j = 0; j < i; j++)
                sum[j] = triangle[i][j];

            // for each starting position [r][c] (in reverse r order)
            for (int32_t r = i-1; r >= 0; r--) {
                for (int32_t c = 0; c <= r; c++) {
                    int32_t c_max = c + i - r;

                    // add the sum of triangle[i][c..c_max] = sum[c] + triangle[i][c_max]
                    triangle[r][c] += sum[c] + triangle[i][c_max];
                    // update partial sum for next row
                    sum[c] += triangle[i][c_max];

                    // update min triangle sum
                    result = min(result, triangle[r][c]);
                }
            }
            // check single value triangles at row i
            for (int32_t c = 0; c <= i; c++)
                result = min(result, triangle[i][c]);
        }

        return result;
    }

}