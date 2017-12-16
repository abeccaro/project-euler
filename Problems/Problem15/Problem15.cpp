//
// Created by Alex Beccaro on 16/12/17.
//

#include <iostream>
#include "../../Utilities/GeneralUtilities.h"

using namespace std;
using namespace chrono;
using namespace general_utilities;

/**
 * Calculates the number of routes in a grid of width x height. It uses a matrix for memoization.
 * @param width The width of the grid
 * @param height The height of the grid
 * @param memory The matrix with already calculated routes numbers.
 * @return The number of routes
 */
unsigned long routes(const unsigned long width, const unsigned long height, vector<vector<unsigned long>>& memory) {
    if (width == 0 || height == 0)
        return 1;

    if (memory[width-1][height-1] != 0)
        return memory[width-1][height-1];

    unsigned long right = routes(width-1, height, memory);
    if (width > 1) {
        memory[width - 2][height - 1] = right;
        memory[height - 1][width - 2] = right;
    }
    unsigned long down = routes(width, height-1, memory);
    if (height > 1) {
        memory[width - 1][height - 2] = down;
        memory[height - 2][width - 1] = down;
    }

    return right + down;
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const unsigned long WIDTH = 20;
    const unsigned long HEIGHT = 20;

    high_resolution_clock::time_point start = high_resolution_clock::now();

//    unsigned long result = binomialCoefficient(WIDTH + HEIGHT, WIDTH); // overflow!

    unsigned long maxDim = max(WIDTH, HEIGHT);
    vector<vector<unsigned long>> memory(maxDim);
    for (auto &i : memory)
        i = vector<unsigned long>(maxDim);

    unsigned long result = routes(WIDTH, HEIGHT, memory);

    double time = duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000000.0;

    cout << "Through a " << WIDTH << "x" << HEIGHT << " grid there are " << result << " routes" << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}