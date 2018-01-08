//
// Created by Alex Beccaro on 07/01/18.
//

#include <iostream>
#include <primes.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using primes::prime_factors;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype FACTORS = 4;
    const numtype N = 4;

    timer::time_point start = timer::now();

    numtype result;
    numtype found = 0;

    for (numtype i = 1; found < N; i++)
        if (prime_factors(i).size() == FACTORS) {
            found++;
            if (found == N)
                result = i - N + 1;
        } else
            found = 0;

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The solution is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}