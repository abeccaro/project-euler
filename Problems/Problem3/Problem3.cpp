//
// Created by Alex Beccaro on 11/12/17.
//

#include <iostream>
#include "../../Utilities/Primes.h"

using namespace std;
using namespace chrono;
using namespace primes;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const long NUMBER = 600851475143;

    high_resolution_clock::time_point start = high_resolution_clock::now();

    int largestPrimeFactor = primeFactors(NUMBER).back();

    double time = duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000000.0;

    cout << "The largest prime factor of " << NUMBER << " is " << largestPrimeFactor << endl;
    cout << "Calculation took " << time << " seconds" << endl;

    return 0;
}