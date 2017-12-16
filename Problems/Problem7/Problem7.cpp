//
// Created by Alex Beccaro on 12/12/17.
//

#include <iostream>
#include "series/primes.hpp"

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using series::primes;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype POSITION = 10001;

    timer::time_point start = timer::now();

    primes<numtype> p;
    numtype prime = p[POSITION-1];

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The " << POSITION << "th prime is " << prime << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}