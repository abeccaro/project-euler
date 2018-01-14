//
// Created by Alex Beccaro on 14/01/18.
//

#include <iostream>
#include <generics.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using generics::digits;

using numtype = uint128_t;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    // bounds for numbers to check:
    // 10^x will always have x+1 digits so bases range is [1,9]
    // log_10(9^x) + 1 = x gives 21.8... so the maximum exponent to check is 21
    const numtype MAX_BASE = 9;
    const numtype MAX_EXP = 21;

    timer::time_point start = timer::now();

    numtype result = 0;

    for (numtype b = 1; b <= MAX_BASE; b++) {
        numtype n = 1;
        for (numtype e = 1; e <= MAX_EXP; e++) {
            n *= b;
            if (digits(n).size() == e)
                result++;
        }
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The solution is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}