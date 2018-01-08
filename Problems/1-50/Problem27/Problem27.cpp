//
// Created by Alex Beccaro on 18/12/17.
//

#include <iostream>
#include <series/primes.hpp>
#include <primes.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using primes::is_prime;
using series::primes;

using numtype = int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype UPPER_BOUND = 1000;

    timer::time_point start = timer::now();

    primes<numtype> p;
    vector<numtype> primes = p.get_while([UPPER_BOUND](numtype n){return n <= UPPER_BOUND;});
    numtype max_primes = 0;
    numtype max_a, max_b;

    for (numtype a = -1000; a < UPPER_BOUND; a++)
        for (numtype b : primes) {
            numtype count = 0;

            for (numtype n = 0; is_prime(n * n + a * n + b); n++)
                count++;

            if (count > max_primes) {
                max_primes = count;
                max_a = a;
                max_b = b;
            }
        }

    numtype result = max_a * max_b;

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The product of the coefficients, a and b, for the quadratic expression that produces the maximum number "
         << "of primes for consecutive values of n is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}