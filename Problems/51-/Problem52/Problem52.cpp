//
// Created by Alex Beccaro on 09/01/18.
//

#include <iostream>
#include <generics.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using generics::digits;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype MULTIPLES = 6;

    timer::time_point start = timer::now();

    numtype result = 0;

    for (numtype i = 1; result == 0; i++) {
        auto digs = digits(i);
        sort(digs.begin(), digs.end());
        bool ok = true;

        for (numtype j = 2; j <= MULTIPLES; j++) {
            auto multiple_digs = digits(i*j);
            sort (multiple_digs.begin(), multiple_digs.end());

            if (digs != multiple_digs) {
                ok = false;
                break;
            }
        }

        if (ok)
            result = i;
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits is "
         << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}