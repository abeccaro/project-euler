//
// Created by Alex Beccaro on 23/01/18.
//

#include "problem75.hpp"

using ulong = unsigned long;

namespace problems {
    void problem75::sums_up_to(uint ub, unordered_map<uint, uint>& sums, uint a, uint b, uint c) {
        uint sum = a + b + c;
        if (sum > ub) // if ub is reached stop
            return;

        // considering sums of all non primitive triples multiple of this
        for (ulong m = sum; m <= ub; m += sum)
            sums[m]++;

        // recursion using Berggren algorithm
        sums_up_to(ub, sums, a - 2*b + 2*c, 2*a - b +2*c, 2*a - 2*b + 3*c);
        sums_up_to(ub, sums, a + 2*b + 2*c, 2*a + b +2*c, 2*a + 2*b + 3*c);
        sums_up_to(ub, sums, -a + 2*b + 2*c, -2*a + b +2*c, -2*a + 2*b + 3*c);
    }

    uint problem75::solve(uint ub) {
        // map in the form: (sum => count)
        unordered_map<uint, uint> counts;
        sums_up_to(ub, counts);

        uint result = 0;
        for (const auto& e : counts)
            if (e.second == 1)
                result++;
        return result;
    }
}
