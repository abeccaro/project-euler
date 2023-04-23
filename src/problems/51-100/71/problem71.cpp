//
// Created by Alex Beccaro on 22/01/18.
//

#include "generics.hpp"
#include "problem71.hpp"

using fractions::fraction;
using generics::are_coprime;

namespace problems {
    uint32_t problem71::solve(uint32_t ub, fraction<uint64_t> ref) {
        uint64_t ref_num = ref.numerator();
        uint64_t ref_den = ref.denominator();

        uint32_t result;
        fraction<uint64_t> min_diff = 1;

        for (uint32_t d = 2; d <= ub; d++) {
            if (d == ref_den)
                continue;

            uint32_t n = d * ref_num / ref_den;
            while (!are_coprime(n, d))
                n--;
            fraction<uint32_t> f(n, d);

            fraction<uint64_t> diff = ref - f;
            if (diff < min_diff) {
                min_diff = diff;
                result = n;
            }
        }

        return result;
    }
}
