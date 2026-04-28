//
// Created by Alex Beccaro on 28/04/2026.
//

#include "problem179.hpp"
#include "vector"

using std::vector;

namespace problems {
    uint32_t problem179::solve(uint32_t ub) {
        vector<uint32_t> counts(ub, 1);
        uint32_t result = 0;
        for (uint32_t i = 2; i <= ub; i++) {
            for (uint32_t j = i - 1; j < ub; j += i) {
                counts[j]++;
            }
            if (counts[i - 2] == counts[i - 1]) {
                result++;
            }
        }
        return result;
    }
}