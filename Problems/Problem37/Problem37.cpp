//
// Created by Alex Beccaro on 03/01/18.
//

#include <iostream>
#include <series/primes.hpp>
#include <primes.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using primes::is_prime;
using series::primes;
using namespace generics;

using numtype = unsigned int;


bool is_truncatable_from_left(const numtype& n) {
    vector<unsigned short> digs = digits(n);

    while (digs.size() > 1) {
        if (!is_prime(from_digits<numtype>(digs)))
            return false;
        digs.erase(digs.begin());
    }

    return is_prime(digs[0]);
}

bool is_truncatable_from_right(const numtype& n) {
    numtype copy = n;

    while (copy >= 10) {
        if (!is_prime(copy))
            return false;
        copy = copy / 10;
    }

    return is_prime(copy);
}

bool is_truncatable_from_both_sides(const numtype& n) {
    return is_truncatable_from_left(n) && is_truncatable_from_right(n);
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype N = 11; // # of numbers to find

    timer::time_point start = timer::now();

    primes<numtype> p;
    vector<numtype> numbers = p.get(N, [](numtype n){return n >= 10 && is_truncatable_from_both_sides(n);});

    numtype result = 0;
    for (numtype n : numbers)
        result += n;

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The sum of the only eleven primes that are both truncatable from left to right and right to left is "
         << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}