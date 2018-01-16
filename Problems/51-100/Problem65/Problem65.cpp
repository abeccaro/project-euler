//
// Created by Alex Beccaro on 14/01/18.
//

#include <iostream>
#include <cmath>
#include <vector>
#include "fraction.hpp"

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace fractions;

using numtype = uint512_t;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype N = 100;

    timer::time_point start = timer::now();

    fraction<numtype>::set_auto_reduce(false);
    fraction<numtype> convergent = 1; // general formula: N % 3 == 0 ? 2 * N / 3 : 1
    for (numtype i = N - 1; i > 1; i--) {
        convergent.invert();
        if (i % 3 == 0)
            convergent += 2 * i / 3;
        else
            convergent += 1;
    }
    convergent.invert();
    convergent += (numtype) 2;
    fraction<numtype>::set_auto_reduce(true);

    numtype result = 0;
    vector<unsigned int> digs = digits(convergent.get_numerator());
    for (const auto& d : digs)
        result += d;

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The the sum of digits in the numerator of the 100th convergent of the continued fraction for e is "
         << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}