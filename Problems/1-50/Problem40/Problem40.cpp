//
// Created by Alex Beccaro on 05/01/18.
//

#include <iostream>
#include <vector>
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
    timer::time_point start = timer::now();

    vector<unsigned int> d;

    for (numtype i = 1; d.size() < 1000000; i++) {
        vector<unsigned int> digs = digits(i);
        d.insert(d.end(), digs.begin(), digs.end());
    }

    numtype result = d[0] * d[9] * d[99] * d[999] * d[9999] * d[99999] * d[999999];

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The product of requested digits is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}