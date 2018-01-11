//
// Created by Alex Beccaro on 12/12/17.
//

#include <iostream>
#include <series/primes.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using series::primes;

using numtype = unsigned long;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype UPPER_BOUND = 2000000;

    timer::time_point start = timer::now();

    primes<numtype> p;
    vector<numtype> primes = p.get_while([UPPER_BOUND](numtype n) { return n <= UPPER_BOUND; });
    numtype sum = 0;
    for (const auto& prime : primes)
        sum += prime;

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The sum of all the primes below " << UPPER_BOUND << " is " << sum << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}