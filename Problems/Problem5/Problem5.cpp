//
// Created by Alex Beccaro on 11/12/17.
//

#include <iostream>
#include <vector>
#include "../../Utilities/GeneralUtilities.h"

using namespace std;
using namespace chrono;
using namespace general_utilities;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const int MAX_DIVISOR = 20;

    high_resolution_clock::time_point start = high_resolution_clock::now();

    vector<unsigned long> divisors;
    for (int i = MAX_DIVISOR; i >= 2; i--)
        divisors.push_back(i);
    long result = lcm(divisors);

    double time = duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000000.0;

    cout << "The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;

    return 0;
}