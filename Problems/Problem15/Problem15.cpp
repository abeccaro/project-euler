//
// Created by Alex Beccaro on 16/12/17.
//

#include <iostream>
#include "generics.hpp"

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using generics::binomial_coefficient;

using numtype = cpp_int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype WIDTH = 20;
    const numtype HEIGHT = 20;

    timer::time_point start = timer::now();

    numtype result = binomial_coefficient<numtype>(WIDTH + HEIGHT, WIDTH);

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "Through a " << WIDTH << "x" << HEIGHT << " grid there are " << result << " routes" << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}