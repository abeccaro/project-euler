//
// Created by Alex Beccaro on 19/12/17.
//

#include <iostream>
#include <generics.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace generics;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype UPPER_BOUND = 2177280;

    timer::time_point start = timer::now();

    numtype result = 0;
    vector<numtype> factorials(10);

    for (numtype i = 0; i < 10; i++)
        factorials[i] = factorial(i);

    for (numtype i = 10; i < UPPER_BOUND; i++) {
        numtype sum = 0;
        vector<unsigned int> digs = digits(i);

        for (const auto& digit : digs)
            sum += factorials[digit];

        if (sum == i)
            result += i;
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The sum of all numbers which are equal to the sum of the factorial of their digits is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}