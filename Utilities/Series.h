//
// Created by Alex Beccaro on 11/12/17.
//

#include <vector>

using namespace std;

namespace series {
    /**
     * Generates n terms of the fibonacci series.
     * @param n The number of terms to generate
     * @return The vector with the series
     */
    vector<int> fibonacci(unsigned long n);

    /**
     * Generates fibonacci series up to number upperBound.
     * @param upperBound The upper bound
     * @return The vector with the series
     */
    vector<int> fibonacciUpTo(unsigned long upperBound);

    /**
     * Generates the first n primes.
     * @param n The number of primes to generate
     * @return The vector with the series
     */
    vector<int> primes(unsigned long n);

    /**
     * Generates primes up to number upperBound.
     * @param upperBound The upper bound
     * @return The vector with the series
     */
    vector<int> primesUpTo(unsigned long upperBound);
};
