//
// Created by Alex Beccaro on 11/12/17.
//

#include <iostream>
#include <cmath>
#include "Primes.h"

using namespace std;

namespace primes {
    /*
     * Calculates all given number prime factors using division trial.
     */
    vector<int> primeFactors(long n) {
        vector<int> factors;

        if (n % 2 == 0)
            factors.push_back(2);

        for (int i = 3; i * i <= n; i = i+2) {
            if (n % i == 0)
                factors.push_back(i);
            while (n % i == 0)
                n /= i;
        }

        if (n > 2)
            factors.push_back(n);

        return factors;
    }

    /*
     * Generates n * (log n + log log n) primes (given by upper bounds on primes) and truncates result at n elements.
     */
    vector<int> primes(unsigned long n) {
        double upperBound = n * (log(n) + log(log(n)));
        vector<int> ps = primesUpTo(static_cast<unsigned long>(upperBound));
        ps.resize(n);
        return ps;
    }

    /*
     * Sieve of Eratosthenes implementation with some spatial optimisation.
     */
    vector<int> primesUpTo(unsigned long upperBound) {
        vector<bool> primesCheck(upperBound / 2, true);
        vector<int> primes;
        double root = sqrt(upperBound) / 2;

        // 2
        if (upperBound >= 2)
            primes.push_back(2);

        // setting false all multiples of primes
        for(int i = 1; i < root; i ++)
            if (primesCheck[i]) {
                int prime = i * 2 + 1;
                for (int multiple = prime * prime; multiple < upperBound; multiple += 2 * prime)
                    primesCheck[(multiple - 1) / 2] = false;
            }

        // adding primes to vector
        for (int i = 1; i < primesCheck.size(); i++)
            if (primesCheck[i])
                primes.push_back(2 * i + 1);

        return primes;
    }
}