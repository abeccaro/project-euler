//
// Created by Alex Beccaro on 12/12/17.
//

#include <iostream>
#include <limits>
#include "../../Utilities/InputUtilities.h"

using namespace std;
using namespace chrono;
using namespace input_utilities;

/**
 * Calculates max product of 'length' adjacent numbers in given vector.
 * @param vector The vector
 * @param length The number of terms in the products
 * @return The maximum product
 */
long maxProductOfAdjacent(const vector<int> &vector, const int length) {
    long maxProduct = numeric_limits<long>::min();
    for (int i = 0; i <= vector.size() - length; i++) {
        long product = 1;
        for (int j = 0; j < length; j++)
            product *= vector[i+j];
        if (product > maxProduct)
            maxProduct = product;
    }
    return maxProduct;
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const int DIGITS = 13;

    high_resolution_clock::time_point start = high_resolution_clock::now();

    vector<int> digits = readInts(projectPath + "Problems/Problem8/input.txt");
    long product = maxProductOfAdjacent(digits, DIGITS);

    double time = duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000000.0;

    cout << "The solution is " << product << endl;
    cout << "Calculation took " << time << " seconds" << endl;

    return 0;
}