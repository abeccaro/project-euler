//
// Created by Alex Beccaro on 23/01/18.
//

#include "problem75.hpp"

using std::unordered_map;

namespace problems {
    void problem75::sums_up_to(uint32_t ub, unordered_map<uint32_t, uint32_t>& sums, uint32_t a, uint32_t b, uint32_t c) {
        uint32_t sum = a + b + c;
        if (sum > ub) // if ub is reached stop
            return;

        // considering sums of all non primitive triples multiple of this
        for (uint64_t m = sum; m <= ub; m += sum)
            sums[m]++;

        // recursion using Berggren algorithm
        sums_up_to(ub, sums, a - 2*b + 2*c, 2*a - b +2*c, 2*a - 2*b + 3*c);
        sums_up_to(ub, sums, a + 2*b + 2*c, 2*a + b +2*c, 2*a + 2*b + 3*c);
        sums_up_to(ub, sums, -a + 2*b + 2*c, -2*a + b +2*c, -2*a + 2*b + 3*c);
    }

    uint32_t problem75::solve(uint32_t ub) {
        // map in the form: (sum => count)
        unordered_map<uint32_t, uint32_t> counts;
        sums_up_to(ub, counts);

        uint32_t result = 0;
        for (const auto& e : counts)
            if (e.second == 1)
                result++;
        return result;
    }
}
