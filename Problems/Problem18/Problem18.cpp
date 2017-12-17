//
// Created by Alex Beccaro on 17/12/17.
//

#include <iostream>
#include <input.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace input;

using numtype = unsigned int;

/**
 * Calculates the sum of the number in the highest sum path in given triangle from top to bottom.
 * @param triangle The triangle
 * @param row The starting element row
 * @param col The starting element column
 * @return The sum of the best path
 */
numtype best_path_sum(const vector<vector<numtype>> &triangle, const numtype& row = 0, const numtype& col = 0) {
    if (row == triangle.size() - 1)
        return triangle[row][col];

    return triangle[row][col] + max(best_path_sum(triangle, row + 1, col), best_path_sum(triangle, row + 1, col + 1));
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    timer::time_point start = timer::now();

    vector<vector<numtype>> triangle = read_matrix<numtype>(project_path + "Problems/Problem18/input.txt");

    numtype result = best_path_sum(triangle);

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The the maximum total from top to bottom of given triangle is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}