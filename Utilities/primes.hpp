//
// Created by Alex Beccaro on 11/12/17.
//
#ifndef PROJECT_EULER_PRIMES_UTILS_H
#define PROJECT_EULER_PRIMES_UTILS_H

#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using std::vector;
using boost::multiprecision::cpp_int;

namespace primes {
    /**
     * Calculates all given number prime factors. It uses division trial.
     * Complexity: O(√n)
     * @param n The number
     * @return The vector of prime factors
     */
    template<class T>
    vector<T> primeFactors(T n) {
        vector<T> factors;

        if (n % 2 == 0)
            factors.emplace_back(2);

        for (T i = 3; i * i <= n; i = i+2) {
            if (n % i == 0)
                factors.emplace_back(i);
            while (n % i == 0)
                n /= i;
        }

        if (n > 2)
            factors.push_back(n);

        return factors;
    }

    /**
     * Generates the first n primes.
     * Complexity: O((n + log n + log log n) log log (n + log n + log log n))
     * @param n The number of primes to generate
     * @return The vector with the series
     */
    template<class T>
    vector<T> primes(unsigned long n) {
        double upperBound = n * (log(n) + log(log(n)));
        vector<T> ps = primesUpTo((T) upperBound);
        ps.resize(n);
        return ps;
    }

    /**
     * Generates primes up to number upperBound.
     * Complexity: O(n log log n)
     * @param upperBound The upper bound
     * @return The vector with the series
     */
    template<class T>
    vector<T> primesUpTo(T upperBound) {
        vector<bool> primesCheck((unsigned long) (upperBound / 2), true);
        vector<T> primes;
        auto root = sqrt(upperBound) / 2;

        // 2
        if (upperBound >= 2)
            primes.emplace_back(2);

        // setting false all multiples of primes
        for(unsigned long i = 1; i < root; i ++)
            if (primesCheck[i]) {
                T prime = i * 2 + 1;
                for (T multiple = prime * prime; multiple < upperBound; multiple += 2 * prime)
                    primesCheck[(unsigned long) ((multiple - 1) / 2)] = false;
            }

        // adding primes to vector
        for (unsigned long i = 1; i < primesCheck.size(); i++)
            if (primesCheck[i])
                primes.emplace_back(2 * i + 1);

        return primes;
    }
}

#endif //PROJECT_EULER_PRIMES_UTILS_H