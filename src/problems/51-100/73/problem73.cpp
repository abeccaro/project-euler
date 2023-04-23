//
// Created by Alex Beccaro on 22/01/18.
//

#include "generics.hpp"
#include "vector"
#include "problem73.hpp"

using std::vector;
using fractions::fraction;
using generics::are_coprime;

namespace problems {
    uint32_t problem73::solve(uint32_t ub, const range& interval) {
        uint32_t result = 0;

        // generate fractions using Farey sequence up to interval end and count from interval start
        for (fraction prev(0u, 1u), current(1u, ub); current < interval.second;) {
            if (current > interval.first)
                result++;

            uint64_t k = (ub + prev.denominator()) / current.denominator();
            uint64_t temp = prev.numerator();
            prev.numerator(current.numerator());
            current.numerator(k * current.numerator() - temp);
            temp = prev.denominator();
            prev.denominator(current.denominator());
            current.denominator(k * current.denominator() - temp);
        }

        return result;
    }
}
