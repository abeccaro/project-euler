//
// Created by Alex Beccaro on 07/01/18.
//

#include <iostream>
#include <vector>
#include <generics.hpp>
#include <primes.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace generics;
using primes::is_prime;

using numtype = unsigned long;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    vector<unsigned short> ALL_DIGITS = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    timer::time_point start = timer::now();

    numtype result;

    // 9,8,6,5,3,2 -digit pandigitals cannot be primes (always dividable by 3)
    // so only 7,4,1 -digit numbers are tested
    for (unsigned short n = 7; n > 0; n -= 3) {
        vector<unsigned short> permutation(n);
        copy(ALL_DIGITS.begin(), ALL_DIGITS.begin() + n, permutation.begin());

        numtype max = 0;

        numtype permutations = factorial(n);
        for (numtype i = 0; i < permutations; i++) {
            next_permutation(permutation.begin(), permutation.end());
            auto number = from_digits<numtype>(permutation);

            if (is_prime(number) && number > max)
                max = number;
        }

        if (max != 0) {
            result = max;
            break;
        }
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The largest pandigital prime is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}