//
// Created by Alex Beccaro on 07/01/18.
//

#include <iostream>
#include <series/figurate_number.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using series::figurate_number;

using numtype = unsigned long;

/**
 * Checks if given number is pentagonal
 * @param n The number to check
 * @return True if n is pentagonal, false otherwise
 */
bool is_pentagonal(numtype n) {
    auto x = (sqrt(24 * n + 1) + 1) / 6;

    return (numtype) x == x;
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {

    timer::time_point start = timer::now();

    figurate_number<numtype> hexagonals(6);
    numtype result;
    numtype n = 2; // numbers to find

    for (auto i = hexagonals.begin(); i < hexagonals.end(); i++)
        if (is_pentagonal(*i)) { // all hexagonal numbers are also triangular numbers
            if (n == 0) {
                result = *i;
                break;
            } else
                n--;
        }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The second number that is triangular, pentagonal and hexagonal is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}