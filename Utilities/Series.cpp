//
// Created by Alex Beccaro on 11/12/17.
//

#include "Series.h"
#include <cmath>

using namespace std;

namespace series {
    vector<int> fibonacci(unsigned long n) {
        vector<int> fibonacci(n);

        if (n > 0)
            fibonacci.push_back(1);
        if (n > 1)
            fibonacci.push_back(1);

        for (int i = 2; i < n; i++)
            fibonacci[i] = fibonacci[i-2] + fibonacci[i-1];

        return fibonacci;
    }

    vector<int> fibonacciUpTo(unsigned long upperBound) {
        vector<int> fibonacci;

        if (upperBound > 0) {
            fibonacci.push_back(1);
            fibonacci.push_back(1);
        }

        for (int i = 0, next = 2; next <= upperBound; i++, next = fibonacci[i] + fibonacci[i+1])
            fibonacci.push_back(next);

        return fibonacci;
    }

    vector<int> primes(unsigned long n) {
        vector<int> ps(n);
        int count = 0;

        ps[count++] = 2;

        for (int i = 3; count < n; i += 2) {
            bool prime = true;

            // Look for divisors of i up to sqrt(i)
            for (int j = 1; prime && j < count && ps[j] * ps[j] <= i; j++)
                if (i % ps[j] == 0)
                    prime = false;

            // If loop terminated, and this number is prime,
            // then add it to the list:
            if (prime)
                ps[count++] = i;
        }

        return ps;
    }

    vector<int> primesUpTo(unsigned long upperBound) {
        vector<bool> primesCheck(upperBound, true);
        vector<int> primes;
        double root = sqrt(upperBound);

        // 2
        if (upperBound >= 2)
            primes.push_back(2);

        // setting false all multiples of primes
        for(int i = 3; i < root; i += 2)
            if (primesCheck[i])
                for (int j = i * i; j < upperBound; j += 2 * i)
                    primesCheck[j] = false;

        // adding primes to vector
        for (int i = 3; i < upperBound; i += 2)
            if (primesCheck[i])
                primes.push_back(i);

        return primes;
    }
};