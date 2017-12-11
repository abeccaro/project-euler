//
// Created by Alex Beccaro on 11/12/17.
//

#include <iostream>
#include <vector>
#include "../../Utilities/Series.h"

using namespace std;
using namespace chrono;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const int UPPER_BOUND = 4000000;

    high_resolution_clock::time_point start = high_resolution_clock::now();

    vector<int> fibonacci = series::fibonacciUpTo(UPPER_BOUND);
    long sum = 0;
    for (int f : fibonacci)
        if (f % 2 == 0)
            sum += f;

    double time = duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000000.0;

    cout << "The sum of all even fibonacci numbers up to 4 million is " << sum << endl;
    cout << "Calculation took " << time << " seconds" << endl;

    return 0;
}