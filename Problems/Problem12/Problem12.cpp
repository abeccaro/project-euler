//
// Created by Alex Beccaro on 12/12/17.
//

#include <iostream>
#include "../../Utilities/Series/FigurateNumber.h"
#include "../../Utilities/GeneralUtilities.h"

using namespace std;
using namespace chrono;
using namespace series;
using namespace general_utilities;

/**
 * Checks if given number has more than 500 divisors
 * @param n The number to check
 * @return True if n has more than 500 divisors, false otherwise
 */
bool hasDivisors(unsigned long n) {
    const unsigned long DIVISORS = 500;

    unsigned long count = divisors(n).size();
    return count > DIVISORS;
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    high_resolution_clock::time_point start = high_resolution_clock::now();

    FigurateNumber triangles(3);
    unsigned long result = triangles.getFirst(hasDivisors);

    double time = duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000000.0;

    cout << "The solution is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}