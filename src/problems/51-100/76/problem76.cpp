//
// Created by Alex Beccaro on 23/01/18.
//

#include "problem76.hpp"
#include <generics.hpp>

using generics::divisors;

namespace problems {
    ulong problem76::partitions(uint n, vector<ulong> &memory) {
        if (n < 2)
            return 1;

        if (memory[n-1] != 0)
            return memory[n-1];

        ulong sum = 0;
        for (uint k = 0; k < n; k++) {
            vector<uint> divs = divisors(n - k);
            uint divs_sum = 0;
            for (const auto& d : divs)
                divs_sum += d;

            sum += divs_sum * partitions(k, memory);
        }
        sum /= n;
        memory[n-1] = sum;
        return sum;
    }

    ulong problem76::solve(uint n) {
        vector<ulong> memory(n);
        return partitions(n, memory) - 1;
    }
}
