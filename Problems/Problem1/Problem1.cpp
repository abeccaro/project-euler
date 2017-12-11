//
// Created by Alex Beccaro on 11/12/17.
//

#include <iostream>

using namespace std;
using namespace chrono;

/**
 * Calculates the sum of all multiples of given number below given upperBound.
 * @param n The number
 * @param upperBound The upper bound
 * @return The sum of multiples
 */
int multiplesSum(int n, int upperBound) {
    int sum = 0;

    for (int i = 1; n * i < upperBound; i++)
        sum += n * i;

    return sum;
}

/**
 * Specifies values, solves problem and outputs solution and execution time.
 * @return The exit code
 */
int main() {
    const int N1 = 3;
    const int N2 = 5;
    const int UPPER_BOUND = 1000;

    high_resolution_clock::time_point start = high_resolution_clock::now();

    int result = multiplesSum(N1, UPPER_BOUND) + multiplesSum(N2, UPPER_BOUND) - multiplesSum(N1 * N2, UPPER_BOUND);
    
    double time = duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000000.0;

    cout << "The sum of all multiples of 3 and multiples of 5 below 1000 is "<< result << endl;
    cout << "Calculation took " << time << " seconds" << endl;

    return 0;
}