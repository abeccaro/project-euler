//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem24.hpp"

namespace problems {
    vector<uint> problem24::solve(const vector<uint>& digs, uint n) {
        vector<uint> digits = digs;
        for (uint i = 0; i < n - 1; i++)
            next_permutation(digits.begin(), digits.end());
        return digits;
    }
}