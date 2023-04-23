//
// Created by Alex Beccaro on 17/09/2022.
//

#include "problem159.hpp"
#include "vector"
#include "algorithm"

using std::vector;
using std::max;

namespace problems {
    uint64_t problem159::solve(uint64_t ub) {
        uint64_t result = 0;
        vector<uint64_t> mdrs(ub, 0);

        for (uint64_t i = 2; i < ub; i++) {
            mdrs[i] = max(mdrs[i], (i - 1) % 9 + 1); // second term is drs(n)
            for (uint64_t j = 2, n = i + i; j <= i && n < ub; j++, n += i) // n = i * j, j <= i
                mdrs[n] = max(mdrs[n], mdrs[i] + mdrs[j]);
            result += mdrs[i];
        }

        return result;
    }
}