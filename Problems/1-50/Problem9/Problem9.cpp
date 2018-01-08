//
// Created by Alex Beccaro on 12/12/17.
//

#include <iostream>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype SUM = 1000;

    timer::time_point start = timer::now();

    numtype product = 0;
    for (numtype a = 1; a <= SUM / 3; a++) {
        for (numtype b = a + 1; b < SUM / 2; b++) {
            numtype c = SUM - a - b;
            if (a * a + b * b == c * c)
                product = a * b * c;
        }
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The product of the Pythagorean triplet for which a + b + c = 1000 is " << product << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}