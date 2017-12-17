//
// Created by Alex Beccaro on 17/12/17.
//

#include <iostream>
#include <generics.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace generics;

using numtype = cpp_int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype UPPER_BOUND = 1000;

    timer::time_point start = timer::now();

    numtype best_period = 0;
    numtype result = 1;
    for (numtype i = 2; i < UPPER_BOUND; i++) {
        if (areCoprime<numtype>(10, i)) {
            auto mo = multiplicative_order<numtype>(10, i);
            if (mo > best_period) {
                best_period = mo;
                result = i;
            }
        }
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part is "
         << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}