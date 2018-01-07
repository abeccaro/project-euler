//
// Created by Alex Beccaro on 07/01/18.
//

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using boost::multiprecision::cpp_int;

using numtype = cpp_int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const unsigned int EXPONENT_UB = 1000;

    timer::time_point start = timer::now();

    numtype result = 1;

    for (unsigned int i = 2; i <= EXPONENT_UB; i++)
        result += pow((numtype) i, i);

    result %= 10000000000;

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The last 10 digits of the series is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}