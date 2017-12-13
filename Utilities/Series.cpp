//
// Created by Alex Beccaro on 11/12/17.
//

#include "Series.h"
#include <cmath>
#include <iostream>

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
        double upperBound = n * (log(n) + log(log(n)));
        vector<int> ps = primesUpTo(static_cast<unsigned long>(upperBound));
        ps.resize(n);
        return ps;
    }

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
};