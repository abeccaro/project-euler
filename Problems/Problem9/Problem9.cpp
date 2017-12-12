//
// Created by Alex Beccaro on 12/12/17.
//

#include <iostream>

using namespace std;
using namespace chrono;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const int SUM = 1000;

    high_resolution_clock::time_point start = high_resolution_clock::now();

    int product = 0;
    for (int a = 1; a <= SUM / 3; a++) {
        for (int b = a + 1; b < SUM / 2; b++) {
            int c = SUM - a - b;
            if (a * a + b * b == c * c)
                product = a * b * c;
        }
    }

    double time = duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000000.0;

    cout << "The product of the Pythagorean triplet for which a + b + c = 1000 is " << product << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}