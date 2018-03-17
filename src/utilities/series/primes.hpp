//
// Created by Alex Beccaro on 13/12/17.
//
#ifndef PROJECT_EULER_PRIMES_H
#define PROJECT_EULER_PRIMES_H

#include "lazy_series.hpp"
#include "template_conditions.hpp"

using ulong = unsigned long;

namespace series {
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    /**
     * Lazy series implementation for prime numbers.
     * It is less performant than utilities function primes::get and primes::get_up_to.
     * The advantages are in the lazyness.
     */
    class primes : public lazy_series<T>{
    public:
        /**
         * Default constructor that adds first 2 numbers.
         */
        primes();

    protected:
        /**
         * Calculates next prime number.
         * @return The next prime number
         */
        T next_element() final;

    private:
        /**
         * Vector for odd numbers only. If a value is false it means that the n-th odd number is not prime.
         * If value is true it can be both prime or not.
         */
        std::vector<bool> prime_checks;

        /**
         * The highest multiple of the n-th prime that has been set as not prime.
         */
        std::vector<T> next_multiples;
    };
}

#include "primes.ipp"

#endif //PROJECT_EULER_PRIMES_H
