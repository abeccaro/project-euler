//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem21.hpp"
#include <vector>
#include <generics.hpp>

using std::vector;
using generics::divisors;

namespace problems {
    uint32_t problem21::solve(uint32_t ub) {
        vector<uint32_t> divisors_sums(ub);
        for (uint32_t i = 2; i < ub; i++) {
            vector<uint32_t> divs = divisors(i);
            for (const auto &div : divs)
                divisors_sums[i] += div;
            divisors_sums[i] -= i;
        }

        uint32_t amicables = 0;
        for (uint32_t i = 2; i < ub; i++)
            if (divisors_sums[i] < divisors_sums.size() &&
                divisors_sums[i] != i && divisors_sums[divisors_sums[i]] == i)
                amicables += i;

        return amicables;
    }
}