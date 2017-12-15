//
// Created by Alex Beccaro on 13/12/17.
//

#include <cmath>
#include <iostream>
#include "Primes.h"

namespace series {
    Primes::Primes() {
        numbers.push_back(2);
        nextMultiples.push_back(0); // multiples of 2 are ignored

        numbers.push_back(3);
        nextMultiples.push_back(9);
    }

    unsigned long Primes::nextElement() {
        unsigned long size = numbers.size();
        unsigned long n = size + 1;
        unsigned long ub = n < 6 ? 14 : static_cast<unsigned long>(n * (log(n) + log(log(n))));

        primeChecks.resize(ub / 2, true);
        double root = sqrt(ub);

        for (int i = 1; numbers[i] < root && i < size; i++) {
            while (nextMultiples[i] < ub) {
                primeChecks[nextMultiples[i] / 2] = false;
                nextMultiples[i] += 2 * numbers[i];
            }
        }

        for (unsigned long i = numbers.back() + 2; ; i += 2)
            if (primeChecks[i / 2]) {
                nextMultiples.push_back(i * i);
                return i;
            }
    }
}