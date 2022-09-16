//
// Created by Alex Beccaro on 13/09/2022.
//

#include "problem158.hpp"
#include "generics.hpp"

using std::map;
using std::tuple;
using generics::int_pow;
using generics::combinations;

namespace problems {
    map<tuple<uint64_t, uint64_t>, uint64_t> problem158::dsc;
    map<uint64_t, uint64_t> problem158::pc;

    // f(1, m) = m
    // f(l, m) = sum_{i = l - 1}^{m - 1} f(l - 1, i)
    uint64_t problem158::descending_sequences_count(uint64_t len, uint64_t max) {
        if (len == 1)
            return max;

        uint64_t sum = 0;
        for (uint64_t i = len - 1; i < max; i++)
            sum += dsc[{len - 1, i}];
        return sum;
    }

    // c(1) = 0
    // c(n) = c(n - 1) + sum_{i = 1}^{n - 1} f(i, n - 1)
    uint64_t problem158::requested_permutations_count(uint64_t n) {
        if (n == 1)
            return 0;

        uint64_t sum = pc[n - 1];
        for (uint64_t i = 1; i < n; i++)
            sum += dsc[{i, n - 1}];
        return sum;
    }

    uint64_t problem158::solve(uint64_t n_max) {
        // populate dsc
        for (uint64_t l = 1; l <= n_max; l++)
            for (uint64_t m = 1; m <= 26; m++)
                dsc.insert({{l, m}, descending_sequences_count(l, m)});

        // populate pc
        for (uint64_t n = 2; n <= n_max; n++)
            pc.insert({n, requested_permutations_count(n)});

        // find max p(n)
        uint64_t max = 0;
        for (uint64_t n = 1; n <= n_max; n++)
            max = std::max(dsc[{n, 26}] * pc[n], max);

        return max;
    }
}