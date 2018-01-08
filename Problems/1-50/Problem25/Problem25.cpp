//
// Created by Alex Beccaro on 17/12/17.
//

#include <iostream>
#include <series/fibonacci.hpp>
#include <generics.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using boost::multiprecision::cpp_int;
using series::fibonacci;

using numtype = cpp_int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype DIGITS = 1000;

    timer::time_point start = timer::now();

    fibonacci<numtype> f;
    f.get_first([DIGITS](numtype n){return n.str().size() >= 1000;});
    numtype result = f.size();

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The index of the first fibonacci number to have over " << DIGITS << " digits is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}