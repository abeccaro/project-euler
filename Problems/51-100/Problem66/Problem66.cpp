//
// Created by Alex Beccaro on 16/01/18.
//

#include <iostream>
#include <fraction.hpp>
#include <series/sqrt_convergents.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace fractions;
using series::sqrt_convergents;

using numtype = uint256_t;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype UPPER_BOUND = 1000;

    timer::time_point start = timer::now();

    numtype result = 0;
    numtype max_x = 0;

    for (numtype n = 2; n <= UPPER_BOUND; n++) {
        auto root = (numtype) sqrt(n);
        if (root * root == n) // perfect square
            continue;

        sqrt_convergents<numtype> c(n);

        for (auto j = c.begin(); j < c.end(); j++) {
            numtype x = j->get_numerator();
            numtype y = j->get_denominator();

            if (x * x - (n * y * y) == 1) {
                if (x > max_x) {
                    max_x = x;
                    result = n;
                }
                break;
            }
        }
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The solution is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}