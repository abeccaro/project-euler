//
// Created by Alex Beccaro on 11/12/17.
//
#ifndef PROJECT_EULER_PRIMES_H
#define PROJECT_EULER_PRIMES_H

#endif //PROJECT_EULER_PRIMES_H

#include <vector>

using namespace std;

namespace primes {
    /**
     * Calculates all given number prime factors.
     * Complexity: O(√n)
     * @param n The number
     * @return The vector of prime factors
     */
    vector<int> primeFactors(long n);

    /**
     * Generates the first n primes.
     * Complexity: O((n + log n + log log n) log log (n + log n + log log n))
     * @param n The number of primes to generate
     * @return The vector with the series
     */
    vector<int> primes(unsigned long n);

    /**
     * Generates primes up to number upperBound.
     * Complexity: O(n log log n)
     * @param upperBound The upper bound
     * @return The vector with the series
     */
    vector<int> primesUpTo(unsigned long upperBound);
}
