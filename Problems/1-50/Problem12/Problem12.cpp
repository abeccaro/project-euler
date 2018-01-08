//
// Created by Alex Beccaro on 12/12/17.
//

#include <iostream>
#include "series/figurate_number.hpp"
#include "generics.hpp"

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using series::figurate_number;
using generics::divisors;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype DIVISORS = 500;

    high_resolution_clock::time_point start = high_resolution_clock::now();

    figurate_number<numtype> triangles(3);
    numtype result = triangles.get_first([DIVISORS](numtype n) {
        unsigned long count = divisors(n).size();
        return count > DIVISORS;
    });

    double time = duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000000.0;

    cout << "The first triangular number to have more than " << DIVISORS << " divisors is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}