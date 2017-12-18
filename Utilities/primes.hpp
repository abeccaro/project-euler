//
// Created by Alex Beccaro on 11/12/17.
//
#ifndef PROJECT_EULER_PRIMES_UTILS_H
#define PROJECT_EULER_PRIMES_UTILS_H

#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
#include <generics.hpp>

using std::vector;
using boost::multiprecision::cpp_int;
using generics::divisors;

namespace primes {
    /**
     * Calculates all given number prime factors. It uses division trial.
     * Complexity: O(√n)
     * @param n The number
     * @return The vector of prime factors
     */
    template<class T>
    vector<T> prime_factors(T n) {
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
        double upper_bound = n * (log(n) + log(log(n)));
        vector<T> ps = primes_up_to((T) upper_bound);
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
    vector<T> primes_up_to(T upper_bound) {
        vector<bool> primes_check((unsigned long) (upper_bound / 2), true);
        vector<T> primes;
        auto root = sqrt(upper_bound) / 2;

        // 2
        if (upper_bound >= 2)
            primes.emplace_back(2);

        // setting false all multiples of primes
        for(unsigned long i = 1; i < root; i ++)
            if (primes_check[i]) {
                T prime = i * 2 + 1;
                for (T multiple = prime * prime; multiple < upper_bound; multiple += 2 * prime)
                    primes_check[(unsigned long) ((multiple - 1) / 2)] = false;
            }

        // adding primes to vector
        for (unsigned long i = 1; i < primes_check.size(); i++)
            if (primes_check[i])
                primes.emplace_back(2 * i + 1);

        return primes;
    }

    /**
     * Checks if given number is prime.
     * @param n The number to check
     * @return True if given number is prime, false otherwise
     */
    template<class T>
    bool is_prime(T n) {
        return divisors(n).size() == 2;
    }
}

#endif //PROJECT_EULER_PRIMES_UTILS_H