//
// Created by Alex Beccaro on 17/12/17.
//

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <generics.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace boost::multiprecision;
using generics::digits;

using numtype = cpp_int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype BASE = 2;
    const unsigned int POWER = 1000;

    timer::time_point start = timer::now();

    vector<unsigned short> dig = digits<numtype>(pow(BASE, POWER));

    numtype result = 0;
    for (auto n : dig)
        result += n;

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The solution is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}