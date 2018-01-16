//
// Created by Alex Beccaro on 16/01/18.
//

#include <iostream>
#include <fraction.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace fractions;

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
        vector<numtype> period;

        auto a = (numtype) sqrt(n);
        numtype a_0 = a;
        numtype m = 0;
        numtype d = 1;

        if (a * a == n) // perfect square
            continue;

        // calculate period
        do {
            m = d * a - m;
            d = (n - m * m) / d;
            a = (a_0 + m) / d;

            period.push_back(a);
        } while(period.back() != a_0 * 2);

        // calculate convergents until it finds one that's a solution
        fraction<numtype>::set_auto_reduce(false);
        for (ulong i = 1; ; i++) {
            fraction<numtype> convergent(period[(i-1) % period.size()]);

            for (ulong j = i - 1; j > 0; j--) {
                convergent.invert();
                convergent += period[(j-1) % period.size()];
            }
            convergent.invert();
            convergent += a_0;

            numtype x = convergent.get_numerator();
            numtype y = convergent.get_denominator();
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