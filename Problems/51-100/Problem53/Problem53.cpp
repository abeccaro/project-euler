//
// Created by Alex Beccaro on 09/01/18.
//

#include <iostream>
#include <generics.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using generics::binomial_coefficient;
using boost::multiprecision::cpp_int;

using numtype = cpp_int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype THRESHOLD = 1000000;
    const numtype UPPER_BOUND = 100;

    timer::time_point start = timer::now();

    numtype result = 0;

    for (numtype n = 1; n <= UPPER_BOUND; n++)
        for (numtype r = 1; r <= n; r++)
            if (binomial_coefficient(n, r) > THRESHOLD)
                result++;

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The number of values of nCr over " << THRESHOLD << " for n ≤ " << UPPER_BOUND << " is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}