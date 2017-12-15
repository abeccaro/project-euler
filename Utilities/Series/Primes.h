//
// Created by Alex Beccaro on 13/12/17.
//
#ifndef PROJECT_EULER_PRIMES_H
#define PROJECT_EULER_PRIMES_H

#include "LazySeries.h"

using namespace std;

namespace series {
    /**
     * LazySeries implementation for prime numbers.
     * It is less performant than utilities function primes::get and primes::getUpTo.
     * The advantages are in the lazyness.
     */
    class Primes : public LazySeries<unsigned long>{
    public:
        /**
         * Default constructor that adds first 2 numbers.
         */
        Primes();

    protected:
        /**
         * Calculates next prime number.
         * @return The next prime number
         */
        unsigned long nextElement() final;

    private:
        /**
         * Vector for odd numbers only. If a value is false it means that the n-th odd number is not prime.
         * If value is true it can be both prime or not.
         */
        vector<bool> primeChecks;

        /**
         * The highest multiple of the n-th prime that has been set as not prime.
         */
        vector<unsigned long> nextMultiples;
    };
}


#endif //PROJECT_EULER_PRIMES_H
