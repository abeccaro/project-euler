//
// Created by Alex Beccaro on 12/12/17.
//

#include <iostream>

using namespace std;
using namespace chrono;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const int NUMBERS = 100;

    high_resolution_clock::time_point start = high_resolution_clock::now();

    int sumOfSquares = 0, squareOfSum = 0;

    for (int i = 1; i <= NUMBERS; i++) {
        sumOfSquares += i * i;
        squareOfSum += i;
    }
    squareOfSum *= squareOfSum;

    double time = duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000000.0;

    cout << "The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is " << squareOfSum - sumOfSquares << endl;
    cout << "Calculation took " << time << " seconds" << endl;

    return 0;
}