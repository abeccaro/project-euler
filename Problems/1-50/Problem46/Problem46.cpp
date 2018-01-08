//
// Created by Alex Beccaro on 07/01/18.
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
    timer::time_point start = timer::now();

    primes<numtype> p;
    numtype result;

    for (numtype i = 9; result == 0; i += 2)
        if (!is_prime(i)) {
            vector<numtype> primes = p.get_while([i](numtype n){return n < i;});
            bool found = false;

            for (numtype prime: primes) {
                numtype x = (i - prime) / 2;
                auto root = sqrt(x);
                if (root == (numtype) root) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                result = i;
                break;
            }
        }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The solution is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}