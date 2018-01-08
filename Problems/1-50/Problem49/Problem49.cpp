//
// Created by Alex Beccaro on 07/01/18.
//

#include <iostream>
#include <sstream>
#include <series/primes.hpp>
#include <generics.hpp>
#include <primes.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using primes::is_prime;
using series::primes;
using namespace generics;

using numtype = int;

/**
 * Finds all permutations of given number that are prime
 * @param prime The number. It is supposed to be a prime with 4 digits
 * @return The vector of permutations that are prime
 */
vector<numtype> permutation_primes(const numtype& prime) {
    vector<numtype> perm_primes(1, prime);
    auto prime_digs = digits(prime);

    for (numtype i = 1; i < 24; i++) { // 24 = 4! (the number of permutations)
        next_permutation(prime_digs.begin(), prime_digs.end());
        auto perm_n = from_digits<numtype>(prime_digs);
        if (is_prime(perm_n) && find(perm_primes.begin(), perm_primes.end(), perm_n) == perm_primes.end())
            perm_primes.push_back(perm_n);
    }

    return perm_primes;
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype EXCEPT = 1487; // prime not to consider (it's in the example)

    timer::time_point start = timer::now();

    stringstream ss;
    primes<numtype> p;
    vector<numtype> primes_4_digs = p.get_while([](numtype n){return n < 10000;}, [](numtype n){return n > 999;});

    string result;

    for (numtype prime : primes_4_digs) {
        vector<numtype> perm_primes = permutation_primes(prime);

        if (perm_primes.size() >= 3 && prime != EXCEPT)
            for (auto i = perm_primes.begin() + 1; i < perm_primes.end(); i++) {
                numtype diff = *i - prime; // *i is second element in the triple
                numtype next = *i + diff; // next is eventual third element
                if (diff > 0 && find(perm_primes.begin(), perm_primes.end(), next) != perm_primes.end()) {
                    ss << prime;
                    ss << *i;
                    ss << next;
                    result = ss.str();
                    break;
                }
            }

        if (!result.empty())
            break;
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The 12-digit number obtained by concatenating the three terms in required sequence is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}