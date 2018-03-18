//
// Created by Alex Beccaro on 23/01/18.
//

#include "problem76.hpp"
#include <generics.hpp>

using std::vector;
using generics::divisors;

namespace problems {
    uint64_t problem76::partitions(uint32_t n, vector<uint64_t> &memory) {
        if (n < 2)
            return 1;

        if (memory[n-1] != 0)
            return memory[n-1];

        uint64_t sum = 0;
        for (uint32_t k = 0; k < n; k++) {
            vector<uint32_t> divs = divisors(n - k);
            uint32_t divs_sum = 0;
            for (const auto& d : divs)
                divs_sum += d;

            sum += divs_sum * partitions(k, memory);
        }
        sum /= n;
        memory[n-1] = sum;
        return sum;
    }

    uint64_t problem76::solve(uint32_t n) {
        vector<uint64_t> memory(n);
        return partitions(n, memory) - 1;
    }
}
