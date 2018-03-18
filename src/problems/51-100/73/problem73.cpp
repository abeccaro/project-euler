//
// Created by Alex Beccaro on 22/01/18.
//

#include <generics.hpp>
#include "problem73.hpp"

using fractions::fraction;
using generics::are_coprime;

namespace problems {
    uint32_t problem73::solve(uint32_t ub, const range& interval) {
        uint32_t max_num = interval.second.numerator();
        uint32_t max_den = interval.second.denominator();

        uint32_t result = 0;

        for (uint32_t d = 2; d <= ub; d++) {
            if (d == max_den)
                continue;

            uint32_t n = d * max_num / max_den;
            fraction<uint32_t> f(n, d);

            while (!are_coprime(f.numerator(), f.denominator()))
                f.numerator(f.numerator() - 1);

            while (f > interval.first) {
                result++;
                f.numerator(f.numerator() - 1);
                while (!are_coprime(f.numerator(), f.denominator()))
                    f.numerator(f.numerator() - 1);
            }
        }

        return result;
    }
}
