//
// Created by Alex Beccaro on 11/12/17.
//

#include "Series.h"
#include <vector>

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

    vector<int> fibonacciUpTo(int upperBound) {
        vector<int> fibonacci;

        if (upperBound > 0) {
            fibonacci.push_back(1);
            fibonacci.push_back(1);
        }

        for (int i = 0, next = 2; next <= upperBound; i++, next = fibonacci[i] + fibonacci[i+1])
            fibonacci.push_back(next);

        return fibonacci;
    }
};