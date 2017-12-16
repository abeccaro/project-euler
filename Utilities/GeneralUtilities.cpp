//
// Created by Alex Beccaro on 11/12/17.
//

#include "GeneralUtilities.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

namespace general_utilities {
    bool isPalindrome(unsigned long n) {
        vector<int> dig = digits(n);
        vector<int> reversedDig(dig.size());

        reverse_copy(dig.begin(), dig.end(), reversedDig.begin());

        return dig == reversedDig;
    }

    vector<int> digits(unsigned long n) {
        vector<int> digits;

        while (n > 9) {
            int d = n % 10;
            digits.push_back(d);
            n /= 10;
        }
        digits.push_back(n);

        reverse(digits.begin(), digits.end());
        return digits;
    }

    unsigned long lcm(const vector<unsigned long> &numbers) {
        unsigned long product = 1;
        for (unsigned long i : numbers)
            product *= i;

        for (unsigned long i : numbers) {
            unsigned long n = product / i;
            bool dividesAll = true;

            for (unsigned long j : numbers)
                if (n % j != 0) {
                    dividesAll = false;
                    break;
                }

            if (dividesAll)
                product = n;
        }

        return product;
    }

    vector<unsigned long> divisors(unsigned long n) {
        vector<unsigned long> divisors;
        double root = sqrt(n);

        for (unsigned long i = 1; i < root; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                divisors.push_back(n / i);
            }
        }

        if (root == (unsigned long) root)
            divisors.push_back((unsigned long) root);

        return divisors;
    }

    unsigned long factorial(unsigned long n) {
        if (n == 0)
            return 1;

        unsigned long result = 1;
        for (unsigned long i = 2; i <= n; i++)
            result *= i;

        return result;
    }

    unsigned long binomialCoefficient(unsigned long n, unsigned long k) {
        unsigned long num = 1;

        for (unsigned long i = n; i > n - k; i--) {
            if (num * i < num)
                cout << "Overflow" << endl;
            num *= i;
        }

        unsigned long den = factorial(k);

        return num / den; // safe integer division, result is always integer
    }
}