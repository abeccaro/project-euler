//
// Created by Alex Beccaro on 12/12/17.
//

#include <iostream>
#include "../../Utilities/Series.h"

using namespace std;
using namespace chrono;
using namespace series;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const int UPPER_BOUND = 2000000;

    high_resolution_clock::time_point start = high_resolution_clock::now();

    vector<int> primes = primesUpTo(UPPER_BOUND);
    long sum = 0;
    for (int p : primes)
        sum += p;

    double time = duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000000.0;

    cout << "The sum of all the primes below two million is " << sum << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}