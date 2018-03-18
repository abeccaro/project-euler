//
// Created by Alex Beccaro on 07/01/18.
//

#include "problem43.hpp"
#include <generics.hpp>

using std::vector;
using generics::from_digits;
using generics::factorial;

namespace problems {
    bool problem43::has_required_properties(const vector<uint32_t>& digs) {
        if (digs[3] % 2 != 0)
            return false;

        if ((digs[2] + digs[3] + digs[4]) % 3 != 0)
            return false;

        if (digs[5] % 5 != 0)
            return false;

        vector<uint32_t> v1 = {digs[4], digs[5], digs[6]};
        if (from_digits<uint32_t>(v1) % 7 != 0)
            return false;

        int x = (int) digs[6] - digs[5] - digs[7];
        if (abs(x) % 11 != 0)
            return false;

        v1 = {digs[6], digs[7], digs[8]};
        if (from_digits<uint32_t>(v1) % 13 != 0)
            return false;

        v1 = {digs[7], digs[8], digs[9]};
        if (from_digits<uint32_t>(v1) % 17 != 0)
            return false;

        return true;
    }

    uint64_t problem43::solve() {
        vector<uint32_t> pandigital = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        uint64_t result = 0;

        auto iterations = factorial<uint32_t>(10);
        for (uint32_t i = 0; i < iterations; i++) {
            next_permutation(pandigital.begin(), pandigital.end());

            if (pandigital[0] != 0 && has_required_properties(pandigital))
                result += from_digits<uint64_t>(pandigital);
        }

        return result;
    }
}