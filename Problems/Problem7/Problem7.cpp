//
// Created by Alex Beccaro on 12/12/17.
//

#include <iostream>
#include "../../Utilities/Series/Primes.h"

using namespace std;
using namespace chrono;
using namespace series;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const int POSITION = 10001;

    high_resolution_clock::time_point start = high_resolution_clock::now();

    Primes p;
    long prime = p[POSITION-1];

    double time = duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000000.0;

    cout << "The " << POSITION << "th prime is " << prime << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}