//
// Created by Alex Beccaro on 12/12/17.
//

#include <iostream>
#include "input.hpp"

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace input;

using numtype = unsigned long;

/**
 * Calculates max product of 'length' adjacent numbers in given vector.
 * @param vector The vector
 * @param length The number of terms in the products
 * @return The maximum product
 */
numtype maxProductOfAdjacent(const vector<numtype> &vector, const numtype length) {
    numtype maxProduct = numeric_limits<numtype>::min();
    for (int i = 0; i <= vector.size() - length; i++) {
        numtype product = 1;
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
    const numtype DIGITS = 13;

    timer::time_point start = timer::now();

    vector<numtype> digits = read_vector<numtype>(projectPath + "Problems/Problem8/input.txt");
    numtype product = maxProductOfAdjacent(digits, DIGITS);

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The solution is " << product << endl;
    cout << "Calculation took " << time << " seconds" << endl;

    return 0;
}