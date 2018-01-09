//
// Created by Alex Beccaro on 09/01/18.
//

#include <iostream>
#include <primes.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using primes::is_prime;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype THRESHOLD = 10;

    timer::time_point start = timer::now();

    numtype result = 0;

    for (numtype side = 3, primes = 0, last = 1; result == 0; side += 2) {
        numtype increment = side - 1;
        numtype n1 = last + increment;
        numtype n2 = n1 + increment;
        numtype n3 = n2 + increment;
        last = n3 + increment;

        if (is_prime(n1))
            primes++;
        if (is_prime(n2))
            primes++;
        if (is_prime(n3))
            primes++;

        if (100 * primes / (2 * side - 1) < THRESHOLD)
            result = side;
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The side length of the square spiral for which the ratio of primes along both diagonals first falls below "
         << THRESHOLD << "% is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}