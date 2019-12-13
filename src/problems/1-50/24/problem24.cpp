//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem24.hpp"
#include <algorithm>

using std::vector;

namespace problems {
    vector<uint32_t> problem24::solve(const vector<uint32_t>& digs, uint32_t n) {
        vector<uint32_t> digits = digs;
        for (uint32_t i = 0; i < n - 1; i++)
            next_permutation(digits.begin(), digits.end());
        return digits;
    }
}