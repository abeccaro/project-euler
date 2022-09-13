//
// Created by Alex Beccaro on 12/09/2022.
//

#include "problem156.hpp"
#include "generics.hpp"
#include <cmath>

using generics::digits;
using generics::int_pow;

namespace problems {
    uint64_t problem156::f(uint64_t n, uint64_t d) {
        auto digs = digits(n);
        uint64_t pow_ten = int_pow(10ul, digs.size() - 1);
        uint64_t result = 0;

        uint64_t factor = 0;
        // for each digit position count how many times d appears in that position
        for (unsigned int & digit : digs) {
            if (digit < d)
                result += factor * pow_ten;
            else if (digit > d)
                result += (factor + 1) * pow_ten;
            else
                result += factor * pow_ten + (n % pow_ten) + 1;

            factor = factor * 10 + digit;
            pow_ten /= 10;
        }

        return result;
    }

    uint64_t problem156::s(uint64_t d) {
        uint64_t sum = 0;

        // upper bound is 10^11, after that f(n) > n
        for (uint64_t n = 0; n <= 100000000000; n++) {
            uint64_t count = f(n, d);
            if (count == n)
                sum += n;
            else if (count > n)
                // skip to next possible value of n
                n = count - 1;
            else {
                // if possible skip values of n until n = f(n) cold be verified
                // logic could probably be improved, but it's already efficient
                uint64_t pow = floor(log10(n)); // number of digits - 1
                if (pow == 0)
                    continue;

                uint64_t increment = (n - count) / pow;
                if (increment > 1)
                    n += increment - 1;
            }
        }

        return sum;
    }

    uint64_t problem156::solve() {
        uint64_t result = 0;

        for (uint64_t d = 1; d < 10; d++)
            result += s(d);

        return result;
    }
}