//
// Created by Alex Beccaro on 09/01/18.
//

#include <iostream>
#include <generics.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using generics::digits;
using boost::multiprecision::cpp_int;

using numtype = cpp_int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype EXPANSIONS = 1000;

    timer::time_point start = timer::now();

    numtype result = 0;
    numtype num = 1, den = 1;

    for (numtype i = 1; i < EXPANSIONS; i++) {
        numtype next_den = num + den;
        num += 2 * den;
        den = next_den;

        if (num.str().size() > den.str().size())
            result++;
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The number of fractions containing a numerator with more digits than denominator in √2 expansions is "
         << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}