//
// Created by Alex Beccaro on 12/12/17.
//

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype NUMBERS = 100;

    timer::time_point start = timer::now();

    numtype sumOfSquares = 0, squareOfSum = 0;

    for (numtype i = 1; i <= NUMBERS; i++) {
        sumOfSquares += i * i;
        squareOfSum += i;
    }
    squareOfSum *= squareOfSum;

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is " << squareOfSum - sumOfSquares << endl;
    cout << "Calculation took " << time << " seconds" << endl;

    return 0;
}