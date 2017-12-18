//
// Created by Alex Beccaro on 11/12/17.
//

#include <iostream>
#include "primes.hpp"

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using primes::prime_factors;

using numtype = unsigned long;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype NUMBER = 600851475143;

    timer::time_point start = timer::now();

    numtype largestPrimeFactor = prime_factors(NUMBER).back();

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The largest prime factor of " << NUMBER << " is " << largestPrimeFactor << endl;
    cout << "Calculation took " << time << " seconds" << endl;

    return 0;
}