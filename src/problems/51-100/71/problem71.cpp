//
// Created by Alex Beccaro on 22/01/18.
//

#include <generics.hpp>
#include "problem71.hpp"

using generics::are_coprime;

namespace problems {
    uint problem71::solve(uint ub, fraction<ulong> ref) {
        ulong ref_num = ref.numerator();
        ulong ref_den = ref.denominator();

        uint result;
        fraction<ulong> min_diff = 1;

        for (uint d = 2; d <= ub; d++) {
            if (d == ref_den)
                continue;

            uint n = d * ref_num / ref_den;
            while (!are_coprime(n, d))
                n--;
            fraction<uint> f(n, d);

            fraction<ulong> diff = ref - f;
            if (diff < min_diff) {
                min_diff = diff;
                result = n;
            }
        }

        return result;
    }
}
