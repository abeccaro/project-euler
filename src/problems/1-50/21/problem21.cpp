//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem21.hpp"
#include <vector>
#include <generics.hpp>

using generics::divisors;

namespace problems {
    uint problem21::solve(uint ub) {
        vector<uint> divisors_sums(ub);
        for (uint i = 2; i < ub; i++) {
            vector<uint> divs = divisors(i);
            for (const auto &div : divs)
                divisors_sums[i] += div;
            divisors_sums[i] -= i;
        }

        uint amicables = 0;
        for (uint i = 2; i < ub; i++)
            if (divisors_sums[i] < divisors_sums.size() &&
                divisors_sums[i] != i && divisors_sums[divisors_sums[i]] == i)
                amicables += i;

        return amicables;
    }
}