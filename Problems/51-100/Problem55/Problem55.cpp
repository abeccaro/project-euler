//
// Created by Alex Beccaro on 09/01/18.
//

#include <iostream>
#include <generics.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace generics;

using numtype = unsigned long;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype UPPER_BOUND = 10000;
    const numtype MAX_ITERATIONS = 50;

    timer::time_point start = timer::now();

    numtype result = UPPER_BOUND - 1;

    for (numtype i = 1; i < UPPER_BOUND; i++) {
        numtype n = i;
        bool lychrel = true;
        for (numtype j = 0; j < MAX_ITERATIONS; j++) {
            auto digs = digits(n);
            reverse(digs.begin(), digs.end());
            n = n + from_digits<numtype>(digs);
            if (is_palindrome(n)) {
                result--;
                break;
            }
        }
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The number of lychrel numbers below " << UPPER_BOUND << " is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}