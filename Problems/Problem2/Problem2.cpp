//
// Created by Alex Beccaro on 11/12/17.
//

#include <iostream>
#include <vector>
#include "../../Utilities/Series/Fibonacci.h"

using namespace std;
using namespace chrono;
using namespace series;

/**
 * Checks if given number is even.
 * @param n The number to check
 * @return True if n is even, false otherwise
 */
bool isEven(unsigned long n) {
    return n % 2 == 0;
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const int UPPER_BOUND = 4000000;

    high_resolution_clock::time_point start = high_resolution_clock::now();

    Fibonacci fib;
    vector<unsigned long> fibonacci = fib.getUpTo(UPPER_BOUND, isEven);
    long sum = 0;
    for (unsigned long f : fibonacci)
        sum += f;

    double time = duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000000.0;

    cout << "The sum of all even fibonacci numbers up to 4 million is " << sum << endl;
    cout << "Calculation took " << time << " seconds" << endl;

    return 0;
}