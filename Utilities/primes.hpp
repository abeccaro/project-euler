//
// Created by Alex Beccaro on 11/12/17.
//
#ifndef PROJECT_EULER_PRIMES_UTILS_H
#define PROJECT_EULER_PRIMES_UTILS_H

#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
#include <generics.hpp>

using std::vector;
using namespace template_conditions;
using generics::divisors;

namespace primes {
    /**
     * Calculates all given number prime factors. It uses division trial.
     * Complexity: O(√n)
     * @param n The number
     * @return The vector of prime factors
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    vector<T> prime_factors(const T& n) {
        vector<T> factors;
        T copy(n);

        if (copy % 2 == 0)
            factors.emplace_back(2);

        for (T i = 3; i * i <= copy; i = i+2) {
            if (copy % i == 0)
                factors.emplace_back(i);
            while (copy % i == 0)
                copy /= i;
        }

        if (copy > 2)
            factors.push_back(copy);

        return factors;
    }

    /**
     * Generates the first n primes.
     * Complexity: O((n + log n + log log n) log log (n + log n + log log n))
     * @param n The number of primes to generate
     * @return The vector with the series
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    vector<T> primes(const T& n) {
        assert (n > 0 && "Number of primes must be positive");

        auto upper_bound = (T) (n * (log(n) + log(log(n))));
        vector<T> ps = primes_up_to(upper_bound);
        ps.resize(n);
        return ps;
    }

    /**
     * Generates primes up to number upperBound.
     * Complexity: O(n log log n)
     * @param upperBound The upper bound
     * @return The vector with the series
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    vector<T> primes_up_to(const T& upper_bound) {
        vector<bool> primes_check((ulong) (upper_bound / 2), true);
        vector<T> primes;

        if (upper_bound < 2)
            return primes;
        primes.emplace_back(2);

        auto root = sqrt(upper_bound) / 2;

        // setting false all multiples of primes
        for(ulong i = 1; i < root; i ++)
            if (primes_check[i]) {
                T prime = i * 2 + 1;
                for (T multiple = prime * prime; multiple < upper_bound; multiple += 2 * prime)
                    // FIXME: cast might be lossy! (very very high values)
                    primes_check[(ulong) ((multiple - 1) / 2)] = false;
            }

        // adding primes to vector
        for (ulong i = 1; i < primes_check.size(); i++)
            if (primes_check[i])
                primes.emplace_back(2 * i + 1);

        return primes;
    }

    /**
     * Checks if given number is prime.
     * @param n The number to check
     * @return True if given number is prime, false otherwise
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    bool is_prime(const T& n) {
        return divisors(n).size() == 2;
    }
}

#endif //PROJECT_EULER_PRIMES_UTILS_H