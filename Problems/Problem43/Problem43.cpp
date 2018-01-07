//
// Created by Alex Beccaro on 07/01/18.
//

#include <iostream>
#include <vector>
#include <generics.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace generics;

using numtype = unsigned long;

/**
 * Checks divisibility properties required by problem
 * @param digs The ordered digits of pandigital number
 * @return True if it satisfies all properties, false otherwise
 */
bool has_required_properties(const vector<unsigned short>& digs) {
    if (digs[3] % 2 != 0)
        return false;

    if ((digs[2] + digs[3] + digs[4]) % 3 != 0)
        return false;

    if (digs[5] % 5 != 0)
        return false;

    vector<unsigned short> v1 = {digs[4], digs[5], digs[6]};
    if (from_digits<numtype>(v1) % 7 != 0)
        return false;

    if (abs(digs[6] - digs[5] - digs[7]) % 11 != 0)
        return false;

    v1 = {digs[6], digs[7], digs[8]};
    if (from_digits<numtype>(v1) % 13 != 0)
        return false;

    v1 = {digs[7], digs[8], digs[9]};
    if (from_digits<numtype>(v1) % 17 != 0)
        return false;

    return true;
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    timer::time_point start = timer::now();

    vector<unsigned short> pandigital = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    numtype result = 0;

    auto iterations = factorial<numtype>(10);
    for (numtype i = 0; i < iterations; i++) {
        next_permutation(pandigital.begin(), pandigital.end());

        if (pandigital[0] != 0 && has_required_properties(pandigital))
            result += from_digits<numtype>(pandigital);
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The sum of all 0 to 9 pandigital numbers with required properties is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}