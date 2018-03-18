//
// Created by Alex Beccaro on 11/12/17.
//
#ifndef PROJECT_EULER_PRIMES_UTILS_H
#define PROJECT_EULER_PRIMES_UTILS_H

#include <template_conditions.hpp>

namespace primes {
    /**
     * Calculates all given number prime factors. It uses division trial.
     * Complexity: O(√n)
     * @param n The number
     * @return The vector of prime factors
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    std::vector<T> prime_factors(const T& n);

    /**
     * Generates the first n primes.
     * Complexity: let x = n + log n + log log n, O(x log log x)
     * @param n The number of primes to generate
     * @return The vector with the series
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    std::vector<T> primes(const T& n);

    /**
     * Generates primes up to number upper_bound.
     * Complexity: O(n log log n)
     * @param upper_bound The upper bound
     * @return The vector with the series
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    std::vector<T> primes_up_to(const T& upper_bound);

    /**
     * Checks if given number is prime. Correct at least for any number up to 2^64.
     * @param n The number to check
     * @return True if given number is prime, false otherwise
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    bool is_prime(const T& n);
}

#include "primes.ipp"

#endif //PROJECT_EULER_PRIMES_UTILS_H