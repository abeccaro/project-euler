//
// Created by Alex Beccaro on 21/05/2023.
//

#include "algorithm"
#include "problem174.hpp"
#include "unordered_map"


using std::count_if;
using std::unordered_map;

namespace problems {
    uint64_t problem174::solve(uint32_t max_tiles, uint32_t max_n) {
        unordered_map<uint32_t, uint32_t> mem;

        for (uint32_t i = 1, increment = 4; increment * (i + 1) < max_tiles; i++, increment += 4)
            for (uint32_t t = increment * (i + 1); t < max_tiles; t += increment)
                mem[t]++;

        return count_if(mem.begin(), mem.end(), [&](const auto &item) { return item.second <= max_n; });
    }
}