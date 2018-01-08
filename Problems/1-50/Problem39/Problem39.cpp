//
// Created by Alex Beccaro on 05/01/18.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype UPPER_BOUND = 1000;

    const numtype A_BOUND = UPPER_BOUND / 3;

    timer::time_point start = timer::now();

    vector<numtype> counts(UPPER_BOUND - 2); // no possible triangles for 0, 1 and 2.

    for (numtype a = 1; a <= A_BOUND; a++) {
        numtype B_BOUND = (UPPER_BOUND - a) / 2;
        for (numtype b = a; b <= B_BOUND; b++) {
            numtype c_squared = a * a + b * b;
            auto c = (numtype) sqrt(c_squared);
            if (c * c == c_squared) { // if it is right angle triangle
                numtype p = a + b + c;

                if (p <= 1000)
                    counts[p-3]++;
            }
        }
    }

    numtype result = (numtype) distance(counts.begin(), max_element(counts.begin(), counts.end())) + 3;

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The perimeter with most right angle triangles under " << UPPER_BOUND << " is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}