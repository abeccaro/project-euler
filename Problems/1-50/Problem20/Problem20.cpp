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
    const numtype NUMBER = 100;

    timer::time_point start = timer::now();

    vector<unsigned int> dig = digits(factorial(NUMBER));

    numtype result = 0;
    for (const auto& d : dig)
        result += d;

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The sum of the digits of " << NUMBER << "! is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}