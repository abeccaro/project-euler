//
// Created by Alex Beccaro on 19/12/17.
//

#include <iostream>
#include <generics.hpp>
#include <series/primes.hpp>
#include <primes.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace generics;
using primes::is_prime;
using series::primes;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype UPPER_BOUND = 1000000;

    timer::time_point start = timer::now();

    primes<numtype> p;
    vector<numtype> primes = p.get_while([UPPER_BOUND](numtype n){return n < UPPER_BOUND;});

    numtype result = 0;
    for (const auto& prime : primes) {
        vector<numtype> rots = rotations(prime);

        if (all_of(rots.begin() + 1, rots.end(), [](numtype n){return is_prime(n);}))
            result++;
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The number of circular primes below " << UPPER_BOUND << " is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}