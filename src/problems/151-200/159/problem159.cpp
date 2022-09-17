//
// Created by Alex Beccaro on 17/09/2022.
//

#include "problem159.hpp"
#include "generics.hpp"
#include <numeric>

using std::vector;
using std::accumulate;
using generics::digits;

namespace problems {
    vector<vector<uint64_t>> problem159::divisors;

    vector<uint64_t> problem159::mdrs;

    uint64_t problem159::calculate_mdrs(uint64_t n) {
        uint64_t max = 0;

        // divisors by pairs
        uint64_t divisors_count = divisors[n - 2].size();
        uint64_t limit = (divisors_count + 1) / 2;
        for (uint64_t i = 0; i < limit; i++) {
            uint64_t d1 = divisors[n-2][i];
            uint64_t d2 = divisors[n-2][divisors_count - i - 1];
            max = std::max(max, mdrs[d1 - 2] + mdrs[d2 - 2]);
        }

        // n
        max = std::max(max, (n - 1) % 9 + 1);

        return max;
    }

    uint64_t problem159::solve(uint64_t ub) {
        divisors = vector<vector<uint64_t>>(ub - 2);

        // calculate divisors. 1 and n are not included.
        for (uint64_t i = 2; i < ub / 2; i++) {
            for (uint64_t ki = i+i; ki < ub; ki += i) {
                divisors[ki - 2].push_back(i);
            }
        }

        // calculate mdrs
        mdrs.reserve(ub - 2);
        for (uint64_t i = 2; i < ub; i++)
            mdrs.push_back(calculate_mdrs(i));

        // sum all mdrs
        return accumulate(mdrs.begin(),  mdrs.end(), 0ull);
    }
}