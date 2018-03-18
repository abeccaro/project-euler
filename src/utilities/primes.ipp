//
// Created by Alex Beccaro on 16/03/18.
//

#include <generics.hpp>

namespace primes {

    // private functions not exposed
    namespace {
        /**
         * Miller-Rabin determinist algorithm for primality check
         * @param n The number to check
         * @param witnesses The witnesses values to check
         * @return true if n is prime (using given witnesses), false otherwise
         */
        template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
        bool miller_rabin(const T& n, const std::vector<T>& witnesses) {
            uint32_t s = 0;
            T d = n - 1;
            while (d % 2 == 0) {
                s++;
                d /= 2;
            }

            for (const auto& a : witnesses) {
                if (generics::mod_pow<T>(a, d, n) == 1)
                    continue;

                bool composite = true;
                for (uint32_t r = 0; r < s; r++) {
                    if (generics::mod_pow<T>(a, (T) pow(2, r) * d, n) == n - 1) {
                        composite = false;
                        break;
                    }
                }

                if (composite)
                    return false;
            }

            return true;
        }
    }


    template<class T, class>
    std::vector<T> prime_factors(const T &n) {
        std::vector<T> factors;
        T copy(n);

        if (copy % 2 == 0)
            factors.emplace_back(2);
        while (copy % 2 == 0)
            copy /= 2;

        for (T i = 3; i * i <= copy; i = i + 2) {
            if (copy % i == 0)
                factors.emplace_back(i);
            while (copy % i == 0)
                copy /= i;
        }

        if (copy > 2)
            factors.push_back(copy);

        return factors;
    }

    template<class T, class>
    std::vector<T> primes(const T& n) {
        assert (n > 0 && "Number of primes must be positive");

        auto upper_bound = (T) (n * (log(n) + log(log(n))));
        std::vector<T> ps = primes_up_to(upper_bound);
        ps.resize(n);
        return ps;
    }

    template<class T, class>
    std::vector<T> primes_up_to(const T& upper_bound) {
        std::vector<bool> primes_check(upper_bound / 2, true);
        std::vector<T> primes;

        if (upper_bound < 2)
            return primes;
        primes.emplace_back(2);

        auto root = sqrt(upper_bound) / 2;

        // setting false all multiples of primes
        for(uint32_t i = 1; i < root; i ++)
            if (primes_check[i]) {
                T prime = i * 2 + 1;
                for (T multiple = prime * prime; multiple < upper_bound; multiple += 2 * prime)
                    primes_check[(uint64_t) ((multiple - 1) / 2)] = false;
            }

        // adding primes to std::vector
        for (uint64_t i = 1; i < primes_check.size(); i++)
            if (primes_check[i])
                primes.emplace_back(2 * i + 1);

        return primes;
    }

    template<class T, class>
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