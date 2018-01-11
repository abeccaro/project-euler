//
// Created by Alex Beccaro on 09/01/18.
//

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <generics.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using boost::multiprecision::cpp_int;
using generics::digits;

using numtype = cpp_int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype BASE_UB = 100;
    const numtype EXPONENT_UB = 100;

    timer::time_point start = timer::now();

    numtype result = 0;

    for (numtype a = 1; a < BASE_UB; a++) {
        numtype n = 1;
        for (unsigned long b = 1; b < EXPONENT_UB; b++) {
            n *= a;
            auto digs = digits(n);

            numtype sum = 0;
            for (const auto& d : digs)
                sum += d;

            if (sum > result)
                result = sum;
        }
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The maximum digital sum of powers a^b for a < " << BASE_UB << ", b < " << EXPONENT_UB << " is "
         << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}