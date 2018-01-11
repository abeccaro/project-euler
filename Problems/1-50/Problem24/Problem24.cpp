//
// Created by Alex Beccaro on 17/12/17.
//

#include <iostream>
#include <vector>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype PERMUTATION = 1000000;

    timer::time_point start = timer::now();

    vector<numtype> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (numtype i = 1; i < PERMUTATION; i++)
        next_permutation(digits.begin(), digits.end());

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The " << PERMUTATION << "th permutation in lexicographic order is ";
    for (const auto& d : digits)
        cout << d;
    cout << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}