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
using namespace boost::multiprecision;


///region miller-rabin implementation

/**
 * Calculates (base ^ exponent) mod modulo
 * @param base The base
 * @param exponent The exponent
 * @param modulo The modulo
 * @return The result
 */
template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
T modular_power(T base, T exponent, T modulo) {
    base %= modulo;
    T result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulo;
        base = (base * base) % modulo;
        exponent /= 2;
    }

    return result;
}

/**
 * Miller-Rabin determinist algorithm for primality check
 * @param n The number to check
 * @param witnesses The witnesses values to check
 * @return true if n is prime (using given witnesses), false otherwise
 */
template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
bool miller_rabin(const T& n, const vector<T>& witnesses) {
    unsigned int s = 0;
    T d = n - 1;
    while (d % 2 == 0) {
        s++;
        d /= 2;
    }
//    auto l = log((cpp_dec_float_100) n);
//    T max_witness = min<T>(n-1, (T) (2 * (l * l)));

    for (const auto& a : witnesses) {
        if (modular_power<T>(a, d, n) == 1)
            continue;

        bool composite = true;
        for (unsigned int r = 0; r < s; r++) {
            if (modular_power<T>(a, (T) pow(2, r) * d, n) == n - 1) {
                composite = false;
                break;
            }
        }

        if (composite)
            return false;
    }

    return true;
}

///endregion

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
     * Checks if given number is prime. Correct at least for any number up to 2^64.
     * @param n The number to check
     * @return True if given number is prime, false otherwise
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    bool is_prime(const T& n) {
        if (n < 2 || (n % 2 == 0 && n != 2) || (n % 3 == 0 && n != 3))
            return false;

        if (n <= 3)
            return true;

        if (n < 1373653)
            return miller_rabin(n, {2, 3});
        if (n < 4759123141)
            return miller_rabin(n, {2, 7, 61});
        if (n < 3071837692357849)
            return miller_rabin(n, {2, 75088, 642735, 203659041, (T) 3613982119});
        return miller_rabin(n, {2, 325, 9375, 28178, 450775, 9780504, (T) 1795265022});
    }
}

#endif //PROJECT_EULER_PRIMES_UTILS_H