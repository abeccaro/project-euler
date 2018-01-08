//
// Created by Alex Beccaro on 08/01/18.
//

#include <iostream>
#include <primes.hpp>
#include <series/primes.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using primes::is_prime;
using series::primes;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype UPPER_BUOND = 1000000;

    timer::time_point start = timer::now();

    primes<numtype> p;
    numtype result;
    numtype max_n_primes = 0, max_sum = 0;

    for (auto i = p.begin(); result == 0; i++) {
        numtype sum = *i;
        numtype n_primes = 1;

        for (auto j = i+1; sum + *j < UPPER_BUOND; j++) {
            sum += *j;
            n_primes++;

            if (n_primes > max_n_primes && is_prime(sum)) {
                max_sum = sum;
                max_n_primes = n_primes;
            }
        }

        if (n_primes < max_n_primes) {
            result = max_sum;
            break;
        }

        if (is_prime(sum)) {
            max_n_primes = n_primes;
            result = sum;
        }
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The prime below " << UPPER_BUOND << " that can be written as the sum of the most consecutive primes is "
         << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}