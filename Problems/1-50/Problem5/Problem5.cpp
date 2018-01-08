//
// Created by Alex Beccaro on 11/12/17.
//

#include <iostream>
#include <vector>
#include "generics.hpp"

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using generics::lcm;

using numtype = unsigned long;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype MAX_DIVISOR = 20;

    timer::time_point start = timer::now();

    vector<numtype> divisors;
    for (numtype i = MAX_DIVISOR; i >= 2; i--)
        divisors.push_back(i);
    numtype result = lcm(divisors);

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;

    return 0;
}