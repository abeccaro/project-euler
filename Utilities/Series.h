//
// Created by Alex Beccaro on 11/12/17.
//

#include <vector>

using namespace std;

namespace series {
    /**
     * Generates n terms of the fibonacci series.
     * @param n The number of terms to generate
     * @return The vector with the series
     */
    vector<int> fibonacci(unsigned long n);

    /**
     * Generates fibonacci series up to number upperBound.
     * @param upperBound The upper bound
     * @return The vector with the series
     */
    vector<int> fibonacciUpTo(int upperBound);
};
