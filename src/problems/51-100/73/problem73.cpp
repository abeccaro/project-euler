//
// Created by Alex Beccaro on 22/01/18.
//

#include <generics.hpp>
#include "problem73.hpp"

using generics::are_coprime;

namespace problems {
    uint problem73::solve(uint ub, const range& interval) {
        uint max_num = interval.second.numerator();
        uint max_den = interval.second.denominator();

        uint result = 0;

        for (uint d = 2; d <= ub; d++) {
            if (d == max_den)
                continue;

            uint n = d * max_num / max_den;
            fraction<uint> f(n, d);

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
