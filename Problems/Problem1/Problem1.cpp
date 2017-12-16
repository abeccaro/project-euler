//
// Created by Alex Beccaro on 11/12/17.
//

#include <iostream>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;

using numtype = unsigned int;

/**
 * Calculates the sum of all multiples of given number below given upperBound.
 * @param n The number
 * @param upperBound The upper bound
 * @return The sum of multiples
 */
numtype multiplesSum(numtype n, numtype upperBound) {
    numtype sum = 0;

    for (numtype i = 1; n * i < upperBound; i++)
        sum += n * i;

    return sum;
}

/**
 * Specifies values, solves problem and outputs solution and execution time.
 * @return The exit code
 */
int main() {
    const numtype N1 = 3;
    const numtype N2 = 5;
    const numtype UPPER_BOUND = 1000;

    timer::time_point start = timer::now();

    numtype result = multiplesSum(N1, UPPER_BOUND) + multiplesSum(N2, UPPER_BOUND) - multiplesSum(N1 * N2, UPPER_BOUND);
    
    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The sum of all multiples of 3 and multiples of 5 below 1000 is "<< result << endl;
    cout << "Calculation took " << time << " seconds" << endl;

    return 0;
}